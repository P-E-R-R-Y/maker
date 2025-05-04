/**
 * @file ConvertCase.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 04-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CONVERTCASE_HPP
#define CONVERTCASE_HPP

#include <string>
#include <algorithm>
#include <cctype>

class ConvertCase {
    public:
        static std::string toUpperCase(const std::string& str) {
            std::string tmp = str;
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
            return tmp;
        }
        

        static std::string toLowerCase(const std::string& str) {
            std::string tmp = str;
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            return tmp;
        }

        static std::string toCamelCase(const std::string& str) {
            std::string result;
            bool capitalizeNext = false;

            for (size_t i = 0; i < str.size(); ++i) {
                char ch = str[i];
        
                if (ch == '_' || ch == '-' || ch == ' ') {
                    capitalizeNext = true;
                } else {
                    if (result.empty()) {
                        // First character: always lowercase
                        result += std::tolower(ch);
                    } else if (capitalizeNext) {
                        result += std::toupper(ch);
                        capitalizeNext = false;
                    } else {
                        result += std::tolower(ch);
                    }
                }
            }
            return result;
        }

        static std::string toPascalCase(const std::string& input) {
            std::string result;
            bool capitalizeNext = false;

            for (char ch : input) {
                if (ch == '_' || ch == '-' || ch == ' ') {
                    capitalizeNext = true;
                } else {
                    if (result.empty()) {
                        // First character: always lowercase
                        result += std::toupper(ch);
                    } else if (capitalizeNext) {
                        result += std::toupper(ch);
                        capitalizeNext = false;
                    } else {
                        result += std::tolower(ch);
                    }
                }
            }

            return result;
        }

        static std::string toSnakeCase(const std::string& input) {
            std::string result;
        
            for (size_t i = 0; i < input.size(); ++i) {
                char ch = input[i];
        
                if (std::isupper(ch)) {
                    if (i != 0) {
                        result += '_';
                    }
                    result += std::tolower(ch);
                } else if (ch == '-' || ch == ' ') {
                    result += '_';
                } else {
                    result += ch;
                }
            }
        
            return result;
        }

        static std::string toKebabCase(const std::string& input) {
            std::string result;
        
            for (size_t i = 0; i < input.size(); ++i) {
                char ch = input[i];
        
                if (std::isupper(ch)) {
                    if (i != 0) {
                        result += '-';
                    }
                    result += std::tolower(ch);
                } else if (ch == '_' || ch == ' ') {
                    result += '-';
                } else {
                    result += ch;
                }
            }
        
            return result;
        }
};

#endif // CONVERTCASE_HPP