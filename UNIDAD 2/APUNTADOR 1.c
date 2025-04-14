#include <stdio.h>
int main(){
    int num1,num2;
    int *ptr1,*ptr2;

    ptr1= &num1;
    ptr2= &num2;
    printf("P1= %p\n",ptr1);
    printf("P2= %p\n",ptr2);
    num1=10;
    num2=20;
    ptr1 =ptr2;
    ptr2=NULL;
    printf("P1= %p\n",ptr1);
    printf("P2= %p\n",ptr2);
    return 0;

}
//
#include <stdio.h>

void mostrarMarco(int ancho, int alto) {
    // Marco superior
    for(int i = 0; i < ancho; i++) printf("*");
    printf("\n");
    
    // Lados y contenido
    for(int j = 1; j < alto-1; j++) {
        printf("*");
        if(j == 2) {
            // Primera línea del menú
            printf("  1. Suma");
            for(int i = 0; i < ancho-12; i++) printf(" ");
            printf("*\n");
            continue;
        }
        if(j == 3) {
            // Segunda línea del menú
            printf("  2. Resta");
            for(int i = 0; i < ancho-12; i++) printf(" ");
            printf("*\n");
            continue;
        }
        if(j == 4) {
            // Tercera línea del menú
            printf("  3. Multiplicacion");
            for(int i = 0; i < ancho-20; i++) printf(" ");
            printf("*\n");
            continue;
        }
        if(j == 5) {
            // Cuarta línea del menú
            printf("  4. Division");
            for(int i = 0; i < ancho-14; i++) printf(" ");
            printf("*\n");
            continue;
        }
        if(j == 6) {
            // Quinta línea del menú
            printf("  5. Salir");
            for(int i = 0; i < ancho-11; i++) printf(" ");
            printf("*\n");
            continue;
        }
        // Líneas vacías
        for(int i = 1; i < ancho-1; i++) printf(" ");
        printf("*\n");
    }
    
    // Marco inferior
    for(int i = 0; i < ancho; i++) printf("*");
    printf("\n");
}

int main() {
    int opcion;
    
    mostrarMarco(40, 12); // 40 de ancho, 12 de alto
    
    printf("\n  Seleccione una opcion: ");
    scanf("%d", &opcion);
    
    // Aquí iría el switch con las operaciones
    // ...
    
    return 0;
}

//