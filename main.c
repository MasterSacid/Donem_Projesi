#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "include/menu.h"
#include "include/console.h"
#include "include/arthandler.h"
#include "include/rolldice.h"
#include "include/effects.h"
#include "include/character.h"
#include "include/locationtime.h"
#include "include/combat.h"
#include "story/narrative.h"
#include "story/eventhandler.h"
#include "story/beginning.h"
#include "story/dialogues.h"
#include "UI/ui.h"

int centerArtX(); //Bu fonksiyon main içinde olmak zorunda
/*
    GLOBAL DEĞERLER
*/
HANDLE STDOUT,STDIN;
int MISSION_COUNTER=0;
int TIME;
int ITEM_INDEX;
player PLAYER;
COORD SCREEN_SIZE;
pMenu SELECTED_MENU;
message GAME_MESSAGES[10]={};
int GAME_MESSAGE_COUNTER=0;
char artBuffer [4096];

int main(void) {
    setlocale(LC_ALL, "");
    STDOUT=GetStdHandle(STD_OUTPUT_HANDLE);
    STDIN=GetStdHandle(STD_INPUT_HANDLE);

    hide_cursor();

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

    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        NULL,
        0,
        (pMenu[]){&startAdventure, &eatFood, &talkToSomeone,&locationMenu,&item_menu},
        5,
        NULL
    );

    menu combat_menu,attack,use_spell,use_item,run_confirm;

    initMenu(
    &combat_menu,
        L"Savaş",
        L"Ne yapmak istediğini seç",
        NULL,
        0,
        (pMenu[]){&attack,&use_spell,&use_item,&run_confirm},
        4,
        NULL
    );

    initMenu(
       &attack,
       L"Saldır",
       L"Nasıl saldıracaksın?",
       (wchar_t[][64]){L"Silah1",L"Silah2",L"Yumruk",L"Tekme"},
       4,
       NULL,
       0,
       &combat_menu
    );
    initMenu(
       &use_spell,
       L"Büyü Kullan",
       L"Hangi büyüyü kullanacaksın?",
       (wchar_t[][64]){L"Büyü1",L"Büyü2",L"Büyü3",L"Büyü4"},
       4,
       NULL,
       0,
       &combat_menu
    );
    initMenu(
       &use_item,
       L"Eşya Kullan",
       L"Hangi eşyayı kullanacaksın?",
       (wchar_t[][64]){L"Eşya",L"Eşya",L"Eşya",L"Eşya"},
       4,
       NULL,
       0,
       &combat_menu
    );
    initMenu(
       &run_confirm,
       L"Kaç",
       L"Kaçmak istediğine emin misin?",
       (wchar_t[][64]){L"Evet"},
       1,
       NULL,
       0,
       &combat_menu
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

    TIME=8*3600;

    wcscpy(PLAYER.name,L"PLAYER");
    PLAYER.locationAdress=&tavern;
    initStats(&PLAYER.stat,10,10,10,10,10,10);
    printf("%d",PLAYER.stat.charisma);
    PLAYER.level=1;
    PLAYER.maxHealth=5*PLAYER.stat.constition+(5*PLAYER.stat.constition*(PLAYER.level-1)/25);
    PLAYER.health=PLAYER.maxHealth;
    PLAYER.currency=20;
    PLAYER.mental=100;
    PLAYER.saturation=100;
    PLAYER.exhaustion=0;
    PLAYER.abilityPoints=0;
    updatePlayer();

    character ally,enemy;
    ally.stat.wisdom=9;
    ally.stat.dexterity=9;
    enemy.stat.wisdom=12;
    enemy.stat.dexterity=8;

/*
    ANA DÖNGÜ
*/
    SELECTED_MENU=&main_menu;

    ITEM_INDEX=0;

    int totalCount;

    clear();

    //initCombat(&combat_menu,(pCharacter[]){&ally},1,(pCharacter[]){&enemy},1);

    while(1){
        int totalCount=SELECTED_MENU->childrenCount+SELECTED_MENU->itemCount;
        userInteraction();

        if(SELECTED_MENU->childrenCount>ITEM_INDEX){//Children menülerden seçim
            SELECTED_MENU=SELECTED_MENU->children[ITEM_INDEX];
    
        }else if((SELECTED_MENU->itemCount)>ITEM_INDEX-(SELECTED_MENU->childrenCount) && (ITEM_INDEX-(SELECTED_MENU->childrenCount))>=0){
            //Fonksiyon çağrıları
            if(SELECTED_MENU==&startAdventure){//Macera Menüsü
                if(ITEM_INDEX==0){
                    updateMission(&talkToSomeone);
                }
            }
            if(SELECTED_MENU==&talkToSomeone){//Konuşma Menüsü
                updateNPCDialog();
            }
        }else if(SELECTED_MENU!=&main_menu){//Ana haricindeki menülerin çıkışı
            if(ITEM_INDEX>=totalCount && SELECTED_MENU->parent!=NULL){
                SELECTED_MENU=SELECTED_MENU->parent;
            }
        }else{//Ana menünün çıkışı
            clear();
            unhide_cursor();
            return 0;
        }
        // Yapılan işlemler sonrası değişimleri güncelleme
        updatePlayer();
        clear();
    }
}


int centerArtX() {
    int rightSectionWidth = SCREEN_SIZE.X - 33;
    int artWidth = getArtWidth(artBuffer);
    int centeredX = 33 + ((rightSectionWidth - artWidth) / 2);
    return centeredX;
}