/*
 * controller.c
 *
 *  Created on: 22 nov. 2020
 *      Author: CLEM
 */
#include  "controller.h"
#include "utn_validaciones.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REINTENTOS 5


int controller_menu()
{

	int vOpcionMenu;	  //va a contener la opcion del menu seleccionada
	int vResultadoIngreso;// va a ser 0 si el usuario ingreso la opcion de menu deseada correctamente y -1 si no

	do {
		//Imprimo el menu
		system("cls");
		printf("*************************************************************************************\n");
		printf(" Menu: \n");
		printf("	1. Cargar los datos de los articulos desde el archivo (modo texto).\n");
		printf("	2. Ordenar articulos.\n");
		printf("	3. Listar articulos.\n");
		printf("	4. Realizar descuento.\n");
		printf("	5. Guardar los datos de los articulos en el archivo mapeado.csv (modo texto).\n");
		printf("	6. Informes.\n");
		printf("	7. Salir.\n");
		printf("*************************************************************************************\n");

		//Pido el ingreso de un numero entero entre 1 y 7 para seleccionar la opcion de menu
		vResultadoIngreso = utn_getNumero(&vOpcionMenu," Ingrese la opcion deseada: ",
				" No ingreso una opcion valida.\n Vuelva a intentarlo.\n", 1, 7,0);

	} while (vResultadoIngreso == -1);//Mientras que el el ingreso sea erroneo continuo pidiendolo

	system("cls");

	return vOpcionMenu;
}
int controller_loadFromText(char* path , LinkedList* pArrayListaArticulos, int* idArticulo)
{
	int vRetorno = -1;
	FILE* fp;
	int auxId;
	int len;

	if(pArrayListaArticulos!= NULL && path!= NULL && idArticulo != NULL){

		len = ll_len(pArrayListaArticulos);
		if(len==0){
			fp = fopen (path, "r");
			if(fp != NULL)
			{
				auxId=parser_articuloDeTexto(fp, pArrayListaArticulos);
				if(auxId>=0){
					*idArticulo = auxId;
					vRetorno =0;
				}
				fclose(fp);
			}
		}else
		{
			printf(" Ya se ha cargado anteriormente.\n");
		}
	}
	return vRetorno;
}

int controller_buscarIndexArtPorId(LinkedList* pArrayListaArtoculo,int* index, int id)
{
	int vRetorno  = -1;
	int i;
	int largo;
	eArticulo* pAuxArticulo;

	if(pArrayListaArtoculo!= NULL && index != NULL && id>=0)
	{
		largo = ll_len(pArrayListaArtoculo);
		if(largo>0){
			for(i=0;i<largo;i++)
			{
				pAuxArticulo = ll_get(pArrayListaArtoculo, i);
				if(pAuxArticulo!= NULL && pAuxArticulo->id == id)
				{
					*index = i;
					vRetorno = 0;
					break;
				}
			}
		}
	}
	return vRetorno;
}
int controller_tomarAriculoPorId(LinkedList* pArrayListaArticulos,LinkedList* pArrayListaRubro,eArticulo **pArticulo, int reintentos)
{
	int vRetorno = -1;
	int id;
	int index;
	eArticulo* pAuxArticulo = NULL;

	if(pArrayListaArticulos != NULL && pArticulo != NULL && reintentos>=0)
	{
		do{
			system("cls");
			if(!ll_sort(pArrayListaArticulos, articulo_compararPorArticulo, 1) &&
			   !controller_ListarArticulos(pArrayListaArticulos, pArrayListaRubro) &&
			   !utn_getNumeroMin(&id, " Ingrese el id del articulo que desea: ",
					   " El id ingresado no es valido", -1, 0))
			{
				if(!controller_buscarIndexArtPorId(pArrayListaArticulos, &index, id))
				{
					pAuxArticulo = ll_get(pArrayListaArticulos, index);
					if(pAuxArticulo!= NULL)
					{
						*pArticulo = pAuxArticulo;
						vRetorno = 0;
						break;
					}
				}else
				{
					 printf(" El id ingresado no es valido.\n ");
					 system("pause");
				}
			}
			reintentos--;

		}while(reintentos>=0);
	}
	return vRetorno;
}

