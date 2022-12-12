/*
 * Sets.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Sets.h"

int sets_setPositions(char bufferPosicion[])
{
	int todoOk = -1;
	int opcion;

	opcion = gets_getNumerInt(
			"1. Arqueros \n"
			"2. Defensores \n"
			"3. Mediocampistas \n"
			"4. Delanteros\n"
			"\nElija posición para este jugador: ", "*** ERROR. Ingrese una de las opciones. ", 1, 4);

	switch(opcion)
	{
	case 1:
		strcpy(bufferPosicion, "Arquero");
			todoOk = 1;
		break;
	case 2:
		strcpy(bufferPosicion, "Defensores");
			todoOk = 1;
		break;
	case 3:
		strcpy(bufferPosicion, "Mediocampista");
			todoOk = 1;
		break;
	case 4:
		strcpy(bufferPosicion, "Delantero");
			todoOk = 1;
		break;
	}

	return todoOk;
}



