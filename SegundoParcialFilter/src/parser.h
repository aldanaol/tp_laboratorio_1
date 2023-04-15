/*
 * parser.h
 *
 *  Created on: 27 jul. 2022
 *      Author: Admin
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

//int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros);
int parser_parserComputer(char* fileName, LinkedList* listaComputers);
int saveArchivo(char* path , LinkedList* listaComputers);


#endif /* PARSER_H_ */
