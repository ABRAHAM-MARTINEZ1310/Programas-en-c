#include <stdio.h>

#define FILAS 3
#define COLUMNAS 6

int main() {
    int matriz[FILAS][COLUMNAS];  // Matriz para almacenar números
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < 2; j++) {  
            printf("Ingresa el valor: ");
            scanf("%d", &matriz[i][j]);
        }
        matriz[i][2] = matriz[i][0] + matriz[i][1]; 
        matriz[i][3] = matriz[i][0] - matriz[i][1]; 
        matriz[i][4] = matriz[i][0] * matriz[i][1]; 
        matriz[i][5] = matriz[i][0] / matriz[i][1];
    }

    printf("\nRecorriendo la matriz: \n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d\t", matriz[i][j]);  
        }
        printf("\n");
    }

    return 0;
}