int controller_ListarArticulos(LinkedList* pArrayListaArticulo, LinkedList* pArrayListaRubro)
{
	int vRetorno = -1;
	int largo;
	int i;
	eArticulo* pArticulo;

	if(pArrayListaArticulo!= NULL && pArrayListaRubro != NULL )
	{
		largo = ll_len(pArrayListaArticulo);

		if(largo>0)
		{
			printf("+----------+--------------------------------------------------+--------------------+--------------------+------------------------------+\n");
			printf("|    ID    |                     ARTICULO                     |       MEDIDA       |       PRECIO       |             RUBRO            |\n");
			printf("+----------+--------------------------------------------------+--------------------+--------------------+------------------------------+\n");
			for(i=0;i<largo;i++)
			{
				pArticulo = ll_get(pArrayListaArticulo, i);
				if(pArticulo!= NULL)
				{
					if(!articulo_imprimir(pArticulo, pArrayListaRubro))
					{
						vRetorno = 0;
					}
				}
			}
		}
		else
		{
			printf("\n Es necesario cargar los articulos del Datos_SP_LABO.csv antes de realizar el listado.\n ");
		}
	}
    return vRetorno;
}
int controller_ordenarArticulos(LinkedList* pArrayListaArticulos, LinkedList* pArrrayListaRubro)
{
	int vRetorno = -1;
	int len;

	if(pArrayListaArticulos != NULL){

		len = ll_len(pArrayListaArticulos);
		if(len>0){

			if (!ll_sort(pArrayListaArticulos, articulo_compararPorArticulo, 1)
				&& !controller_ListarArticulos(pArrayListaArticulos, pArrrayListaRubro))
			{
				vRetorno=0;
				printf(" Listado finalizado.\n ");
			}

		}else
		{
			printf("\n Es necesario cargar los articulos del Datos_SP_LABO.csv antes de ordenar.\n ");
		}
	}

    return vRetorno;
}
int controller_tomarNombreArchivo(char *path, int largoNombre,
		char* nombreEsperado, char* mensaje, char* mesanjeError)
{
	int vRetorno = -1;
	char auxNombreArchivo[largoNombre];
	int reintentos = REINTENTOS;

	if(path != NULL && largoNombre>0 && nombreEsperado != NULL
			&& mensaje != NULL && mesanjeError != NULL)
	{
		do
		{
			if(!utn_getTexto(auxNombreArchivo, largoNombre, mensaje, mesanjeError, 0))
			{

				if(strcmp(nombreEsperado,auxNombreArchivo) == 0)
				{
					strcpy(path,auxNombreArchivo);
					strcat(path,".csv");
					vRetorno = 0;
					break;
				}
				printf("%s",mesanjeError);
			}
			reintentos--;
		}while(reintentos>=0);
	}
	return vRetorno;
}

void controller_calcularDescuentos(void* pArticulo)
{
	int auxRubroId;
	float auxPrecio;

	if(pArticulo != NULL)
	{
		articulo_tomarIdRubro((eArticulo*)pArticulo, &auxRubroId);
		articulo_tomarPrecio((eArticulo*)pArticulo, &auxPrecio);

		switch(auxRubroId)
		{
		case 1:
			if(auxPrecio>=120)
			{
				auxPrecio = auxPrecio*0.8;
				articulo_cargarPrecio(pArticulo, auxPrecio);
			}
			break;
		case 2:
			if(auxPrecio<=200)
			{
				auxPrecio = auxPrecio*0.9;
				articulo_cargarPrecio(pArticulo, auxPrecio);
			}
			break;
		}
	}
	return;
}
int controller_mapear(LinkedList* pArrayListaArticulo, LinkedList* pArrayListaRubro)
{
	int vRetorno = -1;
	if(pArrayListaArticulo!= NULL )
	{
		if(ll_len(pArrayListaArticulo)>0)
		{
			ll_map(pArrayListaArticulo, controller_calcularDescuentos);
			vRetorno =0;
		}else
		{
			printf("\n Es necesario cargar los articulos del Datos_SP_LABO.csv antes de realizar el descuento.\n ");
		}
	}
	return vRetorno;

}

