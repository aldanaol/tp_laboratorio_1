/*
 * Utn.h
 *
 *  Created on: 11 ago. 2022
 *      Author: Admin
 */

#ifndef UTN_H_
#define UTN_H_
#define QTY_CARACTERES 50
int getInt(char*,char*,int,int);

float getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);

char getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				char minimo,
				char maximo,
				int reintentos);

int initArrayInt(int array[],int limite,int valor );

int imprimeArrayInt(int array[],int limite );

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int maximoArrayInt(int array[],int limite,int *pResultado);
int minimoArrayInt(int array[],int limite,int *pResultado);

int ordenarArrayInt(int array[],int limite );

int get_String(	char *mensaje,
				char *cadena,
				int tamanio);

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int menu( char opciones[]  );





#endif /* UTN_H_ */
