//Carlo Magno Romero Calixto

#include <stdio.h>
#include <string.h>

struct Carro{
    char modelo[20]; //Mustang
    float hoursepower; //Potencia en caballos de fuerza
    char marca[20]; //Ford
    float precio; //Precio en dolares
    int numPuertas; //2 o 4 puertas
};

int main(int argc, char const *argv[]){
    struct Carro c1={"Mustang", 450.0, "Ford", 55000.0, 2};

    //-> Variacion
    //strcp(miCarro.modelo, "Mustang");
    //miCarro.precio = 55000.0;

    struct Carro *c=&c1;

    //Usando el puntero C para accedr a c1
    printf("Modelo: %s\n", c->modelo);
    printf("HP: %.2f\n", c->hoursepower);
    printf("Marca: %s\n", c->marca);
    printf("Precio: %.2f\n", c->precio);
    printf("Num Puertas: %d\n", c->numPuertas);
    
    //Apuntador que modifica los datos de la estructura 

    strcpy(c->modelo, "Xsg");
    c->hoursepower = 600.0; //estandar de facto
    strcpy(c->marca, "Ferrari");
    (*c).precio = 1000000.0;
    (*c).numPuertas = 4;

    printf("Modificando con puntero:\n");

    //Usando el puntero C para accedr a c1
    printf("Modelo: %s\n", c->modelo);
    printf("HP: %.2f\n", c->hoursepower);
    printf("Marca: %s\n", c->marca);
    printf("Precio: %.2f\n", c->precio);
    printf("Num Puertas: %d\n", c->numPuertas);

    //Accdeder ala estructrura 

    /*
    Operador flecha
        Accede a los miembros deuna estructura 
        a traves de un apuntador 
        pr2->Julian
        
    Por * y.
     Accede a los miembros de la variable struct de 
     manera directa 
    (*pr2).nombre="Julian"
    */
   return 0;
}