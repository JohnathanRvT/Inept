# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Inept)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add IneptEngine project
add_subdirectory(IneptEngine)

# Add IneptEditor project
add_subdirectory(IneptEditor)
 
# Add lua project
add_subdirectory("vendor/lua" "${CMAKE_SOURCE_DIR}/build/lua")  
 
# Add glad project
add_subdirectory("vendor/glad" "${CMAKE_SOURCE_DIR}/build/glad")