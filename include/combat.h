#pragma once
#include "combat.h"
#include "character.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include "console.h"
#include "../UI/ui.h"

#define t_character 0
#define t_player 1

#define cha 0
#define cons 1
#define dext 2
#define inte 3
#define stre 4
#define wisd 5

void initCombatMenus();

int initCombat(pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

char isIn(int number, int array[], int size);

void emptyArray(int array[], int size);

int playerTurn(pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

void playTurnAlly(pCharacter ally, pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

void playTurnEnemy(pCharacter enemy, pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

int try_to_run();

void character_attack(pCharacter actor, pCharacter target);

void player_attack();

pCharacter randomTarget(pCharacter characters[], int targetC, char incPlayer);

void updateTargets(pCharacter enemies[], int enemyC, pMenu caller);

int is_eligible(int i, int list[], pCharacter allies[], int allyC, pCharacter enemies[], int enemyC);

int combatant_state_check(pCharacter allies[], int *allyC, pCharacter enemies[], int *enemyC, int *exp, int *currency);

void update_attack_weapons();

pItem findItemByName(pCharacter chr, wchar_t name[]);

void view_stats(pCharacter targets[], int targetI);
