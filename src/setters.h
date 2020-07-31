/*
 * setters.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#ifndef SETTERS_H_
#define SETTERS_H_



#endif /* SETTERS_H_ */

/**
 * @brief  setea un nuevo id en la estructura
 * @param  this estructura donde se seteara el nuevo id
 * @param  id nuevo a setear
 * @return retorna 1 si se realizo con exito o 0 si hubo algun error
 */
int Object_setID(ePais *this, int id);

/**
 * @brief  setea un nuevo nombre en la estructura
 * @param  this estructura donde se seteara el nuevo nombre
 * @param  nombre nuevo a setear
 * @return retorna 1 si se realizo con exito o 0 si hubo algun error
 */
int Object_setNombre(ePais *this, char * nombre);

/**
 * @brief  setea un nuevo numero de recuperados en la estructura
 * @param  this estructura donde se seteara el nuevo numero de recuperados
 * @param  numero de recuperados nuevo a setear
 * @return retorna 1 si se realizo con exito o 0 si hubo algun error
 */
int Object_setRecuperados(ePais *this, int recuperados);

/**
 * @brief  setea un nuevo numero de infectados en la estructura
 * @param  this estructura donde se seteara el nuevo numero de infectados
 * @param  numero de infectados nuevo a setear
 * @return retorna 1 si se realizo con exito o 0 si hubo algun error
 */
int Object_setInfectados(ePais *this,int infectados);

/**
 * @brief  setea un nuevo numero de muertos en la estructura
 * @param  this estructura donde se seteara el nuevo numero de muertos
 * @param  numero de muertos nuevo a setear
 * @return retorna 1 si se realizo con exito o 0 si hubo algun error
 */
int Object_setMuertos(ePais *this, int muertos);

/**
 * @brief setea toda la informacion ingresada por parametros en la estructura ePais ingresada
 * @param this estructura a setear
 * @param id que se le seteara a la estructura
 * @param nombre a setear a la estructura
 * @param recuperados a setear en la estructura
 * @param infectados a setear en la estructura
 * @param muertos a setear en la estructura
 * @return retorna 1 si lo realizo con exito o 0 si no
 */
int Object_setAllInfo(ePais *this, int id, char *nombre, int recuperados, int infectados, int muertos);
