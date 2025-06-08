#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char *ptr;

    printf("Escribe una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Eliminar salto de línea si lo hay
    frase[strcspn(frase, "\n")] = '\0';

    printf("\nLongitud de la frase: %lu\n", strlen(frase));

    // Buscar primera aparición de 'a'
    ptr = strchr(frase, 'a');
    if (ptr)
        printf("Primera 'a': posicion %ld\n", ptr - frase);

    // Buscar última aparición de 'a'
    ptr = strrchr(frase, 'a');
    if (ptr)
        printf("Ultima 'a': posicion %ld\n", ptr - frase);

    // Buscar palabra "hola" en la frase
    ptr = strstr(frase, "hola");
    if (ptr)
        printf("La palabra 'hola' esta en la frase.\n");

    // strspn: contar cuántos caracteres al inicio son letras
    size_t letras = strspn(frase, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("Caracteres al inicio que son letras: %lu\n", letras);

    // strcspn: contar hasta que aparece una vocal
    size_t hasta_vocal = strcspn(frase, "aeiouAEIOU");
    printf("Caracteres hasta la primera vocal: %lu\n", hasta_vocal);

    // strpbrk: primer caracter que sea vocal
    ptr = strpbrk(frase, "aeiouAEIOU");
    if (ptr)
        printf("Primera vocal en la frase: '%c'\n", *ptr);

    // strtok: separar en palabras
    printf("\nPalabras de la frase:\n");
    ptr = strtok(frase, " ");
    while (ptr != NULL) {
        printf("- %s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}
