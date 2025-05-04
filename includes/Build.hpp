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

#ifndef BUILD_HPP
#define BUILD_HPP

#include <iostream>
#include "Repository.hpp"
#include <filesystem>

class Build {
    public:
        static void createFolder() {
            std::string path = Repository::instance().get() + "/build";
            if (!std::filesystem::exists(path)) {
                std::filesystem::create_directories(path);
                std::cout << "Build folder created at: " << path << std::endl;
            }
        }
};

#endif // BUILD_HPP