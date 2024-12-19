#include "combat.h"
#include "character.h"
#include "rolldice.h"
#include "menu.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

extern HANDLE STDOUT,STDIN;
extern pMenu SELECTED_MENU,MAIN_MENU;
extern int ITEM_INDEX;
extern int TIME;
extern player PLAYER;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNT;
extern COORD SCREEN_SIZE;

menu combat_menu,attack,use_spell,use_item,run_confirm,target_menu;

void initCombatMenus(){

    initMenu(
        &target_menu,
        L"Hedef",
        L"Hedefini seç",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &attack,
        L"Saldır",
        L"Nasıl saldıracaksın?",
        (wchar_t[][64]){L"Silah1",L"Silah2"},
        2,
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
}

void initCombat(pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    char isInitialTurn=1;//İlk tur bool
    int turnOwnerIndex=0;//Tur sahibi index
    int playedTurns[16]={};//Her aşama sıfırlanan turunu oynayanalarını kaydeden liste
    emptyArray(playedTurns,16);//Listeyi -1 ile doldurur
    int greatest=0;//En büyük skor
    int combatantC=allyC+enemyC+1;//Savaşan sayısı
    int j=0;//Tur sahibi index
    SELECTED_MENU=&combat_menu;
    clear();
    drawUI();
    // Savaşa başla
    for(int i=0;;i++){
        if(isInitialTurn){// İlk aşama için
            //Her aşamada sıfırla
            emptyArray(playedTurns,16);
            for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(PLAYER.chr.stat.wisdom>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=PLAYER.chr.stat.wisdom;
                        turnOwnerIndex=j;
                    }
                    j++;
                    //Dostlar
                    for(;j<=allyC;j++){
                        if(allies[j-1]->stat.wisdom>greatest && !isIn(j,playedTurns,combatantC)){
                            greatest=allies[j-1]->stat.wisdom;
                            turnOwnerIndex=j;
                        }
                    }
                    //Düşmanlar
                    for(;j<=enemyC+allyC;j++){
                        if(enemies[j-allyC-1]->stat.wisdom>greatest && !isIn(j,playedTurns,combatantC)){
                            greatest=enemies[j-allyC-1]->stat.wisdom;
                            turnOwnerIndex=j;
                        }
                    }
                //Dönme bitti en büyüğe turunu oynat ve oynadığını kaydet
                playedTurns[a]=turnOwnerIndex;
                if(turnOwnerIndex==0){//Oyuncu
                    if(playerTurn(allies,allyC,enemies,enemyC)==0){
                        SELECTED_MENU=MAIN_MENU;
                        return;
                    }
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1],allies,allyC,enemies,enemyC);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1],allies,allyC,enemies,enemyC);
                }
            }
            isInitialTurn=0;
        }else{//Sonraki Aşamalar için
                //Her aşamada sıfırla
                emptyArray(playedTurns,16);
                for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(PLAYER.chr.stat.dexterity>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=PLAYER.chr.stat.dexterity;
                        turnOwnerIndex=j;
                    }
                    j++;
                    //Dostlar
                    for(;j<=allyC;j++){
                        if(allies[j-1]->stat.dexterity>greatest && !isIn(j,playedTurns,combatantC)){
                            greatest=allies[j-1]->stat.dexterity;
                            turnOwnerIndex=j;
                        }
                    }
                    //Düşmanlar
                    for(;j<=enemyC+allyC;j++){
                        if(enemies[j-allyC-1]->stat.dexterity>greatest && !isIn(j,playedTurns,combatantC)){
                            greatest=enemies[j-allyC-1]->stat.dexterity;
                            turnOwnerIndex=j;
                        }
                    }
                //Dönme bitti en büyüğe turunu oynat ve oynadığını kaydet
                playedTurns[a]=turnOwnerIndex;
                if(turnOwnerIndex==0){
                    if(playerTurn(allies,allyC,enemies,enemyC)==0){
                        SELECTED_MENU=MAIN_MENU;
                        return;
                    }
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1],allies,allyC,enemies,enemyC);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1],allies,allyC,enemies,enemyC);
                }
            }
        }
    }
}

//Array içinde bir sayı olup olmadığını bulan fonksiyon
char isIn(int number,int array[],int size){
    for(int i=0;i<size;i++){
        if(array[i]==number){
            return 1;
        }
    }
    return 0;
}

//Array'i -1 ile doldur
void emptyArray(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=-1;
    }
}

