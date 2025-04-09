#include<stdio.h>
#include<string.h>
#include<math.h>

struct Ecuacion {
    int a;
    int b;
    int c;
    int disc;
    float r1;
    float r2;
    char mensaje[30];
};

int main() {
    int total;
    printf("Cuantas ecuaciones cuadraticas vas a meter?: ");
    scanf("%d", &total);

    struct Ecuacion ecuaciones[total];
    
    for(int i = 0; i < total; i++) {
        printf("Ecuacion %d: \n", i + 1);
        printf("Dame A: ");
        scanf("%d", &ecuaciones[i].a);
        printf("Dame B: ");
        scanf("%d", &ecuaciones[i].b);
        printf("Dame C: ");
        scanf("%d", &ecuaciones[i].c);
        ecuaciones[i].r1 = 0.00;
        ecuaciones[i].r2 = 0.00;
    }
    
    for(int i = 0; i < total; i++) {
        int d = (ecuaciones[i].b * ecuaciones[i].b) - (4 * ecuaciones[i].a * ecuaciones[i].c);
        ecuaciones[i].disc = d;
        
        if (d < 0) {
            strcpy(ecuaciones[i].mensaje, "No hay solucion real");
        } else {
            float x1 = (-ecuaciones[i].b + sqrt(d)) / (2.0 * ecuaciones[i].a);
            float x2 = (-ecuaciones[i].b - sqrt(d)) / (2.0 * ecuaciones[i].a);
            strcpy(ecuaciones[i].mensaje, "Tiene solucion");
            ecuaciones[i].r1 = x1;
            ecuaciones[i].r2 = x2;
        }
    }

    printf("A | B | C | X1 | X2 | Mensaje\n");
    for (int i = 0; i < total; i++) {
        printf("%d | %d | %d | %.2f | %.2f | %s\n", ecuaciones[i].a, ecuaciones[i].b, ecuaciones[i].c, ecuaciones[i].r1, ecuaciones[i].r2, ecuaciones[i].mensaje);
    }
    
    return 0;
}
