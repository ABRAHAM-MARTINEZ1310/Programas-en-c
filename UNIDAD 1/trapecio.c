#include <stdio.h>

int main() {
    int espacios = 4;
    int asteriscos = 15; 

    for (int i = 3; i >= 0; i--) {  
        for (int j = 1; j <= espacios; j++) {  
            printf("%5s", " ");  
        }
        for (int k = 1; k <= asteriscos; k++) {  
            printf("%5s","*");  
        }
       
        asteriscos-=2; 
        espacios++;   

        
        printf("\n");  
    
}   
    return 0;
}