int playerTurn(pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    SELECTED_MENU=&combat_menu;
    message turnInfo={
        .shown=0,
        .string=L"Oynama sırası sende"
    };
    sendToRightSection(turnInfo);
    SELECTED_MENU=&combat_menu;
    char actionTaken=0;
    while(actionTaken==0){
        userInteraction();
        int totalCount=SELECTED_MENU->itemCount+SELECTED_MENU->childrenCount;
        if(SELECTED_MENU->childrenCount>ITEM_INDEX){//Alt menü seçimi
            SELECTED_MENU=SELECTED_MENU->children[ITEM_INDEX];
        }else if(ITEM_INDEX>totalCount-1){//Alt menülerin çıkışı
            SELECTED_MENU=SELECTED_MENU->parent;
        }else{//Alt menü seçenekleri
            if(SELECTED_MENU==&attack){//Saldırı Menüsünün Seçenekleri
                if(ITEM_INDEX==0){
                    updateTargets(enemies,enemyC);
                }
            }else if(SELECTED_MENU==&target_menu){//Hedef menüsü
                player_attack(enemies,ITEM_INDEX);
                actionTaken=1;
            }else if(SELECTED_MENU==&run_confirm){//Kaçma Menüsü
                if(ITEM_INDEX==0){
                    if(try_to_run()==0){
                        message info={
                            .shown=0,
                            .string=L"Savaş Sonlandı"
                        };
                        sendToRightSection(info);
                        clear();
                        drawUI();
                        return 0;
                    }else{
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}

void playTurnAlly(pCharacter ally,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    pCharacter target=randomTarget(enemies,enemyC,0);
    character_attack(ally,target);
    clear();
    drawUI();
}
void playTurnEnemy(pCharacter enemy,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    pCharacter target=randomTarget(allies,allyC,1);
    character_attack(enemy,target);
    clear();
    drawUI();
}

int try_to_run(){
    message success={
        .shown=0,
        .string=L"Kaçma girişimi başarılı"
    };
    message failure={
        .shown=0,
        .string=L"Kaçma girişimi başarısız"
    };
    DiceRollConfig dice={
        .animationSpeed=100,
        .diceType=20,
        .position=(COORD){35,0},
        .rolls=5,
        .result=0
    };
    int diceResult=rollDiceAnimated(STDOUT,dice);
    if(diceResult>10-(int)((PLAYER.chr.stat.dexterity-10)/2)){
        sendToRightSection(success);
        PLAYER.mental-=10;
        clear();
        drawUI();
        return 0;
    }else{
        sendToRightSection(failure);
        PLAYER.mental-=20;
        clear();
        drawUI();
        return 1;
    }
}

void character_attack(pCharacter actor,pCharacter target){
    DiceRollConfig dice={
        .animationSpeed=100,
        .diceType=10,
        .position=(COORD){60,0},
        .rolls=5,
        .result=0
    };
    int diceResult=rollDiceAnimated(STDOUT,dice);
    float modifier=(actor->stat.strength-10)/2;
    if(modifier<1){
        modifier=0;
    }
    int damage=diceResult+(int)modifier;
    target->health-=damage;
    message info={};
    swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls, %ls'e %d hasar verdi.",actor->name,target->name,damage);
    sendToRightSection(info);
}

void player_attack(pCharacter enemies[],int enemyIndex){
    DiceRollConfig dice={
        .animationSpeed=100,
        .diceType=20,
        .position=(COORD){60,0},
        .rolls=5,
        .result=0
    };
    int diceResult=rollDiceAnimated(STDOUT,dice);

    float modifier=(PLAYER.chr.stat.strength-10)/2;
    int damage=diceResult+(int)modifier;
    message info={};
    swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls'e %d hasar verdin.",enemies[enemyIndex]->name,damage);
    sendToRightSection(info);
    enemies[enemyIndex]->health-=damage;
}

pCharacter randomTarget(pCharacter characters[],int targetC,char incPlayer){
    int random;
    targetC++;
    if(incPlayer==1){
        random=rand()%targetC;
        if(random==targetC-1){
            return &PLAYER.chr;
        }else{
            return characters[random];
        }
    }else{
        random=rand()%(targetC-1);
        return characters[random];
    }
}

void updateTargets(pCharacter enemies[],int enemyC){
    wchar_t string[32];
    SELECTED_MENU=&target_menu;
    target_menu.parent=&attack;
    target_menu.itemCount=enemyC;
    for(int i=0;i<enemyC;i++){
        wcscpy(string,L"");
        swprintf(string,sizeof(string)/sizeof(wchar_t),L"%ls(%d)",enemies[i]->name,enemies[i]->health);
        wcscpy(target_menu.menuItems[i],string);
    }
}