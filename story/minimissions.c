#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "../include/rolldice.h"
#include "minimissions.h"
#include "../include/eventHandler.h"
#include "../include/console.h"
#include "../include/narrative.h"


int minigamePicker (int ITEM_INDEX,int MISSION_COUNTER) {
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //-----------MEMORY GAME -----------------
    if (MISSION_COUNTER == 0) {
        if (ITEM_INDEX == 0) {
            DiceRollConfig easy = {
                .result = 0,            // Random sonuc
                .position = (COORD){15,12},   // konum belirle
                .diceType = 5,  // maks zar boyutu
                .animationSpeed = 100,  // animasyon hızı
                .rolls = 10             // kaç tur çevrilcek
            };
            int memoryGameResult = memoryGame(3);
            int diceResult= rollDiceAnimated(stdOut,easy);
            int gameScore= memoryGameResult + diceResult;
            return gameScore;

        }
        if (ITEM_INDEX == 1) {

            DiceRollConfig medium = {
                .result = 0,            // Random sonuc
                .position = (COORD){15,12},   // konum belirle
                .diceType = 12,  // maks zar boyutu
                .animationSpeed = 100,  // animasyon hızı
                .rolls = 10             // kaç tur çevrilcek
            };

            int memoryGameResult= memoryGame(6);
            int diceResult= rollDiceAnimated(stdOut,medium);
            int gameScore= memoryGameResult + diceResult;
            return gameScore;
        }
        if (ITEM_INDEX == 2) {
            DiceRollConfig hard = {
                .result = 0,            // Random sonuc
                .position = (COORD){15,12},   // konum belirle
                .diceType = 20,  // maks zar boyutu
                .animationSpeed = 100,  // animasyon hızı
                .rolls = 20             // kaç tur çevrilcek
            };
            int memoryGameResult=memoryGame(9);
            int diceResult=rollDiceAnimated(stdOut,hard);
            int gameScore= memoryGameResult + diceResult;
            return gameScore;
        }
    }




}




void displayNumberFromFile(int number) {
    char fileName[20];
    sprintf(fileName, "../dicenums/%d.txt", number);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void clearScreen() {
    system("cls");
}


void playSoundAndWait(const char* soundFile) {
    PlaySound(soundFile, NULL, SND_FILENAME | SND_SYNC);
}


void displaySequence(int sequence[], int length, int untilThatNumber) {
    for (int i = 0; i < length; i++) {
        clearScreen();
        displayNumberFromFile(sequence[i]);


        char soundFile[20];
        sprintf(soundFile, "../sounds/memorygame/coremusic/%d.wav", i % untilThatNumber + 1);
        playSoundAndWait(soundFile);
    }
    clearScreen();
}

//Zaman kısıtlaması olayını ChatGPT yazdı onun dışındakileri ben yazdım :9
int userInputForMinigame(int sequence[], int length,int untilThatNumber) {
    for (int i = 0; i < length; i++) {
        DWORD startTime = GetTickCount();
        int timeLimit = 5000; // 5 seconds in milliseconds
        char input = 0;

        while (GetTickCount() - startTime < timeLimit) {
            if (_kbhit()) {  // Check if a key has been pressed
                input = _getch();
                if (input >= '1' && input <= '9') {
                    break;
                }
            }
            Sleep(10);  // Small delay to prevent high CPU usage
        }

        // If no valid input received within time limit
        if (input < '1' || input > '9') {
            clearScreen();
            printf("Zaman doldu!\n");
            //printf("Skor: %d\n", i);
            return 0;
        }

        int userInput = input - '0';

        clearScreen();
        displayNumberFromFile(userInput);

        // Play sound
        char soundFile[20];
        sprintf(soundFile, "../sounds/memorygame/coremusic/%d.wav", i % untilThatNumber + 1);
        playSoundAndWait(soundFile);

        if (userInput != sequence[i]) {
            clearScreen();
            printf("Batirdin cevabin su olmasi lazimdi ");
            for (int j = 0; j <= i; j++) {
                printf("%d ", sequence[j]);
            }
            printf("\nGG!\n");
            return 0;
        }
    }
    return 1;
}

int memoryGame(int untilThatNumber){
    srand(time(NULL));
    int sequence[9];
    int currentLength=1;
    int gameOver = 0;

    PlaySound("../sounds/memorygame/effects/fullsound.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("Hafiza Oyunu!\n");
    printf("Tekrar et.\n");
    Sleep(5000);
    clearScreen();

    sequence[0] = (rand() % untilThatNumber) + 1;

    while (!gameOver && currentLength < untilThatNumber+1) {
        displaySequence(sequence, currentLength,untilThatNumber);

        if (!userInputForMinigame(sequence, currentLength,untilThatNumber)) {
            gameOver = 1;
            break;
        }

        printf("Helal len!\n");
        Sleep(1000);
        //PlaySound("correct.wav", NULL, SND_FILENAME | SND_SYNC);
        clearScreen();

        sequence[currentLength] = (rand() % untilThatNumber) + 1;
        currentLength++;
    }

    printf("Skor: %d\n", currentLength);
    //PlaySound("gameover.wav", NULL, SND_FILENAME | SND_SYNC);
    Sleep(4000);
    clearScreen();
    return currentLength;
}

