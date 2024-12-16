#include <stdio.h>
#include "menu.h"
#include "console.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "narrative.h"

void printSequence(HANDLE stdOut,dialog sequence[]){
    for(int i=0;sequence[i].message.string[0]!='\0';i++){
        printsAnimated(stdOut,&sequence[i].message,(COORD){0,0},10,"letter");
        Sleep(sequence[i].duration);
        if(sequence[i].clear){
            system("cls");
        }
    }
}
/*
int dialogChoice(HANDLE stdOut,HANDLE stdIn,wchar_t string[],wchar_t opts[][64],int optCount){
    int itemIndex=0;
    COORD size;
    refreshSize(stdOut,&size);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(stdOut,&bufferInfo);
    COORD pos=bufferInfo.dwCursorPosition;
    pos.Y+=5;
    int sizeTracker=0;
    while(1){

        wprintf(L"%ls",string);
        printf("\n");
        SetConsoleCursorPosition(stdOut,(COORD){pos.X+sizeTracker,pos.Y});
        // Seçenekleri Yazdır
        for(int i=0;wcscmp(opts[i],L"\0")!=0;i++){
            refreshSize(stdOut,&size);
            if(itemIndex==i){
                SetConsoleCursorPosition(stdOut,(COORD){pos.X+sizeTracker,pos.Y+1});
                for(int i=0;i<wcslen(opts[i]);i++){
                    printf("%c",'^');
                }
                SetConsoleCursorPosition(stdOut,(COORD){pos.X+sizeTracker,pos.Y});
                SetConsoleTextAttribute(stdOut,styleHiglight);
            }
            if(sizeTracker>size.X){
                pos.Y+=2;
                SetConsoleCursorPosition(stdOut,(COORD){pos.X,pos.Y});
                sizeTracker=0;
                wprintf(L"%ls",opts[i]);
                sizeTracker+=wcslen(opts[i])+5;
            }else{
                wprintf(L"%ls",opts[i]);
                sizeTracker+=wcslen(opts[i])+5;
            }
            SetConsoleCursorPosition(stdOut,(COORD){pos.X+sizeTracker,pos.Y});

            SetConsoleTextAttribute(stdOut,styleDefault);
        }
        sizeTracker=0;
        // Seçenekleri yazdırma bitti

        //Tuş alma
        int key=-1;
        while(key==-1){
            key=waitKeys(stdIn,(WORD[]){VK_LEFT,VK_RIGHT,VK_RETURN},3);
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
        clear(stdOut,&size);
    }
} */

int dialogChoice(HANDLE stdOut, HANDLE stdIn, wchar_t string[], wchar_t opts[][300], int optCount) {
    int itemIndex = 0;
    COORD size;
    refreshSize(stdOut, &size);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(stdOut, &bufferInfo);
    COORD pos = bufferInfo.dwCursorPosition;
    pos.Y += 2;

    while(1) {
        // Print the main string
        wprintf(L"%ls\n", string);

        // Print options vertically
        for(int i = 0; i < optCount; i++) {
            SetConsoleCursorPosition(stdOut, (COORD){pos.X, pos.Y + i});

            // Highlight selected option
            if(itemIndex == i) {
                SetConsoleTextAttribute(stdOut, styleHiglight);
                wprintf(L"> %ls", opts[i]);
            } else {
                SetConsoleTextAttribute(stdOut, styleDefault);
                wprintf(L"  %ls", opts[i]);  // Two spaces for alignment
            }

            SetConsoleTextAttribute(stdOut, styleDefault);
        }

        // Key input handling
        int key = -1;
        while(key == -1) {
            key = waitKeys(stdIn, (WORD[]){VK_UP, VK_DOWN, VK_RETURN}, 3);
        }

        switch(key) {
            case 0:  // Up
                if(itemIndex <= 0) {
                    itemIndex = optCount - 1;
                } else {
                    itemIndex--;
                }
            break;
            case 1:  // Down
                if(itemIndex >= optCount - 1) {
                    itemIndex = 0;
                } else {
                    itemIndex++;
                }
            break;
            case 2:  // Return
                return itemIndex;
        }

        clear(stdOut, &size);
    }
}