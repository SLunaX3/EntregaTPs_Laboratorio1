/*
 * getsYcalculos.h
 *
 *      Author: Luna, Sonia
 */

#ifndef GETSYCALCULOS_H_
#define GETSYCALCULOS_H_

/// @fn int getsYcalculos_getNumerInt(char*, char*, int, int)
/// @brief Permite y valida el ingreso de n�meros enteros.
/// Los mensajes se piden por referencia, est�n inicializados en el main.
///
/// @param mensaje Para pedirle al usuario que ingrese un n�mero
/// @param mensajeError Para avisar que es un ingreso erroneo
/// @param minimo El valor m�nimo requerido para que se valide el ingreso
/// @param maximo El valor m�ximo permitido para que se valide el ingreso
/// @return Retorna el n�mero ingresado ya validado
int getsYcalculos_getNumerInt(char* mensaje, char* mensajeError, int minimo, int maximo);

/// @fn float getsYcalculos_getNumerFloat(char*, char*, int)
/// @brief Permite y valida el ingreso de n�meros con decimales.
/// Los mensajes se piden por referencia, est�n inicializados en el main.
///
/// @param mensaje Para pedile al usuario que ingrese un n�mero
/// @param mensajeError Para avisar que es un ingreso erroneo
/// @param minimo El valor m�nimo requerido para que se valide el ingreso
/// @param maximo El valor m�ximo permitido para que se valide el ingreso
/// @return Retorna el n�mero ingresado ya validado
float getsYcalculos_getNumerFloat(char* mensaje, char* mensajeError, int minimo);

/// @fn float getsYcalculos_average(int, int)
/// @brief Divide dos n�meros que recibe por par�metro.
/// Esta funci�n se cre� para realizar promedios.
///
/// @param cantidad La cantidad de jugadores de cada confederaci�n
/// @param cantTotal La cantidad de jugadores ingresados
/// @return Retorna el resultado de la operaci�n de esta funci�n (promedio)
float getsYcalculos_average (int cantidad, int cantTotal);

/// @fn void getsYcalculos_averageConfedPlayers(int*, int, int, int, int, int, int, float*, float*, float*, float*, float*, float*)
/// @brief Calcula los promedios de jugadores de cada confederaci�n.
/// El resultado del calculo de la cantidad de jugadores y los promedios salen por referencia como par�metro para utilizarlos sus valores en otra funci�n.
///
/// @param pCantJug La cantidad de jugadores ingresados
/// @param AFC La cantidad de jugadores ingresados de AFC
/// @param CAF La cantidad de jugadores ingresados de CAF
/// @param CONCACAF La cantidad de jugadores ingresados de CONCACAF
/// @param CONMEBOL La cantidad de jugadores ingresados de CONMEBOL
/// @param UEFA La cantidad de jugadores ingresados de UEFA
/// @param OFC La cantidad de jugadores ingresados de OFC
/// @param pPromAFC El promedio de jugadores ingresados de AFC
/// @param pPromCAF El promedio de jugadores ingresados de CAF
/// @param pPromCONCACAF El promedio de jugadores ingresados de CONCACAF
/// @param pPromCONMEBOL El promedio de jugadores ingresados de CONMEBOL
/// @param pPromUEFA El promedio de jugadores ingresados de UEFA
/// @param pPromOFC El promedio de jugadores ingresados de OFC
void getsYcalculos_averageConfedPlayers (int* pCantJug, int AFC, int CAF, int CONCACAF, int CONMEBOL, int UEFA, int OFC, float* pPromAFC, float* pPromCAF, float* pPromCONCACAF, float* pPromCONMEBOL, float* pPromUEFA, float* pPromOFC);

/// @fn float getsYcalculos_calculateExpenses(float*, int, float*, float, float, float, int, int)
/// @brief Calcula todos los gastos de mantenimiento.
/// El resultado del calculo de los gastos y el monto del aumento salen por referencia como par�metro para poder utilizarlos en una funci�n de printeo.
///
/// @param pGastos El resultado de la suma de los costos de hospedaje, comida y transporte
/// @param aumento El numero del porcentaje del respectivo aumento
/// @param pAumEuropa El monto del aumento, resultado
/// @param hospedaje El monto ingresado del hospedaje
/// @param comida El monto ingresado de la comida
/// @param transporte El monto ingresado del transporte
/// @param cantJug La cantidad de jugadores ingresados
/// @param UEFA La cantidad de jugadores ingresados de la UEFA
/// @return Retorna el resultado de los gastos de mantenimiento calculados en la funci�n
float getsYcalculos_calculateExpenses (float* pGastos , int aumento, float* pAumEuropa, float hospedaje, float comida, float transporte, int cantJug, int UEFA);


#endif /* GETSYCALCULOS_H_ */
