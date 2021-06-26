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
include_directories(server/include)
include_directories(mapEditor)
# include_directories(editor)

add_subdirectory(source)
add_subdirectory(server)
add_subdirectory(mapEditor)
# add_subdirectory(editor)
add_executable(showAnImage test/showAnImage.cpp)
target_link_libraries(showAnImage source server SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D)

add_executable(tiles test/tiles.cpp)
target_link_libraries(tiles source server SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D)

# add_executable(dragAndDrop test/pruebaDragAndDrop.cpp)
# target_link_libraries(dragAndDrop source server editor SDL2 SDL2_image SDL2_mixer SDL2_ttf Box2D)

add_executable(box2dTest server/serverMain.cpp)
target_link_libraries(box2dTest server Box2D)

add_executable(mapTest test/makeMap.cpp)
target_link_libraries(mapTest mapEditor yaml-cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
