// Bu dosya konsol fonksiyonlarıyla alakalıdır
#include "../UI/ui.h"
#include <windows.h>
#include "console.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

extern HANDLE STDOUT;
extern HANDLE STDIN;
extern COORD SCREEN_SIZE;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNTER;


CONSOLE_SCREEN_BUFFER_INFO refreshSize(){
    CONSOLE_SCREEN_BUFFER_INFO buffer;
    GetConsoleScreenBufferInfo(STDOUT,&buffer);
    SCREEN_SIZE.X=buffer.srWindow.Right-buffer.srWindow.Left;
    SCREEN_SIZE.Y=buffer.srWindow.Bottom-buffer.srWindow.Top;
    return buffer;
}

int waitKeys(WORD keys[],int keyAmount){
    INPUT_RECORD input;
    DWORD eventsRead;
    int j=-1;
    if(ReadConsoleInputW(STDIN,&input,1,&eventsRead)){
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

void clearChosenArea(COORD start, COORD end) { //Sacit ekledi kafan karışmasın
    refreshSize();
    DWORD nChars;
    int width = end.X - start.X + 1;
    int height = end.Y - start.Y + 1;

    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(STDOUT, &savePos);

    FillConsoleOutputAttribute(STDOUT, styleDefault, width * height, start, &nChars);
    FillConsoleOutputCharacter(STDOUT, ' ', width * height, start, &nChars);

    SetConsoleCursorPosition(STDOUT, savePos.dwCursorPosition);
}

void clear(){
    DWORD temp;
    refreshSize();
    FillConsoleOutputAttribute(STDOUT,styleDefault,(DWORD)((SCREEN_SIZE.X+1)*(SCREEN_SIZE.Y+1)),(COORD){0,0},&temp);
    FillConsoleOutputCharacterW(STDOUT,' ',(DWORD)((SCREEN_SIZE.X+1)*(SCREEN_SIZE.Y+1)),(COORD){0,0},&temp);
    SetConsoleCursorPosition(STDOUT,(COORD){0,0});
}

// Dikey çizgi çizer
void displayVertLine(COORD start,COORD end,char displaychar){
    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(STDOUT,&savePos);
    int temp=start.Y;
    refreshSize();
    SetConsoleCursorPosition(STDOUT,start);
    for(int i=0;i<=end.X-start.X;i++){
        for(int j=0;j<end.Y-start.Y;j++){
            //SetConsoleTextAttribute(STDOUT,styleHiglight);
            printf("%c",displaychar);
            start.Y++;
            SetConsoleCursorPosition(STDOUT,(COORD){start.X,start.Y});
        }
        start.Y=temp;
        start.X++;
        SetConsoleCursorPosition(STDOUT,(COORD){start.X,start.Y});
    }
    SetConsoleTextAttribute(STDOUT,styleDefault);
    SetConsoleCursorPosition(STDOUT,savePos.dwCursorPosition);
}

// Yatay Çizgi çizer
void displayHorLine(COORD start,COORD end,char displaychar){
    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(STDOUT,&savePos);
    int temp=start.X;
    refreshSize();
    SetConsoleCursorPosition(STDOUT,start);
    for(int i=0;i<=end.Y-start.Y;i++){
        for(int j=0;j<end.X-start.X;j++){
            //SetConsoleTextAttribute(STDOUT,styleHiglight);
            SetConsoleCursorPosition(STDOUT,(COORD){start.X+j,start.Y+i});
            printf("%c",displaychar);
        }
    }
    SetConsoleTextAttribute(STDOUT,styleDefault);
    SetConsoleCursorPosition(STDOUT,savePos.dwCursorPosition);
}

//Kayık yazdırma fonksiyonu
void offset_prints(wchar_t string[],COORD start){
    SetConsoleCursorPosition(STDOUT,start);
    for(int i=0;i<wcslen(string);i++){
        if(string[i]==L'\n'){
            start.Y++;
            SetConsoleCursorPosition(STDOUT,(COORD){start.X,start.Y});
        }else{
            wprintf(L"%lc",string[i]);
        }
    }
}

void hide_cursor(){
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(STDOUT,&cursor);
    cursor.bVisible=FALSE;
    SetConsoleCursorInfo(STDOUT,&cursor);
}

void unhide_cursor(){
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(STDOUT,&cursor);
    cursor.bVisible=TRUE;
    SetConsoleCursorInfo(STDOUT,&cursor);
}

void printsAnimated(pMessage msg,COORD start,int ms,char stopAt[]){
    COORD temp=start;
    refreshSize();
    fitToLine(SCREEN_SIZE.X-start.X,msg->string);
    int nCounter=0;
    if(strcmp(stopAt,"letter")==0){
        for(int i=0;i<wcslen(msg->string);i++){
            if(msg->string[i]==L'\n'){
                nCounter++;
                start.X=temp.X;
            }
            wchar_t currentChar[2]={msg->string[i],L'\0'};
            offset_prints(currentChar,(COORD){start.X,start.Y+nCounter});
            start.X++;
            Sleep(ms);
        }
        Sleep(1000);
    }else if(strcmp(stopAt,"word")==0){
        wchar_t array[32];
        int counter=0;
        for(int i=0;i<wcslen(msg->string);i++){
            if(msg->string[i]==L' '){
                array[counter]=L'\0';
                offset_prints(array,start);
                start.X+=counter;
                wcscpy(array,L"\0");
                counter=0;
                Sleep(ms);
            }
            array[counter]=msg->string[i];
            counter++;
        }
        array[counter]=L'\0';
        offset_prints(array,start);
    }else if(strcmp(stopAt,"uneven")==0){
        srand(time(NULL));
            for(int i=0;i<wcslen(msg->string);i++){
                int y=rand()%3;
                wchar_t currentChar[2]={msg->string[i],L'\0'};
                offset_prints(currentChar,(COORD){start.X,start.Y});
                start.X++;
                Sleep(ms);
        }
    }
}

void printMessages(COORD start,int ms,char style[]){
    for(int i=0;i<15;i++){
        if(GAME_MESSAGES[i].shown==0){
            printsAnimated(&GAME_MESSAGES[i],(COORD){start.X,start.Y+2*i},ms,style);
            GAME_MESSAGES[i].shown=1;
        }else{
            offset_prints(GAME_MESSAGES[i].string,(COORD){start.X,start.Y+2*i});
        }
        if(GAME_MESSAGES[i+1].string[0]==L'\0'){
            break;
        }
    }
}

void fitToLine(int lineSize,wchar_t string[]){
    int stringSize=wcslen(string);
    int currentChar=0;
    while(stringSize>lineSize){
        for(int i=lineSize-1;i>=0;i--){
            if(string[currentChar+i]==L' ' || string[currentChar+i]==L'\n'){
                string[currentChar+i]=L'\n';
                currentChar+=i;
                stringSize-=lineSize;
                break;
            }
            if(i<=-1){
                string[currentChar+i]=L'\n';
                currentChar+=lineSize;
                stringSize-=lineSize;
                break;
            }
        }
    }
}

void sendToRightSection(message newMessage) {
    if (GAME_MESSAGE_COUNTER < 15) {
        (GAME_MESSAGE_COUNTER)++;
    }

    for (int i = GAME_MESSAGE_COUNTER - 1; i > 0; i--) {
        GAME_MESSAGES[i] = GAME_MESSAGES[i - 1];
    }

    GAME_MESSAGES[0] = newMessage;
    clear();
    drawUI();
}