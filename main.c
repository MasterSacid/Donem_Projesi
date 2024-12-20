#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
#include "story/minimissions.h"

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
pMenu MAIN_MENU;
message GAME_MESSAGES[15]={};
int GAME_MESSAGE_COUNTER=0;
char artBuffer [4096];

int main(void) {
    setlocale(LC_ALL, "");
    STDOUT=GetStdHandle(STD_OUTPUT_HANDLE);
    STDIN=GetStdHandle(STD_INPUT_HANDLE);

    hide_cursor();
    srand(time(NULL));

    /*
        MENÜLER
    */

    menu main_menu,confirm_exit,startAdventure,talkToSomeone,locationMenu,sing,eatFood,food_menu,item_menu,inspect_menu,skill_menu;
    menu confirm,location_activities;
    location tavern,foodShop,healer,weaponsmith;

    initMenu(
        &confirm,
        L"",
        L"",
        (wchar_t[][64]){L"evet"},
        1,
        (pMenu[]){},
        0,
        &main_menu
    );

    initMenu(
        &location_activities,
        L"",
        L"",
        (wchar_t[][64]){},
        0,
        (pMenu[]){},
        0,
        &main_menu
    );

    initMenu(
        &skill_menu,
        L"Yetenek Menüsü",
        L"Artırmak istediğin yetenekleri\nseç",
        (wchar_t[][64]){
        L"Bilgelik        ",
        L"Çeviklik        ",
        L"Dayanıklılık    ",
        L"Güç             ",
        L"Karizma         ",
        L"Zeka            "},
        6,
        NULL,
        0,
        &main_menu
    );

    initMenu(
        &inspect_menu,
        L"",
        L"",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &main_menu
    );

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
       (wchar_t[][64]){L"Hancı",L"Ayyaş"},
       2,
       NULL,
       0,
       &main_menu
    );

    initMenu(
       &locationMenu,
       L"Yolculuk Menüsü",
       L"Nereye gitmek istersin",
       (wchar_t[][64]){L"Şifacı",L"Erzak Dükkanı",L"Silahçı"},
       3,
       NULL,
       0,
       &main_menu
    );

    initMenu(
       &food_menu,
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
       L"Eşyalarını burada inceleyebilir-\nsin",
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
        (pMenu[]){&location_activities,&startAdventure, &food_menu,&locationMenu,&item_menu,&skill_menu},
        6,
        NULL
    );

    initCombatMenus();

    MAIN_MENU=&main_menu;

    /*
        KONUMLAR
    */

   tavern=(location){
    .name=L"Han",
    .description=L"Han Description Placeholder",
    .path={&foodShop,&healer,&weaponsmith},
    .pathLength={100,150,200},
    .pathCount=3,
    .characters={},
    .characterCount=0,
    .activities={L"Birisiyle Konuş",L"Şarkı Söyle",L"Uyu"},
    .activityCount=3
   };

    foodShop=(location){
    .name=L"Erzak Dükkanı",
    .description=L"Food Shop Description Placeholder",
    .path={&tavern,&healer,&weaponsmith},
    .pathLength={100,150,250},
    .pathCount=3,
    .characterCount=0,
    .activities={L"Yiyecek satın al"},
    .activityCount=1
   };

    healer=(location){
    .name=L"Şifacı",
    .description=L"Healer Description Placeholder",
    .path={&tavern,&foodShop,&weaponsmith},
    .pathLength={150,150,200},
    .pathCount=3,
    .characterCount=0,
    .activities={L"Şifalı eşyalar satın al"},
    .activityCount=1
   };

    weaponsmith=(location){
    .name=L"Silahçı",
    .description=L"Healer Description Placeholder",
    .path={&tavern,&foodShop,&healer},
    .pathLength={100,250,200},
    .pathCount=3,
    .characterCount=0,
    .activities={L"Silah satın al"},
    .activityCount=1
   };

    /*
        Başlangıç Seçenekleri
    */

    TIME=8*3600;

    wcscpy(PLAYER.chr.name,L"PLAYER");
    PLAYER.chr.locationAdress=&tavern;
    initStats(&PLAYER.chr.stat,10,10,10,10,10,10);
    printf("%d",PLAYER.chr.stat.charisma);
    PLAYER.chr.level=1;
    PLAYER.chr.maxHealth=5*PLAYER.chr.stat.constition+(5*PLAYER.chr.stat.constition*(PLAYER.chr.level-1)/25);
    PLAYER.chr.health=30;
    PLAYER.chr.currency=20;
    PLAYER.mental=80.0;
    PLAYER.saturation=80.0;
    PLAYER.exhaustion=0.0;
    PLAYER.abilityPoints=0;
    PLAYER.hygiene=100.0;


    // Başlangıç Eşyaları
    item bread={
        .name=L"Ekmek",
        .description=L"Biraz kurumuş olsa\nda yenebilir durumda",
        .type=L"food",
        .value=1,
        .itemValues=(dictValue){L"saturation",10}
    };
    item blade={
        .name=L"Bıçak",
        .description=L"Yakın zamanda dövülmüş\n bir bıçak(+1 Hasar)",
        .type=L"weapon",
        .value=1,
        .itemValues=(dictValue){L"modifier",1}
    };

    addItem(&PLAYER.chr,&bread);
    addItem(&PLAYER.chr,&bread);
    addItem(&PLAYER.chr,&blade);

    updatePlayer();

    character ally,enemy,ally2;
    ally2.stat.wisdom=1;
    ally2.stat.dexterity=1;
    ally.stat.wisdom=9;
    ally.stat.dexterity=9;
    enemy.stat.wisdom=12;
    enemy.stat.dexterity=8;

    wcscpy(ally.name,L"Ally");
    wcscpy(ally2.name,L"ally2");
    wcscpy(enemy.name,L"Foe");

    // Eşya Alışveriş Değerleri

    menu shop_menu;

    shop_menu=(menu){
        .parent=&location_activities
    };

    shop food_shop={
        .name=L"Erzak Dükkanı",
        .description=L"Ne alacaksın?"
    };

    shop weapon_shop={
        .name=L"Silahçı",
        .description=L"Ne alacaksın?"
    };

    shop healer_shop={
        .name=L"Şifacı",
        .description=L"Ne alacaksın?"
    };

    pShop selected_shop=NULL;

