#pragma once
#include <wchar.h>
#define MAX_TIME 86400

struct character;
struct menu;
typedef struct menu* pMenu;
typedef struct character* pCharacter;
struct shop;
typedef struct shop* pShop;


typedef struct location{
    wchar_t name[32];
    wchar_t description[128];
    struct location* path[16];
    int pathLength[16];
    int pathCount;
    pCharacter characters[16];
    int characterCount;
    wchar_t activities[8][32];
    int activityCount;
}location, *pLocation;

void pass_time(int time);

void change_location(pLocation location);

void location_activity_handler(pLocation locations[], pMenu menus[], pShop shops[],pShop *selected_shop);