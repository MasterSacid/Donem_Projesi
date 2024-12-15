#include <windows.h>
#include <wchar.h>
#ifndef CONSOLE
#define CONSOLE
#define styleHiglight BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED
#define styleDefault FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED

typedef struct message{
    wchar_t string[128];
    char shown;
    int highlight[8][2];
    char color[8][16];
}message,*pMessage;

CONSOLE_SCREEN_BUFFER_INFO refreshSize(HANDLE stdOut,PCOORD coord);
int waitKeys(HANDLE stdIn,WORD keys[],int keyAmount);
void clear(HANDLE stdOut,PCOORD coord);

void clearChosenArea(HANDLE stdOut, PCOORD coord, COORD start, COORD end); //Sacit ekledi kafan karışmasın

void displayVertLine(HANDLE stdOut, PCOORD coord, COORD start, COORD end, char displaychar);

void displayHorLine(HANDLE stdOut,PCOORD coord,COORD start,COORD end,char displaychar);

void offset_prints(HANDLE stdOut, wchar_t string[], COORD start);

void hide_cursor(HANDLE stdOut);

void unhide_cursor(HANDLE stdOut);

void printsAnimated(HANDLE stdOut, pMessage msg, COORD start, int ms, char stopAt[]);

void printMessages(HANDLE stdOut, message msgs[], COORD start);

#endif