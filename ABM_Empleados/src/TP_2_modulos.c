/*
 * TP_2_modulos.c
 *
 *  Created on: 20 nov. 2020
 *      Author: CLEM
 */
#include <stdio.h>
#include <stdlib.h>
#include "TP_2_modulos.h"
#include "utn_validaciones.h"
#define REINTENTOS 5

int menu()
{

	int vOpcionMenu;	  //va a contener la opcion del menu seleccionada
	int vResultadoIngreso;// va a ser 0 si el usuario ingreso la opcion de menu deseada correctamente y -1 si no

	do {
		//Imprimo el menu
		system("cls");
		printf("-------------------EMPLEADOS-------------------\n");
		printf(" 1.ALTA EMPLEADO\n");
		printf(" 2.MODIFICAR EMPLAEDO\n");
		printf(" 3.BAJA EMPLAEDO\n");
		printf(" 4.INFORMAR EMPLEADOS\n");
		printf(" 5.SALIR\n");
		printf("-----------------------------------------------\n");

		//Pido el ingreso de un numero entero entre 1 y 5 para seleccionar la opcion de menu
		vResultadoIngreso = utn_getNumero(&vOpcionMenu,
				" Ingrese la opcion deseada: ",
				" No ingreso una opcion valida.\n Vuelva a intentarlo.\n", 1,
				5, 0);
	} while (vResultadoIngreso == -1);//Mientras que el el ingreso sea erroneo continuo pidiendolo

	system("cls");

	return vOpcionMenu;
}

void altas(eEmpleado* lista,int largoEmpleados, int* id)
{
	int vBanderaReintentos = 1;	// (1) se quedo sin reintentos (0) cargo correctamente
	eEmpleado empleadoIngresado;// contendra la informacion del alumno que ingresa el usuario

	if (lista != NULL && largoEmpleados > 0) {

		if (utn_getTextoSoloLetras(empleadoIngresado.nombre, largoEmpleados,
				" Ingrese el nombre del empleado: ", " Nombre ingresado invalido", REINTENTOS) == 0)
		{
			system("cls");

			if (utn_getTextoSoloLetras(empleadoIngresado.apellido, largoEmpleados,
					" Ingrese el apellido del empleado: ", " Apellido ingresado invalido.", REINTENTOS) == 0)
			{
				system("cls");
				if (utn_getNumeroConDecimalesMin(&empleadoIngresado.salario, " Ingrese el salario del empleado.",
						" El salario ingresado es invalido. ", 0, REINTENTOS) == 0)
				{
					system("cls");

					if (utn_getNumero(&empleadoIngresado.sector, " Ingrese el sector del empleado(1-100): ",
							" El sector ingresado es invalido.", 1, 100, REINTENTOS) == 0) {
						system("cls");

						empleadoIngresado.id = *id + 1;
						empleadoIngresado.estaVacio = 0;
						vBanderaReintentos = 0;
						system("cls");

						if (agregarEmpleado(lista, largoEmpleados, empleadoIngresado.id, empleadoIngresado.nombre,
								empleadoIngresado.apellido, empleadoIngresado.salario, empleadoIngresado.sector)
								== 0) {
							(*id)++;
							printf("\n Se le ha asignado el legajo: %d \n Alta exitosa.\n ",*id);

						} else {
							printf("\n Hay %d empleados cargados, no es posible cargar mas.\n No se ha dado el alta.\n ",
									largoEmpleados);
						}
					}

				}
			}
		}

		if (vBanderaReintentos == 1) {
			printf("\n No tiene mas reintentos.\n No se ha dado el alta.\n ");
		}
	}
	return;
}

