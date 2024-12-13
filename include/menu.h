#include <windows.h>
#include <wchar.h>
#ifndef MENU
#define MENU

typedef struct menu{
    wchar_t name[64];
    wchar_t description[128];
    wchar_t menuItems[16][64];
    int itemCount;
    struct menu* children[16];
    struct menu* parent;
}menu,*pmenu;

void initMenu(pmenu menu,wchar_t name[64],wchar_t description[128],wchar_t menuItems[16][64],int itemCount,pmenu children[16],pmenu parent);
void displayMenu(HANDLE stdOut,pmenu menu,int itemIndex,PCOORD coord);
#endif