int controller_saveAsText(char* path , LinkedList* pArrayListaArticulo)
{
	int vRetorno = -1;
	FILE* fp;
	int largo;
	int i;
	eArticulo* pArticulo;
	eArticulo auxArticulo;

	if(pArrayListaArticulo!= NULL && path!= NULL){
		fp = fopen(path, "w");
		largo = ll_len(pArrayListaArticulo);
		if(largo>0)
		{
			if(fp != NULL)
			{
				fprintf(fp,"id,articulo,medida,precio,rubroId\n");
				for(i=0;i<largo;i++)
				{
					pArticulo = (eArticulo* )ll_get(pArrayListaArticulo, i);

					if(!articulo_tomarId(pArticulo, &auxArticulo.id) &&
						!articulo_tomarDescArticulo(pArticulo, auxArticulo.articulo) &&
						!articulo_tomarMedida(pArticulo, auxArticulo.medida) &&
						!articulo_tomarPrecio(pArticulo, &auxArticulo.precio) &&
						!articulo_tomarIdRubro(pArticulo, &auxArticulo.rubroId))
					{
						fprintf(fp,"%d,%s,%s,%f,%d\n",auxArticulo.id,
								auxArticulo.articulo,auxArticulo.medida,
								auxArticulo.precio,auxArticulo.rubroId);
					}
				}
				vRetorno = 0;
				fclose(fp);
			}
		}else
		{
			printf("\n Es necesario cargar los articulos del Datos_SP_LABO1.csv antes de dar el alta.\n ");
		}
	}
	return vRetorno;
}

int controller_validaMayor100(void* pArticulo)
{
	int vRetorno = 0;
	float auxPrecio;

	if(pArticulo != NULL)
	{
		articulo_tomarPrecio((eArticulo*)pArticulo, &auxPrecio);
		if(auxPrecio>100)
		{
			vRetorno = 1;
		}
	}
	return vRetorno;
}
int controller_validaRubro1(void* pArticulo)
{
	int vRetorno = 0;
	int auxIdRubro;

	if(pArticulo != NULL)
	{
		articulo_tomarIdRubro((eArticulo*)pArticulo, &auxIdRubro);
		if(auxIdRubro==1)
		{
			vRetorno = 1;
		}
	}
	return vRetorno;
}

int controller_informes(LinkedList* pArrayListaArticulo)
{
	int vRetorno = -1;
	int vOpcionSubMenu;
	int vRespuestaVolver = 0;
	int cantidad;

	if(pArrayListaArticulo != NULL)
	{

		if(ll_len(pArrayListaArticulo)){
			do{
				do {
					system("cls");

					printf("---------------------------------INFORMES----------------------------------\n");
					printf(" 1.Cantidad de Articulos cuyo precio sea mayor a $100.\n");
					printf(" 2.Cantidad de Articulos del Rubro 1-CUIDADO DE ROPA \n");
					printf(" 3.Volver\n");
					printf("---------------------------------------------------------------------------\n");

				} while (utn_getNumero(&vOpcionSubMenu,
						" Ingrese la opcion que desea: ",
						" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
						1, 3, 0) == -1);
				system("cls");

				switch(vOpcionSubMenu){
				case 1:
					cantidad=ll_count(pArrayListaArticulo, controller_validaMayor100);
					if(cantidad>0)
					{
						printf("La cantidad de articulos de precio mayor o igual a 100 es de: %d.\n Informe finalizado. \n ", cantidad);
					}
					else
					{
						printf("No hay articulos con precio mayor o igual a 100.\n Informe finalizado. \n ");
					}
					system("pause");
					vRetorno = 0;
					break;
				case 2:
					cantidad=ll_count(pArrayListaArticulo, controller_validaRubro1);
					if(cantidad>0)
					{
						printf("La cantidad de articulos del Rubro 1-CUIDADO DE ROPA es de: %d.\n Informe finalizado. \n ", cantidad);
					}
					else
					{
						printf("No hay articulos del Rubro 1-CUIDADO DE ROPA.\n Informe finalizado. \n ");
					}
					system("pause");
					vRetorno = 0;
					break;
				case 3://Pregunto si desea volver al menu
					do {
						vRespuestaVolver = unt_preguntaRespuestaBinaria(
								" Desea volver?(s/n) ", 's', 'n');
						system("cls");
					} while (vRespuestaVolver == -1);
					break;
				}
			} while (vRespuestaVolver == 0); //Siempre que la respuesta de salida sea 0 vuelvo a iterar
		}
		else
		{
			printf("\n Es necesario cargar los articulos del Datos_SP_LABO1.csv antes de realizar los informes.\n ");
		}

	}
	return vRetorno;
}
