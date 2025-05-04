/**
 * @file Assets.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 04-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "Repository.hpp"

class Assets {
    public:

        static void createFolders(json j) {
            if (j.contains("assets") && j["assets"].is_array()) {
                std::string path = Repository::instance().get() + "/assets";
                if (!std::filesystem::exists(path)) {
                    std::filesystem::create_directories(path);
                    std::cout << "Assets folder created at: " << path << std::endl;
                }
                for (auto& item : j["assets"]) {
                    if (item.is_string()) {
                        std::string assetPath = path + "/" + item.get<std::string>();
                        if (!std::filesystem::exists(assetPath)) {
                            std::filesystem::create_directories(assetPath);
                            std::cout << "Asset folder created at: " << assetPath << std::endl;
                        }
                    }
                }
            }
        }        
};

#endif //ASSETS_HPP