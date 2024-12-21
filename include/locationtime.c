#include "locationtime.h"
#include "character.h"
#include "console.h"
#include "../story/minimissions.h"

extern int TIME;
extern player PLAYER;
extern int ITEM_INDEX;
extern pMenu SELECTED_MENU;

void pass_time(int time){
    TIME+=time;
    while(TIME>MAX_TIME){
        TIME-=MAX_TIME;
    }
    int i=time;
    if(time>3600){
        i=600;
    }
    for(;time>0;){
        time-=i;
        resource_operation(&PLAYER.mental,i/2400.0,100,0.0);
        resource_operation(&PLAYER.saturation,-i/3600.0,100.0,0.0);
        resource_operation(&PLAYER.exhaustion,i/800.0,100.0,0.0);
        resource_operation(&PLAYER.hygiene,-i/2400.0,100.0,0.0);

        if(PLAYER.chr.health<PLAYER.chr.maxHealth && PLAYER.saturation>30){
            resource_operation(&PLAYER.saturation,-i/3600.0,100.0,0);
            resource_operation(&PLAYER.chr.health,i/3600.0,PLAYER.chr.maxHealth,0.0);
        }

        if(PLAYER.saturation<=0){
            resource_operation(&PLAYER.chr.health,-i/3600.0,100,0);
        }
    }
}

void change_location(pLocation location){
    pass_time(PLAYER.chr.locationAdress->pathLength[ITEM_INDEX]*10);
    resource_operation(&PLAYER.exhaustion,PLAYER.chr.locationAdress->pathLength[ITEM_INDEX]/10.0,100,0);
    PLAYER.chr.locationAdress=location;
    message info;
    swprintf(info.string,sizeof(wchar_t)*512,L"%ls konumuna yolculuk ettin.",location->name);
    sendToRightSection(info);
}

void location_activity_handler(pLocation locations[],pMenu menus[],pShop shops[],pShop *selected_shop){
    if(PLAYER.chr.locationAdress==locations[0]){
        if(ITEM_INDEX==0){
            SELECTED_MENU=menus[0];
        }
        if(ITEM_INDEX==1){
            if(PLAYER.hygiene>20){
                minigamePicker(0,0);
            }else{
                message info={
                    .string=L"Bunu yapman için hijyenin 20'den büyük olması lazım",
                    .shown=1
                };
                sendToRightSection(info);
            }
        }
        if(ITEM_INDEX==2){
            player_sleep();
        }
        if(ITEM_INDEX==3){
            message info={.string=L"Yıkandın"};
            pass_time(30*60);
            PLAYER.hygiene=100.0;
            sendToRightSection(info);
        }
    }
    if(PLAYER.chr.locationAdress==locations[1]){
        if(ITEM_INDEX==0){
            *selected_shop=shops[0];
            wcscpy(menus[1]->name,shops[0]->name);
            wcscpy(menus[1]->description,shops[0]->description);
            menus[1]->itemCount=shops[0]->itemC;
            for(int i=0;i<shops[0]->itemC;i++){
                wcscpy(menus[1]->menuItems[i],shops[0]->items[i]->name);
            }
            SELECTED_MENU=menus[1];
        }
    }
    if(PLAYER.chr.locationAdress==locations[2]){
        if(ITEM_INDEX==0){
            
        }
    }
    if(PLAYER.chr.locationAdress==locations[3]){
        if(ITEM_INDEX==0){
            
        }
    }
}