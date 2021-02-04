/*
 * ArrayEmpleados.h
 *
 *  Created on: 20 nov. 2020
 *      Author: CLEM
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

 typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int estaVacio;

} eEmpleado;

#endif /* ARRAYEMPLEADOS_H_ */

/** @brief Para indicar que todas las posiciones en el array estan vacias,
 * 		   esta funcion pone la bandera (isEmty) en verdadero (1) en todas
 *         las posiciones del array.
 *
 * @param lista eEmpleado* Puntero al array de empleados
 * @param largo int Array Largo del array de empleados
 * \return int Retorna (-1) en caso de ERROR [largo invalido o puntero nulo] - (0) en caso de EXITO
 *
 */
int inicializarEmpleados(eEmpleado* lista, int largo);
/** @brief Añade a una lista existente de empleados los valores recividos como parametros
 *		   en la primer posicion vacia.
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param id int ID del usuario a agregar
 * @param nombre char* nombre del usuario a agregar
 * @param apellido char* apellido del usuario a agregar
 * @param salario float Salario del usuario a agregar
 * @param sector int Sector del usuario a agregar
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo o sin espacio libre]
 *
 **/
int agregarEmpleado(eEmpleado *lista, int largo, int id, char* nombre, char* apellido,float salario, int sector);
/** @brief Busca un Empleado por Id y devuelve la posicion del indice del Array,
 *
 * @param lista Empleado*  Puntero al array de empleados
 * @param largo Int Largo del array de empleados
 * @param id Int ID del usuario a agregar
 * @return Int Retorna la posicion del indice del Empleado o (-1) si [Largo invalido o puntero
 *  nulo o empleado no encontrado]
 *
 **/
int buscarEmpleadoPorId(eEmpleado* lista, int largo,int id);
/** @brief Remueve a un Empleado por Id (pone la bandera isEmpty en 1).
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param id int ID del usuario a eliminar
 * @return int Retorna (-1) si ERROR [Largo invalido o puntero nulo o
 * si no puede encontrar el empleado]  - (0) en caso de EXITO
 *
 **/
int removerEmpleado(eEmpleado* lista, int largo, int id);

/** @brief   Ordena los elementos en el Array de Empleados, el argumento
 * de orden indica orden ascendente u orden descendente
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param orden int [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * @return int Retorna (-1) en caso de ERROR [Largo invalido o puntero
 * nulo] - (0) en caso de EXITO
 *
 */
int ordenarEmpleados(eEmpleado* lista, int largo, int orden);
/** \brief Imprime el contenido del Array de Empleados
 *
 * \param lista Empleado* Puntero al array de empleados
 * \param largo int Largo del array de empleados
 * \return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 *
 */
int imprimirEmpleados(eEmpleado* lista, int largo);
/**
 * @brief	Imprimir el contenido del array de empleados en la posicion pasada por parametro
 * 			(solo la imprime si esta no esta vacia)
 *
 * @param lista	Empleado* Puntero al array de eEmpelado
 * @param largo	Int. Largo del arrray de eEmpleado
 * @param posicion	Int. Posicion que se desea imprimir
 * @return Int. Retorna (0) en caso de EXITO - (-1) en caso de ERROR (no pudo imprimir, puntero
 * 			invalido, posicion o largo invalido.)
 */
int imprimirEmpleado(eEmpleado *lista, int largo, int posicion);
/**\brief Retorna el sueldo promedio del Array de Empleados
 *
 * \param lista Empleado* Puntero al array de empleados
 * \param largo int Largo del array de empleados
 * \param promedio * Puntero al espacio de memoria donde se guardara el promedio
 * \return Int Retorna (-1) en caso de Error [Largo invalido o puntero nulo]
 * 		   -(0) en caso de EXITO
 */
int sueldoPromedioEmpleados(eEmpleado* lista, int largo, float *promedio);
/**@brief Busca si hay algun empelado cargado en el array y devuelve true (1)
 * si lo encuentra y (0)false si no
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @return Retorna (-1) en caso de Error [Largo invalido o puntero nulo o si no
 * 		   hay empleado cargado] - (0) en caso de encontrar al menos un empeleado
 * 		   cargado.
 *
 */
int hayEmpleadoCargado(eEmpleado *lista, int largo);
/**
 * @brief	Valida si existe en el listado un empleado con el id pasado por parametro
 *
 * @param listadoEmpleados	Puntero al array de empleados
 * @param largoEmpleados	Int largo del array de empleados
 * @param id	Int. Id a validar.
 * @return Retorna (-1) en caso de ERROR - (0) si el empleado esta en el listado
 */
int validarIdEmpleado(eEmpleado *listadoEmpleados, int largoEmpleados,int id);
/**
 * @brief	Le muestra al usuario el listado de empelados con el id correspondiente y
 * 			le pide ingresar uno de estos id, valida que el ingreso este dentro del listado
 * 			y si es valido lo retorna por el puntero pIdResultado.
 *
 * @param pIdResultado	Puntero al entero Id donde retornara el ingreso de usuario.
 * @param mensaje	Cadena de caracetres del mensaje a mostrar para el ingreso
 * @param mensajeError Cadena de caracteres del mensaje de error a mostrar
 * @param listadoEmpleado	Array de eEmpleados
 * @param largoEmpleados	Int. Largo del array de eEmpleados
 * @param reintentos	Int. Cantidad de reintentos para el ingreso.
 * @return	Retorna (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			reintentos invalido, sin reintentos) - (0) si
 */
int pedirEmpleadoPorId(int *pIdResultado,char *mensaje, char *mensajeError ,
		eEmpleado *listadoEmpleado,int largoEmpleados, int reintentos);
/**
 * @brief	Hardcodea a lo sumo 10 empleados al array de eEmpleados
 *
 * @param listaEmpleados	array de eEmpleados
 * @param largoEmpleados	largo del array de eEmpleados
 * @param cantidad
 * @return	Int.Retorna la catindad de empleados cargados en el array en caso de EXITO
 * 			o (-1) en caso de ERROR (puntero nulo, largo invalido, cantidad invalida.)
 */
int hardcodearEmpleados(eEmpleado* listaEmpleados ,int largoEmpleados , int cantidad);
/** @brief   Ordena los elementos en el Array de Empleados, el argumento
 * de orden indica orden ascendente u orden descendente
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param orden int [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * @return int Retorna (-1) en caso de ERROR [Largo invalido o puntero
 * nulo] - (0) en caso de EXITO
 *
 */
int ordenarEmpleadosPorId(eEmpleado* lista, int largo, int orden);
