#pragma once
#include <windows.h>
#include <wchar.h>
#include "character.h"

typedef struct menu{
    wchar_t name[64];
    wchar_t description[128];
    wchar_t menuItems[16][64];
    int itemCount;
    void (*fptrArray[16])(void);
    struct menu* children[16];
    int childrenCount;
    struct menu* parent;
}menu,*pMenu;

void initMenu(pMenu menu, wchar_t name[64], wchar_t description[128], wchar_t menuItems[][64], int itemCount, pMenu children[16], int childrenCount, pMenu parent);
void displayMenu(pMenu menu);
void displayHUD(COORD hudPos);
