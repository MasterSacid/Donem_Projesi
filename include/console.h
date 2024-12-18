#pragma once
#include <windows.h>
#include "console.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define styleHiglight BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED
#define styleDefault FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED

typedef struct message{
    wchar_t string[512];
    char shown;
    int highlight[8][2];
    char color[8][16];
}message,*pMessage;

CONSOLE_SCREEN_BUFFER_INFO refreshSize();

int waitKeys(WORD keys[],int keyAmount);

void clearChosenArea(COORD start, COORD end); //Sacit ekledi kafan karışmasın

void clear();

void displayVertLine(COORD start, COORD end, char displaychar);

void displayHorLine(COORD start,COORD end,char displaychar);

void offset_prints(wchar_t string[], COORD start);

void hide_cursor();

void unhide_cursor();

void printsAnimated(pMessage msg, COORD start, int ms, char stopAt[]);

void printMessages(COORD start,int ms,char style[]);

void fitToLine(int lineSize, wchar_t string[]);

void sendToRightSection(message newMessage);