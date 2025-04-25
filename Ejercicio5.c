// Gonzalez Zavala Ulises Rodrigo

#include <stdio.h>
#include <stdlib.h> // Incluye a malloc
#include <string.h>

// Definicion de Libro(struct)
typedef struct{

    char name[40];
    char publicationDate[20];
    char author[50];
    int edition;
    float price;

} Libro;

void imprimirLibro(Libro *p, int tamLibros){

    printf("\n=> Arreglo Libros <=\n");
    for (int i = 0; i < tamLibros; i++) {
        printf("Libro %d:\n", i + 1);
        printf("   Nombre: %s\n", p[i].name);
        printf("   Fecha de Publicacion: %s\n", p[i].publicationDate);
        printf("   Autor: %s\n", p[i].author);
        printf("   Edicion: %d\n", p[i].edition);
        printf("   Precio: $%.2f\n \n", p[i].price);
    }   
}

int main(int argc, char const *argv[])
{
    // Puntero que se utliza como arreglo dinamico para Libro
    Libro *p;
    // Variable que asigna el num de libro dentro del array
    int tamLibros = 5;
    // Arreglo dinamico con 5 datos de tipo Libro (struct)
    p = (Libro*)malloc(tamLibros * sizeof(Libro));

    // Asignar memoria dinamicamente usando malloc
    if(p == NULL ){
        printf("Error al asignar memoria dinamicamente");
        return 1;
    }
  
    // Colocando datos a los libros
    strcpy(p[0].name, "1984");
    strcpy(p[0].publicationDate, "08/06/1949");
    strcpy(p[0].author, "George Orwell");
    p[0].edition = 1;
    p[0].price = 299.99;

    strcpy(p[1].name, "Cien años de soledad");
    strcpy(p[1].publicationDate, "05/06/1967");
    strcpy(p[1].author, "Gabriel Garcia Marquez");
    p[1].edition = 2;
    p[1].price = 350.50;

    strcpy(p[2].name, "El Principito");
    strcpy(p[2].publicationDate, "06/04/1943");
    strcpy(p[2].author, "Antoine de Saint-Exupery");
    p[2].edition = 5;
    p[2].price = 180.00;

    strcpy(p[3].name, "Fahrenheit 451");
    strcpy(p[3].publicationDate, "19/10/1953");
    strcpy(p[3].author, "Ray Bradbury");
    p[3].edition = 3;
    p[3].price = 275.75;

    strcpy(p[4].name, "Orgullo y Prejuicio");
    strcpy(p[4].publicationDate, "28/01/1813");
    strcpy(p[4].author, "Jane Austen");
    p[4].edition = 4;
    p[4].price = 199.90;

    // Imprimir arreglo de libros dinamico
    imprimirLibro(p,  tamLibros);

    // Liberar memoria 
    free(p);

    return 0;
}
