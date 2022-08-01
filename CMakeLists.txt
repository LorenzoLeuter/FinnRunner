cmake_minimum_required(VERSION 3.22)
project(FinnRunner)

set(CMAKE_CXX_STANDARD 11)

add_executable(FinnRunner main.cpp GameMap.cpp GameMap.h GameCharacter.cpp GameCharacter.h GameData.cpp GameData.h EnemyObject.cpp EnemyObject.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(FinnRunner sfml-system sfml-window sfml-audio sfml-graphics)
