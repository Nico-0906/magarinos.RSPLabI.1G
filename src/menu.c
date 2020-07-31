/*
 * menu.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"

int menu(){
	int opcion;
	system("clear");

	printf("----------------------------\n");
	printf("****** MENU PRINCIPAL ******\n\n");
	printf("1-. Cargar archivo \n");
	printf("2-. Imprimir lista \n");
	printf("3-. Asignar estadísticas \n");
	printf("4-. Filtrar por países exitosos \n");
	printf("5-. Filtrar por países en el horno \n");
	printf("6-. Ordenar por nivel de infección \n");
	printf("7-. Mostrar más castigado \n");
	printf("8-. Salir. \n");

	opcion = validarOpcion(8, 1, "\nIngrese opcion: ", "\nOpcion incorrecta, reintentar: ");
	__fpurge(stdin);

	return opcion;
}
