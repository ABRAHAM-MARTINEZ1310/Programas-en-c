#include <stdio.h>
#include <stdlib.h>

// Función para dibujar el marco de asteriscos
void dibujarMarco(int ancho, int alto) {
    int i, j;

    // Dibujar marco superior
    for(i = 0; i < ancho; i++) {
        printf("*");
    }
    printf("\n");
    
    // Dibujar lados
    for(j = 1; j < alto-1; j++) {
        printf("*");
        for(i = 1; i < ancho-1; i++) {
            printf(" ");
        }
        printf("*\n");
    }
    
    // Dibujar marco inferior
    for(i = 0; i < ancho; i++) {
        printf("*");
    }
    printf("\n");
}

// Función para centrar texto
void centrarTexto(const char *texto, int ancho) {
    int espacios = (ancho - strlen(texto)) / 2;
    if(espacios < 0) espacios = 0;
    
    printf("%*s%s\n", espacios, "", texto);
}


int main() {
    int opcion;
    float num1, num2, resultado;
    const int ANCHO = 50;
    const int ALTO = 20;
    
    do {
        dibujarMarco(ANCHO, ALTO);
        
        // Posicionar texto dentro del marco (simulado)
        printf("\n\n");
        centrarTexto("CALCULADORA BASICA", ANCHO);
        printf("\n");
        centrarTexto("1. Suma", ANCHO);
        centrarTexto("2. Resta", ANCHO);
        centrarTexto("3. Multiplicacion", ANCHO);
        centrarTexto("4. Division", ANCHO);
        centrarTexto("5. Salir", ANCHO);
        printf("\n");
        centrarTexto("Seleccione una opcion: ", ANCHO);
        
        // Mover cursor a posición para entrada
        printf("\033[%d;%dH", ALTO/2 + 5, (ANCHO/2) - 5); // Secuencia ANSI para posicionar cursor
        scanf("%d", &opcion);
        
        if(opcion >= 1 && opcion <= 4) {
            dibujarMarco(ANCHO, ALTO);
            printf("\n\n");
            centrarTexto("Ingrese primer numero: ", ANCHO);
            scanf("%f", &num1);
            centrarTexto("Ingrese segundo numero: ", ANCHO);
            scanf("%f", &num2);
            
            switch(opcion) {
                case 1:
                    resultado = num1 + num2;
                    centrarTexto("Resultado de la suma:", ANCHO);
                    break;
                case 2:
                    resultado = num1 - num2;
                    centrarTexto("Resultado de la resta:", ANCHO);
                    break;
                case 3:
                    resultado = num1 * num2;
                    centrarTexto("Resultado de la multiplicacion:", ANCHO);
                    break;
                case 4:
                    if(num2 != 0) {
                        resultado = num1 / num2;
                        centrarTexto("Resultado de la division:", ANCHO);
                    } else {
                        centrarTexto("Error: division por cero", ANCHO);
                        resultado = 0;
                    }
                    break;
            }
            
            if(!(opcion == 4 && num2 == 0)) {
                printf("\n");
                centrarTexto("-----------------------", ANCHO);
                printf("\n");
                centrarTexto("El resultado es:", ANCHO);
                printf("\n");
                centrarTexto("", ANCHO-15);
                printf("%.2f\n", resultado);
            }
            

        }
        
    } while(opcion != 5);
    
    dibujarMarco(ANCHO, ALTO);
    printf("\n\n");
    centrarTexto("Gracias por usar la calculadora!", ANCHO);
    printf("\n\n");
    
    return 0;
}