#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

Fraccion simplificar(Fraccion f) {
    int divisor = mcd(abs(f.numerador), abs(f.denominador));
    f.numerador /= divisor;
    f.denominador /= divisor;
    if (f.denominador < 0) {
        f.numerador *= -1;
        f.denominador *= -1;
    }
    return f;
}

Fraccion sumar(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return simplificar(resultado);
}

Fraccion restar(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return simplificar(resultado);
}

Fraccion multiplicar(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return simplificar(resultado);
}

Fraccion dividir(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.numerador = a.numerador * b.denominador;
    resultado.denominador = a.denominador * b.numerador;
    return simplificar(resultado);
}

Fraccion leer_fraccion() {
    Fraccion f;
    scanf("%d/%d", &f.numerador, &f.denominador);
    return simplificar(f);
}

void imprimir_fraccion(Fraccion f) {
    printf("%d/%d", f.numerador, f.denominador);
}

void llenar_matriz(int filas, int columnas, Fraccion matriz[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para [%d][%d] (formato a/b): ", i, j);
            matriz[i][j] = leer_fraccion();
        }
    }
}

void mostrar_matriz(int filas, int columnas, Fraccion matriz[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            imprimir_fraccion(matriz[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void transpuesta(int filas, int columnas, Fraccion matriz[MAX][MAX], Fraccion resultado[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[j][i] = matriz[i][j];
        }
    }
}

Fraccion traza(int tam, Fraccion matriz[MAX][MAX]) {
    Fraccion suma = (Fraccion){0, 1};
    for (int i = 0; i < tam; i++) {
        suma = sumar(suma, matriz[i][i]);
    }
    return suma;
}

Fraccion determinante_2x2(Fraccion matriz[2][2]) {
    Fraccion a = multiplicar(matriz[0][0], matriz[1][1]);
    Fraccion b = multiplicar(matriz[0][1], matriz[1][0]);
    return restar(a, b);
}

void adjunta_2x2(Fraccion matriz[2][2], Fraccion resultado[2][2]) {
    resultado[0][0] = matriz[1][1];
    resultado[0][1] = (Fraccion){-matriz[0][1].numerador, matriz[0][1].denominador};
    resultado[1][0] = (Fraccion){-matriz[1][0].numerador, matriz[1][0].denominador};
    resultado[1][1] = matriz[0][0];
}

int inversa_2x2(Fraccion matriz[2][2], Fraccion resultado[2][2]) {
    Fraccion det = determinante_2x2(matriz);
    if (det.numerador == 0) {
        return 0;
    }
    adjunta_2x2(matriz, resultado);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = dividir(resultado[i][j], det);
        }
    }
    return 1;
}

void copiar_2x2(Fraccion origen[MAX][MAX], Fraccion destino[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

void sumar_matrices(int filas, int columnas, Fraccion A[MAX][MAX], Fraccion B[MAX][MAX], Fraccion resultado[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = sumar(A[i][j], B[i][j]);
        }
    }
}

void restar_matrices(int filas, int columnas, Fraccion A[MAX][MAX], Fraccion B[MAX][MAX], Fraccion resultado[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = restar(A[i][j], B[i][j]);
        }
    }
}

void multiplicar_matrices(int filasA, int columnasA, int columnasB, Fraccion A[MAX][MAX], Fraccion B[MAX][MAX], Fraccion resultado[MAX][MAX]) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = (Fraccion){0, 1};
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] = sumar(resultado[i][j], multiplicar(A[i][k], B[k][j]));
            }
        }
    }
}

int main() {
    int tam;
    printf("Ingrese el tamano de las matrices cuadradas (max %d): ", MAX);
    scanf("%d", &tam);

    Fraccion A[MAX][MAX], B[MAX][MAX];
    printf("Ingrese los valores de la matriz A:\n");
    llenar_matriz(tam, tam, A);
    printf("Ingrese los valores de la matriz B:\n");
    llenar_matriz(tam, tam, B);

    printf("Matriz A:\n");
    mostrar_matriz(tam, tam, A);
    printf("Matriz B:\n");
    mostrar_matriz(tam, tam, B);

    Fraccion At[MAX][MAX], Bt[MAX][MAX];
    transpuesta(tam, tam, A, At);
    transpuesta(tam, tam, B, Bt);
    printf("Transpuesta de A:\n");
    mostrar_matriz(tam, tam, At);
    printf("Transpuesta de B:\n");
    mostrar_matriz(tam, tam, Bt);

    if (tam == 2) {
        Fraccion tempA[2][2], tempB[2][2];
        copiar_2x2(A, tempA);
        copiar_2x2(B, tempB);

        Fraccion detA = determinante_2x2(tempA);
        Fraccion detB = determinante_2x2(tempB);
        printf("Determinante de A: "); imprimir_fraccion(detA); printf("\n");
        printf("Determinante de B: "); imprimir_fraccion(detB); printf("\n");

        Fraccion invA[2][2], invB[2][2];
        if (inversa_2x2(tempA, invA)) {
            printf("Inversa de A:\n"); mostrar_matriz(2, 2, invA);
        } else {
            printf("No se puede calcular la inversa de A (determinante = 0).\n");
        }

        if (inversa_2x2(tempB, invB)) {
            printf("Inversa de B:\n"); mostrar_matriz(2, 2, invB);
        } else {
            printf("No se puede calcular la inversa de B (determinante = 0).\n");
        }

        Fraccion adjA[2][2], adjB[2][2];
        adjunta_2x2(tempA, adjA);
        adjunta_2x2(tempB, adjB);
        printf("Adjunta de A:\n"); mostrar_matriz(2, 2, adjA);
        printf("Adjunta de B:\n"); mostrar_matriz(2, 2, adjB);
    }

    if (tam == 2 || tam == 3) {
        Fraccion trazaA = traza(tam, A);
        Fraccion trazaB = traza(tam, B);
        printf("Traza de A: "); imprimir_fraccion(trazaA); printf("\n");
        printf("Traza de B: "); imprimir_fraccion(trazaB); printf("\n");
    }

    Fraccion suma[MAX][MAX], resta[MAX][MAX];
    sumar_matrices(tam, tam, A, B, suma);
    restar_matrices(tam, tam, A, B, resta);
    printf("Suma A + B:\n"); mostrar_matriz(tam, tam, suma);
    printf("Resta A - B:\n"); mostrar_matriz(tam, tam, resta);

    Fraccion producto[MAX][MAX];
    multiplicar_matrices(tam, tam, tam, A, B, producto);
    printf("Producto A * B:\n"); mostrar_matriz(tam, tam, producto);

    if (tam == 2) {
        Fraccion tempA[2][2], resultado[2][2];
        copiar_2x2(A, tempA);
        if (inversa_2x2(tempA, resultado)) {
            multiplicar_matrices(2, 2, 2, resultado, B, resultado);
            printf("Solucion X al sistema AX = B:\n"); mostrar_matriz(2, 2, resultado);
        } else {
            printf("No se puede resolver AX = B porque A no tiene inversa.\n");
        }
    }

    return 0;
}
