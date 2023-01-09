cmake_minimum_required(VERSION 3.21)
project(M3OEP)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(M3OEP
        Cat_Bat.cpp
        Cat_Bat.h
        Chicken_Hamster.cpp
        Chicken_Hamster.h
        Home.cpp
        Home.h
        main.cpp
        Pet.cpp
        Pet.h
        Robot_Dragon.cpp
        Robot_Dragon.h
        Spending.cpp
        Spending.h)
