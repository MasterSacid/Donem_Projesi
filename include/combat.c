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
    // Savaşa başla
    for(int i=0;;i++){
        if(isInitialTurn){// İlk aşama için
            //Her aşamada sıfırla
            emptyArray(playedTurns,16);
            wprintf(L"\nAşama başladı");
            for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                for(int j=0;j<combatantC;j++){
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    if(j==0){//Oyuncu
                        if(Player->stat.wisdom>greatest){
                            greatest=Player->stat.wisdom;
                            turnOwnerIndex=j;
                        }
                    }else if(j<=allyC && j>0){//Dostlar
                        if(allies[j-1]->stat.wisdom>greatest){
                            greatest=allies[j-1]->stat.wisdom;
                            turnOwnerIndex=j;
                        }
                    }else{//Düşmanlar
                        if(enemies[j-allyC-1]->stat.wisdom>greatest){
                            greatest=enemies[j-allyC-1]->stat.wisdom;
                            turnOwnerIndex=j;
                        }
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
                isInitialTurn=0;
            }
            }else{//Sonraki Aşamalar için
                //Her aşamada sıfırla
                emptyArray(playedTurns,16);
                wprintf(L"\nAşama başladı");
                for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                    // Tüm savaşçıları dön
                    for(int j=0;j<combatantC;j++){
                        // Her tur sıfırla
                        turnOwnerIndex=0;
                        greatest=0;
                        if(isIn(j,playedTurns,combatantC)){//Turun sahibi oynadıysa geç
                            continue;
                        }
                        if(j==0){//Oyuncu
                            if(Player->stat.dexterity>greatest){
                                greatest=Player->stat.dexterity;
                                turnOwnerIndex=j;
                            }
                        }else if(j<=allyC && j>0){//Dostlar
                            if(allies[j-1]->stat.dexterity>greatest){
                                greatest=allies[j-1]->stat.dexterity;
                                turnOwnerIndex=j;
                            }
                        }else{//Düşmanlar
                            if(enemies[j-allyC-1]->stat.dexterity>greatest){
                                greatest=enemies[j-allyC-1]->stat.dexterity;
                                turnOwnerIndex=j;
                            }
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
        
        wprintf(L"\nAşama bitti\n");
    }
}

//Array içinde bir sayı olup olmadığını bulan fonksiyon
char isIn(int number,int array[],int size){
    for(int i=0;i<size;i++){
        if(array[i]==number){
            return 1;
        }
    }
    printf("   %d %d %d   ",array[0],array[1],array[2]);
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