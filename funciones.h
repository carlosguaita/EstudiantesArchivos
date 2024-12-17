#include <stdio.h>

int menu();
void ingresarAlumno(char nombre[][20], int edad[], int i, FILE *fnombres, FILE *fdatos);
void mostrarAlumnos(char nombre[][20], int edad[], int i, FILE *fnombres, FILE *fdatos);