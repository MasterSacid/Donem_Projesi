// Bu dosya menü yapısıyla ilgili fonksiyonlardan oluşur.

#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>


//Menünün değerlerini ayarlamak için kullanılacak fonksiyon
void initMenu(pmenu menu,wchar_t name[64],wchar_t description[128],wchar_t menuItems[16][64],int itemCount,pmenu children[16],pmenu parent){
    wcscpy(menu->name,name);
    wcscpy(menu->description,description);
    menu->itemCount=itemCount;
    //0'dan 15'e kadar ilerleyerek menuItems'ları kopyalar.
    for(int i=0;i<16;i++){
        if(menuItems!=NULL){
            wcscpy(menu->menuItems[i],menuItems[i]);
        }
    }
    //itemCount'a göre ilerleyerek menuItems'a children'ların isimlerini çeker.
    for(int i=0;i<itemCount;i++){
        if(children!=NULL){
            menu->children[i]=children[i];
            wcscpy(menu->menuItems[i],menu->children[i]->name);
        }
    }
    menu->parent=parent;
}

//Menüyü ekrana yazdıran fonksiyon
void displayMenu(HANDLE stdOut,pmenu menu,int itemIndex,PCOORD coord){

    if(itemIndex>menu->itemCount){
        itemIndex=menu->itemCount;
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

    for(int i=0;i<menu->itemCount;i++){
        if(i==itemIndex){
            SetConsoleTextAttribute(stdOut,styleHiglight);
        }
        wprintf(L"> %ls\n",menu->menuItems[i]);
        SetConsoleTextAttribute(stdOut,styleDefault);
    }
    if(itemIndex>menu->itemCount-1){
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