#include "character.h"
#include <stdlib.h>

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

void updatePlayer(pPlayer Player){
    Player->maxHealth=5*Player->stat.constition+(5*Player->stat.constition*(Player->level-1)/25);
    while(Player->xpPoint>=100){
        Player->xpPoint-=100;
        Player->abilityPoints+=1;
    }
    wcscpy(Player->locationName,Player->locationAdress->name);
}