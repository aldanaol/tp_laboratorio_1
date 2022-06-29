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

int PedirNumero(char mensaje[],char mensajeError[],int min,int max){

	int numero;

	printf(mensaje);
	scanf("\n%d", &numero);

	while(numero<min || numero>max){
		printf(mensajeError);
		scanf("%d",&numero);
	}
	return numero;
}
