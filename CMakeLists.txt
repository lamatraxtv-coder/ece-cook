cmake_minimum_required(VERSION 3.00)
project(allegro C)

set(CMAKE_C_STANDARD 99)

add_executable(allegro main.c
        sous-programme.c
        librairies.h
        Aliments.c)


target_link_libraries(allegro mingw32 alleg44)