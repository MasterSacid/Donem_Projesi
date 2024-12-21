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
#include "../story/beginning.h"
#include "../story/part2.h"
#include "../story/part3.h"
#include "../story/part4.h"
#include "../story/part5.h"
#include "../story/part6.h"
#include "../story/part7.h"
#include "../story/part8.h"
#include "../story/part9.h"

extern int MISSION_COUNTER,ITEM_INDEX;
extern message GAME_MESSAGES[];

void updateMission(pLocation tavern,int listCounts[],pCharacter chars[][32]){
    updateCharacters(tavern,listCounts,chars);
    (MISSION_COUNTER)++;
    switch (MISSION_COUNTER)
    {
        case 1:
            //part2();
                printf("comething");
                Sleep(1000);

        break;
        case 2:
           // part3();
        printf("comething");
        Sleep(1000);
        break;

        case 3:
           // part4();
        printf("comething");
        Sleep(1000);
        break;
        case 4:
           // part5();
        printf("comething");
        Sleep(1000);
        break;
        case 5:
           // part5();
        printf("comething");
        Sleep(1000);
        break;
        case 6:
           // part6();
        printf("comething");
        Sleep(1000);
        break;
        case 7:
           // part7();
        printf("comething");
        Sleep(1000);
        break;
        case 8:
           // part8();
        printf("comething");
        Sleep(1000);
        break;
        case 9:
            //part9();
        printf("comething");
        Sleep(1000);
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
    if(ITEM_INDEX==4) {
        dialoguePerson4();
    }
}


