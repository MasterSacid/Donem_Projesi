// Bu dosya menü yapısıyla ilgili fonksiyonlardan oluşur.

#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "character.h"
#include "locationtime.h"


//Menünün değerlerini ayarlamak için kullanılacak fonksiyon
void initMenu(pmenu menu,wchar_t name[64],wchar_t description[128],wchar_t menuItems[][64],int itemCount,pmenu children[16],int childrenCount,pmenu parent){
    wcscpy(menu->name,name);
    wcscpy(menu->description,description);
    menu->itemCount=itemCount;
    menu->childrenCount=childrenCount;
    //itemCount'a göre ilerleyerek menuItems'a children'ların isimlerini çeker.
    for(int i=0;i<childrenCount;i++){
        menu->children[i]=children[i];
        wcscpy(menu->menuItems[i],menu->children[i]->name);
    }
    //menuItems'ları kopyalar.
    for(int i=0;i<itemCount;i++){
        wcscpy(menu->menuItems[i+childrenCount],menuItems[i]);
    }
    menu->parent=parent;
}

//Menüyü ekrana yazdıran fonksiyon
void displayMenu(HANDLE stdOut,pmenu menu,int itemIndex,PCOORD coord){
    
    int totalCount=menu->childrenCount+menu->itemCount;

    if(itemIndex>totalCount){
        itemIndex=totalCount;
    }
    printf("================================");
    CONSOLE_SCREEN_BUFFER_INFO buffer=refreshSize(stdOut,coord);
    buffer.dwCursorPosition.X=16-wcslen(menu->name)/2;
    SetConsoleCursorPosition(stdOut,buffer.dwCursorPosition);
    wprintf(L"%s\n\n",menu->name);
    if(menu->description[0]!='\n'){
        wprintf(L"%ls\n",menu->description);
        printf("================================\n\n");
    }else{
        printf("================================\n\n");
        wprintf(L"%ls\n",menu->description);
    }
    for(int i=0;i<totalCount;i++){
        if(i==itemIndex){
            SetConsoleTextAttribute(stdOut,styleHiglight);
        }
        wprintf(L"> %ls\n",menu->menuItems[i]);
        SetConsoleTextAttribute(stdOut,styleDefault);
    }
    if(itemIndex>=totalCount){
        SetConsoleTextAttribute(stdOut,styleHiglight);
    }
    if(menu->parent!=NULL){
        wprintf(L"< %ls",menu->parent->name);
        SetConsoleTextAttribute(stdOut,styleDefault);
    }else{
        wprintf(L"< Oyundan Çık");
        SetConsoleTextAttribute(stdOut,styleDefault);
    }
}

void displayHUD(HANDLE stdOut,pPlayer player,COORD hudPos,int* time){
    int savedTime=*time;
    int hour=0,minute=0;
    if(savedTime>=MAX_TIME){
        savedTime=0;
        hour=0;
        minute=0;
    }
    while(savedTime>=3600){
        savedTime-=3600;
        hour++;
    }
    while(savedTime>=60){
        savedTime-=60;
        minute++;
    }
    SetConsoleCursorPosition(stdOut,hudPos);
    wprintf(L"%ls\n",player->name);
    wprintf(L"%ls konumundasın.\n\n",player->locationName);
    wprintf(L"Altın         : %*d\n",5,player->currency);
    wprintf(L"Seviye        : %*d\n",5,player->level);
    wprintf(L"Tecrübe puanı : %*d/100\n",5,player->xpPoint);
    wprintf(L"Can           : %*d/%d\n",5,player->health,player->maxHealth);
    wprintf(L"Yorgunluk     : %*d/100\n",5,player->exhaustion);
    wprintf(L"Tokluk        : %*d/100\n",5,player->saturation);
    wprintf(L"Akıl Sağlığı  : %*d/100\n",5,player->mental);
    printf("\n\nSaat %02d:%02d",hour,minute);
}