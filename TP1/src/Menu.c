/*
 * Menu.c
 *
 *  Created on: 29 jun. 2022
 *      Author: Admin
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Utn_get.h"
#include "Menu.h"


int menu( char opciones[]  ){
	int opcion;

	printf( opciones );

	opcion=PedirNumero("Ingrese la opcion deseada","Error",1,6);

	return opcion;
}

void mostrarCostos(float kmIngresados,float precioAA,float debitoAA, float creditoAA, float btcAA, float unitarioAA,float precioLatam, float debitoLatam, float creditoLatam, float btcLatam, float unitarioLatam, float difPrecio){

	printf("\nKM INGRESADOS: %.2f\n\nPrecio Aerolineas: %.2f\na)Precio con tardeja de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con bitcoin: %.2f\nd)Mostrar precio unitario: $%.2f\n\nPrecio Latam: $%.2f\na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con bitcoin: %.2f\nd)Mostrar precio unitario: $%.2f\n\nLa diferencia de precio es: $%.2f",kmIngresados,precioAA,debitoAA,creditoAA,btcAA,unitarioAA,precioLatam,debitoLatam,creditoLatam,btcLatam,unitarioLatam,difPrecio);
}
