
#ifndef VALIDS_H_
#define VALIDS_H_



int esNumero(char* cadena);

int convertirCharAInt(char num[], int* pNumero);

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
/// @param mensaje Mensaje para solicitar ingreso de datos
/// @param mensajeERROR Mensaje para informar que hubo un Error al ingresar datos
/// @param cadena Variable de retorno por referencia
/// @param tam Cantidad de caracteres permitidos
void getValidStringRango(char* mensaje,char* mensajeERROR, char cadena[], int tam);

int pidoValidoNumero(int* pNumero, char* mensaje);

int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo);

void pidoNombreCompleto(char nombreCompleto[]);

int esFlotante(char* flotante,int tam);

float gets_getNumerFloat(char* mensaje, char* mensajeError, float minimo, float maximo);

int convertirCharAFloat(char flotante[], float* pFloat);

char getCharOpc(char* mensaje, char* mensajeError);


#endif /* VALIDS_H_ */
