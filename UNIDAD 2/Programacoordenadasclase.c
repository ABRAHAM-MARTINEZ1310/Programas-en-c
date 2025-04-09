#include <stdio.h>
#include<math.h>

struct coordenada {
    int x;
    int y;
};
int main (){
    int opc;
    printf("%s\n","Selecciona una opcion");
    printf("%s\n","1.-cuadrado");
    printf("%s\n","2.-Triangulo");
    scanf("%d",&opc);
    struct coordenada arreglo[4];
    for(int i=0; i<4 ;i++){
        int posicion= i+1;
        printf("%s%d\n","Ingrese coordenada x",posicion);
        scanf("%d",&arreglo[i].x);
        printf("%s%d\n","Ingrese coordenada y",posicion);
        scanf("%d",&arreglo[i].y);
    }
    switch (opc)
    {
    case 1://cuadrado
     float ab=sqrt(
        pow(arreglo[1].x-arreglo[0].x)+
        pow(arreglo[1].y-arreglo[0].y);
    float bc= ;
    float dc= ;
    float ad= ;
    float perimetro=ab+ ba +dc +ad;
    float area =dc*ac;
    printf("%s%f\n","Perimetro total: ",perimetro);
    printf("%s%f\n","Area: ",area);
    )
    break;
    }
}