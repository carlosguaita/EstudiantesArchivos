#include <stdio.h>
#include <string.h>


int menu(){
    int opcion;
    printf("1. Ingresar alumno\n");
    printf("2. Mostrar alumnos\n");
    printf("3. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void ingresarAlumno(char nombre[][20], int edad[], int i, FILE *fnombres, FILE *fdatos){
    float n1,n2,n3;
    printf("Ingrese el nombre del alumno: ");
    fgets(nombre[i],20,stdin);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &edad[i]);
    printf("Ingrese la nota 1: ");
    scanf("%f", &n1);
    printf("Ingrese la nota 2: ");
    scanf("%f", &n2);
    printf("Ingrese la nota 3: ");
    scanf("%f", &n3);
    fputs(nombre[i], fnombres);
    fprintf(fdatos, "%d %f %f %f\n", edad[i],n1,n2,n3);
}

void mostrarAlumnos(char nombre[][20], int edad[], int i, FILE *fnombres, FILE *fdatos){
    int j=0;
    float n1, n2, n3;
    printf("Nombre\t\tEdad\t\tNota1\t\tNota2\t\tNota3\n");
    while(!feof(fnombres)){
        fgets(nombre[j],20,fnombres);
        fscanf(fdatos, "%d %f %f %f\n", &edad[j],&n1,&n2,&n3);
        printf("%s\t\t%d\t\t%f\t\t%f\t\t%f\n", nombre[j], edad[j], n1, n2, n3);
        j++;
    }
}
