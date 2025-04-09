#include <stdio.h>

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

void escalarMatrizA(int filas, int columnas, 
    int matriz1[filas][columnas], int matrizeA[filas][columnas],
    int escalar) {  
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizeA[i][j] = matriz1[i][j] * escalar;  
        }
    }
}

void escalarMatrizB(int filas, int columnas, 
    int matriz2[filas][columnas], int matrizeB[filas][columnas],
    int escalar) {  
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizeB[i][j] = matriz2[i][j] * escalar;  
        }
    }
}

void determinanteMatrizA(int filas, int columnas, 
    int matriz1[filas][columnas],int deterA,
    int escalar) {  
            deterA= (matriz2[1][1] *matriz2[2][2]*matriz2[3][3])
                    +(matriz2[1][2] *matriz2[2][3]*matriz2[3][1])
                    +(matriz2[1][3] *matriz2[2][1]*matriz2[3][2])
                    -(matriz2[1][3] *matriz2[2][2]*matriz2[3][1])
                    -(matriz2[1][1] *matriz2[2][3]*matriz2[3][2])
                    -(matriz2[1][2] *matriz2[2][1]*matriz2[3][3])
                    ;
        }
    


void determinanteMatrizB(int filas, int columnas, 
    int matriz2[filas][columnas], int deterB,
    int escalar) {  
        deterB= (matriz2[1][1] *matriz2[2][2]*matriz2[3][3])
        +(matriz2[1][2] *matriz2[2][3]*matriz2[3][1])
        +(matriz2[1][3] *matriz2[2][1]*matriz2[3][2])
        -(matriz2[1][3] *matriz2[2][2]*matriz2[3][1])
        -(matriz2[1][1] *matriz2[2][3]*matriz2[3][2])
        -(matriz2[1][2] *matriz2[2][1]*matriz2[3][3])
        ;
        
    }


int main() {
    int filas, columnas, escalar, deterA,deterB;
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);
    
    printf("Ingrese el numero escalar para multiplicar la matriz: ");
    scanf("%d", &escalar);  
    
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_r[filas][columnas];
    int matriz_eA[filas][columnas];  
    int matriz_eB[filas][columnas];  


    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);
    
    imprimirMatriz("Matriz A", filas, columnas, matriz_a);
    imprimirMatriz("Matriz B", filas, columnas, matriz_b);
    
    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirMatriz("SUMA A+B", filas, columnas, matriz_r); 

    escalarMatrizA(filas, columnas, matriz_a, matriz_eA, escalar);
    imprimirMatriz("Matriz A multiplicada por escalar", filas, columnas, matriz_eA);
    escalarMatrizB(filas, columnas, matriz_b, matriz_eB, escalar);
    imprimirMatriz("Matriz B multiplicada por escalar", filas, columnas, matriz_eB);


    return 0;
}