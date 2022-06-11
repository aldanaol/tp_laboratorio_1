

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeross en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option;
    int flag = 0;
    int flagBinario = 0;
    int id = 1000;
    //int prueba;

    LinkedList* pArrayListPassenger = ll_newLinkedList();
    do{
         system("cls");
         printf(	 "Menu:\n\n"
			 "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
			 "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
			 "3. Alta de pasajero\n"
			 "4. Modificar datos de pasajero\n"
			 "5. Baja de pasajero\n"
			 "6. Listar pasajeros\n"
			 "7. Ordenar pasajeros\n"
			 "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
			 "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
			"10. Salir\n");
    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,10,2);

        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    if(controller_loadFromText("data.csv",pArrayListPassenger)==0)
                    {
                        printf("Lista cargada con exito\n");
                        flag = 1;

                    }

                }
                else
                    {
                        if(flag == 1)
                        {
                            printf("Ya se cargaron los archivos\n");

                        }
                    }

                break;
            case 2:
                if(flagBinario == 0 && flag == 0)
                {
                    if(controller_loadFromBinary("data.csv",pArrayListPassenger)==0)
                    {
                        printf("Archivo en binario cargado exitosamente\n");
                        flagBinario = 1;

                    }

                }
                else
                {
                    if(flag == 1)
                    {
                        printf("Ya se cargaron los archivos como texto\n");

                    }
                }

            	break;

            case 3:
                system("cls");
                if(flagBinario == 1)
                {
                    printf("Debe cerrar el programa y cargar la lista como texto\n");

                }
                else
                {
                    if(ll_len(pArrayListPassenger)!=0 && flag == 1)
                    {
                         if(controller_addPassenger(pArrayListPassenger,id)==0)
                        {
                            printf("Se cargo el nuevo pasajero\n");
                            id++;

                        }

                    }
                    else
                    {
                        printf("Debe cargar un archivo de texto primero\n");

                    }
                }

            	break;

            case 4:

                if(flagBinario == 1)
                {
                    printf("Debe cerrar el programa y cargar la lista como texto\n");

                }
                else
                {
                  if(ll_len(pArrayListPassenger) != 0)
                    {
                       if(flag == 1)
                        {
                          controller_editPassenger(pArrayListPassenger);
                        }
                    }

                    else
                        {
                            printf("Debe cargar primero un archivo\n");

                        }
                }

                break;

            case 5:

                if(flagBinario == 1)
                {
                    printf("Debe cerrar el programa y cargar la lista como texto\n");

                }
                else
                {
                  if(ll_len(pArrayListPassenger) != 0)
                    {
                       if(flag == 1)
                        {
                          controller_removePassenger(pArrayListPassenger);
                        }
                    }
                    else
                    {
                       printf("Debe cargar primero un archivo\n");

                    }
                }

                break;

            case 6:

                if(flagBinario == 1)
                {
                    printf("Debe cerrar el programa y cargar la lista como texto\n");

                }
                else
                {
                     if(ll_len(pArrayListPassenger)!= 0)
                        {
                            if(flag == 1)
                            {
                            controller_ListPassenger(pArrayListPassenger);

                            }
                        }
                        else
                        {
                           printf("Debe cargar primero un archivo\n");

                        }
                }

                break;

            case 7:

                if(flagBinario == 1)
                {
                    printf("Debe cerrar el programa y cargar la lista como texto\n");

                }
                else
                {
                    if(ll_len(pArrayListPassenger)!= 0)
                    {
                      if(flag == 1)
                        {
                         controller_sortPassenger(pArrayListPassenger);
                        }
                    }
                    else
                    {
                       printf("Debe cargar primero un archivo\n");

                    }
                }

                break;

            case 8:

                  if(flag == 1 || flagBinario == 1)
                    {
                      controller_saveAsText("data.csv",pArrayListPassenger);
                      printf("Guardado exitoso\n");

                    }
                    else
                    {
                       printf("Se debe cargar primero el archivo como texto\n");

                    }
                break;
            case 9:
                 if(flagBinario == 1 || flag == 1)
                    {
                     controller_saveAsBinary("data.csv",pArrayListPassenger);
                     printf("Guardado exitoso\n");
                    }
                    else
                    {
                        printf("Se debe cargar primero el archivo como binario\n");

                    }

                break;

            case 10:
            	printf("Hasta la proxima!");
            	break;

            default:
            	printf("Opcion incorrecta");
            	break;

        }
    }while(option != 10);
    return EXIT_SUCCESS;
}


