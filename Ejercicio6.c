//Carlo Magno Romero Calixto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Definicion de los limites  de strings
#define MAX_TITULO 100
#define MAX_AUTOR 50

//Definicion estructura libro
typedef struct{
    char titulo[MAX_TITULO];//guarda titulo
    char autor[MAX_AUTOR];//Guardad autor
    int año; //Año de publicación
    bool disponible; //Disponibilidad

}Libro;

//Agregar libro
void agregarLibro(Libro **lista, int *total, const char *titulo, const char *autor, int año, bool disponible){

    *total += 1; //Aumenta contador de libros

    *lista = realloc(*lista, (*total) * sizeof(Libro)); //Redimensiona el arreglo para acomodarnuevo libro

    if(*lista == NULL){ //Verifica si la asignacion fue correcta
        puts("ERROR RESERVANDO MEMORIA");
        exit(1);
    }

Libro *ultimo = *lista+(*total - 1); //Apuntador al ultimo libro agregado(nueva posicion)
strncpy(ultimo->titulo, titulo, MAX_TITULO-1);
ultimo->titulo[MAX_TITULO-1]=0;
strncpy(ultimo->autor, autor, MAX_AUTOR-1);
ultimo->autor[MAX_AUTOR-1] = 0;
ultimo->año = año;
ultimo->disponible = disponible;
}

//Quitar libro
void quitarLibro(Libro **lista, int *total, const char *titulo){
    int pos = -1;//posicion del libro a eliminar
    for(int i=0; i<*total; i++){
        if(strcmp((*lista)[i].titulo, titulo) !=0) continue;//Si no coincide continua
        pos = i;//Guarda la posicion cuando encuentra el libro
        break;
    }

    if(pos == -1) return;//Si  no se encuentra el libro, termina

	//Desplaza los libros posteriores para llenar el espacio del libro elimninado
    for(int j=pos; j<*total-1; j++){
        (*lista)[j] = (*lista)[j+1];//Sobreescribe  libro actual con el sig.
    }

    *total-=1;//Reduce contador total de libros

	//REajsta el tamaño del arrglo despues de la eliminación
    Libro *tmp = realloc(*lista, (*total) *sizeof(Libro));

	//Verifica i hay errores en la reasignacion
    if(tmp == NULL && *total > 0){
        puts("ERROR, AJUSTANDO MEMORIA");
        exit(2);
    }

    *lista= tmp;//Actualiza el puntero al arreglo

}

//Mostrar libros disponibles 
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
    Libro *inventario =NULL;//Puntero al arreglo de libros, inicio vacio
    int cantidad = 0;//Contador de libros, inicia en 0

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
