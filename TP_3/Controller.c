#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include <string.h>

#include "funcionesCriterio.h"
#include "Valids.h"

int menu()
{

    int opcion;
    printf("\n    ***** MENÚ ***** \n");
    printf("-------------------------------------------------------------------------------\n");
    printf(" 1. CARGA DE ARCHIVOS\n");
    printf(" 2. ALTA DE JUGADORES\n");
    printf(" 3. MODIFICACIÓN DE JUGADORES\n");
    printf(" 4. BAJA DE JUGADORES\n");
    printf(" 5. LISTADOS\n");
    printf(" 6. CONVOCAR JUGADORES\n");
    printf(" 7. ORDENAR Y LISTAR\n");
    printf(" 8. GENERAR ARCHIVO BINARIO\n");
    printf(" 9. CARGAR ARCHIVO BINARIO\n");
    printf(" 10. GUARDAR ARCHIVOS .CSV\n");
    printf(" 11. Salir\n\n");
    printf("------------------------------------------------------------------------------\n");
    pidoValidoNumeroRango(&opcion, "opcion", 1, 11);

    return opcion;
}



int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = -1;
	FILE* f = NULL;

    if(path != NULL && pArrayListJugador != NULL)
    {
        if((f = fopen(path, "r")) != NULL)
        {
            parser_JugadorFromText(f, pArrayListJugador);
            todoOk = 1;
        }
        else{
            if((f = fopen(path, "w")) != NULL){
                printf("\n --> No se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
                todoOk = 0;
            }
        }
        fclose(f);

    }
    else
    {
    	printf("\n ****** ERROR. La lista de pasajeros ya fue cargada ! *****\n");
    }
    return todoOk;
}


int controller_cargarJugadoresDesdeBinario(char *path,LinkedList *pArrayListJugador) {
	int retorno = 0;
	FILE *pArchivo;
	if ((pArchivo = fopen(path, "rb")) != NULL) {
		ll_clear(pArrayListJugador);
		parser_JugadorFromBinary(pArchivo, pArrayListJugador);
	} else {
		if ((pArchivo = fopen(path, "wb")) != NULL) {
			printf(
					"\n***** Al no encontrarse el archivo se creo uno con el nombre \"%s\" *****\n\n",
					path);
			retorno = 1;
		}
	}
	return retorno;
}


int controller_agregarJugador(LinkedList *pArrayListJugador) {
	int retorno;
	int  bufferIntId;
	int bufferEdad;
	int bufferIdSeleccion;
	int bufferIdJugador;
	char bufferId[128];
	char bufferNombre[128];
	char  bufferPosicion[128];
	char bufferNacionalidad[128];
	retorno=0;
	Jugador *this = jug_new();

	fflush(stdin);
	printf("\n ******* Alta Jugador******* \n");

	if (controller_cargarIdJugadorModoTexto("idJugs.csv", bufferId)) {
		bufferIntId = atoi(bufferId);
		bufferIntId++;
		sprintf(bufferId, "%d", bufferIntId);
		bufferIdJugador=bufferIntId;
	}
	getValidStringRango("Ingrese el nombre del Jugador: ", "**** Error al ingresar *****",
			bufferNombre, 128);
	fflush(stdin);
	pidoValidoNumeroRango(&bufferEdad, "edad del jugador entre 18 y 60 anios: ", 18, 60);

	fflush(stdin);

	jug_showAndSetPositions(bufferPosicion);
	jug_getNationalityPlayer(bufferNacionalidad);
	fflush(stdin);
	bufferIdSeleccion=0;

	jug_setId(this, bufferIdJugador);
	jug_setNombreCompleto(this, bufferNombre);
	jug_setPosicion(this, bufferPosicion);
	jug_setNacionalidad(this, bufferNacionalidad);
	jug_setEdad(this, bufferEdad);
	jug_setIdSeleccion(this, bufferIdSeleccion);

	if (this != NULL)
	{
			if(controller_guardarIdJugadorModoTexto("idJugs.csv", bufferId))
			{
			ll_add(pArrayListJugador, this);
			retorno =1;
			printf("\n******* Jugador cargado Correctamente ******\n\n");
			}
	}
	return retorno;
}


