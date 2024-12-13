#include <stdio.h>

void chooseArtFile(const char *artname) {
    char cwd[1024];

    FILE *file = fopen(artname, "r");
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
