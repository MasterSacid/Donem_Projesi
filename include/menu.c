// Bu dosya menü yapısıyla ilgili fonksiyonlardan oluşur.

#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "character.h"
#include "locationtime.h"
#include "../UI/ui.h"

extern HANDLE STDOUT,STDIN;
extern int ITEM_INDEX;
extern COORD SCREEN_SIZE;
extern int TIME;
extern player PLAYER;
extern pMenu MAIN_MENU;
extern pMenu SELECTED_MENU;


//Menünün değerlerini ayarlamak için kullanılacak fonksiyon
void initMenu(pMenu menu,wchar_t name[64],wchar_t description[128],wchar_t menuItems[][64],int itemCount,pMenu children[16],int childrenCount,pMenu parent){
    wcscpy(menu->name,name);
    wcscpy(menu->description,description);
    menu->itemCount=itemCount;
    menu->childrenCount=childrenCount;
    //child menüleri kopyalar
    for(int i=0;i<childrenCount;i++){
        menu->children[i]=children[i];
    }
    //menuItems'ları kopyalar.
    for(int i=0;i<itemCount;i++){
        wcscpy(menu->menuItems[i],menuItems[i]);
    }
    menu->parent=parent;
    menu->draw_exit=1;
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
    for(int i=0;i<menu->childrenCount;i++){
        if(i==ITEM_INDEX){
            SetConsoleTextAttribute(STDOUT,styleHiglight);
        }
        wprintf(L"> %ls\n",menu->children[i]->name);
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }
    for(int i=0;i<menu->itemCount;i++){
        if(i==ITEM_INDEX){
            SetConsoleTextAttribute(STDOUT,styleHiglight);
        }
        wprintf(L"- %ls\n",menu->menuItems[i]);
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }
    if(ITEM_INDEX>=totalCount){
        SetConsoleTextAttribute(STDOUT,styleHiglight);
    }
    if(wcscmp(menu->name,L"Yetenek Menüsü")==0){
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }else if(menu->parent!=NULL){
        wprintf(L"< %ls",menu->parent->name);
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }else if(wcscmp(menu->name,L"Savaş")==0){
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }else{
        wprintf(L"< Oyundan Çık");
        SetConsoleTextAttribute(STDOUT,styleDefault);
    }
}

void displayHUD(COORD hudPos){
    int savedTime=TIME;
    if(TIME>MAX_TIME){
        TIME=0;
    }
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
    wprintf(L"%ls\n",PLAYER.chr.name);
    wprintf(L"%ls konumundasın.\n\n",PLAYER.chr.locationName);
    wprintf(L"Altın         : %*d\n",5,PLAYER.chr.currency);
    wprintf(L"Seviye        : %*d\n",5,PLAYER.chr.level);
    wprintf(L"Tecrübe puanı : %*d/100\n",5,PLAYER.xpPoint);
    wprintf(L"Can           : %5.0f/%.0f\n",PLAYER.chr.health,PLAYER.chr.maxHealth);
    wprintf(L"Yorgunluk     : %5.0f/100\n",PLAYER.exhaustion);
    wprintf(L"Tokluk        : %5.0f/100\n",PLAYER.saturation);
    wprintf(L"Akıl Sağlığı  : %5.0f/100\n",PLAYER.mental);
    wprintf(L"Hijyen        : %5.0f/100\n",PLAYER.hygiene);
    printf("\n\nSaat %02d:%02d",hour,minute);
}

void updateItems(pMenu item_menu,pMenu food_menu){
    item_menu->itemCount=PLAYER.chr.itemCount;
    int foodC=0;
    int skip=0;
    for(int i=0;i<item_menu->itemCount;i++){
        if(PLAYER.chr.items[i]==NULL){
            continue;
        }
        wcscpy(item_menu->menuItems[i+skip],PLAYER.chr.items[i+skip]->name);
        if(wcscmp(PLAYER.chr.items[i+skip]->type,L"food")==0){
            wcscpy(food_menu->menuItems[foodC+skip],PLAYER.chr.items[i+skip]->name);
            foodC++;
        }
        wcscpy(item_menu->menuItems[i+skip],PLAYER.chr.items[i+skip]->name);
    }
    food_menu->itemCount=foodC;
}

void inspectItem(pMenu inspect_menu){
    wcscpy(inspect_menu->name,PLAYER.chr.items[ITEM_INDEX]->name);
    wcscpy(inspect_menu->description,PLAYER.chr.items[ITEM_INDEX]->description);
}

void eat_food(pMenu food_menu,pMenu item_menu){
    pItem item;
    for(int i=0;i<PLAYER.chr.itemCount;i++){
        if(wcscmp(PLAYER.chr.items[i]->name,food_menu->menuItems[ITEM_INDEX])==0){
            item=PLAYER.chr.items[i];
            break;
        }
    }
    resource_operation(&PLAYER.saturation,(float)getValueByDictName(L"saturation",item->itemValues,item->value),100,0);
    message info;
    swprintf(info.string,sizeof(wchar_t)*512,L"%ls yedin.",item->name);
    removeItem(&PLAYER.chr,item);
    pass_time(300);
    updateItems(item_menu,food_menu);
    sendToRightSection(info);
    clear();
    drawUI();
}

void update_skill_menu(pMenu skill_menu){
    swprintf(skill_menu->description,sizeof(wchar_t)*128,L"Artırmak istediğin yetenekleri\nseç. (%d Puanın var)",PLAYER.abilityPoints);
    for(int i=0;i<6;i++){
        swprintf(&skill_menu->menuItems[i][15],sizeof(wchar_t)*16,L": %d",*(&PLAYER.chr.stat.constitution+i));
    }
}

int confirm_menu(pMenu confirm_menu,wchar_t name[32],wchar_t description[128],pMenu parent){
    SELECTED_MENU=confirm_menu;
    wcscpy(confirm_menu->name,name);
    wcscpy(confirm_menu->description,description);
    confirm_menu->parent=parent;
    userInteraction();
    if(ITEM_INDEX==1){
        SELECTED_MENU=confirm_menu->parent;
        clear();
        drawUI();
        return -1;
    }
    clear();
    drawUI();
    if(ITEM_INDEX==0){
        return 0;
    }else{
        return -1;
    }
}

void update_locations(pMenu locationMenu){
    locationMenu->itemCount=PLAYER.chr.locationAdress->pathCount;
    for(int i=0;i<PLAYER.chr.locationAdress->pathCount;i++){
        swprintf(locationMenu->menuItems[i],sizeof(wchar_t)*64,L"%ls (%.0f dakika)",
        PLAYER.chr.locationAdress->path[i]->name,(float)((PLAYER.chr.locationAdress->pathLength[i])*10/60));
    }
}

void update_talk_menu(pMenu talkToSomeone){
    talkToSomeone->itemCount=PLAYER.chr.locationAdress->characterCount;
    for(int i=0;i<PLAYER.chr.locationAdress->characterCount;i++){
        wcscpy(talkToSomeone->menuItems[i],PLAYER.chr.locationAdress->characters[i]->name);
    }
}

void update_location_activities(pMenu activity_menu){
    activity_menu->itemCount=PLAYER.chr.locationAdress->activityCount;
    wcscpy(activity_menu->name,PLAYER.chr.locationAdress->name);
    swprintf(activity_menu->description,sizeof(wchar_t)*64,L"%ls,\nkonumunda yapılacaklar",PLAYER.chr.locationAdress->name);
    for(int i=0;i<PLAYER.chr.locationAdress->activityCount;i++){
        wcscpy(activity_menu->menuItems[i],PLAYER.chr.locationAdress->activities[i]);
    }
}