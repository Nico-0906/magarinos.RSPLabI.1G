/*
 * controller.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */
#include "pais.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/**
 * @brief  carga lo que hay en un texto a una linkedlist
 * @param  archivo que se desea cargar
 * @param  linkedlist donde se desea cargar el archivo
 * @return Retorna (1) si el puntero es NULL o 0 si se completo con exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

**/

/**
 * @brief  muestra un pais y su informacion
 * @param  estructura de pandemia que se desea mostrar
 */
void pais_show(ePais* this);

/**
 * @brief  muestra una linkedlist completa
 * @param  linkedlist que se desea mostrar
 * @return retorna 1 si no se pudo cargar o 0 si se realizo con exito
 */
int controller_ListPandemia(LinkedList* pArrayListEmployee);

/**
 * @brief  verifica los paises con menos de 5000 muertos
 * @param  estructura donde se debe analizar cantidad de muertos
 * @return retorna 1 si el pais tiene menos de 5000 muertos o 0 sino
 */
int controller_paisesExitosos(ePais* paises);

/**
 * @brief  verifica los paises con el triple de infectados que de recuperados
 * @param  estructura donde se debe analizar cantidad de infectados y recuperados
 * @return retorna 1 si el pais tiene el triple de infectados que de recuperados o 0 sino
 */
int controller_paisesEnElHorno(ePais* paises);

/**
 * @brief  compara la cantidad de infectados dos paises
 * @param  estructura donde se debe analizar cantidad de infectados
 * @param  estructura donde se debe analizar cantidad de infectados
 * @return retorna 1 si el primero tiene mas cantidad de infectados q el segundo o 0 sino
 */
int filtInfec(ePais* this, ePais* thistwo);

/**
 * @brief	asigna aleatoriamente los valores a la estructura pais
 * @param	estructura a la que se quiere asignar los valores
 * @return retorna una estructura pais con los valores asignados
 */
ePais* controller_asignarValores(ePais* this);

/**
 * @brief  verifica la mayor cantidad de muertos en los paises del linkedlist
 * @param  linkedlist a verificar cantidad de muertos mayor
 * @return retorna la mayor cantidad de muertos del linkedlist
 */
int controller_mayorNumeroMuertos(LinkedList* this);

/**
 * @brief  verifica la cantidad de muertos del linkedlist genera una lista nueva con los que tienen el mayor numero
 * @param  estructura donde se debe analizar cantidad de muertos
 * @param  cantidad de muertos a nalizar
 * @return retorna el linkedlist con la cantidad de muertos igual o mayor al ingresado
 */
LinkedList* controller_paisesMayorMuertos(LinkedList* this, int mayor);
