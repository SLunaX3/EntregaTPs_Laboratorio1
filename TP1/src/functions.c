/*
 * functions.c
 *
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "getsYcalculos.h"



int functions_menu(float trasporte, float hospedaje, float comida, int contArqueros, int contDefensores, int contMediocampos, int contDelanteros, char* mensaje, char* mensajeError, int minimo, int maximo)
	{
    int opcion;

        printf("1. Ingreso de los costos de Mantenimiento \n"
        		"Costo de Hospedaje -> $%.2f \n"
        		"Costo de Comida -> $%.2f \n"
        		"Costo de Transporte -> $%.2f \n", hospedaje, comida, trasporte);
        printf("2. Carga de jugadores: \n"
        		"Arqueros -> %d \n"
        		"Defensores -> %d \n"
        		"Mediocampistas -> %d \n"
        		"Delanteros -> %d \n", contArqueros, contDefensores, contMediocampos, contDelanteros);
        printf("3. Realizar todos los cálculos: \n");
        printf("4. Informar todos los Resultados: \n");
        printf("5. Salir \n");

        opcion = getsYcalculos_getNumerInt(mensaje, mensajeError, minimo, maximo);

        return opcion;
    }






void functions_setCosts(float* pTransporte, float* pHospedaje, float* pComida)
{
	char seguir = 's';
	int opcion;
	float precio;

	do
	{
		opcion = getsYcalculos_getNumerInt( "\nElija costo que deasea Ingresar: \n"
	    		"1. Costo de Hospedaje \n"
	    		"2. Costo de Comida \n"
	    		"3. Costo de Transporte \n", "ERROR. Ingrese una de las opciones", 1, 3);
		precio = getsYcalculos_getNumerFloat("Ingrese precio: $ ", "\n*** ERROR. Ingrese un monto Válido: \n", 1);

		switch(opcion)
		{
		case 1:
			*pHospedaje=precio;
			break;
		case 2:
			*pComida=precio;
			break;
		case 3:
			*pTransporte=precio;
			break;
		}
		printf("Desea continuar: s (Sí)/ n (No) \n");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(seguir!='n' && seguir!='s')
		{
			printf("*** ERROR. Ingrese 's' o 'n' : ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}
	while(seguir=='s');

}



int functions_setPositions(int* pArqueros, int maxArqueros, int* pDefensores, int maxDefensores, int* pMediocampos, int maxMediocampos, int* pDelanteros, int maxDelanteros)
{
	int todoOk = -1;
	int opcion;

	opcion = getsYcalculos_getNumerInt( "\nElija posición que deasea Ingresar: \n"
			"1. Arqueros \n"
			"2. Defensores \n"
			"3. Mediocampistas \n"
			"4. Delanteros\n", "*** ERROR. Ingrese una de las opciones: ", 1, 4);

	switch(opcion)
	{
	case 1:
		if(*pArqueros<maxArqueros)//para que cargue hasta 2
		{
			*pArqueros+=1;
			todoOk = 1;
		}
		else
		{
			printf("\n__________ ***** Posición completa. ****** __________\n"
					"Ya se ingresaron todos los Arqueros para el plantel.\n\n");
		}
		break;
	case 2:
		if(*pDefensores<maxDefensores)//para que cargue hasta 8
		{
			*pDefensores+=1;
			todoOk = 1;

		}
		else
		{
			printf("\n__________ ***** Posición completa. ****** __________\n"
					"Ya se ingresaron todos los Defensores para el plantel.\n\n");
		}
		break;
	case 3:
		if(*pMediocampos<maxMediocampos)//para que cargue hasta 8
		{
			*pMediocampos+=1;
			todoOk = 1;

		}
		else
		{
			printf("\n__________ ***** Posición completa. ****** __________\n"
					"Ya se ingresaron todos los Mediocampistas para el plantel.\n\n");
		}
		break;
	case 4:
		if(*pDelanteros<maxDelanteros)//para que cargue hasta 4
		{
			*pDelanteros+=1;
			todoOk = 1;

		}
		else
		{
			printf("\n__________ ***** Posición completa. ****** __________\n"
					"Ya se ingresaron todos los Delanteros para el plantel.\n\n");
		}
		break;
	}

	return todoOk;
}




void functions_setConfederation(int numCamiseta, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC)
{
	int opcion;

	opcion = getsYcalculos_getNumerInt( "\nElija confederación: \n"
			"1. AFC \n"
			"2. CAF \n"
			"3. CONCACAF \n"
			"4. CONMEBOL \n"
			"5. UEFA \n"
			"6. OFC \n", "*** ERROR. Ingrese una de las opciones: ", 1, 6);

		switch(opcion)
		{
		case 1:
			*pAFC+=1;
			printf("-> Se ingresó un jugador de la confederación AFC, de camiseta n°%d \n\n ", numCamiseta);
			break;
		case 2:
			*pCAF+=1;
			printf("-> Se ingresó un jugador de la confederación CAF, de camiseta n°%d \n\n", numCamiseta);
			break;
		case 3:
			*pCONCACAF+=1;
			printf("-> Se ingresó un jugador de la confederación CONCACAF, de camiseta n°%d \n\n", numCamiseta);
			break;
		case 4:
			*pCONMEBOL+=1;
			printf("-> Se ingresó un jugador de la confederación CONMEBOL, de camiseta n°%d \n\n", numCamiseta);
			break;
		case 5:
			*pUEFA+=1;
			printf("-> Se ingresó un jugador de la confederación UEFA, de camiseta n°%d \n\n", numCamiseta);
			break;
		case 6:
			*pOFC+=1;
			printf("-> Se ingresó un jugador de la confederación OFC, de camiseta n°%d \n\n", numCamiseta);
			break;
		}

}


void functions_showResults (float promAFC, float promCAF, float promCONCACAF, float promCONMEBOL, float promUEFA, float promOFC, float gastos, float aumEuropa, float mantenimiento)
{
	printf("Promedio de Jugadores de AFC %.2f \n"
			"Promedio de Jugadores de CAF %.2f \n"
			"Promedio de Jugadores de CONCACAF %.2f \n"
			"Promedio de Jugadores de CONMEBOL %.2f \n"
			"Promedio de Jugadores de UEFA %.2f \n"
			"Promedio de Jugadores de OFC %.2f \n", promAFC, promCAF, promCONCACAF, promCONMEBOL, promUEFA, promOFC);

	if(aumEuropa==0)
	{
		printf("Costos de Mantenimiento: $%.2f; NO HAY AUMENTO; Total Gastos de Mantenimiento: $%.2f \n", gastos, mantenimiento);
	}
	else
	{
		printf("El Costo de Mantenimiento era de $%.2f y recibió un Aumento de $%.2f, su nuevo valor es de $%.2f \n\n", gastos, aumEuropa, mantenimiento);
	}

}
