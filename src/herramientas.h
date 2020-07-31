/*
 * herramientas.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_



#endif /* HERRAMIENTAS_H_ */

/**
 * @brief  pide una cadena de caracteres por consola
 * @param  puntero donde se desea guardar la cadena
 * @param  entero indicando el tamaño del puntero a char anterior
 * @return Retorna (0) si se realizo con exito o -1 si no
 */
int getString(char* string, int lon);

/**
 * @brief  verifica si una cadena de caracteres es un entero
 * @param  cadena que se desea verificar
 * @param  tamaño de la cadena
 * @return retorna 1 si es un entero o retorna 0 si no lo es
 */
int isNumber(char* string, int limite);

/**
 * @brief  pide un numero por consola con un mensaje, mensaje de error, minimo, maximo y cantidad de intentos
 * @param  puntero a entero donde se guardara el numero pedido
 * @param  mensaje a enviar por consola para pedir el numero
 * @param  mensaje de error si se ingreso mal el numero
 * @param  numero minimo a ingresar
 * @param  numero maximo a ingresar
 * @param  cantidad maxima de reintentos
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,	int minimo, int maximo, int reintentos);

/**
 * @brief  verifica si la cadena ingresada es un nombre o no
 * @param  cadena que se desea verificar
 * @param  tamaño de la cadena a verificar
 * @return retorna 1 si es un nombre o 0 si no lo es
 */
int esNombre(char *string, int longitud);

/**
 * @brief  pide un nombre por consola enviando un mensaje, mensaje de error y con una cantidad de reintentos
 * @param  puntero a cadena donde sera guardado el nombre
 * @param  entero tamaño de la cadena
 * @param  mensaje a enviar para solicitar el nombre
 * @param  mensaje de error al ingresar mal el nombre
 * @param  cantidad de intentos maxima
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

//void pedirFecha(eFecha fechas[]);

/**
 * @brief  solicita un entero a travez de un mensaje y lo valida entre un maximo y un minimo ingresado
 * @param  entero maximo a ingresar
 * @param  entero minimo a ingresar
 * @param  mensaje a enviar para solicitar el numero
 * @param  mensaje de error en caso de que sea ingresado mal el entero
 * @return retorna el entero ingresado por el usuario ya validado
 */
int validarOpcion(int max, int min,char mensaje[], char mensajeError[]);

/**
 * @brief  se le pasa una cadena y se devuelve con la primer inicial mayuscula y las demas minusculas
 * @param  cadena que se desea formatear
 * @param  tamaño de la cadena
 */
void tipoNombre(char vec[], int tam);

/**
 * @brief  obtiene una cadena de caracteres
 * @param  cadena donde se desea guardar
 * @param  tamaño de la cadena a ingresar
 */
void getStr(char cadena[], int tam);

/**
 * @brief  solicita al usuario caracteres de confirmacion (s / n) mayusc o minusc y los valida
 * @param  puntero a caracter donde sera guardada la confirmacion
 */
void getCharConfirmValidado(char* caracter);

/**
 * @brief  muestra un menu de opciones y retorna la opcion ingresada por el usuario
 * @return retorna el caracter ingresado por el usuario
 */
char menuOpciones();

/**
 * @brief  guarda en un archivo CSV una linkedlist formato texto
 * @param  lista que se guardara en el archivo CSV
 * @param  nombre del archivo CSV donde se guardara la lista
 * @return retorna 1 si hubo un error o 0 si se realizo con exito
 */
int guardarCSV(LinkedList *lista, char *path);
