#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char* chooseArtFile(const char *artname, char* buffer, size_t bufferSize) {
    FILE *file = fopen(artname, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    size_t pos = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && pos < bufferSize - 1) {
        buffer[pos++] = ch;
    }
    buffer[pos] = '\0';

    fclose(file);
    return buffer;
}

int getArtWidth(const char* art) { //the value that returns might be used to center the art
    int maxWidth = 0;
    int currentWidth = 0;

    for(int i = 0; art[i] != '\0'; i++) {
        if(art[i] == '\n') {
            if(currentWidth > maxWidth) {
                maxWidth = currentWidth;
            }
            currentWidth = 0;
        } else {
            currentWidth++;
        }
    }

    //check final line
    if(currentWidth > maxWidth) {
        maxWidth = currentWidth;
    }

    return maxWidth;
}

