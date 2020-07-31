/*
 * parser.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */
#include <stdio_ext.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "pais.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	ePais *pandemia;

	char id[5];
	char nombre[128];
	char muert[5];
	char infec[5];
	char recu[5];

	int retorno = 0;
	int firstElement = 1;

	if (pFile != NULL && this != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recu, infec, muert);
				firstElement = 0;
			}else{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recu, infec, muert);
				pandemia = pandemia_newParam(id, nombre, recu, infec, muert);

				if (pandemia != NULL) {
					ll_add(this, pandemia);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int parser_ObjectFromBinary(FILE *pFile, LinkedList *this) {
	ePais *pandemia;
	int sucess = 0;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			pandemia = pandemia_new();
			if (fread(pandemia, sizeof(ePais), 1, pFile) == 1) {
				ll_add(this, pandemia);
			}
		}
		sucess = 1;
	}
	return sucess;
}
