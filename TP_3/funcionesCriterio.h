
#ifndef FUNCIONESCRITERIO_H_
#define FUNCIONESCRITERIO_H_

/// @brief Recibe dos elementos y compara los campos confederacion de entidad seleccion
///
/// @param A Primer elemento
/// @param B Segundo elemento
/// @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales, -1 si el primero es menor que el segundo
int funcionesCriterio_Confederation(void* A, void* B);

/// @brief Recibe dos elementos y compara los campos nombre de entidad jugador
///
/// @param A Primer elemento
/// @param B Segundo elemento
/// @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales, -1 si el primero es menor que el segundo
int funcionesCriterio_name(void* A, void* B);

/// @brief Recibe dos elementos y compara los campos edad de entidad jugador
///
/// @param A Primer elemento
/// @param B Segundo elemento
/// @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales, -1 si el primero es menor que el segundo
int funcionesCriterio_Age(void* A, void* B);

/// @brief Recibe dos elementos y compara los campos nacionalidad de entidad jugador
///
/// @param A Primer elemento
/// @param B Segundo elemento
/// @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales, -1 si el primero es menor que el segundo
int funcionesCriterio_nationality(void* A, void* B);

/// @brief Filtra linkedlist
///
/// @param this Un puntero a linkedlist, lista a filtrar
/// @param pFunc Un puntero a funcion de filtrado
/// @return Retorna un puntero a linkedlist
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));

#endif /* FUNCIONESCRITERIO_H_ */
