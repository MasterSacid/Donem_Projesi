#pragma once
#include <windows.h>
#include "../include/menu.h"
#include "../include/console.h"

int userInteraction(HANDLE stdOut, HANDLE stdIn, pmenu selectedMenu, int *itemIndex, PCOORD coord, pPlayer Player, int *time, message output[]);
