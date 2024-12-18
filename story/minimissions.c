#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/rolldice.h"
#include "../include/eventHandler.h"
#include "../include/console.h"
#include "../include/narrative.h"


DiceRollConfig config = {
    .result = 0,            // Random sonuc
    .position = (COORD){0,12}   // konum belirle
    .diceType = 12,  // maks zar boyutu
    .animationSpeed = 100,  // animasyon hızı
    .rolls = 8             // kaç tur çevrilcek
};


void minigamePicker () {
    rollDiceAnimated(stdout,config);
}


