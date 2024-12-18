// Bu dosya menü yapısıyla ilgili fonksiyonlardan oluşur.

#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "character.h"
#include "locationtime.h"

extern HANDLE STDOUT,STDIN;
extern int ITEM_INDEX;
extern COORD SCREEN_SIZE;
extern int TIME;
extern player PLAYER;


//Menünün değerlerini ayarlamak için kullanılacak fonksiyon
void initMenu(pMenu menu,wchar_t name[64],wchar_t description[128],wchar_t menuItems[][64],int itemCount,pMenu children[16],int childrenCount,pMenu parent){
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
void displayMenu(pMenu menu){
    
    int totalCount=menu->childrenCount+menu->itemCount;

    if(ITEM_INDEX>totalCount){
        ITEM_INDEX=totalCount;
    }
    printf("================================");
    CONSOLE_SCREEN_BUFFER_INFO buffer=refreshSize();
    buffer.dwCursorPosition.X=16-wcslen(menu->name)/2;
    SetConsoleCursorPosition(STDOUT,buffer.dwCursorPosition);
    wprintf(L"%s\n\n",menu->name);
    if(menu->description[0]!='\n'){
        wprintf(L"%ls\n",menu->description);
        printf("================================\n\n");
    }else{
        printf("================================\n\n");
        wprintf(L"%ls\n",menu->description);
    }
    for(int i=0;i<totalCount;i++){
        if(i==ITEM_INDEX){
            SetConsoleTextAttribute(STDOUT,styleHiglight);
        }
        wprintf(L"> %ls\n",menu->menuItems[i]);
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }
    if(ITEM_INDEX>=totalCount){
        SetConsoleTextAttribute(STDOUT,styleHiglight);
    }
    if(menu->parent!=NULL){
        wprintf(L"< %ls",menu->parent->name);
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }else{
        wprintf(L"< Oyundan Çık");
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }
}

void displayHUD(COORD hudPos){
    int savedTime=TIME;
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
    SetConsoleCursorPosition(STDOUT,hudPos);
    wprintf(L"%ls\n",PLAYER.name);
    wprintf(L"%ls konumundasın.\n\n",PLAYER.locationName);
    wprintf(L"Altın         : %*d\n",5,PLAYER.currency);
    wprintf(L"Seviye        : %*d\n",5,PLAYER.level);
    wprintf(L"Tecrübe puanı : %*d/100\n",5,PLAYER.xpPoint);
    wprintf(L"Can           : %*d/%d\n",5,PLAYER.health,PLAYER.maxHealth);
    wprintf(L"Yorgunluk     : %*d/100\n",5,PLAYER.exhaustion);
    wprintf(L"Tokluk        : %*d/100\n",5,PLAYER.saturation);
    wprintf(L"Akıl Sağlığı  : %*d/100\n",5,PLAYER.mental);
    printf("\n\nSaat %02d:%02d",hour,minute);
}