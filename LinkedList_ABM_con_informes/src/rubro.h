/*
 * rubro.h
 *
 *  Created on: 22 nov. 2020
 *      Author: CLEM
 */
#include "../inc/LinkedList.h"

#ifndef SRC_RUBRO_H_
#define SRC_RUBRO_H_

#define LARGO_DESC_RUBRO 31

typedef struct
{
    int id;
	char descripcion[LARGO_DESC_RUBRO];

}eRubro;

#endif /* SRC_RUBRO_H_ */

/**
 * @brief Coloca el id pasado como parametro al Rubro pasado por puntero.
 *
 * @param this	Puntero al eRubro.
 * @param id	Int. Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int rubro_cargarId(eRubro* this,int id);
/**
 * @brief Coloca el id pasado como cadena de caracteres al Rubro pasado por puntero.
 *
 * @param this	Puntero al eRubro.
 * @param id Cadena de caracteres.Id a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int rubro_cargarIdTxt(eRubro* this,char* id);
/**
 * @brief  Toma el id del Rubro pasado por puntero y lo retorna en el id pasado como puntero a Int.
 *
 * @param this	Puntero al eRubro.
 * @param id Puntero a int donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int rubro_tomarId(eRubro* this,int* id);
/**
 * @brief  Toma el id del Rubro pasado por puntero y lo retorna en el id pasado como cadena de Caracteres.
 *
 * @param this	Puntero al eRubro.
 * @param id Cadena de caracteres donde se retornara el ID.
 * @return	Int. Retorna (0) eb caso de EXITO - (-1) en caso de ERROR
 */
int rubro_tomarIdTxt(eRubro* this,char* id);

/**
 * @brief Coloclar la descripcion pasado como cadena de caracteres al eRubro pasado por puntero.
 *
 * @param this Puntero al eRubro.
 * @param descripcion	Cadena de caracteres.Rubro a colocar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int rubro_cargarDescripcion(eRubro* this,char* descripcion);
/**
 * @brief  Toma la descripcion del rubro pasado por puntero y
 *  lo retorna en el nombre pasado como cadena de Caracteres.
 *
 * @param this Puntero al eRubro.
 * @param descripcion	Cadena de caracteres. Rubro a tomar.
 * @return	Int.Retorna (0) en caso de EXITO - (-1) en caso de ERROR
 */
int rubro_tomarDescripcion(eRubro* this,char* descripcion);
/**
 * @brief Crea un nuevo rubro y devuelve la direccionde memoria del mismo.
 * 		 Si no pudo crearlo devuelve NULL.
 *
 * @return	Retorno al espacio de memoria del nuevo rubro.
 */
eRubro* rubro_nuevo();
/**
 * @brief Creo un nuevo rubro y devuelve la direccionde memoria del mismo
 * 		  si no pudo crearlo devuelve NULL.
 *
 * @param idStr Id como cadena de caracteres con el que se inicializara
 * @param descripcionStr descripcion del rubro como cadena de caracteres con el que se inicializara
 * @return	Puntero al eArticulo creado o NULL si no se pudo crear.
 */
eRubro* rubro_nuevoParametros(char* idStr,char* descripcionStr);

/**
 * @brief Imprime el rubro pasado por parametro
 *
 * @param lista	Puntero al rubro.
 * @param largo
 * @param id
 * @return
 */
int mostarRubro(eRubro* this);
/**
 * @brief busca el indice del rubro con el id pasado por paramentro. Si existe lo retorna y si no retorna -1
 *
 * @param listaRubro Puntero a la LinkedList de eRubro
 * @param idRubro	Int. Id buscado.
 * @return	Int. Retorna (-1) en caso de ERRO (puntero nulo, id invalido, id no perteneciente al linkedlist)
 * 			- (Index con dicho id) en caso de encontrarlo con EXITO.
 */
int rubro_buscarPorID(LinkedList* listaRubro, int idRubro);
/**
 * @brief	Carga la descripcion del rubro con el id pasado por parametro en caso de existir el mismo.
 *
 *
 * @param listaRubro
 * @param idRubro
 * @param descripcion
 * @return
 */
int rubro_cargarDescPorID(LinkedList* listaRubro, int idRubro, char* descripcion);
/**
 * @brief	Hardcodea la likedlist de rubro
 *
 * @param listaRubros	Puntero a linkedlist de rubros
 * @param cantidad	cantidad a hardcodear
 * @return	Int. En caso de EXITO retorna la cantidad hardcodeada
 * 			- (-1) en caso de ERROR
 */
int rubro_hardcodearRubro(LinkedList* listaRubros, int cantidad);
