#include <stdio.h>

void llenar_matriz(int tam, int matriz[tam][tam]) {
    for (int i =0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Ingrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void llenar_vector(int tam, int vector[tam]) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el valor para la posicion [%d] del vector: ", i);
        scanf("%d", &vector[i]);
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

void mostrar_vector(int tam, int vector[tam]) {
    printf("\nVector:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", vector[i]);
    }
}

void multiplicar_matriz_vector(int tam, int matriz[tam][tam], int vector[tam], int resultado[tam]) {
    for (int i = 0; i < tam; i++) {
        resultado[i] = 0;
        for (int j = 0; j < tam; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    int tam;
    
    printf("Ingrese el tamano de la matriz cuadrada y el vector: ");
    scanf("%d", &tam);
    
    int matriz[tam][tam];
    int vector[tam];
    int resultado[tam];
    
    llenar_matriz(tam, matriz);
    llenar_vector(tam, vector);
    
    mostrar_matriz(tam, matriz);
    mostrar_vector(tam, vector);
    
    multiplicar_matriz_vector(tam, matriz, vector, resultado);
    
    printf("\nResultado de la multiplicacion matriz por vector:\n");
    mostrar_vector(tam, resultado);
    
    return 0;
}