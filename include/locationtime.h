#pragma once
#include <wchar.h>
#define MAX_TIME 86400

struct character;
typedef struct character* pCharacter;

typedef struct location{
    wchar_t name[32];
    wchar_t description[128];
    struct location* path[16];
    int pathLength[16];
    int pathCount;
    pCharacter character[16];
    int characterCount;
}location, *pLocation;

void pass_time(int time);

void change_location(pLocation location);
