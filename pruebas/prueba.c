#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num = 4;
    printf("Factorial de %d es %d\n", num, factorial(num));
    return 0;
}
#include <stdio.h>

int sumaNaturales(int n) {
    if (n == 1)
        return 1;
    else
        return n + sumaNaturales(n - 1);
}

int main() {
    int num = 5;
    printf("Suma de los primeros %d numeros naturales es %d\n", num, sumaNaturales(num));
    return 0;
}
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int i, cantidad = 10;
    printf("Serie Fibonacci:\n");
    for (i = 0; i < cantidad; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int numDiscos = 3;
    hanoi(numDiscos, 'A', 'C', 'B');
    return 0;
}
#include <stdio.h>

int potencia(int base, int exponente) {
    if (exponente == 0)
        return 1;
    else
        return base * potencia(base, exponente - 1);
}

int main() {
    int base = 2, exponente = 3;
    printf("%d elevado a la %d es %d\n", base, exponente, potencia(base, exponente));
    return 0;
}
#include <stdio.h>

int contarDigitos(int n) {
    if (n == 0)
        return 0;
    else
        return 1 + contarDigitos(n / 10);
}

int main() {
    int numero = 12345;
    printf("Cantidad de digitos en %d es %d\n", numero, contarDigitos(numero));
    return 0;
}
#include <stdio.h>

int sumarDigitos(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10) + sumarDigitos(n / 10);
}

int main() {
    int numero = 1234;
    printf("Suma de los digitos de %d es %d\n", numero, sumarDigitos(numero));
    return 0;
}
#include <stdio.h>

int invertirNumero(int n, int resultado) {
    if (n == 0)
        return resultado;
    else
        return invertirNumero(n / 10, resultado * 10 + n % 10);
}

int main() {
    int numero = 1234;
    int invertido = invertirNumero(numero, 0);
    printf("Numero invertido de %d es %d\n", numero, invertido);
    return 0;
}
#include <stdio.h>

int mcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return mcd(b, a % b);
}

int main() {
    int a = 48, b = 18;
    printf("El MCD de %d y %d es %d\n", a, b, mcd(a, b));
    return 0;
}
