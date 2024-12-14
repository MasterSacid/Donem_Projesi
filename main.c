#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"
#include <wchar.h>
#include <locale.h>

// Ekran boyutunu saklamak için açılan COORD yapısı
COORD coord;

int main(void) {
    setlocale(LC_ALL, "");
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);

    menu main_menu,confirm_exit,startAdventure,talkToSomeone,sing,eatFood;

    initMenu(
      &confirm_exit,
      L"Çık",
      L"Oyundan çıkmak istediğine\nemin misin ?",
      (wchar_t[][64]){L"Evet"},
      1,
      NULL,
      0,
      &main_menu
    );

    initMenu(
      &startAdventure,
      L"Maceraya Atıl",
      L"Bu Maceraya atılmak istediğinden\nemin misin ?",
      (wchar_t[][64]){L"Evet",L"Hayır"},
      2,
      NULL,
      0,
      &main_menu
    );

    initMenu(
      &talkToSomeone,
      L"Biriyle konuş",
      L"Kiminle konuşacaksın ?",
      (wchar_t[][64]){L"Ayyaş",L"Barmen",L"Gezgin",L"Evsiz"}, //Bu kişileri seçtikten sonra yanda resimler olabilir
      4,
      NULL,
      0,
      &main_menu
    );

    initMenu(
       &sing,
       L"Şarkı söyle",
       L"İstdeğin şarkıyı seç",
       (wchar_t[][64]){L"Şarkı1",L"Şarkı2"},
       2,
       NULL,
       0,
       &main_menu
    );
    initMenu(
        &eatFood,
        L"Yemek ye",
        L"Hangi yemeği alacaksın",
        (wchar_t[][64]){L"Yemek1",L"Yemek2",L"Yemek3",L"Yemek4",L"Yemek5"},
        5,
        NULL,
        0,
        &main_menu
    );
    // Önemli not : Yemek menüsü seçildikten sonra yanda ascii resimler gösterilebilir. Bu bir fikir sadece


    //Ana menü
    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        NULL,
        0,
        (pmenu[]){&startAdventure, &eatFood, &talkToSomeone, &sing},
        4,
        NULL
    );

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    //Başlangıç Seçenekleri

    pmenu selectedMenu=&main_menu;
    int itemIndex=0;
    clear(stdOut,&coord);
    wchar_t output[10][128]={
        L"TEST\n",
        L"TEST2\n",
        L"TEST3\n"
    };

    while(1){
        //Görüntüleme
        displayMenu(stdOut,selectedMenu,itemIndex,&coord);
        displayVertLine(stdOut,&coord,(COORD){33,0},(COORD){33,60},'|');
        displayHorLine(stdOut,&coord,(COORD){0,15},(COORD){33,15},'-');

        for(int i=0;i<10;i++){
            offset_prints(stdOut,output[i],(COORD){35,0+2*i});
        }

        //Klavyeden geçerli tuş alınması
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
            //Klavyeden alınan tuşa göre işlem yapılması
            int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
            switch(key){
                case -1:
                    continue;
                case 0:
                    //Menü en yukarıdayken yukarı tuşuna basıldığında en aşağı inme
                    if(itemIndex<=0){
                        itemIndex=totalCount;
                    }else if(itemIndex>=totalCount){
                        itemIndex=totalCount-1;
                    }else{
                        itemIndex--;
                    }
                    break;
                case 1:
                    //Menü en aşağıdayken aşağı tuşuna basıldığında en yukarı çıkma
                    if(itemIndex>=totalCount){
                        itemIndex=0;
                    }else{
                        itemIndex++;
                    }
                    break;
                case 2:
                    if(itemIndex>=totalCount){
                        if(selectedMenu==&main_menu){
                            selectedMenu=&confirm_exit;
                        }else{
                            selectedMenu=selectedMenu->parent;
                        }
                    }else if(itemIndex<=selectedMenu->childrenCount-1){
                        selectedMenu=selectedMenu->children[itemIndex];
                    }else{
                        if(selectedMenu==&confirm_exit){
                            if(itemIndex==0){
                                clear(stdOut,&coord);
                                return 0;
                            }
                        }
                    }
                    break;
                }
            }
            clear(stdOut,&coord);
        }
    return 0;
}