#include <stdio.h>
#include <stdlib.h> // Para system("cls")

// Función gotoxy como la tenías
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Función para dibujar los bordes verticales
void dibujarBordes(int x, int y, int altura, int ancho) {
    for(int i = 0; i < altura; i++) {
        gotoxy(x, y + i); printf("*");
        gotoxy(x + ancho + 1, y + i); printf("*");
    }
}

// TUS FUNCIONES ORIGINALES (sin cambios)
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
    int x = 10, y = 5; // Posición inicial
    int ancho = columnas * 5;
    
    // Dibujar bordes verticales
    dibujarBordes(x, y, filas + 2, ancho);
    
    // Título centrado
    gotoxy(x + 1, y); printf("%*s", (ancho + strlen(nombre))/2, nombre);
    
    // Datos de la matriz
    for(int i = 0; i < filas; i++) {
        gotoxy(x + 1, y + i + 1);
        for(int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
    }
}

// Operación de suma con gotoxy
void mostrarSuma(int filas, int columnas, int A[filas][columnas], int B[filas][columnas], int R[filas][columnas]) {
    system("cls");
    int y = 5;
    
    // Matriz A
    imprimirMatriz("MATRIZ A", filas, columnas, A);
    
    // Signo +
    gotoxy(35, y + filas/2); printf("+");
    
    // Matriz B (a la derecha de A)
    imprimirMatriz("MATRIZ B", filas, columnas, B);
    gotoxy(10, y + filas + 3); // Posición para resultado
    
    // Línea de igual
    gotoxy(35, y + filas + 3 + filas/2); printf("=");
    
    // Resultado (abajo)
    imprimirMatriz("RESULTADO", filas, columnas, R);
}

// (Tus otras funciones originales aquí...)

int main() {
    int filas = 3, columnas = 3; // Ejemplo con matrices 3x3
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_r[filas][columnas];
    
    // Llenar matrices (como en tu código original)
    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);
    
    // Sumar matrices
    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
    
    // Mostrar con gotoxy y bordes
    mostrarSuma(filas, columnas, matriz_a, matriz_b, matriz_r);
    
    return 0;
}