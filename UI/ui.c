#include "ui.h"
#include <windows.h>

int userInteraction(HANDLE stdOut,HANDLE stdIn,pmenu selectedMenu,int* ie,PCOORD coord,pPlayer Player,int* time,message output[]){
    int itemIndex=*ie;
    while(1){
        clear(stdOut,coord);
        drawUI(stdOut,selectedMenu,*ie,coord,Player,time,output);
        itemIndex=userInput(stdIn,selectedMenu,ie);
        if(itemIndex==-1){
            continue;
        }
        *ie=itemIndex;
        return itemIndex;
    }
}

void drawUI(HANDLE stdOut,pmenu selectedMenu,int itemIndex,PCOORD coord,pPlayer Player,int* time,message output[]){
    displayMenu(stdOut,selectedMenu,itemIndex,coord);
    displayVertLine(stdOut,coord,(COORD){33,0},(COORD){33,60},'|');
    displayHorLine(stdOut,coord,(COORD){0,15},(COORD){33,15},'-');
    displayHUD(stdOut,Player,(COORD){0,17},time);
    printMessages(stdOut,output,(COORD){35,0},10,"letter");
}

int userInput(HANDLE stdIn,pmenu selectedMenu,int* ie){
    int itemIndex=*ie;
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
        }
        int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
        switch(key){
            case 0:
                if(itemIndex<=0){
                    itemIndex=totalCount;
                }else if(itemIndex>=totalCount){
                    itemIndex=totalCount-1;
                }else{
                    itemIndex--;
                }
                *ie=itemIndex;
                return -1;
            case 1:
                if(itemIndex>=totalCount){
                    itemIndex=0;
                }else{
                    itemIndex++;
                }
                *ie=itemIndex;
                return -1;
            case 2:
                system("cls");
                *ie=itemIndex;
                return itemIndex;
        }
    return -1;
}
