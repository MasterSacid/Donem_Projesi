#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"
#include "menu.h"
#include "character.h"
#include "eventhandler.h"

void updateMission(int* missionC,pmenu talkMenu,void* storyPart){
    updateCharacters(*missionC, talkMenu);
    (*missionC)++;
}


void updateCharacters(int missionC,pmenu talkMenu){

    wchar_t list[][8][64]={
        //Mission 0
        {{L"Person1"},{L"Person2"}},
        //Mission1
        {{L"Person2"},{L"Person3"}},
        //Mission2
        {{L"Person4"},{L"Person5"},{L"Person6"}},
    };
    int listCounts[]={2,2,3};

    talkMenu->itemCount=listCounts[missionC];
    for(int i=0;i<listCounts[missionC];i++){
        wcscpy(talkMenu->menuItems[i],list[missionC][i]);
    }
}

void moveToTavern(pmenu locationMenu){
    locationMenu->itemCount=4;
    for(int i=0;i<4;i++){
        wcscpy(locationMenu->menuItems[i],L"Şifahane");
        wcscpy(locationMenu->menuItems[i],L"Silahçı");
        wcscpy(locationMenu->menuItems[i],L"Erzak dükkanı");
        wcscpy(locationMenu->menuItems[i],L"Odana çık ve uyu");
    }
}