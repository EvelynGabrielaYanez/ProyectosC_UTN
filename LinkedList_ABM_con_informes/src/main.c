/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "utn_validaciones.h"
#include "Articulo.h"
#include "rubro.h"
#include "controller.h"

int main(void)
{
		setbuf(stdout, NULL);
	  LinkedList* listaArticulos= ll_newLinkedList();
	  LinkedList* listaRubros = ll_newLinkedList();
	  int vRespSalir = 0;
	  int idArticulo;
	  char path[19];
	  int vBanderaMapeo = 0;

	  rubro_hardcodearRubro(listaRubros, 4);

		do {
				switch (controller_menu()) {
				case 1:
					if(!controller_tomarNombreArchivo(path,15, "Datos_SP_LABO1",
							" Ingrese el nombre del archivo(Datos_SP_LABO1): "
							, " El nombre ingresado es invalido.") &&
						!controller_loadFromText(path , listaArticulos, &idArticulo))
					{
						printf(" Carga exitosa.\n ");
					}else{
						printf(" No se realizo la carga.\n ");
					}
					system("pause");
				break;
				case 2:
					if(!controller_ordenarArticulos(listaArticulos, listaRubros))
					{
						printf(" Ordenado correctamente.\n ");
					}else{
						printf(" No se pudo ordenar.\n ");
					}
					system("pause");
					break;
				case 3:
					if(!controller_ListarArticulos(listaArticulos, listaRubros))
					{
						printf(" Listado finalizado.\n ");
					}else{
						printf(" No se pudo realizar el listado.\n ");
					}
					system("pause");
					break;
				case 4:
					if(vBanderaMapeo == 0)
					{
						if( !controller_mapear(listaArticulos, listaRubros) &&
								!controller_ListarArticulos(listaArticulos, listaRubros))
						{
							vBanderaMapeo = 1;
							printf(" Descuento realizado\n ");
						}else{
							printf(" No se pudo realizar el descuento.\n ");
						}
					}else
					{
						printf(" No se pudo realizar el descuento.\n Este ya fue ralizado con anterioridad\n ");
					}
					system("pause");
					break;
				case 5:
					if(vBanderaMapeo == 1 && !controller_saveAsText("mapeado.csv", listaArticulos))
					{
						printf(" Archivo creado. \n ");
					}
					else
					{
						printf(" No se puede generar el archivo mapeado.csv si no se realizo el descuento.\n");
					}
					system("pause");
					break;
				case 6:
					if(!controller_informes(listaArticulos))
					{
						printf(" Informe finalizado. \n ");
					}
					else
					{
						printf(" No se realizo ningun informe.\n");
					}
					system("pause");
					break;
				case 7:
					do{
					//Pregunto si desea salir hasta que ingrese s o n.
					vRespSalir = unt_preguntaRespuestaBinaria("\n Desea Salir?(s/n) ", 's', 'n');
					system("cls");
					}while(vRespSalir==-1);
					break;
				}

			} while (vRespSalir == 0); // Mientras vRespSalir = n continuo en el menu



    return 0;
}
