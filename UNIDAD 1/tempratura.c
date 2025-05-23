#include <stdio.h>

/* Imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300 */

int main() 
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* Límite inferior de la tabla de temperaturas */
    upper = 300;  /* Límite superior */

    step = 20;    /* Tamaño del incremento */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f %6.1f\n", fahr, celsius);  // Corregido aquí
        fahr = fahr + step;
    }
}