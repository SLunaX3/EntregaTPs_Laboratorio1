
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "Valids.h"


int esNumero(char* cadena)
{
	   int todoOk = 1;
	    int esNumero;

	    if(cadena != NULL)
	    {
	        for(int i = 0; i < strlen(cadena) -1; i++)
	        {
	            esNumero = isdigit(cadena[i]);
	            if(esNumero == 0)
	            {
	                todoOk = 0;
	                break;
	            }
	        }
	    }

	    return todoOk;
}


int convertirCharAInt(char num[], int* pNumero)
{
    int todoOk = 0;

    if(num != NULL && pNumero != NULL)
    {
        *pNumero = atoi(num);
        todoOk = 1;
    }
    return todoOk;
}


int gets_getNumerInt(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	char buffNum[100];
	int retorno;
	if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        printf("%s ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);

        while(esNumero(buffNum) == 0)
        {
            printf("%s ", mensajeError);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }

        if(convertirCharAInt(buffNum, &retorno))
        {

            if(retorno < minimo || retorno > maximo)
            {
                printf("%s ", mensajeError);
                fflush(stdin);
                fgets(buffNum, 100, stdin);
                convertirCharAInt(buffNum, &retorno);
            }
        }
    }
	return retorno;
}

int esSoloLetras(char* cadena)
{
	int todoOk = 1;
	int i;

	if(cadena!=NULL)
	{
		for(i=0; cadena[i]!='\0' && i<strlen(cadena);i++)
		{
			if((cadena[i] != ' ') && (cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'a'||cadena[i]>'z'))
			{
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}



void corregirMayusculas(char cadena[])
{
    int lenght;
    lenght = strlen(cadena);
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(int i=0; i<lenght; i++)
    {
        if(cadena[i] == ' ')
        {
            cadena[i+1] = toupper(cadena[i+1]);
        }
    }
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", input);
}


int getStringLetrasRango(char* mensaje,char cadena[], int tam)
{
	int todoOk = 0;
    char aux[256];
    getString(mensaje,aux);
    int i=0;
    if(esSoloLetras(aux))
    {
        while(strlen(aux)>tam)
        {i++;
            printf("\n --> ERROR. Supero la cantidad de caracteres permitidos\n\n");
            getString(mensaje,aux);
            continue;
        }
        corregirMayusculas(aux);
        strcpy(cadena,aux);
        todoOk = 1;
    }
    return todoOk;
}

void getValidStringRango(char* mensaje,char* mensajeERROR, char cadena[], int tam)
{
	int flag=0;

    do
    {
        if (!getStringLetrasRango(mensaje,cadena, tam))
        {
            printf ("%s\n",mensajeERROR);
            fflush(stdin);
            continue;
        }
        else
        {
        	flag=1;
        }
        fflush(stdin);
        break;
    }while(flag!=1);
}





int pidoValidoNumero(int* pNumero, char* mensaje)
{
    int todoOk = 0;
    char bufferNum[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(bufferNum, 100, stdin);

        while(esNumero(bufferNum) == 0 || stricmp(bufferNum , "\n") == 0)
        {
            printf("*** Ingreso inválido ****.\n--> Reingrese %s: ", mensaje);
            fflush(stdin);
            fgets(bufferNum, 100, stdin);
        }
        if(convertirCharAInt(bufferNum, &numero))
        {
            *pNumero = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}

int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo)
{
    int todoOk = 0;
    char bufferNum[100];
    int numero;

    if(pNumero != NULL && mensaje != NULL && minimo < maximo)
    {
        printf("Ingrese %s: ", mensaje);
        while(todoOk==0)
        {
			fflush(stdin);
			fgets(bufferNum, 100, stdin);
        	if(esNumero(bufferNum) == 0 || stricmp(bufferNum , "\n") == 0)
        	{
				printf("**** Ingreso inválido ****.\n--> Reingrese %s: ", mensaje);
        	}
        	else
        	{
        		if(convertirCharAInt(bufferNum, &numero))
				{
					if(numero < minimo || numero > maximo)
					{
						printf("***** Numero fuera de rango, NO GUARDADO! Reingrese %s: ", mensaje);
					}
					else
					{
						*pNumero = numero;
						todoOk = 1;
					}
				}
        	}
        }
    }
    return todoOk;
}

int esFlotante(char* flotante,int tam)
{
    int todoOk = 1;
    int esFloat;
    int coma = tam;

    if(flotante != NULL && tam > 0)
    {
        for(int i = 0; i < strlen(flotante) -1; i++)
        {
            if(flotante[i] == '.')
            {
                coma = i;
            }

        }
        if(coma != tam)
        {
            for(int i = 0; i < coma; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
            for(int i = coma +1; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);
                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
    }
    return todoOk;
}

float gets_getNumerFloat(char* mensaje, char* mensajeError, float minimo, float maximo)
{
	char buffNum[100];
	int tam = 100;
	float retorno;
	if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        printf("%s ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);

        while(!esFlotante(buffNum, tam))
        {
            printf("%s ", mensajeError);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAFloat(buffNum, &retorno))
        {
            if(retorno < minimo || retorno > maximo)
            {
                printf("%s ", mensajeError);
                fflush(stdin);
                fgets(buffNum, 100, stdin);
                convertirCharAFloat(buffNum, &retorno);
            }
        }
    }
	return retorno;
}

int convertirCharAFloat(char flotante[], float* pFloat)
{
    int todoOk = 0;

    if(flotante != NULL && pFloat != NULL)
    {
        *pFloat = atof(flotante);
        todoOk = 1;
    }
    return todoOk;
}


char getCharOpc(char* mensaje, char* mensajeError)
{
	char aux;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&aux);
	aux=toupper(aux);
	while(aux!= 'S' && aux!= 'N')
	{
		printf("%s",mensajeError);
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&aux);
		aux=toupper(aux);

	}
	return aux;
}
