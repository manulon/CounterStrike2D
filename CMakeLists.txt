cmake_minimum_required(VERSION 2.8)

project(CounterStrike2D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -Werror -pedantic -pedantic-errors -O3 -pthread")

include_directories(client/include 
					client/include/Exception 
					client/include/SDL/Init
					client/include/SDL/Color
					client/include/SDL/Renderer
					client/include/SDL/Sound
					client/include/SDL/Texture
					client/include/SDL/Window
					)
include_directories(server/include)
include_directories(mapEditor)

FILE(GLOB_RECURSE source "client/source/*.cpp")
FILE(GLOB_RECURSE server "server/source/*.cpp")
FILE(GLOB_RECURSE common "common/*.cpp")
FILE(GLOB_RECURSE mapEditor "mapEditor/*.cpp")

add_executable(editor test/editor.cpp ${mapEditor} ${server} ${source} ${common})
target_link_libraries(editor SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(showAnImage test/showAnImage.cpp ${server} ${source} ${common})
target_link_libraries(showAnImage SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

# add_executable(tiles test/tiles.cpp ${server} ${source})
# target_link_libraries(tiles SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(serverTest test/serverTest.cpp ${server})
target_link_libraries(serverTest Box2D yaml-cpp)

# add_executable(mapTest test/makeMap.cpp ${source} ${server} ${mapEditor})
# target_link_libraries(mapTest SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
