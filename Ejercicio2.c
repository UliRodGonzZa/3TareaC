//Carlo Magno Romero Calixto

#include <stdio.h>
#include <string.h>

typedef struct Producto
{
    char nombre[20];
    float precio;
    int cantidad;
} Producto ;


float cartTotal(Producto *p,int sizeCart){

    float Total = 0.0;

    for (int i = 0; i < sizeCart; i++)
    {
        Total+= p[i].precio * p[i].cantidad;
    }

    return Total;

}

int main(int argc, char const *argv[])
{
    // Inicializamos 5 productos
    Producto p1 = {"Jabon", 60, 3};
    Producto p2 = {"Brincolin", 1200, 1};
    Producto p3 = {"Cafe",52.50,2};
    Producto p4 = {"Salchichas", 40, 4};
    Producto p5 = {"Aceitunas", 180, 3};

    // Inicializamos el arreglo con los productos
    Producto Cart[5] = {p1,p2,p3,p4,p5};

    // Declaramos el apuntador que ayudara a recorrer el array
    Producto *p = Cart;

    // Debido a que trabajamos con un arreglo estatico 
    // utilizaremos size_of

    int cartSize = sizeof(Cart) / sizeof(Producto);

   // printf("\n Size: %d \n", cartSize);

    printf("El valor total del carrito es de %.2f\n", cartTotal(p,cartSize));

    return 0;
}