int controller_editarJugador(LinkedList *pArrayListJugador) {
	int retorno = 0;
	int	flagJugadorEncontrado = 0;
	int	bufferIdJugadorIngresado;
	int opcion;
	int i;
	int tamJugadores;
	int idJugador;
	int	bufferEdad;

	char bufferNombre[51];
	char bufferPosicion[128];
	char bufferNacionalidad[128];

	Jugador *this;

	printf("\n***** MODIFICAR JUGADOR ******\n\n");
	 pidoValidoNumero(&bufferIdJugadorIngresado,"Id del jugador a modificar");
	fflush(stdin);
	tamJugadores = ll_len(pArrayListJugador);
	for (i = 0; i < tamJugadores; i++) {
		this = (Jugador*) ll_get(pArrayListJugador, i);
		jug_getId(this, &idJugador);
		if (idJugador == bufferIdJugadorIngresado) {
			flagJugadorEncontrado = 1;
			break;
		}
	}
	if (flagJugadorEncontrado == 1)
			{
		jug_getId(this, &idJugador);
		jug_getNombreCompleto(this, bufferNombre);
		jug_getEdad(this, &bufferEdad);
		jug_getNacionalidad(this, bufferNacionalidad);
		jug_getPosicion(this, bufferPosicion);

		jug_printData(this);
		opcion = menuModificaciones();
		operarMenuModificar(opcion, bufferNombre, &bufferEdad,
				bufferNacionalidad, bufferPosicion, this);
		retorno = 1;
	} else
	{
		printf("\n ****** No existe jugador con el ID ingresado ******\n\n");
	}
	return retorno;
}


int controller_removerJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSelecciones) {
	int retorno = 0;
	int flagJugadorEncontrado = 0;
	int flagJugadorConvocado = 0;
	int indiceJugador;
	int i;
	int j;
	int bufferIdSeleccionJugador;
	char confirmacion;
	int tamJug;
	int tamSelecciones;
	int idJugador;
	int idSeleccion;
	int bufferIdJugador;
	int convocados;
	Jugador *this;
	Seleccion *sThis;

	printf("\n**** BAJA DE JUGADOR *****\n\n");
	pidoValidoNumero(&bufferIdJugador,"el ID del Jugador");
	tamJug= ll_len(pArrayListJugador);
	tamSelecciones=ll_len(pArrayListSelecciones);
	for (i = 0; i < tamJug; i++){
		this = (Jugador*) ll_get(pArrayListJugador, i);
		jug_getId(this, &idJugador);
		if (idJugador == bufferIdJugador)
				{
			flagJugadorEncontrado = 1;
			indiceJugador = i;
			jug_getIdSeleccion(this, &bufferIdSeleccionJugador);
			if (bufferIdSeleccionJugador > 0)
					{

				for (j = 0; j < tamSelecciones; j++) {
					sThis = (Seleccion*) ll_get(pArrayListSelecciones, j);
					selec_getId(sThis, &idSeleccion);
					if (idSeleccion == bufferIdSeleccionJugador) {

						flagJugadorConvocado = 1;
						break;
					}
				}
			}
			break;
		}

	}

	if (flagJugadorEncontrado == 1) {
		jug_printData(this);
		confirmacion = getCharOpc(
				"\nConfirme el pedido de baja (S/N):",
				"***ERROR al ingresar la opcion***\n");
		if (confirmacion == 'S'){
			if (flagJugadorConvocado == 1) {
				selec_getConvocados(sThis, &convocados);
				convocados--;
				selec_setConvocados(sThis, convocados);
			}
			printf("******Eliminando jugador del indice %d ********\n", idJugador);
			ll_remove(pArrayListJugador, indiceJugador);
			jug_delete(this);
			printf("***** Jugador dado de baja con exito ******\n");
			retorno = 1;
		}
		else{printf("******Baja cancelada *****\n");}
	}



	else {
		printf("***** No se encontro jugador *****\n");
	}

	return retorno;
}


int controller_listarJugadores(LinkedList *pArrayListJugador)
{
	int retorno = 0;
	Jugador *this;
	int i;
	int tamJugador;
	tamJugador=ll_len(pArrayListJugador);

	controller_cabeceraParaListarYOrdenar();
	for (i = 0; i < tamJugador; i++)
			{
		this = (Jugador*) ll_get(pArrayListJugador, i);
		jug_printData(this);
		retorno = 1;
	}
	printf("\n");
	return retorno;
}




