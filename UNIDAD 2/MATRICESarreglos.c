#include <stdio.h>

#define FILAS 3                                 //DIRECTIVA DEL PROCESADOR, ES UNA VARIABLE GLOBAL
#define COLUMNAS 3

int main(){
    int matriz[FILAS][COLUMNAS] = {                //INT MATRIZ ES UN CONJUNTO DE ARREGLOS
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Recorriendo la matriz: \n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);  // Usar corchetes para acceder a los elementos de la matriz
        }
        printf("\n");
    }
    return 0;
}