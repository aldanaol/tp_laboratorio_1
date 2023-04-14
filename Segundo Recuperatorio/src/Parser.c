/*
 * Parser.c
 *
 *  Created on: 11 ago. 2022
 *      Author: Admin
 */


#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "superHeroe.h"



int parser_parserSuperHeroe(char* fileName, LinkedList* listaSuperHeroe)
{
	int retorno = -1;
	eSuperHeroe* auxSuperHeroe;

    char id[4096];
	char nombre[4096];
	char idPropietario[4096];
	char power[4096];
	char ataque[4096];

	FILE* pFile;

	pFile = fopen(fileName,"r");



	if(listaSuperHeroe != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,idPropietario,power,ataque);//si trae titulo agrego este fscanf

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,idPropietario,power,ataque);
			auxSuperHeroe= SuperHeroe_newParametros(id,nombre,idPropietario,power,ataque);
			if(auxSuperHeroe != NULL)
			{
				ll_add(listaSuperHeroe,auxSuperHeroe);
				retorno = 1;
			}
			else
				break;

		}while(!feof(pFile));
	}
	fclose(pFile);
	fileName = NULL;
    return retorno; // OK
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int saveArchivo(char* path , LinkedList* listaSuperHeroe)
{
    eSuperHeroe* auxSuperHeroe;
    int retorno = -1;
    int i;

    int id;
    char nombre[4096];
    int idPropietario;
    int power;
    int ataque;
    //char oferta[4096];


    FILE* pFile;
    pFile = fopen(path,"w");

	if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,idPropietario,power,ataque\n");
        for(i=0; i<ll_len(listaSuperHeroe); i++)
        {
            auxSuperHeroe = ll_get(listaSuperHeroe,i);

            SuperHeroe_getId(auxSuperHeroe,&id);
            SuperHeroe_getNombre(auxSuperHeroe,nombre);
            SuperHeroe_getIdPropietario(auxSuperHeroe,&idPropietario);
            SuperHeroe_getPower(auxSuperHeroe,&power);
            SuperHeroe_getAtaque(auxSuperHeroe,&ataque);

            fprintf(pFile,"%d,%s,%d,%d,%d\n",id,nombre,idPropietario,power,ataque);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}

