//
// Created by ahmetak on 12/15/2024.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"
#include "../story/beginning.h"

void updateMission(int *missionC, pmenu talkMenu);

void updateCharacters(int missionC, pmenu talkMenu);

void updateNPCDialog(int missionC, int selectedPerson);
