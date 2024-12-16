#include <windows.h>
#include <wchar.h>
#include "character.h"
#ifndef MENU
#define MENU

typedef struct menu{
    wchar_t name[64];
    wchar_t description[128];
    wchar_t menuItems[16][64];
    int itemCount;
    struct menu* children[16];
    int childrenCount;
    struct menu* parent;
}menu,*pmenu;

void initMenu(pmenu menu, wchar_t name[64], wchar_t description[128], wchar_t menuItems[][64], int itemCount, pmenu children[16], int childrenCount, pmenu parent);
void displayMenu(HANDLE stdOut, pmenu menu, int itemIndex, PCOORD coord);
void displayHUD(HANDLE stdOut, pPlayer player, COORD hudPos,int* time);
int dialogChoice(HANDLE stdOut, HANDLE stdIn, wchar_t string[], wchar_t opts[][64], int optCount);
#endif