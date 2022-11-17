cmake_minimum_required(VERSION 3.21)

project(SkyrimScripting.Plugin VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h include/*.h)

find_package(CommonLibSSE CONFIG REQUIRED)
add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
include_directories(${PROJECT_NAME} include)
target_precompile_headers(${PROJECT_NAME} PUBLIC include/SkyrimScripting/Plugin/PCH.h)
