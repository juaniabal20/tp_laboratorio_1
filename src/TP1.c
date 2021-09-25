/*
 ============================================================================
 Name        : TP1.c
 Author      : Juan Ignacio Abal
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	float operandoUno;
	float operandoDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int resultadoFactorial1;
	int resultadoFactorial2;
	float retDivision;

	do {
		printf("Opcion 1: Ingresar primer operando (A=%.2f).\n"
				"Opcion 2: Ingresar segundo operando (B=%.2f).\n"
				"Opcion 3: Realizar todos los calculos.\n"
				"Opcion 4: Visualizar el resultado de los calculos.\n"
				"Opcion 5: Salir.\n\n", operandoUno, operandoDos);
		opcion = IngresarOpcion();

		switch (opcion) {
		case 1:
			operandoUno = IngresarNumero();
			printf("primer operando= %.2f\n\n", operandoUno);
			break;
		case 2:
			operandoDos = IngresarNumero();
			printf("Segundo operando= %.2f\n\n", operandoDos);
			break;
		case 3:
			resultadoSuma = Sumar(operandoUno, operandoDos);
			resultadoResta = Restar(operandoUno, operandoDos);
			resultadoDivision = Dividir(operandoUno, operandoDos, &retDivision);
			resultadoMultiplicacion = Multiplicar(operandoUno, operandoDos);
			resultadoFactorial1= SacarFactorial(operandoUno);
			resultadoFactorial2= SacarFactorial(operandoDos);
			printf(
					"Las operaciones fueron realizadas, seleccione opcion 4 para visualizar los resultados.\n\n");
			break;
		case 4:
			printf("El resultado de %.2f + %.2f es: %.2f\n", operandoUno, operandoDos,
					resultadoSuma);
			printf("El resultado de %.2f - %.2f es: %.2f\n", operandoUno, operandoDos,
					resultadoResta);
			if (resultadoDivision == 0) {
				printf("El resultado de %.2f / %.2f es: %.2f\n", operandoUno,
						operandoDos, retDivision);
			} else {
				printf("No es posible dividir por cero\n");
			}
			printf("El resultado de %.2f * %.2f es: %.2f\n", operandoUno, operandoDos,
					resultadoMultiplicacion);
			printf("El factorial de %.2f es: %d y El factorial de %.2f es: %d\n\n", operandoUno, resultadoFactorial1, operandoDos, resultadoFactorial2);
			break;
		case 5:
			printf("Usted selecciono 'Salir'. Programa finalizado.");
			break;
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}



