/*
 * parser.c
 *
 *  Created on: 27 jul. 2022
 *      Author: Admin
 */




#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"



int parser_parserComputer(char* fileName, LinkedList* listaComputers)
{
	int retorno = -1;
	eComputer* auxComputer;

    char id[4096];
	char descripcion[4096];
	char precio[4096];
	char idTipo[4096];

	FILE* pFile;

	pFile = fopen(fileName,"r");

	if(listaComputers != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);//si trae titulo agrego este fscanf

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
			auxComputer = computer_newParametros(id,descripcion,precio,idTipo);
			if(auxComputer != NULL)
			{
				ll_add(listaComputers,auxComputer);
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
int saveArchivo(char* path , LinkedList* listaComputers)
{
    eComputer* auxComputer;
    int retorno = -1;
    int i;

    int id;
    char descripcion[4096];
    float precio;
    int idTipo;
    //char oferta[4096];


    FILE* pFile;
    pFile = fopen(path,"wb");

	if(pFile != NULL)
    {
        fprintf(pFile,"id,descripcion,precio,idTipo\n");
        for(i=0; i<ll_len(listaComputers); i++)
        {
            auxComputer = ll_get(listaComputers,i);

            computer_getId(auxComputer,&id);
            computer_getDescripcion(auxComputer,descripcion);
            computer_getPrecio(auxComputer,&precio);
            computer_getIdTipo(auxComputer,&idTipo);

            fprintf(pFile,"%d,%s,%f,%d\n",id,descripcion,precio,idTipo);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}
