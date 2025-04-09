#include <stdio.h>

double potencia(double base, int exponente) {
    double resultado = 1.0;
    

    int exponente_abs = exponente;
    if (exponente < 0) {
        exponente_abs = -exponente;
    }
    
    for (int i = 0; i < exponente_abs; i++) {
        resultado *= base;
    }
    
    if (exponente < 0) {
        return 1.0 / resultado;
    }
    return resultado;
}

int main() {
    double base;
    int exponente;
    
    printf("Ingrese la base: ");
    scanf("%lf", &base);
    
    printf("Ingrese el exponente (entero): ");
    scanf("%d", &exponente);
    
    double resultado = potencia(base, exponente);
    printf("Resultado: %.2lf^%d = %.4lf\n", base, exponente, resultado);
    
    return 0;
}