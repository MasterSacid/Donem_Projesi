#include <windows.h>

typedef struct {
    HANDLE stdOut;
    WORD color;
    int duration;
} ScreenEffect;

#include <stdio.h>
#include <stdlib.h>

void flashScreen(ScreenEffect effect) {
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo; //contains the info about the console screen buffer
    GetConsoleScreenBufferInfo(effect.stdOut, &bufferInfo);

    // Calculate total screen size
    int width = bufferInfo.dwSize.X;
    int height = bufferInfo.dwSize.Y;
    int totalSize = width * height;

    // store the current content so we can retrieve it later
    CHAR_INFO* screenBuffer = malloc(sizeof(CHAR_INFO) * totalSize);
    if (!screenBuffer) return;

    // Define the region to save/restore (entire screen)
    SMALL_RECT region = {
        0, 0,
        width,
        height
    };

    // Save entire screen content including characters and their attributes
    ReadConsoleOutput(effect.stdOut,
                      screenBuffer,
                      (COORD){width, height},
                      (COORD){0, 0},
                      &region);

    // ----------------Fill entire screen with color ------
    DWORD write;
    /*At microsofts page it tells that this function:
    Sets the character attributes for a specified number of character cells,
    beginning at the specified coordinates in a screen buffer.
    */
    FillConsoleOutputAttribute(effect.stdOut, effect.color, totalSize, (COORD){0, 0}, &write);

    /*for this one
    Writes a character to the console screen buffer a specified number of times,
    beginning at the specified coordinates. */
    FillConsoleOutputCharacter(effect.stdOut, ' ', totalSize, (COORD){0, 0}, &write);

    Sleep(effect.duration);

    /* Restore the original screen content by
     writing character and color attribute data to a specified rectangular
     block of character cells in a console screen buffer. */
    WriteConsoleOutput(effect.stdOut,
                       screenBuffer,
                       (COORD){width, height},
                       (COORD){0, 0},
                       &region);

    free(screenBuffer);
}

/*NOTES BY THE AUTHOR (SACİD)
 In order to use this function effectiveley you have to define it in main like this

HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);

ScreenEffect effect = {
.stdOut = stdOut,
.color = BACKGROUND_RED | BACKGROUND_INTENSITY,
.duration = 200
};

flashScreen(effect); //and then call it like this

I have tried to implement with enums but cannot do that fix it asap if possible!
*/



