/*
 * arrayemployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: juani
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayemployees.h"


int IngresarEntero(char mensaje[]) {
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
float IngresarFlotante(char mensaje[]) {
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
int getString(char cadena[], char mensaje[], int tam) {
	char auxiliarString[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL) {
		retorno = 1;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);

		while (strlen(auxiliarString) > tam) {
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(cadena, auxiliarString);
	}
	return retorno;
}
eEmpleado IngresarUnEmpleado() {

	eEmpleado empleado;
	int lenNombre;
	int lenApellido;
	char nombre[51];
	char apellido[51];
	int retValidacionString;
	//int retValidacionNumero;
	//char salario[10];
	//char sector[10];

	getString(empleado.nombre, "Ingrese el nombre del empleado: ", 51);
	lenNombre = strlen(empleado.nombre);
	snprintf(nombre, sizeof(nombre), "%s", empleado.nombre);
	retValidacionString = ValidarString(nombre, lenNombre);
	while (retValidacionString == 0) {
		getString(empleado.nombre, "\nERROR. Ingrese el nombre del empleado: ",
				51);
		lenNombre = strlen(empleado.nombre);
		snprintf(nombre, sizeof(nombre), "%s", empleado.nombre);
		retValidacionString = ValidarString(nombre, lenNombre);
	}

	getString(empleado.apellido, "Ingrese el apellido del empleado: ", 51);
	lenApellido = strlen(empleado.apellido);
	snprintf(apellido, sizeof(apellido), "%s", empleado.apellido);
	retValidacionString = ValidarString(apellido, lenApellido);
	while (retValidacionString == 0) {
		getString(empleado.apellido,
				"\nERROR. Ingrese el apellido del empleado: ", 51);
		lenApellido = strlen(empleado.apellido);
		snprintf(apellido, sizeof(apellido), "%s", empleado.apellido);
		retValidacionString = ValidarString(apellido, lenApellido);
	}

	empleado.salario = IngresarFlotante("Ingrese el salario del empleado: ");
	/*itoa(empleado.salario, salario, 10);
	retValidacionNumero = ValidarNumero(salario);
	while (retValidacionNumero == 1) {
		empleado.salario = IngresarFlotante("ERROR. Ingrese el salario del empleado: ");
		itoa(empleado.salario, salario, 10);
		retValidacionNumero = ValidarNumero(salario);
	}*/

	empleado.sector = IngresarEntero(" Ingrese el sector del empleado: ");
	/*itoa(empleado.sector, sector, 10);
	retValidacionNumero = ValidarNumero(sector);
	while (retValidacionNumero == 1) {
		empleado.sector = IngresarEntero("ERROR.Ingrese el sector del empleado: ");
		itoa(empleado.sector, sector, 10);
		retValidacionNumero = ValidarNumero(sector);
	}*/

	empleado.isEmpty = FULL;

	return empleado;
}
int ValidarString(char str[], int tam) {
	int i;
	int retValidacion;

	for (i = 0; i < tam; i++) {
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < 'A' || str[i] > 'Z')) {
			retValidacion = 0;
		} else {
			retValidacion = 1;
		}

	}
	return retValidacion;
}
/*int ValidarNumero(char str[]) {
	int i;
	int j;
	int retValidacion = 0;

	j=strlen(str);
	while(i<j && retValidacion==0)
	{
		if(isdigit(str[i])!=0)
		{
			i++;
		}
		else
		{
			retValidacion=1;
		}
	}
	return retValidacion;
}*/

int CargarEmpleado(eEmpleado lista[], int tam, int bandera, int *ultimoId) {

	int i;
	int index;
	index = BuscarPrimerEspacioLibre(lista, tam);

	for (i = 0; i < tam; i++) {
		if (index != -1 && bandera == 1) {
			lista[index] = IngresarUnEmpleado();
			lista[index].idEmpleado = 1;
			break;
		} else if (index != -1 && bandera == 0) {
			lista[index] = IngresarUnEmpleado();
			lista[index].idEmpleado = *ultimoId + 1;
			*ultimoId = lista[index].idEmpleado;
			break;
		}
	}

	return index;
}
int BuscarPrimerEspacioLibre(eEmpleado lista[], int tam) {
	int i;
	int index;

	index = -1;
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == EMPTY) {
			index = i;
			break;
		}
	}
	return index;
}
void initEmployees(eEmpleado lista[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		lista[i].isEmpty = EMPTY;
	}
}

