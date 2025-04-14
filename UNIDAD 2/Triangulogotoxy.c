#include <stdio.h>
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
int main() {
    int espacios = 6;
    int asteriscos = 0; 

    for (int i = 6; i >= 0; i--) {  
        for (int j = 1; j <= espacios; j++) {  
            setColor("\033[0;30m");
            printf("%5s", " ");  
        }
        for (int k = 0; k <= asteriscos; k++) {  
            setColor("\033[7;31m");
            printf("%5s","*");  
        }
        setColor("\033[0;30m");
        asteriscos+=2; 
        espacios--;   
        printf("\n");  
    }
}