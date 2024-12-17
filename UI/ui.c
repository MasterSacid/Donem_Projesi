#include "ui.h"
#include <windows.h>

int userInteraction(HANDLE stdOut,HANDLE stdIn,pmenu selectedMenu,int* ie,PCOORD coord,pPlayer Player,int* time,message output[]){
    int itemIndex=*ie;
    while(1){
        clear(stdOut,coord);
        displayMenu(stdOut,selectedMenu,itemIndex,coord);
        displayVertLine(stdOut,coord,(COORD){33,0},(COORD){33,60},'|');
        displayHorLine(stdOut,coord,(COORD){0,15},(COORD){33,15},'-');
        displayHUD(stdOut,Player,(COORD){0,17},time);
        printMessages(stdOut,output,(COORD){35,0},10,"letter");
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
        }
        int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
        switch(key){
            case -1:
                continue;
            case 0:
                if(itemIndex<=0){
                    itemIndex=totalCount;
                }else if(itemIndex>=totalCount){
                    itemIndex=totalCount-1;
                }else{
                    itemIndex--;
                }
                break;
            case 1:
                if(itemIndex>=totalCount){
                    itemIndex=0;
                }else{
                    itemIndex++;
                }
                break;
            case 2:
                clear(stdOut,coord);
                return itemIndex;
        }
    }
    return itemIndex;
}