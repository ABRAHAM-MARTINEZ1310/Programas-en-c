#include <stdio.h>
#include <stdlib.h>

void imprimirMarco(int ancho) {
    for(int i = 0; i < ancho + 4; i++) {
        printf("*");
    }
    printf("\n");
}

void imprimirGrafica(int valores[], int num_valores) {
    // Encontrar el valor máximo para escalar la gráfica
    int max = valores[0];
    for(int i = 1; i < num_valores; i++) {
        if(valores[i] > max) {
            max = valores[i];
        }
    }
    
    // Determinar el ancho máximo necesario
    int ancho_max = 0;
    for(int i = 0; i < num_valores; i++) {
        int longitud = snprintf(NULL, 0, "%d", valores[i]);
        if(longitud > ancho_max) {
            ancho_max = longitud;
        }
    }
    ancho_max += 10; // Espacio para la barra
    
    // Imprimir marco superior
    imprimirMarco(ancho_max);
    
    // Imprimir gráfica de barras
    for(int i = 0; i < num_valores; i++) {
        printf("* ");
        int longitud_barra = (valores[i] * 10) / max;
        
        // Imprimir el valor
        printf("%d |", valores[i]);
        
        // Imprimir la barra
        for(int j = 0; j < longitud_barra; j++) {
            printf("#");
        }
        
        // Rellenar con espacios si es necesario
        int espacios = ancho_max - (snprintf(NULL, 0, "%d", valores[i]) + 3 + longitud_barra);
        for(int j = 0; j < espacios; j++) {
            printf(" ");
        }
        
        printf(" *\n");
    }
    
    // Imprimir marco inferior
    imprimirMarco(ancho_max);
}

int main() {
    int num_valores;
    
    printf("Ingrese el número de valores para la gráfica: ");
    scanf("%d", &num_valores);
    
    if(num_valores <= 0) {
        printf("El número de valores debe ser mayor que 0.\n");
        return 1;
    }
    
    int *valores = (int *)malloc(num_valores * sizeof(int));
    
    printf("Ingrese los valores (separados por espacios):\n");
    for(int i = 0; i < num_valores; i++) {
        scanf("%d", &valores[i]);
        if(valores[i] < 0) {
            printf("Los valores no pueden ser negativos.\n");
            free(valores);
            return 1;
        }
    }
    
    printf("\nGráfica de barras:\n");
    imprimirGrafica(valores, num_valores);
    
    free(valores);
    return 0;
}