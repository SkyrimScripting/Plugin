cmake_minimum_required(VERSION 3.21)

project(SkyrimScripting.Plugin VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

find_package(CommonLibSSE CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} INTERFACE CommonLibSSE::CommonLibSSE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(Examples)
