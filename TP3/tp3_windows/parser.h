/*
 * parser.h
 *
 *  Created on: 29 jun. 2022
 *      Author: Admin
 */

#ifndef PARSER_H_
#define PARSER_H_


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger);
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger);
#endif /* PARSER_H_ */
