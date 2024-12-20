#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "../include/rolldice.h"
#include "eventhandler.h"
#include "../include/console.h"
#include "narrative.h"

extern int ITEM_INDEX;
extern int MISSION_COUNTER;



void displayNumberFromFile(int number);
void clearScreen();
void playSoundAndWait(const char* soundFile);
void displaySequence(int sequence[], int length,int untilThatNumber);
int userInputForMinigame(int sequence[], int length,int untilThatNumber);
int memoryGame(int untilThatNumber);
int minigamePicker (int ITEM_INDEX,int MISSION_COUNTER);
