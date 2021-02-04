
#include "../inc/LinkedList.h"
#include "Articulo.h"
#include "parser.h"

int parser_articuloDeTexto(FILE* pFile , LinkedList* pArrayListaArticulos)
{
	int vRetorno = -1;
	char auxId[4096];
	char auxDescArticulo[LARGO_ARTICULO];
	char auxMedidas[4096];
	char auxPrecio[4096];
	char auxRubroId[4096];
	char auxIndice[4096];
	eArticulo* pArticulo;
	int idMax=-1;

	if(pFile!=NULL && pArrayListaArticulos!= NULL)
	{
		fscanf(pFile,"%[^\n]\n",auxIndice);
		do{
			vRetorno = -1;

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescArticulo,auxMedidas,auxPrecio,auxRubroId) == 5)
			{
				pArticulo = articulo_nuevoParametros(auxId, auxDescArticulo, auxMedidas, auxPrecio, auxRubroId);

				if(pArticulo!= NULL)
				{
					if(!ll_add(pArrayListaArticulos, pArticulo))
					{
						if(idMax<atoi(auxId)){
							idMax = atoi(auxId);
							vRetorno = idMax+1;
						}

					}else{
						vRetorno = -1;
						break;
					}
				}else{
					ll_clear(pArrayListaArticulos);
					vRetorno = -1;
					break;
				}
			}
		}while(!feof(pFile));

	}
    return vRetorno;
}


/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int vRetorno = -1;
	char auxId[4096];
	char auxHorasTrabajadas[4096];
	char auxSueldo[4096];
	Employee Empleado;
	Employee *pEmpleado;
	int idMax=-1;


	if(pFile!=NULL && pArrayListEmployee!= NULL)
	{
		do{
			if(fread(&Empleado, sizeof(Employee),1,pFile) == 1)
			{
				sprintf(auxId,"%d",Empleado.id);
				sprintf(auxHorasTrabajadas,"%d",Empleado.horasTrabajadas);
				sprintf(auxSueldo,"%d",Empleado.sueldo);

				pEmpleado = employee_newParametros(auxId, Empleado.nombre, auxHorasTrabajadas, auxSueldo);
				if(pEmpleado!= NULL)
				{
					if(!ll_add(pArrayListEmployee, pEmpleado))
					{
						if(idMax<Empleado.id)
						{
							idMax = Empleado.id;
							vRetorno = idMax+1;
						}
					}else
					{
						vRetorno = -1;
						break;
					}
				}else
				{
					vRetorno = -1;
					break;
				}
			}
		}while(!feof(pFile));
	}
    return vRetorno;
}
*/
