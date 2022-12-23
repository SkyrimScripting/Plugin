project(PluginDemo VERSION 0.0.1 LANGUAGES CXX)

find_package(SkyrimScripting.CMake CONFIG REQUIRED)

set(SKYRIMSCRIPTING_DEBUG true)
add_skse_plugin(${PROJECT_NAME} SOURCES plugin.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SkyrimScripting.Plugin)
