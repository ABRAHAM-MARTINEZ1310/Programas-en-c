// Proyecto de Álgebra Lineal - Abraham Ismael Martínez Santiago
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Definición de estructura Fraccion
typedef struct {
    int numerador;
    int denominador;
} Fraccion;

// Funciones utilitarias
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

void mostrar_error_y_pausar(const char* mensaje) {
    color(12);
    printf("\n[ERROR] %s\n\n", mensaje);
    color(15);
    pausar();
}

void despedida() {
    limpiar_pantalla();
    color(11);
    gotoxy(20, 10); printf("Gracias profe Luis Angel por revisar mi proyecto.");
    gotoxy(25, 11); printf("Proyecto elaborado por Abraham.");
    color(15);
    printf("\n\nPresiona ENTER para salir...");
    while (getchar() != '\n');
}

void portada() {
    limpiar_pantalla();
    color(14);
    gotoxy(30, 2); printf("UNIVERSIDAD DE LA SALLE OAXACA");
    gotoxy(24, 4); printf("INGENIERIA EN SOFTWARE Y SISTEMAS COMPUTACIONALES");
    gotoxy(32, 5); printf("ALGEBRA LINEAL - SOFTWARE B");
    gotoxy(30, 6); printf("PROFESOR: LUIS ANGEL RAMIREZ LOPEZ");
    gotoxy(30, 7); printf("ALUMNO: ABRAHAM ISMAEL MARTINEZ SANTIAGO");
    gotoxy(30, 9); printf("Presione doble ENTER para continuar...");
    color(15);
    while (getchar() != '\n');
    limpiar_pantalla();
}
int es_entero_positivo(const char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') return 0;
        i++;
    }
    return i > 0;
}

int leer_entero_color(const char* mensaje, int color_code) {
    char entrada[100];
    int valor;
    while (1) {
        color(color_code);
        printf("%s", mensaje);
        if (fgets(entrada, sizeof(entrada), stdin)) {
            int i = 0;
            while (entrada[i] != '\n' && entrada[i] != '\0') i++;
            entrada[i] = '\0';
            if (es_entero_positivo(entrada)) {
                valor = atoi(entrada);
                if (valor > 0) {
                    color(15);
                    return valor;
                }
            }
        }
        color(12);
        printf("[ERROR] Solo se permiten numeros enteros positivos.\n");
    }
}


int leer_entero(const char* mensaje) {
    return leer_entero_color(mensaje, 15);
}

Fraccion simplificar(Fraccion f) {
    int a = abs(f.numerador), b = abs(f.denominador);
    int r;
    while (b) { r = a % b; a = b; b = r; }
    f.numerador /= a;
    f.denominador /= a;
    if (f.denominador < 0) {
        f.numerador *= -1;
        f.denominador *= -1;
    }
    return f;
}

