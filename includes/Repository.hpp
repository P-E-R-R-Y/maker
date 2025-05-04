/**
 * @file Repository.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 01-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <iostream>
#include <filesystem>
#include <fstream>
#include <mutex>

class Repository {
public:
    static void createRepository(const std::string& path) {
        std::filesystem::path repoPath(path);
        if (!std::filesystem::exists(repoPath)) {
            std::filesystem::create_directories(repoPath);
            std::cout << "Repository created at: " << repoPath << std::endl;
        }
        Repository::instance().set(repoPath.string());
    }

    static Repository& instance() {
        static Repository inst;
        return inst;
    }

    const std::string& get() {
        std::call_once(initFlag, [this]() {
            if (repoName.empty()) {
                repoName = "./";  // Replace with actual logic if needed
            }
        });
        return repoName;
    }

    void set(const std::string& name) {
        repoName = name;
    }

private:
    Repository() = default;

    std::string repoName;
    std::once_flag initFlag;
};

#endif // REPOSITORY_HPP