int controller_menuListar()
{
    int opcion;

    printf("\n*** Seleccione Ordenamiento ***\n\n");
    printf(" 1. Todos los jugadores.\n");
    printf(" 2. Todas las selecciones.\n");
    printf(" 3. Jugadores CONVOCADOS (únicamente).\n");
    printf(" 4. Salir\n\n");

    pidoValidoNumeroRango(&opcion , "Opcion ", 1, 4);

    return opcion;
}
void controller_listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;

	opcion = controller_menuListar();

	switch (opcion)
	{
		case 1:
			printf("\nTODOS LOS JUGADORES\n");
			controller_listarJugadoresConDescripcion(pArrayListJugador, pArrayListSeleccion);
			break;
		case 2:
			printf("\nTODAS LAS SELECCIONES\n");
			controller_listarSelecciones(pArrayListSeleccion);
			break;
		case 3:
			printf("\nSOLO LOS CONVOCADOS\n");
			controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
			break;
		case 4:
			printf("\n---> Saliendo .... \n");
			break;
	}
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int todoOk = 0;
    Jugador* this1;
    Seleccion* this2;
    int len1;
    int len2;
    int jugIdSeleccion;

    int idJug;
    char nombreCompleto[100];
    int edad;
    char posicion[50];
    char nacionalidad[50];
    int idSeleccion;
    int j;
    int i;
    int hayConvocados=0;
    char pais[30];

    if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
    {
    	LinkedList* auxArrayListJugador = ll_clone(pArrayListJugador);
    	LinkedList* auxArrayListSeleccion = ll_clone(pArrayListSeleccion);

    	if(auxArrayListJugador!=NULL && auxArrayListSeleccion!=NULL)
    	{
    		if(ll_isEmpty(auxArrayListJugador)==0 && ll_isEmpty(auxArrayListSeleccion)==0)
    		{
    			len1 = ll_len(pArrayListJugador);
    			len2 = ll_len(pArrayListSeleccion);
    			if(len1>0)
    			{
					printf("                       ***** LISTADO DE JUGADORES *****\n\n");
					jug_cabeceraListadoJugadores();
					for(i=0; i < len1 ; i++)
					{
						this1 = (Jugador*) ll_get(pArrayListJugador, i);
						jug_getIdSeleccion(this1, &jugIdSeleccion);


						jug_getId(this1, &idJug);
						jug_getNombreCompleto(this1, nombreCompleto);
						jug_getEdad(this1, &edad);
						jug_getPosicion(this1, posicion);
						jug_getNacionalidad(this1, nacionalidad);

						if(jugIdSeleccion>0)
						{
						    for(j=0; j < len2 ; j++)
						    {
						    	this2 = (Seleccion*) ll_get(pArrayListSeleccion, j);
						    	selec_getId(this2, &idSeleccion);
						    	if(idSeleccion == jugIdSeleccion)
						    	{
						    		selec_getPais(this2, pais);
						    		hayConvocados=1;
								    printf("   %5d | %12s          | %4d  | %12s          | %12s          |  %-30s \n", idJug, nombreCompleto, edad, posicion, nacionalidad, pais);
						    	}
						    }

						   todoOk = 1;

						}

					}
				    if(hayConvocados==0)
				    {
				    	printf("                          No hay jugadores convocados                           \n");
				    }
    			}
    		}
    	}
    }
    else
    {
        printf(" --> Primero debe cargar Jugadores ...\n");
    }
    return todoOk;
}

void controllerConvocarOQuitarDeSeleccion(LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int opcion;
	printf("\n1) Convocar Jugador.\n2) Quitar de la seleccion.\n\n");
	pidoValidoNumeroRango(&opcion, "opcion", 1, 2);
	if (opcion == 1)
	{
		controller_convocarJugador(listaJugadores,listaSelecciones);
	} else
	{
		controller_quitarDeSeleccion(listaJugadores,listaSelecciones);
	}
}


void controllerMenuListar(LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int opcionSubMenu;
	opcionSubMenu = controller_ordenarJugadores(listaJugadores);
	if (opcionSubMenu == 2) {
		controller_ordenarSelecciones(listaSelecciones);
	}
}


int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador) {
	FILE *pArchivo;
	Jugador *this;
	int retorno = 0;
	int bufferId;
	char bufferNombre[128];
	int bufferEdad;
	char bufferPosicion[128];
	char bufferNacionalidad[128];
	int bufferIdSeleccion;
	int tamJugador;
	int i;
	pArchivo = fopen(path, "w");
	if (pArchivo != NULL && pArrayListJugador != NULL) {
		tamJugador=ll_len(pArrayListJugador);
		rewind(pArchivo);
		fprintf(pArchivo,
				"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
		for (i = 0; i <tamJugador ; i++) {
			this = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(this, &bufferId);
			jug_getNombreCompleto(this, bufferNombre);
			jug_getEdad(this, &bufferEdad);
			jug_getPosicion(this, bufferPosicion);
			jug_getNacionalidad(this, bufferNacionalidad);
			jug_getIdSeleccion(this, &bufferIdSeleccion);
			fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", bufferId, bufferNombre,
					bufferEdad, bufferPosicion, bufferNacionalidad,
					bufferIdSeleccion);
		}
		printf("\n****** Los Datos se guardaron correctamente ******\n");
		retorno = 1;

	}
	fclose(pArchivo);
	return retorno;
}


int controller_guardarIdJugadorModoTexto(char *path, char *id) {
	FILE *pArchivo;
	int retorno = 0;
	pArchivo = fopen(path, "w");
	if (pArchivo != NULL) {
		rewind(pArchivo);
		fprintf(pArchivo, "%s", id);
		retorno = 1;
	}

	fclose(pArchivo);
	return retorno;
}



