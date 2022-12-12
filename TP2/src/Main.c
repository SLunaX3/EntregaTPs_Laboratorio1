/*
 ============================================================================
 Name        : TP2.c
 Author      : Luna, Sonia

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "Jugadores.h"
#include "Gets.h"
#include "Sets.h"
#include "Menu.h"
#include "Informes.h"
#include "Confed.h"

#define CANT_HARCODEOJUG 15

int main(void) {

	setbuf(stdout, NULL);

	char salir = 'n';
	char* msjValidOpciones="\n\n===> No hay jugadores ingresados. Son necesarios para esta operación ... \n\n";
	int proxJugador = 0;
	int contJugadores = 0;


	eJugador vec[TAM_JUG];

	inicializarJugador(vec);


	/////////// HARCODEO DE CONFEDERACIONES ///////////////
	eConfederacion confederaciones[] =
	{
	        {100, "CONMEBOL", "SUDAMENRICA", 1916},
	        {101, "UEFA", "EUROPA", 1954},
	        {102, "AFC", "ASIA", 1954},
	        {103, "CAF", "AFRICA", 1957},
	        {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
			{105, "OFC", "OCEANIA", 1966}
	};



	do
	{
		switch (menu_menu())
		{
			case 1: //ALTA
				jugadores_addPlayer(vec, confederaciones, &proxJugador, &contJugadores);
				break;

			case 2: //BAJA
				if(contJugadores>0)
				{
					jugadores_erasePlayer(vec, confederaciones, &contJugadores);
				}
				else
				{
					printf("%s", msjValidOpciones);
				}
				break;

			case 3: // MODIFICACION
				if(contJugadores>0)
				{
					jugadores_modifyPlayers(vec, confederaciones);
				}
				else
				{
					printf("%s", msjValidOpciones);
				}

				break;

			case 4: // INFORMES
				if(contJugadores>0)
				{
					menu_reportsMenu(vec, confederaciones, contJugadores);
				}
				else
				{
					printf("%s", msjValidOpciones);
				}

				break;

			case 5:
				jugadores_hardcodePlayers(vec, &proxJugador, CANT_HARCODEOJUG, &contJugadores);
				break;

			case 6: // SALIR
				salir = 's';
				break;

			default:
				printf("---> Ingrese alguna de las opciones:");
				break;
		}

	} while (salir != 's');

	return EXIT_SUCCESS;
}
