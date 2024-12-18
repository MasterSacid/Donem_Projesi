#pragma once
#include <windows.h>

typedef struct {
    int result;         // // Random sonuc
    COORD position;     // konum belirle
    int diceType;       // maks zar boyutu
    int animationSpeed; // animasyon hızı
    int rolls;         // kaç tur çevrilcek
} DiceRollConfig;

// Function Declarations
void displayDiceFrame(HANDLE STDOUT, int number, COORD position);
int rollDiceAnimated(HANDLE STDOUT, DiceRollConfig config);
int quickRollDice(HANDLE STDOUT, COORD position, int diceType);

