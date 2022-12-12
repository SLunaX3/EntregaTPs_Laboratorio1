/*
 * Confederaciones.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef CONFED_H_
#define CONFED_H_

#define TAM_CONF 6


typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;

/// @brief Busca confederacion por su id
///
/// @param vec Array de confederaciones
/// @param id Id de la confederacion
/// @param pIndex Indice de la confederacion
/// @return 1 si logró la operacion, 0 si no
int searchConfed(eConfederacion vec[], int id, int* pIndex);

/// @brief Muestra los datos de una condeferacion
///
/// @param confederacion Confederacion a mostrar
void confed_showConfederation(eConfederacion confederacion);

/// @brief Lista las confederaciones
///
/// @param confederaciones Array de confederaciones
/// @return 1 si logró la operacion, 0 si no
int confed_listConfederations(eConfederacion confederaciones[]);

/// @brief
///
/// @param confederaciones Array de confederaciones
/// @param idConfederacion
/// @param nombreCondfed
/// @return 1 si logró la operacion, 0 si no
int confed_loadConfederation(eConfederacion confederaciones[], int idConfederacion , char nombreCondfed[]);

/// @brief Menú ABM de confederaciones
///
/// @return opcion elegida
int menuConfed();

/// @brief Menú modifciacion de confederaciones
///
/// @return opcion elegida
int menu_menuModifyConfed();

/// @brief Verifica si hay lugar para un ingreso/un alta en el array recibido por parámetro
///
/// @param vec Array de confederaciones
/// @param pIndex Posicion en le array
/// @return 1 si se logró la operación, 0 si no
int buscarFreeConfed(eConfederacion vec[], int* pIndex);

/// @brief Ingresa una confederacion a la lista de confederaciones, con todos los datos ingresados por el usuario
///
/// @param vec Array de confederaciones
/// @param pNextConf Proximo id a asignar
/// @param contConf cantidad de confederaciones ingresadas
/// @return 1 si se logró la operación, 0 si no
int confed_addCondef(eConfederacion vec[], int* pNextConf, int* contConf);

/// @brief Modifica datos de la confederacion
///
/// @param vec Array de confederaciones
/// @return 1 si se logró la operación, 0 si no
int confed_modifyConfed(eConfederacion vec[]);

/// @brief Borra una confederacion de la lista
///
/// @param vec Array de confederaciones
/// @param contConf
/// @return 1 si se logró la operación, 0 si no
int confed_eraseConfed(eConfederacion vec[],int* contConf);

#endif /* CONFED_H_ */
