/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Utn.h"
#include "superHeroe.h"

int main()
{
	setbuf(stdout, NULL);
    int option;
	int flag = 0;
	char path[50];


	LinkedList* pAarraySuperHeroeList;
	LinkedList* listaMapeada = NULL;
	pAarraySuperHeroeList = ll_newLinkedList();


	do{



	    option=menu("Menu:\n\n"
				 "1. Cargar archivo\n"
				 "2. Ordenar por id\n"
				 "3. Imprimir listado\n"
				 "4. Desarrollar funcion ll_map\n"
				 "5. Guardar archivo mapeado.csv\n"
				 "6. Salir\n");

	        switch(option)
	        {
	            case 1:

	                if(flag == 0)
	                {   get_String("Archivo a abrir: ", path, 50);
                        if(parser_parserSuperHeroe(path,pAarraySuperHeroeList)==1)
                        {
                           printf("Lista cargada con exito\n");
                           flag = 1;
                           system("pause");
                        }
                        else {
                        	printf("Error al abrir el archivo.Intente nuevamente.");
                        }

	                }
	                else
	                    {
	                        if(flag == 1)
	                        {
	                            printf("Ya se cargaron los archivos\n");
	                            system("pause");
	                        }
	                    }

	                break;
	            case 2:
	                if(flag == 1)
	                {
	                    if(!ll_sort(pAarraySuperHeroeList,SuperHeroe_compareById,0))
                        {
                            system("cls");
                            printf("Se ordeno correctamente\n");

                        }

	                	system("pause");
	                }
	                else
	                {
	                	printf("Debe cargar un archivo primero\n");
	                	system("pause");
	                }
	            	break;
	            case 3:
	            	SuperHeroe_imprimirTodosLosSuperHeroe(pAarraySuperHeroeList);

                    system("pause");
	            	break;

	            case 4:

	            	listaMapeada=SuperHeroe_map(pAarraySuperHeroeList);
	            	if(listaMapeada != NULL)
	            					{
	            						printf("\nSE MAPEO EXITOSAMENTE");

	            					}


                    system("pause");
	                break;

                case 5:
                    saveArchivo("mapeado.csv",listaMapeada);
                    if(listaMapeada!=NULL)
                    {
                    	printf("Se genero el archivo");
                    }
                    break;

                case 6:
                	printf("Hasta la proxima!");
                	break;

                default:
                	printf("Opcion invalida");
                	break;

	        }
	    }while(option != 6);
    return 0;
}
