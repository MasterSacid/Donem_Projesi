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
        include/locationtime.c
        include/locationtime.h
        include/narrative.h
        include/narrative.c
        include/combat.h
        include/combat.c
        include/eventhandler.c
        include/eventhandler.h
        story/beginning.c
        story/beginning.h
        story/part2.h
        story/part2.c
        UI/ui.h
        UI/ui.c
        include/dialogues.c
        include/dialogues.h

)

target_link_libraries(Donem_Projesi winmm)