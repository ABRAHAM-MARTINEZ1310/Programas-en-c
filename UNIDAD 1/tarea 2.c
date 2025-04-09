#include <stdio.h>
#define FILAS 6
#define COLUMNAS 6

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {10, 20, 30, 40, 60, 30}, 
        {40, 50, 60, 60, 40, 20},
        {70, 80, 90, 0, 50, 30},
        {10, 20, 30, 40, 60, 30},
        {40, 50, 60, 60, 40, 20},
        {70, 80, 90, 0, 50, 30}
    };

    printf("Recorriendo la matriz:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (j % 2 == 0) { 
                printf("|%d ", matriz[i][j]); // Imprime el valor de la matriz
            } else { 
                printf("|# "); // Imprime un símbolo "#"
            }
        }
        printf("|\n"); 
    }

    return 0;
}