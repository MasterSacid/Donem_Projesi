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
#include "include/eventHandler.h"
#include "include/narrative.h"
#include <stdlib.h>
#include "story/beginning.h"

int centerArtX(); //Bu fonksiyon main içinde olmak zorunda

int exitProgram(HANDLE stdOut, PCOORD coord, void **collectionAdress);

// Ekran boyutunu saklamak için açılan COORD yapısı
COORD coord;
char artBuffer [4096]; //Ascii tablolarının maks karakter sayısı

int collectionSize=0;


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

    menu main_menu,confirm_exit,startAdventure,talkToSomeone,sing,eatFood,food_menu;

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
        L"Bu Maceraya atılmak istediğinden\nemin misin ?",
        (wchar_t[][64]){L"Evet",L"Hayır"},
        2,
        NULL,
        0,
        &main_menu
    );

    initMenu(
       &talkToSomeone,
       L"Yemek ye",
       L"Ne yiyeceksin?",
       (wchar_t[][64]){L"Şarkı1",L"Şarkı2"},
       2,
       NULL,
       0,
       &main_menu
    );


    initMenu(
        &sing,
        L"Şarkı söyle",
        L"İstdeğin şarkıyı seç",
        (wchar_t[][64]){L"Şarkı1",L"Şarkı2"},
        2,
        NULL,
        0,
        &main_menu
    );


    initMenu(
       &eatFood,
       L"Yemek ye",
       L"Ne yiyeceksin?",
       (wchar_t[][64]){L"Şarkı1",L"Şarkı2"},
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
        (pmenu[]){&startAdventure, &eatFood, &talkToSomeone, &sing},
        4,
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

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;


    //Başlangıç Seçenekleri

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

    pmenu selectedMenu=&main_menu;
    int itemIndex=0;
    clear(stdOut,&coord);
    message output[10]={};

    beginning();

    while(1){
        displayMenu(stdOut,selectedMenu,itemIndex,&coord);
        displayVertLine(stdOut,&coord,(COORD){33,0},(COORD){33,60},'|');
        displayHorLine(stdOut,&coord,(COORD){0,15},(COORD){33,15},'-');
        displayHUD(stdOut,&Player,(COORD){0,17},&time);
        //printMessages(stdOut,output,(COORD){35,0});

        //Klavyeden geçerli tuş alınması
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
            int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
            switch(key){
                case -1:
                    continue;
                case 0:
                    if(itemIndex<0){
                        itemIndex=totalCount;
                    }else if(itemIndex>=totalCount){
                        itemIndex=totalCount-1;
                    }else{
                        itemIndex--;
                    }
                    break;
                case 1:
                    if(itemIndex>totalCount){
                        itemIndex=0;
                    }else{
                        itemIndex++;
                    }
                    break;
                case 2:
                    //Enter tuşuna basıldığında yapılacaklar

                    //Bir menüdeyken en son seçenek seçiliyse yapılacak
                    if(itemIndex>=totalCount){
                        if(selectedMenu==&main_menu){
                            selectedMenu=&confirm_exit;
                        }else{
                            selectedMenu=selectedMenu->parent;
                        }
                    //Bir menüdeyken alt menüler seçiliyken yapılacaklar
                    }else if(itemIndex<=selectedMenu->childrenCount-1){
                        selectedMenu=selectedMenu->children[itemIndex];
                    //Alt menü olmayan seçenekler seçiliyken yapılacaklar
                    }else{
                        if(selectedMenu==&confirm_exit){
                            if(itemIndex==0){
                                return exitProgram(stdOut,&coord,&collection);
                            }
                        }
                    }
                    break;
            }
        }
        // Yapılan işlemler sonrası değişimleri güncelleme
        updatePlayer(&Player);
        clear(stdOut,&coord);
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
        printf("Succesfully deleted");
    }
    return 0;
}