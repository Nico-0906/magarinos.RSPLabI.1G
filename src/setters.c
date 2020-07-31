/*
 * setters.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "pais.h"
#include "setters.h"

int Object_setID(ePais *this, int id) {
	int sucess = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = id;
			sucess = 1;
		}
	}
	return sucess;
}

int Object_setNombre(ePais *this, char *name) {
	int sucess = 0;

	if (this != NULL && name != NULL) {
		strncpy(this->nombre, name, 20);
		sucess = 1;
	}
	return sucess;
}

int Object_setRecuperados(ePais *this, int recuperados) {
	int sucess = 0;

	if (this != NULL && recuperados >= 0) {
		this->recu = recuperados;
		sucess = 1;
	}
	return sucess;
}

int Object_setInfectados(ePais *this,int infectados) {
	int sucess = 0;

		if (this != NULL && infectados >= 0) {
			this->infec = infectados;
			sucess = 1;
		}
		return sucess;
	}

int Object_setMuertos(ePais *this, int muertos) {
	int sucess = 0;

	if (this != NULL && muertos >= 0) {
			this->muert = muertos;
			sucess = 1;
	}
	return sucess;
}


int Object_setAllInfo(ePais *this, int id, char *nombre, int recuperados, int infectados, int muertos) {
	int sucess = -1;

	if (this != NULL) {
		Object_setID(this, id);
		Object_setNombre(this, nombre);
		Object_setRecuperados(this, recuperados);
		Object_setInfectados(this, infectados);
		Object_setMuertos(this, muertos);
		sucess = 0;
	}
	return sucess;
}

