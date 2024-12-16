#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.h"
#include "../story/part2.h"
#include "narrative.h"
static int counter=0;


void startAdventureEvent() {


    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);



    dialog dialogues3[] = {
        {{L"\nBu bir denemedir"}, 1000, 1},
    };

    if (counter == 0) {
        system("cls");
        printSequence(stdOut, dialogues3);
        //bolum_2_savas();
        system("cls");
        counter++; // Increment counter
    } else if (counter == 1) {
        system("cls");
       bolum_2_savas();
        counter++;
    }


}


void talkToSomeoneMenuChange(menu* talkToSomeone) {

    wchar_t list1[][64] = {L"Adam1", L"Adam2"};
    wchar_t list2[][64] = {L"Adam3", L"Adam4"};



    wchar_t (*currentList)[64];
    int itemCount;
    if (counter == 0) {
        currentList = list1;
        itemCount = 2;

    } else if (counter == 1) {
        currentList = list2;
        itemCount = 2;
    }
    talkToSomeone->itemCount = itemCount;
    for (int i = 0; i < itemCount; i++) {
        wcscpy(talkToSomeone->menuItems[i], currentList[i]);
    }
}
