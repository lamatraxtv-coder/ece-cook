cmake_minimum_required(VERSION 3.26)
project(allegro C)

set(CMAKE_C_STANDARD 11)

add_executable(allegro main.c)


target_link_libraries(allegro mingw32 alleg44)
