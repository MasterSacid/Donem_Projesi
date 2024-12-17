#pragma once
#include <windows.h>

typedef struct {
    HANDLE stdOut;
    WORD color;
    int duration;
} ScreenEffect;

void flashScreen(ScreenEffect effect);