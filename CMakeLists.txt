cmake_minimum_required(VERSION 2.8)

project(CounterStrike2D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(include include/exception include/sdl)

add_subdirectory(source)
add_executable(showAnImage test/showAnImage.cpp)

target_link_libraries(showAnImage source SDL2 SDL2_image SDL2_mixer Box2D)

add_executable(box2dTest test/box2d.cpp)
target_link_libraries(box2dTest Box2D)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
