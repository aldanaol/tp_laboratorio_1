/*
 * ArrayPassengerAux.c
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
#include "ArrayPassengerAux.h"


int menu( char opciones[]  ){
	int opcion;

	printf( opciones );

	printf("\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}

ePassenger PassengerAux(int id,int cant){

	ePassenger aux;
	char auxName[51];
	char auxLastName[51];
	char auxFlyCode[51];





	         aux.id=id;

	         GetString(auxName,51,"Ingrese el nombre: ");
	         strcpy(aux.name,auxName);


			 GetString(auxLastName,51,"Ingrese el apellido: ");
			 strcpy(aux.lastName,auxLastName);


			 aux.price=getFloat("Ingrese el precio del vuelo");

			 GetString(auxFlyCode,10,"Ingrese el codigo de vuelo: ");
			 strcpy(aux.flycode,auxFlyCode);

			 aux.typePassenger=getInt("Ingrese el tipo de pasajero:\n1-Economica\n2-Primera clase\n3-VIP");

			 aux.statusFlight=getInt("Ingrese el estado de vuelo:\n1-Activo\n2-Demorado\n3-Cancelado");


			 addPassenger(aux,cant,aux.id,aux.name,aux.lastName,aux.price,aux.flycode,aux.typePassenger,aux.statusFlight);









		return aux;
}



ePassenger lowLogic(ePassenger list, int len, int id){

	char confirmar;


		for(int i = 0; i < len; i++)
		{
			if(list.id == id)
			{
				printOnePassenger(list);
				printf("Dar de baja? [S|N]: ");
				fflush(stdin);
				scanf("%c", &confirmar);
				confirmar = toupper( confirmar );
				if( confirmar == 'S'){
				list.isEmpty = -1;


				printf("Se han borrado los datos...");
				}
				else{
					printf("No se han borrado los datos...");
				    }

			}
		}

		return list;
}


void printOnePassenger(ePassenger list){

	printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\tCOD.VUELO\tTIPO DE PASAJERO\tESTADO DE VUELO\n");
	printf("%d\t %s\t %s\t %f\t %s\t%d\t %d\n", list.id, list.name, list.lastName,list.price,list.flycode,list.typePassenger,list.statusFlight);
}

ePassenger ModifyPassanger(ePassenger passenger){



	int opcionModificar;
	char auxNombre[51];
	char auxApellido[51];
	char auxFlyCode[10];


	do{
									opcionModificar = menu( "MENU\n1.Nombre\n2. Apellido\n3. Precio\n 4.Tipo de pasajero\n5.Codigo de vuelo\n6 Salir" );

									switch( opcionModificar ){
										case 1:
											GetString(auxNombre,51,"Ingrese el nombre");
											strcpy(passenger.name,auxNombre);
											break;
										case 2:
											GetString(auxApellido,51,"Ingrese el apellido");
											strcpy(passenger.lastName,auxApellido);
											break;
										case 3:
											passenger.price=getInt("Ingrese el precio");
											break;
										case 4:
											passenger.typePassenger=getInt("\nIngrese el tipo de pasajero:\n1-Economica\n2-Primera clase\n3-VIP");
											break;
										case 5:
											GetString(auxFlyCode,10,"Ingrese el codigo de vuelo");
											strcpy(passenger.flycode,auxFlyCode);
											break;
										case 6:
											printf("Volviendo al menu principal ");
											break;

										default:
											printf("La opcion ingresada es incorrecta..");
											break;
									}
			}while( opcionModificar != 6);



return passenger;


}

void Informar(float total, int contador,int cant, ePassenger passenger[]){

	int opcion;
	int i=0;
	float promedio;
	int precioNoSupera=0;
	int order;



	do{
		opcion=menu("\nINFORMAR\n1.Listado de pasajeros ordenados por Apellido y Tipo de Pasajero\n2.Total y promedio de los precios de los pasajes,y cuantos no superan el promedio\n3. Listado de los pasajeros por codigo de vuelo y estados de vuelo ACTIVO\n4. Salir\n");


		switch(opcion){

		case 1:

			order=menu("\n1. Listado ascendente.\n2. Listado descendente.");
			sortPassengers(passenger, cant, order);

	   break;

		case 2:

			promedio=total/cant;
			 for(i=0; i<cant; i++){
			      if(passenger[i].price<promedio){

			            	precioNoSupera++;
			           }
				}

			printf("\nEl total es %f:\nEl promedio es %f:\n La cantidad de vuelos que no superan el promedio es %d:",total,promedio,precioNoSupera);
			break;



		case 3:
			order=menu("\n1. Listado ascendente.\n2. Listado descendente.");
			sortPassengersByCode(passenger,cant,order);
			break;

		case 4:
			printf("Volviendo al menu principal");
			break;

		default:
			printf("La opcion ingresada no es correcta");
			break;
		}

	}while(opcion!=4);
}

void forcedLoad(ePassenger passenger[], int cant){

	int i;
	int id[5] = {1,2,3,4,5};
	char nombres[5][51]= {"Alberto","Rodrigo","Nora","Fernando","Dolores"};
	char apellido[5][51]= {"Olivera","Enciso","Paez","Galiano","Enciso"};
    float precio[5]= {1500,3550,350.50,2500,280};
    char codVuelo[5][10]={"AR100","BL200","IN150","BL250","IN200"};
    int tipoPas[5]={2,3,1,2,1};
    int estadoVuelo[5]={1,1,2,1,3};
    int empty[5]={1,1,1,1,1};

	    for(i=0; i<cant; i++)
	    {
	        passenger[i].id = id[i];
	        strcpy(passenger[i].name, nombres[i]);
	        strcpy(passenger[i].lastName, apellido[i]);
	        passenger[i].price = precio[i];
	        strcpy(passenger[i].flycode, codVuelo[i]);
	        passenger[i].typePassenger = tipoPas[i];
	        passenger[i].statusFlight = estadoVuelo[i];
	        passenger[i].isEmpty = empty[i];


	    }
	}




