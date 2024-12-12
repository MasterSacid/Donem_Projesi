#include <windows.h>
#ifndef MENU
#define MENU

typedef struct menu{
    char name[64];
    char description[128];
    char menuItems[16][64];
    int itemCount;
    struct menu* children[16];
    struct menu* parent;
}menu,*pmenu;

void initMenu(pmenu menu,char name[64],char description[128],char menuItems[16][64],int itemCount,pmenu children[16],pmenu parent);
void displayMenu(HANDLE stdOut,pmenu menu,int itemIndex,PCOORD coord);
#endif