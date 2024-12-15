// Bu dosya konsol fonksiyonlarıyla alakalıdır
#include <windows.h>
#include "console.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


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
    FillConsoleOutputAttribute(stdOut,styleDefault,(coord->X+1)*(coord->Y+1),start,&nChars);
    FillConsoleOutputCharacter(stdOut,' ',(coord->X+1)*(coord->Y+1),start,&nChars);
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

void printsAnimated(HANDLE stdOut,pMessage msg,COORD start,int ms,char stopAt[]){
    COORD temp=start;
    COORD size;
    refreshSize(stdOut,&size);
    fitToLine(size.X-start.X,msg->string);
    int nCounter=0;
    if(strcmp(stopAt,"letter")==0){
        for(int i=0;i<wcslen(msg->string);i++){
            if(msg->string[i]==L'\n'){
                nCounter++;
                start.X=temp.X;
            }
            wchar_t currentChar[2]={msg->string[i],L'\0'};
            offset_prints(stdOut,currentChar,(COORD){start.X,start.Y+nCounter});
            start.X++;
            Sleep(ms);
        }
    }else if(strcmp(stopAt,"word")==0){
        wchar_t array[32];
        int counter=0;
        for(int i=0;i<wcslen(msg->string);i++){
            if(msg->string[i]==L' '){
                array[counter]=L'\0';
                offset_prints(stdOut,array,start);
                start.X+=counter;
                wcscpy(array,L"\0");
                counter=0;
                Sleep(ms);
            }
            array[counter]=msg->string[i];
            counter++;
        }
        array[counter]=L'\0';
        offset_prints(stdOut,array,start);
    }else if(strcmp(stopAt,"uneven")==0){
        srand(time(NULL));
            for(int i=0;i<wcslen(msg->string);i++){
                int y=rand()%3;
                wchar_t currentChar[2]={msg->string[i],L'\0'};
                offset_prints(stdOut,currentChar,(COORD){start.X,start.Y});
                start.X++;
                Sleep(ms);
        }
    }
}

void printMessages(HANDLE stdOut,message msgs[],COORD start,int ms,char style[]){
        for(int i=0;i<10;i++){
            if(msgs[i].shown==0){
                printsAnimated(stdOut,&msgs[i],(COORD){start.X,start.Y+2*i},ms,style);
                msgs[i].shown=1;
            }else{
                offset_prints(stdOut,msgs[i].string,(COORD){start.X,start.Y+2*i});
            }
            if(msgs[i+1].string[0]==L'\0'){
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