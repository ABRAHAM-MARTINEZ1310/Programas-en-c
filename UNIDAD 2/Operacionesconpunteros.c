#include <stdio.h>

int main() {
    int val1, val2, sum, rest, mult, div;
    int *val1aptr = &val1, *val2aptr = &val2; // Punteros a val1 y val2
    int *sumaptr = &sum, *restaptr = &rest;   // Punteros a resultados
    int *multaptr = &mult, *divaptr = &div;

    printf("Ingrese el primer valor: ");
    scanf("%d", &val1); // Leer val1 directamente (no con puntero)

    printf("Ingrese el segundo valor: ");
    scanf("%d", &val2); // Leer val2 directamente

    // Operaciones normales (sin punteros)
    sum = val1 + val2;
    rest = val1 - val2;
    mult = val1 * val2;
    div = val1 / val2;

    // Mostrar valores y direcciones de val1 y val2
    printf("\n--- Valores y direcciones originales ---\n");
    printf("Valor de 'val1': %d\n", val1);
    printf("Dirección de 'val1': %p\n", (void*)&val1);
    printf("Valor de 'val2': %d\n", val2);
    printf("Dirección de 'val2': %p\n", (void*)&val2);

    // Mostrar punteros a val1 y val2 (val1aptr y val2aptr)
    printf("\n--- Punteros a val1 y val2 ---\n");
    printf("Valor de 'val1aptr' (dirección de val1): %p\n", (void*)val1aptr);
    printf("Valor al que apunta 'val1aptr': %d\n", *val1aptr);
    printf("Dirección de 'val1aptr': %p\n", (void*)&val1aptr);
    printf("\nValor de 'val2aptr' (dirección de val2): %p\n", (void*)val2aptr);
    printf("Valor al que apunta 'val2aptr': %d\n", *val2aptr);
    printf("Dirección de 'val2aptr': %p\n", (void*)&val2aptr);

    // Mostrar resultados de operaciones
    printf("\n--- Resultados de operaciones ---\n");
    printf("Suma: %d\n", sum);
    printf("Resta: %d\n", rest);
    printf("Multiplicación: %d\n", mult);
    printf("División: %d\n", div);

    // Mostrar punteros a resultados (sumaptr, restaptr, etc.)
    printf("\n--- Punteros a resultados ---\n");
    printf("Valor de 'sumaptr' (dirección de 'sum'): %p\n", (void*)sumaptr);
    printf("Valor al que apunta 'sumaptr': %d\n", *sumaptr);
    printf("Dirección de 'sumaptr': %p\n", (void*)&sumaptr);
    printf("\nValor de 'divaptr' (dirección de 'div'): %p\n", (void*)divaptr);
    printf("Valor al que apunta 'divaptr': %d\n", *divaptr);
    printf("Dirección de 'divaptr': %p\n", (void*)&divaptr);

    return 0;
}