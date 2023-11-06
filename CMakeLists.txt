cmake_minimum_required(VERSION 3.22)
project(sdl2-test)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp)

# SDL2 - https://www.libsdl.org/
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "sdl2/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

# GLM - https://glm.g-truc.net/0.9.9/
set(glm_DIR "glm/cmake/glm")
find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} glm::glm)

# GLAD - https://gen.glad.sh/
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
file(GLOB BUTTERFLIES_SOURCES_C ${CMAKE_CURRENT_SOURCE_DIR} *.c glad/src/gl.c)