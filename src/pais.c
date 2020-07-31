/*
 * pandemia.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#include "pais.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


ePais* pandemia_new(void){
    ePais* pAux;
    pAux = (ePais*) malloc(sizeof(ePais));
    return pAux;
}

ePais* pandemia_newParam(char *id, char *nombre, char *recu, char *infec, char *muert) {
	ePais *newPandemia;
	newPandemia = pandemia_new();

	char auxId;
	char auxRecu;
	char auxInfec;
	char auxMuert;

	auxId = atoi(id);
	auxRecu = atoi(recu);
	auxInfec = atoi(infec);
	auxMuert = atoi(muert);


	if (newPandemia != NULL && id > 0 && nombre != NULL && recu >= 0 && infec >= 0 && muert >= 0) {
		Object_setAllInfo(newPandemia, auxId, nombre, auxRecu, auxInfec, auxMuert);
	}
	return newPandemia;
}

