/*
 * getters.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#ifndef GETTERS_H_
#define GETTERS_H_



#endif /* GETTERS_H_ */

/**
 * @brief  obtiene el id de una estructura pasada
 * @param  estructura de la que se desea obtener el id
 * @param  puntero a id donde se desea guardar el id
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int Object_getID(ePais *this, int *id);

/**
 * @brief  obtiene el nombre de una estructura pasada
 * @param  estructura de la que se desea obtener el nombre
 * @param  puntero a nombre donde se va a guardar
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int Object_getPais(ePais *this, char* pais);

/**
 * @brief  obtiene el numero de muertos de una estructura pasada
 * @param  estructura de la que se desea obtener el numero de muertos
 * @param  puntero a entero donde se desea guardar el numero
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int Object_getMuertos(ePais *this, int *muert);

/**
 * @brief  obtiene el numero de infectados de una estructura pasada
 * @param  estructura de la que se desea obtener el numero
 * @param  puntero a entero donde se desea guardar el numero
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int Object_getInfectados(ePais *this, int *infec);

/**
 * @brief  obtiene el numero de recuperados de una estructura pasada
 * @param  estructura de la que se desea obtener el numero
 * @param  puntero a entero donde se desea guardar el numero
 * @return Retorna (1) si se realizo con exito o 0 si no
 */
int Object_getRecuperados(ePais *this, int *recu);

