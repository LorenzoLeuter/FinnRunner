cmake_minimum_required(VERSION 3.22)
project(Finn_Runner)

set(CMAKE_CXX_STANDARD 14)

add_executable(Finn_Runner main.cpp GameMap.cpp GameMap.h GameCharacter.cpp GameCharacter.h GameData.cpp GameData.h EnemyObject.cpp EnemyObject.h)

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Finn_Runner sfml-system sfml-window sfml-graphics sfml-audio sfml-network)