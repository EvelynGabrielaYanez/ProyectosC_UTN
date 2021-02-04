/*
 * Articulo.h
 *
 *  Created on: 21 nov. 2020
 *      Author: CLEM
 */
#include "../inc/LinkedList.h"
#include "rubro.h"

#ifndef SRC_ARTICULO_H_
#define SRC_ARTICULO_H_

#define LARGO_ARTICULO 41
#define LARGO_MEDIDA 31

typedef struct
{
    int id;
    char articulo[51];
    char medida[51];
	float precio;
	int rubroId;

}eArticulo;

#endif /* SRC_ARTICULO_H_ */

/**
 * @brief Coloca el id pasado como parametro al Articulo pasado por puntero.
 *
 * @param this	Puntero al articulo.
 * @param id	Int. Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarId(eArticulo* this,int id);
/**
 * @brief Coloca el id pasado como cadena de caracteres al Articulo pasado por puntero.
 *
 * @param this	Puntero al articulo.
 * @param id Cadena de caracteres.Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarIdTxt(eArticulo* this,char* id);
/**
 * @brief  Toma el id del Articulo pasado por puntero y lo retorna en el id pasado como puntero a Int.
 *
 * @param this	Puntero al articulo.
 * @param id Puntero a int donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarId(eArticulo* this,int* id);
/**
 * @brief  Toma el id del Articulo pasado por puntero y lo retorna en el id pasado como cadena de Caracteres.
 *
 * @param this	Puntero al articulo.
 * @param id Cadena de caracteres donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarIdTxt(eArticulo* this,char* id);
/**
 * @brief Coloclar el articulo pasado como cadena de caracteres al eArticulo pasado por puntero.
 *
 * @param this Puntero al eArticulo.
 * @param articulo	Cadena de caracteres.Articulo a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarDescArticulo(eArticulo* this,char* articulo);
/**
 * @brief  Toma el articulo del eArticulo pasado por puntero y
 *  lo retorna en el nombre pasado como cadena de Caracteres.
 *
 * @param this Puntero al eArticulo.
 * @param articulo	Cadena de caracteres. Articulo a tomar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarDescArticulo(eArticulo* this,char* articulo);
/**
 * @brief  Coloca la medida pasada como cadena de caracteres al Articulo pasado por puntero.
 *
 * @param this Puntero al articulo.
 * @param medida Cadena de Caracteres. Medida a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarMedida(eArticulo* this,char* articulo);
/**
 * @brief  Toma la medida del Articulo pasada por puntero y
 * 			la retorna en el parametro pasado
 * 			como cadena de Caracteres.
 *
 * @param this Puntero al articulo.
 * @param medida Cadena de Caracteres. medida a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarMedida(eArticulo* this,char* articulo);

/**
 * @brief  Coloca el precio pasado como parametro al Articulo pasado por puntero.
 *
 * @param this Puntero al articulo.
 * @param precio Float.Precio a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarPrecio(eArticulo* this,float precio);
/**
 * @brief  Coloca el precio pasado como cadena de caracteres al Articulo pasado por puntero.
 *
 * @param this Puntero al articulo.
 * @param precio Cadena de Caracteres. Precio a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarPrecioTxt(eArticulo* this,char* precio);
/**
 * @brief  Toma el precio del Articulo pasado por puntero y
 * 			lo retorna por el puntero a flotante pasado por parametro.
 *
 * @param this Puntero al articulo.
 * @param precio Float.Precio a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarPrecio(eArticulo* this,float* precio);
/**
 * @brief  Toma el precio del Articulo pasado por puntero y
 * 			lo retorna en el parametro pasado
 * 			como cadena de Caracteres.
 *
 * @param this Puntero al articulo.
 * @param precio Cadena de Caracteres. Precio a colocar.
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarPrecioTxt(eArticulo* this,char* precio);

/**
 * @brief Coloca el id pasado como parametro al Articulo pasado por puntero.
 *
 * @param this	Puntero al articulo.
 * @param rubroId	Int. Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarIdRubro(eArticulo* this,int rubroId);
/**
 * @brief Coloca el id pasado como cadena de caracteres al Articulo pasado por puntero.
 *
 * @param this	Puntero al articulo.
 * @param rubroId Cadena de caracteres.Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int articulo_cargarIdRubroTxt(eArticulo* this,char* rubroId);
/**
 * @brief  Toma el id del Articulo pasado por puntero y lo retorna en el id pasado como puntero a Int.
 *
 * @param this	Puntero al articulo.
 * @param rubroId Puntero a int donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarIdRubro(eArticulo* this,int* rubroId);
/**
 * @brief  Toma el id del Articulo pasado por puntero y lo retorna en el id pasado como cadena de Caracteres.
 *
 * @param this	Puntero al articulo.
 * @param rubroId Cadena de caracteres donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int articulo_tomarIdRubroTxt(eArticulo* this,char* rubroId);
/**
 * @brief Crea un nuevo articulo y devuelve la direccionde memoria del mismo.
 * 		 Si no pudo crearlo devuelve NULL.
 *
 * @return	Retorno al espacio de memoria del nuevo articulo.
 */
