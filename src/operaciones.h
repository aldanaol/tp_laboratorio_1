/*
 * operaciones.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Olivera Aldana
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

float pedirKm();
float pedirPrecioAA();
float pedirPrecioLatam();
float calcularCostos(float km, float precio, int operacion );
float diferenciaPrecio(float precioLatam, float precioAA);
void mostrarCostos(float kmIngresados,float precioAA,float debitoAA, float creditoAA, float btcAA, float unitarioAA,float precioLatam, float debitoLatam, float creditoLatam, float btcLatam, float unitarioLatam, float difPrecio);



#endif /* OPERACIONES_H_ */
