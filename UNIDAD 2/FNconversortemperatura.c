#include <stdio.h>
float celsius_a_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_a_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsius_a_kelvin(float celsius) {
    return celsius + 273.15f; 
}

float kelvin_a_celsius(float kelvin) {
    return kelvin - 273.15f;
}

float fahrenheit_a_kelvin(float fahrenheit) {
    float celsius = fahrenheit_a_celsius(fahrenheit);
    return celsius_a_kelvin(celsius);
}

float kelvin_a_fahrenheit(float kelvin) {
    float celsius = kelvin_a_celsius(kelvin);
    return celsius_a_fahrenheit(celsius);
}

int main() {
    int opcion;
    float temperatura, resultado;

    printf("1. Celsius a Fahrenheit\n");
    printf("2. Fahrenheit a Celsius\n");
    printf("3. Celsius a Kelvin\n");
    printf("4. Kelvin a Celsius\n");
    printf("5. Fahrenheit a Kelvin\n");
    printf("6. Kelvin a Fahrenheit\n");
    scanf("%d", &opcion);

    printf("Ingrese la temperatura: ");
    scanf("%f", &temperatura);  

    switch (opcion) {
        case 1:
            resultado = celsius_a_fahrenheit(temperatura);
            printf("%.2f °C = %.2f °F\n", temperatura, resultado);
            break;
        case 2:
            resultado = fahrenheit_a_celsius(temperatura);
            printf("%.2f °F = %.2f °C\n", temperatura, resultado);
            break;
        case 3:
            resultado = celsius_a_kelvin(temperatura);
            printf("%.2f °C = %.2f K\n", temperatura, resultado);
            break;
        case 4:
            resultado = kelvin_a_celsius(temperatura);
            printf("%.2f K = %.2f °C\n", temperatura, resultado);
            break;
        case 5:
            resultado = fahrenheit_a_kelvin(temperatura);
            printf("%.2f °F = %.2f K\n", temperatura, resultado);
            break;
        case 6:
            resultado = kelvin_a_fahrenheit(temperatura);
            printf("%.2f K = %.2f °F\n", temperatura, resultado);
            break;
    }

    return 0;
}