int controller_guardarJugadoresModoBinario(char *path,LinkedList* pArrayListJugador) {
	FILE* pArchivo;
	Jugador* this;
	int retorno = 0;
	int datosLeidos;
	int i;

	pArchivo = fopen(path, "wb");
	if (pArchivo != NULL && pArrayListJugador != NULL) {
		rewind(pArchivo);
		for (i = 0; i < ll_len(pArrayListJugador); i++) {
			this = (Jugador*) ll_get(pArrayListJugador, i);
			datosLeidos = fwrite(this, sizeof(Jugador), 1, pArchivo); retorno = 0;
			if (datosLeidos != 1) {
				printf("\n**** Error al escribir los datos en el archivo.****\n");
			}
		}
		retorno = 1;
		printf("\n --> Datos guardados con exito!!!.\n\n");
	} else {
		printf("\n*** No se pudo acceder al archivo.***\n");
	}
	fclose(pArchivo);
	return retorno;
}

int controller_guardarJugadoresModoBinarioConDescripcion(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo;
	Jugador* this;
	Seleccion*selecThis;
	int retorno = -1;

	int idSeleccion=0;
	int variableaux;
	char nombreConfederacion[128];
	char nombreConfederacionBuffer[128];
	int idSelecJugador=0;
	int opcionConfederacion;
	int tamListaJugadores;
	int tamListaSelecciones;
	int i;
	int j;
	controller_printMenuConfederaciones();
	pidoValidoNumeroRango(&opcionConfederacion,"Id Seleccion", 1, 5);
controller_selectPlayerConfederation(opcionConfederacion, nombreConfederacion);


	pArchivo = fopen(path, "wb");
	if (pArchivo != NULL && pArrayListJugador != NULL) {
		tamListaSelecciones=ll_len(pArrayListSeleccion);
		tamListaJugadores=ll_len(pArrayListJugador);

		rewind(pArchivo);
		for(j=0;j<tamListaSelecciones;j++)
		{
			selecThis=(Seleccion*)ll_get(pArrayListSeleccion,j);
			selec_getConfederacion(selecThis, nombreConfederacionBuffer);
			variableaux=strcmp(nombreConfederacion,nombreConfederacionBuffer);
			if( variableaux==0)
			{
			selec_getId(selecThis, &idSeleccion);
				for ( i = 0; i < tamListaJugadores; i++)
				{
					this = (Jugador*) ll_get(pArrayListJugador, i);
					jug_getIdSeleccion(this, &idSelecJugador);
					if(pArchivo!=NULL && idSeleccion==idSelecJugador)
					{
						fwrite(this, sizeof(Jugador), 1, pArchivo);
						retorno = 1;
					}

				}

			}

		}
		if (retorno==-1)
		{
			printf("\n*** Error al escribir los datos en el archivo. \n"
					"*** No hay jugadores convocados en esta confederacion.\n");

		}
		else
		{
			retorno = 1;
			printf("\n --> Datos guardados con exito!!!.\n\n");
		}

	} else {
		printf("\n***** No se pudo acceder al archivo. *****\n");
	}
	fclose(pArchivo);
	return retorno;
}


int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	int retorno = 1;

	FILE *pArchivo;
	if ((pArchivo = fopen(path, "r")) != NULL) {
		parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
	} else {
		if ((pArchivo = fopen(path, "w")) != NULL) {
			printf(
					"\n*****Al no encontrarse el archivo se creo uno con el nombre \"%s\" ******\n\n",
					path);
			retorno = 0;
		}
	}

	return retorno;
}





int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	Seleccion *this;

	printf("-----------------------------------------------------------------------------");
	printf("\n|    ID    |          PAIS            |     CONFEDERACION     | CONVOCADOS  |\n ");
	printf("-----------------------------------------------------------------------------\n");

	for (int i = 0; i < ll_len(pArrayListSeleccion); i++)
			{
		this = (Seleccion*) ll_get(pArrayListSeleccion, i);
		selec_printData(this);
		retorno = 1;
	}
	printf("\n");
	return retorno;
}


int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {
	LinkedList* auxListaSelecciones;

	if(pArrayListSeleccion!=NULL)
	{
		auxListaSelecciones=ll_clone(pArrayListSeleccion);
		if(auxListaSelecciones!=NULL)
		{
			ll_sort(auxListaSelecciones, funcionesCriterio_Confederation, 1);
			controller_listarSelecciones(auxListaSelecciones);
			ll_deleteLinkedList(auxListaSelecciones);
		}
	}
	return 1;
}


