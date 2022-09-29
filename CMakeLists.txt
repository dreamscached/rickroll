cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

# Project metadata
set(PROJECT_NAME RickrollCXX)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# External projects (pull from GitHub and alike) setup
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
include(ExternalProject)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

# Add CLI11 external project
ExternalProject_add(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11 GIT_TAG main
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

# Build executable from *.cpp files under src/
file(GLOB_RECURSE PROJECT_FILES src/**.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Add CLI11 dependency
add_dependencies(${PROJECT_NAME} CLI11)

# Set executable base name to rickroll
set(PROJECT_EXECUTABLE_NAME rickroll)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_EXECUTABLE_NAME})

if (${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation")
    target_link_libraries(${PROJECT_NAME} "-framework ApplicationServices")
endif()
