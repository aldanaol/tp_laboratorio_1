/*
 * operaciones.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Olivera Aldana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BTC 4606954.55

//Pedimos los km//

/**
 * @brief solicita al usuario ingresar los km
 * @param km guarda los km ingresados
 * @return retorna los km ingresados
 */

float pedirKm(){


	float km;
	printf("\nIngrese la cantidad de KM: ");
	scanf("\n%f",&km);

	return km;
}

//Pedimos el precio de Aerolineas/

/**
 * @brief pide al usuario ingresar el precio de Aerolineas
 * @param precioAA guarda el precio ingresado
 * @return retorna el precio ingresado
 */

float pedirPrecioAA(){

	float precioAA;
	printf("\nIngrese el precio del vuelo de Aerolineas: ");
	scanf("\n%f",&precioAA);

	return precioAA;
}

//Pecimos el precio de Latam//

/**
 * @brief pide al usuario que ingrese el precio de Latam
 * @param precioLatam guarda el precio ingresado
 * @return retorna el precio
 */

float pedirPrecioLatam(){

	float precioLatam;
	printf("\nIngrese el precio del vuelo de Latam: ");
	scanf("\n%f", &precioLatam);

	return precioLatam;
}

//Calculamos los costos//

/**
 * @brief calcula todos los costos requeridos con los datos ingresados
 * @return retorna los resultados
 */

float calcularCostos(float precio, float km, int operacion){

	float debito;
	float credito;
	float bitcoin;
	float unitario;
	float resultado;

	switch(operacion){

	case 1:

		debito=precio-(precio*10/100);
		resultado=debito;
		break;

	case 2:

		credito=precio+(precio*25/100);
		resultado=credito;
		break;

	case 3:

		bitcoin=precio/BTC;
		resultado=bitcoin;
		break;

	case 4:

		unitario=precio/km;
		resultado=unitario;
		break;

	default:

		printf("No hay datos ingresados");
		break;
	}

	return resultado;




}

//Calculamos la diferencia de precios//

/**
 * @brief calcula la diferencia de precios entre Latam y Aerolineas
 * @return retorna el resultado
 */

float diferenciaPrecio(float precioLatam, float precioAA){

	float diferenciaPrecio;

	if (precioLatam>precioAA)
	{
		diferenciaPrecio=precioLatam-precioAA;
	}
	else
	{
		diferenciaPrecio=precioAA-precioLatam;
	}

	return diferenciaPrecio;



}

//Mostramos los resultados//

/**
 * @brief mostramos los resultados
 * @param kmIngresados
 * @param precioAA
 * @param debitoAA
 * @param creditoAA
 * @param btcAA
 * @param unitarioAA
 * @param precioLatam
 * @param debitoLatam
 * @param creditoLatam
 * @param btcLatam
 * @param unitarioLatam
 * @param difPrecio
 */

void mostrarCostos(float kmIngresados,float precioAA,float debitoAA, float creditoAA, float btcAA, float unitarioAA,float precioLatam, float debitoLatam, float creditoLatam, float btcLatam, float unitarioLatam, float difPrecio){

	printf("\nKM INGRESADOS: %.2f\n\nPrecio Aerolineas: %.2f\na)Precio con tardeja de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con bitcoin: %.2f\nd)Mostrar precio unitario: $%.2f\n\nPrecio Latam: $%.2f\na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con bitcoin: %.2f\nd)Mostrar precio unitario: $%.2f\n\nLa diferencia de precio es: $%.2f",kmIngresados,precioAA,debitoAA,creditoAA,btcAA,unitarioAA,precioLatam,debitoLatam,creditoLatam,btcLatam,unitarioLatam,difPrecio);
}



