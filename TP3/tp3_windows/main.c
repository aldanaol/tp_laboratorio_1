

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "Gets.h"

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

int main(void)
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros;
    LinkedList* listaCodigosDevuelo;
    int opcion;
	int banderaGuardadoArchivo = 0;
	int banderaLecturaArchivo = 0;
	int confirmacionGuardado;

    listaPasajeros = ll_newLinkedList();
    listaCodigosDevuelo = ll_newLinkedList();
    controller_initFlyCodes(listaCodigosDevuelo);

    do{
    	opcion = passenger_menuInt("\n1. Cargar los datos de los pasajeros desde archivo en modo texto\n2. Cargar los datos de los pasajeros desde archivo en modo binario\n3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar\n8. Guardar los datos de los pasajeros en modo texto\n9. Guardar los datos de los pasajeros en modo binario\n10. Salir\n",1,10);
        switch(opcion)
        {
            case 1:
				if(!controller_loadFromText("data.csv",listaPasajeros))
				{
					banderaLecturaArchivo = 1;
					printf("Lista cargada con exito\n");
				}
                break;
            case 2:
				if(!controller_loadFromBinary("dataBin.bin",listaPasajeros))
				{
					banderaLecturaArchivo = 1;
					printf("Archivo binario cargado exitosamente\n");
				}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros, listaCodigosDevuelo) == 0)
            	{
            		printf("Pasajero cargado correctamente\n");
            	}
            	else
            	{
            		printf("Error: No se pudo cargar el pasajero\n");
            	}
            	break;
            case 4:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		if(!controller_editPassenger(listaPasajeros, listaCodigosDevuelo))
            		{
            			printf("\nPasajero modificado exitosamente.");
            		}
            		else
            		{
            			printf("\nNo se pudo modificar al pasajero");
            		}
            	}
            	else
            	{
					printf("No hay pasajeros cargados\n");
            	}
            	break;
            case 5:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		if(!controller_removePassenger(listaPasajeros))
            		{
            			printf("\nPasajero dado de baja exitosamente.");
            		}
            	}
            	else
            	{
					printf("\nNo hay pasajeros cargados.\n");

            	}
            	break;
            case 6:
            	if(!ll_isEmpty(listaPasajeros))
            	{

            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
					printf("Error.No hay pasajeros cargados en el sistema\n");
            	}
            	break;
            case 7:
            	if(!ll_isEmpty(listaPasajeros))
				{
            		if(!controller_sortPassenger(listaPasajeros))
					{
						printf("\nSe ordenaron los pasajeros exitosamente\n");
					}
				}
            	else
            	{
					printf("\Error.No hay pasajeros cargados\n");
            	}

            	break;
            case 8:
            	if(!ll_isEmpty(listaPasajeros))
            	{
					if(banderaLecturaArchivo == 1)
					{
						controller_saveAsText("data2.csv", listaPasajeros);
					}
					else
					{
						printf("\nSe perderan los pasajeros cargados en el archivo\n");
						get_Entero("Si desea guardarlo igualmente ingrese 1: ", &confirmacionGuardado);
						if(confirmacionGuardado == 1 && !controller_saveAsText("data2.csv", listaPasajeros))
						{
							printf("\nArchivo de texto guardado correctamente\n");
							banderaGuardadoArchivo = 1;
						}
					}
            	}
            	else
            	{
            		printf("\nError.No hay pasajeros cargados para guardar\n");
            	}
            	break;
            case 9:
            	if(!ll_isEmpty(listaPasajeros))
            	{
					if(!controller_saveAsBinary("dataBin.bin", listaPasajeros))
					{
						printf("Guardado correctamente");
						banderaGuardadoArchivo = 1;
					}
            	}
            	else
            	{
            		printf("Error.No hay pasajeros cargados para guardar\n");
            	}
            	break;
            case 10:
            	if(banderaGuardadoArchivo == 0)
            	{
            		opcion = 0;
            		printf("\nDebe guardar la lista antes de salir del sistema\n");
            	}
            	else
            	{
            		printf("\nHasta la proxima!\n");
            	}
            	break;
            default:
            	printf("\nError.Ingrese una opcion correcta");
            	break;
        }
    }while(opcion != 10);

    ll_deleteLinkedList(listaPasajeros);
    ll_deleteLinkedList(listaCodigosDevuelo);

    return 0;
}
