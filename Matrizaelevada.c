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
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_matrices(int tam, int A[tam][tam], int B[tam][tam], int resultado[tam][tam]) {
    int temp[tam][tam];
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < tam; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
 
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            resultado[i][j] = temp[i][j];
        }
    }
}

void matriz_potencia(int tam, int matriz[tam][tam], int exponente, int resultado[tam][tam]) {

    int temp[tam][tam];
    

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            resultado[i][j] = (i == j) ? 1 : 0;
            temp[i][j] = matriz[i][j];
        }
    }
    
    for (int contador = 0; contador < exponente; contador++) {
        multiplicar_matrices(tam, resultado, matriz, resultado);
    }
}

int main() {
    int tam, exponente;
    printf("Ingrese el tamano de la matriz cuadrada: ");
    scanf("%d", &tam);
    
    printf("Ingrese el exponente al que desea elevar la matriz: ");
    scanf("%d", &exponente);
    
    if (exponente < 0) {
        printf("Error: El exponente debe ser un numero no negativo.\n");
        return 1;
    }
    
    int matriz[tam][tam];
    int resultado[tam][tam];
    
    llenar_matriz(tam, matriz);
    
    printf("\nMatriz original (%dx%d):\n", tam, tam);
    mostrar_matriz(tam, matriz);
    
    matriz_potencia(tam, matriz, exponente, resultado);
    
    printf("\nMatriz elevada a la potencia %d:\n", exponente);
    mostrar_matriz(tam, resultado);
    
    return 0;
}