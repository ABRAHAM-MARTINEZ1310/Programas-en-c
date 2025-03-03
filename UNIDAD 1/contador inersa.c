#include <stdio.h>

int main() {
    int limetey = 10;

    while (limetey >= 0) {
        int limetex = 10;

        while (limetex >= 0) {
            printf("%4d", limetex); // Imprime el valor de limetex
            limetex--;
        }

        printf("\n"); // Salto de línea al final de cada fila
        limetey--;
    }

    return 0;
}