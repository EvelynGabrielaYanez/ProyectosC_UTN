/*
 * Articulo.c
 *
 *  Created on: 21 nov. 2020
 *      Author: CLEM
 */
#include "Articulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esValidoNumero(char *cadena);
static int esValidoNumeroDecimal(char *cadena);
static int esValidoArticulo(char *cadena);
static int esValidoMedida(char *cadena);

static int esValidoNumero(char *cadena) {

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


/**@brief Verifica dsi la cadena ingresada es numerica decimal
 *
 * @param Cadena. Cadena de caracteres a ser analizada
 * @return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esValidoNumeroDecimal(char *cadena)
{

	int vRetorno = 1;
	int i = 0;
	int vContadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if (cadena[i] == '.') {
				vContadorPuntos++;
			}

			if ((cadena[i] < '0' || cadena[i] > '9' || vContadorPuntos > 1)
					&& cadena[i] != '.') {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}

static int esValidoArticulo(char *cadena)
{

	int vRetorno = 1;
	int i = 1;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if(i==0 && cadena[i] == ' ')
			{
				break;	// No permito ingresar un vacio en el primer espacio
			}

			if (cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i]!= '-'
					&& cadena[i]!= '.'&&  cadena[i]!= '/'  &&  cadena[i] !='ñ' && cadena[i]!= 'á' 	&& cadena[i]!= 'í'
					&& cadena[i]!= 'ó' && cadena[i]!= 'ú'  &&  cadena[i]!= 'é' && cadena[i] != 'Ñ') {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}

static int esValidoMedida(char *cadena)
{

	int vRetorno = 1;
	int i = 1;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if(i==0 && cadena[i] == ' ')
			{
				break;	// No permito ingresar un vacio en el primer espacio
			}

			if (cadena[i] != ' '  && (cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z' ) &&
					(cadena[i] < '0' || cadena[i] > '9')){
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}

int articulo_cargarId(eArticulo* this,int id)
{
	int vRetorno = -1;
	if(this != NULL && id >=0)
	{
		this->id=id;
		vRetorno=0;
	}
	return vRetorno;
}

int articulo_cargarIdTxt(eArticulo* this,char* id)
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
int articulo_tomarId(eArticulo* this,int* id)
{
	int vRetorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		vRetorno=0;
	}

	return vRetorno;
}
int articulo_tomarIdTxt(eArticulo* this,char* id)
{
	int vRetorno = -1;
		if(this != NULL && id != NULL)
		{
			sprintf(id, "%d", this->id);
			vRetorno=0;
		}

	return vRetorno;
}
int articulo_cargarDescArticulo(eArticulo* this,char* articulo)
{
	int vRetorno = -1;

	if(this != NULL && articulo != NULL)
	{
		if(esValidoArticulo(articulo))
		{
			strncpy(this->articulo,articulo,LARGO_ARTICULO);
			vRetorno=0;
		}
	}
	return vRetorno;
}
int articulo_tomarDescArticulo(eArticulo* this,char* articulo)
{
	int vRetorno = -1;

	if(this != NULL && articulo != NULL)
	{
		strncpy(articulo,this->articulo,LARGO_ARTICULO);
		vRetorno=0;
	}
	return vRetorno;
}

int articulo_cargarMedida(eArticulo* this,char* medida)
{
	int vRetorno = -1;

	if(this != NULL && medida != NULL)
	{
		if(esValidoMedida(medida))
		{
			strncpy(this->medida,medida,LARGO_MEDIDA);
			vRetorno=0;
		}
	}
	return vRetorno;
}
int articulo_tomarMedida(eArticulo* this,char* medida)
{
	int vRetorno = -1;

	if(this != NULL && medida != NULL)
	{
		strncpy(medida,this->medida,LARGO_MEDIDA);
		vRetorno=0;
	}
	return vRetorno;
}

int articulo_cargarPrecio(eArticulo* this,float precio)
{
	int vRetorno = -1;
	if(this != NULL && precio >0)
	{
		this->precio=precio;
		vRetorno=0;
	}
	return vRetorno;
}
int articulo_cargarPrecioTxt(eArticulo* this,char* precio)
{
	int vRetorno = -1;
	if(this != NULL && precio != NULL)
	{
		if(esValidoNumeroDecimal(precio))
		{
			this->precio=atof(precio);
			vRetorno=0;
		}
	}
	return vRetorno;
}
int articulo_tomarPrecio(eArticulo* this,float* precio)
{
	int vRetorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		vRetorno=0;
	}

	return vRetorno;
}
int articulo_tomarPrecioTxt(eArticulo* this,char* precio)
{
	int vRetorno = -1;
		if(this != NULL && precio != NULL)
		{
			sprintf(precio, "%f", this->precio);
			vRetorno=0;
		}

	return vRetorno;
}

int articulo_cargarIdRubro(eArticulo* this,int rubroId)
{
	int vRetorno = -1;
	if(this != NULL && rubroId >=0)
	{
		this->rubroId=rubroId;
		vRetorno=0;
	}
	return vRetorno;
}
int articulo_cargarIdRubroTxt(eArticulo* this,char* rubroId)
{
	int vRetorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		if(esValidoNumero(rubroId))
		{
			this->rubroId=atoi(rubroId);
			vRetorno=0;
		}
	}
	return vRetorno;
}
int articulo_tomarIdRubro(eArticulo* this,int* rubroId)
{
	int vRetorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		*rubroId = this->rubroId;
		vRetorno=0;
	}
	return vRetorno;
}
int articulo_tomarIdRubroTxt(eArticulo* this,char* rubroId)
{
	int vRetorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		sprintf(rubroId, "%d", this->rubroId);
		vRetorno=0;
	}
	return vRetorno;
}
eArticulo* articulo_nuevo()
{
	eArticulo* pArticulo = NULL;

	pArticulo =(eArticulo*)malloc(sizeof(eArticulo));
	if(pArticulo!= NULL)
	{
		articulo_cargarIdTxt(pArticulo, "");
		articulo_cargarDescArticulo(pArticulo, "");
		articulo_cargarMedida(pArticulo, "");
		articulo_cargarPrecioTxt(pArticulo, "");
		articulo_cargarIdRubroTxt(pArticulo, "");

	}

	return pArticulo;
}
eArticulo* articulo_nuevoParametros(char* idStr,char* articuloStr,char* medidaStr,char* precioStr, char* rubroIdStr)
{
	eArticulo* pArticulo = NULL;

	if(idStr!= NULL && articuloStr != NULL && medidaStr != NULL && precioStr != NULL && rubroIdStr != NULL){

		pArticulo = articulo_nuevo();

		if(pArticulo!= NULL)
		{

			if(	articulo_cargarIdTxt(pArticulo, idStr) ||
				articulo_cargarDescArticulo(pArticulo, articuloStr) ||
				articulo_cargarMedida(pArticulo, medidaStr) ||
				articulo_cargarPrecioTxt(pArticulo, precioStr) ||
				articulo_cargarIdRubroTxt(pArticulo, rubroIdStr) )
			{
				free(pArticulo);
				pArticulo = NULL;
			}
		}
	}
	return pArticulo;
}
void articulo_borrar(eArticulo* this)
{
	if(this!= NULL )
	{
		free(this);
	}
}
int articulo_imprimir(eArticulo* this, LinkedList* listaRubro)
{
	int vRetorno = -1;
	int auxId;
	char auxDescArticulo[LARGO_ARTICULO];
	char auxMedida[LARGO_MEDIDA];
	float auxPrecio;
	int auxIdRubro;
	char auxDescRubro[LARGO_DESC_RUBRO];


	if(this != NULL){



		if(!articulo_tomarId(this, &auxId) &&
			!articulo_tomarDescArticulo(this, auxDescArticulo) &&
			!articulo_tomarMedida(this, auxMedida) &&
			!articulo_tomarPrecio(this, &auxPrecio) &&
			!articulo_tomarIdRubro(this, &auxIdRubro))
		{

			if(!rubro_cargarDescPorID(listaRubro, auxIdRubro, auxDescRubro))
			{
				printf("|%10d|%50s|%20s|%20.2f|%30s|\n",auxId,auxDescArticulo,auxMedida,auxPrecio,auxDescRubro);
				printf("+----------+--------------------------------------------------+--------------------+--------------------+------------------------------+\n");
				vRetorno = 0;
			}
		}

	}

	return vRetorno;
}
int articulo_compararPorId(void* pArticulo1,void* pArticulo2)
{
	int vRetorno = -1;
	int auxId1;
	int auxId2;
	int dif;

	if(pArticulo2 != NULL && pArticulo1 != NULL)
	{
		if(!articulo_tomarId((eArticulo*)pArticulo1, &auxId1) && !articulo_tomarId((eArticulo*)pArticulo2, &auxId2))
		{
			dif = auxId1 - auxId2;
			if(dif<0)
			{
				vRetorno = -1;
			}
			else if(dif == 0){
				vRetorno = 0;
			}else{
				vRetorno = 1;
			}
		}
	}

	return vRetorno;
}

int articulo_compararPorArticulo(void* pArticulo1,void* pArticulo2)
{
	int vRetorno = -1;
	char auxDescArt1[LARGO_ARTICULO];
	char auxDescArt2[LARGO_ARTICULO];

	if(pArticulo1 != NULL && pArticulo2 != NULL)
	{
		if(!articulo_tomarDescArticulo((eArticulo*)pArticulo1, auxDescArt1) &&
				!articulo_tomarDescArticulo((eArticulo*)pArticulo2, auxDescArt2))
		{
			vRetorno = strcmp(auxDescArt1,auxDescArt2);
		}
	}

	return vRetorno;
}


