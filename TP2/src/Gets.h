/*
 * Gets.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef GETS_H_
#define GETS_H_



/// @brief Verifica si la cadena ingresada es numerica
///
/// @param cadena Cadena de caracteres a ser analizada
/// @param len Tamaño de la cadena a analizar
/// @return Retorna 1 si es numerica, 0 sino no lo es
int esNumero(char* cadena);

/// @brief Convierte una cadena char a int
///
/// @param num Int obtenido
/// @param pNumero Cadena a convertir
/// @return 1 si se logró la operacion, 0 si no
int convertirCharAInt(char num[], int* pNumero);

/// @brief Pide y valida que sea int
///
/// @param mensaje Mensaje de pedido
/// @param mensajeError Mensaje de error
/// @param minimo Minimo del rango
/// @param maximo Maximo del rango
/// @return
int gets_getNumerInt(char* mensaje, char* mensajeError, int minimo, int maximo);


/// @brief Verifica si el valor recibido contiene solo letras
///
/// @param cadena Cadena a ser analizada
/// @return Retorna 1 si pasa las validaciones, sino 0
int esSoloLetras(char* cadena);

/// @brief Cambia las primeras letras de una cadena de caracteres a mayusculas
///
/// @param cadena Cadena a modificar
void corregirMayusculas(char cadena[]);

/// @brief Toma una cadena
///
/// @param mensaje Mensaje para solicitar ingreso de datos
/// @param input Cadena a tomar
void getString(char mensaje[],char input[]);

/// @brief Obtiene una cadena de caracteres
///
/// @param mensaje Mensaje para solicitar ingreso de datos
/// @param cadena Variable de retorno por referencia
/// @param tam Cantidad de caracteres permitidos
/// @return 1 si pasa las validaciones, sino 0
int getStringLetrasRango(char* mensaje,char cadena[], int tam);

/// @brief Obtiene y valida una cadena de caracteres
///
/// @param mensaje Palabra/s para solicitar el ingreso de datos
/// @param mensajeERROR Mensaje para informar que hubo un Error al ingresar datos
/// @param cadena Variable de retorno por referencia
/// @param tam Cantidad de caracteres permitidos
void getValidStringRango(char* mensaje,char* mensajeERROR, char cadena[], int tam);

/// @brief Verifica si el valor recibido sea solo flotante
///
/// @param flotante El dato a verificar
/// @param tam Tamaño del dato a verificar
/// @return Retorno 1 si es flotante, 0 si no lo es
int esFlotante(char* flotante,int tam);

/// @brief Pide y valida que sea float
///
/// @param mensaje Mensaje de pedido de datos
/// @param mensajeError Mensaje de error
/// @param minimo Minimo del rango
/// @param maximo Maximo del rango
/// @return
float gets_getNumerFloat(char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Convierte una cadena char a float
///
/// @param flotante Float obtenido
/// @param pFloat Cadena a convertir
/// @return 1 si se logró la operacion, 0 si no
int convertirCharAFloat(char flotante[], float* pFloat);

/// @brief Pide y valida que sea short
///
/// @param mensaje Mensaje de pedido de datos
/// @param mensajeError Mensaje de error
/// @param minimo Minimo del rango
/// @param maximo Maximo del rango
short gets_getNumerShort(char* mensaje, char* mensajeError, short minimo, short maximo);

#endif /* GETS_H_ */
