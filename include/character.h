#pragma once
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
    dictValue itemValues[8];
}item,*pItem;

typedef struct shop{
    wchar_t name[32];
    wchar_t description[128];
    pItem items[16];
    pItem selected_item;
    int item_prices[16];
    int itemC;
}shop,*pShop;

typedef struct character{
    wchar_t name[64];
    wchar_t locationName[32];
    wchar_t characterClass[32];
    pLocation locationAdress;
    pItem items[16];
    int itemCount;
    stats stat;
    int currency;
    int level;
    float health;
    float maxHealth;
}character,*pCharacter;

typedef struct player{
    character chr;
    pItem selected_item;
    pCharacter selected_character;
    int xpPoint;
    float saturation;
    float exhaustion;
    float mental;
    float hygiene;
    int abilityPoints;
}player,*pPlayer;

void initStats(pStats stats, int con, int cha, int dex, int inl, int str, int wis);

pItem createItem(wchar_t name[], wchar_t description[], wchar_t type[], int value, dictValue itemValues[]);

pCharacter createNPC(wchar_t name[]);

void updatePlayer();

void addItem(pCharacter character, pItem item);

void removeItem(pCharacter character, pItem item);

void array_add_item(pItem item, pItem items[], int *arrayC);

void array_remove_item(pItem item, pItem items[], int *arrayC);

int getValueByDictName(wchar_t name[32], dictValue array[], int i);

void resource_operation(float *resource, float value, float max, float min);

void player_sleep();
