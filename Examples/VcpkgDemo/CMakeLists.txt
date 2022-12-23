cmake_minimum_required(VERSION 3.21)

project(PluginVcpkgDemo VERSION 0.0.1 LANGUAGES CXX)

add_skse_plugin(${PROJECT_NAME} SOURCES plugin.cpp)