eArticulo* articulo_nuevo();
/**
 * @brief Creo un nuevo articulo y devuelve la direccionde memoria del mismo
 * 		  si no pudo crearlo devuelve NULL.
 *
 * @param idStr Id como cadena de caracteres con el que se inicializara
 * @param articuloStr descripcion del ariticulo como cadena de caracteres con el que se inicializara
 * @param medidaStr medidas como cadena de caracteres con las que se inicializara
 * @param precioStr precio como cadena de caracteres con el que se inicializara
 * @param rubroIdStr id del rubro como cadena de caracteres con el que se inicializara
 * @return	Puntero al eArticulo creado o NULL si no se pudo crear.
 */
eArticulo* articulo_nuevoParametros(char* idStr,char* articuloStr,char* medidaStr,char* precioStr, char* rubroIdStr);
/**
 * @brief Elimino el eArticulo.
 *
 * @param this  Puntero al eArticulo que se desea eliminar.
 */
void articulo_borrar(eArticulo* this);
/**
 * @brief Imprime el eArticulo pasado por puntero.
 *
 * @param this Puntero al eArticulo.
 * @param listaRubro Puntero al Linedlist de eRubro
 * @return  Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 *
 */
int articulo_imprimir(eArticulo* this, LinkedList* listaRubro);
/**
 * @brief	Compara los articulos por id, retonra -1 en caso de ser id1<id2,
 * 			0 en caso de ser id1 = id2 y 1 en caso de ser id1>id2.
 *
 * @param pArticulo1 Puntero al eArticulo1.
 * @param pArticulo2 Puntero al eArticulo2.
 *
 * @return  Int.Retorna (0) si id_articulo1 = id_articulo2
 * 			- (-1) si id_articulo1 < id_articulo2
 * 			- (-1) si id_articulo1 > id_articulo2
 */
int articulo_compararPorId(void* pArticulo1,void* pArticulo2);
/**
 * @brief	Compara los articulos por descripcion de articulo,
 * 			retonra -1 en caso de ser descArticulo1<descArticulo2,
 * 			0 en caso de ser descArticulo1 = descArticulo2 y
 * 			1 en caso de ser descArticulo1>descArticulo2.
 *
 * @param pArticulo1 Puntero al eArticulo1.
 * @param pArticulo2 Puntero al eArticulo2.
 *
 * @return  Int.Retorna (0) si descArticulo1 = descArticulo2
 * 			- (-1) si descArticulo1 < descArticulo2
 * 			- (-1) si descArticulo1 > descArticulo2
 */
int articulo_compararPorArticulo(void* pArticulo1,void* pArticulo2);
