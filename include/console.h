#include <windows.h>
#ifndef CONSOLE
#define CONSOLE
#define styleHiglight BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED
#define styleDefault FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED

CONSOLE_SCREEN_BUFFER_INFO refreshSize(HANDLE stdOut,PCOORD coord);

#endif

