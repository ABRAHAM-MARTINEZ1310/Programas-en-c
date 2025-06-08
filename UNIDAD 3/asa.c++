// Proyecto de Álgebra Lineal - Abraham Ismael Martínez Santiago
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int color_code) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}

void limpiar_pantalla() {
    system("cls");
}

void pausar() {
    printf("\nPresiona ENTER para continuar...");
    while (getchar() != '\n');
}

void portada() {
    limpiar_pantalla();
    color(14);
    gotoxy(30, 2); printf("UNIVERSIDAD DE LA SALLE OAXACA");
    gotoxy(24, 4); printf("INGENIERIA EN SOFTWARE Y SISTEMAS COMPUTACIONALES");
    gotoxy(32, 5); printf("ALGEBRA LINEAL - SOFTWARE B");
    gotoxy(30, 6); printf("PROFESOR: LUIS ANGEL");
    gotoxy(30, 7); printf("ALUMNO: ABRAHAM ISMAEL MARTINEZ SANTIAGO");
    gotoxy(30, 9); printf("Presiona ENTER para continuar...");
    color(15);
    while (getchar() != '\n');
    limpiar_pantalla();
}

int mcd(int a, int b) {
    return (b == 0) ? a : mcd(b, a % b);
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

Fraccion leer_fraccion() {
    Fraccion f;
    char slash;
    while (1) {
        printf("Ingrese fraccion (a/b): ");
        if (scanf("%d %c %d", &f.numerador, &slash, &f.denominador) == 3 && slash == '/' && f.denominador != 0) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            return simplificar(f);
        }
        color(12);
        printf("[ERROR] Entrada invalida. Formato correcto: a/b con b distinto de cero.\n");
        color(15);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

void imprimir_fraccion(Fraccion f, int color_code) {
    color(color_code);
    printf("%d/%d", f.numerador, f.denominador);
    color(15);
}

Fraccion sumar(Fraccion a, Fraccion b) {
    Fraccion res = { a.numerador * b.denominador + b.numerador * a.denominador, a.denominador * b.denominador };
    return simplificar(res);
}

Fraccion restar(Fraccion a, Fraccion b) {
    Fraccion res = { a.numerador * b.denominador - b.numerador * a.denominador, a.denominador * b.denominador };
    return simplificar(res);
}

Fraccion multiplicar(Fraccion a, Fraccion b) {
    Fraccion res = { a.numerador * b.numerador, a.denominador * b.denominador };
    return simplificar(res);
}

Fraccion dividir(Fraccion a, Fraccion b) {
    if (b.numerador == 0) {
        color(12); printf("[ERROR] Division entre cero.\n"); color(15);
        exit(1);
    }
    Fraccion res = { a.numerador * b.denominador, a.denominador * b.numerador };
    return simplificar(res);
}

Fraccion** crear_matriz(int filas, int columnas) {
    Fraccion** m = (Fraccion**)malloc(filas * sizeof(Fraccion*));
    for (int i = 0; i < filas; i++)
        m[i] = (Fraccion*)malloc(columnas * sizeof(Fraccion));
    return m;
}

void liberar_matriz(Fraccion** m, int filas) {
    for (int i = 0; i < filas; i++)
        free(m[i]);
    free(m);
}

void llenar_matriz(Fraccion** m, int filas, int columnas, char nombre) {
    color(10);
    printf("\nLlenado de matriz %c:\n", nombre);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("%c[%d][%d] = ", nombre, i, j);
            m[i][j] = leer_fraccion();
        }
    color(15);
}

void mostrar_matriz_color(Fraccion** m, int filas, int columnas, int color_code) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            imprimir_fraccion(m[i][j], color_code);
            printf("\t");
        }
        printf("\n");
    }
}

Fraccion** transpuesta(Fraccion** m, int filas, int columnas) {
    Fraccion** res = crear_matriz(columnas, filas);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            res[j][i] = m[i][j];
    return res;
}

Fraccion determinante(Fraccion** m, int n) {
    if (n == 1) return m[0][0];
    Fraccion det = {0, 1};
    for (int p = 0; p < n; p++) {
        Fraccion** sub = crear_matriz(n - 1, n - 1);
        for (int i = 1; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                sub[i - 1][col++] = m[i][j];
            }
        }
        Fraccion cofactor = multiplicar(m[0][p], determinante(sub, n - 1));
        if (p % 2 != 0) cofactor.numerador *= -1;
        det = sumar(det, cofactor);
        liberar_matriz(sub, n - 1);
    }
    return det;
}

Fraccion** adjunta(Fraccion** m, int n) {
    Fraccion** res = crear_matriz(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Fraccion** sub = crear_matriz(n - 1, n - 1);
            int subi = 0;
            for (int mi = 0; mi < n; mi++) {
                if (mi == i) continue;
                int subj = 0;
                for (int mj = 0; mj < n; mj++) {
                    if (mj == j) continue;
                    sub[subi][subj++] = m[mi][mj];
                }
                subi++;
            }
            Fraccion minor = determinante(sub, n - 1);
            if ((i + j) % 2 != 0) minor.numerador *= -1;
            res[i][j] = minor;
            liberar_matriz(sub, n - 1);
        }
    }
    return res;
}

