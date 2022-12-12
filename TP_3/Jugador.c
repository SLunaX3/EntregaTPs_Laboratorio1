#include "Jugador.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Seleccion.h"
#include "Valids.h"
#include "Controller.h"


Jugador* jug_new() {
	Jugador *unJugador = malloc(sizeof(Jugador));
	if (unJugador != NULL) {
		unJugador->id = 0;
		strcpy(unJugador->nombreCompleto, "");
		unJugador->edad = 0;
		strcpy(unJugador->posicion, "");
		strcpy(unJugador->nacionalidad, "");
		unJugador->idSeleccion = 0;
	} else {
		printf("\n***** No hay espacio para cargar un nuevo jugador *****\n");
	}
	return unJugador;
}
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr) {
	int auxId;
	int auxEdad;
	int auxIdSeleccion;
	int flagSetters = 1;

	Jugador *unJugador = jug_new();
	auxId = atoi(idStr);
	if (jug_setId(unJugador, auxId) != 1) {
		flagSetters = 2;
	}

	if (jug_setNombreCompleto(unJugador, nombreCompletoStr)!=1) {
		flagSetters = 3;
	}

	auxEdad = atoi(edadStr);
	if (jug_setEdad(unJugador, auxEdad) != 1) {
		flagSetters = 4;
	}

	if (jug_setPosicion(unJugador, posicionStr)!=1) {
		flagSetters = 5;
	}

	if (jug_setNacionalidad(unJugador, nacionalidadStr)!=1) {
		flagSetters = 6;
	}

	auxIdSeleccion = atoi(idSelccionStr);
	if (jug_setIdSeleccion(unJugador, auxIdSeleccion) != 1) {
		flagSetters = 7;
	}

	if (flagSetters != 1) {
		printf("\n****** Error al crear jugador ******\n");
		printf("\n***** Error en setter numero: %d ******\n",flagSetters);
	}

	return unJugador;
}

int jug_setId(Jugador *this, int id) {

	int retorno = 0;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int jug_getId(Jugador *this, int *id) {
	int retorno = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this, char* nombre) {
	int retorno = 0;
	if (this != NULL && strlen(nombre)>0) {
		strcpy(this->nombreCompleto, nombre);
		retorno = 1;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador *this, char *nombre) {
	int retorno = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombreCompleto);
		retorno = 1;
	}
	return retorno;

}

int jug_setPosicion(Jugador *this, char *posicion) {
	int retorno = 0;
	if (this != NULL && posicion != NULL) {
		strcpy(this->posicion, posicion);
		retorno = 1;
	}
	return retorno;
}

int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno = 0;
	if (this != NULL && posicion != NULL) {
		strcpy(posicion, this->posicion);
		retorno = 1;
	}
	return retorno;
}

int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}
	return retorno;
}

int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}
	return retorno;
}

