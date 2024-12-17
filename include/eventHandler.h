//
// Created by ahmetak on 12/15/2024.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"

void updateMission(int missionC, pmenu talkMenu, pmenu locationMenu);

void updateLocations(int missionC, pmenu locationMenu);

void updateCharacters(int missionC, pmenu talkMenu);

#endif //EVENTHANDLER_H