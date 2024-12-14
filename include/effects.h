#ifndef EFFECTS_H
#define EFFECTS_H

#include <windows.h>

typedef struct {
    HANDLE stdOut;
    WORD color;
    int duration;
} ScreenEffect;

void flashScreen(ScreenEffect effect);
#endif //EFFECTS_H
