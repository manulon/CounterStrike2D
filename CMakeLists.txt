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
include_directories(client/threads/include
					client/messagesFromServer/include)					
include_directories(common)
include_directories(server/include
					server/threads/include
					server/include/events
					server/include/messages)
include_directories(mapEditor)

FILE(GLOB_RECURSE source "client/source/*.cpp")
FILE(GLOB_RECURSE server "server/*.cpp")
FILE(GLOB_RECURSE serverThreads "server/threads/source/*.cpp")
FILE(GLOB_RECURSE common "common/*.cpp")
FILE(GLOB_RECURSE mapEditor "mapEditor/*.cpp")
FILE(GLOB_RECURSE nbq "common/NonBlockingQueue.cpp")
FILE(GLOB_RECURSE serverMessages "server/source/messages/*.cpp")
FILE(GLOB_RECURSE serverEvents "server/source/events/*.cpp")
FILE(GLOB_RECURSE clientExceptions "client/source/Exception/*.cpp")

add_executable(editor mapEditor/main/editor.cpp ${mapEditor} ${source} ${common})
target_link_libraries(editor SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(server server/source/server.cpp ${common} ${server} ${serverMessages} ${serverThreads} ${nbq})
target_link_libraries(server Box2D yaml-cpp)

add_executable(client client/main/client.cpp ${common} ${source})
target_link_libraries(client SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)



file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})