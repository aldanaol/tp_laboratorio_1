/*
 * Computer.h
 *
 *  Created on: 27 jul. 2022
 *      Author: Admin
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_


#include "utn.h"
#include "LinkedList.h"
#define HORA_MAXIMA 250
#define SUELDO_MAXIMO 100000
#define ID_MAXIMO 10000
typedef struct
{
    int id;
    char descripcion[4096];
    float precio;
    int idTipo;
    char oferta[4096];

}eComputer;


eComputer* computer_new();
eComputer* computer_newParametros(	char* idStr,
									char* descripcionStr,
									char* precioStr,
									char* idTipoStr);

void computer_delete(eComputer* this);

int computer_setId(eComputer* this,int id);
int computer_getId(eComputer* this,int* id);

int computer_setDescripcion(eComputer* this,char* descripcion);
int computer_getDescripcion(eComputer* this,char* descripcion);

int computer_setPrecio(eComputer* this,float precio);
int computer_getPrecio(eComputer* this,float* precio);

int computer_setIdTipo(eComputer* this,int idTipo);
int computer_getIdTipo(eComputer* this,int* idTipo);

int computer_setOferta(eComputer* this,char* oferta);
int computer_getOferta(eComputer* this,char* oferta);

void computer_imprimirComputer(eComputer* this);
int computer_imprimirTodosLosComputers(LinkedList* pAarrayComputerList);
int computer_buscarPorId(LinkedList* pAarrayComputerList);
int computer_compareIdComputer(void* argumentoUno, void* argumentoDos);
int computer_filtrarDesktop(void *pComputer);

/*int computer_filtrarMenoresPrecio(void* pElement);
int computer_filtrarCallejeros(void* pElement);
int computer_filtrarMachos(void* pElement);
int cargarListaFiltradaGenero(LinkedList* this);
int imprimirListaFiltradaCallejero(LinkedList* this);
int cargarListaFiltradaMenoresPrecio(LinkedList* this);*/
#endif /* COMPUTER_H_ */
