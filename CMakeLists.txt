cmake_minimum_required(VERSION 3.11)
project(InputSomething LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

message(STATUS ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB InputSomething_SRC
    "*main.cpp"
    "*InputSomething.cpp"
    "*InputSomething.h"
)

add_executable(InputSomething ${InputSomething_SRC}) 

target_link_libraries(InputSomething ${SDL2_LIBRARIES} SDL2_Image SDL2_ttf)
