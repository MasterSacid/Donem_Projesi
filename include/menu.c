// Bu dosya menü yapısıyla ilgili fonksiyonlardan oluşur.

#include <stdio.h>
#include "menu.h"
#include "console.h"

#ifdef _WIN32
#include <windows.h>
#endif


//Menünün değerlerini ayarlamak için kullanılacak fonksiyon
void initMenu(pmenu menu,char name[64],char description[128],char menuItems[16][64],int itemCount,pmenu children[16],pmenu parent){
    strcpy(menu->name,name);
    strcpy(menu->description,description);
    menu->itemCount=itemCount;
    //0'dan 15'e kadar ilerleyerek menuItems'ları kopyalar.
    for(int i=0;i<16;i++){
        if(menuItems!=NULL){
            strcpy(menu->menuItems[i],menuItems[i]);
        }
    }
    //itemCount'a göre ilerleyerek menuItems'a children'ların isimlerini çeker.
    for(int i=0;i<itemCount;i++){
        if(children!=NULL){
            menu->children[i]=children[i];
            strcpy(menu->menuItems[i],menu->children[i]->name);
        }
    }
    menu->parent=parent;
}

//Menüyü ekrana yazdıran fonksiyon
void displayMenu(HANDLE stdOut,pmenu menu,int itemIndex){

    if(itemIndex>menu->itemCount){
        itemIndex=menu->itemCount;
    }
    printf("================================");
    CONSOLE_SCREEN_BUFFER_INFO buffer=refreshSize(stdOut);
    buffer.dwCursorPosition.X=16-strlen(menu->name)/2;
    SetConsoleCursorPosition(stdOut,buffer.dwCursorPosition);
    printf("%s\n\n",menu->name);
    if(menu->description[0]!='\n'){
        printf("%s\n",menu->description);
        printf("================================\n\n");
    }else{
        printf("================================\n\n");
        printf("%s\n",menu->description);
    }

    for(int i=0;i<menu->itemCount;i++){
        if(i==itemIndex){
            SetConsoleTextAttribute(stdOut,styleHiglight);
        }
        printf("> %s\n",menu->menuItems[i]);
        SetConsoleTextAttribute(stdOut,styleDefault);
    }
    if(itemIndex>menu->itemCount-1){
        SetConsoleTextAttribute(stdOut,styleHiglight);
    }
    if(menu->parent!=NULL){
        printf("< %s",menu->parent->name);
        SetConsoleTextAttribute(stdOut,styleDefault);
    }else{
        printf("< Exit");
        SetConsoleTextAttribute(stdOut,styleDefault);
    }
}