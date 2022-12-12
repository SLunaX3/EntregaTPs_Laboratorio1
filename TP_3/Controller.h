#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/// @brief Menú principal
///
/// @return opcion elegida
int menu();


/// @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
///
/// @param path Archivo a utilizar
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
///
/// @param path Archivo a utilizar
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Carga un archivo de texto id (para autoincremental y persistencia del id
///
/// @param path Archivo a utilizar
/// @param id Ultimo id ingresado
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_cargarIdJugadorModoTexto(char* path, char* id);


/// @brief Alta de jugador
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// @brief Modifica datos de jugador
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_editarJugador(LinkedList* pArrayListJugador);

/// @brief Baja de jugador
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Seleccioneses
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones);

/// @brief Lista los jugadores
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_listarJugadores(LinkedList* pArrayListJugador);

//int controller_listarJugadoresPorSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,int criterio);//mia

/// @brief Menú de Ordenamiento
///
/// @return opcion elegida
int controller_menuListar();

/// @brief Muestra los listados
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
void controller_listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Lista los jugadores convocados
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Lista los jugadores noconvocados
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Printeo de cabecera para listar y ordenar
///
void controller_cabeceraParaListarYOrdenar();

/// @brief Lista jugadores
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_listarJugadoresConDescripcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Genera y guarda lista de jugadores en modo binario bajo un criterio
///
/// @param path Archivo a utilizar
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_guardarJugadoresModoBinarioConDescripcion(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Ordena jugadores o confedraciones según criterio
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no,
/// por no poder modificar el prototipo se utiliza el retorno 2 para acceder al ordenamiento correspondiente
int controller_ordenarJugadores(LinkedList* pArrayListJugador);


/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
///
/// @param path Archivo a utilizar
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);


/// @brief Guarda los datos de los jugadores en el archivo binario.
///
/// @param path Archivo a utilizar
/// @param pArrayListJugador Array de jugadores
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);


/// @brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
///
/// @param path Archivo a utilizar
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_guardarSeleccionesModoTexto(char *path, LinkedList *pArrayListSeleccion);

/// @brief Guarda id en un archivo de texto
///
/// @param path Archivo a utilizar
/// @param id Id a guardar
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_guardarIdJugadorModoTexto(char* path, char* id);

/// @brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
///
/// @param path Archivo a utilizar
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// @brief Lista las selecciones
///
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Ordena lista de selecciones alfabeticamente ascendentemente
///
/// @param pArrayListSeleccion Array de Selecciones
/// @return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Menú de Posiciones
///
void controller_printMenuPosiciones();

/// @brief Menú de confederaciones
///
void controller_printMenuConfederaciones();

/// @brief Menú de modificaciones
///
/// @return opcion elegida
int menuModificaciones();

/// @brief Modifica datos de jugador
///
/// @param opcion Opcion de dato a modificar
/// @param bufferNombre Buffer del nombre a modificar
/// @param bufferEdad Buffer de la edad a modificar
/// @param bufferNacionalidad Buffer de la nacionalidad a modificar
/// @param bufferPosicion Buffer de la posicion a modificar
/// @param this El jugador al que se esta modificando
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int operarMenuModificar (int opcion, char* bufferNombre, int* bufferEdad ,char* bufferNacionalidad, char* bufferPosicion, Jugador* this);

/// @brief Convoca un jugador
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no, -1 si no hay cupo enla seleccion o el id nocoincide con un jugador noconvocado
int controller_convocarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// @brief Genera y carga lista de no convocados
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna dicha lista
LinkedList* controller_cargarListaJugadoresNoConvocados(LinkedList* pArrayListJugador);

/// @brief Genera y carga lista de convocados
///
/// @param pArrayListJugador Array de jugadores
/// @return Retorna dicha lista
LinkedList* controller_cargarListaJugadoresConvocados(LinkedList* pArrayListJugador);

/// @brief Valida id de jugador
///
/// @param pArrayListJugador Array de jugadores
/// @param idIngresada la id del jugador
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int validarIdJugador(LinkedList* pArrayListJugador,int idIngresada);

/// @brief Obtiene la direccion de memoria del jugador con ese id
///
/// @param pArrayListJugador Array de jugadores
/// @param idIngresada Id recibida pro parametro que se va a buscar
/// @param jugador La entidad encontrada con la coincidencia
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no
int traerJugadorPorId(LinkedList* pArrayListJugador,int idIngresada, Jugador* jugador);

/// @brief Recibe dos elementos y compara los valores de los campos edad de los jugadores
///
/// @param this Primer elemento
/// @param thisTwo Segundo elemento
/// @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales, -1 si el primero es menor que el segundo
int criterioEdad(void* this, void* thisTwo);

/// @brief Quita jugador de seleccion
///
/// @param pArrayListJugador Array de jugadores
/// @param pArrayListSeleccion Array de Selecciones
/// @return Retorna 1 si se logró la operación de la funcion, 0 si no, -1 si no se encuentra en la lista de jugadores convocados
int controller_quitarDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Convoca o quita jugador de la seleccion
///
/// @param listaJugadores Array de jugadores
/// @param listaSelecciones Array de selecciones
void controllerConvocarOQuitarDeSeleccion(LinkedList* listaJugadores,LinkedList* listaSelecciones);

/// @brief Recibe la opcion que corresponde a una confederacion y desvuelve por parametro su string correspondiente
///
/// @param opcion Opcion de confederacion elegida
/// @param auxConfederation Retorno de string
/// @return Retorna 1 si se logró la operacion de la funcion, 0 si no
int controller_selectPlayerConfederation(int opcion,char auxConfederation[]);


/// @brief ordena y lista jugadores y confederaciones
///
/// @param listaJugadores Array de jugadores
/// @param listaSelecciones Array de selcciones
void controllerMenuListar(LinkedList* listaJugadores,LinkedList* listaSelecciones);

