/*
 * arrayemployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: juani
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#endif /* BIBLIOTECA_H_ */

#define TAM 4
#define FULL 1
#define EMPTY 0

typedef struct {
	int idEmpleado;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
} eEmpleado;

/// \fn eEmpleado IngresarUnEmpleado()
/// \brief La función le pide al usuario que ingrese un solo empleado (lo hará en la posición del array que se lo indique la funcioón CargarEmpleados cuando la llame).
/// \return Los datos de un solo empleado.
eEmpleado IngresarUnEmpleado();

/// \fn int CargarEmpleado(eEmpleado[], int, int, int*)
/// \brief Se encarga de llamar a la función IngresarUnEmpleado para pedir al usuario que ingrese los datos de un solo empleado. Indica en qué posición de la lista de empleados hacerlo.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \param bandera de tipo int. recibe la bandera de la funcion de menu opciones para verificar si es el primer empleado que se ingresa, se utiliza para la carga de id automática.
/// \param ultimoId de tipo int. Se utiliza como puntero para la carga de id automático. Primero recibe el valor que se le asigna en la función Menu, y luego le asigna el valor del último ID ingresado.
/// \return el valor de la variable index de la función. En caso de que la variable sea -1, significará que no encontró espacio libre y no se pudo cargar el empleado.
int CargarEmpleado(eEmpleado lista[], int tam, int bandera, int *ultimoId);

/// \fn void initEmployees(eEmpleado[], int)
/// \brief Esta funcion le asinga el valor EMPTY (0) a la variable (isEmpty) de la estructura eEmpleado en todas las posiciones del array.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void initEmployees(eEmpleado lista[], int tam);

/// \fn void MostrarUnEmpleado(eEmpleado)
/// \brief Se utiliza para mostrar un solo empleado cuando la llame la función MostrarEmpleados.
/// \param empleado de tipo eEmpleado. Se utiliza para acceder a las variables de la estructura de eEmpleado.
void MostrarUnEmpleado(eEmpleado empleado);

/// \fn void MostrarEmpleados(eEmpleado[], int)
/// \brief Se utiliza para mostrar todos los empleados en el array de la lista. La función recorre la lista y en cada posición que no esté vacía, muestra al empleado cargado.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void MostrarEmpleados(eEmpleado lista[], int tam);

/// \fn int BajaEmpleado(eEmpleado[], int)
/// \brief Se utiliza para dar de baja un empleado mediante el ID que proporcione el usuario.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna un 1 si se pudo borrar al empleado correctamente y un 0 si no se pudo.
int BajaEmpleado(eEmpleado lista[], int tam);

/// \fn int ModificarEmpleados(eEmpleado[], int)
/// \brief Se utiliza para modificar los datos de un empleado (nombre o apellido o salario o sector) mediante el ID que proporcione el usuario.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna un 1 si se pudo modificar el empleado y un 0 si no se pudo.
int ModificarEmpleados(eEmpleado lista[], int tam);

/// \fn int BuscarPrimerEspacioLibre(eEmpleado[], int)
/// \brief La función se encarga de buscar el primer espacio libre en la lista de empleados.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna un -1 si no pudo encontrar un espacio libre en la lista. Y si pudo encontrar un espacio libre retorna el indice de ese espacio.
int BuscarPrimerEspacioLibre(eEmpleado lista[], int tam);

/// \fn void OrdenarEmpleados(eEmpleado[], int)
/// \brief Ordena los empleados alfabéticamente por apellido y sector.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void OrdenarEmpleados(eEmpleado lista[], int tam);

/// \fn void MostrarEmpleadosOrdenados(eEmpleado[], int)
/// \brief La función llama a la función OrdenarEmpleados para que los ordene y se encarga de mostrar la lista de empleados ordenados.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void MostrarEmpleadosOrdenados(eEmpleado lista[], int tam);

/// \fn void Menu(eEmpleado[], int)
/// \brief La función se encarga de mostrar el menú de opciones disponibles para que el empleado seleccione qué desea realizar. Cuando el empleado selecciona una opción, se llama a la función necesaria para que el programa realice esa acción.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void Menu (eEmpleado lista[], int tam);

/// \fn int ValidarOpcion(eEmpleado[], int, int)
/// \brief La función se utiliza para validar que el empleado sólo pueda borrar, modificar, o mostrar la lista sólo si ya cargó un empleado.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param opcionElegida de tipo int. Recibe el valor de la opción que el empleado seleccionó en el menú.
/// \param bandera de tipo int. Se utilizar para verificar que sea el primer empleado que se está cargando
/// \return
int ValidarOpcion (eEmpleado lista[], int tam, int opcionElegida, int bandera);

/// \fn float SacarTotalSalarios(eEmpleado[], int)
/// \brief La función calcula el total de los salarios de todos los empleados en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna el total de los salarios.
float SacarTotalSalarios (eEmpleado lista[], int tam);

/// \fn float SacarPromedioSalarios(eEmpleado[], int)
/// \brief La función calcula el promedio de los salarios de todos los empleados en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna el promedio de los salarios.
float SacarPromedioSalarios (eEmpleado lista[], int tam);

/*/// \fn void MostrarTotalPromedioSalarios(eEmpleado[], int)
/// \brief La función muestra o imprime el total y el promedio de los salarios en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
void MostrarTotalPromedioSalarios(eEmpleado lista[], int tam);*/

/// \fn int ContarEmpleadosQueSuperenElPromedio(eEmpleado[], int)
/// \brief La función recorre el array de la lista de empleados y se encarga de contar cuántos empleados superan el promedio de salarios.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tamaño de la lista de empleados. Para pasarle el limite de iteraciones que deberá recorrer el for dentro de  la función.
/// \return Retorna la cantidad de empleados que superan el promedio de salarios.
int ContarEmpleadosQueSuperenElPromedio (eEmpleado lista[], int tam);

/// \fn int ValidarString(char[], int)
/// \brief La función se ecnarga de validar que el dato que introduzca el ususario sea un caracter.
/// \param str de tipo char. Recibe el array de caracteres para que lo recorra.
/// \param tam El tamaño del array de caracteres.
/// \return Retorna un 0 si no son todos caracteres y retorna un 1 si el array contiene todos caracteres.
int ValidarString (char str[], int tam);

//int ValidarNumero(char str[]);


/// \fn int IngresarEntero(char[])
/// \brief Se utiliza para que el usuario ingrese un dato de tipo entero.
/// \param mensaje Es el mensaje que se le va a mostrar el usuario.
/// \return Retorna el numero ingresado por el usuario.
int IngresarEntero(char mensaje[]);

/// \fn int getString(char[], char[], int)
/// \brief Se utiliza para que el usuario ingrese un dato de tipo string.
/// \param cadena El array de caracteres donde se asignará como valor el dato que ingrese el usuario.
/// \param mensaje El mensaje que se le va a mostrar el usuario.
/// \param tam El tamaño de caracteres que se podrán ingresar en el array.
/// \return Retorna si se pudo intgresar el mensaje o si no se pudo.
int getString(char cadena[], char mensaje[], int tam);

/// \fn float IngresarFlotante(char[])
/// \brief Se utiliza para que el usuario ingrese un dato de tipo flotante.
/// \param mensaje El mensaje que se le va a mostrar el usuario.
/// \return Retorna el número ingresado.
float IngresarFlotante(char mensaje[]);