int controller_guardarSeleccionesModoTexto(char *path, LinkedList *pArrayListSeleccion)
{
			FILE *pArchivo;
			Seleccion*pSeleccion;
			int retorno = 0;

			int bufferId;
			char bufferPais[128];
			char bufferConfederacion[128];
			int bufferConvocados;
				pArchivo = fopen(path, "w");
			if (pArchivo != NULL && pArrayListSeleccion != NULL) {
				rewind(pArchivo);
				fprintf(pArchivo,
						"id,pais,confederacion,convocados\n");
				for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
					pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
					selec_getId(pSeleccion, &bufferId);
					selec_getPais(pSeleccion, bufferPais);
					selec_getConfederacion(pSeleccion, bufferConfederacion);
					selec_getConvocados(pSeleccion, &bufferConvocados);
					fprintf(pArchivo,"%d,%s,%s,%d\n", bufferId, bufferPais,
							bufferConfederacion, bufferConvocados);
				}
				printf("\n***** Los Datos se guardaron correctamente *****\n");
				retorno = 1;

			}
			fclose(pArchivo);
			return retorno;
		}
void controller_printMenuPosiciones() {
	printf("\n***** MENU POSICIONES ***** \n");
	printf("----------------------------\n");
	printf(" 1. Portero \n");
	printf(" 2. Defensa central \n");
	printf(" 3. Lateral izquierdo \n");
	printf(" 4. Lateral derecho \n");
	printf(" 5. Pivote \n");
	printf(" 6. Mediocentro \n");
	printf(" 7. Mediocentro ofensivo \n");
	printf(" 8. Extremo izquierdo \n");
	printf(" 9. Extremo derecho \n");
	printf(" 10. Mediapunta \n");
	printf(" 11. Delantero centro \n");
	printf(" 12. Interior derecho \n");
	printf(" 13. Interior izquierdo \n\n");
}




void controller_printMenuConfederaciones() {
	printf("\n***** MENU CONFEDERACIONES ***** \n");
	printf("---------------------------------\n");
	printf(" 1.AFC \n");
	printf(" 2.CAF \n");
	printf(" 3.CONCACAF \n");
	printf(" 4.CONMEBOL \n");
	printf(" 5.UEFA \n\n");

}

int controller_cargarIdJugadorModoTexto(char *path, char *id) {
	int retorno = 0;
	FILE *pArchivo;
	if ((pArchivo = fopen(path, "r")) != NULL) {
		parser_idFromText(pArchivo, id);
		retorno = 1;
	}
	return retorno;
}

int menuModificaciones() {
    int opcion;

    printf("\n*** Seleccione campo a Modificar ***\n\n");
    printf(" 1. Nombre Completo.\n");
    printf(" 2. Edad.\n");
    printf(" 3. Posición.\n");
    printf(" 4. Nacionalidad.\n");
    printf(" 5. Salir\n\n");

    pidoValidoNumeroRango(&opcion, "opcion ", 1, 5);
    return opcion;
}

int operarMenuModificar(int opcion, char *bufferNombre, int *bufferEdad,
		char *bufferNacionalidad, char *bufferPosicion, Jugador *this) {
	int retorno = 0;
	char confirmacion;

	int bufferEdadIngresada;
	char bufferNombreIngresado[51];
	char bufferPosicionIngresada[128];
	char bufferNacionalidadIngresada[128];

	switch (opcion) {
	case 1:
		printf("\n*** Modificar nombre ****\n");
		getValidStringRango("Ingrese el nuevo nombre: ",
				"\n****Error. Nombre no valido, reintentelo:", bufferNombreIngresado,
				51);
		printf("\nSe modificara %s por %s \n", bufferNombre,
				bufferNombreIngresado);
		confirmacion = getCharOpc(
				"\nPor favor confirme el cambio  (s/n):",
				"\n*** Error al ingresar la opcion ***");
		if (confirmacion == 'S') {

			jug_setNombreCompleto(this, bufferNombreIngresado);

			printf("\n ****** Se modifico el nombre correctamente ******\n");
			jug_printData(this);
			retorno = 1;
		} else {
			printf("\n****** Modificacion cancelada *******\n");
		}
		break;
	case 2:
		printf("\n*** Modificar edad ***\n");
		pidoValidoNumeroRango(&bufferEdadIngresada, "edad del jugador entre 18 y 60 anios",
				 18, 60);
		printf("\nSe reemplazara %d por %d\n", *bufferEdad, bufferEdadIngresada);
		fflush(stdin);
		confirmacion = getCharOpc(
				"\nPor favor confirme el cambio (s/n):",
				"\n**** Error al ingresar la opcion ****");
		if (confirmacion == 'S') {
			printf("\nprint dentro de confirmacion  %c", confirmacion);

			jug_setEdad(this, bufferEdadIngresada);
			printf("\n***** Se modifico la edad correctamente *****\n");
			jug_printData(this);
			retorno = 1;
		} else {
			printf("\n******** Modificacion cancelada *******\n");
		}
		break;
	case 3:
		printf("\n*** Modificar posicion ***\n");
		jug_showAndSetPositions(bufferPosicionIngresada);
		printf("\nSe reemplazara %s por %s\n", bufferPosicion,
				bufferPosicionIngresada);
		fflush(stdin);
		confirmacion = getCharOpc(
				"\nPor favor confirme el cambio (s/n):",
				"\n**** Error al ingresar la opcion ****\n");
		if (confirmacion == 'S') {
			jug_setPosicion(this, bufferPosicionIngresada);
			printf("\n****** Se modifico la posicion correctamente *****\n");
			jug_printData(this);
			retorno = 1;
		} else {
			printf("\n****** Modificacion cancelada ******\n");
		}
		break;
	case 4:
		printf("\n*** Modificar nacionalidad ***\n");
		jug_getNationalityPlayer(bufferNacionalidadIngresada);
		printf("\nSe modificara %s por %s \n", bufferNacionalidad,
				bufferNacionalidadIngresada);
		confirmacion = getCharOpc(
				"\nPor favor confirme el cambio (s/n):",
				"\n**** Error al ingresar la opcion ****\n");
		if (confirmacion == 'S') {
			jug_setNacionalidad(this, bufferNacionalidadIngresada);
			printf("\n***** Se modifico la nacionalidad correctamente *****\n");
			jug_printData(this);
			retorno = 1;
		} else {
			printf("\n****** Modificacion cancelada *******\n");
		}
		break;
	}

	return retorno;
}

