#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

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

    Passenger* auxPassenger;
	int id;
	char nombre[QTY_CARACTERES];
	char apellido[QTY_CARACTERES];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];

	//pFile = fopen("data.csv","r");
	if(pArrayListPassenger != NULL && pFile != NULL)
    {
        fscanf(pFile,"%d,%[^,],%[^,],%f,%[^,],%d\n",&id,nombre,apellido,&precio,codigoVuelo,&tipoPasajero);

		do
		{
			fscanf(pFile,"%d,%[^,],%[^,],%f,%[^,],%d\n",&id,nombre,apellido,&precio,codigoVuelo,&tipoPasajero);
			auxPassenger = Passenger_newParametros(&id,nombre,apellido,&precio,codigoVuelo,&tipoPasajero);

			if(auxPassenger != NULL)
			  {
			  	 ll_add(pArrayListPassenger,auxPassenger);
			  	 retorno = 0;
			  }
            else
                break;

		}while(!feof(pFile));
    }

		fclose(pFile);
		pFile = NULL;

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
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL && pFile != NULL)
    {
        do
		{
			auxPassenger = Passenger_new();
			fread(auxPassenger,sizeof(Passenger),1,pFile);
			if(auxPassenger != NULL)
            {
                ll_add(pArrayListPassenger,auxPassenger);
                retorno = 0;
            }
            else
                break;

		}while(!feof(pFile));
    }

	fclose(pFile);
	pFile = NULL;

    return retorno;
}
