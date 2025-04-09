#include <stdio.h>

float pesos_a_dolares(float pesos, float tipo_cambio) {
    return pesos / tipo_cambio;
}

int main() {
    float pesos, dolares;
    float tipo_cambio = 20.0f; 

    printf("Ingrese la cantidad en pesos: ");
    scanf("%f", &pesos);

    dolares = pesos_a_dolares(pesos, tipo_cambio);
    printf("%.2f pesos = %.2f dólares (Tipo de cambio: %.2f)\n", pesos, dolares, tipo_cambio);

    return 0;
}