LinkedList* controller_cargarListaJugadoresNoConvocados(LinkedList* pArrayListJugador)
{
	Jugador* this;
	int idJug;
	char nombreCompleto[51];
	int edad;
	char posicion[51];
	char nacionalidad[50];
	int idSeleccion;
	LinkedList* noConvocados=ll_newLinkedList();

	if (pArrayListJugador != NULL)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			this = (Jugador*) ll_get(pArrayListJugador, i);

			jug_getId(this, &idJug);
			jug_getNombreCompleto(this, nombreCompleto);
			jug_getEdad(this, &edad);
			jug_getPosicion(this, posicion);
			jug_getNacionalidad(this, nacionalidad);
			jug_getIdSeleccion(this, &idSeleccion);

			if(idSeleccion==0)
			{
				ll_add(noConvocados, this);
			}
		}

	}
	return noConvocados;
}
LinkedList* controller_cargarListaJugadoresConvocados(LinkedList* pArrayListJugador)
{
	Jugador* this;
	int idJug;
	char nombreCompleto[51];
	int edad;
	char posicion[51];
	char nacionalidad[50];
	int idSeleccion;
	LinkedList* Convocados=ll_newLinkedList();

	if (pArrayListJugador != NULL)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			this = (Jugador*) ll_get(pArrayListJugador, i);

			jug_getId(this, &idJug);
			jug_getNombreCompleto(this, nombreCompleto);
			jug_getEdad(this, &edad);
			jug_getPosicion(this, posicion);
			jug_getNacionalidad(this, nacionalidad);
			jug_getIdSeleccion(this, &idSeleccion);

			if(idSeleccion!=0)
			{
				ll_add(Convocados, this);
			}
		}

	}
	return Convocados;
}



void controller_cabeceraParaListarYOrdenar()
{
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("      ID  |      NombreCompleto                |    Edad    |     Nacionalidad     |    Posición\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
}


int controller_listarJugadoresConDescripcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int todoOk = 0;
    Jugador* this1;
    Seleccion* this2;
    int len1;
    int len2;
    int jugIdSeleccion;

    int idJug;
    char nombreCompleto[100];
    int edad;
    char posicion[50];
    char nacionalidad[50];
    int idSeleccion;

    char pais[30];

    if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
    {
    	LinkedList* auxArrayListJugador = ll_clone(pArrayListJugador);
    	LinkedList* auxArrayListSeleccion = ll_clone(pArrayListSeleccion);

    	if(auxArrayListJugador!=NULL && auxArrayListSeleccion!=NULL)
    	{
    		if(ll_isEmpty(auxArrayListJugador)==0 && ll_isEmpty(auxArrayListSeleccion)==0)
    		{
    			len1 = ll_len(pArrayListJugador);
    			len2= ll_len(auxArrayListSeleccion);
    			if(len1>0)
    			{
					printf("                       ***** LISTADO DE JUGADORES *****\n\n");
					jug_cabeceraListadoJugadores();
					for(int i=0; i < len1 ; i++)
					{
						this1 = (Jugador*) ll_get(pArrayListJugador, i);
						jug_getIdSeleccion(this1, &jugIdSeleccion);

						jug_getId(this1, &idJug);
						jug_getNombreCompleto(this1, nombreCompleto);
						jug_getEdad(this1, &edad);
						jug_getPosicion(this1, posicion);
						jug_getNacionalidad(this1, nacionalidad);
						if(jugIdSeleccion==0)
						{
							printf("     %5d | %-30s          | %-4d  | %-20s          | %-15s          |  No Convocado \n", idJug, nombreCompleto, edad, posicion, nacionalidad);

						}
						else
						{
						    for(int j=0; j < len2 ; j++)
						    {
						    	this2 = (Seleccion*) ll_get(pArrayListSeleccion, j);
						    	selec_getId(this2, &idSeleccion);
						    	if(idSeleccion == jugIdSeleccion)
						    	{
						    		selec_getPais(this2, pais);
								    printf("   %5d | %-30s          | %-4d  | %-20s          | %-15s          |  %-30s \n", idJug, nombreCompleto, edad, posicion, nacionalidad, pais);

						    	}
						    }
						   todoOk = 1;

						}
					}

    			}
    		}
    	}
    }
    else
    {
        printf(" --> Primero debe cargar Jugadores ...\n");
    }
    return todoOk;
}

