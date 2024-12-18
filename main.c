#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"
#include "include/arthandler.h"
#include "include/rolldice.h"
#include "include/effects.h"
#include <wchar.h>
#include <locale.h>
#include "include\character.h"
#include "include\locationtime.h"
#include "include/narrative.h"
#include "include/combat.h"
#include <stdlib.h>
#include "include/eventhandler.h"
#include "story/beginning.h"
#include "UI/ui.h"
#include "include/dialogues.h"

int centerArtX(); //Bu fonksiyon main içinde olmak zorunda

int exitProgram(HANDLE stdOut, PCOORD coord, void **collectionAdress);

int missionC=0;

// Ekran boyutunu saklamak için açılan COORD yapısı
COORD coord;
char artBuffer [4096]; //Ascii tablolarının maks karakter sayısı

int collectionSize=0;

void* functionToCall=NULL;

int main(void) {
    setlocale(LC_ALL, "");
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);

    hide_cursor(stdOut);


    //Garbage collection

    void* collection=malloc(sizeof(void*));

    /*
        MENÜLER
    */

    menu main_menu,confirm_exit,startAdventure,talkToSomeone,locationMenu,sing,eatFood,food_menu,item_menu;

    initMenu(
        &confirm_exit,
        L"Çık",
        L"Oyundan çıkmak istediğine\nemin misin ?",
        (wchar_t[][64]){L"Evet"},
        1,
        NULL,
        0,
        &main_menu
    );
    

    initMenu(
        &startAdventure,
        L"Maceraya Atıl",
        L"Hangi maceraya atılmak istersin",
        (wchar_t[][64]){L"Ana Hikaye"},
        1,
        NULL,
        0,
        &main_menu
    );

    initMenu(
       &talkToSomeone,
       L"Birisiyle konuş",
       L"Kimle konuşucaksın",
       (wchar_t[][64]){L"Kişi1",L"Kişi2"},
       2,
       NULL,
       0,
       &main_menu
    );

    initMenu(
       &locationMenu,
       L"Yolculuk Menüsü",
       L"Nereye gitmek istersin",
       (wchar_t[][64]){},
       0,
       NULL,
       0,
       &main_menu
    );

    initMenu(
       &eatFood,
       L"Yemek ye",
       L"Ne yiyeceksin?",
       (wchar_t[][64]){L"Yemek1",L"Yemek2"},
       2,
       NULL,
       0,
       &main_menu
    );

    initMenu(
       &item_menu,
       L"Eşyalarım",
       L"Eşyalarını burada inceleyebilirsin",
       (wchar_t[][64]){L"Eşya1",L"Eşya2"},
       2,
       NULL,
       0,
       &main_menu
    );

    // Önemli not : Yemek menüsü seçildikten sonra yanda ascii resimler gösterilebilir. Bu bir fikir sadece


    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        NULL,
        0,
        (pmenu[]){&startAdventure, &eatFood, &talkToSomeone,&locationMenu,&item_menu},
        5,
        NULL
    );


    /*
        KONUMLAR
    */

   location tavern={
    .name=L"Han",
    .description=L"Han Description Placeholder",
    .path=NULL,
    .pathLength=0
   };

    location foodShop={
    .name=L"Han",
    .description=L"Han Description Placeholder",
    .path=NULL,
    .pathLength=0
   };

    location healer={
    .name=L"Han",
    .description=L"Han Description Placeholder",
    .path=NULL,
    .pathLength=0
   };

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    /*
        Başlangıç Seçenekleri
    */

    int time=8*3600;

    player Player;
    wcscpy(Player.name,L"Player");
    Player.locationAdress=&tavern;
    initStats(&Player.stat,10,10,10,10,10,10);
    Player.level=1;
    Player.maxHealth=5*Player.stat.constition+(5*Player.stat.constition*(Player.level-1)/25);
    Player.health=Player.maxHealth;
    Player.currency=20;
    Player.mental=100;
    Player.saturation=100;
    Player.exhaustion=0;
    Player.abilityPoints=0;
    updatePlayer(&Player);

    character ally,enemy;
    ally.stat.wisdom=9;
    ally.stat.dexterity=9;
    enemy.stat.wisdom=12;
    enemy.stat.dexterity=8;

/*
    ANA DÖNGÜ
*/
    pmenu selectedMenu=&main_menu;

    int itemIndex=0;

    clear(stdOut,&coord);

    message rightSideText[10]={};
    int rightSideTextC=0;

    message test1={L"\nTEST1"};
    message test2={L"\nTEST2"};
    message test3={L"\nTEST3"};
    message test4={L"\nTEST4"};

    int uiValue=0;

    sendToRightSection(rightSideText,&rightSideTextC,&test1);
    sendToRightSection(rightSideText,&rightSideTextC,&test2);
    sendToRightSection(rightSideText,&rightSideTextC,&test3);
    sendToRightSection(rightSideText,&rightSideTextC,&test4);

    while(1){
        uiValue=0;
        int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
        uiValue=userInteraction(stdOut,stdIn,selectedMenu,&itemIndex,&coord,&Player,&time,rightSideText);

        if(selectedMenu->childrenCount>uiValue){//Children menülerden seçim
            selectedMenu=selectedMenu->children[uiValue];
    
        }else if((selectedMenu->itemCount)>uiValue-(selectedMenu->childrenCount) && (uiValue-(selectedMenu->childrenCount))>=0){
            //Fonksiyon çağrıları
            if(selectedMenu==&startAdventure){//Macera Menüsü
                if(uiValue==0){
                    updateMission(&missionC,&talkToSomeone);
                }
            }
            if(selectedMenu==&talkToSomeone){//Konuşma Menüsü
                updateNPCDialog(missionC,uiValue,&rightSideTextC,rightSideText);
            }
        }else if(selectedMenu!=&main_menu){//Ana haricindeki menülerin çıkışı
            if(uiValue>=totalCount && selectedMenu->parent!=NULL){
                selectedMenu=selectedMenu->parent;
            }
        }else{//Ana menünün çıkışı
            return exitProgram(stdOut,&coord,&collection);
        }
        // Yapılan işlemler sonrası değişimleri güncelleme
        updatePlayer(&Player);
        system("cls");
    }
}


int centerArtX() {
    int rightSectionWidth = coord.X - 33;
    int artWidth = getArtWidth(artBuffer);
    int centeredX = 33 + ((rightSectionWidth - artWidth) / 2);
    return centeredX;
}

void garbageCollector(void **collectorAdress,void *toBeCollected){
    collectionSize++;
    *collectorAdress=realloc(collectorAdress,(sizeof(void*))*collectionSize);
    collectorAdress[collectionSize-1]=toBeCollected;
}

int exitProgram(HANDLE stdOut,PCOORD coord,void **collectionAdress){
    clear(stdOut,coord);
    unhide_cursor(stdOut);
    for(int i;i<collectionSize;i++){
        free(collectionAdress[i]);
    }
    return 0;
}