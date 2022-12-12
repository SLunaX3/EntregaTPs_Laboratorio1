
#include "Seleccion.h"
#include "Jugador.h"
#include <string.h>


int funcionesCriterio_Confederation(void* A, void* B)
{
	int retorno;
	Seleccion* a = (Seleccion*) A;
	Seleccion* b = (Seleccion*) B;
	char auxConfederacionA[50];
	char auxConfederacionB[50];
	selec_getConfederacion(a, auxConfederacionA);
	selec_getConfederacion(b, auxConfederacionB);
	 retorno=stricmp(auxConfederacionA,auxConfederacionB);
	 return retorno;
}


int funcionesCriterio_name(void* A, void* B)
{
	int retorno;
	Jugador* a = (Jugador*) A;
	Jugador* b = (Jugador*) B;
	char auxNombreA[50];
	char auxNombreB[50];
	jug_getNombreCompleto(a, auxNombreA);
	jug_getNombreCompleto(b, auxNombreB);

	retorno = strcmp(auxNombreA,auxNombreB);

	return retorno;
}


int funcionesCriterio_Age(void* A, void* B)
{
	Jugador* a = (Jugador*) A;
	Jugador* b = (Jugador*) B;
	int auxEdadA;
	int auxEdadB;
	jug_getEdad(a, &auxEdadA);
	jug_getEdad(b, &auxEdadB);
	int comparison = 0;
	if( auxEdadA> auxEdadB)
	{
		comparison = 1;
	}
	else if( auxEdadA <auxEdadB)
	{
		comparison = -1;
	}
	return comparison;
}

int funcionesCriterio_nationality(void* A, void* B)
{
	int retorno;
	Jugador* a = (Jugador*) A;
	Jugador* b = (Jugador*) B;
	char auxNacionalidadA[50];
	char auxNacionalidadB[50];
	jug_getNacionalidad(a, auxNacionalidadA );
	jug_getNacionalidad(b, auxNacionalidadB );
	retorno = strcmp(auxNacionalidadA,auxNacionalidadB);
	return retorno;
}
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filteredList;
    int i;
    void* pElement;

    if(this != NULL)
    {
        filteredList = ll_newLinkedList();

        if(filteredList != NULL)
        {
            for(i = 0; i < this->size; i++)
            {
                pElement = ll_get(this, i);

                if(pFunc(pElement))
                {
                    ll_add(this, pElement);
                }
            }
        }
    }

    return filteredList;
}
