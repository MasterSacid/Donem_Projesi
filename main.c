#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"
#include <wchar.h>
#include <locale.h>

// Ekran boyutunu saklamak için açılan COORD yapısı
COORD coord;

enum{
    startAdventure,
    talkToSomeone,
    sing,
    eatFood
};

int main(void) {
    setlocale(LC_ALL, "");
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);

    //Ana menü
    menu main_menu,startAdventure,eatFood,talkToSomeone,sing;
    pmenu mainMenuChildren[50] = {&startAdventure, &eatFood, &talkToSomeone, &sing};


    initMenu(
      &startAdventure,
      L"Maceraya Atıl",
      L"Bu Maceraya atılmak istediğinden emin misin ?",
      (wchar_t[][64]){L"Evet",L"Hayır"},
      2,
      NULL,
      &main_menu
  );

    initMenu(
      &talkToSomeone,
      L"Biriyle konuş",
      L"Kiminle konuşacaksın ?",
      (wchar_t[][64]){L"Ayyaş",L"Barmen",L"Gezgin",L"Evsiz"}, //Bu kişileri seçtikten sonra yanda resimler olabilir
      4,
      NULL,
      &main_menu
  );

    initMenu(
       &sing,
       L"Şarkı söyle",
       L"İstdeğin şarkıyı seç",
       (wchar_t[][64]){L"Şarkı1",L"Şarkı2"},
       2,
       NULL,
       &main_menu
   );
    initMenu(
        &eatFood,
        L"Yemek ye",
        L"Hangi yemeği alacaksın",
        (wchar_t[][64]){L"Yemek1",L"Yemek2",L"Yemek3",L"Yemek4",L"Yemek5"},
        5,
        NULL,
        &main_menu
    );
    // Önemli not : Yemek menüsü seçildikten sonra yanda ascii resimler gösterilebilir. Bu bir fikir sadece



    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        (wchar_t[][64]){L"Maceraya atıl",L"Etraftakilerle konuş",L"Şarkı söyle",L"Yemek ye"},
        4,
        mainMenuChildren,
        NULL
    );

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    //Başlangıç Seçenekleri
    pmenu menus[]={&startAdventure,&talkToSomeone,&sing,&eatFood};

    pmenu selectedMenu=&main_menu;
    int itemIndex=0;
    clear(stdOut,&coord);

    while(1){
        //Görüntüleme
        displayMenu(stdOut,selectedMenu,itemIndex,&coord);
        displayVertLine(stdOut,&coord,(COORD){33,0},(COORD){33,60},'|');
        displayHorLine(stdOut,&coord,(COORD){0,15},(COORD){33,15},'-');
        //Klavyeden geçerli tuş alınması
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
        }
        //Klavyeden alınan tuşa göre işlem yapılması
        switch(key){
            case -1:
                continue;
            case 0:
                //Menü en yukarıdayken yukarı tuşuna basıldığında en aşağı inme
                if(itemIndex<=0){
                    itemIndex=selectedMenu->itemCount;
                }else{
                    itemIndex--;
                }
                break;
            case 1:
                //Menü en aşağıdayken aşağı tuşuna basıldığında en yukarı çıkma
                if(itemIndex>=selectedMenu->itemCount){
                    itemIndex=0;
                }else{
                    itemIndex++;
                }
                break;
            case 2:
                if(itemIndex>selectedMenu->itemCount){
                    return 0;
                }else if(selectedMenu==&main_menu){
                    selectedMenu=menus[itemIndex];
                }
                break;
        }
        clear(stdOut,&coord);
    }
    return 0;
}