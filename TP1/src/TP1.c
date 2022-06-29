/*
 ============================================================================
 Name        : TP1.c
 Author      : Olivera Aldana
 Division    : K
 ===========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"
#include "Utn_Get.h"
#include "Menu.h"

int main (void){

	setbuf(stdout, NULL);

	int opcion;
	float km,precioAA,precioLatam,debitoAA,creditoAA,btcAA,unitarioAA,debitoLatam,creditoLatam,btcLatam,unitarioLatam,difPrecio;
    int flagKm=0;
    int flagPrecio=0;
    int flagCostos=0;

	do{

	    opcion=menu("\n1)Ingresar Km:\n2)Ingresar precio de vuelos:\n3)Calcular todos los costos:\n4)Informar resultados:\n5)Carga forzada de datos.\n6)Salir\n");
		switch(opcion){

		case 1:
			if(flagKm==0)
			{
				km=PedirFloat("Ingrese los km","Error,intente nuevamente",1,1000000);
				flagKm=1;
			}
			break;
		case 2:
			if (flagKm==1)
			{
				precioAA=PedirFloat("ingrese el precio de AA","Error,intente nuevamente",1,1000000);
				precioLatam=PedirFloat("ingrese el precio de AA","Error,intente nuevamente",1,1000000);
				flagPrecio=1;
			}
			break;
		case 3:
			if(flagKm==1 && flagPrecio==1)
			{
				debitoAA=calcularCostos(precioAA,km,1);
				creditoAA=calcularCostos(precioAA,km,2);
				btcAA=calcularCostos(precioAA,km,3);
				unitarioAA=calcularCostos(precioAA,km,4);

				debitoLatam=calcularCostos(precioLatam,km,1);
				creditoLatam=calcularCostos(precioLatam,km,2);
				btcLatam=calcularCostos(precioLatam,km,3);
				unitarioLatam=calcularCostos(precioLatam,km,4);

				difPrecio=diferenciaPrecio(precioLatam,precioAA);

				flagCostos=1;

			}
			else
			{
				printf("\nError.No hay datos ingresados");
			}
			break;
		case 4:
			if (flagKm==1 && flagPrecio==1 && flagCostos==1)
			{
				mostrarCostos(km,precioAA,debitoAA,creditoAA,btcAA,unitarioAA,precioLatam,debitoLatam,creditoLatam,btcLatam,unitarioLatam,difPrecio);
			}
			else
			{
				printf("\nError.No hay datos para mostrar");
			}
			break;
		case 5:
			km=7090;
			precioAA=1335000.66;
			precioLatam=1350000.76;

			debitoAA=calcularCostos(precioAA,km,1);
			creditoAA=calcularCostos(precioAA,km,2);
			btcAA=calcularCostos(precioAA,km,3);
			unitarioAA=calcularCostos(precioAA,km,4);

			debitoLatam=calcularCostos(precioLatam,km,1);
			creditoLatam=calcularCostos(precioLatam,km,2);
			btcLatam=calcularCostos(precioLatam,km,3);
		    unitarioLatam=calcularCostos(precioLatam,km,4);

			difPrecio=diferenciaPrecio(precioLatam,precioAA);

			mostrarCostos(km,precioAA,debitoAA,creditoAA,btcAA,unitarioAA,precioLatam,debitoLatam,creditoLatam,btcLatam,unitarioLatam,difPrecio);

			break;
		case 6:
			printf("\nGRACIAS!\n");
			break;
		default:
			printf("\nError.Ingrese una opcion valida");
			break;
		}


	}while(opcion!=6);

	return 0;
}
