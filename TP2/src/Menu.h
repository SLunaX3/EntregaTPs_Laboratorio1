/*
 * Menu.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef MENU_H_
#define MENU_H_

#include "Informes.h"

/// @brief Menú ABM jugadores
///
/// @return opcion elegida
int menu_menu();

/// @brief Menú de informes
///
/// @return opcion elegida
int menu_reportsMenuOptions();

/// @brief Informes
///
/// @param vec Array de jugadores
/// @param confederaciones Array de confederaciones
/// @param contJugadores Contador de jugadores
void menu_reportsMenu( eJugador vec[],  eConfederacion confederaciones[], int contJugadores);

/// @brief Menú para la modificacion de jugadores
///
/// @return opcion elegida
int menu_menuModify();

#endif /* MENU_H_ */
