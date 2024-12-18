//
// Created by ahmetak on 12/15/2024.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/menu.h"
#include "../include/console.h"
#include "../include/locationtime.h"
#include "../story/beginning.h"
#include "../include/character.h"
#include "eventhandler.h"
#include "dialogues.h"
#include "beginning.h"
#include "part2.h"

void updateMission(pMenu talkMenu);

void updateCharacters(pMenu talkMenu);

void updateNPCDialog();
