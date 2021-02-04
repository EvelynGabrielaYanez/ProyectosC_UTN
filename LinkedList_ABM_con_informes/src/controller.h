/*
 * controller.h
 *
 *  Created on: 22 nov. 2020
 *      Author: CLEM
 */
#include "rubro.h"
#include "Articulo.h"

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_



#endif /* SRC_CONTROLLER_H_ */
/**
 * @brief Muesta el menu, pide el ingreso de una de las opciones, lo valida y la retorna.
 *
 * @return	Int. Retonra la opciones seleccionada.
 */
int controller_menu();
/** @brief Carga los datos de los articulos desde el archivo Datos_SP_LABO1.csv (modo texto).
 *
 * @param path char* Cadena de caracteres con la direccion del archivo a cargar.
 * @param pArrayListaArticulos LinkedList*	Puntero a la linkedlist donde se cargara.
 * @param idArticulo Int. Siguiente id a cargar (autonumerico)
 * @return int	Retorna (-1) en caso de error - (Maximo id cargado) en caso de EXITO
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListaArticulos, int* idArticulo);
/**
 * @brief	Busca el index del articulo segun el id pasado por parametro.En caso de encontrarlo lo
 * 			retorna en el puntero index pasado por paramentro.
 *
 * @param pArrayListaArtoculo	LinkedList* Puntero a la Linkedlist donde se buscara.
 * @param index	Puntero donde retornara el index en caso de encontrarse.
 * @param Id	Int. Id del que se buscara el index.
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR (Puntero nulo,
 * 			id invalido, index no encontrado)
 */
int controller_buscarIndexArtPorId(LinkedList* pArrayListaArtoculo,int* index, int id);
/**
 * @brief	Lista los articulos con sus conrrespondientes Id, pide el ingreso de una de estas, la valida
 * 			y en caso afirmativo retorna la direccion de memoria del articulo correspondiente.
 *
 * @param pArrayListaArticulos LinkedList* Puntero a la Linkedlist de Articulos.
 * @param pArrayListaRubro	LinkedList* Puntero a la Linkedlist de Rubros.
 * @param pArticulo	puntero al puntero pArticulo donde se retornara la direccionde memoria del articulo seleccionado.
 * @param reintentos	Cantidad de reintentos que tendra el usuario para ingreasr el id.
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, reintentos invalido, sin reintentos).
 */
int controller_tomarAriculoPorId(LinkedList* pArrayListaArticulos,LinkedList* pArrayListaRubro,
		eArticulo **pArticulo, int reintentos);
/**
 * @brief	Lista los articulos cargados en la linkedlist Artoculo con la descripcion del rubro
 * 			correspondiente segun su id rubro.
 *
 * @param pArrayListaArticulo LinkedList* Puntero a la Linkedlist de Articulos.
 * @param pArrayListaRubro	LinkedList* Puntero a la Linkedlist de Rubros.
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR ( puntero nulo, no hay articulos cargados).
 */
int controller_ListarArticulos(LinkedList* pArrayListaArticulo, LinkedList* pArrayListaRubro);
/**
 * @brief	Ordena los articulos por descripcion de articulo de forma ascendente y los lista ordenados.
 *
 * @param pArrayListEmployee LinkedList* Puntero a la Linkedlist de Articulos.
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR ( puntero nulo, no hay articulos cargados).
 */
int controller_ordenarArticulos(LinkedList* pArrayListaArticulos, LinkedList* pArrrayListaRubro);
/**
 * @brief	Le pide al usuario el ingreso del nombre del archivo, valida que este sea igual al esperado. En caso afirmativo
 * 			le concatena al nombre ".csv" el formato del archivo y retorna la cadena concatenada en la cadena de caracteres path.
 *
 * @param path	Cadena de caracteres donde retornara el nombre-ruta del archivo.
 * @param largoNombre	largo esperado del nombre del archivo.
 * @param nombreEsperado	Cadena de caracteres con el nombre del archivo esperado.
 * @param mensaje	Cadena de caracteres con el mensaje a mostrar para el pedido de ingreso.
 * @param mesanjeError	Cadena de caracteres con el mensaje de error a mostrar.
 * @return	Int. Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo valido, sin reintentos).
 */
int controller_tomarNombreArchivo(char *path, int largoNombre,
		char* nombreEsperado, char* mensaje, char* mesanjeError);
/**
 * @brief	Le realiza un descuento al precio del articulo pasado por puntero.
 * 			precio = 0.8*precio si el id del rubro es igual a 1 y precio>=120
 * 			precio = 0.9*precio si el id del runro es igual a 2 y precio <=200
 *
 * @param pArticulo	Puntero al articulo al que se le descontara.
 */
void controller_calcularDescuentos(void* pArticulo);
/**
 * @brief	Recorre la linkedlist y le aplica el descuento correspondiete a los casos
 * 			cond id de rubro 1 y orecio >= 120, y id de rubro 2 y precio <=200.
 *
 * @param pArrayListaArticulo LinkedList* Puntero a la Linkedlist de Articulos.
 * @param pArrayListaRubro LinkedList* Puntero a la Linkedlist de Rubro.
 * @return	Int. Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo)
 */
int controller_mapear(LinkedList* pArrayListaArticulo, LinkedList* pArrayListaRubro);
/**
 * @brief Guarda los datos de los articulos en el archivo (modo texto).
 *
 * @param path Nombre del archivo donde se guardara.
 * @param pArrayListaArticulo LinkedList* Puntero a la Linkedlist de Articulos.
 * @return	Int. Retorna (-1) en caso de ERROR (puntero nulo, error al guardar)- (0) en caso de EXITO.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListaArticulo);
/**
 * @brief	Imprime el submenu de informes, pide la seleccion de una opcion por
 * 			 parte del usuario y la realiza.
 *
 * @param listaArticulos LinkedList* Puntero a la Linkedlist de Articulos.
 * @return	Int. Retorna (-1) en caso de ERROR (puntero nulo)- (0) en caso de EXITO.
 */
int controller_informes(LinkedList* pArrayListaArticulo);
/**
 * @brief	Valida si es un un articulo de precio mayor a 100
 *
 * @param pArticulo Puntero al articulo a validar.
 * @return Int. Retorna (0) si es VALIDO - (-1) si es INVALIDO
 */
int controller_validaMayor100(void* pArticulo);
/**
 * @brief	Valida si es un un articulo de rubro 1.
 *
 * @param pArticulo Puntero al articulo a validar.
 * @return Int. Retorna (0) si es VALIDO - (-1) si es INVALIDO
 */
int controller_validaRubro1(void* pArticulo);
