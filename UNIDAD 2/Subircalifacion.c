#include <stdio.h>
#include <stdlib.h>

// Códigos ANSI para colores de fondo (sin cambiar color del texto)
#define ROJO     "\x1b[41m"
#define VERDE    "\x1b[42m"
#define AMARILLO "\x1b[43m"
#define AZUL     "\x1b[44m"
#define MAGENTA  "\x1b[45m"
#define CIAN     "\x1b[46m"
#define BLANCO   "\x1b[47m"
#define RESET_COLOR    "\x1b[0m"

void dibujarMarcoSuperiorInferior(int ancho) {
    for (int i = 0; i < ancho + 2; i++) {
        printf("*");
    }
    printf("\n");
}

void dibujarGrafica(int barras[], int numBarras) {
    int maxAltura = 0;
    int anchoGrafica = numBarras * 3 - 1; // 2 caracteres por barra + espacios
    
    // Encontrar la altura máxima
    for (int i = 0; i < numBarras; i++) {
        if (barras[i] > maxAltura) {
            maxAltura = barras[i];
        }
    }
    
    // Dibujar marco superior
    dibujarMarcoSuperiorInferior(anchoGrafica);
    
    // Dibujar de arriba hacia abajo
    for (int nivel = maxAltura; nivel > 0; nivel--) {
        printf("*"); // Lado izquierdo del marco
        
        for (int barra = 0; barra < numBarras; barra++) {
            if (barras[barra] >= nivel) {
                // Aplicar color de fondo solo cuando hay barra
                switch(barra) {
                    case 0: printf(ROJO); break;
                    case 1: printf(VERDE); break;
                    case 2: printf(AMARILLO); break;
                    case 3: printf(AZUL); break;
                    case 4: printf(MAGENTA); break;
                    case 5: printf(CIAN); break;
                    case 6: printf(BLANCO); break;
                }
                printf("**"); // Asteriscos con fondo coloreado
                printf(RESET_COLOR); // Resetear color
            } else {
                printf("  "); // Espacios sin color
            }
            
            if (barra < numBarras - 1) {
                printf(" "); // Espacio entre barras
            }
        }
        
        printf("*\n"); // Lado derecho del marco
    }
    
    // Dibujar marco inferior
    dibujarMarcoSuperiorInferior(anchoGrafica);
}

int main() {
    int numBarras;
    int alturas[7];
    
    printf("Graficador de Barras con Fondo Coloreado\n");
    printf("Cuantas barras deseas (1-7)? ");
    scanf("%d", &numBarras);
    
    if (numBarras < 1 || numBarras > 7) {
        printf("Error: Solo se permiten entre 1 y 7 barras.\n");
        return 1;
    }
    
    for (int i = 0; i < numBarras; i++) {
        printf("Altura de la barra %d: ", i+1);
        scanf("%d", &alturas[i]);
        
        if (alturas[i] < 1) {
            printf("Error: La altura debe ser al menos 1.\n");
            return 1;
        }
    }
    
    printf("\nGrafica de Barras:\n");
    dibujarGrafica(alturas, numBarras);
    
    return 0;
}