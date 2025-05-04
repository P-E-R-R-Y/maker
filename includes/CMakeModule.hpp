/**
 * @file CMakeModule.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 03-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CMAKE_MODULE_HPP
#define CMAKE_MODULE_HPP

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

#include "Repository.hpp"
#include "Warn.hpp"
#include "ConvertCase.hpp"

using json = nlohmann::json;

class CMakeModule {
    public:

        static void cmakeModule(json j) {
            std::string path = Repository::instance().get() + "/cmake";

            if (j.contains("deps") && j["deps"].is_object()) {
                if ((j["deps"].contains("shared") && j["deps"]["shared"].is_array()) || (j["deps"].contains("static") && j["deps"]["static"].is_array())) {
                    if (!std::filesystem::exists(path)) {
                        std::filesystem::create_directories(path);
                        std::cout << "CMake module created at: " << path << std::endl;
                    }
                }
            } else {
                std::cerr << "Warn: JSON file does not contain 'deps' key." << std::endl;
                return;
            }

            if (j.contains("deps") && j["deps"].is_object()) {
                if (j["deps"].contains("shared") && j["deps"]["shared"].is_array()) {
                    deps(j["deps"]["shared"]);
                }
                if (j["deps"].contains("static") && j["deps"]["static"].is_array()) {
                    deps(j["deps"]["static"]);
                }
            }
            Warn::warn(j);
        }

        static void deps(json j) {
            std::string path = Repository::instance().get() + "/cmake/";
            for (auto& item : j) {
                if (item.is_object() && item.contains("name") && item["name"].is_string()) {
                    std::ofstream f(path + "Find" + ConvertCase::toPascalCase(item["name"].get<std::string>()) + ".cmake");
                    if (item.contains("git")) {
                        git(f, item);
                    } else if (item.contains("url")) {
                        url(f, item);
                    } else {
                        perry(f, item);
                    }
                    f.close();
                }
            }
        }

        static void git(std::ofstream& f, json j) {
            f << "set(name " << j["name"].get<std::string>() << ")" << std::endl;
            f << "set(tag " << j["tag"].get<std::string>() << ")" << std::endl << std::endl;

            f << "include(FetchContent)" << std::endl;
            f << "FetchContent_GetProperties(${name})" << std::endl;

            f << "if (NOT ${name}_POPULATED)" << std::endl;
            f << "\tFetchContent_Declare(" << std::endl;
            f << "\t\t${name}" << std::endl;
            f << "\t\tGIT_REPOSITORY " << j["git"].get<std::string>() << std::endl;
            f << "\t\tGIT_TAG ${tag}" << std::endl;
            f << "\t)" << std::endl;
            f << "\tFetchContent_MakeAvailable(${name})" << std::endl;
            f << "endif()" << std::endl << std::endl;
        }

        static void url(std::ofstream& f, json j) {
            f << "set(name " << j["name"].get<std::string>() << ")" << std::endl;
            f << "set(sha " << j["tag"].get<std::string>() << ")" << std::endl << std::endl;

            f << "include(FetchContent)" << std::endl;
            f << "if (NOT ${name}_POPULATED)" << std::endl;
            f << "\tFetchContent_Declare(" << std::endl;
            f << "\t\t${name}" << std::endl;
            f << "\t\tGIT_REPOSITORY " << j["git"].get<std::string>() << std::endl;
            f << "\t\tGIT_TAG ${tag}" << std::endl;
            f << "\t)" << std::endl;
            f << "\tFetchContent_MakeAvailable(${name})" << std::endl;
            f << "endif()" << std::endl << std::endl;

        }

        static void perry(std::ofstream& f, json j) {
            f << "set(name " << j["name"].get<std::string>() << ")" << std::endl;
            f << "set(tag " << j["tag"].get<std::string>() << ")" << std::endl << std::endl;

            f << "include(FetchContent)" << std::endl;
            f << "if (NOT ${name}_POPULATED)" << std::endl;
            f << "\tFetchContent_Declare(" << std::endl;
            f << "\t\t${name}" << std::endl;
            f << "\t\tGIT_REPOSITORY " << "https://github.com/P-E-R-R-Y/${name}" << std::endl;
            f << "\t\tGIT_TAG ${tag}" << std::endl;
            f << "\t)" << std::endl;
            f << "\tFetchContent_MakeAvailable(${name})" << std::endl;
            f << "endif()" << std::endl << std::endl;
        }

};

#endif // C