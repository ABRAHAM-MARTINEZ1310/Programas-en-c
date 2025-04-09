#include <stdio.h>
#include <string.h>

#define FILAS 3
#define COLUMNAS 3
#define TAMANO_MAXIMA 100  // Longitud máxima de cada palabra

int main() {
    char matriz[FILAS][COLUMNAS][TAMANO_MAXIMA];  // Matriz para almacenar cadenas

    // Llenar la matriz con palabras ingresadas por el usuario
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Ingresa la palabra: ");
            scanf("%s", matriz[i][j]);
        }
    }


    printf("\nRecorriendo la matriz: \n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%s\t", matriz[i][j]);  
        }
        printf("\n");
    }

    return 0;
}