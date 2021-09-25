/*
 * biblioteca.c
 *
 *  Created on: 19 sep. 2021
 *      Author: juani
 */
#include "biblioteca.h"
#include <stdio.h>

int IngresarOpcion(void) {

	int opcion;

	printf("Ingrese la opcion que desea realizar (1,2,3,4,5) : ");
	scanf("%d", &opcion);

	while (opcion < 1 || opcion > 5) {
		printf("Error ingrese la opcion nuevamente (1,2,3,4,5): ");
		scanf("%d", &opcion);
	}
	return opcion;
}
float IngresarNumero(void) {

	float numeroIngresado;

	printf("Ingrese operando: ");
	scanf("%f", &numeroIngresado);

	return (numeroIngresado);
}

float Sumar(float numeroUno, float numeroDos) {

	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}
float Restar(float numeroUno, float numeroDos) {

	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
float Dividir(float numeroUno, float numeroDos, float *retResultado) {

	int huboError;

	if (numeroDos == 0) {
		huboError = 1;
	} else {

		*retResultado = numeroUno / numeroDos;
		huboError = 0;
	}
	return huboError;
}

float Multiplicar(float numeroUno, float numeroDos) {

	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}
int SacarFactorial(int operando){

	int resultado;

	if(operando == 0){
		resultado = 1;
	}
	else{
		resultado = operando * SacarFactorial(operando - 1);
	}
	return resultado;
}
