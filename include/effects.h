#pragma once
#include <windows.h>

typedef struct {
    HANDLE STDOUT;
    WORD color;
    int duration;
} ScreenEffect;

void flashScreen(ScreenEffect effect);