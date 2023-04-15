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
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"
#include "Computer.h"

int main()
{
   int option;
	int flag = 0;

	LinkedList* pAarrayComputerList;
	LinkedList* listraFiltradaDesktop;
	pAarrayComputerList = ll_newLinkedList();


	do{
        system("cls");
	    printf(	 "Menu:\n\n"
				 "1. Cargar archivo\n"
				 "2. Ordenar por idTipo\n"
				 "3. Imprimir listado\n"
				 "4. Aplicar funcion ll_map\n"
				 "5. Filtrar lista Desktop\n"
				 "6. Guardar archivo filtrado.csv\n"
				 "7. Salir\n");

	    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,7,2);

	        switch(option)
	        {
	            case 1:

	                if(flag == 0)
	                {
                        if(parser_parserComputer("datos_Fin.csv",pAarrayComputerList)==1)
                        {
                           printf("Lista cargada con exito\n");
                           flag = 1;
                           system("pause");
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
	                    if(!ll_sort(pAarrayComputerList,computer_compareIdComputer,1))
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
                    computer_imprimirTodosLosComputers(pAarrayComputerList);

                    system("pause");
	            	break;

	            case 4:



	            case 5:
                    listraFiltradaDesktop = NULL;
                    listraFiltradaDesktop = ll_filter(pAarrayComputerList,computer_filtrarDesktop);
                    printf("Se aplico el filtro solicitado\n");
                    system("pause");
	                break;
                case 6:
                    saveArchivo("filtrado.csv",listraFiltradaDesktop);
                    break;

	        }
	    }while(option != 7);
    return 0;
}
