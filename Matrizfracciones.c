#include <stdio.h>
typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void llenar_matriz_fracciones(int tam, Fraccion matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Ingrese el numerador para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j].numerador);
            printf("Ingrese el denominador para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j].denominador);
            
        }}}

void mostrar_matriz_fracciones(int tam, Fraccion matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d/%d\t", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void multiplicar_fracciones_matrices(int tam, Fraccion A[tam][tam], Fraccion B[tam][tam], Fraccion resultado[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            resultado[i][j].numerador = A[i][j].numerador * B[i][j].numerador;
            resultado[i][j].denominador = A[i][j].denominador * B[i][j].denominador;
        }
    }
}

int main() {
    int tam;
    printf("Ingrese el tamano de las matrices cuadradas: ");
    scanf("%d", &tam);
    
    Fraccion matrizA[tam][tam];
    Fraccion matrizB[tam][tam];
    Fraccion resultado[tam][tam];
    
    printf("\nLlenado de la primera matriz:\n");
    llenar_matriz_fracciones(tam, matrizA);
    
    printf("\nLlenado de la segunda matriz:\n");
    llenar_matriz_fracciones(tam, matrizB);
    
    printf("\nMatriz A:\n");
    mostrar_matriz_fracciones(tam, matrizA);
    
    printf("\nMatriz B:\n");
    mostrar_matriz_fracciones(tam, matrizB);
    
    multiplicar_fracciones_matrices(tam, matrizA, matrizB, resultado);
    
    printf("\nResultado de la multiplicacion (fraccion por fraccion):\n");
    mostrar_matriz_fracciones(tam, resultado);
    
    return 0;
}