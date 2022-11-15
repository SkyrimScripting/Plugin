cmake_minimum_required(VERSION 3.21)

project(YourModNameHere VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CommonLibSSE CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h include/*.h)

add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
include_directories(${PROJECT_NAME} include)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/PCH.h)

enable_testing()
set(TEST_PROJECT_NAME ${PROJECT_NAME}.Tests)
file(GLOB_RECURSE UNIT_TESTS_SOURCE test/*.cpp test/*.h)
add_executable(${TEST_PROJECT_NAME} ${UNIT_TESTS_SOURCE})
include_directories(${TEST_PROJECT_NAME} include)
find_path(BANDIT_INCLUDE_DIRS "bandit/adapters.h")
target_include_directories(${TEST_PROJECT_NAME} PRIVATE ${BANDIT_INCLUDE_DIRS})
find_path(SNOWHOUSE_INCLUDE_DIRS "snowhouse/assert.h")
target_include_directories(${TEST_PROJECT_NAME} PRIVATE ${SNOWHOUSE_INCLUDE_DIRS})

add_custom_command(
	TARGET "${PROJECT_NAME}"
	POST_BUILD
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/${PROJECT_NAME}.dll"
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/${PROJECT_NAME}.pdb"
	VERBATIM
)
