/*
 * herramientas.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "herramientas.h"
#include "pais.h"

int getString(char* string, int lon) {
	int retorno = -1;
	char buffer[1000];

	if (string != NULL && lon > 0) {
		__fpurge(stdin);
		if(fgets(buffer,sizeof(buffer),stdin) != NULL){
			if(buffer[strnlen(buffer,sizeof(buffer))-1] == '\n'){
				buffer[strnlen(buffer,sizeof(buffer))-1] = '\0';
			}
			if(strnlen(buffer,sizeof(buffer)) <= lon){
				strncpy(string, buffer, lon);
				retorno=0;
			}
		}
	}
	return retorno;
}

int isNumber(char* string, int limite) {
	int retorno = 1;
	int i;
	for (i = 0; i < limite && string[i] != '\0'; i++) {
		if (i == 0 && (string[i] == '+' || string[i] == '-')) {
			continue;
		}
		if (string[i] > '9' || string[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int getInt(int* pResultado){
    int retorno = -1;
    char buffer[50];
    if(	pResultado != NULL &&
    	getString(buffer,sizeof(buffer)) == 0 &&
    	isNumber(buffer, sizeof(buffer))) {
		retorno=0;
		*pResultado = atoi(buffer) ;

	}
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,	int minimo, int maximo, int reintentos){
	int retorno = 0;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&	bufferInt <= maximo){
			retorno = 1;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

static int getNombre(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int esNombre(char *string, int longitud) {
	int i=0;
	int retorno = 1;

	if (string != NULL && longitud > 0) {
		for (i = 0; string[i] != '\0' && i < longitud; i++) {
			if ((string[i] < 'A' || string[i] > 'Z')
					&& (string[i] < 'a' || string[i] > 'z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = 0;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**void pedirFecha(eFecha fechas[]){
    int bucle = 1;
    eFecha auxFecha;
    while(bucle == 1){
        scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        if(auxFecha.dia >= 1 && auxFecha.dia <= 31 && auxFecha.mes >= 1 && auxFecha.mes <= 12 && auxFecha.anio >= 1900 && auxFecha.anio <= 9999){
            printf("\nFecha ingresada con exito\n");
            *fechas = auxFecha;
            bucle = 0;
        }else{
            printf("\nFecha incorrecta, reingresar: ");
        }
    }
}**/

int validarOpcion(int max, int min,char mensaje[], char mensajeError[]){
    int retorno;
    int bucle = 1;
    int opcion;

    printf("%s", mensaje);

    while(bucle == 1){
        scanf("%d", &opcion);

        if(opcion <= max && opcion >= min){
            retorno = opcion;
            bucle = 0;
        }else{
            printf("%s", mensajeError);
        }
    }
    return retorno;
}

void tipoNombre(char vec[], int tam){
    vec[0] = toupper(vec[0]);

    for(int i = 1 ; i < tam ; i++){
        vec[i] = tolower(vec[i]);
    }
}

void getStr(char cadena[], int tam){

    fgets(cadena, tam, stdin);

    for(int i = 0; i < tam; i++){
        if(cadena[i] == '\n'){
            cadena[i] = '\0';
        }
    }
}

void getCharConfirmValidado(char* caracter){
    int bucle = 0;
    char opcion;

    while(bucle == 0){
        __fpurge(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        if(opcion == 's' || opcion == 'n' || opcion == 'S' || opcion == 'N'){
            *caracter = opcion;
            bucle = 1;
        }else{
            printf("\n Opcion incorrecta, ingrese S o N : ");
        }
    }
}

char menuOpciones(){
    char retorno;
    int bandera = 0;
    system("clear");

    printf("****** Menu opciones ******\n\n");
    printf("A- Alta moto\n");
    printf("B- Modificar moto\n");
    printf("C- Baja moto\n");
    printf("D- Listar motos\n");
    printf("E- Listar tipos\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Salir\n");
    printf("K- INFORMES\n");
    __fpurge(stdin);

    while(bandera == 0){
        __fpurge(stdin);
        scanf("%c", &retorno);
        if( (retorno < 76 && retorno > 64) || (retorno < 108 && retorno > 96) ){
            bandera = 1;
        }else{
            printf("\nOpcion incorrecta, ingrese opcion: ");
        }
    }

    return retorno;
}

int guardarCSV(LinkedList *lista, char *path){
	FILE* f;
	int error = 1;
	f = fopen(path, "w");
	ePais* pandemia;

	int id;
	char nombre[150];
	int recuperados;
	int infectados;
	int muertos;
	int tam;

	if(lista != NULL){

		tam = ll_len(lista);

		for(int i = 0 ; i < tam ; i++){
			pandemia = (ePais*) ll_get(lista, i);
			id = pandemia->id;
			strcpy(nombre, pandemia->nombre);
			recuperados = pandemia->recu;
			infectados = pandemia->infec;
			muertos = pandemia->muert;
			fprintf(f, "%d,%s,%d,%d,%d\n", id, nombre, recuperados, infectados, muertos);
		}
		error = 0;
	}
	fclose(f);

	return error;

}
