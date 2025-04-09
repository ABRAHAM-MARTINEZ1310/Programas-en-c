#include <stdio.h>
#define PI 3.1416

struct Area {
    float valor;
};

struct Volumen {
    float valor;
};

union Datos {
    struct Area area;
    struct Volumen volumen;
};

struct Resultado {
    int tipo; 
    union Datos datos;
};


int areaCuadrado(int l) {
    return l * l;
}

int areaRectangulo(int b, int h) {
    return b * h;
}

int areaTriangulo(int b, int h) {
    return (b * h) / 2;
}

float areaCirculo(float r) {
    return PI * r * r;
}

float areaRombo(int d1, int d2) {
    return (d1 * d2) / 2.0;
}

float volumenCubo(float l) {
    return l * l * l;
}

float volumenPrisma(float a, float b, float c) {
    return a * b * c;
}

float volumenEsfera(float r) {
    return (4.0/3.0) * PI * r * r * r; 
}

float volumenCilindro(float r, float h) {
    return PI * r * r * h;
}

float volumenCono(float r, float h) {
    return (PI * r * r * h) / 3.0;  
}

int main() {
    int opcion;
    struct Resultado resultado;
    
    printf("1. Area de cuadrado\n");
    printf("2. Area de rectangulo\n");
    printf("3. Area de triangulo\n");
    printf("4. Area de circulo\n");
    printf("5. Area de rombo\n");
    printf("6. Volumen de cubo\n");
    printf("7. Volumen de prisma\n");
    printf("8. Volumen de esfera\n");
    printf("9. Volumen de cilindro\n");
    printf("10. Volumen de cono\n");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: {
            int l;
            printf("Ingrese el lado del cuadrado: ");
            scanf("%d", &l);
            resultado.tipo = 0;
            resultado.datos.area.valor = areaCuadrado(l);
            break;
        }
        case 2: {
            int b, h;
            printf("Ingrese base y altura del rectangulo: ");
            scanf("%d %d", &b, &h);
            resultado.tipo = 0;
            resultado.datos.area.valor = areaRectangulo(b, h);
            break;
        }
        case 3: {
            int b, h;
            printf("Ingrese base y altura del triangulo: ");
            scanf("%d %d", &b, &h);
            resultado.tipo = 0;
            resultado.datos.area.valor = areaTriangulo(b, h);
            break;
        }
        case 4: {
            float r;
            printf("Ingrese radio del circulo: ");
            scanf("%f", &r);
            resultado.tipo = 0;
            resultado.datos.area.valor = areaCirculo(r);
            break;
        }
        case 5: {
            int d1, d2;
            printf("Ingrese diagonales del rombo: ");
            scanf("%d %d", &d1, &d2);
            resultado.tipo = 0;
            resultado.datos.area.valor = areaRombo(d1, d2);
            break;
        }
        case 6: {
            float l;
            printf("Ingrese lado del cubo: ");
            scanf("%f", &l);
            resultado.tipo = 1;
            resultado.datos.volumen.valor = volumenCubo(l);
            break;
        }
        case 7: {
            float a, b, c;
            printf("Ingrese ancho, largo y altura del prisma: ");
            scanf("%f %f %f", &a, &b, &c);
            resultado.tipo = 1;
            resultado.datos.volumen.valor = volumenPrisma(a, b, c);
            break;
        }
        case 8: {
            float r;
            printf("Ingrese radio de la esfera: ");
            scanf("%f", &r);
            resultado.tipo = 1;
            resultado.datos.volumen.valor = volumenEsfera(r);
            break;
        }
        case 9: {
            float r, h;
            printf("Ingrese radio y altura del cilindro: ");
            scanf("%f %f", &r, &h);
            resultado.tipo = 1;
            resultado.datos.volumen.valor = volumenCilindro(r, h);
            break;
        }
        case 10: {
            float r, h;
            printf("Ingrese radio y altura del cono: ");
            scanf("%f %f", &r, &h);
            resultado.tipo = 1;
            resultado.datos.volumen.valor = volumenCono(r, h);
            break;
        }
        default:
            printf("Opcion no valida!\n");
            return 1;
    }

    if(resultado.tipo == 0) {
        printf("\nEl area calculada es: ");
        if(opcion <= 3) 
            printf("%d\n", (int)resultado.datos.area.valor);
        else
            printf("%.2f\n", resultado.datos.area.valor);
    } else {
        printf("\nEl volumen calculado es: %.2f\n", resultado.datos.volumen.valor);
    }
    return 0;
}