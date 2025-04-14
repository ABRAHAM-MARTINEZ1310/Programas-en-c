#include <stdio.h>

// Prototipo
int suma(int a, int b);

int main() {
    int resultado = suma(5, 3);
    printf("La suma es: %d\n", resultado);
    return 0;
}

// Definición
int suma(int a, int b) {
    return a + b;
}


//otro
#include <stdio.h>
#include <string.h>

// Prototipos
void gotoxy(int x, int y);
void mostrar_menu();
int sumar(int a, int b);
void dibujar_cuadro(int x1, int y1, int x2, int y2);

// Función principal
int main() {
    int opcion, a, b;
    
    do {
        system("cls"); // Limpiar pantalla
        dibujar_cuadro(5, 2, 40, 15);
        gotoxy(10, 4);
        printf("MENU PRINCIPAL");
        
        gotoxy(10, 6);
        printf("1. Sumar dos numeros");
        gotoxy(10, 7);
        printf("2. Dibujar cuadro");
        gotoxy(10, 8);
        printf("3. Salir");
        gotoxy(10, 10);
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                gotoxy(10, 12);
                printf("Ingrese primer numero: ");
                scanf("%d", &a);
                gotoxy(10, 13);
                printf("Ingrese segundo numero: ");
                scanf("%d", &b);
                gotoxy(10, 14);
                printf("Resultado: %d", sumar(a, b));
                getchar(); getchar(); // Pausa
                break;
            case 2:
                dibujar_cuadro(15, 8, 65, 20);
                gotoxy(17, 10);
                printf("Este es un cuadro dibujado con funciones");
                getchar(); getchar();
                break;
        }
    } while(opcion != 3);
    
    return 0;
}

// Implementación de funciones
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}

int sumar(int a, int b) {
    return a + b;
}

void dibujar_cuadro(int x1, int y1, int x2, int y2) {
    int i;
    
    // Esquinas
    gotoxy(x1, y1); printf("╔");
    gotoxy(x2, y1); printf("╗");
    gotoxy(x1, y2); printf("╚");
    gotoxy(x2, y2); printf("╝");
    
    // Bordes horizontales
    for(i = x1+1; i < x2; i++) {
        gotoxy(i, y1); printf("═");
        gotoxy(i, y2); printf("═");
    }
    
    // Bordes verticales
    for(i = y1+1; i < y2; i++) {
        gotoxy(x1, i); printf("║");
        gotoxy(x2, i); printf("║");
    }
}

//triangulo
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setColor(int color) {
    printf("\033[1;%dm", color);
}

void resetColor() {
    printf("\033[0m");
}

void triangulo_colorido(int base, int x, int y) {
    int i, j;
    int color = 31; // Rojo
    
    for(i = 0; i < base; i++) {
        setColor(color);
        gotoxy(x - i, y + i);
        
        for(j = 0; j < 2*i + 1; j++) {
            printf("*");
        }
        
        color++;
        if(color > 37) color = 31; // Reiniciar secuencia de colores
    }
    resetColor();
}

int main() {
    system("cls"); // Limpiar pantalla
    
    // Dibujar triángulo en posición (40, 5) con base 10
    triangulo_colorido(10, 40, 5);
    
    gotoxy(1, 20); // Mover cursor al final
    return 0;
}

//cuadrado con bordes de colores
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void dibujar_cuadrado_colorido(int x, int y, int ancho, int alto) {
    int i;
    
    // Colores ANSI
    int color_borde = 34; // Azul
    int color_relleno = 46; // Cyan
    
    // Dibujar bordes
    setColor(color_borde);
    for(i = 0; i < ancho; i++) {
        gotoxy(x + i, y); printf("═"); // Borde superior
        gotoxy(x + i, y + alto - 1); printf("═"); // Borde inferior
    }
    
    for(i = 0; i < alto; i++) {
        gotoxy(x, y + i); printf("║"); // Borde izquierdo
        gotoxy(x + ancho - 1, y + i); printf("║"); // Borde derecho
    }
    
    // Esquinas
    gotoxy(x, y); printf("╔");
    gotoxy(x + ancho - 1, y); printf("╗");
    gotoxy(x, y + alto - 1); printf("╚");
    gotoxy(x + ancho - 1, y + alto - 1); printf("╝");
    
    // Relleno
    setColor(color_relleno);
    for(i = 1; i < alto - 1; i++) {
        gotoxy(x + 1, y + i);
        for(int j = 1; j < ancho - 1; j++) {
            printf(" ");
        }
    }
    
    resetColor();
}

int main() {
    system("cls");
    
    // Dibujar cuadrado en (10,5) de 20x10
    dibujar_cuadrado_colorido(10, 5, 20, 10);
    
    gotoxy(1, 30); // Mover cursor al final
    return 0;
}

//rombo con degradado de colores 
#include <stdio.h>
#include <stdlib.h>

