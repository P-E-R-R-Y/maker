# CMakeList.txt : CMake project for maker, 

cmake_minimum_required(VERSION 3.10)
project(maker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## ----------- Find package -----------

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(finder REQUIRED)
find_package(json REQUIRED)

## ----------- Executable -----------
set(SOURCE_FILES
    sources/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    finder
    nlohmann_json::nlohmann_json
)

## ----------- Include -----------
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/
)

## ----------- Compile Options -----------
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

## ----------- Install -----------

message(STATUS "Installing ${PROJECT_NAME} to ${CMAKE_INSTALL_PREFIX}")

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

message(STATUS "Installing ${PROJECT_NAME} to ${CMAKE_INSTALL_PREFIX}")