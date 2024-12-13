#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void chooseDiceTextFile(int randomNumber) {
    char fileName[20]; // Stores the file name that is just generated

    // Generate the file name if it exists then you cannot generate it
    sprintf(fileName, "../dicenums/%d.txt", randomNumber);

    // Open the file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    //print the numbers on the screen
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void clearScreen() {
    system("cls");
}

int randomNumber = (rand() % 20) + 1;

int rollDice() {
    srand(time(NULL));
    int randomNumberScreenTime = 0;



    PlaySound(TEXT("./sounds/effects/dice/dice.wav"), NULL, SND_FILENAME | SND_ASYNC);

    while (1) {


        PlaySound(TEXT("../sounds/effects/dice/knockwood.wav"), NULL, SND_FILENAME | SND_ASYNC);

        chooseDiceTextFile(randomNumber);

        Sleep(randomNumberScreenTime);

        randomNumberScreenTime += 10;


        if (randomNumberScreenTime == 300) {
            for (int i = 1; i < 4; i++) {
                randomNumberScreenTime += 300;
                Sleep(randomNumberScreenTime);
                clearScreen();
                randomNumber = (rand() % 20) + 1;
                chooseDiceTextFile(randomNumber);
                PlaySound(TEXT("./sounds/effects/dice/knockwood.wav"), NULL, SND_FILENAME | SND_ASYNC);

            }
            break;
        }
        clearScreen();
    }

    if (randomNumber == 20) {
        PlaySound(TEXT("./sounds/effects/dice/win.wav"), NULL, SND_FILENAME | SND_SYNC);
    }

    return randomNumber;


}
