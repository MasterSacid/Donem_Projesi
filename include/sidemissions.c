#include "menu.h"
#include "locationtime.h"
#include "combat.h"
#include "rolldice.h"
#include "character.h"

extern player PLAYER;
extern HANDLE STDOUT,STDIN;
extern pMenu CONFIRM,SELECTED_MENU,MAIN_MENU;
extern COORD SCREEN_SIZE;

item common_loot_table[4]={
    {.name=L"Elma",.type=L"food",.itemValues={L"saturation",5},.description=L"Taze kırmızı elma...\nSTatlı gözüküyor."},
    {.name=L"Kırık Kılıç",.type=L"weapon",.itemValues={L"modifier",2},.description=L"Kırık ama eskiden iyi\nbir kılıçmış."},
    {.name=L"Şifalı bitki",.type=L"herb",.itemValues={L"saturation",10},.description=L"Bu mantarların yenebilir\nolduğundan kesin eminim\n(sanırım)"},
    {.name=L"Minik Can İksiri",.itemValues={L"health",5},.description=L"Bir yudum ama az da olsa\niyileştirir."}
};

item rare_loot_table[4]={
    {.name=L"Karpuz",.itemValues={L"saturation",20},.description=L"Taze kırmızı elma...\nSTatlı gözüküyor."},
    {.name=L"Savaş Baltası",.itemValues={L"modifier",4},.description=L"Kırık ama eskiden iyi\nbir kılıçmış."},
    {.name=L"Enerji Karışımı",.type=L"consumable",.itemValues={L"exhaustion",-50},.description=L"Yorgunluğa iyi gelir."},
    {.name=L"Orta Boy Can İksiri",.type=L"consumable",.itemValues={L"health",15},.description=L"Orta boyutta bir can iksiri."}
};

location dark_forest={
    .name=L"Karanlık Orman"
};

void side_mission_dark_forest(){
    change_location(&dark_forest);
    while(1){
        refreshSize();
        //Rasgele etkinlik
        int difficulty=10;
        DiceRollConfig cfg={
            .animationSpeed=100,
            .diceType=20,
            .result=0,
            .position={SCREEN_SIZE.X/2,SCREEN_SIZE.Y/2},
            .rolls=10
        };
        int random=rollDiceAnimated(STDOUT,cfg)+(PLAYER.chr.stat.wisdom-10)/2;
        message info;
        if(random<6){
            //COMBAT
        }else if(random<11){
            int xp=rand()%10+1;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"Hiçbir şey bulamadın ama gezerken deneyim kazandın.(%d Deneyim)",xp);
        }else if(random<16){
            int xp=rand()%20+1;
            int cur=rand()%40+1;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"Yeni eşya(lar) buldun envanterini kontrol et.(%d deneyim ve %d altın kazandın.)",xp,cur);
            for(int i=0;i<4;i++){
                if(rand()%3>1){
                    addItem(&PLAYER.chr,&common_loot_table[i]);
                }
            }
        }else{
            int xp=rand()%40+1;
            int cur=rand()%80+1;
            swprintf(info.string,sizeof(info.string)/sizeof(wchar_t),L"Yeni eşya(lar) buldun envanterini kontrol et.(%d deneyim ve %d altın kazandın.)",xp,cur);
            for(int i=0;i<4;i++){
                if(rand()%3>1){
                    addItem(&PLAYER.chr,&rare_loot_table[i]);
                }
            }
        }
        pass_time(rand()%(4*60*60)+2*60*60);
        sendToRightSection(info);
        if(confirm_menu(CONFIRM,"Macera","Maceraya devam etmek\nister misin?",MAIN_MENU)==0){
            continue;
        }else{
            SELECTED_MENU=MAIN_MENU;
            break;
        }
    }   
}