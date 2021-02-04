/*
 * ArrayEmpleados.c
 *
 *  Created on: 20 nov. 2020
 *      Author: CLEM
 */
#include "ArrayEmpleados.h"
#include "utn_validaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarEmpleados(eEmpleado* lista, int largo)
{
	int vRetorno = 0;
	int i;

	if (lista != NULL && largo > 0)
	{
		for (i = 0; i < largo; i++)
		{
			lista[i].estaVacio = 1;
		}
	} else
	{
		vRetorno = -1;
	}
	return vRetorno;
}

int agregarEmpleado(eEmpleado *lista, int largo,
		int id, char* nombre, char* apellido,
		float salario, int sector)
{
	int i;
	int vRetorno = -1;
	//Controlo si hay o no espacio libre

	if (lista != NULL && largo > 0)
	{
		for (i = 0; i <= largo; i++)
		{
			if (lista[i].estaVacio == 1)
			{ //Controlo si hay alguno libre
				//cargo los parametros recibidos
				lista[i].id = id;
				strcpy(lista[i].nombre, nombre);
				strcpy(lista[i].apellido, apellido);
				lista[i].salario = salario;
				lista[i].sector = sector;
				lista[i].estaVacio = 0;
				vRetorno = 0;
				break;
			}
		}
	}
	return vRetorno;
}

int buscarEmpleadoPorId(eEmpleado *lista, int largo, int id)
{
	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0)
	{
		for (i = 0; i < largo; i++)
		{
			if (lista[i].id == id && lista[i].estaVacio == 0) {
				vRetorno = i;
				break;
			}
		}
	}
	return vRetorno;
}
int removerEmpleado(eEmpleado *lista, int largo, int id)
{
	int vRetorno = -1;
	int posicion;

	if (lista != NULL && largo > 0)
	{
		posicion = buscarEmpleadoPorId(lista, largo, id);
		if (posicion >= 0) {
			lista[posicion].estaVacio = 1;
			vRetorno = 0;
		}
	}
	return vRetorno;
}

int ordenarEmpleados(eEmpleado *lista, int largo, int orden) {

	int vRetorno = -1;
	int i;
	int j;
	eEmpleado aux;

	if (lista != NULL && largo > 0 && (orden == 0 || orden == 1)) {

		switch (orden) {
		case 0:
			for (i = 0; i < largo - 1; i++) {

				for (j = 0; j < largo; j++) {

					if (strcmp(lista[i].apellido, lista[j].apellido) > 0) {

						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;

					} else if (strcmp(lista[i].apellido, lista[j].apellido)
							== 0) {

						if (lista[i].sector > lista[j].sector) {

							aux = lista[i];
							lista[i] = lista[j];
							lista[j] = aux;

						}

					}

				}
			}

			vRetorno = 0;

			break;

		case 1:
			for (i = 0; i < largo - 1; i++) {

				for (j = 0; j < largo; j++) {

					if (strcmp(lista[i].apellido, lista[j].apellido) < 0) {

						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;

					} else if (strcmp(lista[i].apellido, lista[j].apellido)
							== 0) {

						if (lista[i].sector < lista[j].sector) {

							aux = lista[i];
							lista[i] = lista[j];
							lista[j] = aux;

						}

					}

				}
			}

			vRetorno = 0;
			break;
		}

	}

	return vRetorno;
}


