#include "character.h"
#include "console.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

struct menu;  

typedef struct menu* pMenu;

extern player PLAYER;

void initStats(pStats stats,int con,int cha,int dex,int inl,int str,int wis){
    stats->constition=con;
    stats->charisma=cha;
    stats->dexterity=dex;
    stats->intelligence=inl;
    stats->strength=str;
    stats->wisdom=wis;
}

pItem createItem(wchar_t name[],wchar_t description[],wchar_t type[],int value,dictValue itemValues[]){
    pItem itemAdress=(pItem)malloc(sizeof(item));
    wcscpy(itemAdress->name,name);
    wcscpy(itemAdress->description,description);
    wcscpy(itemAdress->type,type);
    itemAdress->value=value;
    for(int i=0;i<8;i++){
        wcscpy(itemAdress->itemValues[i].name,itemValues[i].name);
        itemAdress->itemValues[i].value=itemValues[i].value;
    }
    return itemAdress;
}

pCharacter createNPC(wchar_t name[]){
    pCharacter characterAdress=(pCharacter)malloc(sizeof(character));
    wcscpy(characterAdress->name,name);
    initStats(&(characterAdress->stat),0,0,0,0,0,0);
    characterAdress->health=50;
    characterAdress->maxHealth=50+5*(characterAdress->stat.constition);
    characterAdress->currency=0;
    characterAdress->level=1;
    return characterAdress;
}

void updatePlayer(){
    PLAYER.chr.maxHealth=5*PLAYER.chr.stat.constition+(5*PLAYER.chr.stat.constition*(PLAYER.chr.level-1)/25);
    while(PLAYER.xpPoint>=100){
        PLAYER.xpPoint-=100;
        PLAYER.abilityPoints+=1;
        PLAYER.chr.level++;
    }
    wcscpy(PLAYER.chr.locationName,PLAYER.chr.locationAdress->name);
}

void addItem(pCharacter character,pItem item){
    character->items[character->itemCount]=item;
    character->itemCount++;
}

void removeItem(pCharacter character,pItem item){
    for(int i=0;i<character->itemCount;i++){
        if(character->items[i]==item){
            character->items[i]=NULL;
            for(int j=i;j<character->itemCount;j++){
                character->items[j]=character->items[j+1];
            }
            break;
        }
    }
    character->itemCount--;
}

void array_add_item(pItem item,pItem items[],int *arrayC){
    items[*arrayC]=item;
    *arrayC+=1;
}

void array_remove_item(pItem item,pItem items[],int *arrayC){
    for(int i=0;i<*arrayC;i++){
        if(items[i]==item){
            items[i]=NULL;
            for(int j=i;j<*arrayC;j++){
                items[j]=items[j+1];
            }
            break;
        }
    }
    *arrayC-=1;
}


int getValueByDictName(wchar_t name[32],dictValue array[],int i){
    for(;i>0;i--){
        if(wcscmp(array[i-1].name,name)==0){
            return array[i-1].value;
        }
    }
    return 0;
}

void resource_operation(float *resource,float value,float max,float min){
    *resource+=value;
    if(*resource>max){
        *resource=max;
    }
    if(*resource<min){
        *resource=min;
    }
}

void player_sleep(){
    pass_time(8*60*60);
    resource_operation(&PLAYER.exhaustion,-100,100,0);
    message info;
    swprintf(info.string,sizeof(wchar_t)*512,L"Uyudun");
    sendToRightSection(info);
}