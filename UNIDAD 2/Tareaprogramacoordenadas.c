#include<stdio.h>
#include<math.h>

struct Triang {
    int a1, b1;
    int a2, b2;
    int a3, b3;
};

struct Cuadra {
    int p1, q1;
    int p2, q2;
    int p3, q3;
    int p4, q4;
};

int main() {
    int opcion;
    printf("Seleccione una figura geometrica:\n");
    printf("1. Triangulo\n");
    printf("2. Cuadrado\n");
    scanf("%d", &opcion);
    
    switch (opcion) {
    case 1: {
        struct Triang t;
        printf("Ingrese las coordenadas del triangulo:\n");
        printf("a1: ");
        scanf("%d", &t.a1);
        printf("b1: ");
        scanf("%d", &t.b1);
        printf("a2: ");
        scanf("%d", &t.a2);
        printf("b2: ");
        scanf("%d", &t.b2);
        printf("a3: ");
        scanf("%d", &t.a3);
        printf("b3: ");
        scanf("%d", &t.b3);
        
        float l1 = sqrt(pow(t.a2 - t.a1, 2) + pow(t.b2 - t.b1, 2));
        float l2 = sqrt(pow(t.a3 - t.a2, 2) + pow(t.b3 - t.b2, 2));
        float l3 = sqrt(pow(t.a1 - t.a3, 2) + pow(t.b1 - t.b3, 2));
        float perim = l1 + l2 + l3;
        
        float semiP = perim / 2;
        float areaT = sqrt(semiP * (semiP - l1) * (semiP - l2) * (semiP - l3));
        
        printf("Perimetro del triangulo: %.2f\n", perim);
        printf("Area del triangulo: %.2f\n", areaT);
        break;
    }

    case 2: {
        struct Cuadra cuad;
        printf("Ingrese las coordenadas del cuadrado:\n");
        printf("p1: ");
        scanf("%d", &cuad.p1);
        printf("q1: ");
        scanf("%d", &cuad.q1);
        printf("p2: ");
        scanf("%d", &cuad.p2);
        printf("q2: ");
        scanf("%d", &cuad.q2);
        printf("p3: ");
        scanf("%d", &cuad.p3);
        printf("q3: ");
        scanf("%d", &cuad.q3);
        printf("p4: ");
        scanf("%d", &cuad.p4);
        printf("q4: ");
        scanf("%d", &cuad.q4);
        
        float ladoC = sqrt(pow(cuad.p2 - cuad.p1, 2) + pow(cuad.q2 - cuad.q1, 2));
        float periC = 4 * ladoC;
        float areaC = ladoC * ladoC;
        
        printf("Perimetro del cuadrado: %.2f\n", periC);
        printf("Area del cuadrado: %.2f\n", areaC);
        break;
    }

    default:
        printf("Opcion invalida\n");
        break;
    }

    return 0;
}