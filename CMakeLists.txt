cmake_minimum_required(VERSION 3.22)
project(FinnRunner)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


set(SOURCE_FILES
        Achievement.cpp
        Achievement.h
        Bat.cpp
        Bat.h
        DisplayElement.h
        GameCharacter.h
        GameData.cpp
        GameData.h
        Hero.cpp
        Hero.h
        main.cpp
        Observer.h
        PowerUp.cpp
        PowerUp.h
        PowerUpFactory.cpp
        PowerUpFactory.h
        Subject.h
        ZombieToast.cpp
        ZombieToast.h)

add_executable(FinnRunner main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
add_library(core ${SOURCE_FILES})
target_link_libraries(core sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(FinnRunner core)
add_subdirectory(unit_testing)




