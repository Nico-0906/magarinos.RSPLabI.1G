/*
 * getters.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pais.h"
#include "getters.h"

int Object_getID(ePais *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		sucess = 1;
	}
	return sucess;
}

int Object_getPais(ePais *this, char* pais){
	int retorno = 0;

	if(this != NULL && pais != NULL){
		strcpy(pais, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Object_getMuertos(ePais *this, int *muert){

	int retorno = 0;

	if(this != NULL && muert != NULL){
		*muert = this->muert;
		retorno = 1;
	}
	return retorno;
}

int Object_getInfectados(ePais *this, int *infec){

	int retorno = 0;

	if(this != NULL && infec != NULL){
		*infec = this->infec;
		retorno = 1;
	}
	return retorno;
}

int Object_getRecuperados(ePais *this, int *recu)
{
	int retorno = 0;

	if(this != NULL && recu != NULL){
		*recu = this->recu;
		retorno = 1;
	}
	return retorno;
}

