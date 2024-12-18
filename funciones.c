#include <stdio.h>
#include <string.h>
#include "funciones.h"


int menu(){
    int opcion;
    printf("1. Ingresar alumno\n");
    printf("2. Mostrar alumnos\n");
    printf("3. Buscar alumno por Nombre\n");
    printf("4. Editar alumno\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void ingresarAlumno(){
    float n1,n2,n3;
    char nombre[20];
    int edad;
    FILE *fnombres = fopen("nombres.txt", "a+");
    FILE *fdatos = fopen("datos.txt", "a+");
    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    fgets(nombre,20,stdin);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &edad);
    printf("Ingrese la nota 1: ");
    scanf("%f", &n1);
    printf("Ingrese la nota 2: ");
    scanf("%f", &n2);
    printf("Ingrese la nota 3: ");
    scanf("%f", &n3);
    fputs(nombre, fnombres);
    fprintf(fdatos, "%d %f %f %f\n", edad,n1,n2,n3);
    fclose(fnombres);
    fclose(fdatos);
}

void mostrarAlumnos(){
    float n1, n2, n3;
    char nombre[20];
    int edad;
    FILE *fnombres = fopen("nombres.txt", "a+");
    FILE *fdatos = fopen("datos.txt", "a+");
    printf("Nombre\t\tEdad\t\tNota1\t\tNota2\t\tNota3\n");
    while(!feof(fnombres)){
        fgets(nombre,20,fnombres);
        int len = strlen(nombre) -1;
        nombre[len]='\0';
        fscanf(fdatos, "%d %f %f %f\n", &edad,&n1,&n2,&n3);
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", nombre, edad, n1, n2, n3);
    }
    fclose(fnombres);
    fclose(fdatos);
}

void buscarAlumno(char nombreBuscar[], int *posicionNombres, int *posicionNotas){
    float n1, n2, n3;
    char nombre[20];
    int edad;
    FILE *fnombres = fopen("nombres.txt", "a+");
    FILE *fdatos = fopen("datos.txt", "a+");
    while(!feof(fnombres)){
        fgets(nombre,20,fnombres);
        int len = strlen(nombre) -1;
        nombre[len]='\0';
        fscanf(fdatos, "%d %f %f %f\n", &edad,&n1,&n2,&n3);
        if (strcmp(nombre,nombreBuscar)==0)
        {
            printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", nombre, edad, n1, n2, n3);
            break;
        }
        *posicionNombres=ftell(fnombres);
        *posicionNotas=ftell(fdatos);
    }
    fclose(fnombres);
    fclose(fdatos);
}

void editarAlumno(int posicionNombres, int posicionNotas){

    float n1,n2,n3;
    char nombre[20];
    int edad;
    FILE *fnombres = fopen("nombres.txt", "r+");
    FILE *fdatos = fopen("datos.txt", "r+");
    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    fgets(nombre,20,stdin);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &edad);
    printf("Ingrese la nota 1: ");
    scanf("%f", &n1);
    printf("Ingrese la nota 2: ");
    scanf("%f", &n2);
    printf("Ingrese la nota 3: ");
    scanf("%f", &n3);
    fseek(fnombres,posicionNombres,0);
    fputs(nombre, fnombres);
    fseek(fdatos,posicionNotas,0);
    fprintf(fdatos, "%d %f %f %f\n", edad,n1,n2,n3);
    fclose(fnombres);
    fclose(fdatos);

}
