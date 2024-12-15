#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    int result;         // // Random sonuc
    COORD position;     // konum belirle
    int diceType;       // maks zar boyutu
    int animationSpeed; // animasyon hızı
    int rolls;         // kaç tur çevrilcek
} DiceRollConfig;

// Function to display a single dice frame
void displayDiceFrame(HANDLE stdOut, int number, COORD position) {
    char fileName[64];
    sprintf(fileName, "../dicenums/%d.txt", number);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) return;

    CONSOLE_SCREEN_BUFFER_INFO savePos;
    GetConsoleScreenBufferInfo(stdOut, &savePos);

    SetConsoleCursorPosition(stdOut, position);
    char ch;
    COORD currentPos = position;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            currentPos.Y++;
            currentPos.X = position.X;
            SetConsoleCursorPosition(stdOut, currentPos);
        } else {
            putchar(ch);
            currentPos.X++;
        }
    }

    fclose(file);
    SetConsoleCursorPosition(stdOut, savePos.dwCursorPosition);
}

// Main dice rolling function
int rollDiceAnimated(HANDLE stdOut, DiceRollConfig config) {
    srand(time(NULL));

    // Store the current screen content
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(stdOut, &bufferInfo);

    // Calculate buffer size
    DWORD bufferSize = bufferInfo.dwSize.X * bufferInfo.dwSize.Y;
    CHAR_INFO* screenBuffer = malloc(sizeof(CHAR_INFO) * bufferSize);
    SMALL_RECT readRegion = {0, 0, bufferInfo.dwSize.X - 1, bufferInfo.dwSize.Y - 1};

    // Save current screen content
    ReadConsoleOutput(stdOut, screenBuffer, bufferInfo.dwSize, (COORD){0, 0}, &readRegion);

    // Play initial dice sound
    PlaySound(TEXT("../sounds/effects/dice/dice.wav"), NULL, SND_FILENAME | SND_ASYNC);

    int finalRoll = (config.result > 0) ? config.result : (rand() % config.diceType) + 1;

    // Animation loop
    for (int i = 0; i < config.rolls; i++) {
        // Restore the original screen content
        WriteConsoleOutput(stdOut, screenBuffer, bufferInfo.dwSize, (COORD){0, 0}, &readRegion);

        // Generate random number for animation
        int animationRoll;
        if (i == config.rolls - 1) {
            animationRoll = finalRoll; // Show final result
        } else {
            animationRoll = (rand() % config.diceType) + 1;
        }

        // Show the dice
        displayDiceFrame(stdOut, animationRoll, config.position);


        PlaySound(TEXT("../sounds/effects/dice/knockwood.wav"), NULL, SND_FILENAME | SND_ASYNC);

        // Gradually increase delay for slower animation
        Sleep(config.animationSpeed + (i * 50));
    }

    // Play win sound if maximum roll
    if (finalRoll == config.diceType) {
        PlaySound(TEXT("../sounds/effects/dice/win.wav"), NULL, SND_FILENAME | SND_SYNC);
    }

    // Free the buffer
    free(screenBuffer);

    return finalRoll;
}
int quickRollDice(HANDLE stdOut, COORD position, int diceType) {
    DiceRollConfig config = {
        .result = 0,            // Random sonuc
        .position = position,   // konum belirle
        .diceType = diceType,  // maks zar boyutu
        .animationSpeed = 100,  // animasyon hızı
        .rolls = 8             // kaç tur çevrilcek
    };

    return rollDiceAnimated(stdOut, config);
}



