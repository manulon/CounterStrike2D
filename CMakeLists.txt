cmake_minimum_required(VERSION 2.8)

project(sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable (showAnImage
  Semana1/showAnImage.cpp  
)

target_link_libraries(showAnImage sdldemo SDL2 SDL2_image)

file(COPY Semana1/assets DESTINATION ${CMAKE_BINARY_DIR})
