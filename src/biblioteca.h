/*
 * biblioteca.h
 *
 *  Created on: 19 sep. 2021
 *      Author: juani
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int IngresarOpcion(void);
/// @brief Solicita un número al usuario para utilizar como opción ingresada y lo devuelve.
/// @return Devuelve un entero.
float IngresarNumero(void);
/// @brief Solicita un número y lo devuelve.
/// @return Devuelve un flotante.
float Sumar(float numeroUno, float numeroDos);
/// @brief Suma dos números entre sí.
/// @param numeroUno Flotante.El primer número ingresado previamente.
/// @param numeroDos Flotante.El segundo número ingresado previamente.
/// @return Devuelve el resultado de la suma de ambos números como flotante.
float Restar(float numeroUno, float numeroDos);
/// @brief Resta dos números ingresados previamente entre sí.
/// @param numeroUno Flotante.El primer número ingresado previamente.
/// @param numeroDos Flotante.El segundo número ingresado previamente.
/// @return Devuelve el resultado de la resta de ambos números como flotante.
float Dividir(float numeroUno, float numeroDos, float *retResultado);
/// @brief Realiza la división entre dos números y devuelve si hubo error.
/// @param numeroUno Flotante.El primer número ingresado previamente.
/// @param numeroDos Flotante.El segundo número ingresado previamente.
/// @param retResultado asigna el valor del resultado de la división en una variable en el main.
/// @return Devuelve si hubo error o no (si el usuario ingresó cero en el segundo operando).
float Multiplicar(float numeroUno, float numeroDos);
/// @brief Realiza la multiplicación entre dos números previamente ingresados.
/// @param numeroUno Flotante.El primer número ingresado previamente.
/// @param numeroDos Flotante.El segundo número ingresado previamente.
/// @return Devuelve un flotante como resultado de la multiplicación entre numeroUno y numeroDos.
int SacarFactorial(int operando);
/// @brief Saca el factorial de un número previamente ingresado.
/// @param operando Entero. El número previamente ingresado.
/// @return Devuelve el factorial del operando como entero.

#endif /* BIBLIOTECA_H_ */
