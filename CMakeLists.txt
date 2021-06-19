cmake_minimum_required(VERSION 2.8)

project(CounterStrike2D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -pedantic-errors -O3")

include_directories(include 
					include/Exception 
					include/SDL/Init
					include/SDL/Renderer
					include/SDL/Sound
					include/SDL/Texture
					include/SDL/Window)

add_subdirectory(source)
add_executable(showAnImage test/showAnImage.cpp)
target_link_libraries(showAnImage source SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D)

add_subdirectory(server)
add_executable(box2dTest server/serverMain.cpp)
target_link_libraries(box2dTest server Box2D)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
