//Carlo Magno Romero Calixto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITULO 100
#define MAX_AUTOR 50

typedef struct{
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int año;
    bool disponible;

}Libro;

void agregarLibro(Libro **lista, int *total, const char *titulo, const char *autor, int año, bool disponible){
    *total += 1;
    *lista = realloc(*lista, (*total) * sizeof(Libro));
    if(*lista == NULL){
        puts("ERROR RESERVANDO MEMORIA");
        exit(1);
    }
Libro *ultimo = *lista+(*total - 1);
strncpy(ultimo->titulo, titulo, MAX_TITULO-1);
ultimo->titulo[MAX_TITULO-1]=0;
strncpy(ultimo->autor, autor, MAX_AUTOR-1);
ultimo->autor[MAX_AUTOR-1] = 0;
ultimo->año = año;
ultimo->disponible = disponible;
}

void quitarLibro(Libro **lista, int *total, const char *titulo){
    int pos = -1;
    for(int i=0; i<*total; i++){
        if(strcmp((*lista)[i].titulo, titulo) !=0) continue;
        pos = i;
        break;
    }

    if(pos == -1) return;

    for(int j=pos; j<*total-1; j++){
        (*lista)[j] = (*lista)[j+1];
    }

    *total-=1;
    Libro *tmp = realloc(*lista, (*total) *sizeof(Libro));

    if(tmp == NULL && *total > 0){
        puts("ERROR, AJUSTANDO MEMORIA");
        exit(2);
    }

    *lista= tmp;

}

void buscarLibro(const Libro * lista, int total){
    puts("\n\nInventario Actual:\n\n");
    for(int i=0; i<total; i++){
        printf("Titulo: %s\n", lista[i].titulo);
        printf("Autor: %s\n", lista[i].autor);
        printf("Publicación: %d\n", lista[i].año);
        printf("Disponibilidad: %s\n\n", lista[i].disponible ? "Disponile" : "Prestado");
    }
}


int main(){
    Libro *inventario =NULL;
    int cantidad = 0;

    agregarLibro(&inventario, &cantidad, "El mejor momento es ahora", "Jack Kornfield", 2018, 0 );
    agregarLibro(&inventario, &cantidad, "Las batallas en el desierto", "José Emilio Pacheco", 1981, 1 );
    agregarLibro(&inventario, &cantidad, "El llano en llamas", "Juan Rulfo", 1953, 0 );
    agregarLibro(&inventario, &cantidad, "Cien años de soledad", "Gabriel Garcia Marquez", 1967, 1 );
    agregarLibro(&inventario, &cantidad, "El principito", "Antonie de Saint-Exupéry", 1947, 1 );
    agregarLibro(&inventario, &cantidad, "Matar a un ruiseñor", "Harper Lee", 1960, 1 );
    agregarLibro(&inventario, &cantidad, "La rebelion en la granja", "George Orwell", 1949, 0 );
    agregarLibro(&inventario, &cantidad, "Pequeño cerdo capitalista", "Sofía Macías", 2011, 1 );


    quitarLibro(&inventario, &cantidad, "Cien años de soledad");
    quitarLibro(&inventario, &cantidad, "El llano en llamas");
    quitarLibro(&inventario, &cantidad, "Pequeño cerdo capitalista");


    buscarLibro(inventario, cantidad);

    free(inventario);
    return 0;
}