void modificar(eEmpleado* lista,int largoEmpleados)
{
	int vIdEmpleado;//Contendra el Id que ingresa el empleado para modificar
	int vOpcionSubMenu;			//Contendra la opcion seleccionada en el submenu
	int vPosicionEmpleado;//Contendra el estado de la opcion ingresada en el submenu 0 EXITO, -1 ERROR
	int vRespuestaVolver = 0;//Contendra la respuesta del usuario 0 (NO) o 1 (SI) a la pregunta 'desea volver?'

	if (lista != NULL && largoEmpleados > 0) {

		if (hayEmpleadoCargado(lista, largoEmpleados) == 0) {
			//Si se ingreso el ID de manera correcta, es decir, si es igual a 0.
			if (ordenarEmpleadosPorId(lista, largoEmpleados, 1) == 0 &&
				pedirEmpleadoPorId(&vIdEmpleado, " Ingrese el id del empleado deseado: ",
					" El id ingresado es invalido. ", lista,
					largoEmpleados, REINTENTOS) == 0 ) {	//Buso el Id en el listado
				vPosicionEmpleado = buscarEmpleadoPorId(lista, largoEmpleados, vIdEmpleado);
				//Si no se encontro el ID en el listado comunico y vuelvo al menu inicial
				if (vPosicionEmpleado == -1) {
					printf("\n No se ha ingresado ningun electrodomestico de Id %d ",vIdEmpleado);

				} else // Si se encontro el ID en el listado
				{
					do {
						do { //Menu de modificacion. Sigo iterando mientras la opcion ingresada sea incorrecta
							system("cls");
							printf("----------------INFORMACION DEL EMPLEADO----------------\n\n");
							printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
							printf("|     ID     |      APELLIDO      |          NOMBRE          |     SECTOR     |      SALARIO      |\n");
							printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
							imprimirEmpleado(lista, largoEmpleados, vPosicionEmpleado);

							printf("\n\n----------------MODIFICAR---------------\n");
							printf(" 1.NOMBRE\n");
							printf(" 2.APELLIDO\n");
							printf(" 3.SALARIO\n");
							printf(" 4.SECTOR\n");
							printf(" 5.VOLVER\n");
							printf("--------------------------------------------\n");

						} while (utn_getNumero(&vOpcionSubMenu,
								" Ingrese la opcion deseada modificar: ",
								" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
								1, 5, 0) == -1);

						system("cls");

						switch (vOpcionSubMenu) { //Analizo caso por caso de la opcion seleccionada del menu
						case 1:
							if (utn_getTextoSoloLetras(lista[vPosicionEmpleado].nombre, largoEmpleados,
									" Ingrese el nombre del empleado modificado: ",
									" El nombre ingresado es invalido", REINTENTOS)== 0)
							{
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 2:
							if (utn_getTextoSoloLetras(lista[vPosicionEmpleado].apellido, largoEmpleados,
									" Ingrese el apellido del empleado modificado: ",
									" El apellido ingresado es invalido", REINTENTOS)== 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 3:
							if (utn_getNumeroConDecimalesMin(&lista[vPosicionEmpleado].salario,
									" Ingrese el salario del empleado modificado: ",
									" El salario ingresado es invalido.",
									0, REINTENTOS)== 0)
							{
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 4:
							if (utn_getNumero(&lista[vPosicionEmpleado].sector, " Ingrese el sector del empleado modificado(1-100): ",
									" El sector ingresado es invalido.", 1, 100, REINTENTOS)== 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 5:
							//Pregunto si desea volver al menu
							do {
								vRespuestaVolver = unt_preguntaRespuestaBinaria(" Desea volver?(s/n) ", 's', 'n');
								system("cls");
							} while (vRespuestaVolver == -1);
							break;
						}

					} while (vRespuestaVolver == 0); //Siempre que la respuesta de salida sea 0 vuelvo a iterar

					system("cls");
				}
			} else {
				system("cls");
				printf("\n Ya no tiene reintentos.\n ");
				system("pause");
			}
		} else {
			system("cls");
			printf("\n No puede modificar, no hay empleados cagados.\n ");
			system("pause");

		}
	}
	return;
}
void baja(eEmpleado* lista,int largoEmpleados)
{

	int vIdEmpleados;//Contendra el ID que el usuario ingresa para eliminar
	int vRetornoRespuestaEliminar = 0; /* (1) si desea eliminar (0) si no desea eliminar
	 (-1) si no ingreso una opcion correcta*/
	int vPosicionEmpleado; //posicion del empleados que desea eliminar

	if (lista != NULL && largoEmpleados > 0)
	{
		if (hayEmpleadoCargado(lista, largoEmpleados) == 0) {
			//Pido al usuario que ingrese el ID y veo si ingreso el usuario correctamente (EXITO)
			if (ordenarEmpleadosPorId(lista, largoEmpleados, 1) == 0 &&
				pedirEmpleadoPorId(&vIdEmpleados, " Ingrese el id del empleado que desea eliminar: ",
					" El id ingresado es invalido.",lista, largoEmpleados, REINTENTOS)== 0) {
				system("cls");

				vPosicionEmpleado = buscarEmpleadoPorId(lista, largoEmpleados, vIdEmpleados);

				if (vPosicionEmpleado >= 0) {
					//Pido el usuario confirmacion 's' o 'n' para eliminar y veo is confirma la eliminacion
					do {
						printf("----------------ELIMINAR---------------\n \n");
						printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
						printf("|     ID     |      APELLIDO      |          NOMBRE          |     SECTOR     |      SALARIO      |\n");
						printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
						if (imprimirEmpleado(lista, largoEmpleados, vPosicionEmpleado) == 0)
						{
							vRetornoRespuestaEliminar =unt_preguntaRespuestaBinaria(
											"\n Esta seguro que desea eliminarlo?(s/n) ",
											's', 'n');
							system("cls");
						}
					} while (vRetornoRespuestaEliminar == -1);

					if (vRetornoRespuestaEliminar == 1)
					{
						//Si se elimino exitosamente pongo la variable de retorno en 0 (EXITO)
						if (removerEmpleado(lista, largoEmpleados, vIdEmpleados)== 0)
						{
							printf("\n Empleado eliminado.\n ");
						}else{
							printf("\n No se elimino el empleado.\n ");
						}

					} else {
						printf("\n No se elimino el empleado.\n ");
					}

				} else {
					printf("\n No se ha ingresado ningun empleado de Id %d ",vIdEmpleados);
				}

			} else {
				printf("\n Ya no tiene reintentos.\n ");
			}

		} else {
			printf("\n No puede eliminar, no hay empleados cagados.\n ");
		}
	}
	return;
}
void informar(eEmpleado* lista,int largoEmpleados)
{
	int vOpcionSubMenu;				//Contendra la opcion del menu seleccionada

	if (lista != NULL && largoEmpleados > 0 ) {

		if (hayEmpleadoCargado(lista, largoEmpleados) == 0) {

			do {
				system("cls");

				printf("--------------------LISTA DE EMPLEADOS--------------------\n");
				printf(" 1.ORDENADA POR APELLIDO Y SECTOR DE MANERA ASCENDENTE\n");
				printf(" 2.ORDENADA POR APELLIDO Y SECTOR DE MANERA DESCENDENTE\n");
				printf("-----------------------------------------------------------\n");

			} while (utn_getNumero(&vOpcionSubMenu,
					" Ingrese la opcion que desea: ",
					" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
					1, 2, 0) == -1);
			system("cls");

			switch (vOpcionSubMenu) {
			case 1:
				if (ordenarEmpleados(lista, largoEmpleados, 1)== 0
						&& imprimirEmpleados(lista, largoEmpleados) == 0) {
					printf("\n Informe finalizado.\n ");
				}
				break;
			case 2:

				if (ordenarEmpleados(lista, largoEmpleados, 0)== 0
						&& imprimirEmpleados(lista, largoEmpleados) == 0)
				{
					printf("\n Informe finalizado.\n ");
				}

				break;
			}

		} else {
			system("cls");
			printf("\n No puede informar, no hay empleado cagados.\n ");
		}
	}


	return;
}
