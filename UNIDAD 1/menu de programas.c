#include <stdio.h>
#include <math.h>
int main(){
    int opcion;
    printf("1:AREA Y VOLUMEN DE UN CILINDRO\n");
    printf("2:AREA Y VOLUMEN DE UN CONO\n");
    printf("3:AREA Y VOLUMEN DE UNA ESFERA\n");
    printf("4:CONTADOR\n");
    printf("5:CONTADOR INVERSA\n");
    printf("6.-CALCULADORA DE NUMEROS\n");
    printf("7.-CUADRADO DE ASTERISCOS\n");
    printf("8.-CUADRADO DE NUMEROS\n");
    printf("9.-DIAGONAL\n");
    printf("10.- ESCAPES\n");
    printf("11.-PROMEDIO\n");
    printf("12.-PRUEBA SWITCH\n");
    printf("13.-TABLAS DE MULTIPLICACION\n");
    printf("14.-TEMPERATURA ENTEROS\n");
    printf("15.-TEMPERATURA FLOAT\n");
    printf("16.-TIPOS DE DATOS\n");
    printf("17.-TRAPECIO\n");
    printf("18.-TRIANGULO EQUILATERO\n");
    printf("19.-TRIANGULO RECTANGULO 1\n");
    printf("20.- TRIANGUO RECTANGULO 2\n");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("ELEGISTE EL AREA Y VOLUMEN DE UN CILINDRO\n");
            float r;
            float h;
            float pi=3.1416;
            printf("%s\n","ingresa el radio del cilindro");
            scanf("%f",&r);
            printf("%s\n","ingresa la altura del cilindro");
            scanf("%f",&h);
            float v=(pi*(r*r)*h);
            float a=(2*pi*r)*(r+h);
            printf("%s%f\n","El area es:",a);
            printf("%s%f\n","El volumen es:",v);
            break;
        case 2:
            printf("ELEGISTE EL AREA Y VOLUMEN DE UN CONO\n");
            float r1;
            float h1;
            float pi1=3.1416;
            printf("%s\n","ingresa el radio del cono");
            scanf("%f",&r1);
            printf("%s\n","ingresa la altura del cono");
            scanf("%f",&h1);
            float g1=sqrt((r1*r1)+(h1*h1));
            float v1=((pi1*(r1*r1)*h1)/3);
            float a1=(pi1*r1)*(r1+g1);
            printf("%s%f\n","El area es:",a1);
            printf("%s%f\n","El volumen es:",v1);
            break;
        case 3:
            printf("ELEGISTE EL AREA Y VOLUMEN DE UNa ESFERA\n");
            float r2;
            float pi2=3.1416;
            printf("%s\n","ingresa el radio de la esfera");
            scanf("%f",&r2);
            float v2=((4*pi2*(r2*r2*r2))/3);
            float a2=(4*pi2*(r2*r2));
            printf("%s%f\n","El area es:",a2);
            printf("%s%f\n","El volumen es:",v2);
            break;
        case 4:
            printf("ELEGISTE EL CONTADOR\n");
            int contador = 0;
            int limite = 10;
            printf("%4s\n","EJEMPLO DE IMPRESION");
            while (contador <= limite){
            printf("%4d",contador);
            contador++;
            }
            break;
            case 5:
            printf("ELEGISTE CONTADOR A LA INVERSA/n");
            int limetey = 10;
            while (limetey >= 0) {
            int limetex = 10;
            while (limetex >= 0) {
                printf("%4d", limetex); // Imprime el valor de limetex
                limetex--;
            }
            printf("\n"); // Salto de línea al final de cada fila
            limetey--;
            }
            break;

        case 6:
            printf("ELEGISTE CALCULADORA DE NUMEROS\n");
            float num1, num2;
            int ope;
            float res;
            printf("%s", "Ingresa el numero 1: ");
            scanf("%f", &num1);
            printf("%s", "Ingresa el numero 2: ");
            scanf("%f", &num2);

            printf("%s\n", "Que operacion quieres realizar?");
            printf("%s\n", "1: Sumar");
            printf("%s\n", "2: Restar");
            printf("%s\n", "3: Multiplicar");
            printf("%s\n", "4: Division");
            scanf("%d", &ope);

            switch(ope){
                case 1:
                    res=num1+num2;
                    printf("%s\n%.5f", "El resultado es:", res);
                    break;

                case 2:
                    res=num1-num2;
                    printf("%s\n%.5f", "El resultado es:", res);
                    break;

                case 3:
                    res=num1*num2;
                    printf("%s\n%.5f", "El resultado es:", res);
                    break;
                    
                case 4:
                    res=num1/num2;
                    printf("%s\n%.5f", "El resultado es:", res);
                    break;

                    default:
                    printf("%s", "No has elegido un operacion correcta");
                    break;
                }

        break;

        case 7:
        printf("ELEGISTE EL CUADRADO DE ASTERISCOS \n");
        
                for (int a=0;a<=9;a++){
                    printf("%3s","*");
                }
                printf("\n");
                for(int b=1;b<=7;b++){
                    printf("%3s","*");

                    for (int c=1;c<=8;c++){
                        printf("%3s"," ");
                    }

                    printf("%3s","*");
                    printf("\n");

                }
                for (int a=0;a<=9;a++){
                    printf("%3s","*");
                }

        break;
        case 8:
                printf("ELEGISTE CUADRADO DE NUMEROS\n");
                int contador2 = 0;
                int limite2 = 10;
                
                printf("%4s\n", "Ejemplo de impresion");
                while (contador2 <= limite2) {
            
                        printf("%4d", contador2);
                        contador2++;
                }
                printf("\n%s\n", "ejemplo de impresiom");
            
            int limitey2 = 10;
                while (limitey2 >= 0) {
                    int limitex2 = 10;
                    while (limitex2 >= 0) {
                        printf("%4d", limitex2);
                        limitex2--;
            
                    }
                    printf("\n");
                    limitey2--;
                }
            
                printf("\n%s\n","ejemplo de impresion");
            
                int limitesy2 = 0;
                while (limitesy2 <= 10) {
                    int limitex2 = 0;
                    while (limitex2 <= 10) {
                        printf("%4d", limitex2);
                        limitex2++;
            
                    }
                    printf("\n");
                    limitey2++;
                }
            
                printf("\n%s\n","ejemplo de impresion");

        break;
        case 9:
        printf("ELEGISTE DIAGONAL\n");
        int espacio=1;
            
        for(int a=9;a>=0;a--){
    
            for(int b=2;b<=espacio;b++){
                printf("%4s"," ");
            }
            
            espacio++;
            printf("%4s","*");
            printf("\n");
    
        }
        break;
        case 10:
        printf("ELEGISTE ESCAPES\n");
        printf("\\a Alarma\n");
        printf("\\b Retroceso\n");
        printf("\\f Avance de pagina\n");
        printf("\\n Retorno de carro y avance de linea\n");
        printf("\\r Retorno de carro\n");
        printf("\\t Tabulacion\n");
        printf("\\\\ Diagonal invertida\n");
        printf("\\? Signo de interrogacion\n");
        printf("\\\" Comillas dobles\n");
        printf("\\000 Octal\n");
        printf("\\xhh Hexadecimal\n");
        printf("\\0 Caracter nulo\n");

        break;
        case 11:
        printf("ELEGISTE PROMEDIO\n");
        char nombre[50];
        printf("%s\n", "Ingrese su nombre: ");
        scanf("%s", &nombre);
    
        int cal1;
        printf("%s", "Ingresa la calificacion 1: ");
        scanf("%d", &cal1);
    
        int cal2;
        printf("%s", "Ingresa la calificacion 2: ");
        scanf("%d", &cal2);
    
        int cal3;
        printf("%s", "Ingresa la calificacion 3: ");
        scanf("%d", &cal3);
    
        float promedio=(cal1 + cal2 + cal3)/3;
        printf("%s%s", "Nombre:", nombre);
        printf("\n");
        printf("%s%2f", "El promedio es:\n", promedio);
        printf("\n");
        
        if(promedio>=6){
            printf("%s\n","APROBADO!");
        } else { 
            printf("%s\n","REPROBADO ");
        }
        break;
        case 12:
        printf("ELEGISTE PRUEBA SWITCH\n");
        int opcion;
        printf("1.- Suma\n");
        printf("2.- Resta\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("Elegiste la suma\n");
                break;
            case 2:
                printf("Elegiste la resta\n");
                break;
        }
        break;
        case 13:
        printf("ELEGISTE TABLAS DE MULTIPLICACION\n");
        int tabla = 0;
        while(tabla <= 10){
        int numero = 0;
        while (numero <= 10){
            int multi= numero * tabla;
            printf("%s%d%s%d%s%d\n",
                "(",tabla,")(",numero,")=",multi);
            numero++;}  
        tabla++;
        
    }
        break;
        case 14:
        printf("ELEGISTE TEMPERATURA INT \n");
        int fahr, celsius; /* Declarar variables en formato int*/
        int lower, upper, step; /* Declarar variables en formato int*/
    
            lower = 0; /* Asignar valores a una variable*/
            upper = 300;  /* Asignar valores a una variable*/
            step = 20;  /* Asignar valores a una variable*/
            fahr = lower;  /* Asignar valores a una variable*/
    
                while (fahr <= upper) {  /* Declarar un ciclo que se realiza mientraas fahr es menor o igual a upper*/
                    celsius = 5 * (fahr-32) / 9; /*Realizar la aperacion para celsius*/
                    printf("%d\t%d\n", fahr, celsius); /* imprimir las variables fahr y celsius con una tabulacion y un salto de linea*/
                    fahr = fahr + step; /*Sumar step a fahr*/
                    
                } /*fin del ciclo*/

        break;
        case 15:
        printf("ELEGISTE TEMPERATURA FLOAT \n");
        float fahr2, celsius2;
        int lower2, upper2, step2;
    
        lower2 = 0;    /* Límite inferior de la tabla de temperaturas */
        upper2 = 300;  /* Límite superior */
    
        step2 = 20;    /* Tamaño del incremento */
    
        fahr2 = lower2;
        while (fahr2 <= upper2) {
            celsius2 = 5 * (fahr2 - 32) / 9;
            printf("%3.0f %6.1f\n", fahr2, celsius2);  // Corregido aquí
            fahr2 = fahr2 + step2;
        }

        break;
        case 16:
        printf("ELEGISTE TIPOS DE DATOS\n");
        printf("%s","%d Imprime datos enteros decimales: 5\n");
        printf("%s","%i Imprime datos enteros: 2\n");
        printf("%s","%o Imprime datos octales: 6\n");
        printf("%s","%x Imprime datos hexadecimales: 8A1\n");
        printf("%s","%u Imprime datos enteros sin signo en decimal: 23\n");
        printf("%s","%c Imprime datos de caracteres: #\n");
        printf("%s","%e Imprime datos reales expresados en base y exponente:5^2 \n");
        printf("%s","%f Imprime datos reales escrito con punto decimal: 23.12\n");
        printf("%s","%g Imprime datos reales : 14\n");
        printf("%s","%s Imprime cadenas de caracteres: Hola123\n");
        printf("%s","%lf Imprime datos reales de tipo long double: 2.1646466565466642\n");
        break;
        case 17:
        printf("ELEGISTE TRAPECIO \n");
        int espacios1 = 3;
        int asteriscos1 = 3; 
    
        for (int i = 3; i >= 0; i--) {  
            for (int j = 1; j <= espacios1; j++) {  
                printf("%5s", " ");  
            }
            for (int k = 1; k <= asteriscos1; k++) {  
                printf("%5s","*");  
            }
           
            asteriscos1+=2; 
            espacios1--;   
    
            
            printf("\n");  
        
    }   
        break;
        case 18:
        printf("ELEGISTE TRIANGULO EQUILATERO\n");
        int espacios2 = 6;
        int asteriscos2 = 0; 
    
        for (int i = 6; i >= 0; i--) {  
            for (int j = 1; j <= espacios2; j++) {  
                printf("%5s", " ");  
            }
            for (int k = 0; k <= asteriscos2; k++) {  
                printf("%5s","*");  
            }
           
            asteriscos2+=2; 
            espacios2--;   
            printf("\n");  
        }

        break;
        case 19:
        printf("ELEGISTE TRIANGULO RECTANGULO 1\n");
        int asteriscos3=1;
for (int i=6 ; i>=0;i--) {
    for (int j=1; j<= asteriscos3; j++) {
    printf("%5s", "*");
}
asteriscos3++;
printf("\n");
}

        break;
    case 20:
    printf("ELEGISTE TRIANGULO RECTANGULO 2\n");
    int asteriscos4=1;
    for (int i=6 ; i>=0;i--) {
        for (int k=6; k>= asteriscos4; k--){
            printf("%5s", " ");
    
        }
        for (int j=1; j<= asteriscos4; j++) {
        printf("%5s", "*");
    }
    asteriscos4++;
    printf("\n");
    }


    break;
    }
    return 0;
}
