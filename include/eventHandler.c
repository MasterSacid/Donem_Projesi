#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"
#include "menu.h"
#include "character.h"
#include "eventhandler.h"

void updateMission(int missionC,pmenu talkMenu,pmenu locationMenu){
    updateLocations(missionC, locationMenu);
    updateCharacters(missionC, talkMenu);
}

void updateLocations(int missionC,pmenu locationMenu){

    wchar_t list[][8][64]={
        //Mission 0
        {{L"Location1"},{L"Location2"}},
        //Mission1
        {{L"Location3"},{L"Location4"}},
        //Mission2
        {{L"Location4"},{L"Location"},{L"Location6"}},
    };
    int listCounts[]={2,2,3};

    locationMenu->itemCount=listCounts[missionC];
    for(int i=0;i<listCounts[missionC];i++){
        wcscpy(locationMenu->menuItems[i],list[missionC][i]);
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