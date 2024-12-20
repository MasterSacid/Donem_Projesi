#include "locationtime.h"
#include "character.h"
#include "console.h"

extern int TIME;
extern player PLAYER;
extern int ITEM_INDEX;

void pass_time(int time){
    TIME+=time;
    PLAYER.exhaustion+=time/600;
    PLAYER.saturation-=time/600;

    if(PLAYER.exhaustion>100){
        PLAYER.exhaustion=100;
    }
    if(PLAYER.saturation<0){
        PLAYER.saturation=0;
    }
}

void change_location(pLocation location){
    pass_time(PLAYER.chr.locationAdress->pathLength[ITEM_INDEX]*10);
    PLAYER.chr.locationAdress=location;
    message info;
    swprintf(info.string,sizeof(wchar_t)*512,L"%ls konumuna yolculuk ettin.",location->name);
    sendToRightSection(info);   
}