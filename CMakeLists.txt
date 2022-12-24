cmake_minimum_required(VERSION 3.21)

project(SkyrimScripting.Plugin VERSION 0.1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

find_package(CommonLibSSE CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} INTERFACE CommonLibSSE::CommonLibSSE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(DIRECTORY include DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/..")

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # static and import libs?
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # .so?
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # .dll
)

install(
    EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}-targets.cmake
    NAMESPACE "SkyrimScriptingPlugin::"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake"
)

configure_file(
    cmake/Config.cmake.in
    ${PROJECT_NAME}Config.cmake
    @ONLY
)

install(
    FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake"
)

add_subdirectory(Examples)
