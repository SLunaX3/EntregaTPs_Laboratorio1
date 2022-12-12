/*
 * Menu.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Menu.h"

int menu_menu()
{

    int opcion = -1;

	do{
		printf("\n--------------------------------\n\n");
		printf("   1. Alta de Jugador\n");
		printf("   2. Baja de Jugador \n");
		printf("   3. Modificaci�n de Jugador \n");
		printf("   4. INFORMES \n");
		printf("   5.HARCODEO de Jugadores \n");
		printf("   6. Salir.\n\n");

		opcion = gets_getNumerInt("--> Ingrese opcion: ", "ERROR. Opcion inv�lida", 1, 5);


	}while(opcion<1 || opcion>5);

    return opcion;
}

int menu_reportsMenuOptions()
{

    int opcion = -1;

	do{
		printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
		printf("   1. Listado de los jugadores ordenados alfab�ticamente por nombre de confederaci�n y nombre de jugador.\n");
		printf("   2. Listado de confederaciones con sus jugadores. \n");
		printf("   3. Total y promedio de todos los salarios y cu�ntos jugadores cobran m�s del salario promedio. \n");
		printf("   4. Informar la confederaci�n con mayor cantidad de a�os de contratos total. \n");
		printf("   5. Informar porcentaje de jugadores por cada confederaci�n. \n");
		printf("   6. Informar cual es la regi�n con m�s jugadores y el listado de los mismos. \n");
		printf("   7. Salir de INFORMES .\n\n");

		opcion = gets_getNumerInt("--> Ingrese opcion: ", "ERROR. Opcion inv�lida", 1, 7);


	}while(opcion<1 || opcion>7);

    return opcion;
}

void menu_reportsMenu( eJugador vec[],  eConfederacion confederaciones[], int contJugadores)
{
	int aContJug[TAM_CONF] = {0};
	int  mayorCantRegion = 0;
	char salir = 'n';
	int opcion;
	do{

		opcion = menu_reportsMenuOptions();
		switch (opcion) {
			case 1:
				informes_sortPlayersByConfederationAndName(vec, confederaciones);
				jugadores_listPlayers(vec, confederaciones);
				break;


			case 2:
				informes_showPlayersByConfederation(vec, confederaciones);
				break;

			case 3:
				informes_reportSalaries(vec, contJugadores);
				break;

			case 4:
				informes_confederacionConMasAnios(vec, confederaciones);
				break;

			case 5:
				confedPorcentajeJugadores(vec, confederaciones, contJugadores);
				break;

			case 6:
				informes_countPlayersPerRegion(vec, confederaciones, aContJug);
				mayorCantRegion = informes_regionMostPlayers(aContJug);
				informes_showRegionMostPlayers(vec, confederaciones,  mayorCantRegion, aContJug);
				break;

			case 7:
	            salir = 's';
	            break;
			default:
				printf("--- Ingrese alguna de las opciones:");
				break;
		}
	}while(salir!='s');

}

int menu_menuModify()
{
    int opcion = -1;

	do{
		printf("\n-----Elija la modificacion a realizar-----\n\n");
		printf("   1. Nombre\n");
		printf("   2. Posici�n \n");
		printf("   3. N�mero de Camiseta \n");
		printf("   4. Id Confedraci�n \n");
		printf("   5. Salario \n");
		printf("   6. Aniod de Contrato \n");
		printf("   7. Salir de la modificaci�n.\n\n");

		opcion = gets_getNumerInt("--> Ingrese opcion: ", "ERROR. Opcion inv�lida", 1, 7);

	}while(opcion<1 || opcion>7);

	return opcion;
}
