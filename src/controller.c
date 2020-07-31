/*
 * controller.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "controller.h"
#include "getters.h"
#include "pais.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    //char buffer[5][4000];
    int retorno = 1;
    //int cargados;
    //ePais* auxEmp;
    FILE *txtFile;
    txtFile = fopen(path,"r");

    if(pArrayListEmployee != NULL && path != NULL && txtFile != NULL){

    	parser_ObjectFromText(txtFile, pArrayListEmployee);
		fclose(txtFile);
		retorno = 0;
    }

    __fpurge(stdin);
    return retorno;
}

/**
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isError = 1;
    eBicicleta* auxEmp;
    FILE* binFile;
    binFile = fopen(path,"rb");
    while(!feof(binFile))
    {
        auxEmp= bicicleta_new();
        fread(auxEmp,sizeof(eBicicleta),1,binFile);
        if(auxEmp->id!=0)
        {
            ll_add(pArrayListEmployee,auxEmp);
            isError=0;
        }
    }
    if(isError)
    {
        printf("ERROR! No se pudo cargar los datos del documento, es posible que\n");
        printf("el documento no exista o este da�ado.\n");
    }
    else
    {
        printf("Datos cargados.\n");
    }
    fclose(binFile);

    return isError;
}

**/

void pais_show(ePais* this)
{
    if (this!=NULL)
    {
        printf(" %04d   %20s    %4d    %4d    %4d\n",this->id,this->nombre,this->recu,this->infec, this->muert);
    }
}

int controller_ListPandemia(LinkedList* pArrayListEmployee)
{
    int length;
    int error = 1;
    ePais* auxEmp;
    int id;
    char pais[20];
    int	muert;
    int infec;
    int recu;

    __fpurge(stdin);
    length = ll_len(pArrayListEmployee);
    if (length > 0 && pArrayListEmployee != NULL)
    {
        printf("   ID                    Pais     Recuperados    Infectados   Muertos\n\n");
        for(int i=0; i<length; i++)
        {
            auxEmp = (ePais*) ll_get(pArrayListEmployee,i);
            Object_getID(auxEmp, &id);
            Object_getPais(auxEmp, pais);
            Object_getMuertos(auxEmp, &muert);
            Object_getInfectados(auxEmp, &infec);
            Object_getRecuperados(auxEmp, &recu);
            printf("[%3d]  [%20s]        [%6d]      [%6d]   [%5d] \n", id, pais, recu, infec, muert);
        }
        getchar();
        error=0;
    }
    else
    {
        printf("\nNo hay paises para mostrar. Primero deben cargarse.\n");
        getchar();
    }
    //free(auxEmp);  SI LO DEJO EN LINUX ME TIRA UN ERROR
    return error;
}

int controller_paisesExitosos(ePais* paises){
	int retorno = 0;

	if(paises != NULL && paises->muert < 5000){
		retorno = 1;
	}
	return retorno;
		//free(aux);
}

int controller_paisesEnElHorno(ePais* paises){

	int retorno = 0;
	int triplicado;
	triplicado = paises->recu * 3;
	if(paises != NULL && paises->infec > triplicado){
				retorno = 1;
	}
		//free(aux);
	return retorno;
}

int filtInfec(ePais* this, ePais* thistwo){
	int retorno = -1;
	if(this->infec > thistwo->infec){
		retorno = 1;
	}
	return retorno;
}

ePais* controller_asignarValores(ePais* this){
	ePais* auxPandemia;
	auxPandemia = this;
	int aleatorio = rand()%(50001) + 50000;
	this->recu = aleatorio;
	aleatorio = rand()%(160001) + 40000;
	this->infec = aleatorio;
	aleatorio = rand()%(49001) + 1000;
	this->muert = aleatorio;

	return auxPandemia;
}

int controller_mayorNumeroMuertos(LinkedList* this){
	int mayor = 0;
	int tam = ll_len(this);
	ePais* aux;
	if (tam > 0 && this != NULL){
		for(int i = 0; i < tam ; i++){
			aux = (ePais*) ll_get(this ,i);
			if(aux->muert > mayor){
				mayor = aux->muert;
			}
		}
	}

	return mayor;
}

LinkedList* controller_paisesMayorMuertos(LinkedList* this, int mayor){
	LinkedList* auxList = ll_newLinkedList();
	int length;
	ePais* auxEmp;
	length = ll_len(this);
	for(int i = 0; i < length ; i++){
		auxEmp = (ePais*) ll_get(this,i);
		if(this != NULL && auxEmp->muert >= mayor){
			ll_add(auxList, auxEmp);
		}
	}
	//free(aux);
	return auxList;
}
