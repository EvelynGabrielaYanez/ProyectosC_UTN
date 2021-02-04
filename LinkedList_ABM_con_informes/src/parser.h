/*
 * parser.h
 *
 *  Created on: 3 nov. 2020
 *      Author: CLEM
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef PARSER_H_
#define PARSER_H_


#endif /* PARSER_H_ */
/** @brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile Puntero al archivo.
 * @param pArrayListaArticulos LinkedList* Puntero la LinkedList que se guardara.
 * @return	Int. Retorna (-1) en caso de ERROR- (0) en caso de EXITO.
 *
 */
int parser_articuloDeTexto(FILE* pFile , LinkedList* pArrayListaArticulos);
