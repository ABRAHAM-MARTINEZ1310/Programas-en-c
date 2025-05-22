#include <stdio.h>

// Función recursiva para resolver el problema de las Torres de Hanoi
void hanoi(char torre1, char torre2, char torre3, int disco) {
    if (disco == 1) {
        printf("Mover disco %d desde torre %c a torre %c\n", disco, torre1, torre3);
    } else {
        hanoi(torre1, torre3, torre2, disco - 1);
        printf("Mover disco %d desde torre %c a torre %c\n", disco, torre1, torre3);
        hanoi(torre2, torre1, torre3, disco - 1);
    }
}

int main() {
    char a, b, c;
    int discos;

    printf("Nombre de la torre 1: ");
    scanf(" %c", &a);
    printf("Nombre de la torre 2: ");
    scanf(" %c", &b);
    printf("Nombre de la torre 3: ");
    scanf(" %c", &c);
    printf("Cantidad de discos: ");
    scanf("%d", &discos);

    hanoi(a, b, c, discos);

    return 0;
}
