/*
 * Confederaciones.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Confed.h"
#include "Gets.h"



int searchConfed(eConfederacion vec[], int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < TAM_CONF; i++)
        {

            if( vec[i].id == id)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }

    }
    return todoOk;
}


void confed_showConfederation(eConfederacion confederacion)
{

    printf("  %3d    %-10s    %-22s    %10d\n",
           confederacion.id,
           confederacion.nombre,
		   confederacion.region,
		   confederacion.anioCreacion);
}

int confed_listConfederations(eConfederacion confederaciones[]) //tamaño por Define
{
    int todoOk = 0;

	if(confederaciones != NULL)
	{
		printf("\n                ***   CONFEDERACIONES   ***\n");
		printf("===================================================================\n");
		printf("| ID   | NOMBRE      |     REGION                |  AÑO CREACION |\n");
		printf("-------------------------------------------------------------------\n");
		for(int i = 0; i < TAM_CONF; i++)
		{
			if(confederaciones[i].id !=-1)
			{
				confed_showConfederation(confederaciones[i]);
			}
		}
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}

int confed_loadConfederation(eConfederacion confederaciones[], int idConfederacion , char nombreConfed[])
{
	int todoOk = 0;
	if(confederaciones != NULL && nombreConfed != NULL)
	{
		for(int i = 0; i < TAM_CONF; i++)
		{
			if(confederaciones[i].id == idConfederacion)
			{
				strcpy(nombreConfed, confederaciones[i].nombre);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;

}

int menuConfed()
{
    int opcion = -1;

	do{
		printf("\n--------------------------------\n\n");
		printf("   1. Alta Confederacion\n");
		printf("   2. Baja Confederacion \n");
		printf("   3. Modificación de Confederacion \n");
		printf("   4. Salir.\n\n");

		opcion = gets_getNumerInt("--> Ingrese opcion: ", "ERROR. Opcion inválida", 1, 4);


	}while(opcion<1 || opcion>4);

    return opcion;
}


int menu_menuModifyConfed()
{
    int opcion = -1;

	do{
		printf("\n-----Elija la modificacion a realizar-----\n\n");
		printf("   1. Nombre\n");
		printf("   2. Region \n");
		printf("   3. Aniod de Creacion \n");
		printf("   4. Salir de la modificación.\n\n");

		opcion = gets_getNumerInt("--> Ingrese opcion: ", "ERROR. Opcion inválida", 1, 4);

	}while(opcion<1 || opcion>4);

	return opcion;
}


int buscarFreeConfed(eConfederacion vec[], int* pIndex) // tamaño por Define
{

    int todoOk = 0;
    int indice = -1; // no hay lugar libre

    if( vec != NULL && pIndex != NULL)
    {

        for(int i=0; i < TAM_CONF; i++)
        {
            if(vec[i].id==-1) //
            {
                indice = i;
                break;
            }
        }
        *pIndex = indice; // recien aca pisa e imprime el valor

        todoOk = 1;
    }
    return todoOk;
}

int confed_addCondef(eConfederacion vec[], int* pNextConf, int* contConf)
{
    int todoOk = 0;
    int indice;
    eConfederacion nuevaConfed;

    if( vec != NULL && pNextConf != NULL )
    {
        printf("\n-------------- Alta CONFEDERACION ---------------\n");
        printf("---------------------------------------------\n\n");
        buscarFreeConfed(vec, &indice);

        if(indice == -1) //si no hay lugar
        {
            printf("*** No hay lugar en el sistema!!! ****\n");
        }
        else
        {
        	// ID autoincremental
            nuevaConfed.id = *pNextConf;

            // NOMBRE
            getValidStringRango("Ingrese nombre del jugador: ", "ERROR. Ingrese un Nombre válido: ", nuevaConfed.nombre, 50);
            printf("\n");


            //REGION
            getValidStringRango("Ingrese nombre de la Region: ", "ERROR. Ingrese un Nombre válido: ", nuevaConfed.region, 50);
            printf("\n");

			// ANIOS DE CREACION
			nuevaConfed.anioCreacion = gets_getNumerShort("Ingrese anio de creacion: ", "ERROR. Ingrese anios: ", 0, 100);
			printf("\n");


            //nuevaConfed.isEmpty = 0;

            vec[indice] = nuevaConfed;

            (*pNextConf)++;

            todoOk = 1;

            contConf++;

            printf("\n\n ***  Alta exitosa!!!  ***\n\n");

        }
    }
    return todoOk;
}





int confed_modifyConfed(eConfederacion vec[])
{
    int modificado = 0;
    int id = -1;
    int indice;


    if(vec != NULL)
    {
        printf("\n----------------------- Modificar CONFEDERACION ------------------------\n");
        printf("-------------------------------------------------------------------\n");


        	confed_listConfederations(vec);

			printf("\nIngrese Id de la Confederacion que desea modificar: ");
			fflush(stdin);
			scanf("%d", &id);


			if(id!=-1)
			{

				searchConfed(vec, id, &indice);

				if(indice == -1)
				{
					printf("No existe Confederacion con ese id: %d\n", id);
				}
				else
				{
					printf("\n");

					confed_showConfederation(vec[indice]);

						switch(menu_menuModifyConfed())
						{
						case 1:
							getValidStringRango("Ingrese nuevo nombre: ", "ERROR. Ingrese un Nombre válido: ", vec[indice].nombre, 50);
							modificado = 1;
							printf("\n");
							break;

						case 2:
							getValidStringRango("Ingrese nuevo nombre de Region: ", "ERROR. Ingrese un Nombre válido: ", vec[indice].nombre, 50);
							modificado = 1;
							printf("\n");
							break;
						case 3:
							vec[indice].anioCreacion = gets_getNumerShort("Ingrese anio de creacion: ", "ERROR. Ingrese anios: ", 0, 100);
							modificado = 1;
							printf("\n");
							break;
						}

						printf("\n\n ***  Modificación exitosa!!!  ***\n\n");

						confed_showConfederation(vec[indice]);
				}
			}
			else
			{
				printf("En ese paso se permiten sólo números. \n");
			}
    }
    return modificado;
}


int confed_eraseConfed(eConfederacion vec[],int* contConf)
{
    int borrado = 0;
    int indice;
    int id = -1;
    char confirma;
    if( vec != NULL)
    {
        printf("------------------------- Baja CONFEDERACION --------------------------\n");
        printf("--------------------------------------------------------------\n");

        	confed_listConfederations(vec);
			printf("\nIngrese Id del Confede que desea dar de baja: ");
			fflush(stdin);
			scanf("%d", &id);
			printf("\n");

			if(id!=-1)
			{
				if(searchConfed(vec, id, &indice))
				{
					if(indice == -1)
					{
						printf("No existe confederacion con el Id > %d < en el sistema\n", id);
					}
					else
					{

						confed_showConfederation(vec[indice]);
						printf("Confirma baja?('s' para confirmar, cualquier otro caracter para cancelar: ");
						fflush(stdin);
						scanf("%c", &confirma);

						if(confirma == 's' || confirma == 'S')
						{
							vec[indice].id = -1;
							printf("\n\n ***  Baja exitosa!!!  ***\n\n");
							borrado = 1;
							(*contConf)--;

							confed_listConfederations(vec);
						}
						else
						{
							printf("\nBaja cancelada por el usuario...\n");
						}

					}

				}
			}
			else
			{
				printf("En ese paso se permiten sólo números...: \n");
			}

    }
    return borrado;
}
