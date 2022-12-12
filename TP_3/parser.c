#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include <string.h>
#include "Valids.h"
#include "Controller.h"



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* this;
	int readData;
	char bufferId[10];
	char bufferNombreCompleto[100];
	char bufferEdad[10];
	char bufferPosicion[30];
	char bufferNacionalidad[30];
	char bufferIdSeleccion[10];

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombreCompleto, bufferEdad, bufferPosicion,bufferNacionalidad,bufferIdSeleccion); //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar y le asigno a "datosLeidos" el retorno de la lectura "fscanf"
	while(!feof(pFile))
	{
		 readData=	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombreCompleto, bufferEdad, bufferPosicion,bufferNacionalidad,bufferIdSeleccion);
		 if(readData==6)
		 {
			 corregirMayusculas(bufferNombreCompleto);
			 this = jug_newParametros(bufferId, bufferNombreCompleto, bufferEdad, bufferPosicion, bufferNacionalidad, bufferIdSeleccion);
			 ll_add(pArrayListJugador, this);
		 }
		 else if(readData!=6 && this==NULL)
		 {
			 if(!feof(pFile))
			 {
				 printf("\n****** Error al leer el ultimo dato****** \n");
				 break;
			 }
			 else
			 {
				 printf("\n***** Se leyo todo el archivo correctamente ******\n");
			 }
		 }
	}
	fclose(pFile);
	return 1;
}


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* this;
	int readData;
	while(!feof(pFile))
	{
		this=jug_new();
		readData=fread(this,sizeof(Jugador),1,pFile);
		if(readData==1 && this != NULL)
		{
			ll_add(pArrayListJugador,this);
		}
		else  if(readData!=1)
		{
			 if(!feof(pFile))
			 {
				 printf("\n****** Error al leer el ultimo dato ******");
				 break;
			 }
			 else
			 {
				 printf("\n****** Se leyo el archivo correctamente *******\n");
			 }
		}
	}
	printf("\n***** Jugadores cargados correctamente ******\n");
	fclose(pFile);
    return 1;
}


int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int retorno = 1;
	Jugador* this;
	Seleccion* selecThis;
	char confederacion[50];
	char confederacionAux[50];
	int idSelecciones;
	int idSelec;

	LinkedList* auxListaSelecciones;
	LinkedList* auxLjugadores;
	auxListaSelecciones = ll_clone(pArrayListSeleccion);
	auxLjugadores = ll_clone(pArrayListJugador);

	if(pArrayListJugador != NULL)
	{	controller_printMenuConfederaciones();
		for(int i = 0; i < ll_len(auxListaSelecciones); i++)
		{
			selecThis = (Seleccion*)ll_get(auxListaSelecciones, i);
			selec_getConfederacion(selecThis, confederacion);
			selec_getId(selecThis, &idSelec);
			if(strcmp(confederacion, confederacionAux) == 0)
			{
				for(int j=0; j<ll_len(auxLjugadores); j++)
				{
					this = (Jugador*)ll_get(auxLjugadores, j);
					jug_getIdSeleccion(this, &idSelecciones);
					if(this != NULL && pFile != NULL && idSelecciones == idSelec )
					{
						fwrite(this, sizeof(Jugador), 1, pFile);
						retorno = 0;
						break;
					}
				}
			}
		}
	}

	return retorno;
}



int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* this;
	int readData;
	char bufferId[10];
	char bufferpais[30];
	char bufferconfederacion[30];
	char bufferconvocados[22];
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferpais,bufferconfederacion,bufferconvocados);
	while(!feof(pFile))
	{
		readData = 	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferpais,bufferconfederacion,bufferconvocados);
		if (readData==4)
		{
			this = selec_newParametros(bufferId, bufferpais, bufferconfederacion, bufferconvocados);
			ll_add(pArrayListSeleccion, this);
		}
		else if (readData!=4 && this == NULL)
		{
			if(!feof(pFile))
			{
				printf("\n***** Error al leer el ultimo dato ******\n");
				break;
			}
			else
			{
				printf("\n***** Se leyo todo correctamente *****\n");
			}
		}
	}
	fclose(pFile);
	return 1;
}

int parser_idFromText(FILE* pFile, char* id)
{
    int retorno =0;

	do{
		fflush(stdin);
		if(fgets(id,4,pFile)!=NULL){retorno=1;}
	}while(!feof(pFile));
	fclose(pFile);
	return retorno;
}




void parser_NacionalidadesFromText(FILE* pFile , char* nacionalidades[])
{
	int readData;
	char buffer[20];
	int index = 0;
	int nacSize=0;

	while(!feof(pFile))
	{
		 readData =	fscanf(pFile, "%[^\n]\n", buffer);

		 if(readData==1)
		 {
			 nacSize=snprintf(NULL,0,"%s",buffer);
			 nacionalidades[index]=malloc((nacSize+1)*sizeof(char));
			 nacSize=sprintf(nacionalidades[index],"%s",buffer);
		 }
		 else
		 {
			 if(!feof(pFile))
			 {
				 break;
				 printf("\n****** Error al leer el ultimo dato ******\n");
			 }
			 else
			 {
				 printf("\n****** Se leyo todo el archivo correctamente ******\n");
			 }
		 }
	    index++;
	}
	fclose(pFile);
}



