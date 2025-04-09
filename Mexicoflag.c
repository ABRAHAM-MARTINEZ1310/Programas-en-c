#include <stdio.h>
void setColor(const char* color) {
    printf("%s", color);
}

int main() {
    printf("\033[2J"); 
    int filas = 5; 
    int columnas = 9; 


    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 3; j++) {
            setColor("\033[7;32m");
            printf("%2s", " ");
            setColor("\033[0m");
        }
        for (int k = 0; k < 3; k++) {
            if(i==2 && k==1){
                setColor("\033[7;37m");
                printf("%2s", " ");
                printf("%2s", "  ");
                setColor("\033[0m");
                k++;
            }else{
            setColor("\033[7;37m");
            printf("%2s", " ");
            setColor("\033[0m");
            }
        }
        for (int u = 0; u < 3; u++) {
            setColor("\033[7;31m");
            printf("%2s", " ");
            setColor("\033[0m");
        }
        printf("\n");
    }

return 0;
}