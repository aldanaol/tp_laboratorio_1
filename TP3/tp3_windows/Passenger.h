/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"
#define ID_MAXIMO 1000
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int statusFligth;

}Passenger;

Passenger* Passenger_new();//
Passenger* Passenger_newParametros(int* idStr,char* nombreStr,char* apellidoStr,float* precioStr,char* codigoStr,int* tipoPasajeroStr);
void Passenger_delete();//

int Passenger_setId(Passenger* this,int* id);//
int Passenger_getId(Passenger* this,int* id);//

int Passenger_setNombre(Passenger* this,char* nombre);//
int Passenger_getNombre(Passenger* this,char* nombre);//

int Passenger_setApellido(Passenger* this,char* apellido);//
int Passenger_getApellido(Passenger* this,char* apellido);//

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);//
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);//

int Passenger_setTipoPasajero(Passenger* this,int* tipoPasajero);//
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);//

int Passenger_setPrecio(Passenger* this,float* precio);//
int Passenger_getPrecio(Passenger* this,float* precio);//
void Passenger_imprimirPassenger(Passenger* this);
int Passenger_ordenarPorNombre(void* pasajeroUno, void* pasajeroDos);
int Passenger_ordenarPorCodigo(void* pasajeroUno, void* pasajeroDos);
int Passanger_ordenarPorTipo(void* pasajeroUno, void* pasajeroDos);
void passenger_menuModificacion(LinkedList* pArrayListPassenger);
int Passenger_modificarNombre(Passenger* this);
int Passenger_modificarApellido(Passenger* this);
int Passenger_modificarPrecio(Passenger* this);
int Passenger_modificarCodigo(Passenger* this);
int Passenger_modificarTipo(Passenger* this);
int Passenger_buscarPorId(LinkedList* pArrayListPassenger);
int Passenger_imprimirTodosLosPasajeros(LinkedList* pArrayListPassenger);



#endif /* PASSENGER_H_ */



