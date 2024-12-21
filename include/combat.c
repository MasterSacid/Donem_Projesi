#include "combat.h"
#include "character.h"
#include "rolldice.h"
#include "menu.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

extern HANDLE STDOUT,STDIN;
extern pMenu SELECTED_MENU,MAIN_MENU;
extern int ITEM_INDEX;
extern int TIME;
extern player PLAYER;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNT;
extern COORD SCREEN_SIZE;
extern pMenu LOST_MENU;

menu combat_menu,attack,use_spell,use_item,run_confirm,target_menu,view_enemies,selection_menu;

void initCombatMenus(){

    initMenu(
        &selection_menu,
        L"Seçim",
        L"Seçimini yap",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &view_enemies,
        L"Düşmanları İncele",
        L"Kimi inceleyeceksin",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &target_menu,
        L"Hedef",
        L"Hedefini seç",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &attack,
        L"Saldır",
        L"Kime Saldıracaksın",
        (wchar_t[][64]){},
        0,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &use_item,
        L"Eşya Kullan",
        L"Hangi eşyayı kullanacaksın?",
        (wchar_t[][64]){L"Eşya",L"Eşya",L"Eşya",L"Eşya"},
        4,
        NULL,
        0,
        &combat_menu
    );
    initMenu(
        &run_confirm,
        L"Kaç",
        L"Kaçmak istediğine emin misin?",
        (wchar_t[][64]){L"Evet"},
        1,
        NULL,
        0,
        &combat_menu
    );

    initMenu(
        &combat_menu,
        L"Savaş",
        L"Ne yapmak istediğini seç",
        NULL,
        0,
        (pMenu[]){&view_enemies,&attack,&use_item,&run_confirm},
        4,
        NULL
    );
    combat_menu.draw_exit=0;
}

