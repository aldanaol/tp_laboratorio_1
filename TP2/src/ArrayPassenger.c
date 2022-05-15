/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: Admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Utn_Get.h"
#include "ArrayPassengerAux.h"

int initPassengers(ePassenger passenger[],int index){

	int i;
	int retorno=-1;

		if (passenger != NULL){

			retorno = 0;

		for( i=0; i<index; i++ ){
				passenger[i].isEmpty = 0;
			}
		}

		return retorno;



}




int addPassenger(ePassenger list , int len, int id, char name[],char
lastName[],float price,char flyCode[], int typePassenger, int statusFlight)
{

	int rtn=-1;





		list.id = id;
		strcpy(list.name, name);
		strcpy(list.lastName, lastName);
		list.price = price;
		strcpy(list.flycode ,flyCode);
		list.typePassenger = typePassenger;
		list.statusFlight = statusFlight;
		list.isEmpty= 1;











return rtn;
}

int findPassengerById(ePassenger Passenger[], int len, int id)
{
	int rtn = -1;
	if(Passenger != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(Passenger[i].id == id)
			{
				rtn = i;
				return rtn;
			}
		}
	}

	return rtn;
}

int printPassengers(ePassenger list[], int len){

	int rtn=0;
	int i;

	for(i=0; i<len;i++){

		if(list[i].isEmpty==1){
			printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\tCOD.VUELO\tTIPO DE PASAJERO\tESTADO DE VUELO\n");
			printf("%d\t %s\t %s\t %f\t %s\t%d\t %d\n", list[i].id, list[i].name, list[i].lastName,list[i].price,list[i].flycode,list[i].typePassenger,list[i].statusFlight);

		}



	}



	return rtn;
}



int removePassenger (ePassenger passenger, int len,int id){
	int rtn = -1;




	char confirmar;


			for(int i = 0; i < len; i++)
			{
				if(passenger.id == id)
				{
					printOnePassenger(passenger);
					printf("Dar de baja? [S|N]: ");
					fflush(stdin);
					scanf("%c", &confirmar);
					confirmar = toupper( confirmar );
					if( confirmar == 'S'){
				     passenger.isEmpty = -1;

					printf("Se han borrado los datos...");
					}
					else{
						printf("No se han borrado los datos...");
					    }

				}
			}






	return rtn;
}



int sortPassengers(ePassenger list[], int len, int order){

	int i;
	int j;
	ePassenger aux;
	int rtn=0;



     switch(order){

     case 1:

     for( i=0; i<len-1; i++ ){

     			for( j=i+1; j<len; j++ ){

     					if((strcmp(list[i].lastName, list[j].lastName)>0) ){

     						aux=list[i];
     						list[i]=list[j];
     						list[j]=aux;
     					}
     					else{
     						if((strcmp(list[i].lastName, list[j].lastName)==0)){
     							if(list[i].typePassenger >list[j].typePassenger){

     								aux = list[i];
     								list[i] = list[j];
     								list[j] = aux;
     						}
     		      		}
     				}

     			}

     		}
     break;

     case 2:
    	 for( i=0; i<len-1; i++ ){

    	 			for( j=i+1; j<len; j++ ){

    	 					if((strcmp(list[i].lastName, list[j].lastName)<0) ){

    	 						aux=list[i];
    	 						list[i]=list[j];
    	 						list[j]=aux;
    	 					}
    	 					else{
    	 						if((strcmp(list[i].lastName, list[j].lastName)==0)){
    	 							if(list[i].typePassenger <list[j].typePassenger){

    	 								aux = list[i];
    	 								list[i] = list[j];
    	 								list[j] = aux;
    	 						}
    	 		      		}
    	 				}

    	 			}

    	 		}
    	 break;

     default:
    	 printf("Ingrese una opcion correcta");
    	 break;



     }





		for( i=0; i<len; i++){
			if(list[i].isEmpty==1){
				printOnePassenger(list[i]);
			}
		   }



     return rtn=1;
}

int sortPassengersByCode(ePassenger list[], int len, int order){


	int i;
	int j;
	ePassenger aux;
	int rtn=0;

	switch(order){

	case 1:

			for( i=0; i<len-1; i++ ){

     			for( j=i+1; j<len; j++ ){

     				if(list[i].statusFlight==1){
     					if((strcmp(list[i].flycode, list[j].flycode)>0) ){

     							aux=list[i];
     							list[i]=list[j];
   								list[j]=aux;
     					}



		      		}
				}

			}
	break;

	case 2:

		for( i=0; i<len-1; i++ ){

			for( j=i+1; j<len; j++ ){

				if(list[i].statusFlight==1){

					if((strcmp(list[i].flycode, list[j].flycode)<0) ){

						aux=list[i];
						list[i]=list[j];
						list[j]=aux;

				}
			 }
			}
		}
		break;

	default:

		printf("Ingrese una opcion correcta");
		break;
	}


		for( i=0; i<len; i++){
			if(list[i].isEmpty==1){
				printOnePassenger(list[i]);
			}
		   }



     return rtn=1;

}









