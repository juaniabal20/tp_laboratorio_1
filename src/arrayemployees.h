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
/// \brief La funci�n le pide al usuario que ingrese un solo empleado (lo har� en la posici�n del array que se lo indique la funcio�n CargarEmpleados cuando la llame).
/// \return Los datos de un solo empleado.
eEmpleado IngresarUnEmpleado();

/// \fn int CargarEmpleado(eEmpleado[], int, int, int*)
/// \brief Se encarga de llamar a la funci�n IngresarUnEmpleado para pedir al usuario que ingrese los datos de un solo empleado. Indica en qu� posici�n de la lista de empleados hacerlo.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \param bandera de tipo int. recibe la bandera de la funcion de menu opciones para verificar si es el primer empleado que se ingresa, se utiliza para la carga de id autom�tica.
/// \param ultimoId de tipo int. Se utiliza como puntero para la carga de id autom�tico. Primero recibe el valor que se le asigna en la funci�n Menu, y luego le asigna el valor del �ltimo ID ingresado.
/// \return el valor de la variable index de la funci�n. En caso de que la variable sea -1, significar� que no encontr� espacio libre y no se pudo cargar el empleado.
int CargarEmpleado(eEmpleado lista[], int tam, int bandera, int *ultimoId);

/// \fn void initEmployees(eEmpleado[], int)
/// \brief Esta funcion le asinga el valor EMPTY (0) a la variable (isEmpty) de la estructura eEmpleado en todas las posiciones del array.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void initEmployees(eEmpleado lista[], int tam);

/// \fn void MostrarUnEmpleado(eEmpleado)
/// \brief Se utiliza para mostrar un solo empleado cuando la llame la funci�n MostrarEmpleados.
/// \param empleado de tipo eEmpleado. Se utiliza para acceder a las variables de la estructura de eEmpleado.
void MostrarUnEmpleado(eEmpleado empleado);

/// \fn void MostrarEmpleados(eEmpleado[], int)
/// \brief Se utiliza para mostrar todos los empleados en el array de la lista. La funci�n recorre la lista y en cada posici�n que no est� vac�a, muestra al empleado cargado.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void MostrarEmpleados(eEmpleado lista[], int tam);

/// \fn int BajaEmpleado(eEmpleado[], int)
/// \brief Se utiliza para dar de baja un empleado mediante el ID que proporcione el usuario.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna un 1 si se pudo borrar al empleado correctamente y un 0 si no se pudo.
int BajaEmpleado(eEmpleado lista[], int tam);

/// \fn int ModificarEmpleados(eEmpleado[], int)
/// \brief Se utiliza para modificar los datos de un empleado (nombre o apellido o salario o sector) mediante el ID que proporcione el usuario.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna un 1 si se pudo modificar el empleado y un 0 si no se pudo.
int ModificarEmpleados(eEmpleado lista[], int tam);

/// \fn int BuscarPrimerEspacioLibre(eEmpleado[], int)
/// \brief La funci�n se encarga de buscar el primer espacio libre en la lista de empleados.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna un -1 si no pudo encontrar un espacio libre en la lista. Y si pudo encontrar un espacio libre retorna el indice de ese espacio.
int BuscarPrimerEspacioLibre(eEmpleado lista[], int tam);

/// \fn void OrdenarEmpleados(eEmpleado[], int)
/// \brief Ordena los empleados alfab�ticamente por apellido y sector.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void OrdenarEmpleados(eEmpleado lista[], int tam);

/// \fn void MostrarEmpleadosOrdenados(eEmpleado[], int)
/// \brief La funci�n llama a la funci�n OrdenarEmpleados para que los ordene y se encarga de mostrar la lista de empleados ordenados.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void MostrarEmpleadosOrdenados(eEmpleado lista[], int tam);

/// \fn void Menu(eEmpleado[], int)
/// \brief La funci�n se encarga de mostrar el men� de opciones disponibles para que el empleado seleccione qu� desea realizar. Cuando el empleado selecciona una opci�n, se llama a la funci�n necesaria para que el programa realice esa acci�n.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void Menu (eEmpleado lista[], int tam);

/// \fn int ValidarOpcion(eEmpleado[], int, int)
/// \brief La funci�n se utiliza para validar que el empleado s�lo pueda borrar, modificar, o mostrar la lista s�lo si ya carg� un empleado.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param opcionElegida de tipo int. Recibe el valor de la opci�n que el empleado seleccion� en el men�.
/// \param bandera de tipo int. Se utilizar para verificar que sea el primer empleado que se est� cargando
/// \return
int ValidarOpcion (eEmpleado lista[], int tam, int opcionElegida, int bandera);

/// \fn float SacarTotalSalarios(eEmpleado[], int)
/// \brief La funci�n calcula el total de los salarios de todos los empleados en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna el total de los salarios.
float SacarTotalSalarios (eEmpleado lista[], int tam);

/// \fn float SacarPromedioSalarios(eEmpleado[], int)
/// \brief La funci�n calcula el promedio de los salarios de todos los empleados en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna el promedio de los salarios.
float SacarPromedioSalarios (eEmpleado lista[], int tam);

/*/// \fn void MostrarTotalPromedioSalarios(eEmpleado[], int)
/// \brief La funci�n muestra o imprime el total y el promedio de los salarios en la lista.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
void MostrarTotalPromedioSalarios(eEmpleado lista[], int tam);*/

/// \fn int ContarEmpleadosQueSuperenElPromedio(eEmpleado[], int)
/// \brief La funci�n recorre el array de la lista de empleados y se encarga de contar cu�ntos empleados superan el promedio de salarios.
/// \param lista de tipo eEmpleado. El array de la lista de empleados.Para recorrer la lista de empleados.
/// \param tam de tipo entero. Es el tama�o de la lista de empleados. Para pasarle el limite de iteraciones que deber� recorrer el for dentro de  la funci�n.
/// \return Retorna la cantidad de empleados que superan el promedio de salarios.
int ContarEmpleadosQueSuperenElPromedio (eEmpleado lista[], int tam);

/// \fn int ValidarString(char[], int)
/// \brief La funci�n se ecnarga de validar que el dato que introduzca el ususario sea un caracter.
/// \param str de tipo char. Recibe el array de caracteres para que lo recorra.
/// \param tam El tama�o del array de caracteres.
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
/// \param cadena El array de caracteres donde se asignar� como valor el dato que ingrese el usuario.
/// \param mensaje El mensaje que se le va a mostrar el usuario.
/// \param tam El tama�o de caracteres que se podr�n ingresar en el array.
/// \return Retorna si se pudo intgresar el mensaje o si no se pudo.
int getString(char cadena[], char mensaje[], int tam);

/// \fn float IngresarFlotante(char[])
/// \brief Se utiliza para que el usuario ingrese un dato de tipo flotante.
/// \param mensaje El mensaje que se le va a mostrar el usuario.
/// \return Retorna el n�mero ingresado.
float IngresarFlotante(char mensaje[]);



