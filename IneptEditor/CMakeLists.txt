# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(IneptEditor)

# Set the C++ standard to the latest available (currently C++20)
set(CMAKE_CXX_STANDARD 20)

# Get list of all source and header files in the directory
file(GLOB_RECURSE SOURCES source/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

# Include directories for IneptEditor
include_directories(PUBLIC include ../IneptEngine/include ../vendor/lua/src)

# Create the executable
add_executable(IneptEditor ${SOURCES} ${HEADERS})

# Add any dependencies or libraries needed to link
target_link_libraries(IneptEditor IneptEngine)

# Check if building for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES Windows)
  # Add INEPT_PLATFORM_WINDOWS preprocessor definition
  add_definitions(-DINEPT_PLATFORM_WINDOWS -DLUA_BUILD_AS_DLL)
# Check if building for Android
elseif (${CMAKE_SYSTEM_NAME} MATCHES Android)
  # Add INEPT_PLATFORM_ANDROID preprocessor definition
  add_definitions(-DINEPT_PLATFORM_ANDROID)
# Check if building for macOS
elseif (${CMAKE_SYSTEM_NAME} MATCHES Darwin)
  # Add INEPT_PLATFORM_MACOS preprocessor definition
  add_definitions(-DINEPT_PLATFORM_MACOS)
# Check if building for Linux
elseif (${CMAKE_SYSTEM_NAME} MATCHES UNIX)
  # Add INEPT_PLATFORM_MACOS preprocessor definition
  add_definitions(-DINEPT_PLATFORM_UNIX)
endif()