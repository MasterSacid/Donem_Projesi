#include <windows.h>
#include <wchar.h>
#ifndef CONSOLE
#define CONSOLE
#define styleHiglight BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED
#define styleDefault FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED

CONSOLE_SCREEN_BUFFER_INFO refreshSize(HANDLE stdOut,PCOORD coord);
int waitKeys(HANDLE stdIn,WORD keys[],int keyAmount);
void clear(HANDLE stdOut,PCOORD coord);

void clearChosenArea(HANDLE stdOut, PCOORD coord, COORD start, COORD end); //Sacit ekledi kafan karışmasın
void writeOneByOne(HANDLE stdOut, const wchar_t* inputText, COORD position,int waitMiliSeconds); //Sacit ekledi kafan karışmasın

void displayVertLine(HANDLE stdOut, PCOORD coord, COORD start, COORD end, char displaychar);

void displayHorLine(HANDLE stdOut,PCOORD coord,COORD start,COORD end,char displaychar);

void offset_prints(HANDLE stdOut, wchar_t string[], COORD start);

void hide_cursor(HANDLE stdOut);

#endif