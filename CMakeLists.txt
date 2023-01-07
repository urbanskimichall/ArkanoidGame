cmake_minimum_required(VERSION 3.15)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 17)
add_executable(Arkanoid main.cpp Platform.cpp Platform.h Ball.cpp Ball.h BallMovement.cpp BallMovement.h BallDirections.h GameOver.cpp GameOver.h Blocks.cpp Blocks.h ShootingBonus.cpp ShootingBonus.h BlockDestroyer.cpp BlockDestroyer.h Bonus.h BonusManager.cpp BonusManager.h)
include_directories(C:/SFML/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

if(SFML_FOUND)
    include_directories(C:/SFML/include)
    target_link_libraries(Arkanoid sfml-system sfml-window sfml-graphics sfml-audio)
endif()

