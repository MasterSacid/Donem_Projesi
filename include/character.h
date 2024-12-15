#ifndef CHARACTER
#define CHARACTER
#include <wchar.h>
#include "locationtime.h"

typedef struct dictValue{
    wchar_t name[16];
    int value;
}dictValue,*pDictValue;

typedef struct stats{
    int constition;
    int charisma;
    int dexterity;
    int intelligence;
    int strength;
    int wisdom;
}stats,*pStats;

typedef struct item{
    wchar_t name[32];
    wchar_t description[128];
    wchar_t type[16];
    int value;
    int itemValues[8];
}item,*pItem;

typedef struct character{
    wchar_t name[32];
    wchar_t locationName[32];
    pLocation locationAdress;
    pItem items[16];
    stats stat;
    int currency;
    int level;
    int health;
    int maxHealth;
}character,*pCharacter;

typedef struct player{
    wchar_t name[32];
    wchar_t locationName[32];
    pLocation locationAdress;
    pItem items[16];
    stats stat;
    int currency;
    int level;
    int xpPoint;
    int health;
    int maxHealth;
    int saturation;
    int exhaustion;
    int mental;
    int abilityPoints;
}player,*pPlayer;

void initStats(pStats stats, int con, int cha, int dex, int inl, int str, int wis);

pItem createItem(wchar_t name[], wchar_t description[], wchar_t type[], int value,int itemValues[]);

pCharacter createNPC(wchar_t name[]);

void updatePlayer(pPlayer Player);

#endif