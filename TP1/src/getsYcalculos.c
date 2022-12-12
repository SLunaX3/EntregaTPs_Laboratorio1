/*
 * getsYcalculos.c
 *
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getsYcalculos.h"
#include "functions.h"

int getsYcalculos_getNumerInt(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int bufferInt = minimo-1;
	int retorno= -1;
	if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				retorno= bufferInt;
				break;
			}
			else
			{
				printf("%s \n", mensajeError);
				fflush(stdin);
			}

		}while(retorno==-1);
	}
	return retorno;
}


float getsYcalculos_getNumerFloat(char* mensaje, char* mensajeError, int minimo)
{
	float bufferFloat = -1;
	float retorno= -1;
	if(mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat>=minimo)
			{
				retorno= bufferFloat;
				break;
			}
			else
			{
				printf("%s \n", mensajeError);
				fflush(stdin);
			}

		}while(retorno==-1);
	}
	return retorno;
}



float getsYcalculos_average (int cantidad, int cantTotal)
{
	float promedio = -1;

	if(cantTotal==0)
	{
		printf("***** ERROR. No es posible realizar operación *****");
	}
	else
	{
		promedio = (float) cantidad / cantTotal;
	}

	return promedio;
}


void getsYcalculos_averageConfedPlayers (int* pCantJug, int AFC, int CAF, int CONCACAF, int CONMEBOL, int UEFA, int OFC, float* pPromAFC, float* pPromCAF, float* pPromCONCACAF, float* pPromCONMEBOL, float* pPromUEFA, float* pPromOFC)
{

	*pCantJug = AFC + CAF + CONCACAF+ CONMEBOL + UEFA + OFC;

	*pPromAFC = getsYcalculos_average(AFC, *pCantJug);
	*pPromCAF = getsYcalculos_average(CAF, *pCantJug);
	*pPromCONCACAF = getsYcalculos_average(CONCACAF, *pCantJug);
	*pPromCONMEBOL = getsYcalculos_average(CONMEBOL, *pCantJug);
	*pPromUEFA = getsYcalculos_average(UEFA, *pCantJug);
	*pPromOFC = getsYcalculos_average(OFC, *pCantJug);
}

float getsYcalculos_calculateExpenses (float* pGastos , int aumento, float* pAumEuropa, float hospedaje, float comida, float transporte, int cantJug, int UEFA)
{
	float auxiliar;
	float mantenimiento;

	*pGastos = hospedaje + comida + transporte;

	auxiliar =(float) cantJug/2;

	if(auxiliar<UEFA)
	{
		*pAumEuropa = (float) *pGastos * aumento/100;
	}

	mantenimiento = *pGastos + *pAumEuropa;

	return mantenimiento;
}