Fraccion leer_fraccion() {
    Fraccion f;
    char slash;
    int ch;
    color(10);
    while (1) {
        printf("Ingrese fraccion (a/b): ");
        if (scanf("%d %c %d", &f.numerador, &slash, &f.denominador) == 3 && slash == '/' && f.denominador != 0) {
            while ((ch = getchar()) != '\n' && ch != EOF);
            return simplificar(f);
        }
        color(12);
        printf("[ERROR] Entrada invalida. Formato correcto: a/b con b distinto de cero.\n");
        color(10);
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

Fraccion traza(Fraccion** m, int n) {
    Fraccion suma = {0, 1};
    for (int i = 0; i < n; i++) {
        suma = sumar(suma, m[i][i]);
    }
    return suma;
}

int es_nula(Fraccion f) {
    return f.numerador == 0;
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

void llenar_matriz(Fraccion** m, int filas, int columnas, char nombre, int color_code) {
    color(color_code);
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
    Fraccion** adj = crear_matriz(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Fraccion** menor = crear_matriz(n-1, n-1);
            for (int x = 0, mi = 0; x < n; x++) {
                if (x == i) continue;
                for (int y = 0, mj = 0; y < n; y++) {
                    if (y == j) continue;
                    menor[mi][mj++] = m[x][y];
                }
                mi++;
            }
            Fraccion det = determinante(menor, n-1);
            if ((i+j) % 2 != 0) det.numerador *= -1;
            adj[j][i] = det;
            liberar_matriz(menor, n-1);
        }
    }
    return adj;
}
Fraccion** inversa(Fraccion** m, int n) {
    Fraccion det = determinante(m, n);
    if (det.numerador == 0) return NULL;
    
    Fraccion** adj = adjunta(m, n);
    Fraccion** inv = crear_matriz(n, n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = dividir(adj[i][j], det);

    liberar_matriz(adj, n);
    return inv;
}

Fraccion** sumar_o_restar(Fraccion** a, Fraccion** b, int filas, int columnas, int es_suma) {
    Fraccion** res = crear_matriz(filas, columnas);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            res[i][j] = es_suma ? sumar(a[i][j], b[i][j]) : restar(a[i][j], b[i][j]);
    return res;
}

Fraccion** multiplicar_matrices(Fraccion** a, int filasA, int columnasA, Fraccion** b, int filasB, int columnasB) {
    Fraccion** res = crear_matriz(filasA, columnasB);
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            Fraccion suma = {0, 1};
            for (int k = 0; k < columnasA; k++) {
                suma = sumar(suma, multiplicar(a[i][k], b[k][j]));
            }
            res[i][j] = suma;
        }
    }
    return res;
}

int calcular_rango(Fraccion** m, int filas, int columnas) {
    int rango = 0;
    int* fila_usada = (int*)calloc(filas, sizeof(int));
    for (int col = 0; col < columnas; col++) {
        int fila;
        for (fila = 0; fila < filas; fila++) {
            if (!fila_usada[fila] && !es_nula(m[fila][col])) break;
        }
        if (fila < filas) {
            fila_usada[fila] = 1;
            rango++;
        }
    }
    free(fila_usada);
    return rango;
}
void mostrar_operacion(Fraccion** a, Fraccion** b, Fraccion** r, int filas, int columnas, char operador) {
    printf("\nOperacion:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            imprimir_fraccion(a[i][j], 10);
            printf("\t");
        }
        printf(i == filas / 2 ? " %c  " : "    ", operador);
        for (int j = 0; j < columnas; j++) {
            imprimir_fraccion(b[i][j], 12);
            printf("\t");
        }
        printf(i == filas / 2 ? " =  " : "    ");
        for (int j = 0; j < columnas; j++) {
            imprimir_fraccion(r[i][j], 11);
            printf("\t");
        }
        printf("\n");
    }
}

int menu_principal() {
    limpiar_pantalla();
    color(14);
    gotoxy(30, 2); printf("MENU PRINCIPAL");
    color(15);
    gotoxy(30, 4); printf("1. Mostrar matrices");
    gotoxy(30, 5); printf("2. Transpuestas");
    gotoxy(30, 6); printf("3. Sumar matrices");
    gotoxy(30, 7); printf("4. Restar matrices");
    gotoxy(30, 8); printf("5. Multiplicar matrices");
    gotoxy(30, 9); printf("6. Determinantes");
    gotoxy(30, 10); printf("7. Inversas");
    gotoxy(30, 11); printf("8. Trazas");
    gotoxy(30, 12); printf("9. Sistema AX = B");
    gotoxy(30, 13); printf("10. Rangos");
    gotoxy(30, 14); printf("0. Salir");
    gotoxy(30, 16); printf("Seleccione una opcion: ");
    return leer_entero("");
}

