/*
 ============================================================================
 Name        : TP1.c
 Author      : Luna, Sonia
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "getsYcalculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char* msjError="*** ERROR. Ingrese un valor Válido: ";

	float transporte = 0;
	float hospedaje = 0;
	float comida = 0;
	int maxArqueros = 2;
	int maxDefensores = 8;
	int maxMedioCampos = 8;
	int maxDelanteros = 4;
	int contArqueros = 0;
	int contDefensores = 0;
	int contMedioCampos = 0;
	int contDelanteros = 0;
	int posicionOk;
	int numCamiseta;
	int contAFC = 0;
	int contCAF = 0;
	int contCONCACAF = 0;
	int contCONMEBOL = 0;
	int contUEFA = 0;
	int contOFC = 0;
	float gastos = 0 ; //inicializado para validación para opción 4
	int aumento = 35;
	float aumEuropa = 0; //inicializado para validación mensajes opción 4
	float mantenimiento;
	int cantJug;
	float promAFC;
	float promCAF;
	float promCONCACAF;
	float promCONMEBOL;
	float promUEFA;
	float promOFC;

	do
	{
		opcion = functions_menu(transporte, hospedaje, comida, contArqueros, contDefensores, contMedioCampos, contDelanteros, "---> Ingrese opción: ", msjError, 1, 5);
		switch(opcion)
		{
		case 1:
			functions_setCosts(&transporte, &hospedaje, &comida);
			break;
		case 2:
			posicionOk = functions_setPositions(&contArqueros, maxArqueros, &contDefensores, maxDefensores, &contMedioCampos, maxMedioCampos, &contDelanteros, maxDelanteros);
			if(posicionOk==1)
			{
				numCamiseta = getsYcalculos_getNumerInt("---> Ingrese número de Camiseta: ", msjError, 1, 99);
				functions_setConfederation(numCamiseta, &contAFC, &contCAF, &contCONCACAF, &contCONMEBOL, &contUEFA, &contOFC);
			}
			break;
		case 3:
			if(hospedaje==0 || comida==0 || transporte==0)
			{
				printf("\n*** Debe ingresar jugadores y todos los Costos de Mantenimiento para hacer los cálculos. ***\n\n");
			}
			else
			{
				if(posicionOk!=1)
				{
					printf("\n*** Debe ingresar jugadores para hacer los cálculos. ***\n\n");
				}
				else
				{
					getsYcalculos_averageConfedPlayers (&cantJug, contAFC, contCAF, contCONCACAF, contCONMEBOL, contUEFA, contOFC, &promAFC, &promCAF, &promCONCACAF, &promCONMEBOL, &promUEFA, &promOFC);
					mantenimiento = getsYcalculos_calculateExpenses (&gastos , aumento, &aumEuropa, hospedaje, comida, transporte, cantJug, contUEFA);
					printf("***** CALCULOS REALIZADOS ****** \n");
				}
			}
			break;
		case 4:
			if(gastos==0)
			{
				printf("\n*** Primero debe realizar todos los Cálculos. ***\n\n");
			}
			else
			{
				functions_showResults (promAFC, promCAF, promCONCACAF, promCONMEBOL, promUEFA, promOFC, gastos, aumEuropa, mantenimiento);
			}
			break;
		case 5:
			printf("\n ___ *** Gracias por usar esta aplicación *** ___\n");
			break;
//		default:
//			printf("---> Ingrese una opción válida del 1 al 5 <--- \n");

		}
	}
	while(opcion!=5);
	return EXIT_SUCCESS;
}
