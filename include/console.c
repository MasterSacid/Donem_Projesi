// Bu dosya konsol fonksiyonlarıyla alakalıdır
#include <windows.h>
#include "console.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>



CONSOLE_SCREEN_BUFFER_INFO refreshSize(HANDLE stdOut,PCOORD coord){
    CONSOLE_SCREEN_BUFFER_INFO buffer;
    GetConsoleScreenBufferInfo(stdOut,&buffer);
    coord->X=buffer.srWindow.Right-buffer.srWindow.Left;
    coord->Y=buffer.srWindow.Bottom-buffer.srWindow.Top;
    return buffer;
}

int waitKeys(HANDLE stdIn,WORD keys[],int keyAmount){
    INPUT_RECORD input;
    DWORD eventsRead;
    int j=-1;
    if(ReadConsoleInputW(stdIn,&input,1,&eventsRead)){
        if(input.EventType==KEY_EVENT){
            if(input.Event.KeyEvent.bKeyDown){
                for(int i=0;i<keyAmount;i++){
                    if(input.Event.KeyEvent.wVirtualKeyCode==keys[i]){
                        j=i;
                        break;
                    }
                }
            }
        }
    }
    return j;
}

//Ekranı temizler
void clear(HANDLE stdOut,PCOORD coord){
    refreshSize(stdOut,coord);
    COORD start={0,0};
    DWORD nChars;
    FillConsoleOutputAttribute(stdOut,styleDefault,coord->X*coord->Y,start,&nChars);
    FillConsoleOutputCharacter(stdOut,' ',coord->X*coord->Y,start,&nChars);
    SetConsoleCursorPosition(stdOut,start);
}

void clearChosenArea(HANDLE stdOut, PCOORD coord, COORD start, COORD end) { //Sacit ekledi kafan karışmasın
    refreshSize(stdOut, coord);
    DWORD nChars;
    int width = end.X - start.X + 1;
    int height = end.Y - start.Y + 1;

    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(stdOut, &savePos);

    FillConsoleOutputAttribute(stdOut, styleDefault, width * height, start, &nChars);
    FillConsoleOutputCharacter(stdOut, ' ', width * height, start, &nChars);

    SetConsoleCursorPosition(stdOut, savePos.dwCursorPosition);
}

// Dikey çizgi çizer
void displayVertLine(HANDLE stdOut,PCOORD coord,COORD start,COORD end,char displaychar){
    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(stdOut,&savePos);
    int temp=start.Y;
    refreshSize(stdOut,coord);
    SetConsoleCursorPosition(stdOut,start);
    for(int i=0;i<=end.X-start.X;i++){
        for(int j=0;j<end.Y-start.Y;j++){
            //SetConsoleTextAttribute(stdOut,styleHiglight);
            printf("%c",displaychar);
            start.Y++;
            SetConsoleCursorPosition(stdOut,(COORD){start.X,start.Y});
        }
        start.Y=temp;
        start.X++;
        SetConsoleCursorPosition(stdOut,(COORD){start.X,start.Y});
    }
    SetConsoleTextAttribute(stdOut,styleDefault);
    SetConsoleCursorPosition(stdOut,savePos.dwCursorPosition);
}

// Yatay Çizgi çizer
void displayHorLine(HANDLE stdOut,PCOORD coord,COORD start,COORD end,char displaychar){
    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(stdOut,&savePos);
    int temp=start.X;
    refreshSize(stdOut,coord);
    SetConsoleCursorPosition(stdOut,start);
    for(int i=0;i<=end.Y-start.Y;i++){
        for(int j=0;j<end.X-start.X;j++){
            //SetConsoleTextAttribute(stdOut,styleHiglight);
            SetConsoleCursorPosition(stdOut,(COORD){start.X+j,start.Y+i});
            printf("%c",displaychar);
        }
    }
    SetConsoleTextAttribute(stdOut,styleDefault);
    SetConsoleCursorPosition(stdOut,savePos.dwCursorPosition);
}

//Kayık yazdırma fonksiyonu
void offset_prints(HANDLE stdOut,wchar_t string[],COORD start){
    SetConsoleCursorPosition(stdOut,start);
    for(int i=0;i<wcslen(string);i++){
        if(string[i]==L'\n'){
            start.Y++;
            SetConsoleCursorPosition(stdOut,(COORD){start.X,start.Y});
        }else{
            wprintf(L"%lc",string[i]);
        }
    }
}
//Bir Bir Yazdırma Fonksiyonu
void writeOneByOne(HANDLE stdOut, const wchar_t* inputText, COORD position,int waitMiliSeconds) {
    for (size_t i = 0; i < wcslen(inputText); i++) {
        wchar_t currentChar[2] = {inputText[i], L'\0'};  // Passes the current char in input text to the current char string array
        offset_prints(stdOut, currentChar, position);
        position.X++;  // Move to next position
        Sleep(waitMiliSeconds);     // Add delay between characters
    }
}

void hide_cursor(HANDLE stdOut){
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(stdOut,&cursor);
    cursor.bVisible=FALSE;
    SetConsoleCursorInfo(stdOut,&cursor);
}

void unhide_cursor(HANDLE stdOut){
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(stdOut,&cursor);
    cursor.bVisible=TRUE;
    SetConsoleCursorInfo(stdOut,&cursor);
}