int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int todoOk = 0;
    Jugador* this1;
    int len1;
    int jugIdSeleccion;
    int idJug;
    char nombreCompleto[100];
    int edad;
    char posicion[50];
    char nacionalidad[50];


    if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
    {
    	LinkedList* auxArrayListJugador = ll_clone(pArrayListJugador);
    	LinkedList* auxArrayListSeleccion = ll_clone(pArrayListSeleccion);

    	if(auxArrayListJugador!=NULL && auxArrayListSeleccion!=NULL)
    	{
    		if(ll_isEmpty(auxArrayListJugador)==0 && ll_isEmpty(auxArrayListSeleccion)==0)
    		{
    			len1 = ll_len(pArrayListJugador);
      			if(len1>0)
    			{
					printf("                       ***** LISTADO DE JUGADORES *****\n\n");
					jug_cabeceraListadoJugadores();
					for(int i=0; i < len1 ; i++)
					{
						this1 = (Jugador*) ll_get(pArrayListJugador, i);
						jug_getIdSeleccion(this1, &jugIdSeleccion);

						jug_getId(this1, &idJug);
						jug_getNombreCompleto(this1, nombreCompleto);
						jug_getEdad(this1, &edad);
						jug_getPosicion(this1, posicion);
						jug_getNacionalidad(this1, nacionalidad);
						if(jugIdSeleccion==0)
						{
							printf("   %5d | %-30s          | %-4d  | %-20s          | %-15s          |  No Convocado \n", idJug, nombreCompleto, edad, posicion, nacionalidad);

						}
						todoOk = 1;
					}

    			}
    		}
    	}
    }
    else
    {
        printf(" --> Primero debe cargar Jugadores ...\n");
    }
    return todoOk;
}

int controller_convocarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	int auxId;
	Jugador* jugadorActual = NULL;
	Seleccion* selecjugadorActual;

	int idSel;
	int id;
	int i;
	int j;
	int idSeleccionJugador;
	char pais[30];
	char confederacion[30];
	int convocados;
	int auxIdSeleccion;
	LinkedList* noConvocados;

	controller_listarJugadoresNoConvocados(pArrayListJugador,pArrayListSeleccion);
	noConvocados=controller_cargarListaJugadoresNoConvocados(pArrayListJugador);
	pidoValidoNumero(&auxId, "el id del jugador");
	if (noConvocados != NULL && pArrayListSeleccion!=NULL)
	{
		if(!validarIdJugador(noConvocados, auxId))
		{
			printf("\n***** El jugador no se encuentra en la lista de jugadores no convocados *****\n");
			retorno =-1;
		}
		else
		{
			int tamListaJugadores;
			int tamListaSelecciones;
			tamListaJugadores=ll_len(pArrayListJugador);
			tamListaSelecciones=ll_len(pArrayListSeleccion);
			controller_listarSelecciones(pArrayListSeleccion);
			pidoValidoNumero(&auxIdSeleccion,"el id de la seleccion");
			for( i=0;i<tamListaJugadores; i++)
			{
				jugadorActual=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(jugadorActual, &id);
				jug_getIdSeleccion(jugadorActual, &idSeleccionJugador);
				if(auxId==id)
				{
					for(j=0; j<tamListaSelecciones ;j++)
					{
						selecjugadorActual = (Seleccion*) ll_get(pArrayListSeleccion, j);
						selec_getId(selecjugadorActual, &idSel);
						if(auxIdSeleccion==idSel)
						{
							selec_getPais(selecjugadorActual, pais);
							selec_getConfederacion(selecjugadorActual, confederacion);
							selec_getConvocados(selecjugadorActual, &convocados);
							if(convocados>=22)
							{
								printf("\n***** No hay cupo disponible en esa seleccion *****\n");
								retorno=-1;
								break;
							}
							convocados++;
							jug_setIdSeleccion(jugadorActual,auxIdSeleccion);
							selec_setConvocados(selecjugadorActual, convocados);
							retorno = 1;
						}
					}
				}
			}

		}
	}
return retorno;
}

int validarIdJugador(LinkedList* pArrayListJugador,int idIngresada)
{
	int retorno=0;
	Jugador* this;
	int idJugador;

	if(pArrayListJugador!=NULL && idIngresada>0)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			this = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(this, &idJugador);
			if(idJugador==idIngresada)
			{
				retorno=1;
				printf("\n**** Id ingresada encontrada ****\n");
				break;
			}
		}
	}
