#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/menu.h"
#include "../include/console.h"
#include "../story/beginning.h"
#include "../include/character.h"
#include "../include/locationtime.h"
#include "eventhandler.h"
#include "dialogues.h"
#include "beginning.h"
#include "part2.h"
extern int MISSION_COUNTER,ITEM_INDEX;
extern message GAME_MESSAGES[];

void updateMission(pLocation tavern,int listCounts[],pCharacter chars[][32]){
    updateCharacters(tavern,listCounts,chars);
    (MISSION_COUNTER)++;
    switch (MISSION_COUNTER)
    {
    case 1:
        beginning();
        break;
    case 2:
        bolum_2_savas();
        break;
    default:
        break;
    }
}


void updateCharacters(pLocation tavern,int listCounts[],pCharacter chars[][32]){

    tavern->characterCount=listCounts[MISSION_COUNTER];
    for(int i=0;i<listCounts[MISSION_COUNTER];i++){
        tavern->characters[i]=chars[MISSION_COUNTER][i];
    }
}

void updateNPCDialog(){
        if(ITEM_INDEX==0){
            dialoguePerson0();
        }
        if(ITEM_INDEX==1){
            dialoguePerson1();
        }
         if(ITEM_INDEX==2) {
            dialoguePerson2();
         }
         if(ITEM_INDEX==3) {
             dialoguePerson3();
         }
}