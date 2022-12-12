
#ifndef PARSER_H_
#define PARSER_H_


/// @brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
///
/// @param pFile
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);


/// @brief Parsea los datos de los jugadores desde el archivo binario.
///
/// @param pFile
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/// @brief
///
/// @param pFile
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de selecciones
/// @return Retorna 0 si se realizó el parseo, 1 si no
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Parsea los datos de las selecciones desde el archivo selecciones.csv (modo texto).
///
/// @param pFile
/// @param pArrayListSeleccion Array de selecciones
/// @return Retorna 1
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

/// @brief
///
/// @param pFile
/// @param id
/// @return Retorna 1 si se logró el parseo, 0 si no
int parser_idFromText(FILE* pFile, char* id);

/// @brief
///
/// @param pFile
/// @param nacionalidades
void parser_NacionalidadesFromText(FILE* pFile , char* nacionalidades[]);

#endif /* PARSER_H_ */
