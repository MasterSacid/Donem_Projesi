#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "narrative.h"

extern HANDLE STDOUT,STDIN;

void printSequence(dialog sequence[]){
    for(int i=0;sequence[i].message.string[0]!='\0';i++){
        printsAnimated(&sequence[i].message,(COORD){0,0},10,"letter");
        Sleep(sequence[i].duration);
        if(sequence[i].clear){
            system("cls");
        }
    }
}
//Narrative.c
void printSequenceOnDialog(dialog sequence[]){
    for(int i=0;sequence[i].message.string[0]!='\0';i++){
        printsAnimated(&sequence[i].message,(COORD){35,0},10,"letter");
        Sleep(sequence[i].duration);
        if(sequence[i].clear){
            system("cls");
        }
    }
}



/*
int dialogChoice(HANDLE STDOUT,HANDLE STDIN,wchar_t string[],wchar_t opts[][64],int optCount){
    int itemIndex=0;
    COORD size;
    refreshSize(STDOUT,&size);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(STDOUT,&bufferInfo);
    COORD pos=bufferInfo.dwCursorPosition;
    pos.Y+=5;
    int sizeTracker=0;
    while(1){

        wprintf(L"%ls",string);
        printf("\n");
        SetConsoleCursorPosition(STDOUT,(COORD){pos.X+sizeTracker,pos.Y});
        // Seçenekleri Yazdır
        for(int i=0;wcscmp(opts[i],L"\0")!=0;i++){
            refreshSize(STDOUT,&size);
            if(itemIndex==i){
                SetConsoleCursorPosition(STDOUT,(COORD){pos.X+sizeTracker,pos.Y+1});
                for(int i=0;i<wcslen(opts[i]);i++){
                    printf("%c",'^');
                }
                SetConsoleCursorPosition(STDOUT,(COORD){pos.X+sizeTracker,pos.Y});
                SetConsoleTextAttribute(STDOUT,styleHiglight);
            }
            if(sizeTracker>size.X){
                pos.Y+=2;
                SetConsoleCursorPosition(STDOUT,(COORD){pos.X,pos.Y});
                sizeTracker=0;
                wprintf(L"%ls",opts[i]);
                sizeTracker+=wcslen(opts[i])+5;
            }else{
                wprintf(L"%ls",opts[i]);
                sizeTracker+=wcslen(opts[i])+5;
            }
            SetConsoleCursorPosition(STDOUT,(COORD){pos.X+sizeTracker,pos.Y});

            SetConsoleTextAttribute(STDOUT,styleDefault);
        }
        sizeTracker=0;
        // Seçenekleri yazdırma bitti

        //Tuş alma
        int key=-1;
        while(key==-1){
            key=waitKeys(STDIN,(WORD[]){VK_LEFT,VK_RIGHT,VK_RETURN},3);
        }
        switch(key){
            case -1:
                continue;
            case 0:
                if(itemIndex<=0){
                    itemIndex=optCount;
                }else if(itemIndex>optCount-1){
                    itemIndex=optCount-1;
                }else{
                    itemIndex--;
                }
                break;
            case 1:
                if(itemIndex>=optCount-1){
                    itemIndex=0;
                }else{
                    itemIndex++;
                }
                break;
            case 2:
                return itemIndex;
                break;
        }
        clear(STDOUT,&size);
    }
} */

int dialogChoice(wchar_t string[], wchar_t opts[][300], int optCount) {
    int itemIndex = 0;
    COORD size;
    refreshSize(); // Get console dimensions
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(STDOUT, &bufferInfo);
    COORD pos = bufferInfo.dwCursorPosition;
    pos.Y += 2;

    int consoleWidth = bufferInfo.dwSize.X; // Width of the console buffer

    while (1) {
        // Print the main string
        wprintf(L"%ls\n", string);

        // Print options vertically
        int currentY = pos.Y; // Track current Y position
        for (int i = 0; i < optCount; i++) {
            SetConsoleCursorPosition(STDOUT, (COORD){pos.X, currentY});

            // Highlight selected option
            if (itemIndex == i) {
                SetConsoleTextAttribute(STDOUT, styleHiglight);
                wprintf(L"> %ls", opts[i]);
            } else {
                SetConsoleTextAttribute(STDOUT, styleDefault);
                wprintf(L"  %ls", opts[i]); // Two spaces for alignment
            }

            SetConsoleTextAttribute(STDOUT, styleDefault);

            // Calculate the number of lines this option takes
            int optionLength = wcslen(opts[i]);
            int linesRequired = (optionLength + consoleWidth - 1) / consoleWidth; // Round up
            currentY += linesRequired; // Move to the next option's Y position
        }

        // Key input handling
        int key = -1;
        while (key == -1) {
            key = waitKeys((WORD[]){VK_UP, VK_DOWN, VK_RETURN}, 3);
        }

        switch (key) {
            case 0:  // Up
                if (itemIndex <= 0) {
                    itemIndex = optCount - 1;
                } else {
                    itemIndex--;
                }
                break;
            case 1:  // Down
                if (itemIndex >= optCount - 1) {
                    itemIndex = 0;
                } else {
                    itemIndex++;
                }
                break;
            case 2:  // Return
                return itemIndex;
        }

        system("cls");
    }
}
