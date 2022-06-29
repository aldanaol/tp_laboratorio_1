#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include "Controller.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
		char Nombre[150];
		char Apellido[150];
		char FlyCode[150];
		char Type[150];
		char Precio[150];
		char Id[150];
		char Status[150];
		char buffer[150];
		int contador = 0;
		Passenger* auxPasajero;
		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			fscanf(pFile, "%[^\n]\n", buffer);
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", Id, Nombre, Apellido, Precio, FlyCode, Type, Status) == 7)
				{
					auxPasajero = passenger_newParametrosTxt(Id, Nombre, Apellido, Precio, FlyCode, Type, Status);
					if(auxPasajero != NULL)
					{
						if(!ll_add(pArrayListPassenger, auxPasajero))
						{
							contador++;
						}
					}
				}

			}while(!feof(pFile));
		}
		retorno = contador;
		return retorno;
	}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
		int contador = 0;
		Passenger* auxPasajero;
		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			do
			{
				auxPasajero = passenger_new();
				if(auxPasajero != NULL)
				{
					if(fread(auxPasajero, sizeof(Passenger), 1, pFile) == 1)
					{
						if(!ll_add(pArrayListPassenger, auxPasajero))
						{
							contador++;
						}
					}
				}

			}while(!feof(pFile));
			retorno = contador;
		}
		return retorno;
}


int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger){

	int retorno = -1;
	char Nombre[150];
	char Apellido[150];
	char FlyCode[150];
	char Type[150];
	float Precio;
	int Id;
	char Status[150];
	int intType;
	int intStatus;
	int len, i;
	Passenger* auxPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i = 0; i < len; i++)
		{
			auxPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			if(auxPasajero != NULL)
			{
				if(!passenger_getId(auxPasajero, &Id) &&
					!passenger_getName(auxPasajero, Nombre) &&
					!passenger_getLastName(auxPasajero, Apellido) &&
					!passenger_getPrice(auxPasajero, &Precio) &&
					!passenger_getFlyCode(auxPasajero, FlyCode) &&
					!passenger_getTypePassenger(auxPasajero, &intType) &&
					!passenger_getStatusFlight(auxPasajero, &intStatus))
				{

					passenger_readStatusFlightInt(intStatus, Status);
					passenger_readTypePassengerInt(intType, Type);
					retorno = 0;
					fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n", Id, Nombre, Apellido, Precio, FlyCode, Type, Status);
				}
			}
		}
	}

	return retorno;
}
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger){

	int retorno = -1;
	int len,i;
	Passenger* auxPasajero;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		len = ll_len(pArrayListPassenger);
		for(i = 0; i < len; i++)
		{
			auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPasajero, sizeof(Passenger), 1, pFile);
		}
	}
	return retorno;
}