void initCombat(pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    message info={
        .string=L"Savaş başladı"
    };
    sendToRightSection(info);
    int loot_currency=0;
    int loot_exp;

    char isInitialTurn=1;//İlk tur bool
    int turnOwnerIndex=0;//Tur sahibi index
    int playedTurns[16]={};//Her aşama sıfırlanan turunu oynayanalarını kaydeden liste
    emptyArray(playedTurns,16);//Listeyi -1 ile doldurur
    int greatest=0;//En büyük skor
    int combatantC=allyC+enemyC+1;//Savaşan sayısı
    int j=0;//Tur sahibi index
    SELECTED_MENU=&combat_menu;
    clear();
    drawUI();
    // Savaşa başla
    for(int i=0;;i++){
        if(isInitialTurn){// İlk aşama için
            //Her aşamada sıfırla
            emptyArray(playedTurns,16);
            for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(PLAYER.chr.stat.wisdom>greatest && is_eligible(j,playedTurns,allies,allyC,enemies,enemyC)){
                        greatest=PLAYER.chr.stat.wisdom;
                        turnOwnerIndex=j;
                    }
                    j++;
                    //Dostlar
                    for(;j<=allyC;j++){
                        if(allies[j-1]->stat.wisdom>greatest && is_eligible(j,playedTurns,allies,allyC,enemies,enemyC)){
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
                    if(playerTurn(allies,allyC,enemies,enemyC)==0){
                        SELECTED_MENU=MAIN_MENU;
                        return;
                    }
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1],allies,allyC,enemies,enemyC);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1],allies,allyC,enemies,enemyC);
                }
                //Tur oyandıktan sonra savaşın durumu kontrol etme ve döngü değerlerini yeniden hesaplama
                pass_time(60);
                int state=combatant_state_check(allies,&allyC,enemies,&enemyC,&loot_exp,&loot_currency);
                if(state==1){
                    PLAYER.chr.currency+=loot_currency;
                    PLAYER.xpPoint+=loot_exp;
                    SELECTED_MENU=MAIN_MENU;
                    return;
                }else if(state==2){
                    SELECTED_MENU=LOST_MENU;
                }
                combatantC=allyC+enemyC+1;
            }
            isInitialTurn=0;
        }else{  //Sonraki Aşamalar için
                //Her aşamada sıfırla
                emptyArray(playedTurns,16);
                for(int a=0;a<combatantC;a++){// Tüm savaşçılar için bir kere tur aç
                // Tüm savaşçıları dön
                    j=0;
                    // Her tur sıfırla
                    turnOwnerIndex=-1;
                    greatest=0;
                    //Oyuncu
                    if(PLAYER.chr.stat.dexterity>greatest && is_eligible(j,playedTurns,allies,allyC,enemies,enemyC)){
                        greatest=PLAYER.chr.stat.dexterity;
                        turnOwnerIndex=j;
                    }
                    j++;
                    //Dostlar
                    for(;j<=allyC;j++){
                        if(allies[j-1]->stat.dexterity>greatest && is_eligible(j,playedTurns,allies,allyC,enemies,enemyC)){
                            greatest=allies[j-1]->stat.dexterity;
                            turnOwnerIndex=j;
                        }
                    }
                    //Düşmanlar
                    for(;j<=enemyC+allyC;j++){
                        if(enemies[j-allyC-1]->stat.dexterity>greatest && is_eligible(j,playedTurns,allies,allyC,enemies,enemyC)){
                            greatest=enemies[j-allyC-1]->stat.dexterity;
                            turnOwnerIndex=j;
                        }
                    }
                //Dönme bitti en büyüğe turunu oynat ve oynadığını kaydet
                playedTurns[a]=turnOwnerIndex;
                if(turnOwnerIndex==0){
                    if(playerTurn(allies,allyC,enemies,enemyC)==0){
                        SELECTED_MENU=MAIN_MENU;
                        return;
                    }
                }else if(turnOwnerIndex<=allyC && turnOwnerIndex>0){//Dostlar
                    playTurnAlly(allies[turnOwnerIndex-1],allies,allyC,enemies,enemyC);
                }else{//Düşmanlar
                    playTurnEnemy(enemies[turnOwnerIndex-allyC-1],allies,allyC,enemies,enemyC);
                }
                //Tur oyandıktan sonra savaşın durumu kontrol etme ve döngü değerlerini yeniden hesaplama
                pass_time(60);
                int state=combatant_state_check(allies,&allyC,enemies,&enemyC,&loot_exp,&loot_currency);
                if(state==1){
                    PLAYER.chr.currency+=loot_currency;
                    PLAYER.xpPoint+=loot_exp;
                    SELECTED_MENU=MAIN_MENU;
                    return;
                }else if(state==2){
                    SELECTED_MENU=LOST_MENU;
                }
                combatantC=allyC+enemyC+1;
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

int playerTurn(pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    SELECTED_MENU=&combat_menu;
    if(PLAYER.exhaustion>95){
        message info={.string=L"Sıranı dinlenmeye harcadın!"};
        resource_operation(&PLAYER.exhaustion,-20.0,100,0);
        sendToRightSection(info);
        return 1;
    }
    message turnInfo={
        .shown=0,
        .string=L"Oynama sırası sende"
    };
    sendToRightSection(turnInfo);
    SELECTED_MENU=&combat_menu;
    char actionTaken=0;
    while(actionTaken==0){
        PLAYER.selected_item=NULL;
        PLAYER.selected_character=NULL;
        userInteraction();
        int totalCount=SELECTED_MENU->itemCount+SELECTED_MENU->childrenCount;
        if(SELECTED_MENU->childrenCount>ITEM_INDEX){//Alt menü seçimi
            //Alt menülerden hazır hale gelmesi gerekenler için fonksiyonlar
            if(SELECTED_MENU==&combat_menu && ITEM_INDEX==0){
                updateTargets(enemies,enemyC,&view_enemies);
            }else if(SELECTED_MENU==&combat_menu && ITEM_INDEX==1){//Saldırı menüsü fonksiyonu
                if(PLAYER.selected_character==NULL){
                    updateTargets(enemies,enemyC,&selection_menu);
                    SELECTED_MENU=&selection_menu;
                    userInteraction();
                    clear();
                    drawUI();
                    if(ITEM_INDEX==selection_menu.itemCount){
                        SELECTED_MENU=&combat_menu;
                        continue;
                    }
                    PLAYER.selected_character=enemies[ITEM_INDEX];
                }
                clear();
                drawUI();
                if(PLAYER.selected_item==NULL){
                    SELECTED_MENU=&selection_menu;
                    update_attack_weapons();
                    userInteraction();
                    clear();
                    drawUI();
                    if(ITEM_INDEX==selection_menu.itemCount){
                        SELECTED_MENU=&combat_menu;
                        continue;
                    }
                    PLAYER.selected_item=findItemByName(&PLAYER.chr,SELECTED_MENU->menuItems[ITEM_INDEX]);
                }
                player_attack();
                actionTaken=1;
            }else{
                SELECTED_MENU=SELECTED_MENU->children[ITEM_INDEX];
            }
        }else if(ITEM_INDEX>totalCount-1){//Alt menülerin çıkışı
            SELECTED_MENU=SELECTED_MENU->parent;
        }else if(ITEM_INDEX>=SELECTED_MENU->childrenCount){
            if(SELECTED_MENU==&view_enemies){
                if(ITEM_INDEX<enemyC){
                    view_stats(enemies,ITEM_INDEX);
                }
            }
        }else{//Alt menü seçenekleri
            if(SELECTED_MENU==&run_confirm){//Kaçma Menüsü
                if(ITEM_INDEX==0){
                    if(try_to_run()==0){
                        message info={
                            .shown=0,
                            .string=L"Savaş Sonlandı"
                        };
                        sendToRightSection(info);
                        clear();
                        drawUI();
                        return 0;
                    }else{
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}

void playTurnAlly(pCharacter ally,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    pCharacter target=randomTarget(enemies,enemyC,0);
    character_attack(ally,target);
    clear();
    drawUI();
}
void playTurnEnemy(pCharacter enemy,pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){
    pCharacter target=randomTarget(allies,allyC,1);
    character_attack(enemy,target);
    clear();
    drawUI();
}

int try_to_run(){//Kaçmaya çalışma
    message success={
        .shown=0,
        .string=L"Kaçma girişimi başarılı"
    };
    message failure={
        .shown=0,
        .string=L"Kaçma girişimi başarısız"
    };
    DiceRollConfig dice={
        .animationSpeed=100,
        .diceType=20,
        .position=(COORD){35,0},
        .rolls=5,
        .result=0
    };
    int diceResult=rollDiceAnimated(STDOUT,dice);
    if(diceResult>10-(int)((PLAYER.chr.stat.dexterity-10)/2)){
        sendToRightSection(success);
        resource_operation(&PLAYER.mental,-10.0,100,0);
        resource_operation(&PLAYER.exhaustion,30.0,100,0);
        clear();
        drawUI();
        return 0;
    }else{
        sendToRightSection(failure);
        resource_operation(&PLAYER.mental,-20.0,100,0);
        resource_operation(&PLAYER.exhaustion,20.0,100,0);
        clear();
        drawUI();
        return 1;
    }
}

void character_attack(pCharacter actor,pCharacter target){//Karakterlerin saldırısını kontrol eden fonksiyon
    if(target==&PLAYER.chr){
        resource_operation(&PLAYER.hygiene,-20.0,100,0);
    }
    int dodge_check=(rand()%20+1)+(actor->stat.dexterity-target->stat.dexterity);
    message info={.shown=0};
    if(dodge_check<6){
        swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls hedefinin(%ls) kaçınması sonucunda hasar veremedi.",actor->name,target->name);
    }else{
        DiceRollConfig dice={
            .animationSpeed=100,
            .diceType=10,
            .position=(COORD){60,0},
            .rolls=5,
            .result=0
        };
        int diceResult=rollDiceAnimated(STDOUT,dice);
        float modifier=(actor->stat.strength-10)/2;
        int damage=diceResult+(int)modifier;;
        if(damage<=0){
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls güçsüz bir saldırı gerçekleştirdi ve hedefi bundan etkilenmedi.",actor->name);
        }else{
            target->health-=damage;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls, %ls hedefine %d hasar verdi. [ %.0f ]",actor->name,target->name,damage,target->health);
        }
    }
    sendToRightSection(info);
}

void player_attack(){//Oyunucunun saldırısını kontrol eden fonksiyon
    resource_operation(&PLAYER.exhaustion,-10.0,100,0);
    int dodge_check=(rand()%20+1)+(PLAYER.chr.stat.dexterity-PLAYER.selected_character->stat.dexterity);
    message info={.shown=0};
    if(dodge_check<6){
        swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"Hedefin saldırından kaçındı.");
    }else{
        DiceRollConfig dice={
            .animationSpeed=100,
            .diceType=20,
            .position=(COORD){70,0},
            .rolls=5,
            .result=0
        };
        int diceResult=rollDiceAnimated(STDOUT,dice);

        float modifier=(PLAYER.chr.stat.strength-10)/2;
        modifier+=(PLAYER.selected_item==NULL)?0:getValueByDictName(L"modifier",PLAYER.selected_item->itemValues,PLAYER.selected_item->value);

        int damage=diceResult+(int)modifier;
        if(damage<=0){
            damage=0;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"Güçsüz bir saldırı gerçekleştirdin ve hedefin bundan etkilenmedi.");
        }else{
            PLAYER.selected_character->health-=damage;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"%ls'e %d hasar verdin. [ %.0f ]"
            ,PLAYER.selected_character->name,damage,PLAYER.selected_character->health);
        }
    }
    sendToRightSection(info);
}

pCharacter randomTarget(pCharacter characters[],int targetC,char incPlayer){//Rasgele hedef belirleyen fonksiyon
    int random;
    targetC++;
    if(incPlayer==1){
        random=rand()%targetC;
        if(random==targetC-1){
            return &PLAYER.chr;
        }else{
            return characters[random];
        }
    }else{
        random=rand()%(targetC-1);
        return characters[random];
    }
}

void updateTargets(pCharacter targets[],int targetC,pMenu caller){//Hedef alınması için menüleri güncelleyen fonksiyon
    wchar_t string[32];
    target_menu.parent=&combat_menu;
    SELECTED_MENU=caller;
    caller->itemCount=targetC;
    for(int i=0;i<targetC;i++){
        wcscpy(string,L"");
        swprintf(string,sizeof(string)/sizeof(wchar_t),L"%ls[ %0.f ]",targets[i]->name,targets[i]->health);
        wcscpy(caller->menuItems[i],string);
    }
}

int is_eligible(int i,int list[],pCharacter allies[],int allyC,pCharacter enemies[],int enemyC){//Hamle yapma uygunluğunu kontrol eden fonksiyon
    if(i==0){
        if(PLAYER.chr.health>0 && !isIn(i,list,allyC+enemyC+1)){
            return 1;
        }
    }else if(i<=allyC){
        if(allies[i-1]->health>0 && !isIn(i,list,allyC+enemyC+1)){
            return 1;
        }
    }else if(i<=allyC+enemyC){
        if(enemies[i-1-allyC]->health>0 && !isIn(i,list,allyC+enemyC+1)){
            return 1;
        }
    }
    return 0;
}

int combatant_state_check(pCharacter allies[],int* allyC,pCharacter enemies[],int* enemyC,int* exp,int* currency){
    for(int i=0;i<*allyC;i++){
        if(allies[i]->health<=0){
            message info;
            swprintf(info.string,sizeof(wchar_t)*512,L"%ls öldü",allies[i]->name);
            sendToRightSection(info);
            allies[i]=NULL;
            if(i<*allyC-1){
                for(int j=i;j<*allyC;j++){
                    allies[j]=allies[j+1];
                }
            }
            *allyC-=1;
            i--;
        }
    };
    for(int i=0;i<*enemyC;i++){
        if(enemies[i]->health<=0){
            message info;
            int xp=enemies[i]->level*25+rand()%25;
            int cur=enemies[i]->currency;
            *currency+=cur;
            *exp+=xp;
            swprintf(info.string,sizeof(wchar_t)*512,L"%ls öldü( %d XP ve %d altın toplam ganimete eklendi)",enemies[i]->name,xp,cur);
            sendToRightSection(info);
            clear();
            drawUI();
            enemies[i]=NULL;
            if(i<*enemyC-1){
                for(int j=i;j<*enemyC;j++){
                    enemies[j]=enemies[j+1];
                }
            }   
            *enemyC-=1;
            i--;
        }
    }
    if(PLAYER.chr.health<=0){
        message info={
            .string=L"Öldün."
        };
        sendToRightSection(info);
        return 2;
    }
    if(*enemyC<=0){
        message info={
            .string=L"Kazandınız."
        };
        sendToRightSection(info);
        return 1;
    }
    return 0;
}

void update_attack_weapons(){
    int weaponC=0;
    for(int i=0;i<PLAYER.chr.itemCount;i++){
        if(wcscmp(PLAYER.chr.items[i]->type,L"weapon")==0){
            wcscpy(selection_menu.menuItems[weaponC],PLAYER.chr.items[i]->name);
            weaponC++;
        }
    }
    selection_menu.itemCount=weaponC;
}

pItem findItemByName(pCharacter chr,wchar_t name[]){
    for(int i=0;i<chr->itemCount;i++){
        if(wcscmp(chr->items[i]->name,name)==0){
            return chr->items[i];
        }
    }
    return NULL;
}

void view_stats(pCharacter targets[],int targetI){
    view_enemies.itemCount=6;
    wcscpy(view_enemies.menuItems[0],L"Dayanıklılık   ");
    wcscpy(view_enemies.menuItems[1],L"Karizma        ");
    wcscpy(view_enemies.menuItems[2],L"Çeviklik       ");
    wcscpy(view_enemies.menuItems[3],L"Zeka           ");
    wcscpy(view_enemies.menuItems[4],L"Güç            ");
    wcscpy(view_enemies.menuItems[5],L"Bilgelik       ");
    for(int i=0;i<6;i++){
        swprintf(&view_enemies.menuItems[i][15],sizeof(wchar_t)*16,L": %d",*(&(targets[targetI]->stat.constition)+i));
    }
}