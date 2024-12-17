#include "combat.h"
#include "character.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

void initCombat(pPlayer Player,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
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
            wprintf(L"\nAşama başladı");
            for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(Player->stat.wisdom>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=Player->stat.wisdom;
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
                    playerTurn();
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly();
                }else{//Düşmanlar
                    playTurnEnemy();
                }
            }
            isInitialTurn=0;
            wprintf(L"\nAşama bitti\n");
        }else{//Sonraki Aşamalar için
                //Her aşamada sıfırla
                emptyArray(playedTurns,16);
                wprintf(L"\nAşama başladı");
                for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(Player->stat.dexterity>greatest && !isIn(j,playedTurns,combatantC)){
                        greatest=Player->stat.dexterity;
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
                    playerTurn();
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly();
                }else{//Düşmanlar
                    playTurnEnemy();
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

void playerTurn(){
    printf("\nOyuncunun turu");
    Sleep(1000);
}
void playTurnAlly(){
    printf("\nDostun turu");
    Sleep(1000);
}
void playTurnEnemy(){
    wprintf(L"\nDüşmanın turu");
    Sleep(1000);
}