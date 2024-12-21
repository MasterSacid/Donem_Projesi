cmake_minimum_required(VERSION 3.30)
project(Donem_Projesi C)

set(CMAKE_C_STANDARD 11)

add_executable(Donem_Projesi
        main.c
        include/console.c
        include/console.h
        include/menu.c
        include/menu.h
        include/arthandler.c
        include/arthandler.c
        include/rolldice.c
        include/rolldice.h
        include/character.c
        include/character.h
        include/locationtime.c
        include/locationtime.h
        include/combat.h
        include/combat.c
        story/eventhandler.c
        story/eventhandler.h
        story/narrative.h
        story/narrative.c
        story/beginning.c
        story/beginning.h
        story/part2.h
        story/part2.c
        story/dialogues.c
        story/dialogues.h
        UI/ui.h
        UI/ui.c
        story/minimissions.c
        story/minimissions.h
        story/part3.c
        story/part3.h
        story/part4.c
        story/part4.h
        story/part5.c
        story/part5.h
        story/part6.c
        story/part6.h
        story/part7.c
        story/part7.h
        story/part8.c
        story/part8.h
        story/part9.c
        story/part9.h

)

target_link_libraries(Donem_Projesi winmm)