// Gonzalez Zavala Ulises Rodrigo

#include <stdio.h>
#include <stdlib.h> // La funcion malloc se define en esta libreria
#include <string.h>  

// Definicion de struct para Empleado
typedef struct Employee
{
    char name[20];
    char ID[8];
    float salary;
    int age;
} Employee;

// Definicion de struct para Departamento
typedef struct Department
{
    char name[20];
    int sizeEmployees;
    Employee *Employee; // Arreglo dinamico de empleados
} Department;

// Funcion que imprime los trabajadores del arreglo
void Employees(Employee *p, int sizeEmployees){

    printf("Empleados:\n");

    for (int i = 0; i < sizeEmployees; i++)
    {
        printf("-->  %s \n", p->name);
        printf("ID: %s \n",p->ID);
        printf("Edad: %d \n", p->age);
        printf("Salario: %.2f \n", p->salary);
        
        p++;
    }
}


int main(int argc, char const *argv[])
{
    // Inicializamos departamento con nombres y numero de empleados
    Department devop = {"Web",3};

    // La memoria se asigna dinámicamente usando malloc()
    devop.Employee = (Employee*)malloc(devop.sizeEmployees * sizeof(Employee));

    // Asignar memoria dinamicamente usando mallo
    if(devop.Employee == NULL ){
        printf("Error al asignar memoria dinamicamente");
        return 1;
    }
    
    // Puntero para recorrer el arreglo
    Employee *p = devop.Employee;

    // Colocando los datos de los empleados:

    strcpy(devop.Employee[0].name, "Rodrigo");
    strcpy(devop.Employee[0].ID,   "RXS");
    devop.Employee[0].salary = 25000.00;
    devop.Employee[0].age = 25;

    strcpy(devop.Employee[1].name, "Carlo");
    strcpy(devop.Employee[1].ID,   "CAA");
    devop.Employee[1].salary = 15000.00;
    devop.Employee[1].age = 22;

    strcpy(devop.Employee[2].name, "Alessa");
    strcpy(devop.Employee[2].ID,   "AAX");
    devop.Employee[2].salary = 22000.00;
    devop.Employee[2].age = 24;

    // Imprimir Datos del Departamento

    printf("Nombre del Departamento: %s \n",devop.name); 
    Employees(p,devop.sizeEmployees);

     // Liberar memoria dinamica
     free(devop.Employee);


    return 0;
}
