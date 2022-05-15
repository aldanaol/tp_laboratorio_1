/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: Admin
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

int initPassengers(ePassenger[],int);
int addPassenger(ePassenger , int, int, char[],char[],float,char[], int, int);
int findPassengerById(ePassenger[],int,int);
int removePassenger(ePassenger,int,int);
int sortPassengers(ePassenger[],int,int);
int printPassengers(ePassenger[],int);
int sortPassengersByCode(ePassenger[],int,int);





#endif /* ARRAYPASSENGER_H_ */
