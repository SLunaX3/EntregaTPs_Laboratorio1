#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "Valids.h"

int main() {

	setbuf(stdout, NULL);

	char seguir = 'S';
	int flagSalir = 0;
	int flagBinario=0;

	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList* listaJugadoresBin=ll_newLinkedList();
	int archivoEstado = 0; // 0 estado inicial, 1 cambios por guardar

	do {
		switch (menu()) {
		case 1:
        	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones)==1)
        	{
        		if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) && controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones))
        		{
        			printf("\n ****** LISTA CARGADA CON EXITO ******\n\n");
        		}
        	}

            break;
		case 2:
        	if((!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) || flagBinario==1)
        	{
        		controller_agregarJugador(listaJugadores);
        		archivoEstado = 1;
        	}
        	else
        	{
        		printf("\n ***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... *****\n\n");
        	}
        	break;

		case 3:
        	if((!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) || flagBinario==1)
        	{
        		controller_listarJugadoresConDescripcion(listaJugadores, listaSelecciones);
        		controller_editarJugador(listaJugadores);
        		archivoEstado = 1;
        	}
        	else
        	{
        		printf("\n ***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
        	}
        	break;

		case 4:
        	if((!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) || flagBinario==1)
        	{
        		controller_listarJugadoresConDescripcion(listaJugadores, listaSelecciones);
        		controller_removerJugador(listaJugadores, listaSelecciones);
        		archivoEstado = 1;
        	}
        	else
        	{
        		printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
        	}
        	break;
		case 5:// LISTADOS
        	if((!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) || flagBinario==1)
        	{
        		controller_listar(listaJugadores, listaSelecciones);
        		archivoEstado = 1;
        	}
        	else
        	{
        		printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
        	}
        	break;
		case 6:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {
				controllerConvocarOQuitarDeSeleccion(listaJugadores, listaSelecciones);
				archivoEstado=1;
			} else {
			    		printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
			}
			break;
		case 7:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {
				controllerMenuListar(listaJugadores, listaSelecciones);
			} else {
			       		printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
			}
			break;
		case 8:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				controller_guardarJugadoresModoBinarioConDescripcion(
						"archivoJugadorBinario.bin", listaJugadores,
						listaSelecciones);
			} else {
				printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADOS ... \n\n");
			}
			break;
		case 9:
			if(!controller_cargarJugadoresDesdeBinario("archivoJugadorBinario.bin",listaJugadoresBin))
			{

				controller_listarJugadores(listaJugadoresBin);
			}
			else
				{
						printf("\n***** NO HAY JUGADORES PARA MOSTRAR ******\n");
				}

			break;
		case 10:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {
				controller_guardarJugadoresModoTexto("jugadores.csv",
						listaJugadores);
				controller_guardarSeleccionesModoTexto("selecciones.csv",
						listaSelecciones);
        		archivoEstado = 0;
			} else {
        		printf("\n***** ES NECESARIO QUE LOS ARCHIVOS ESTEN CARGADO PREVIAMENTE... \n\n");
			}
			break;
		case 11:
			if (archivoEstado == 1)
			{
						seguir = getCharOpc("\n*** Ocurrieron cambios que no fueron guardados, desea poder guardarlos? (S/N)",
								"\n*** La opcion ingresada no es valida, reintente: ");
						if(seguir=='S')
						{
							flagSalir=1;
						}

			} else {
				seguir = 'N';
				flagSalir = 1;
				ll_deleteLinkedList(listaSelecciones);
				ll_deleteLinkedList(listaJugadores);
				ll_deleteLinkedList(listaJugadoresBin);
				printf("\n****** Saliendo del programa ******\n");
			}
			break;
		}
		if (flagSalir == 0) {
			seguir = getCharOpc("\n ----> Desea continuar operando? (S/N): ",
					"\n ----> La opcion ingresada no es valida, reintente: ");
		}
		fflush(stdin);
	} while (seguir == 'S');

	return 0;
}
