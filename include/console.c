// Bu dosya konsol fonksiyonlarıyla alakalıdır
#include <windows.h>
#include "console.h"
#include <wchar.h>


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

void clear(HANDLE stdOut,PCOORD coord){
    refreshSize(stdOut,coord);
    COORD start={0,0};
    DWORD nChars;
    FillConsoleOutputAttribute(stdOut,styleDefault,coord->X*coord->Y,start,&nChars);
    FillConsoleOutputCharacter(stdOut,' ',coord->X*coord->Y,start,&nChars);
    SetConsoleCursorPosition(stdOut,start);
}