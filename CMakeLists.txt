cmake_minimum_required(VERSION 3.30)
project(Donem_Projesi C)

set(CMAKE_C_STANDARD 11)

add_executable(Donem_Projesi
        include/console.c
        include/console.h
        include/menu.c
        include/menu.h
        include/arthandler.c
        include/arthandler.c
        main.c
)

target_link_libraries(Donem_Projesi winmm)