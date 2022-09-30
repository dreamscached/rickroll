cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

# Project metadata
set(PROJECT_NAME RickrollCXX)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# External projects (pull from GitHub and alike) setup
include(FetchContent)

# Pull CLI11 external project
FetchContent_Declare(
        cli11_proj
        QUIET
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.2.0
)
FetchContent_MakeAvailable(cli11_proj)

# Build executable from *.cpp files under src/
file(GLOB_RECURSE PROJECT_FILES src/**.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Include CLI11 project
include_directories(${cli11_proj_SOURCE_DIR}/include)

# Set executable base name to rickroll
set(PROJECT_EXECUTABLE_NAME rickroll)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_EXECUTABLE_NAME})

if (${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation")
    target_link_libraries(${PROJECT_NAME} "-framework ApplicationServices")
endif()
