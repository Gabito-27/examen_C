#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresarDepartamentos(int numDepartamentos);
void mostrarDepartamentosOrdenados();
int main() {
    int numDepartamentos;

    printf("Ingrese cuantos departamentos desea ingresar: ");
    scanf("%d", &numDepartamentos);

    ingresarDepartamentos(numDepartamentos);
    mostrarDepartamentosOrdenados();

    return 0;
}

void ingresarDepartamentos(int numDepartamentos) {
    FILE *archivo;
    archivo = fopen("departamentos.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    char departamento[50];

    for (int i = 0; i < numDepartamentos; i++) {
        printf("Ingrese el nombre del departamento %d: ", i + 1);
        scanf("%s", departamento);
        fprintf(archivo, "%s\n", departamento);
    }

    fclose(archivo);
}

void mostrarDepartamentosOrdenados() {
    FILE *archivo;
    archivo = fopen("departamentos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    char departamentos[100][50];
    int numDepartamentos = 0;

    while (fscanf(archivo, "%s", departamentos[numDepartamentos]) != EOF) {
        numDepartamentos++;
    }

    for (int i = 0; i < numDepartamentos; i++) {
        for (int j = i + 1; j < numDepartamentos; j++) {
            if (strcmp(departamentos[i], departamentos[j]) < 0) {
                char temp[50];
                strcpy(temp, departamentos[i]);
                strcpy(departamentos[i], departamentos[j]);
                strcpy(departamentos[j], temp);
            }
        }
    }

    printf("Departamentos ordenados de Z a A:\n");
    for (int i = 0; i < numDepartamentos; i++) {
        printf("%s\n", departamentos[i]);
    }

    fclose(archivo);
}