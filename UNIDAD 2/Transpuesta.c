#include <stdio.h>
#include <stdlib.h>
void llenar_matriz(int tam, int matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Ingrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar_matriz(int tam, int matriz[tam][tam]) {
    printf("\nMatriz %dx%d:\n", tam, tam);
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void transponer_matriz(int tam, int matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            int a = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i]= a;
        }
    }
}

int main() {
    int tam;
    
    printf("Tamano de la matriz cuadrada: ");
    scanf("%d", &tam);
    int matriz[tam][tam];
    
    llenar_matriz(tam, matriz);
    mostrar_matriz(tam, matriz);
    
    transponer_matriz(tam, matriz);
    mostrar_matriz(tam, matriz);
    
return 0;
}