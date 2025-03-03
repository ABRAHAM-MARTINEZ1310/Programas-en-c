#include <stdio.h>
int main() {
    int espacios = 6;
    int asteriscos = 0; 

    for (int i = 6; i >= 0; i--) {  
        for (int j = 1; j <= espacios; j++) {  
            printf("%5s", " ");  
        }
        for (int k = 0; k <= asteriscos; k++) {  
            printf("%5s","*");  
        }
       
        asteriscos+=2; 
        espacios--;   
        printf("\n");  
    }
}