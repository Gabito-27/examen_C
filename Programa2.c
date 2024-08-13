#include <stdio.h>
#include <string.h>

struct Estudiante {
    int carnet;
    char nombre[50];
    char grado[20];
    char departamento[30];
    int edad;
};

void registrarEstudiante(struct Estudiante estudiantes[], int *numEstudiantes);
void buscarEstudiante(struct Estudiante estudiantes[], int numEstudiantes, int carnet);
void listaEstudiantesPorGrado(struct Estudiante estudiantes[], int numEstudiantes, char grado[]);
void editarEstudiante(struct Estudiante estudiantes[], int numEstudiantes, int carnet);
int main() {
    struct Estudiante estudiantes[100];
    int numEstudiantes = 0;
    int opcion, carnet;
    char grado[20];

    do {
        printf("\nOpciones:\n");
        printf("1. Registrar estudiante\n");
        printf("2. Buscar estudiante por carnet\n");
        printf("3. Lista de estudiantes por grado\n");
        printf("4. Editar un estudiante\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarEstudiante(estudiantes, &numEstudiantes);
                break;
            case 2:
                printf("Ingrese el carnet a buscar: ");
                scanf("%d", &carnet);
                buscarEstudiante(estudiantes, numEstudiantes, carnet);
                break;
            case 3:
                printf("Ingrese el grado a listar: ");
                scanf("%s", grado);
                listaEstudiantesPorGrado(estudiantes, numEstudiantes, grado);
                break;
            case 4:
                printf("Ingrese el carnet del estudiante a editar: ");
                scanf("%d", &carnet);
                editarEstudiante(estudiantes, numEstudiantes, carnet);
                break;
            case 5:
                printf("Usted salio del programa\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

void registrarEstudiante(struct Estudiante estudiantes[], int *numEstudiantes) {
    printf("Ingrese el numero de carnet: ");
    scanf("%d", &estudiantes[*numEstudiantes].carnet);
    printf("Ingrese el nombre: ");
    scanf("%s", estudiantes[*numEstudiantes].nombre);
    printf("Ingrese el grado: ");
    scanf("%s", estudiantes[*numEstudiantes].grado);
    printf("Ingrese el departamento: ");
    scanf("%s", estudiantes[*numEstudiantes].departamento);
    printf("Ingrese la edad: ");
    scanf("%d", &estudiantes[*numEstudiantes].edad);
    
    (*numEstudiantes)++;
}

void buscarEstudiante(struct Estudiante estudiantes[], int numEstudiantes, int carnet) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].carnet == carnet) {
            printf("Estudiante encontrado:\n");
            printf("Nombre: %s\n", estudiantes[i].nombre);
            printf("Grado: %s\n", estudiantes[i].grado);
            printf("Departamento: %s\n", estudiantes[i].departamento);
            printf("Edad: %d\n", estudiantes[i].edad);
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

void listaEstudiantesPorGrado(struct Estudiante estudiantes[], int numEstudiantes, char grado[]) {
    printf("Estudiantes en el grado %s:\n", grado);
    for (int i = 0; i < numEstudiantes; i++) {
        if (strcmp(estudiantes[i].grado, grado) == 0) {
            printf("Nombre: %s, Carnet: %d\n", estudiantes[i].nombre, estudiantes[i].carnet);
        }
    }
}

void editarEstudiante(struct Estudiante estudiantes[], int numEstudiantes, int carnet) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].carnet == carnet) {
            printf("Ingrese el nuevo nombre: ");
            scanf("%s", estudiantes[i].nombre);
            printf("Ingrese el nuevo grado: ");
            scanf("%s", estudiantes[i].grado);
            printf("Ingrese el nuevo departamento: ");
            scanf("%s", estudiantes[i].departamento);
            printf("Ingrese la nueva edad: ");
            scanf("%d", &estudiantes[i].edad);
            printf("Estudiante editado exitosamente.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}