Fraccion** inversa(Fraccion** m, int n) {
    Fraccion det = determinante(m, n);
    if (det.numerador == 0) {
        color(12);
        printf("[ERROR] La matriz no tiene inversa.\n");
        color(15);
        return NULL;
    }
    Fraccion** adj = adjunta(m, n);
    Fraccion** inv = transpuesta(adj, n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = dividir(inv[i][j], det);
    liberar_matriz(adj, n);
    return inv;
}

Fraccion** multiplicar_matrices(Fraccion** a, int fa, int ca, Fraccion** b, int fb, int cb) {
    if (ca != fb) return NULL;
    Fraccion** res = crear_matriz(fa, cb);
    for (int i = 0; i < fa; i++)
        for (int j = 0; j < cb; j++) {
            res[i][j] = (Fraccion){0, 1};
            for (int k = 0; k < ca; k++)
                res[i][j] = sumar(res[i][j], multiplicar(a[i][k], b[k][j]));
        }
    return res;
}

Fraccion** sumar_o_restar(Fraccion** a, Fraccion** b, int f, int c, int suma) {
    Fraccion** res = crear_matriz(f, c);
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = suma ? sumar(a[i][j], b[i][j]) : restar(a[i][j], b[i][j]);
    return res;
}

void mostrar_operacion(Fraccion** A, Fraccion** B, Fraccion** R, int f, int c, char op) {
    printf("Matriz A:\n"); mostrar_matriz_color(A, f, c, 10);
    printf("\n%c\n\n", op);
    printf("Matriz B:\n"); mostrar_matriz_color(B, f, c, 12);
    printf("\n=\n\n");
    printf("Resultado:\n"); mostrar_matriz_color(R, f, c, 11);
}

int leer_entero(const char* mensaje) {
    int valor;
    char entrada[100];
    while (1) {
        printf("%s", mensaje);
        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &valor) == 1 && valor > 0) return valor;
        color(12);
        printf("[ERROR] Solo numeros enteros positivos.\n");
        color(15);
    }
}

int main() {
    portada();
    int f = leer_entero("Filas de A: ");
    int c = leer_entero("Columnas de A: ");
    Fraccion** A = crear_matriz(f, c);

    int fB = leer_entero("Filas de B: ");
    int cB = leer_entero("Columnas de B: ");
    Fraccion** B = crear_matriz(fB, cB);

    llenar_matriz(A, f, c, 'A');
    llenar_matriz(B, fB, cB, 'B');

    int opc;
    do {
        limpiar_pantalla();
        printf("\n1. Mostrar\n2. Transpuesta\n3. Suma\n4. Resta\n5. Multiplicacion\n6. Determinante\n7. Inversa\n0. Salir\nOpcion: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1:
                printf("\nMatriz A:\n"); mostrar_matriz_color(A, f, c, 10);
                printf("\nMatriz B:\n"); mostrar_matriz_color(B, fB, cB, 12);
                break;
            case 2:
                printf("\nTranspuesta A:\n"); mostrar_matriz_color(transpuesta(A, f, c), c, f, 10);
                printf("\nTranspuesta B:\n"); mostrar_matriz_color(transpuesta(B, fB, cB), cB, fB, 12);
                break;
            case 3:
                if (f == fB && c == cB) {
                    Fraccion** R = sumar_o_restar(A, B, f, c, 1);
                    mostrar_operacion(A, B, R, f, c, '+');
                    liberar_matriz(R, f);
                }
                break;
            case 4:
                if (f == fB && c == cB) {
                    Fraccion** R = sumar_o_restar(A, B, f, c, 0);
                    mostrar_operacion(A, B, R, f, c, '-');
                    liberar_matriz(R, f);
                }
                break;
            case 5:
                if (c == fB) {
                    Fraccion** R = multiplicar_matrices(A, f, c, B, fB, cB);
                    printf("\nMultiplicacion A * B:\n");
                    mostrar_matriz_color(R, f, cB, 11);
                    liberar_matriz(R, f);
                }
                break;
            case 6:
                if (f == c) {
                    printf("Determinante A: "); imprimir_fraccion(determinante(A, f), 10); printf("\n");
                }
                if (fB == cB) {
                    printf("Determinante B: "); imprimir_fraccion(determinante(B, fB), 12); printf("\n");
                }
                break;
            case 7:
                if (f == c) {
                    printf("Inversa A:\n"); mostrar_matriz_color(inversa(A, f), f, f, 10);
                }
                if (fB == cB) {
                    printf("Inversa B:\n"); mostrar_matriz_color(inversa(B, fB), fB, fB, 12);
                }
                break;
        }
        if (opc != 0) pausar();
    } while (opc != 0);

    liberar_matriz(A, f);
    liberar_matriz(B, fB);
    return 0;
}