int jug_setEdad(Jugador *this, int edad) {

	int retorno = 0;
	if (this != NULL && edad > 0) {
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}

int jug_getEdad(Jugador *this, int *edad) {
	int retorno = 0;
	if (this != NULL && edad != NULL) {
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}
void jug_delete(Jugador* this)
{
	free(this);
}

void jug_printData(Jugador* this)
{
   	int id;
    char nombre[51];
    int edad;
    int idSeleccion;
    char nacionalidad[51];
    char posicion[51];
    jug_getId(this, &id);
    jug_getNombreCompleto(this, nombre);
    jug_getEdad(this, &edad);
    jug_getIdSeleccion(this, &idSeleccion);
    jug_getNacionalidad(this, nacionalidad);
    jug_getPosicion(this, posicion);

			printf("\n   %4d   |      %-30s|    %-4d    | %-20s |    %-15s      |\n ",id,nombre,edad,nacionalidad,posicion);


}


int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int retorno = 0;
	if (this != NULL && idSeleccion >= 0) {
		this->idSeleccion= idSeleccion;
		retorno = 1;
	}
	return retorno;
}

int jug_getIdSeleccion(Jugador *this, int *idSeleccion) {
	int retorno = 0;
	if (this != NULL && idSeleccion != NULL) {
		*idSeleccion=this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}


int jug_validateId(LinkedList* pArrayListJugador, char* idstring)
{
	int retorno=0;
	int bufferId;

	bufferId=atoi(idstring);
	Jugador* this;
	if(pArrayListJugador != NULL)
	{
		for(int i=0; i<ll_len(pArrayListJugador);i++)
		{
			this = (Jugador*)ll_get(pArrayListJugador, i);
			if(this->id==bufferId)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}


void jug_cabeceraListadoJugadores()
{
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("   ID      |      NombreCompleto                     | Edad  |   Posición                    | Nacionalidad             | idSelección\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
}




int jug_buscarId(LinkedList* pArrayListJugador, int *pIndex, int id)
{
    int todoOk = 0;
    int idAux;
    Jugador *this = NULL;

    if(pArrayListJugador != NULL && pIndex >= 0 && id >= 0)
    {
        for(int i=0; i < ll_len(pArrayListJugador); i++)
        {
            this = ll_get(pArrayListJugador, i);
            if(this != NULL)
            {
                jug_getId(this, &idAux);
                if(id == idAux)
                {
                    *pIndex = i;
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}

int jug_showAndSetPositions(char bufferPosicion[])
{
	int todoOk = -1;
	int opcion;
	controller_printMenuPosiciones();
	pidoValidoNumeroRango(&opcion,"una opcion ", 1, 13);

	switch(opcion)
	{
	case 1:
		strcpy(bufferPosicion, "Portero");
			todoOk = 1;
		break;
	case 2:
		strcpy(bufferPosicion, "Defensa Central");
			todoOk = 1;
		break;
	case 3:
		strcpy(bufferPosicion, "Lateral Izquierdo");
			todoOk = 1;
		break;
	case 4:
		strcpy(bufferPosicion, "Lateral Derecho");
			todoOk = 1;
		break;
	case 5:
		strcpy(bufferPosicion, "Pivote");
			todoOk = 1;
		break;
	case 6:
		strcpy(bufferPosicion, "MedioCentro");
			todoOk = 1;
		break;
	case 7:
		strcpy(bufferPosicion, "MedioCentro Ofensivo");
			todoOk = 1;
		break;
	case 8:
		strcpy(bufferPosicion, "Extremo Izquierdo");
			todoOk = 1;
		break;
	case 9:
		strcpy(bufferPosicion, "Extremo Derecho");
			todoOk = 1;
		break;
	case 10:
		strcpy(bufferPosicion, "MediaPunta");
			todoOk = 1;
		break;
	case 11:
		strcpy(bufferPosicion, "DelanteroCentro");
			todoOk = 1;
		break;
	case 12:
		strcpy(bufferPosicion, "Interior Derecho");
			todoOk = 1;
		break;
	case 13:
		strcpy(bufferPosicion, "Interior Izquierdo");
			todoOk = 1;
		break;
	}

	return todoOk;
}



int jug_getNationalityPlayer(char *pNacionalidad)
{
	int todoOk = 0;
	int i;
	char auxNationality[32][30] =
	{"Saudi", "Australiano", "SurCoreano ", "Irani", "Japones", "Qatari", "Camerunes", "Ganhes", "Marroqui", "Senegales", "Tunecino", "Canadience", "Costarricense", "Estadounidense", "Mexicano", "Argentino", "Brasilenio", "Ecuatoriano", "Uruguayo", "Aleman", "Belga", "Croata", "Danes", "Espaniol", "Frances",
					"Gales", "Neerlandes", "Ingles", "Polaco", "Portugues", "Serbio", "Suizo" };


	if (pNacionalidad != NULL)
	{
		do
		{
			printf("\n***NACIONALIDADES***\n");
			for(i=0; i<32; i++)
			{
				printf("%-20s \n", auxNationality[i]);
			}

			if(getStringLetrasRango("Ingrese la nacionalidad: ", pNacionalidad, 20))
			{
				for(int i=0; i<32; i++)
				{
					if(strcmp(pNacionalidad, auxNationality[i])==0)
					{
						strcpy(pNacionalidad, auxNationality[i]);
						todoOk = 1;
					}
				}
			}
		}while(todoOk==0);
	}
	return todoOk;
}

