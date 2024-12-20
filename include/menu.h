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

void updateItems(pMenu item_menu, pMenu food_menu);

void inspectItem(pMenu inspect_menu);

void eat_food(pMenu food_menu,pMenu item_menu);

void update_skill_menu(pMenu skill_menu);

int confirm_menu(pMenu confirm_menu, wchar_t name[32], wchar_t description[128], pMenu parent);

void update_locations(pMenu locationMenu);

void update_talk_menu(pMenu talkToSomeone);

void update_location_activities(pMenu activity_menu);
