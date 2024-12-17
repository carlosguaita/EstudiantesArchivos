#include "funciones.h"

int main (int argc, char *argv[]) {

    int opc=0, opc2=0;
    int i=0;
    char nombre[5][20];
    int edad[5];
    FILE *fnombres = fopen("nombres.txt", "a+");
    FILE *fdatos = fopen("datos.txt", "a+");
    do
    {
        opc=menu();
        switch (opc)
        {
            case 1:
                ingresarAlumno(nombre, edad, i, fnombres, fdatos);
                i++;
            case 2:
                mostrarAlumnos(nombre, edad, i, fnombres, fdatos);
                break;
        default:
            break;
        }
        printf("Desea otra opcion: 1.Si 2.No\n");
        scanf("%d", &opc2);
    } while (opc2==1);
    fclose(fnombres);
    fclose(fdatos);
    return 0;
}