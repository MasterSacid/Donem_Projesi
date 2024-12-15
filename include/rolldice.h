#ifndef ROLLDICE_H
#define ROLLDICE_H

#include <windows.h>

typedef struct {
    int result;         // // Random sonuc
    COORD position;     // konum belirle
    int diceType;       // maks zar boyutu
    int animationSpeed; // animasyon hızı
    int rolls;         // kaç tur çevrilcek
} DiceRollConfig;

// Function Declarations
void displayDiceFrame(HANDLE stdOut, int number, COORD position);
int rollDiceAnimated(HANDLE stdOut, DiceRollConfig config);
int quickRollDice(HANDLE stdOut, COORD position, int diceType);

#endif ROLLDICE_H
