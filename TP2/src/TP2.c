/*
 ============================================================================
 Name        : TP2.c
 Author      : Olivera Aldana
 Division    : 1K

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Utn_Get.h"
#include "ArrayPassengerAux.h"

#define CANT 2000


int main(void) {

	setbuf(stdout, NULL);

	ePassenger passenger[CANT];
	int i,opcion;
	int contadorAlta=0;
	int id=1;
	int auxId;
	float acumuladorPrecio=0;
	int flagAlta;

	initPassengers(passenger,CANT);

	do{
		opcion = menu("\nMENU\n1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5.Alta Forzada\n6. Salir\n");

		switch(opcion){

		      case 1:
		    	  flagAlta=0;
		    		  for(i=0;i<CANT;i++){
		    			  if(passenger[i].isEmpty==0){

		    				  passenger[i]=PassengerAux(id,CANT);
		    				  id++;
		   		    		  contadorAlta++;
		   		    		  acumuladorPrecio=acumuladorPrecio+passenger[i].price;
		   		    		  flagAlta=1;
		   		    		  break;


		    			  }
		    		  }
		    		  if(flagAlta==0){
		    			  printf("No hay espacio disponible");
		    		  }
		    		  break;



		      case 2:
		    	  if(contadorAlta>0){

		    		  auxId=getInt("Ingrese el ID: ");
		    		  i=findPassengerById(passenger,CANT,auxId);

		    		 if(i==-1){

		    			  auxId=getInt("Error.Ingrese un ID valido:");
		    		  }
		    		  else{

		    		         for( i=0; i<CANT; i++ ){
					          if (auxId==passenger[i].id && passenger[i].isEmpty==1){

					        	  printOnePassenger(passenger[i]);
					        	  passenger[i]=ModifyPassanger(passenger[i]);

		    		 					   }


		    		 				   }
		    		  }

		    	  }
		    	  else{

		    		  printf("No hay datos cargados");
		    	  }
		     	   break;

		      case 3:
		    	  if(contadorAlta>0){

		    		  auxId=getInt("Ingrese el ID: ");
		    		  i=findPassengerById(passenger,CANT,auxId);

		    		  if(i==-1){

		    		    auxId=getInt("Error.Ingrese un ID valido:");
		    		  }
		    		  else{

		  		         for( i=0; i<CANT; i++ ){
		    			  if (auxId==passenger[i].id && passenger[i].isEmpty==1){
		  		        	  removePassenger(passenger[i],CANT,auxId);

		    		    	 }
		  				   }
   		    		  }
		    	  }
		    	  else{
		    		  printf("No hay datos cargados");
 		    	  }


		    	  break;

		      case 4:
		    	  if(contadorAlta>0){
		    		  Informar(acumuladorPrecio, contadorAlta,CANT,passenger);

		    	  }
		    	  else{
		    		  printf("No hay datos cargados");
		    	  }


		    	  break;

		      case 5:

		    	  forcedLoad(passenger,CANT);
		    	  contadorAlta=1;
		    	  break;

		      case 6:
		    	  printf("Hasta la proxima");
		    	  break;

		      default:

		    	  printf("Ingrese una opcion correcta");
		    	  break;



		    	  }






	}while(opcion!=6);

}




