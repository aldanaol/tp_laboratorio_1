/*
 * Utn_Get.c
 *
 *  Created on: 29 jun. 2022
 *      Author: Admin
 */

float PedirFloat(char mensaje[],char mensajeError[],int min,int max){

	float numero;

	printf(mensaje);
	scanf("\n%f", &numero);

	while(numero<min || numero>max){
		printf(mensajeError);
		scanf("%f",&numero);
	}

	return numero;


}
