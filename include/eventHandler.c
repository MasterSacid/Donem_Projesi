#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "locationtime.h"
#include "menu.h"
#include "character.h"

void peopleAtLocation (pLocation loc) {

}

//Konuşma seçeneği seçildiğinde oyuncunun olduğu konumdaki karakterlerin ismini menüye yazan fonksiyon
void talkToSomeoneAtLocation (pLocation location,pmenu menu) {
    //wcscpy(menu->menuItems[0],location->character[0]->name);

    if (wcscmp(location->name,"Han")) {
        location ->charachterCount = 4;
    }

    menu->itemCount = 0;  // Reset menu item count

    // Iterate through all characters at the location
    for (int i = 0; i < location->charachterCount; i++) {
            wcscpy(menu->menuItems[menu->itemCount], location->character[i]->name);
            menu->itemCount++;
    }

}
/*  Macereya atıl
 *  1 Kolay
 *  2 Orta
 *  3 Zor
 *  ------
 */

void deleteAllCharacters(pLocation location) {

    // Free each character
    for (int i = 0; i < location->charachterCount; i++) {
        if (location->character[i]) {
            free(location->character[i]);
            location->character[i] = NULL;
        }
    }

    // Reset character count
    location->charachterCount = 0;
}