void rombo_degradado(int size, int x, int y) {
    int i, j;
    int color = 36; // Cyan
    
    // Parte superior del rombo
    for(i = 0; i < size; i++) {
        setColor(color);
        gotoxy(x - i, y + i);
        
        for(j = 0; j < 2*i + 1; j++) {
            printf("*");
        }
        
        color = (color + 1) > 37 ? 31 : color + 1;
    }
    
    // Parte inferior del rombo
    for(i = size - 2; i >= 0; i--) {
        setColor(color);
        gotoxy(x - i, y + (2*size - 2 - i));
        
        for(j = 0; j < 2*i + 1; j++) {
            printf("*");
        }
        
        color = (color + 1) > 37 ? 31 : color + 1;
    }
    
    resetColor();
}

int main() {
    system("cls");
    
    // Dibujar rombo de tamaño 8 en (40,5)
    rombo_degradado(8, 40, 5);
    
    gotoxy(1, 30);
    return 0;
}
//bandera
#include <stdio.h>
#include <stdlib.h>

void bandera_tricolor(int ancho, int alto, int x, int y) {
    int i, j;
    
    // Primera franja (rojo)
    for(i = 0; i < alto/3; i++) {
        gotoxy(x, y + i);
        setBackground(41); // Fondo rojo
        for(j = 0; j < ancho; j++) {
            printf(" ");
        }
    }
    
    // Segunda franja (blanco)
    for(i = alto/3; i < 2*alto/3; i++) {
        gotoxy(x, y + i);
        setBackground(47); // Fondo blanco
        for(j = 0; j < ancho; j++) {
            printf(" ");
        }
    }
    
    // Tercera franja (verde)
    for(i = 2*alto/3; i < alto; i++) {
        gotoxy(x, y + i);
        setBackground(42); // Fondo verde
        for(j = 0; j < ancho; j++) {
            printf(" ");
        }
    }
    
    resetColor();
}

void setBackground(int color) {
    printf("\033[%dm", color);
}

int main() {
    system("cls");
    
    // Dibujar bandera de 50x15 en (5,5)
    bandera_tricolor(50, 15, 5, 5);
    
    gotoxy(1, 30);
    return 0;
}
//circulo raro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void circulo_colorido(int radio, int x_centro, int y_centro) {
    int x, y;
    double distancia;
    int color = 31; // Rojo
    
    for(y = -radio; y <= radio; y++) {
        for(x = -radio; x <= radio; x++) {
            distancia = sqrt(x*x + y*y);
            
            if(distancia <= radio + 0.5) {
                setColor(color);
                gotoxy(x_centro + x, y_centro + y);
                printf("O");
                
                // Cambiar color gradualmente
                color++;
                if(color > 36) color = 31;
            }
        }
    }
    
    resetColor();
}

int main() {
    system("cls");
    
    // Dibujar círculo de radio 10 en (40,15)
    circulo_colorido(10, 40, 15);
    
    gotoxy(1, 30);
    return 0;
}
//menu gotoxy fn
#include <stdio.h>
#include <stdlib.h>


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void lineaHorizontal(int longitud, int x, int y) {
    gotoxy(x, y);
    for(int i = 0; i < longitud; i++) {
        printf("*");
    }
}


void lineaVertical(int altura, int x, int y) {
    for(int i = 0; i < altura; i++) {
        gotoxy(x, y + i);
        printf("*");
    }
}


void dibujarMarco(int ancho, int alto, int x, int y) {
    lineaHorizontal(ancho, x, y);
    lineaVertical(alto - 2, x, y + 1);
    lineaVertical(alto - 2, x + ancho - 1, y + 1);
    lineaHorizontal(ancho, x, y + alto - 1);
}


void mostrarMenu(int x, int y) {
    gotoxy(x, y++); printf("1. Suma");
    gotoxy(x, y++); printf("2. Resta");
    gotoxy(x, y++); printf("3. Multiplicacion");
    gotoxy(x, y++); printf("4. Division");
    gotoxy(x, y++); printf("5. Salir");
}


int main() {
    int opcion;
    float num1, num2, resultado;
    
    system("cls || clear"); 
    
    dibujarMarco(30, 10, 5, 3);
    
    mostrarMenu(7, 5);
    

    gotoxy(7, 9);
    printf("Seleccione opcion: ");
    scanf("%d", &opcion);
    printf("\033[2J");
    switch(opcion) {
        case 1:
           
            break;
        case 2:
         
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;

    }
    
    return 0;
}
//codigos de ccolores
Textos:
30 - Negro       31 - Rojo       32 - Verde      33 - Amarillo
34 - Azul        35 - Magenta     36 - Cyan       37 - Blanco

Fondos:
40 - Negro       41 - Rojo       42 - Verde      43 - Amarillo
44 - Azul        45 - Magenta     46 - Cyan       47 - Blanco

Atributos:
0 - Normal       1 - Negrita     4 - Subrayado   5 - Parpadeo
7 - Inverso      8 - Oculto

