#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"

COORD coord;

int main(void) {
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);
    menu main_menu;
    initMenu(
        &main_menu,
        "Ana Menu",
        "Ana menu aciklama",
        NULL,
        0,
        NULL,
        NULL
    );
    displayMenu(stdOut,&main_menu,0,&coord);
    return 0;
}