int imprimirEmpleados(eEmpleado *lista, int largo) {

	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0) {
		printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
		printf("|     ID     |      APELLIDO      |          NOMBRE          |     SECTOR     |      SALARIO      |\n");
		printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
		for (i = 0; i < largo; i++) {

			if (lista[i].estaVacio == 0) {
				printf("|%12d|%-20s|%-26s|%16d|%19.2f|\n",
						lista[i].id,lista[i].apellido,lista[i].nombre,
						lista[i].sector, lista[i].salario);
				printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
			}
		}

		vRetorno = 0;
	}

	return vRetorno;
}
int imprimirEmpleado(eEmpleado *lista, int largo, int posicion)
{
	int vRetorno = -1;

	if (lista != NULL && largo > 0 && largo > posicion)
	{
		if (lista[posicion].estaVacio == 0) {
			printf("|%12d|%-20s|%-26s|%16d|%19.2f|\n",
					lista[posicion].id,lista[posicion].apellido,lista[posicion].nombre,
					lista[posicion].sector, lista[posicion].salario);
			printf("+------------+--------------------+--------------------------+----------------+-------------------+\n");
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int sueldoPromedioEmpleados(eEmpleado *lista, int largo, float *promedio) {

	int vRetorno = -1;
	int i;
	float suma = 0;
	int contadorEmpelados = 0;

	if (lista != NULL && promedio != NULL && largo > 0) {

		for (i = 0; i < largo; i++) {

			if (lista[i].estaVacio == 0) {

				suma += lista[i].salario;
				contadorEmpelados++;
			}

		}

		if (contadorEmpelados == 0) {
			printf("\n No hay empleados cargados, no se puede calcular el promedio");
		} else {

			*promedio = suma / contadorEmpelados;
			vRetorno = 0;
		}

	}

	return vRetorno;

}
int hayEmpleadoCargado(eEmpleado *lista, int largo) {

	int vRetorno = -1;
	int i;
	if (lista != NULL && largo > 0) {
		for (i = 0; i < largo; i++) {

			if (lista[i].estaVacio == 0) {
				vRetorno = 0;
				break;
			}

		}
	}

	return vRetorno;
}
int validarIdEmpleado(eEmpleado *listadoEmpleados, int largoEmpleados,int id)
{
	int vRetorno = -1;
	int i;

	if (listadoEmpleados != NULL && largoEmpleados > 0 && id>=0) {
		for (i = 0; i < largoEmpleados; i++) {
			if (listadoEmpleados[i].id == id)
			{
				vRetorno = 0;
				break;
			}
		}
	}
	return vRetorno;
}

int pedirEmpleadoPorId(int *pIdResultado,char *mensaje, char *mensajeError ,
		eEmpleado *listadoEmpleado,int largoEmpleados, int reintentos)
{
	int vRetorno = -1;
	int vBufferId;

	if (pIdResultado != NULL && listadoEmpleado != NULL && largoEmpleados > 0
			&& reintentos >= 0) {
		do {
			system("cls");
			if (imprimirEmpleados(listadoEmpleado, largoEmpleados)== 0
					&&	utn_getNumeroMin(&vBufferId, mensaje, mensajeError, -1, 0) == 0
					&& validarIdEmpleado(listadoEmpleado, largoEmpleados, vBufferId) == 0)
			{
				*pIdResultado = vBufferId;
				vRetorno = 0;
				system("cls");
				break;
			}
			reintentos--;
		} while (reintentos >= 0);
	}
	return vRetorno;
}
int hardcodearEmpleados(eEmpleado* listaEmpleados ,int largoEmpleados , int cantidad)
{

	int vContador = 0;
	int vRetorno = -1;
	int i;

	if(listaEmpleados !=  NULL && largoEmpleados>0 && cantidad>0 && cantidad<= largoEmpleados && cantidad<11){
		eEmpleado listaAuxiliar[] =
		{
				{ 1, "evelyn", "yanez" ,20000.5,5,0},
				{ 2, "maria","perez" ,30000, 10,0},
				{ 3, "juan carlos","martinez",2018,2,0},
				{ 4, "maria cecilia", "strupenni",100000,3,0},
				{ 5, "roman","vispo",10020.5, 5,0},
				{ 6, "luis", "luna",20000.5, 2, 0},
				{ 7, "martin","cabrera",55000, 3,0},
				{ 8, "lucas", "yanez" ,70000.90, 2,0},
				{ 9, "mariano","arario",80000, 2,0},
				{ 10, "fernando","scoles", 90000, 3,0}
		};

			for(i =0; i<cantidad;i++){
				listaEmpleados[i] = listaAuxiliar[i];
				vContador++;
			}
			vRetorno = vContador;
	}

	return vRetorno;
}
int ordenarEmpleadosPorId(eEmpleado* lista, int largo, int orden)
{
	int vRetorno = -1;
	int i;
	int j;
	eEmpleado aux;

	if (lista != NULL && largo > 0 && (orden == 0 || orden == 1)) {

		switch (orden) {
		case 0:
			for (i = 0; i < largo - 1; i++)
			{
				for (j = 0; j < largo; j++)
				{
					if (lista[i].id> lista[j].id)
					{
						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;
					}
				}
			}

			vRetorno = 0;

			break;

		case 1:
			for (i = 0; i < largo - 1; i++)
			{
				for (j = 0; j < largo; j++)
				{
					if (lista[i].id< lista[j].id)
					{
						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;

					}
				}
			}
			vRetorno = 0;
			break;
		}
	}
	return vRetorno;
}
