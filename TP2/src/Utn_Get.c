/*
 * Utn_Get.c
 *
 *  Created on: 14 may. 2022
 *      Author: Admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Utn_Get.h"



void GetString(char cadena[],int max,char text[]){

		printf("%s",text);
		fflush(stdin);
		scanf("%s",cadena);

		while((strlen(cadena)<0) || strlen(cadena)>max){

			printf("\nError.Intente nuevamente: ");
			fflush(stdin);
			scanf("%s",cadena);
		}

}



int getInt(char mensaje[])//que sea un numero
{
	int retorno = -1;
	int esNumero;
	char auxiliar[30];




	GetString(auxiliar,30,mensaje); // donde se va a guardar, ingresa un numero,limite de la cadena

	while(esNumerica(auxiliar) < 1)
	{
	  GetString(auxiliar,30,mensaje);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}


int esNumerica(char auxiliar[])
{
	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++)
		{
			if(isdigit(auxiliar[i])==0)
			{
				retorno =0;
				break;

			}

		}
	}


	return retorno;

}

float getFloat(char mensaje[])//que sea un numero
{
    float retorno = -1;
	float esNumero;
	char auxiliar[30];




	GetString(auxiliar,30,mensaje); // donde se va a guardar, ingresa un numero,limite de la cadena

	while(esNumerica(auxiliar) < 1)
	{
	  GetString(auxiliar,30,mensaje);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}
//  isdigit(caracter) 0 si no es un numero y mayor a 0 si es un numero



