#pragma once
#include "combat.h"
#include "character.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include "console.h"
#include "../UI/ui.h"

void initCombat(pMenu combat_menu, pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

char isIn(int number, int array[], int size);

void emptyArray(int array[], int size);

void playerTurn(pMenu combat_menu);

void playTurnAlly(pCharacter ally);

void playTurnEnemy(pCharacter enemy);