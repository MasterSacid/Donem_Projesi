#include "locationtime.h"
#include "character.h"
#include "console.h"
#include "../story/minimissions.h"

extern int TIME;
extern player PLAYER;
extern int ITEM_INDEX;
extern pMenu SELECTED_MENU;
extern pMenu LOST_MENU;

void pass_time(int time){

    char send_once_flag=1;

    updatePlayer();

    if(PLAYER.chr.health<=0){
        SELECTED_MENU=LOST_MENU;
        return;
    }

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
        resource_operation(&PLAYER.saturation,-i/1800.0,100.0,0.0);
        resource_operation(&PLAYER.exhaustion,i/800.0,100.0,0.0);
        resource_operation(&PLAYER.hygiene,-i/2400.0,100.0,0.0);

        if(PLAYER.chr.health<PLAYER.chr.maxHealth && PLAYER.saturation>30){
            resource_operation(&PLAYER.saturation,-i/1800.0,100.0,0);
            resource_operation(&PLAYER.chr.health,i/3600.0,PLAYER.chr.maxHealth,0.0);
        }

        if(send_once_flag){
            if(PLAYER.saturation<=0){
                resource_operation(&PLAYER.chr.health,-i/3600.0,100,0);
                message info={.string=L"Açlıktan ölüyorsun."};
                sendToRightSection(info);
            }
            if(PLAYER.mental<=10){
                resource_operation(&PLAYER.chr.health,-i/1800.0,100,0);
                message info={.string=L"Akıl Sağlığını kaybettin. Bilmediğin bir nedenden ötürü sağlığını kaybediyorsun."};
                sendToRightSection(info);
            }
            send_once_flag=0;
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
            update_shop(shops[0],menus[1],menus[2]);
            *selected_shop=shops[0];
        }
    }
    if(PLAYER.chr.locationAdress==locations[2]){
        if(ITEM_INDEX==0){
            update_shop(shops[1],menus[1],menus[2]);
            *selected_shop=shops[1];
        }
    }
    if(PLAYER.chr.locationAdress==locations[3]){
        if(ITEM_INDEX==0){
            update_shop(shops[2],menus[1],menus[2]);
            *selected_shop=shops[2];
        }
    }
}

void update_shop(pShop shop,pMenu menu,pMenu location_activity){
    wcscpy(menu->name,shop->name);
    wcscpy(menu->description,shop->description);
    menu->itemCount=shop->itemC;
    for(int i=0;i<shop->itemC;i++){
        wcscpy(menu->menuItems[i],shop->items[i]->name);
    }
    SELECTED_MENU=menu;
    menu->parent=location_activity;
}