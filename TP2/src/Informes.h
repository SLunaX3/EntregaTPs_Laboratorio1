/*
 * Informes.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Jugadores.h"
#include "Gets.h"
#include "Sets.h"
#include "Menu.h"

/// @brief Ordena jugadores alfabéticamente por nombre de confederación y nombre de jugador
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @return 1 si logró la operacion, 0 si no
int informes_sortPlayersByConfederationAndName(eJugador vec[], eConfederacion confederaciones[]);

/// @brief Ordena jugadores por id, Ascendentemente
///
/// @param vec Array de jugadores
/// @return
int informes_sortPlayersByID(eJugador vec[]);

/// @brief
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param idConfederacion
/// @return
int informes_playersByConfederation(eJugador vec[], eConfederacion confederaciones[], int idConfederacion);

/// @brief Lista confederaciones con sus jugadores
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
void informes_showPlayersByConfederation(eJugador vec[], eConfederacion confederaciones[]);

/// @brief Informa el total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.
///
/// @param vec Array de jugadores
/// @param contJugadores
/// @return 1 si logró la operacion, 0 si no
int informes_reportSalaries(eJugador vec[], int contJugadores);

/// @brief Acumula/suma todos los montos de salarios de los jugadores
///
/// @param vec Array de jugadores
/// @return Retorna el resultado de la acumulacion
float informes_accumulateSalary(eJugador vec[]);

/// @brief Cuenta la cantidad de salarios por arriba del promedio
///
/// @param vec Array de jugadores
/// @param promedio Valor recibido por parámetro
/// @return Cantidad de sueldos por arribadel promedio
int informes_bestSalaries(eJugador vec[], float promedio);

/// @brief Busca la confederacion con más anios de contarto
///
/// @param confederaciones Array de confederaciones
/// @param aniosContrato
/// @param pNombreConf
/// @return Retorna indice de la confederacion conmás anios de contrato
int confed_confedMayorAniosContrato(eConfederacion confederaciones[], short aniosContrato[], char pNombreConf[]);

/// @brief Acumula anios de contrato por confederacion
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param aniosContrato Array de anios de contrato por cada confedracion
/// @return 1 si logró la operacion, 0 si no
int confed_accumulateYearsContract(eJugador vec[], eConfederacion confederaciones[], short aniosContrato[]);

/// @brief Informa la confederación con mayor cantidad de anios de contratos total
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @return 1 si logró la operacion, 0 si no
int informes_confederacionConMasAnios(eJugador vec[], eConfederacion confederaciones[]);

/// @brief Informa porcentaje de jugadores por cada confederación
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param contJugadores
void confedPorcentajeJugadores(eJugador vec[], eConfederacion confederaciones[], int contJugadores);

/// @brief Cuenta la cantidad de jugadores por confederacion/region
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param aContJug Cantidad de jugadores ingresados
/// @return 1 si logró la operacion, 0 si no
int informes_countPlayersPerRegion(eJugador vec[], eConfederacion confederaciones[], int aContJug[]);

/// @brief Evalua las cantidades de jugadores de las regiones
///
/// @param aContJug Cantidad de jugadores ingresados
/// @return Retorna la mayor cantidad de jugadores por region en el array
int informes_regionMostPlayers(int aContJug[]);

/// @brief Informa cual es la región con más jugadores y el listado de los mismos
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param mayorCantRegion
/// @param aContJug Cantidad de jugadores ingreesados
/// @return 1 si logró la operacion, 0 si no
int informes_showRegionMostPlayers(eJugador vec[], eConfederacion confederaciones[], int  mayorCantRegion, int aContJug[]);

#endif /* INFORMES_H_ */
