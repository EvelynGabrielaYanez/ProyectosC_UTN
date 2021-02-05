/*
 * TP_2_modulos.h
 *
 *  Created on: 20 nov. 2020
 *      Author: CLEM
 */

#include "ArrayEmpleados.h"

#ifndef TP_2_MODULOS_H_
#define TP_2_MODULOS_H_



#endif /* TP_2_MODULOS_H_ */
/**@brief  Muestra el menu de opciones y pide al usuario el ingreso de una de ellas y
 * 		   la retorna luego de validarla
 *
 * @return Int. Opcion seleccionada por el usuario
 */
int menu();
/**@brief Pide al usuario el ingreso del nombre, apellido, sector y sueldo calculando
 * 		  el id correspondiente y da de alta en caso de ser posible, caso contrio comunica que
 * 		  no se pudo y explica el motivo(cantidad maxima de cargas alcanzada, reintentos de ingreso
 * 		  de informacion requerida agotados )
 *
 * @param lista  eEmpleado Array. Puntero al espacio de memoria donde se copia el empleado obtenido.
 * @param largo Int. Cantidad de elementos que tiene el array
 * @param contadorId Int. Id que se autoasginara
 */
void altas(eEmpleado* lista,int largoEmpleados, int* id);
/**@brief Pide al usuario que ingrese el ID del empleado que desea modificar. En caso de encontrarlo
 *		  se le permite ingresar nombre o apellido o seccion o salario modificado y se carga la modificacion.
 *
 * @param lista  Empleado Array. Puntero al espacio de memoria donde se modificara el empleado.
 * @param largo Int. Cantidad de elementos que tiene el array
 */
void modificar(eEmpleado* lista,int largoEmpleados);
/**@brief Pide al usuario que ingrese el ID del empleado que desea modificar. En caso de encontrarlo
 *		  se le pide confirmacion y en caso de darla se elimina el empleado con dicha id.
 *
 * @param lista Empleado Array. Puntero al espacio de memoria donde se eliminara el empleado.
 * @param largo Int. Cantidad de elementos que tiene el array
 */
void baja(eEmpleado* lista,int largoEmpleados);
/**@brief Pide al usuario que seleccione que quiere informar, listado de empleados o resumen. En
 * 		  caso de elegir la primer opcion, se le pide seleccionar si lo quiere ver ordenado por
 * 		  apellido y sector de manera ascendente o descendente. En caso de elegir la segunda
 * 		  opcion se le muestra el sueldo tota, el promedio y la cantidad de empleados con sueldo
 * 		  mayor al promedio.
 *
 * @param lista Empleado Array. Puntero al espacio de memoria donde se eliminara el empleado.
 * @param largo Int. Cantidad de elementos que tiene el array
 */
void informar(eEmpleado* lista,int largoEmpleados);
