/*
 * pandemia.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#ifndef PANDEMIA_H_
#define PANDEMIA_H_

typedef struct{
	int id;
	char nombre[20];
	int recu;
	int infec;
	int muert;
}ePais;

#endif /* PANDEMIA_H_ */

/**
 * @brief  crea espacio en memoria dinamica y devuelve el puntero para la estructura
 * @return retorna el puntero a la direccion de memoria dinamica para estructura ePais
 */
ePais* pandemia_new(void);

/**
 * @brief  crea una estructura ePais y la carga con los datos pasados por parametros
 * @param  id de la estructura a cargar
 * @param  nombre de pais de estructura a cargar
 * @param  cantidad de recuperados a cargar
 * @param  cantidad de infectados a cargar
 * @param  cantidad de muertos a cargar
 * @return retorna la estructura ePais nueva cargada con los datos
 */
ePais* pandemia_newParam(char *id, char *nombre, char *recu, char *infec, char *muert);
