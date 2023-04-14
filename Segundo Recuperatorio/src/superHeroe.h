/*
 * superHeroe.h
 *
 *  Created on: 11 ago. 2022
 *      Author: Admin
 */

#ifndef SUPERHEROE_H_
#define SUPERHEROE_H_
#include "Utn.h"
#include "Linkedlist.h"

typedef struct
{
    int id;
    char nombre[4096];
    int idPropietario;
    int power;
    int ataque;

}eSuperHeroe;


eSuperHeroe* SuperHeroe_new();
eSuperHeroe* SuperHeroe_newParametros(	char* idStr,
									char* nombreStr,
									char* idPropietarioStr,
									char* powerStr,
									char* ataqueStr);

void SuperHeroe_delete(eSuperHeroe* this);

int SuperHeroe_setId(eSuperHeroe* this,int id);
int SuperHeroe_getId(eSuperHeroe* this,int* id);

int SuperHeroe_setNombre(eSuperHeroe* this,char* nombre);
int SuperHeroe_getNombre(eSuperHeroe* this,char* nombre);

int SuperHeroe_setIdPropietario(eSuperHeroe* this,int idPropietario);
int SuperHeroe_getIdPropietario(eSuperHeroe* this,int* idPropietario);

int SuperHeroe_setPower(eSuperHeroe* this,int power);
int SuperHeroe_getPower(eSuperHeroe* this,int* power);

int SuperHeroe_setAtaque(eSuperHeroe* this,int ataque);
int SuperHeroe_getAtaque(eSuperHeroe* this,int* ataque);

void SuperHeroe_imprimirSuperHeroe(eSuperHeroe* this);
int SuperHeroe_imprimirTodosLosSuperHeroe(LinkedList* pAarraySuperHeroeList);
int SuperHeroe_compareById(void* p1, void* p2);
LinkedList* SuperHeroe_map(LinkedList* listaSuperHeroe);
int SuperHeroe_mapear(void* elemento);


#endif /* SUPERHEROE_H_ */
