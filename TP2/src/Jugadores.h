/*
 * Jugadores.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "Confed.h"
#include "Gets.h"
#include "Sets.h"


#define TAM_JUG 3000
#define TAM_NOMBRE 50

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamisa;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;

/// @brief Inicializa los campos isEmpty
///
/// @param vec Array de jugadores
/// @return 1 si se logró la operación, 0 si no
int inicializarJugador(eJugador vec[]);

/// @brief Verifica si hay lugar para un ingreso/un alta en el array recibido por parámetro
///
/// @param vec Array de jugadores
/// @param pIndex Posición en el array
/// @return 1 si se logró la operación, 0 si no
int buscarFree(eJugador vec[], int* pIndex);

/// @brief Ingresa un jugador a lista de jugadores, con todos los datos ingresados por el usaurio
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param pNextJugador Proximo id a asignar
/// @param contJugadores Cantidad de jugadores ingresados
/// @return 1 si se logró la operación, 0 si no
int jugadores_addPlayer(eJugador vec[], eConfederacion confederaciones[], int* pNextJugador, int* contJugadores);

/// @brief Imprime los datos de un jugador
///
/// @param unJugador El jugador a mostrar
/// @param confederaciones Array de confederaciones
/// @return 1 si se logró la operación, 0 si no
int jugadores_showPlayer(eJugador unJugador, eConfederacion confederaciones[]);

/// @brief Lista los jugadores
///
/// @param vec Array de jugadores
/// @param confedereaciones Array de confederaciones
/// @return 1 si se logró la operación, 0 si no
int jugadores_listPlayers(eJugador vec[],  eConfederacion confedereaciones[]);

///// @brief Carga la lista de jugadores
/////
///// @param vec Array de jugadores
///// @param pNextId Proximo id a asignar
///// @param cantAharcodear La cantidad de jugadores a cargar
///// @param pcontJugadores Cantidad de jugadores ingresados
///// @return 1 si se logró la operación, 0 si no
int jugadores_hardcodePlayers(eJugador vec[], int* pNextId, int cantAharcodear, int* pcontJugadores);

/// @brief Busca un jugador por su id
///
/// @param vec Array de jugadores
/// @param id Id del jugador
/// @param pIndex Indice del jugador
/// @return 1 si se logró la operación, 0 si no
int jugadores_searchPlayerId(eJugador vec[], int id, int* pIndex);

/// @brief Modifica datos de un jugador
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @return 1 si se logró la modificación, 0 si no
int jugadores_modifyPlayers(eJugador vec[],  eConfederacion confederaciones[]);

/// @brief Borra un jugador de la lista
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param pcontJugadores
/// @return 1 si se logró el borrado, 0 si no
int jugadores_erasePlayer(eJugador vec[], eConfederacion confederaciones[], int* pcontJugadores);

/// @brief Recorre ambos array, acumulando jugadores por cada confederacion en un array
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param jugadoresConfed Array de contadores de jugadores en cada confederacion
void cantidadDeJugadoresPorConfederacion(eJugador vec[], eConfederacion confederaciones[], int jugadoresConfed[]);

#endif /* JUGADORES_H_ */
