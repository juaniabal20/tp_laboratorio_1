/*
 * biblioteca.h
 *
 *  Created on: 19 sep. 2021
 *      Author: juani
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int IngresarOpcion(void);
/// @brief Solicita un n�mero al usuario para utilizar como opci�n ingresada y lo devuelve.
/// @return Devuelve un entero.
float IngresarNumero(void);
/// @brief Solicita un n�mero y lo devuelve.
/// @return Devuelve un flotante.
float Sumar(float numeroUno, float numeroDos);
/// @brief Suma dos n�meros entre s�.
/// @param numeroUno Flotante.El primer n�mero ingresado previamente.
/// @param numeroDos Flotante.El segundo n�mero ingresado previamente.
/// @return Devuelve el resultado de la suma de ambos n�meros como flotante.
float Restar(float numeroUno, float numeroDos);
/// @brief Resta dos n�meros ingresados previamente entre s�.
/// @param numeroUno Flotante.El primer n�mero ingresado previamente.
/// @param numeroDos Flotante.El segundo n�mero ingresado previamente.
/// @return Devuelve el resultado de la resta de ambos n�meros como flotante.
float Dividir(float numeroUno, float numeroDos, float *retResultado);
/// @brief Realiza la divisi�n entre dos n�meros y devuelve si hubo error.
/// @param numeroUno Flotante.El primer n�mero ingresado previamente.
/// @param numeroDos Flotante.El segundo n�mero ingresado previamente.
/// @param retResultado asigna el valor del resultado de la divisi�n en una variable en el main.
/// @return Devuelve si hubo error o no (si el usuario ingres� cero en el segundo operando).
float Multiplicar(float numeroUno, float numeroDos);
/// @brief Realiza la multiplicaci�n entre dos n�meros previamente ingresados.
/// @param numeroUno Flotante.El primer n�mero ingresado previamente.
/// @param numeroDos Flotante.El segundo n�mero ingresado previamente.
/// @return Devuelve un flotante como resultado de la multiplicaci�n entre numeroUno y numeroDos.
int SacarFactorial(int operando);
/// @brief Saca el factorial de un n�mero previamente ingresado.
/// @param operando Entero. El n�mero previamente ingresado.
/// @return Devuelve el factorial del operando como entero.

#endif /* BIBLIOTECA_H_ */
