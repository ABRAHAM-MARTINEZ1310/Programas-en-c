#include <stdio.h>
#define tamano 3
void llenarMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatriz(int filas, int columnas, 
    int matriz1[filas][columnas], int matriz2[filas][columnas], 
    int matrizr[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void escalarMatriz(int filas, int columnas, 
    int matriz[filas][columnas], int matrizResultado[filas][columnas],
    int escalar) {  
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizResultado[i][j] = matriz[i][j] * escalar;  
        }
    }
}

int determinante(int matriz[tamano][tamano]) {
    int suma = 0, resta = 0;   
        for (int i = 0; i < tamano; i++) {
        int producto = 1;
        for (int j = 0; j < tamano; j++) {
         producto *= matriz[j][(i + j) % tamano];
        }
        suma += producto;
    }
    for (int i = 0; i < tamano; i++) {
        int producto = 1;
       for (int j = 0; j < tamano; j++) {
            producto *= matriz[j][(i - j + tamano) % tamano];
            }
        resta += producto;
    }
    return suma - resta;
}

int main() {
    int filas, columnas, escalar;

    printf("Numero de filas: ");
    scanf("%d", &filas);
    printf("Numero de columnas: ");
    scanf("%d", &columnas);
    
    printf("\nIngrese el escalar para multiplicacion: ");
    scanf("%d", &escalar);
    
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_r[filas][columnas];
    int matriz_eA[filas][columnas];
    int matriz_eB[filas][columnas];

    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);
    
    printf("\nMATRICES ORIGINALES:\n");
    imprimirMatriz("Matriz A", filas, columnas, matriz_a);
    imprimirMatriz("Matriz B", filas, columnas, matriz_b);
    
    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
    printf("\nRESULTADO DE SUMA:\n");
    imprimirMatriz("A + B", filas, columnas, matriz_r);
    
    escalarMatriz(filas, columnas, matriz_a, matriz_eA, escalar);
    printf("\nRESULTADO DE MULTIPLICACION POR ESCALAR:\n");
    imprimirMatriz("Escalar de la Matriz A", filas, columnas, matriz_eA);
    
    escalarMatriz(filas, columnas, matriz_b, matriz_eB, escalar);
    imprimirMatriz("Escalar de la Matriz B", filas, columnas, matriz_eB);

    
    if(filas == 3 && columnas == 3) {
        int deterA = calcularDeterminante(matriz_a);
        int deterB = calcularDeterminante(matriz_b);
        printf("Determinante de A: %d\n", deterA);
        printf("Determinante de B: %d\n", deterB);
    } else {
        printf("\nEl calculo de determinantes solo esta disponible para matrices 3x3 Para ver determinantes, ingrese matrices de 3 filas y 3 columnas ");

    }

    return 0;
}