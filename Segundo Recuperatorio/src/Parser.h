/*
 * Parser.h
 *
 *  Created on: 11 ago. 2022
 *      Author: Admin
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_parserSuperHeroe(char* fileName, LinkedList* listaSuperHeroe);
int saveArchivo(char* path , LinkedList* listaSuperHeroe);


#endif /* PARSER_H_ */
