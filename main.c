#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    int opc=0, opc2=0;
    int posnombre=0, posnotas=0;

    do
    {
        opc=menu();
        switch (opc)
        {
            case 1:
                ingresarAlumno();
            case 2:
                mostrarAlumnos();
                break;
            case 3:
                char nombre[20];
                printf("Ingrese el nombre a buscar: ");
                fflush(stdin);
                fgets(nombre,20,stdin);
                int len = strlen(nombre) - 1;
                nombre[len]='\0';
                buscarAlumno(nombre,&posnombre,&posnotas);
                break;
            case 4:
                printf("Ingrese el nombre a buscar: ");
                fflush(stdin);
                fgets(nombre,20,stdin);
                len = strlen(nombre) - 1;
                nombre[len]='\0';
                buscarAlumno(nombre,&posnombre,&posnotas);
                editarAlumno(posnombre,posnotas);
                break;
        default:
            break;
        }
        printf("Desea otra opcion: 1.Si 2.No\n");
        scanf("%d", &opc2);
    } while (opc2==1);

    return 0;
}