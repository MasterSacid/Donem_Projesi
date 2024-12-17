#ifndef COMBAT
#define COMBAT
#include "combat.h"
#include "character.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>

void initCombat(pPlayer Player, pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

char isIn(int number, int array[], int size);

void emptyArray(int array[], int size);

void playerTurn();

void playTurnAlly();

void playTurnEnemy();

#endif

