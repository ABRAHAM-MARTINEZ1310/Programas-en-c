#include <stdio.h>
#include <stdlib.h>


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void lineaHorizontal(int longitud, int x, int y) {
    gotoxy(x, y);
    for(int i = 0; i < longitud; i++) {
        printf("*");
    }
}


void lineaVertical(int altura, int x, int y) {
    for(int i = 0; i < altura; i++) {
        gotoxy(x, y + i);
        printf("*");
    }
}


void dibujarMarco(int ancho, int alto, int x, int y) {
    lineaHorizontal(ancho, x, y);
    lineaVertical(alto - 2, x, y + 1);
    lineaVertical(alto - 2, x + ancho - 1, y + 1);
    lineaHorizontal(ancho, x, y + alto - 1);
}


void mostrarMenu(int x, int y) {
    gotoxy(x, y++); printf("1. Suma matriz");
    gotoxy(x, y++); printf("2. Resta matriz ");
    gotoxy(x, y++); printf("3. Multiplicacion matriz");
    gotoxy(x, y++); printf("4. Determinante");
}

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
            producto =producto* matriz[j][(i + j) % tamano];
        }
        suma =suma+ producto;
    }
    
    for (int i = 0; i < tamano; i++) {
        int producto = 1;
        for (int j = 0; j < tamano; j++) {
            producto =producto* matriz[tamano-1-j][(i+j) % tamano];
        }
        resta =resta+ producto;
    }
    
    return suma - resta;
}

int main() {
    int opcion;
    float num1, num2;
    int filas, columnas,escalar;
    system("cls || clear"); 
    


    dibujarMarco(30, 10, 5, 3);
    
    mostrarMenu(9, 5);
    

    gotoxy(25, 9);
    printf("Opc: ");
    scanf("%d", &opcion);
    printf("\033[2J");
    printf("Numero de filas: ");
    scanf("%d", &filas);
    printf("Numero de columnas: ");
    scanf("%d", &columnas);
    printf("\033[2J");
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_r[filas][columnas];
    int matriz_eA[filas][columnas];
    int matriz_eB[filas][columnas];
    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);
    switch(opcion) {
        case 1:
        printf("\033[2J");
        imprimirMatriz("Matriz A", filas, columnas, matriz_a);
        imprimirMatriz("Matriz B", filas, columnas, matriz_b);
        sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
        printf("\nRESULTADO DE SUMA:\n");
        imprimirMatriz("A + B", filas, columnas, matriz_r);
            break;
        case 2:
        printf("\033[2J");
        imprimirMatriz("Matriz A", filas, columnas, matriz_a);
        imprimirMatriz("Matriz B", filas, columnas, matriz_b);
            break;
        case 3:
        printf("\033[2J");
        imprimirMatriz("Matriz A", filas, columnas, matriz_a);
        imprimirMatriz("Matriz B", filas, columnas, matriz_b);
        escalarMatriz(filas, columnas, matriz_a, matriz_eA, escalar);
        printf("\nRESULTADO DE MULTIPLICACION POR ESCALAR:\n");
        imprimirMatriz("Escalar de la Matriz A", filas, columnas, matriz_eA);

            break;
        case 4:
        printf("\033[2J");
        imprimirMatriz("Matriz A", filas, columnas, matriz_a);
        imprimirMatriz("Matriz B", filas, columnas, matriz_b);
            break;

    }
    
    return 0;
}