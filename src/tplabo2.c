/*
 ============================================================================
 Name        : tplabo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayemployees.h"
#define TAM 1000
#define FULL 1
#define EMPTY 0

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado listaEmpleados[TAM]; //{{123,"Juan Ignacio","Abal",8000,1},{456,"Sofia","Zorifo",8000,3},{789,"Marta","Beltran",8000,2}};

	initEmployees(listaEmpleados, TAM);
	Menu(listaEmpleados, TAM);


	return EXIT_SUCCESS;
}