int main() {
    portada();
    color(10);
    printf("Dimensiones de la matriz A:\n");
    int f = leer_entero("Filas: ");
    int c = leer_entero("Columnas: ");
    Fraccion** A = crear_matriz(f, c);
    llenar_matriz(A, f, c, 'A', 10);

    color(12);
    printf("\nDimensiones de la matriz B:\n");
    int fB = leer_entero("Filas: ");
    int cB = leer_entero("Columnas: ");
    Fraccion** B = crear_matriz(fB, cB);
    llenar_matriz(B, fB, cB, 'B', 12);

    int opc;
    do {
        opc = menu_principal();
        limpiar_pantalla();
        switch (opc) {
            case 1:
                printf("Matriz A:\n"); mostrar_matriz_color(A, f, c, 10);
                printf("\nMatriz B:\n"); mostrar_matriz_color(B, fB, cB, 12);
                break;
            case 2:
                printf("Matriz A:\n"); mostrar_matriz_color(A, f, c, 10);
                printf("Transpuesta A:\n"); {
                    Fraccion** At = transpuesta(A, f, c);
                    mostrar_matriz_color(At, c, f, 11);
                    liberar_matriz(At, c);
                }
                printf("\nMatriz B:\n"); mostrar_matriz_color(B, fB, cB, 12);
                printf("Transpuesta B:\n"); {
                    Fraccion** Bt = transpuesta(B, fB, cB);
                    mostrar_matriz_color(Bt, cB, fB, 11);
                    liberar_matriz(Bt, cB);
                }
                break;
            case 3:
                if (f == fB && c == cB) {
                    Fraccion** R = sumar_o_restar(A, B, f, c, 1);
                    mostrar_operacion(A, B, R, f, c, '+');
                    liberar_matriz(R, f);
                } else mostrar_error_y_pausar("Las matrices deben tener las mismas dimensiones.");
                break;
            case 4:
                if (f == fB && c == cB) {
                    Fraccion** R = sumar_o_restar(A, B, f, c, 0);
                    mostrar_operacion(A, B, R, f, c, '-');
                    liberar_matriz(R, f);
                } else mostrar_error_y_pausar("Las matrices deben tener las mismas dimensiones.");
                break;
            case 5:
                if (c == fB) {
                    Fraccion** R = multiplicar_matrices(A, f, c, B, fB, cB);
                    printf("Resultado A * B:\n"); mostrar_matriz_color(R, f, cB, 11);
                    liberar_matriz(R, f);
                } else mostrar_error_y_pausar("Columnas de A deben coincidir con filas de B.");
                break;
            case 6:
                if (f == c) {
                    printf("Determinante A: "); imprimir_fraccion(determinante(A, f), 10); printf("\n");
                } else mostrar_error_y_pausar("La matriz A no es cuadrada.");
                if (fB == cB) {
                    printf("Determinante B: "); imprimir_fraccion(determinante(B, fB), 12); printf("\n");
                } else mostrar_error_y_pausar("La matriz B no es cuadrada.");
                break;
            case 7:
                if (f == c) {
                    printf("Matriz A:\n"); mostrar_matriz_color(A, f, f, 10);
                    Fraccion** invA = inversa(A, f);
                    if (invA) {
                        printf("Inversa A:\n"); mostrar_matriz_color(invA, f, f, 11);
                        liberar_matriz(invA, f);
                    } else mostrar_error_y_pausar("La matriz A no tiene inversa.");
                } else mostrar_error_y_pausar("La matriz A no es cuadrada.");
                if (fB == cB) {
                    printf("Matriz B:\n"); mostrar_matriz_color(B, fB, fB, 12);
                    Fraccion** invB = inversa(B, fB);
                    if (invB) {
                        printf("Inversa B:\n"); mostrar_matriz_color(invB, fB, fB, 11);
                        liberar_matriz(invB, fB);
                    } else mostrar_error_y_pausar("La matriz B no tiene inversa.");
                } else mostrar_error_y_pausar("La matriz B no es cuadrada.");
                break;

   case 8:
    if (f == c) {
        printf("Matriz A:\n");
        mostrar_matriz_color(A, f, c, 10);
        printf("Traza A: ");
        imprimir_fraccion(traza(A, f), 10);
        printf("\n");
    } else {
        mostrar_error_y_pausar("La matriz A no es cuadrada.");
    }

    if (fB == cB) {
        printf("\nMatriz B:\n");
        mostrar_matriz_color(B, fB, cB, 12);
        printf("Traza B: ");
        imprimir_fraccion(traza(B, fB), 12);
        printf("\n");
    } else {
        mostrar_error_y_pausar("La matriz B no es cuadrada.");
    }
    break;
case 9:
    if (f == c && fB == f && cB == 1) {
        printf("Matriz A:\n");
        mostrar_matriz_color(A, f, c, 10);
        printf("Matriz B:\n");
        mostrar_matriz_color(B, fB, cB, 12);

        Fraccion** inv = inversa(A, f);
        if (inv) {
            Fraccion** res = multiplicar_matrices(inv, f, c, B, fB, cB);
            printf("Solucion X al sistema AX = B:\n");
            mostrar_matriz_color(res, f, cB, 11);
            liberar_matriz(res, f);
            liberar_matriz(inv, f);
        } else {
            mostrar_error_y_pausar("La matriz A no tiene inversa, no se puede resolver el sistema.");
        }
    } else {
        mostrar_error_y_pausar("A debe ser cuadrada y B debe ser una matriz columna con la misma cantidad de filas que A.");
    }
    break;

            case 10:
                printf("Rango de A: %d\n", calcular_rango(A, f, c));
                printf("Rango de B: %d\n", calcular_rango(B, fB, cB));
                break;
            case 0:
                despedida();
                break;
            default:
                mostrar_error_y_pausar("Opcion invalida.");
        }
        if (opc != 0) pausar();
    } while (opc != 0);

    liberar_matriz(A, f);
    liberar_matriz(B, fB);
    return 0;
}
