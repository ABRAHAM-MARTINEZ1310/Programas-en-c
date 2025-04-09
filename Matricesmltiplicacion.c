#include <stdio.h>

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

void multiplicar_matrices(int tam, int matrizA[tam][tam], int matrizB[tam][tam], int resultado[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            resultado[i][j] = 0;
        }
    }
    

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            for (int k = 0; k < tam; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
    int tam;

    printf("Ingrese el tamano para las matrices cuadradas: ");
    scanf("%d", &tam);
    

    int matrizA[tam][tam];
    int matrizB[tam][tam];
    int resultado[tam][tam];
    

    llenar_matriz(tam, matrizA);
    llenar_matriz(tam, matrizB);
    

    printf("\nMatrices ingresadas:");
    mostrar_matriz(tam, matrizA);
    mostrar_matriz(tam, matrizB);
    

    multiplicar_matrices(tam, matrizA, matrizB, resultado);
    

    printf("\nResultado de la multiplicacion (A x B):");
    mostrar_matriz(tam, resultado);
    
    return 0;
}