void MostrarEmpleados(eEmpleado lista[], int tam) {
	int i;

	printf("\nId\tNombre\t\tApellido\tSalario\t\tSector\n");
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL) {

			MostrarUnEmpleado(lista[i]);
		} else {
			printf("La lista esta vacia.\n");
		}
	}
}
void MostrarUnEmpleado(eEmpleado empleado) {
	printf("%d %15s %15s %15.2f %10d \n", empleado.idEmpleado, empleado.nombre,
			empleado.apellido, empleado.salario, empleado.sector);

}
int BajaEmpleado(eEmpleado lista[], int tam) {
	int i;
	int empleadoBaja;
	int auxiliarBajaEmpleado = 0;

	MostrarEmpleados(lista, tam);

	empleadoBaja = IngresarEntero(
			"Seleccione el ID del empleado que desa borrar: ");

	for (i = 0; i < tam; i++) {
		if (lista[i].idEmpleado == empleadoBaja && lista[i].isEmpty == FULL) {
			lista[i].isEmpty = EMPTY;
			auxiliarBajaEmpleado = 1;
			break;
		}
	}
	return auxiliarBajaEmpleado;
}
int ModificarEmpleados(eEmpleado lista[], int tam) {
	int i;
	int empleadoModificado;
	int auxiliarEmpleadoModificado = 0;
	int opcion;

	MostrarEmpleados(lista, tam);
	empleadoModificado = IngresarEntero(
			"Seleccione el ID del empleado que desa modificar: ");

	for (i = 0; i < tam; i++) {
		if (lista[i].idEmpleado
				== empleadoModificado&& lista[i].isEmpty == FULL) {

			do {
				opcion =
						IngresarEntero(
								"Opciones de modificacion de empleado:\n1- Nombre.\n2- Apellido.\n3- Salario.\n4- Sector.\n5- Terminar.\n");
				switch (opcion) {
				case 1:
					getString(lista[i].nombre,
							"Ingrese el nombre del empleado: ", 51);
					break;
				case 2:
					getString(lista[i].apellido,
							"Ingrese el apellido del empleado: ", 51);
					break;
				case 3:
					lista[i].salario = IngresarFlotante(
							"Ingrese el salario del empleado: ");
					break;
				case 4:
					lista[i].sector = IngresarEntero(
							"Ingrese el sector del empleado: ");
					break;
				case 5:
					printf(
							"Usted seleccionó 'terminar'. Será dirigido al menú anterior.\n");
				}
			} while (opcion != 5);

			auxiliarEmpleadoModificado = 1;
		}
	}
	return auxiliarEmpleadoModificado;
}
void OrdenarEmpleados(eEmpleado lista[], int tam) {
	int i;
	int j;
	int auxiliarSector;
	char auxiliarNombre[51];
	int auxiliarId;
	int auxiliarSalario;
	char auxiliarApellido[51];

	for (i = 0; i < tam; i++) {
		for (j = i + 1; j < tam; j++) {
			if ((strcmp(lista[i].apellido, lista[j].apellido) > 0)
					&& (lista[i].sector > lista[j].sector)) {
				auxiliarSector = lista[i].sector;
				lista[i].sector = lista[j].sector;
				lista[j].sector = auxiliarSector;

				auxiliarSalario = lista[i].salario;
				lista[i].salario = lista[j].salario;
				lista[j].salario = auxiliarSalario;

				auxiliarId = lista[i].idEmpleado;
				lista[i].idEmpleado = lista[j].idEmpleado;
				lista[j].idEmpleado = auxiliarId;

				strcpy(auxiliarNombre, lista[i].nombre);
				strcpy(lista[i].nombre, lista[j].nombre);
				strcpy(lista[j].nombre, auxiliarNombre);

				strcpy(auxiliarApellido, lista[i].apellido);
				strcpy(lista[i].apellido, lista[j].apellido);
				strcpy(lista[j].apellido, auxiliarApellido);

			}
		}
	}

}
void MostrarEmpleadosOrdenados(eEmpleado lista[], int tam) {

	int i;

	OrdenarEmpleados(lista, tam);

	printf("\nId\tNombre\t\tApellido\tSalario\t\tSector\n");
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL) {

			MostrarUnEmpleado(lista[i]);
		} else {
			printf("La lista esta vacia.\n");
		}
	}

}
void Menu(eEmpleado lista[], int tam) {
	int retCargarEmpleado;
	int retBajaEmpleado;
	int retModificarEmpleado;
	int opcion;
	int retValidarOpcion;
	int flag = 1;
	int ultimoIdEmpleado = 1;
	float totalSalarios;
	float promedioSalarios;
	int empleadosArribaDelPromedio;

	do {
		opcion =
				IngresarEntero(
						"\n1- Ingresar empleado\n2- Modificar empleado\n3- Borrar empleado\n4- Mostrar lista de empleados\n5- Salir "
								"\nIngrese la opcion que desea seleccionar:  ");
		retValidarOpcion = ValidarOpcion(lista, tam, opcion, flag);
		while (retValidarOpcion == 0) {
			opcion =
					IngresarEntero(
							"\nERROR. Primero debe cargar un empleado.\n\n1- Ingresar empleado\n2- Modificar empleado\n3- Borrar empleado\n4- Mostrar lista de empleados\n5- Salir "
									"\nIngrese la opcion que desea seleccionar:  ");
			retValidarOpcion = ValidarOpcion(lista, tam, opcion, flag);
		}
		switch (opcion) {
		case 1:
			retCargarEmpleado = CargarEmpleado(lista, tam, flag, &ultimoIdEmpleado);
			if (retCargarEmpleado != -1) {
				printf("El empleado se cargó correctamente.\n");
				flag = 0;
			} else {
				printf("El empleado no se pudo cargar correctamente.\n");
			}
			break;
		case 2:
			retModificarEmpleado = ModificarEmpleados(lista, tam);
			if (retModificarEmpleado == 1) {
				printf("El empleado se modificó correctamente.\n");
			} else {
				printf("El empleado no se pudo modificar.\n");
			}
			break;
		case 3:
			retBajaEmpleado = BajaEmpleado(lista, tam);
			if (retBajaEmpleado == 1) {
				printf("El empleado se borro correctamente.\n");
			} else {
				printf("El empleado no se pudo borrar.\n");
			}
			break;
		case 4:
			MostrarEmpleados(lista, tam);
			printf("\nLista empleados ordenados: \n");
			MostrarEmpleadosOrdenados(lista, tam);
			totalSalarios = SacarTotalSalarios(lista, tam);
			printf("\nEl total de los salarios es: %.2f\n", totalSalarios);
			promedioSalarios = SacarPromedioSalarios(lista, tam);
			printf("\nEl promedio de los salarios es: %.2f\n",
					promedioSalarios);
			empleadosArribaDelPromedio = ContarEmpleadosQueSuperenElPromedio(
					lista, tam);
			printf(
					"\nLa cantidad de empleados que superan el promedio es de: %d\n",
					empleadosArribaDelPromedio);
			break;
		case 5:
			printf("Usted seleccionó 'Salir'. El programa finalizó.");
			break;
		}
	} while (opcion != 5);
}
int ValidarOpcion(eEmpleado lista[],int tam, int opcionElegida, int bandera) {
	int retOpcion;
	int i;
	int auxiliar;

	for (i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==FULL)
		{
			auxiliar=1;
			break;
		}
		else
		{
			auxiliar=0;

		}
	}
	if((opcionElegida == 2 || opcionElegida == 3 || opcionElegida == 4) && (auxiliar == 0))
	 {
		retOpcion = 0;
	}
	else if(opcionElegida==1 && auxiliar==0)
	{
		retOpcion = 1;
	}

	return retOpcion;
	//if
}
float SacarTotalSalarios(eEmpleado lista[], int tam) {
	int i;
	float acumuladorSalarios = 0;
	float salario;

	for (i = 0; i < tam; i++) {
		salario = lista[i].salario;

		if (lista[i].isEmpty == FULL) {

			acumuladorSalarios = salario + acumuladorSalarios;
		}
	}
	return acumuladorSalarios;
}
float SacarPromedioSalarios(eEmpleado lista[], int tam) {
	int i;
	float totalSalarios;
	float promedioSalarios;
	int contadorEmpleados = 0;

	totalSalarios = SacarTotalSalarios(lista, tam);

	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL) {
			contadorEmpleados++;
		}
	}
	promedioSalarios = totalSalarios / contadorEmpleados;

	return promedioSalarios;
}
int ContarEmpleadosQueSuperenElPromedio(eEmpleado lista[], int tam) {
	int i;
	int contadorEmpleados = 0;
	float promedioSalarios;

	promedioSalarios = SacarPromedioSalarios(lista, tam);

	for (i = 0; i < tam; i++) {
		if (lista[i].salario > promedioSalarios && lista[i].isEmpty == FULL) {
			contadorEmpleados++;
		}
	}

	return contadorEmpleados;
}
/*void MostrarTotalPromedioSalarios(eEmpleado lista[], int tam)
 {
 float totalSalarios;
 float promedioSalarios;

 totalSalarios = SacarPromedioSalarios(lista, tam);
 promedioSalarios = SacarPromedioSalarios(lista, tam);

 printf("\nEl total de los salarios de todos los empleados es: %.2f\n", totalSalarios);
 printf("\nEl promedio de los salarios de los empleados es de: %.2f\n", promedioSalarios);
 }*/