return retorno;
}

int traerJugadorPorId(LinkedList* pArrayListJugador,int idIngresada, Jugador* jugador)
{
	int retorno=0;
	Jugador* jugadorTemporal;
	int idJugador;

	if(pArrayListJugador!=NULL && idIngresada>0)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugadorTemporal = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(jugadorTemporal, &idJugador);
			if(idJugador==idIngresada)
			{
				jugador = jugadorTemporal;
				retorno=1;
				break;
			}
		}
	}
return retorno;
}
int criterioEdad(void* this, void* thisTwo)
{
	Jugador* auxUno;
	Jugador* auxDos;
	int retorno= 0;
	if(this!=NULL && thisTwo!=NULL)
	{
		auxUno=(Jugador*)this;
		auxDos=(Jugador*)thisTwo;
		printf("print entro primer if");
		if(auxUno->edad > auxDos->edad)
		{
			printf("print entro segundo if");
			retorno=1;
		}
		else
		{
			if(auxUno->edad < auxDos->edad)
			{
				printf("print entro else if");
				retorno=-1;
			}
		}
	}
	return retorno;
}

int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int order = 1;
	int criterio;
	int retorno=0;
	LinkedList* auxListaJugadores;
	if(pArrayListJugador!=NULL)
	{

		printf("\n1)Jugadores por nacionalidad.\n2)Selecciones por confederacion.\n3)Jugadores por edad.\n4)Jugadores por nombre.\n\n");
		pidoValidoNumeroRango(&criterio,"opcion", 1, 4);
		switch(criterio)
			{
				case 1: //Ordenar por NACIONALIDAD
						printf("\n  Ordenando... \n");
						auxListaJugadores=ll_clone(pArrayListJugador);
						ll_sort(auxListaJugadores, funcionesCriterio_nationality, order);
						controller_listarJugadores(auxListaJugadores);
						retorno=1;
						break;
				case 2: //Ordenar por CONFEDERACION
						retorno=2;
						break;

				case 3: //Ordenar por EDAD
						printf("\n  Ordenando...\n");
						auxListaJugadores=ll_clone(pArrayListJugador);
						ll_sort(auxListaJugadores, funcionesCriterio_Age, order);
						controller_listarJugadores(auxListaJugadores);
						retorno=1;

						break;

				case 4: //Ordenar por NOMBRE
						printf("\n  Ordenando...\n");
						auxListaJugadores=ll_clone(pArrayListJugador);
						ll_sort(auxListaJugadores,funcionesCriterio_name, order);
						controller_listarJugadores(auxListaJugadores);
						retorno=1;

						break;
			}
		}

    return retorno;
}



int controller_quitarDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	Jugador* jugadorActual = NULL;
	Seleccion* selecjugadorActual;

	int idSel;
	int id;
	int auxId;
	int idSeleccionJugador;
	LinkedList* convocados;
	int auxConvocados;
	controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
	convocados = controller_cargarListaJugadoresConvocados(pArrayListJugador);
	pidoValidoNumero(&auxId,"el id del jugador");
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && convocados!=NULL)
	{
		if(!validarIdJugador(convocados, auxId))
		{
			printf("\n****** El jugador no se encuentra en la lista de jugadores convocados ******\n");
			retorno =-1;
		}
		else
		{
			for(int i=0;i<ll_len(pArrayListJugador); i++)
			{
				jugadorActual=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(jugadorActual, &id);
				jug_getIdSeleccion(jugadorActual, &idSeleccionJugador);
				if(auxId==id)
				{
					for(int j=0; j< ll_len(pArrayListSeleccion);j++)
					{
						selecjugadorActual = (Seleccion*) ll_get(pArrayListSeleccion, j);
						selec_getId(selecjugadorActual, &idSel);
						selec_getConvocados(selecjugadorActual, &auxConvocados);
						auxConvocados--;
						retorno = 1;
						selec_setConvocados(selecjugadorActual, auxConvocados);
						jug_setIdSeleccion(jugadorActual, 0);
					}
				}
			}
		}

	}
	return retorno;
}


int controller_selectPlayerConfederation(int opcion,char auxConfederation[])
{
	int retorno= 0;
	switch(opcion)
	{
	case 1:
			strcpy(auxConfederation, "AFC");
			retorno=1;
			break;
	case 2:
			strcpy(auxConfederation, "CAF");
			retorno=1;
			break;
	case 3:
			strcpy(auxConfederation, "CONCACAF");
			retorno=1;
			break;
	case 4:
			strcpy(auxConfederation, "CONMEBOL");
			retorno=1;
			break;
	case 5:
			strcpy(auxConfederation, "UEFA");
			retorno=1;
			break;
	}
	return retorno;
}
