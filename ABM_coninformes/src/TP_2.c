/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#include "ArrayEmpleados.h"
#include "TP_2_modulos.h"

#define EMPLEADOS 1000

int main(void) {

	setbuf(stdout, NULL);

	eEmpleado listaEmpleados[EMPLEADOS];

	int vRespSalir = 0; //0 = no, 1 = si
	int vContadorId = 0;

	if (inicializarEmpleados(listaEmpleados, EMPLEADOS)== 0)
	{
		//vContadorId+= hardcodearEmpleados(listaEmpleados,EMPLEADOS, 10);

		do {
			switch (menu()) {
			case 1:
				altas(listaEmpleados, EMPLEADOS, &vContadorId);
				system("pause");
				break;
			case 2:
				modificar(listaEmpleados, EMPLEADOS);
				break;
			case 3:
				baja(listaEmpleados, EMPLEADOS);
				system("pause");
				break;
			case 4:
				informar(listaEmpleados, EMPLEADOS);
				system("pause");
				break;
			case 5:
				do{//Pregunto si desea salir hasta que ingrese s o n.
					vRespSalir = unt_preguntaRespuestaBinaria("\n Desea Salir?(s/n) ", 's', 'n');
					system("cls");
				}while(vRespSalir==-1);
				break;
			}
		} while (vRespSalir == 0); // Mientras vRespSalir = n continuo en el menu
	}
	return 0;
}
