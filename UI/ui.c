#include "ui.h"
#include <windows.h>

extern HANDLE STDOUT,STDIN;
extern pMenu SELECTED_MENU;
extern int TIME;
extern COORD SCREEN_SIZE;
extern int ITEM_INDEX;
extern message GAME_MESSAGES[];
extern int PLAYER;
extern pMenu SELECTED_MENU;

void userInteraction(){
    clear();
    drawUI();
    userInput();
}

void drawUI(){
    displayMenu(SELECTED_MENU);
    displayVertLine((COORD){33,0},(COORD){33,60},'|');
    displayHorLine((COORD){0,15},(COORD){33,15},'-');
    displayHUD((COORD){0,17});
    printMessages((COORD){35,0},10,"letter");
}

void userInput(){
    int key;
    while(1){
        key=-1;
        while(key==-1){
            key=waitKeys((WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
        }
        int totalCount=SELECTED_MENU->childrenCount+SELECTED_MENU->itemCount;
        switch(key){
            case 0:
                if(ITEM_INDEX<=0){
                    ITEM_INDEX=totalCount;
                }else if(ITEM_INDEX>=totalCount){
                    ITEM_INDEX=totalCount-1;
                }else{
                    ITEM_INDEX--;
                }
                break;
            case 1:
                if(ITEM_INDEX>=totalCount){
                    ITEM_INDEX=0;
                }else{
                    ITEM_INDEX++;
                }
                break;
            case 2:
                return;
        }
        clear();
        drawUI();
    }
}