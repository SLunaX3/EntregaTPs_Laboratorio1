#include "Seleccion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Seleccion* selec_new() {
	Seleccion *unaSeleccion= malloc(sizeof(Seleccion));
	if (unaSeleccion != NULL) {
		unaSeleccion->id = 0;
		strcpy(unaSeleccion->pais, "");
		strcpy(unaSeleccion->confederacion, "");
		unaSeleccion->convocados = 0;
	} else {
		printf("No hay espacio para cargar una nueva seleccion");
	}
	return unaSeleccion;
}


Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr) {
	int auxId;
	int auxConvocados;
	int flagSetters = 1;

	Seleccion *unaSeleccion = selec_new();

	if (idStr != NULL) {
		auxId = atoi(idStr);
		unaSeleccion->id = auxId;
	} else {
		flagSetters = 0;
	}

	if (paisStr != NULL) {
		strcpy(unaSeleccion->pais, paisStr);
	} else {
		flagSetters = 0;
	}
	if (confederacionStr != NULL) {
		strcpy(unaSeleccion->confederacion, confederacionStr);
	} else {
		flagSetters = 0;
	}


	if (convocadosStr != NULL) {
		auxConvocados = atoi(convocadosStr);
		unaSeleccion->convocados = auxConvocados;
	} else {
		flagSetters = 0;
	}

	if (flagSetters != 1) {

		printf("Error al cargar seleccion");
	}

	return unaSeleccion;
}


int selec_getId(Seleccion* this,int* id)
{
	int retorno = 0;
	if (this != NULL && id !=NULL) {
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;
	if (this != NULL && convocados >= 0) {
		this->convocados = convocados;
		retorno = 1;
	}
	return retorno;
}


int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;
	if (this != NULL && convocados != NULL) {
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;
	if (this != NULL && pais != NULL) {
		strcpy(pais ,this->pais);
		retorno = 1;
	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;
	if (this != NULL && confederacion != NULL) {
		strcpy(confederacion,this->confederacion);
		retorno = 1;
	}
	return retorno;
}

void selec_printData(Seleccion* this)
{
	int id;
    char pais[30];
    char confederacion[30];
    int convocados;
    selec_getId(this, &id);
    selec_getPais(this, pais);
    selec_getConfederacion(this, confederacion);
    selec_getConvocados(this, &convocados);

			printf("|   %4d   |      %-20s|    %-15s    | %-10d |\n ",id,pais,confederacion,convocados);

}

