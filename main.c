#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "console.h"

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
    return 0;
    displayMenu(stdOut,&main_menu,0);
}

