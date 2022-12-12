/*
 * functions.h
 *
 *      Author: Luna, Sonia
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/// @fn int functions_menu(float, float, float, int, int, int, int, char*, char*, int, int)
/// @brief Muestra las opciones del menú principal.
///
/// @param transporte El monto ingresado de transporte
/// @param hospedaje El monto ingresado de hospedaje
/// @param comida El monto ingresado de la comida
/// @param contArqueros La cantidad de arqueros ingresados
/// @param contDefensores La cantidad de defensores ingresados
/// @param contMediocampos La cantidad de mediocampistas ingresados
/// @param contDelanteros La cantidad de delanteros ingresados
/// @param mensaje Para pedirle al usuario que ingrese un número corespondiente las opciónes del menú
/// @param mensajeError Para avisar que el ingreso es erroneo
/// @param minimo El valor mínimo requerido para que se valide el ingreso
/// @param maximo El valor máximo permitido para que se valide el ingreso
/// @return Retorna el número ingresa, correspondiente a una de las opciones del menú
int functions_menu(float transporte, float hospedaje, float comida, int contArqueros, int contDefensores, int contMediocampos, int contDelanteros, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @fn void functions_setCosts(float*, float*, float*)
/// @brief Carga los montos de costo de hospedaje, comida y transporte.
/// Muestra un submenú de opciones, cada opción corresponde a cada costo,
/// para elegir uno y permitir el ingreso de los montos.
/// Los valores del ingreso de los montos salen por referencia como parámetro para ser utilizados en otras funciones y como validaciones en el main.
///
/// @param pTransporte El ingreso del monto de transporte
/// @param pHospedaje El ingreso del monto de hospedaje
/// @param pComida El ingreso del monto de comida
void functions_setCosts(float* pTransporte, float* pHospedaje, float* pComida);

/// @fn int functions_setPositions(int*, int, int*, int, int*, int, int*, int)
/// @brief Carga las posiciones de los jugadores.
/// Muestra un submenú de opciones, cada opción corresponde a una posición de equipo en el campo,
/// para elegir uno y permitir el ingreso de jugadores por posición.
/// Cada posición tiene un contador para poder usarlos esos como validación de ingresos maximos por posición,
/// esos máximos se reciben por parámetro, están incializados en el main.
/// También, los valores de los contadores salen por referencia como parámetro para ser utilizados en otras funciones.
///
/// @param pArqueros La cantidad de arqueros ingresados
/// @param maxArqueros La cantidad máxima permita de ingreso de arqueros
/// @param pDefensores La cantidad de defensores ingresados
/// @param maxDefensores La cantidad máxima permita de ingreso de defensores
/// @param pMediocampos La cantidad de mediocampistas ingresados
/// @param maxMediocampos La cantidad máxima permita de ingreso de mediocampistas
/// @param pDelanteros La cantidad de delanteros ingresados
/// @param maxDelanteros La cantidad máxima permita de ingreso de delanteros
/// @return
int functions_setPositions(int* pArqueros, int maxArqueros, int* pDefensores, int maxDefensores, int* pMediocampos, int maxMediocampos, int* pDelanteros, int maxDelanteros);

/// @fn void functions_setConfederation(int, int*, int*, int*, int*, int*, int*)
/// @brief Muestra un submenú de opciones, cada opción corresponde a una confederación,
/// para elegir uno y permitir el ingreso de jugadores por confederación.
/// Cada confederación tiene un contador para que sus valores puedan ser utilizados en otras fucniones al salir por referencia como parámetros.
///
/// @param numCamiseta El número de camisa que se le pide al usuario, en el main, que ingrese antes de asignar una confederación
/// @param pAFC La cantidad de jugadores ingresados de la AFC
/// @param pCAF La cantidad de jugadores ingresados de la CAF
/// @param pCONCACAF La cantidad de jugadores ingresados de la CONCACAF
/// @param pCONMEBOL La cantidad de jugadores ingresados de la CONMEBOL
/// @param pUEFA La cantidad de jugadores ingresados de la UEFA
/// @param pOFC La cantidad de jugadores ingresados de la OFC
void functions_setConfederation(int numCamiseta, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);

/// @fn void functions_showResults(float, float, float, float, float, float, float, float, float)
/// @brief Muestra el informe de los resultados de los cálculso realizados.
///
/// @param promAFC El número promedio de jugadores de la AFC
/// @param promCAF El número promedio de jugadores de la CAF
/// @param promCONCACAF El número promedio de jugadores de la CONCACAF
/// @param promCONMEBOL El número promedio de jugadores de la CONMEBOL
/// @param promUEFA El número promedio de jugadores de la UEFA
/// @param promOFC El número promedio de jugadores de la OFC
/// @param gastos El monto de los gastos de mantenimiento
/// @param aumEuropa El monto del aumento si la mayoría del plantel son de la UEFA
/// @param mantenimiento El monto total de los gastos de mantenimiento, tiene incluido el aumento.
void functions_showResults(float promAFC, float promCAF, float promCONCACAF, float promCONMEBOL, float promUEFA, float promOFC, float gastos, float aumEuropa, float mantenimiento);


#endif /* FUNCTIONS_H_*/
