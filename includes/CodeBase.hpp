/**
 * @file Build.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 04-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CODE_BASE_HPP
#define CODE_BASE_HPP

#include "Repository.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <filesystem>
#include <fstream>

class CodeBase {
    public:

        static void createSources(json j) {
            std::string path = Repository::instance().get() + "/sources";
            if (!std::filesystem::exists(path)) {
                std::filesystem::create_directories(path);
                std::cout << "Build folder created at: " << path << std::endl;
            }
            
            if (j.contains("project") && j["project"].is_object() &&  j["project"].contains("sources") && j["project"]["sources"].is_array()) {
            }
            for (auto& item : j["project"]["sources"]) {
                if (item.is_string()) {
                    std::ofstream f(path + "/" + item.get<std::string>());
                }
            }
        }

        static void createIncludes() {
            std::string path = Repository::instance().get() + "/includes";
            if (!std::filesystem::exists(path)) {
                std::filesystem::create_directories(path);
                std::cout << "Build folder created at: " << path << std::endl;
            }
        }
};

#endif // CODE_BASE_HPP