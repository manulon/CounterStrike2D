cmake_minimum_required(VERSION 2.8)

project(CounterStrike2D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -Werror -pedantic -pedantic-errors -O3")

include_directories(include 
					include/Exception 
					include/SDL/Init
					include/SDL/Color
					include/SDL/Renderer
					include/SDL/Sound
					include/SDL/Texture
					include/SDL/Window
					)
include_directories(server/include)
include_directories(mapEditor)

FILE(GLOB_RECURSE source "source/*.cpp")
FILE(GLOB_RECURSE server "server/source/*.cpp")
FILE(GLOB_RECURSE mapEditor "mapEditor/*.cpp")

add_executable(dragAndDrop test/pruebaDragAndDrop.cpp ${mapEditor} ${server} ${source})
target_link_libraries(dragAndDrop SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(showAnImage test/showAnImage.cpp ${server} ${source})
target_link_libraries(showAnImage SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(tiles test/tiles.cpp ${server} ${source})
target_link_libraries(tiles SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

add_executable(box2dTest server/serverMain.cpp ${server})
target_link_libraries(box2dTest Box2D yaml-cpp)

add_executable(mapTest test/makeMap.cpp ${source} ${server} ${mapEditor})
target_link_libraries(mapTest SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)



#add_subdirectory(source)
#add_subdirectory(server)
#add_subdirectory(mapEditor)

#add_executable(dragAndDrop test/pruebaDragAndDrop.cpp)
#target_link_libraries(dragAndDrop source mapEditor SDL2_ttf SDL2 SDL2_image yaml-cpp)

#add_executable(showAnImage test/showAnImage.cpp)
#target_link_libraries(showAnImage source server SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

#add_executable(tiles test/tiles.cpp)
#target_link_libraries(tiles source server SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D yaml-cpp)

#add_executable(box2dTest server/serverMain.cpp)
#target_link_libraries(box2dTest server Box2D)

#add_executable(mapTest test/makeMap.cpp)
#target_link_libraries(mapTest mapEditor yaml-cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
