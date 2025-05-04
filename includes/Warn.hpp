/**
 * @file CMake.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 01-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef WARN_HPP
#define WARN_HPP
 
 #include <fstream>
 #include <nlohmann/json.hpp>
 #include <iostream>
 
 using json = nlohmann::json;
 
class Warn {
    public:
 
        static void warn(json j) {
            if (j.is_object() && j.contains("warn") && j["warn"].is_string()) {
                std::cerr << "Warn: " << j["warn"] << std::endl;
            }
        }
};

#endif // WARN_HPP
