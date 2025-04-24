// Gonzalez Zavala Ulises Rodrigo

#include <stdio.h>
#include <stdlib.h> // Para generar numeros pseudo-aleatorios
#include <time.h>   // Para utilizar el tiempo del sistema

// Definicion de la struct
typedef struct Ejercicio3
{
    float x;
    float y;
    float z;  // Punto de un sistema 3D
} Point;

// Genera el punto aleatorio en 3D
Point randomPoint(){
    Point p;

    // Fórmula: ((float)rand() / RAND_MAX) * (MAX - MIN) + MIN
    // Genera valores entre -100.0 y 100.0
    p.x = ((float)rand() / RAND_MAX) * 200.0f - 100.0f;
    p.y = ((float)rand() / RAND_MAX) * 200.0f - 100.0f;
    p.z = ((float)rand() / RAND_MAX) * 200.0f - 100.0f;

    // Nota: Se realizo casteo de int a float para trabajar con flotantes
    return p;
}


int main(int argc, char const *argv[])
{    
    // Recordando que -> Xₙ₊₁ = (a * Xₙ + c) % m
    // Inicializar semilla aleatoria usando el reloj del sistema
    srand(time(NULL)); 

    // Inicializamos con un punto aleatorio
    Point p1 = randomPoint(); 
    // Puntero para leer datos
    Point *p = &p1; 

    // Imprimir coordenadas
    printf("Coordenada en x: %.2f \n", p->x);
    printf("Coordenada en y: %.2f \n", p->y);
    printf("Coordenada en z: %.2f \n", p->z);

    return 0;
}


