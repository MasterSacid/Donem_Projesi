// Bu dosya konsol fonksiyonlarıyla alakalıdır
#include <windows.h>
#include "console.h"

sprintf(HANDLE stdOut){

}

CONSOLE_SCREEN_BUFFER_INFO refreshSize(HANDLE stdOut){
    CONSOLE_SCREEN_BUFFER_INFO buffer;
    GetConsoleScreenBufferInfo(stdOut,&buffer);
    sizeX=buffer.srWindow.Right-buffer.srWindow.Left;
    sizeY=buffer.srWindow.Bottom-buffer.srWindow.Top;
    return buffer;
}