/*
    Karakterler
*/
    character hanci={
        .name=L"Hancı"
    };
    character ayyas={
        .name=L"Ayyaş"
    };
    character evsiz={
        .name=L"Evsiz"
    };
    character garson={
        .name=L"Garsons"
    };
    pCharacter characters[][32]={{&hanci,&ayyas,&evsiz,&garson}};
    int listCounts[]={4};

/*
    ANA DÖNGÜ
*/
    SELECTED_MENU=&main_menu;

    ITEM_INDEX=0;

    int totalCount;

    clear();

    //initCombat((pCharacter[]){&ally,&ally2},2,(pCharacter[]){&enemy},1);

    while(1){
        updateItems(&item_menu,&food_menu);
        update_skill_menu(&skill_menu);
        update_locations(&locationMenu);
        update_talk_menu(&talkToSomeone);
        update_location_activities(&location_activities);
        updateCharacters(&tavern,listCounts,characters);
        int totalCount=SELECTED_MENU->childrenCount+SELECTED_MENU->itemCount;
        userInteraction();

        if(SELECTED_MENU->childrenCount>ITEM_INDEX){//Children menülerden seçim
            SELECTED_MENU=SELECTED_MENU->children[ITEM_INDEX];
    
        }else if((SELECTED_MENU->itemCount)>ITEM_INDEX-(SELECTED_MENU->childrenCount) && (ITEM_INDEX-(SELECTED_MENU->childrenCount))>=0){
            //Fonksiyon çağrıları
            if(SELECTED_MENU==&startAdventure){//Macera Menüsü
                if(ITEM_INDEX==0){
                    updateMission(&tavern,listCounts,characters);
                }
            }
            if(SELECTED_MENU==&talkToSomeone){//Konuşma Menüsü
                updateNPCDialog();
            }
            if(SELECTED_MENU==&item_menu){
                inspectItem(&inspect_menu);
                SELECTED_MENU=&inspect_menu;
            }
            if(SELECTED_MENU==&food_menu){
                eat_food(&food_menu,&item_menu);
            }
            if(SELECTED_MENU==&skill_menu){
                update_skill_menu(&skill_menu);
            }
            if(SELECTED_MENU==&locationMenu){
                change_location(PLAYER.chr.locationAdress->path[ITEM_INDEX]);
                continue;
            }
            if(SELECTED_MENU==&shop_menu){
                selected_shop->selected_item=selected_shop->items[ITEM_INDEX];
                if(confirm_menu(&confirm,L"Satın al",L"Bu eşyayı almak istediğinden emin misin",&shop_menu)==0){
                    addItem(&PLAYER.chr,selected_shop->selected_item);
                    array_remove_item(selected_shop->selected_item,selected_shop->items,&selected_shop->itemC);
                    selected_shop->itemC--;
                    SELECTED_MENU=&location_activities;
                }
            }
            if(SELECTED_MENU==&location_activities){
                //BU FONKSİYONDAKİ SIRALAMALAR ÖNEMLİ
                location_activity_handler((pLocation[]){&tavern,&healer,&foodShop,&weaponsmith}
                ,(pMenu[]){&talkToSomeone,&shop_menu}
                ,(pShop[]){&healer_shop,&food_shop,&weapon_shop}
                ,&selected_shop);
            }
        }else if(SELECTED_MENU!=&main_menu){//Ana menü haricindeki menülerin çıkışı
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