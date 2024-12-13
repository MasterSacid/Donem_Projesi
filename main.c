#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "include\menu.h"
#include "include\console.h"
#include <wchar.h>
#include <locale.h>

COORD coord;
int main(void) {
    setlocale(LC_ALL, "");
    HANDLE stdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn=GetStdHandle(STD_INPUT_HANDLE);
    menu main_menu;
    initMenu(
        &main_menu,
        L"Ana Menü",
        L"Ne yapmak istediğini seç",
        (wchar_t[][64]){L"Yola çık",L"Yemek ye",L"Uyu",L"Kamp kur"},
        5,
        NULL,
        NULL
    );

    //Başlangıç Seçenekleri
    pmenu selectedMenu=&main_menu;
    int itemIndex=0;

    while(1){
        //Görüntüleme
        displayMenu(stdOut,selectedMenu,itemIndex,&coord);

        //Kullanıcı İnteraksiyonu
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_UP,VK_DOWN,VK_RETURN},3);
            // Klavye kontrolü
        }
        clear(stdOut,&coord);
    }
    return 0;
}