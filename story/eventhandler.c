#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/locationtime.h"
#include "../include/menu.h"
#include "../include/character.h"
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

void updateMission(pMenu talkMenu){
    updateCharacters(talkMenu);
    (MISSION_COUNTER)++;
    switch (MISSION_COUNTER)
    {
    case 1:
        //beginning();
        //part3();
        //part4();
        //part5();
        //part6();
        //part7();
        //part8();
        //part9();

        break;
    case 2:
        part2();
        break;
    default:
        break;
    }
}


void updateCharacters(pMenu talkMenu){

    wchar_t list[][8][64]={
        //Mission 0
        {{L"Person1"},{L"Person2"}},
        //Mission1
        {{L"Person2"},{L"Person3"}},
        //Mission2
        {{L"Person4"},{L"Person5"},{L"Person6"}},
    };
    int listCounts[]={2,2,3};

    talkMenu->itemCount=listCounts[MISSION_COUNTER];
    for(int i=0;i<listCounts[MISSION_COUNTER];i++){
        wcscpy(talkMenu->menuItems[i],list[MISSION_COUNTER][i]);
    }
}

void moveToTavern(pMenu locationMenu){
    locationMenu->itemCount=4;
    for(int i=0;i<4;i++){
        wcscpy(locationMenu->menuItems[i],L"Şifahane");
        wcscpy(locationMenu->menuItems[i],L"Silahçı");
        wcscpy(locationMenu->menuItems[i],L"Erzak dükkanı");
        wcscpy(locationMenu->menuItems[i],L"Odana çık ve uyu");
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


