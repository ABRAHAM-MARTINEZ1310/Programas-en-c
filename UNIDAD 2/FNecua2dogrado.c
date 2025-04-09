#include <stdio.h>
#include <math.h>  // Para sqrt (raíz cuadrada)

void resolverEcuacionCuadratica(float a, float b, float c) {
    float discriminante, x1, x2;

    discriminante = b * b - 4 * a * c;

    if (discriminante > 0) {
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        x2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Raíces reales:\n  x1 = %.2f\n  x2 = %.2f\n", x1, x2);
    } 
    else if (discriminante == 0) {
        x1 = -b / (2 * a);
        printf("Raíz real única:\n  x = %.2f\n", x1);
    } 
    else {
        printf("¡Las raíces son complejas! Ingresa otros coeficientes.\n");
    }
}

int main() {
    float a, b, c;

    printf("Resolución de ecuación cuadrática (ax² + bx + c = 0)\n");

    do {
        printf("\nIngrese el coeficiente a (diferente de cero): ");
        scanf("%f", &a);
        while (a == 0) {  // Evita división por cero
            printf("¡El coeficiente 'a' no puede ser cero! Ingrese otro valor: ");
            scanf("%f", &a);
        }

        printf("Ingrese el coeficiente b: ");
        scanf("%f", &b);
        printf("Ingrese el coeficiente c: ");
        scanf("%f", &c);

        resolverEcuacionCuadratica(a, b, c);

    } while (b * b - 4 * a * c < 0);  // Repite si el discriminante es negativo

    return 0;
}