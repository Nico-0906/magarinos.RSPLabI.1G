/*
 * parser.h
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */


/**
 * @brief 	parsea la informacion de un archivo de texto a un linkedlist pasado
 * @param 	pFile archivo de texto desde el que se parsera la informacion
 * @param 	this linkedlist donde se copiara la informacion del archivo
 * @return	retorna 1 si se completo con exito o 0 si no lo hizo
 */
int parser_ObjectFromText(FILE *pFile, LinkedList *this);

/**
 * @brief 	parsea la informacion de un archivo binario a un linkedlist pasado
 * @param 	pFile archivo binario desde el que se parseara la informacion
 * @param 	this linkedlist donde se parseara la informacion del binario
 * @return	Retorna 1 si funciona o 0 si hay algun error
 */
int parser_ObjectFromBinary(FILE *pFile,LinkedList *this);
