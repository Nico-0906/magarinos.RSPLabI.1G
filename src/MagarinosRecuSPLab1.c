/*
 ============================================================================
 Name        : MagarinosRecuSPLab1.c
 Author      : Nicolas Magariños
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "LinkedList.h"
#include "controller.h"
#include "herramientas.h"
#include "menu.h"

int main(void) {
	srand(time(NULL));
	char confirm = 'n';
	char auxString[40];
	int bandera = 0;
	int mayor;
	LinkedList* listaPandemia = ll_newLinkedList();
	LinkedList* listaAux = ll_newLinkedList();

	do{
		switch (menu()) {
		case 1:
			printf("\nIngrese nombre del archivo que desea cargar (ej pandemia): ");
			getString(auxString, 40);
			strncat(auxString, ".csv", 5);
			getchar();
			if(!controller_loadFromText(auxString, listaPandemia))
			{
				bandera = 1;
				printf("\nDatos cargados con exito!\n");
				getchar();
			}else{
				printf("\nError al cargar los datos!\n");
				getchar();
			}
			break;
		case 2:
			if(!bandera == 0){
				controller_ListPandemia(listaPandemia);
			}else{
				printf("\n Primero debe cargarse una lista!! \n");
				getchar();
			}
			break;
		case 3:
			listaPandemia = ll_map(listaPandemia, controller_asignarValores);
			printf("\n Valores asignados con exito!!\n");
			getchar();
			break;
		case 4:
			listaAux = ll_filter(listaPandemia, controller_paisesExitosos);
			if(!guardarCSV(listaAux, "listafiltrada.csv")){
				printf("\nLista de paises exitosos generada con exito!");
				getchar();
			}
			break;
		case 5:
			listaAux = ll_filter(listaPandemia, controller_paisesEnElHorno);
			if(!guardarCSV(listaAux, "listafiltradaHorno.csv")){
				printf("\nLista de paises en el horno generada con exito!");
				getchar();
			}
			break;
		case 6:
			listaAux = ll_clone(listaPandemia);
			ll_sort(listaAux, filtInfec, 0);
			controller_ListPandemia(listaAux);
			break;
		case 7:
			mayor = controller_mayorNumeroMuertos(listaPandemia);
			listaAux = controller_paisesMayorMuertos(listaPandemia, mayor);
			printf("El mayor numero de muertos es %d y el/los paises son: \n", mayor);
			controller_ListPandemia(listaAux);
			getchar();
			break;
		case 8:
			printf("\nDesea salir del programa? s / n :");
			getCharConfirmValidado(&confirm);
			break;
		}
	}while(!(confirm == 's'));


	return EXIT_SUCCESS;
}
