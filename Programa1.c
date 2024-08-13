#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trabajador {
    char nombre[50];
    int codigo;
    float sueldo;
    int horas_trabajadas;
};

void ingresarTrabajadores(struct Trabajador* trabajadores, int n);
void consultarGenerales(struct Trabajador* trabajadores, int n);
void consultarPorClave(struct Trabajador* trabajadores, int n, int codigo);
void consultarPorNombre(struct Trabajador* trabajadores, int n, char* nombre);
int main() {
    int opcion, numero;
    printf("Ingrese la cantidad de trabajadores a ingresar: ");
    scanf("%d", &numero);
    struct Trabajador* trabajadores = (struct Trabajador*)malloc(numero * sizeof(struct Trabajador));

    do {
        int cod;
        char nombre[50];
        printf("--------MENU--------\n");
        printf("1. Ingresar Trabajadores\n");
        printf("2. Consultas generales\n");
        printf("3. Consultas por clave\n");
        printf("4. Consultas por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarTrabajadores(trabajadores, numero);
                break;
            case 2:
                consultarGenerales(trabajadores, numero);
                break;
            case 3:
                printf("Ingrese el codigo a buscar: ");
                scanf("%d", &cod);
                consultarPorClave(trabajadores, numero, cod);
                break;
            case 4:
                printf("Ingrese el nombre a buscar: ");
                scanf("%s", nombre);
                consultarPorNombre(trabajadores, numero, nombre);
                break;
            case 5:
                printf("Usted salio de programa\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);

    free(trabajadores);
    return 0;
}

void ingresarTrabajadores(struct Trabajador* trabajadores, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del trabajador: ");
        scanf("%s", trabajadores[i].nombre);
        printf("Ingrese el codigo de empleado: ");
        scanf("%d", &trabajadores[i].codigo);
        printf("Ingrese el sueldo: ");
        scanf("%f", &trabajadores[i].sueldo);
        printf("Ingrese las horas trabajadas: ");
        scanf("%d", &trabajadores[i].horas_trabajadas);
        printf("\n");
    }
}

void consultarGenerales(struct Trabajador* trabajadores, int n) {
    for(int i = 0; i < n; i++){
        printf("Trabajador numero:%d\n", i+1);
        printf("Nombre: %s\n", trabajadores[i].nombre);
        printf("Codigo: %d\n", trabajadores[i].codigo);
        printf("Sueldo: %.2f\n", trabajadores[i].sueldo);
        printf("Horas Trabajadas: %d\n\n", trabajadores[i].horas_trabajadas);
    }
}

void consultarPorClave(struct Trabajador* trabajadores, int n, int cod) {
    for(int i = 0; i < n; i++){
        if(cod == trabajadores[i].codigo){
            printf("Nombre: %s || Codigo: %d || Sueldo: %.2f || Horas Trabajadas: %d \n", trabajadores[i].nombre, trabajadores[i].codigo, trabajadores[i].sueldo, trabajadores[i].horas_trabajadas);
        }
    }
}

void consultarPorNombre(struct Trabajador* trabajadores, int n, char* nombre) {
    for(int i = 0; i < n; i++){
        if(nombre == trabajadores[i].nombre){
            printf("Nombre: %s || Codigo: %d || Sueldo: %.2f || Horas Trabajadas: %d \n", trabajadores[i].nombre, trabajadores[i].codigo, trabajadores[i].sueldo, trabajadores[i].horas_trabajadas);
        }
    }
}