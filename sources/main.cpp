/**
 * @file main.cpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 01-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//finder
#include "FileSearcher.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

#include "Repository.hpp"
#include "CMake.hpp"
#include "CMakeModule.hpp"
#include "Build.hpp"
#include "Assets.hpp"
#include "CodeBase.hpp"

using json = nlohmann::json;

int main(int ac, char ** av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <path>" << std::endl;
        return 84;
    }
    std::ifstream inputFile(av[1]);
    json j = json::parse(inputFile);
    
    if (j.contains("general") && j["general"].is_object() &&
        j["general"].contains("name") && j["general"]["name"].is_string()) {
        Repository::createRepository(j["general"]["name"]);
    }
    CMake::cmake(j);
    CMakeModule::cmakeModule(j);
    Build::createFolder();
    Assets::createFolders(j);
    CodeBase::createSources(j);
    CodeBase::createIncludes();



    std::cout << "CMakeLists.txt generated" << std::endl;

    return 0;
}