#include <stdio.h>
#include <stdlib.h>

int toplam = 0;
int sayiTopla(int x);
int main(void) {
    int x;

    printf("Lütfen sayiyi girin: ");
    scanf("%d", &x);
    printf("\n birden girdiğiniz sayıya kadar olan sayıların toplamı %d dir", sayiTopla(x));

    return 0;
}

int sayiTopla(int x) {
    if (x <= 0) {
        return 0;
    }

    return x + sayiTopla(x - 1);
}