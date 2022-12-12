/*
 * Informes.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Informes.h"




int informes_sortPlayersByConfederationAndName(eJugador vec[], eConfederacion confederaciones[])
{
    int todoOk = 0;
    eJugador auxJugador;
    char iNombreConfed[50];
    char jNombreConfed[50];


    if(vec != NULL)
    {
        for(int i = 0; i < TAM_JUG - 1; i++)
        {
            for(int j = i + 1; j < TAM_JUG; j++)
            {
            	confed_loadConfederation(confederaciones, vec[i].idConfederacion, iNombreConfed);
            	confed_loadConfederation(confederaciones, vec[j].idConfederacion, jNombreConfed);

                if((strcmp(iNombreConfed, jNombreConfed)>0) ||
                		(strcmp(iNombreConfed, jNombreConfed)==0 && strcmp(vec[i].nombre, vec[j].nombre)>0))
                {
                    auxJugador = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxJugador;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}




int informes_sortPlayersByID(eJugador vec[])
{
	int todoOk = 0;

	eJugador jugadores;

	if(vec!=NULL)
	{
		for(int i=0; i<TAM_JUG -1; i++)
		{
			for(int j=i+1; j<TAM_JUG; j++)
			{
				if(vec[i].id>vec[j].id)
				{
					jugadores = vec[i];
					vec[i] = vec[j];
					vec[j] = jugadores;
				}
			}
		}
		todoOk = 1;
	}

	return todoOk;
}


int informes_playersByConfederation(eJugador vec[], eConfederacion confederaciones[], int idConfederacion)
{
    int todoOk = 0;
    char nombreConfed[50];
    int flagConfedCargada;

    if(vec != NULL && confederaciones!=NULL)
    {
    	confed_loadConfederation(confederaciones, idConfederacion, nombreConfed);
    	flagConfedCargada = 0;
		printf("\n\n                              *** Listado de Jugadores de la Confederacion %s ***\n", nombreConfed);
		printf("===========================================================================================================================================================\n");
		printf("  ID  |   NOMBRE                                                 |     POSICION            | N° CAMISETA | CONFEDERACION   | SUELDO   | ANIOS DE CONTRATO | \n");
		printf("==========================================================================================================================================================\n");

            for(int j = 0; j < TAM_JUG; j++)
            {
            	if(vec[j].isEmpty==0)
            	{
					if(idConfederacion == vec[j].idConfederacion)
					{
						flagConfedCargada = 1;
						jugadores_showPlayer(vec[j], confederaciones);
					}
            	}

            }
            if(flagConfedCargada == 0)
            {
            	printf(" ========> NO HAY JUGADORES EN ESTA CONFEDERACION \n");
            }


        todoOk = 1;
    }
    return todoOk;
}


void informes_showPlayersByConfederation(eJugador vec[], eConfederacion confederaciones[])
{
	int idConfed;

	 for(int i = 0; i < TAM_CONF; i++)
	 {
		 idConfed = confederaciones[i].id;
		 informes_playersByConfederation(vec,confederaciones, idConfed);

	 }

}

float informes_accumulateSalary(eJugador vec[])
{
    float acumSueldos = 0;

    if(vec != NULL)
    {
        for(int i = 0; i < TAM_JUG; i++)
        {
        	if(vec[i].isEmpty==0)
        	{
        		acumSueldos += vec[i].salario;
        	}
        }
    }
    return acumSueldos;
}



int informes_bestSalaries(eJugador vec[], float promedio)
{
    int contSueldos = 0;

    if(vec != NULL )
    {
        for(int i = 0; i < TAM_JUG; i++)
        {
        	if(vec[i].isEmpty==0)
        	{
				if(vec[i].salario>promedio)
				{
					contSueldos++;
				}
        	}
        }

    }

    return contSueldos;
}




// Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.

int informes_reportSalaries(eJugador vec[], int contJugadores)
{
	int todoOk = 0;
	float sumaSalarios;
	float promedioSalarios;
	int mejoresSueldos;

	if(vec!=NULL && contJugadores>0)
	{
		sumaSalarios = informes_accumulateSalary(vec);

		promedioSalarios = sumaSalarios / contJugadores;

		mejoresSueldos = informes_bestSalaries(vec, promedioSalarios);
		printf(" El Total de los salarios es: $%.2f \n", sumaSalarios);
		printf(" El Promedio de los salarios es: $%.2f \n", promedioSalarios);
		printf(" La cantidad de jugadores con los mejores salarios es: %d jugadores\n", mejoresSueldos);
		todoOk = 1;
	}

	return todoOk;
}


int informes_confederacionConMasAnios(eJugador vec[], eConfederacion confederaciones[])
{
	int todoOk = 0;
	short aniosContrato[] = {
			0, //CONMEBOL
			0, //UEFA
			0, // AFC
			0, // CAF
			0, //CONCACAF
			0 // OFC
	};
	char nombreConfed[50];
	int indice;



	if(vec!=NULL && confederaciones!=NULL)
	{
		confed_accumulateYearsContract(vec, confederaciones, aniosContrato);

		indice = confed_confedMayorAniosContrato(confederaciones, aniosContrato, nombreConfed);

		//printf("\n La confederación con más anios de contratos es: %s \n", nombreConfed);

		printf("\nCONFEDERACION CON MÁS ANIOS DE CONTRATOS\n");
		printf("===========================================\n");
		printf("           %-10s           |   %hd |\n", nombreConfed, aniosContrato[indice]);
		printf("\n\n");

		todoOk = 1;
	}



	return todoOk;
}


int confed_accumulateYearsContract(eJugador vec[], eConfederacion confederaciones[], short aniosContrato[])
{
    int todoOk = 0;

    if(vec != NULL && confederaciones!= NULL)
    {
        for(int i = 0; i < TAM_CONF; i++)
        {
        	for(int j = 0; j < TAM_JUG; j++)
        	{
        		if(vec[j].isEmpty==0)
        		{
					if(confederaciones[i].id==vec[j].idConfederacion)
					{
						aniosContrato[i] += vec[j].aniosContrato;
					}
        		}
        	}
        }
        todoOk=1;
    }
    return todoOk;
}



int confed_confedMayorAniosContrato(eConfederacion confederaciones[], short aniosContrato[], char pNombreConf[])
{
    int todoOk = 0;
	short maxAnios = 0;
	int indice;

    if(aniosContrato!=NULL)
    {
        for(int i = 0; i < TAM_CONF; i++)
        {
			if(aniosContrato[i]>maxAnios)
			{
				maxAnios=aniosContrato[i];
				indice=i;
			}
        }
        strcpy(pNombreConf, confederaciones[indice].nombre);
        todoOk=indice;
    }
    return todoOk;
}


void confedPorcentajeJugadores(eJugador vec[], eConfederacion confederaciones[], int contJugadores)
{
	float porcentaje;
    if( contJugadores>0 && confederaciones != NULL )
    {
    	int jugadoresConfed[TAM_CONF];

    	cantidadDeJugadoresPorConfederacion(vec, confederaciones, jugadoresConfed);

        printf("\n\n PORCENTAJES DE JUGADORES POR CONFEDERACION \n");
        printf("=============================================\n");

        for(int i = 0; i < TAM_CONF; i++)
        {
        	porcentaje = (float)jugadoresConfed[i]*100/contJugadores;

            printf("        %-10s  |       %.2f %c  \n", confederaciones[i].nombre, porcentaje,37);

        }
        printf("==============================================\n");
    }

}





int informes_countPlayersPerRegion(eJugador vec[], eConfederacion confederaciones[], int aContJug[])
{
    int todoOk = 0;


    if(vec != NULL && confederaciones!= NULL)
    {
        for(int i = 0; i < TAM_CONF; i++)
        {
        	int contadorJug = 0;
        	for(int j = 0; j < TAM_JUG; j++)
        	{
        		if(vec[i].isEmpty==0)
        		{
					if(confederaciones[i].id==vec[j].idConfederacion)
					{
						contadorJug ++;
					}
        		}
        	}
        	aContJug[i] = contadorJug; // cantidad de Jugadores en "confederaciones[i]
        }
        todoOk=1;
    }
    return todoOk;
}

// evaluar mayor cant respecto a cantidad de  indice, si indice es = imprimir region de ese indice
int informes_regionMostPlayers(int aContJug[])
{
    int mayorCantRegion = 0;

    if(aContJug!=NULL)
    {
        for(int i = 0; i < TAM_CONF; i++)
        {
			if(aContJug[i]>mayorCantRegion)
			{
				mayorCantRegion=aContJug[i];
			}
        }
    }
    return mayorCantRegion;
}

int informes_showRegionMostPlayers(eJugador vec[], eConfederacion confederaciones[], int  mayorCantRegion, int aContJug[])
{
	   int todoOk = 0;
	   int idConf;

	    if(vec != NULL && confederaciones!= NULL)
	    {
	    	for(int i = 0; i < TAM_CONF; i++)
			{
	    		if(aContJug[i]==mayorCantRegion)
	    		{
			        printf("\n                              REGION CON MAS JUGADORES: %s  \n", confederaciones[i].region);

			        idConf = confederaciones[i].id;
			        informes_playersByConfederation(vec, confederaciones, idConf);
			        todoOk=1;

	    		}
	    	}
	    }
	    return todoOk;
}

