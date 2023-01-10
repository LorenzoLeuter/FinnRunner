cmake_minimum_required(VERSION 3.22)
project(FinnRunner)

set(CMAKE_CXX_STANDARD 11)

add_executable(FinnRunner main.cpp GameCharacter.h GameData.cpp GameData.h Hero.cpp Hero.h Observer.h Subject.h DisplayElement.h Achievement.cpp Achievement.h ZombieToast.cpp ZombieToast.h Bat.cpp Bat.h PowerUp.cpp PowerUp.h PowerUpFactory.cpp PowerUpFactory.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(FinnRunner sfml-system sfml-window sfml-audio sfml-graphics)
