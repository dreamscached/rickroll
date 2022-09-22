cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME RickrollCXX)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE PROJECT_FILES src/**.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

if (CMAKE_SYSTEM_NAME EQUAL Darwin)
    target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation")
    target_link_libraries(${PROJECT_NAME} "-framework ApplicationServices")
endif ()
