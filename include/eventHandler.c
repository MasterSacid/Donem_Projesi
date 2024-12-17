#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"
#include "menu.h"
#include "character.h"
#include "eventhandler.h"
#include "../story/beginning.h"
#include "../story/part2.h"

void updateMission(int* missionC,pmenu talkMenu){
    updateCharacters(*missionC, talkMenu);
    (*missionC)++;
    switch (*missionC)
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

void updateNPCDialog(int missionC,int selectedPerson){
    if(missionC==0){
        if(selectedPerson==0){
            system("cls");
            wprintf(L"Konuşma 1");
            Sleep(1000);
        }
        if(selectedPerson==1){
            system("cls");
            wprintf(L"Konuşma 2");
            Sleep(1000);
        }
    }
}