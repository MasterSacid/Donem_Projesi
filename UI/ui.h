#pragma once
#include <windows.h>
#include "../include/menu.h"
#include "../include/console.h"

int userInteraction(HANDLE stdOut, HANDLE stdIn, pmenu selectedMenu, int *ie, PCOORD coord, pPlayer Player, int *time, message output[]);

void drawUI(HANDLE stdOut, pmenu selectedMenu, int itemIndex, PCOORD coord, pPlayer Player, int *time, message output[]);

int userInput(HANDLE stdIn, pmenu selectedMenu, int *ie);
