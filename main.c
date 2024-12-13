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

    //Ana menü
    menu main_menu;
    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        (wchar_t[][64]){L"Yola çık",L"Yemek ye",L"Uyu",L"Kamp kur"},
        4,
        NULL,
        0,
        NULL
    );

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    //Başlangıç Seçenekleri

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
        int totalCount=selectedMenu->childrenCount+selectedMenu->itemCount;
        switch(key){
            case -1:
                continue;
            case 0:
                //Menü en yukarıdayken yukarı tuşuna basıldığında en aşağı inme
                if(itemIndex<=0){
                    itemIndex=totalCount;
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
                        return 0;
                    }else{
                        selectedMenu=selectedMenu->parent;
                    }
                }else if(itemIndex<selectedMenu->childrenCount){
                    selectedMenu=selectedMenu->children[itemIndex];
                }
                break;
            }
        clear(stdOut,&coord);
        }
    return 0;
}