//rombo normal
#include <stdio.h>

int main() {
    int n = 5; // altura del rombo (impar)
    int i, j;

    // Parte superior
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

    // Parte inferior
    for (i = n - 2; i >= 0; i--) {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}

//circulo normal
#include <stdio.h>
#include <math.h>

int main() {
    int radius = 5;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (sqrt(i * i + j * j) < radius + 0.5 && sqrt(i * i + j * j) > radius - 0.5)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

//trapecio normal
#include <stdio.h>

int main() {
    int top = 5, bottom = 11, height = 5;
    for (int i = 0; i < height; i++) {
        int stars = top + 2 * i;
        int spaces = (bottom - stars) / 2;
        for (int j = 0; j < spaces; j++) printf(" ");
        for (int j = 0; j < stars; j++) printf("*");
        printf("\n");
    }
    return 0;
}

//hexa normal
#include <stdio.h>

int main() {
    int size = 4; // lado del hexágono
    int i, j;

    // Parte superior
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) printf(" ");
        for (j = 0; j < size + 2 * i; j++) printf("*");
        printf("\n");
    }

    // Parte inferior
    for (i = size - 2; i >= 0; i--) {
        for (j = 0; j < size - i; j++) printf(" ");
        for (j = 0; j < size + 2 * i; j++) printf("*");
        printf("\n");
    }

    return 0;
}

//penta normal
#include <stdio.h>

int main() {
    int height = 5;

    // Parte superior (triángulo)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i; j++) printf(" ");
        for (int j = 0; j < 2 * i + 1; j++) printf("*");
        printf("\n");
    }

    // Parte inferior (base del pentágono)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * height + 1; j++) printf("*");
        printf("\n");
    }

    return 0;
}
//tabla de colores

#include <stdio.h>
#include <windows.h>

void setcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    for (int i = 0; i < 16; i++) {
        setcolor(i);
        printf("Color %2d -> Este es un ejemplo\n", i);
    }

    setcolor(7); // Color normal
    return 0;
}

//matrices


#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    int filas = 5;
    int columnas = 5;
    int startX = 10;
    int startY = 5;

    // Dibujar matriz con margen
    for (int i = 0; i < filas + 2; i++) {
        for (int j = 0; j < columnas + 2; j++) {
            gotoxy(startX + j * 4, startY + i * 2);

            if (i == 0 || i == filas + 1 || j == 0 || j == columnas + 1)
                printf("*");  // Márgenes
            else
                printf("[%d]", (i - 1) * columnas + (j - 1));  // Contenido de la matriz
        }
    }

    gotoxy(0, startY + filas + 3); // Para no dejar el cursor dentro
    return 0;
}

//meun conn diferentes posciones
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    system("cls");

    gotoxy(10, 5); printf("1. Iniciar juego");
    gotoxy(10, 7); printf("2. Opciones");
    gotoxy(10, 9); printf("3. Créditos");
    gotoxy(10, 11); printf("4. Salir");

    gotoxy(10, 13);
    printf("Selecciona una opción: ");

    return 0;
}
//cuadro con relleno
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    int x = 5, y = 5, ancho = 20, alto = 10;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            gotoxy(x + j, y + i);
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                setcolor(12); // Rojo
                printf("*");
            } else {
                setcolor(10); // Verde
                printf(".");
            }
        }
    }

    setcolor(7); // Reset
    gotoxy(0, y + alto + 2);
    return 0;
}
//
#include <stdio.h>

void dibujarMarco(int ancho, int alto) {
    int i, j;
    
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            // Si es la primera o última fila, o primera o última columna
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                printf("* ");
            } else {
                printf("  "); // Dos espacios para mantener la proporción
            }
        }
        printf("\n");
    }
}

int main() {
    int ancho, alto;
    
    printf("Ingrese el ancho del marco: ");
    scanf("%d", &ancho);
    
    printf("Ingrese el alto del marco: ");
    scanf("%d", &alto);
    
    // Validar que las dimensiones sean positivas
    if (ancho <= 0 || alto <= 0) {
        printf("Las dimensiones deben ser mayores que cero.\n");
        return 1;
    }
    
    dibujarMarco(ancho, alto);
    
    return 0;
}
//#include <stdio.h>
#include <stdlib.h>

// Función para limpiar la pantalla (portable)
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para dibujar el marco de asteriscos
void dibujarMarco(int ancho, int alto) {
    int i, j;
    
    limpiarPantalla();
    
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

// Función para pausa (portable)
void pausa() {
    printf("\nPresione Enter para continuar...");
    while(getchar() != '\n'); // Limpiar buffer
    getchar(); // Esperar Enter
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
            
            pausa();
        }
        
    } while(opcion != 5);
    
    dibujarMarco(ANCHO, ALTO);
    printf("\n\n");
    centrarTexto("Gracias por usar la calculadora!", ANCHO);
    printf("\n\n");
    
    return 0;
}
