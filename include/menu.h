#ifndef MENU.H
#define MENU.H

typedef struct menu{
    char name[64];
    char description[128];
    char menuItems[16][64];
    int itemCount;
    struct menu* children[16];
    struct menu* parent;
}menu,*pmenu;

#endif