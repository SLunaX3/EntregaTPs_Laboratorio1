/*
 * Jugadores.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugadores.h"
#include "Informes.h"



int inicializarJugador(eJugador vec[]) // tamaño por Define
{
    int todoOk = 0;
    if(vec != NULL)
    {
        for(int i=0; i < TAM_JUG; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarFree(eJugador vec[], int* pIndex) // tamaño por Define
{

    int todoOk = 0;
    int indice = -1; // no hay lugar libre

    if( vec != NULL && pIndex != NULL)
    {

        for(int i=0; i < TAM_JUG; i++)
        {
            if(vec[i].isEmpty == 1) // ==1 hay estructura vacía
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



int jugadores_addPlayer(eJugador vec[], eConfederacion confederaciones[], int* pNextJugador, int* contJugadores)
{
    int todoOk = 0;
    int indice;
    eJugador nuevoJugador;
    char posicion[50];

    if( vec != NULL && pNextJugador != NULL && confederaciones != NULL)
    {
        printf("\n-------------- Alta Jugador ---------------\n");
        printf("---------------------------------------------\n\n");
        buscarFree(vec, &indice);

        if(indice == -1) //si no hay lugar
        {
            printf("*** No hay lugar en el sistema!!! ****\n");
        }
        else
        {
        	// ID autoincremental
            nuevoJugador.id = *pNextJugador;

            // NOMBRE COMPLETO
            getValidStringRango("Ingrese nombre del jugador: ", "ERROR. Ingrese un Nombre válido: ", nuevoJugador.nombre, TAM_NOMBRE);
            printf("\n");

            // POSICION
            sets_setPositions(posicion);
            strcpy(nuevoJugador.posicion, posicion);
            printf("\n");

            //NUMERO DE CAMISETA
			nuevoJugador.numeroCamisa = gets_getNumerShort("Ingrese número de camiseta del jugador: ", "ERROR. Ingrese una número entre 1 y 99: ", 1, 99);
			printf("\n");

			// CONFEDERACION
            confed_listConfederations(confederaciones);
            nuevoJugador.idConfederacion = gets_getNumerInt("Ingrese Id de la Confederación del jugador: ", "ERROR. Ingrese una confederación listada: ", 100, 105);
            printf("\n");

            // SALARIO
			nuevoJugador.salario = gets_getNumerFloat("Ingrese salario del jugador: $ ", "ERROR. Ingrese un monto del salario: $", 0, 1000000);
			printf("\n");

			// ANIOS DE CONTRATO
			nuevoJugador.aniosContrato = gets_getNumerShort("Ingrese anios de contrato del jugador: ", "ERROR. Ingrese anios: ", 0, 11);
			printf("\n");


            nuevoJugador.isEmpty = 0;

            vec[indice] = nuevoJugador;

            (*pNextJugador)++;

            todoOk = 1;

            (*contJugadores)++;

            printf("\n ***  Alta exitosa!!!  ***\n\n");

            jugadores_showPlayer(nuevoJugador, confederaciones);


        }
    }
    return todoOk;
}


int jugadores_showPlayer(eJugador unJugador, eConfederacion confederaciones[])
{
    int todoOk = 0;
	char nombreConfed[50];

    if(confederaciones!=NULL)
    {
    	confed_loadConfederation(confederaciones, unJugador.idConfederacion, nombreConfed);

		printf(" %2d      %-50s             %-20s   %4hd              %-15s    %-15.2f   %-6hd\n",
			   unJugador.id,
			   unJugador.nombre,
			   unJugador.posicion,
			   unJugador.numeroCamisa,
			   nombreConfed,
			   unJugador.salario,
			   unJugador. aniosContrato);

		todoOk = 1;
    }

    return todoOk;
}


int jugadores_listPlayers(eJugador vec[],  eConfederacion confederaciones[])
{
    int todoOk = 0;
    int flag = 1;

    if( vec != NULL)
    {
    	printf("\n                ***   JUGADORES   ***\n"
    			"-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    			"  ID  |   Nombre                                                |       Posicion         |     Camisa   |        Confed.     |      Salario     |  Anios de Contrato   \n"
    			"---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    	for(int i=0; i < TAM_JUG; i++)
        {
            if( vec[i].isEmpty==0)
            {
                jugadores_showPlayer(vec[i], confederaciones);

                flag = 0;
            }
        }
        if(flag)
        {
            printf("    ***No hay JUGADORES en el sistema*** \n");
        }
        todoOk = 1;
    }
    return todoOk;
}


//
//
//int jugadores_hardcodePlayers(eJugador vec[], int* pNextId, int cantAharcodear, int* pcontJugadores)
//{
//    int todoOk = 0;
//    int x = *pNextId;
//    eJugador jugador[] =
//    {
//    		{0, "", "", 0, 0, 0, 0, 0},
//        {0, "Lionel Messi", "Delantero", 10, 101, 200000, 4, 0},
//        {0, "Givanildo Viera(Hulk)", "Delantero", 7, 100, 100000, 3, 0},
//        {0, "Mohamed El Shenawy", "Arquero", 1, 103, 80000, 2, 0},
//        {0, "Enzo Copetti", "Delantero", 9, 100, 86000, 4, 0},
//
//    };
//
//    if( vec != NULL && pNextId != NULL)
//    {
//        for(int i= x; i < cantAharcodear; i++)
//        {
//            vec[i] = jugador[i];
//            vec[i].id = *pNextId;
//            (*pNextId)++;
//            (*pcontJugadores)++;
//        }
//        todoOk = 1;
//        printf("\n*** jugadores cargados con exito!!! ***\n\n");
//
//    }
//    return todoOk;
//}
int jugadores_hardcodePlayers(eJugador vec[], int* pNextId, int cantAharcodear, int* pcontJugadores)
{
    int todoOk = 0;
    int x = *pNextId;
    eJugador jugador[] =
    {
    	       {0,"Emiliano Martinez","ARQUERO",1,100,100000,4,0},
    	       {0,"Juan Musso","ARQUERO",12,100,80000,2,0},
    	       {0,"Leo Messi","DELANTERO",10,100,80000,4,0},
    	       {0,"Almirez Ali","DELANTERO",9,100,55000,1,0},
    	       {0,"Harry Maguire","DEFENSOR",2,101,70000,4,0},
    	       {0,"Eric Dier","DEFENSOR",3,101,60000,2,0},
    	       {0,"Harry Kane","DELANTERO",10,101,3000,2,0},
    	       {0,"Alfred Gomis","ARQUERO",1,101,9000,1,0},
    	       {0,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,0},
    	       {0,"Guillermo Ochoa","ARQUERO",1,104,90000,4,0},
    	       {0,"Tecatito","DELANTERO",11,104,100000,3,0},
    	       {0,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,0},
    	       {0,"Bamba Dieng ","DELANTERO",9,103,100000,2,0},
    	       {0,"Demba Seck","DELANTERO",11,103,6000,2,0},
    	       {0,"Tarek Salman","DEFENSOR",6,102,78000,5,0}

    };

    if( vec != NULL && pNextId != NULL)
    {
        for(int i= x; i < cantAharcodear; i++)
        {
            vec[i] = jugador[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
            (*pcontJugadores)++;
        }
        todoOk = 1;
        printf("\n*** jugadores cargados con exito!!! ***\n\n");

    }
    return todoOk;
}


int jugadores_searchPlayerId(eJugador vec[], int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < TAM_JUG; i++)
        {

            if( vec[i].isEmpty==0  && vec[i].id == id)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }

    }
    return todoOk;
}



int jugadores_modifyPlayers(eJugador vec[],  eConfederacion confederaciones[])
{
    int modificado = 0;
    int id = -1;
    int indice;

    char nuevaPosicion[50];


    if(vec != NULL && confederaciones != NULL )
    {
        printf("\n----------------------- Modificar Jugador ------------------------\n");
        printf("-------------------------------------------------------------------\n");


        	informes_sortPlayersByID(vec);
        	jugadores_listPlayers(vec, confederaciones);

			printf("\nIngrese Id del Jugador que desea modificar: ");
			fflush(stdin);
			scanf("%d", &id);


			if(id!=-1)
			{
				jugadores_searchPlayerId(vec, id, &indice);

				if(indice == -1)
				{
					printf("No existe Jugador con ese id: %d\n", id);
				}
				else
				{
					printf("\n");

					jugadores_showPlayer(vec[indice], confederaciones);

						switch(menu_menuModify())
						{
						case 1:
							getValidStringRango("Ingrese nuevo nombre: ", "ERROR. Ingrese un Nombre válido: ", vec[indice].nombre, TAM_NOMBRE);
							modificado = 1;
							printf("\n");
							break;

						case 2:
							sets_setPositions(nuevaPosicion);
							strcpy(vec[indice].posicion, nuevaPosicion);
							modificado = 1;
				            printf("\n");
							break;

						case 3:
							vec[indice].numeroCamisa = gets_getNumerShort("Ingrese nuevo número de camiseta: ", "ERROR. Ingrese una número entre 0 y 100: ", 0, 100);
							modificado = 1;
							printf("\n");
							break;

						case 4:
				            confed_listConfederations(confederaciones);
							vec[indice].idConfederacion = gets_getNumerInt("Ingrese Id de la Confederación del jugador: ", "ERROR. Ingrese una confederación listada: ", 100, 105);
							modificado = 1;
				            printf("\n");
							break;

						case 5:
							vec[indice].salario = gets_getNumerFloat("Ingrese nuevo salario del jugador: $ ", "ERROR. Ingrese un monto del salario: $", 0, 1000000);
							modificado = 1;
							printf("\n");
							break;

						case 6:
							vec[indice].aniosContrato = gets_getNumerShort("Ingrese anios de contrato del jugador: ", "ERROR. Ingrese anios: ", 0, 11);
							modificado = 1;
							printf("\n");
							break;
						}

						printf("\n\n ***  Modificación exitosa!!!  ***\n\n");

						jugadores_showPlayer(vec[indice], confederaciones);
				}
			}
			else
			{
				printf("En ese paso se permiten sólo números. \n");
			}
    }
    return modificado;
}


int jugadores_erasePlayer(eJugador vec[], eConfederacion confederaciones[], int* pcontJugadores)
{
    int borrado = 0;
    int indice;
    int id = -1;
    char confirma;
    if( vec != NULL && confederaciones != NULL )
    {
        printf("------------------------- Baja Jugador --------------------------\n");
        printf("--------------------------------------------------------------\n");


        	jugadores_listPlayers(vec, confederaciones);
			printf("\nIngrese Id del Jugador que desea dar de baja: ");
			fflush(stdin);
			scanf("%d", &id);
			printf("\n");

			if(id!=-1)
			{
				if(jugadores_searchPlayerId(vec, id, &indice))
				{
					if(indice == -1)
					{
						printf("*** No existe jugador con el Id > %d < en el sistema ***\n", id);
					}
					else
					{
						jugadores_showPlayer(vec[indice], confederaciones);
						printf("Confirma baja?('s' para confirmar, cualquier otro caracter para cancelar: ");
						fflush(stdin);
						scanf("%c", &confirma);

						if(confirma == 's' || confirma == 'S')
						{
							vec[indice].isEmpty = 2;
							printf("\n\n ***  Baja exitosa!!!  ***\n\n");
							borrado = 1;
							(*pcontJugadores)--;
							jugadores_listPlayers(vec, confederaciones);
						}
						else
						{
							printf("\n*** Baja cancelada por el usuario...***\n");
						}

					}

				}
			}
			else
			{
				printf("*** En ese paso se permiten sólo números...: \n");
			}

    }
    return borrado;
}


void cantidadDeJugadoresPorConfederacion(eJugador vec[], eConfederacion confederaciones[], int jugadoresConfed[])
{
    int cantJugadores;

    if( vec != NULL && confederaciones != NULL )
    {
        for(int i = 0; i < TAM_CONF; i++)
        {
        	cantJugadores = 0;

        	for(int j = 0; j < TAM_JUG; j++)
        	{
        		if(vec[j].isEmpty==0)
        		{
					if(confederaciones[i].id==vec[j].idConfederacion)
					{
						cantJugadores++;
					}
        		}
        	}

        	jugadoresConfed[i] = cantJugadores;
        }
    }
}


