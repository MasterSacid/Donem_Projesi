#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"
#include "include/arthandler.h"
#include "include/rolldice.h"
#include "include/effects.h"
#include <wchar.h>
#include <locale.h>


int centerArtX(); //Bu fonksiyon main içinde olmak zorunda

// Ekran boyutunu saklamak için açılan COORD yapısı
COORD coord;
char artBuffer [4096]; //Ascii tablolarının maks karakter sayısı

int main(void) {
    setlocale(LC_ALL, "");
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);

    hide_cursor(stdOut);

    menu main_menu,confirm_exit,startAdventure,talkToSomeone,sing,eatFood,diceTestMenu;

    // BUNU UNUTMA BU BİR DEBUG
    initMenu(
        &diceTestMenu,
        L"Zar Test",
        L"Test için zar at",
        (wchar_t[][64]){L"20 At", L"6 At", L"Özel Zar"},
        3,
        NULL,
        0,
        &talkToSomeone
    );

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

    //burayı unutma kaldırıcan
    initMenu(
        &talkToSomeone,
        L"Biriyle konuş",
        L"Kiminle konuşacaksın ?",
        (wchar_t[][64]){L"Ayyaş",L"Barmen",L"Gezgin",L"Evsiz"},
        4,
        (pmenu[]){&diceTestMenu},  // Add diceTestMenu as child
        1,  // Set childrenCount to 1
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

    pmenu selectedMenu=&main_menu;
    int itemIndex=0;
    clear(stdOut,&coord);
    wchar_t output[10][128]={
        L"TEST\n",
        L"TEST2\n",
        L"TEST3\n"
    };

    while(1){
        displayMenu(stdOut,selectedMenu,itemIndex,&coord);
        displayVertLine(stdOut,&coord,(COORD){33,0},(COORD){33,60},'|');
        displayHorLine(stdOut,&coord,(COORD){0,15},(COORD){33,15},'-');

        for(int i=0;i<10;i++){
            offset_prints(stdOut,output[i],(COORD){35,0+2*i});
        }

        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
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
                    // Handle dice rolling first
                    if(selectedMenu == &diceTestMenu && itemIndex < selectedMenu->itemCount) {
                        switch(itemIndex) {
                            case 0:
                                quickRollDice(stdOut, (COORD){35, 5}, 20);
                                break;
                            case 1:
                                quickRollDice(stdOut, (COORD){35, 5}, 6);
                                break;
                            case 2: {
                                DiceRollConfig config = {
                                    .result = 0,
                                    .position = {60, 10},
                                    .diceType = 20,
                                    .animationSpeed = 100,
                                    .rolls = 8
                                };
                                //rollDiceAnimated(stdOut, config);
                                HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);

                                ScreenEffect effect = {
                                    .stdOut = stdOut,
                                    .color = BACKGROUND_RED | BACKGROUND_INTENSITY,
                                    .duration = 200
                                    };

                                flashScreen(effect); //and then call it like this
                                break;
                            }
                        }
                        Sleep(1000); //Zar atılasın diye bekliyoruz
                        break;
                    }

                    // Handle regular menu navigation
                    if(itemIndex>=totalCount){
                        if(selectedMenu==&main_menu){
                            selectedMenu=&confirm_exit;
                        }else{
                            selectedMenu=selectedMenu->parent;
                        }
                    }else if(itemIndex<=selectedMenu->childrenCount-1){
                        selectedMenu=selectedMenu->children[itemIndex];
                    }else if(selectedMenu==&confirm_exit && itemIndex==0){
                        clear(stdOut,&coord);
                        return 0;
                    }
                    break;
            }
            clear(stdOut,&coord);
        }
    }
    return 0;
}

int centerArtX() {
    int rightSectionWidth = coord.X - 33;
    int artWidth = getArtWidth(artBuffer);
    int centeredX = 33 + ((rightSectionWidth - artWidth) / 2);
    return centeredX;
}