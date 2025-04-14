#include <stdio.h>
#include <string.h>
struct KeyValue{
    char clave [50];
    char valor[100];
};
struct Coordenadas
    {
    char calle[50];
    char numeroCasa[10];
    int cp;
    };

struct Direccion
    {
    char colonia[50];
    struct Coordenadas domicilio;
    };

struct Estudiantes
    {
    int id;
    char nombre[50];
    struct Direccion hogar;
    };
    struct persona {
        char nombre[50];
        struct direccion {
            char calle[50];
            int numero;
        } domicilio;
    };
    
int main() {
    struct KeyValue tabla[3] = {
        {"usuario","admin"},
        {"contraseña","1234"},
        {"servidor","localhost"}
    
};
    int opcion;
    int numeros[] = {12,20,30,20};
    int size = sizeof(numeros)/sizeof(numeros[0]);
    int arreglo[5] = {1,2,3,4,5};
    int a, b, c, d, e, f;
        printf("\n=== MENU DE PROGRAMAS ===\n");
        printf("1. Punteros básicos\n");
        printf("2. Punteros dobles\n");
        printf("3. Arreglo de enteros\n");
        printf("4. Tabla clave-valor\n");
        printf("5. Operaciones con punteros\n");
        printf("6. Ecuación cuadrática (versión 1)\n");
        printf("7. Ecuación cuadrática (versión 2)\n");
        printf("8. Estructuras anidadas (Estudiantes)\n");
        printf("9. Estructuras anidadas (Personas)\n");
        printf("10. Estructura Estudiante básica\n");
        printf("11. Conversión de temperaturas\n");
        printf("12. Conversión de pesos a dólares\n");
        printf("13. Resolución de ecuación cuadrática\n");
        printf("14. Determinar signo de número\n");
        printf("15. Potencia de números\n");
        printf("16. Números pares en intervalo\n");
        printf("17. Tabla de multiplicar\n");
        printf("18. Suma de números\n");
        printf("19. Mayor de 2 números\n");
        printf("20. Mayor de 3 números\n");
        printf("21. Cálculo de áreas y volúmenes\n");
        printf("22. Operaciones con funciones\n");
        printf("23. Estructura Usuario\n");
        printf("24. Matriz 3x3\n");
        printf("25. Matriz con operaciones\n");
        printf("26. Matriz con uniones\n");
        printf("27. Matrices con archivos\n");
        printf("28. Tabla de multiplicar con struct\n");
        printf("29. Operaciones con punteros (versión 2)\n");
        printf("30. Matriz de cadenas\n");
        printf("31. Coordenadas (incompleto)\n");
        printf("32. Uso de sprintf\n");
        printf("33. Suma con punteros\n");
        printf("34. Ecuación cuadrática (versión 3)\n");
        printf("35. Operaciones con matrices\n");
        printf("36. Figuras geométricas\n");
        printf("37. Matriz de estructuras Fruta\n");
        printf("38. Uniones\n");
        printf("39. Colores en consola\n");
        printf("40. Patrón de colores\n");
        printf("41. Bandera con colores\n");
        printf("42. Interfaz con gotoxy\n");
        printf("43. Calculadora con gotoxy\n");
        printf("44. Menú con gotoxy\n");
        printf("45. Bandera mexicana\n");
        printf("46. Matriz de caracteres\n");
        printf("47. Determinante de matrices\n");
        printf("48. Matriz transpuesta\n");
        printf("49. Árbol de asteriscos\n");
        printf("50. Multiplicación de matrices\n");
        printf("51. Potencia de matrices\n");
        printf("52. Matrices de fracciones\n");
        printf("53. Multiplicación matriz-vector\n");
        printf("54. Calculadora avanzada con gotoxy\n");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
            printf("\033[2J"); // Limpia la pantalla
            printf("Seleccionaste Punteros Basicos\n");
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
                break;
            case 2:
            printf("\033[2J"); // Limpia la pantalla
            printf("Seleccionaste Punteros Basicos 2\n");
             printf("Tamaño: %d\n", size);
            for (int i=0; i<size; i++) {
            printf("%d\n", numeros[i]);
                }
                break;
            case 3:

            printf("Tamano: %d\n", size);
            for (int i=0; i<size; i++) {
                printf("%d\n", numeros[i]);
            }
                break;
            case 4:

            for (int i=0; i<5; i++) {
                printf("%d\n", arreglo[i]);
            }
                break;
            case 5:

                break;
            case 6:

            printf("Tabla Clave-Valor:\n");
            for (int i=0; i< 3; i++){
                printf("%s: %s\n", tabla[i].clave, tabla[i].valor);
            }
                break;
            case 7:
   
            printf("Ingrese el valor A\n");
            scanf("%d", &a);
            printf("Ingrese el valor B\n");
            scanf("%d", &b);
            printf("Ingrese el valor C\n");
            scanf("%d", &c);
            printf("Ingrese el valor D\n");
            scanf("%d", &d);
            printf("Ingrese el valor E\n");
            scanf("%d", &e);
            printf("Ingrese el valor F\n");
            scanf("%d", &f);  


            int DH;  
            int* DL = &DH;
            const int* AH = &a;
            const int* AL = &b;
            const int* BH = &c;
            const int* BL = &d;
            const int* CH = &e;
            const int* CL = &f;
            

            printf("Valores ingresados: A=%p\n", AH);
            printf("Valores ingresados: B=%p\n", AL);
            printf("Valores ingresados: C=%p\n", BH);
            printf("Valores ingresados: D=%p\n", BL);
            printf("Valores ingresados: E=%p\n", CH);
            printf("Valores ingresados: F=%p\n", CL);

            /////////// AH Y AL operaciones
            // SUMA
            *DL = *AH + *AL;
            printf("Resultado de la suma: %d\n", *DL);
            printf("Valor nuevo: A=%d\n", *DL);

            // RESTA
            *DL = *AH - *AL;
            printf("Resultado de la resta: %d\n", *DL);
            printf("Valor nuevo: B=%d\n", *DL);

            // MULTIPLICACION
            *DL = *AH * *AL;
            printf("Resultado de la multiplicacion: %d\n", *DL);
            printf("Valor nuevo: C=%d\n", *DL);

            // DIVISION
                *DL = *AH / *AL;
                printf("Resultado de la division: %d\n", *DL);
                printf("Valor nuevo: D=%d\n", *DL);



            //////// BH Y BL operaciones
            // SUMA
            *DL = *BH + *BL;
            printf("Resultado de la suma: %d\n", *DL);
            printf("Valor nuevo: A=%d\n", *DL);

            // RESTA
            *DL = *BH - *BL;
            printf("Resultado de la resta: %d\n", *DL);
            printf("Valor nuevo: B=%d\n", *DL);

            // MULTIPLICACION
            *DL = *BH * *BL;
            printf("Resultado de la multiplicacion: %d\n", *DL);
            printf("Valor nuevo: C=%d\n", *DL);

            // DIVISION
            *DL = *BH / *BL;
            printf("Resultado de la division: %d\n", *DL);
            printf("Valor nuevo: D=%d\n", *DL);

            // CH Y CL operaciones
            // SUMA
            *DL = *CH + *CL;
            printf("Resultado de la suma: %d\n", *DL);
            printf("Valor nuevo: A=%d\n", *DL);

            // RESTA
            *DL = *CH - *CL;
            printf("Resultado de la resta: %d\n", *DL);
            printf("Valor nuevo: B=%d\n", *DL);

            // MULTIPLICACION
            *DL = *CH * *CL;
            printf("Resultado de la multiplicacion: %d\n", *DL);
            printf("Valor nuevo: C=%d\n", *DL);

            // DIVISION
            *DL = *CH / *CL;
            printf("Resultado de la division: %d\n", *DL);
            printf("Valor nuevo: D=%d\n", *DL);
                break;
            case 8:
 
                break;
            case 9:{
            printf("\033[2J"); // Limpia la pantalla
            printf("Seleccionaste Estructuras anidadas (Personas)\n");
            
            int n;
            printf("Ingrese el numero de personas: ");
            scanf("%d", &n);
            getchar(); // Limpiar el buffer
            
            struct persona personas[n];

            for(int i=0; i<n; i++) {
                printf("\nIngrese los datos de la persona %d:\n", i+1);
                printf("Nombre: ");
                scanf("%s", personas[i].nombre); // Leer nombre con espacios
                
                printf("Calle: ");
                scanf(" %s", personas[i].domicilio.calle);
                
                printf("Número: ");
                scanf("%d", &personas[i].domicilio.numero);
                getchar(); // Limpiar buffer después de número
            }

            printf("\n%-20s| %-20s | %-10s\n", "Nombre", "Dirección", "Numero");
            printf("--------------------------------------------------\n");
            for(int i=0; i<n; i++) {
                printf("%-20s| %-20s| %-10d\n",
                    personas[i].nombre,
                    personas[i].domicilio.calle,
                    personas[i].domicilio.numero);
            }}
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 25:
                break;
            case 26:
                break;
            case 27:
                break;
            case 28:
                break;
            case 29:

                break;
            case 30:
                break;

            case 31:
                break;

            case 32:
                break;

            case 33:
                break;

            case 34:
                break;

            case 35:
                break;

            case 36:
                break;

            case 37:
                break;

            case 38:
                break;

            case 39:
                break;

            case 40:
                break;

            case 41:
                break;

            case 42:
                break;

            case 43:
                break;

            case 44:
                break;

            case 45:
                break;

            case 46:
                break;

            case 47:
                break;
            case 48:
                break;

            case 49:
                break;

            case 50:
                break;

            case 51:
                break;

            case 52:
                break;
            case 53:

                break;

            case 54:

                break;


            default:
                break;
        }
        
      
  
    return 0;
}