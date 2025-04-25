// Gonzalez Zavala Ulises Rodrigo

#include <stdio.h>
#include <stdlib.h> // Incluye a malloc
#include <string.h>

// Estructura Paciente
typedef struct Paciente
{ 
    char nombre[20];
    int  edad;
    char diagnostico[20];
    int prioridad; // Este valor indicara el orden de desalojo en la lista
    struct Paciente *sig; // El puntero siguiente para recorrer la lista enlazada
} Paciente;

typedef Paciente *pPointer;  //Puntero al tipo de dato Paciente para no utilizar punteros de punteros

void insertarPaciente     (pPointer *head, char *nombre, int edad, char *diagnostico, int prioridad);
void imprimirPacientes    (Paciente *head);
void borrarPacienteNombre (pPointer *head, const char *nombre);
// const porque no modificaremos el string a utilizar


int main(int argc, char const *argv[])
{
    pPointer head; // Indica la cabeza de la lista enlistada, sera nuestra referencia base
    head = NULL; // Inicializamos como NULL porque no hay ningun nodo cargado en la lista

    // Insertando pacientes:
    insertarPaciente(&head,"Teodoro", 10, "Brazo Roto", 1);
    insertarPaciente(&head,"Rodrigo", 21, "Tos", 3);
    insertarPaciente(&head,"Adrian", 5, "Diabetes", 2);
    insertarPaciente(&head,"Vicente", 18, "Dolor Estomago", 3);
    insertarPaciente(&head,"Lola", 88, "Derrame Cerebral", 1);
    insertarPaciente(&head,"Vanessa", 30, "Alergia", 2);
    insertarPaciente(&head,"Ofelia", 40, "Hinchazon", 2);
    insertarPaciente(&head,"Federico", 3, "Brazo Roto", 1);
    insertarPaciente(&head,"Sasha", 42, "Dolor Estomago", 2);
    insertarPaciente(&head,"Axel", 17, "Dolor de Cabeza", 2);
    // En esta estructura el ultimo paciente registrado es el primero en la cabeza(head)

    imprimirPacientes(head);

    // Eliminando pacientes
    printf("\n");
    borrarPacienteNombre(&head, "Ofelia");
    borrarPacienteNombre(&head, "Axel");
    printf("\n");

    // Despues de atender (eliminar)
    imprimirPacientes(head);

    return 0;
}

void insertarPaciente(pPointer *head, char *nombre, int edad, char *diagnostico, int prioridad) {
    pPointer nuevo; // Creamos un nuevo nodo
    nuevo = malloc(sizeof(Paciente)); // Reservamos memoria para ese nodo

    // Asignamos los valores al nuevo paciente
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    strcpy(nuevo->diagnostico, diagnostico);
    nuevo->prioridad = prioridad;

    // Insertamos al inicio de la lista
    nuevo->sig = *head; //Le asignamos al siguiente el valor de head
    *head = nuevo; // Head pasa a ser el ultimo nodo agregado
}

void imprimirPacientes(Paciente *head) {
    while (head != NULL) { // Mientras Head no sea NULL (final)
        // Imprimimos inf del nodo actual
        printf("Nombre: %s, Edad: %d, Diagnóstico: %s, Prioridad: %d\n",
            head->nombre, head->edad, head->diagnostico, head->prioridad);
            head = head->sig; // Pasamos al siguiente nodo
    }
}

void borrarPacienteNombre(pPointer *head, const char *nombre) {
    Paciente *actual = *head;      // Nodo que toma posición actual
    Paciente *anterior = NULL;     // Nodo que toma posición anterior

    // Recorremos hasta llegar al final de la lista (NULL)
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            if (anterior == NULL) {
                // El nodo a eliminar es la head
                *head = actual->sig;
            } else {
                // El nodo está en medio o al final
                anterior->sig = actual->sig;
            }

            free(actual); // Liberamos de memoria el nodo encontrado
            printf("Paciente: %s atendid@\n", nombre);
            return; // Salimos del while
        }

        anterior = actual;    // Actualizamos nodo anterior
        actual = actual->sig; // Avanzamos el siguiente nodo 
    }

    printf("Paciente: %s, no encontrado\n", nombre);
}
