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




