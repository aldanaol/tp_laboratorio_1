/*
 * ArrayPassengerAux.h
 *
 *  Created on: 14 may. 2022
 *      Author: Admin
 */

#ifndef ARRAYPASSENGERAUX_H_
#define ARRAYPASSENGERAUX_H_

int menu( char[]);
ePassenger PassengerAux(int,int);
ePassenger lowLogic(ePassenger, int,int);
void printOnePassenger(ePassenger);
ePassenger ModifyPassanger(ePassenger);
void Informar(float, int,int, ePassenger[]);
void forcedLoad(ePassenger[],int cant);

#endif /* ARRAYPASSENGERAUX_H_ */
