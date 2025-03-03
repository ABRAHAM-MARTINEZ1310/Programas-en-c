
#include <stdio.h>
int main() { 

    int contador = 0;
    int limite = 10;
     
    printf("%4s\n", "Ejemplo de impresion");
    while (contador <= limite) {

            printf("%4d", contador);
            contador++;
    }
    printf("\n%s\n", "ejemplo de impresiom");

int limitey = 10;
    while (limitey >= 0) {
        int limitex = 10;
        while (limitex >= 0) {
            printf("%4d", limitex);
            limitex--;

        }
        printf("\n");
        limitey--;
    }

    printf("\n%s\n","ejemplo de impresion");

    int limitesy = 0;
    while (limitey <= 10) {
        int limitex = 0;
        while (limitex <= 10) {
            printf("%4d", limitex);
            limitex++;

        }
        printf("\n");
        limitey++;
    }

    printf("\n%s\n","ejemplo de impresion");




    return 0;
}