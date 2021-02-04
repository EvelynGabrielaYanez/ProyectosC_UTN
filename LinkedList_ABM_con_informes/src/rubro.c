/*
 * rubro.c
 *
 *  Created on: 22 nov. 2020
 *      Author: CLEM
 */

#include "rubro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief	Valida si la cadena de caracteres es numerica y entera positiva.
 *
 * @param cadena	Cadena de caracteres a validar.
 * @return	Retorna (1) si es valida - (0) si no lo es.
 */
static int esValidoNumero(char *cadena);
/**
 * @brief	Valida si la cadena de caracteres es un rubro (contiene letras, espacios, puntos, barras, tildes o ñ).
 *
 * @param cadena Cadena de caracteres a validar.
 * @return	Retorna (1) si es valida - (0) si no lo es.
 */
static int esValidoRubro(char *cadena);

static int esValidoNumero(char *cadena)
{

	int i = 0;
	int vRetorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}
	return vRetorno;
}


static int esValidoRubro(char *cadena)
{

	int vRetorno = 1;
	int i = 1;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if(i==0 && cadena[i] == ' ')
			{
				break;	// No permito ingresar un vacio en el primer espacio
			}

			if (cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z' )){
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}

int rubro_cargarId(eRubro* this,int id)
{
	int vRetorno = -1;
	if(this != NULL && id >=0)
	{
		this->id=id;
		vRetorno=0;
	}
	return vRetorno;
}
int rubro_cargarIdTxt(eRubro* this,char* id)
{
	int vRetorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esValidoNumero(id))
		{
			this->id=atoi(id);
			vRetorno=0;
		}
	}
	return vRetorno;
}
int rubro_tomarId(eRubro* this,int* id)
{
	int vRetorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		vRetorno=0;
	}

	return vRetorno;
}
int rubro_tomarIdTxt(eRubro* this,char* id)
{
	int vRetorno = -1;
		if(this != NULL && id != NULL)
		{
			sprintf(id, "%d", this->id);
			vRetorno=0;
		}

	return vRetorno;
}

int rubro_cargarDescripcion(eRubro* this,char* descripcion)
{	int vRetorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		if(esValidoRubro(descripcion))
		{
			strncpy(this->descripcion,descripcion,LARGO_DESC_RUBRO);
			vRetorno=0;
		}
	}
	return vRetorno;

}
int rubro_tomarDescripcion(eRubro* this,char* descripcion)
{
	int vRetorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strncpy(descripcion,this->descripcion,LARGO_DESC_RUBRO);
		vRetorno=0;
	}
	return vRetorno;
}
eRubro* rubro_nuevo()
{
	eRubro* pRubro = NULL;

	pRubro =(eRubro*)malloc(sizeof(eRubro));
	if(pRubro!= NULL)
	{
		rubro_cargarIdTxt(pRubro, "");
		rubro_cargarDescripcion(pRubro, "");
	}
	return pRubro;
}
eRubro* rubro_nuevoParametros(char* idStr,char* descripcionStr)
{
	eRubro* pRubro = NULL;

	if(idStr!= NULL && descripcionStr != NULL )
	{
		pRubro = rubro_nuevo();

		if(pRubro!= NULL)
		{
			if(	rubro_cargarIdTxt(pRubro, idStr)  ||
				rubro_cargarDescripcion(pRubro, descripcionStr))
			{
				free(pRubro);
				pRubro = NULL;
			}
		}
	}
	return pRubro;
}

int mostarRubro(eRubro* this)
{
	int vRetorno = -1;
	int auxId;
	char auxDescripcion[LARGO_DESC_RUBRO];


	if(this != NULL){

		if(!rubro_tomarId(this, &auxId) &&
			!rubro_tomarDescripcion(this, auxDescripcion))
		{
			printf("|%10d|%20s|\n",auxId,auxDescripcion);
			printf("+----------+------------------------------+\n");
			vRetorno = 0;
		}

	}

	return vRetorno;
}

int rubro_buscarPorID(LinkedList* listaRubro, int idRubro)
{
	int vRetorno = -1;
	int largo;
	int i;
	eRubro* pAuxRubro;
	int auxIdRubro;

	if(listaRubro != NULL && idRubro>=0)
	{
		largo = ll_len(listaRubro);
		for(i=0;i<largo; i++)
		{
			pAuxRubro = (eRubro*)ll_get(listaRubro, i);
			rubro_tomarId(pAuxRubro, &auxIdRubro);
			if (auxIdRubro == idRubro)
			{
				vRetorno = i;
			}
		}

	}
	return vRetorno;
}

int rubro_cargarDescPorID(LinkedList* listaRubro, int idRubro, char* descripcion)
{
	int vRetorno = -1;
	int indexRubro;

	char auxDescRubro[LARGO_DESC_RUBRO];

	if(listaRubro != NULL && idRubro>=0 && descripcion != NULL)
	{
		indexRubro = rubro_buscarPorID(listaRubro, idRubro);
		if(indexRubro>-1)
		{
			if(!rubro_tomarDescripcion((eRubro*)ll_get(listaRubro, indexRubro), auxDescRubro) )
			{
				strcpy(descripcion,auxDescRubro);
				vRetorno = 0;
			}
		}
	}
	return vRetorno;
}
int rubro_hardcodearRubro(LinkedList* listaRubros, int cantidad)
{
	int vRetorno = -1;
	int i;
	eRubro* pAuxRubro;
	char auxID[4096];

	if(listaRubros != NULL && cantidad>0 && cantidad<5)
	{
		eRubro listaAuxiliar[] =
		{
			{1,"CUIDADO DE ROPA"},
			{2, "LIMPIEZA Y DESINFECCION"},
			{3, "CUIDADO PERSONAL E HIGUIENE"},
			{4, "CUIDADO DEL AUTOMOTOR"}

		};

		for(i=0; i<cantidad; i++)
		{
			sprintf(auxID,"%d", listaAuxiliar[i].id);
			pAuxRubro = rubro_nuevoParametros(auxID, listaAuxiliar[i].descripcion);

			ll_add(listaRubros, pAuxRubro);
		}
		vRetorno= ll_len(listaRubros);
	}
	return vRetorno;
}
