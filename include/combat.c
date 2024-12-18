#include "combat.h"
#include "character.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

extern HANDLE STDOUT,STDIN;
extern pMenu SELECTED_MENU;
extern int ITEM_INDEX;
extern int TIME;
extern player PLAYER;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNT;
extern COORD SCREEN_SIZE;

void initCombat(pMenu combat_menu,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    char isInitialTurn=1;
    int turnOwnerIndex=0;
    int playedTurns[16]={};
    emptyArray(playedTurns,16);
    int greatest=0;
    int combatantC=allyC+enemyC+1;
    int j=0;
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
                    if(PLAYER.stat.wisdom>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=PLAYER.stat.wisdom;
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
                    playerTurn(combat_menu);
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1]);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1]);
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
                    if(PLAYER.stat.dexterity>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=PLAYER.stat.dexterity;
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
                if(turnOwnerIndex==0){//Oyuncu
                    playerTurn(combat_menu);
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1]);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1]);
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

void playerTurn(pMenu combat_menu){
    message turnInfo={
        .shown=0,
        .string=L"Oynama sırası sende!"
    };
    sendToRightSection(turnInfo);
    char actionTaken=0;
    while(actionTaken==0){
        userInteraction();
        if(SELECTED_MENU!=combat_menu){

        }
    }
}
void playTurnAlly(pCharacter ally){
    message turnInfo={
        .shown=0,
        .string=L"Dostun hamle yapıyor"
    };
    sendToRightSection(turnInfo);
}
void playTurnEnemy(pCharacter enemy){
    message turnInfo={
        .shown=0,
        .string=L"Düşman hamle yapıyor"
    };
    sendToRightSection(turnInfo);
}