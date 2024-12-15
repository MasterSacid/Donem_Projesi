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
        include/rolldice.c
        include/rolldice.h
        include/character.c
        include/character.h
<<<<<<< HEAD
        include/locationtime.c
        include/locationtime.h
=======
        include/eventHandler.c
        include/eventHandler.h
>>>>>>> 43cf947cb7eb5bf412c1c35b5eeed1e4def3e9eb
)

target_link_libraries(Donem_Projesi winmm)