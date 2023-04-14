/*
 * superHeroe.c
 *
 *  Created on: 11 ago. 2022
 *      Author: Admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "superHeroe.h"
#include "Utn.h"
#include "LinkedList.h"
#include "Parser.h"

static int SuperHeroe_isValidId(int* id);
static int SuperHeroe_isValidNombre(char* nombre);
static int SuperHeroe_isValidIdPropietario(int* idPropietario);
static int SuperHeroe_isValidPower(int* power);
static int SuperHeroe_isValidAtaque(int* ataque);



/**
*\brief Solicita memoria para un bloque de estructura la estructura Participante
*\return Retorna la posicion de memoria a la estructura
*/

eSuperHeroe* SuperHeroe_new()
{
	return malloc(sizeof(eSuperHeroe));
}

/**
*\brief Transforma y establece todos los datos de la estructura con los parametros recibidos
*\param char* idStr id del empleado
*\param char* nombreStr nombre del empleado
*\param char* horasTrabajadasStr cantidad de horas trabajadas del empleado
*\param char* sueldoStr sueldo del empleado
* \return Retorna la posicion de memoria a la estructura
*/
eSuperHeroe* SuperHeroe_newParametros(
                                    char* idStr,
									char* nombreStr,
									char* idPropietarioStr,
									char* powerStr,
									char* ataqueStr)
{
	eSuperHeroe* retorno = NULL;
	eSuperHeroe* this;
	this = SuperHeroe_new();
	int id;
	int idPropietario;
	int power;
	int ataque;


	id = atoi(idStr);
    idPropietario = atoi(idPropietarioStr);
    power = atoi(powerStr);
    ataque=atoi(ataqueStr);

	if(this != NULL)
	{
		if( SuperHeroe_setId(this,id)==0 &&
			SuperHeroe_setNombre(this,nombreStr)==0 &&
			SuperHeroe_setIdPropietario(this,idPropietario)==0 &&
			SuperHeroe_setPower(this,power)==0 &&
			SuperHeroe_setAtaque(this,ataque)==0)
		{
			retorno = this;
		}
		else
		{
			SuperHeroe_delete(this);
		}
	}
	return retorno;
}



/**
*\brief libera el espacio de memoria que ocupaba la estructura de Employee
*\param Employee* this puntero a la estructura Employee
*/
void  SuperHeroe_delete(eSuperHeroe* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
*\brief setea un ID a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

int SuperHeroe_setId(eSuperHeroe* this,int id)
{
	int retorno = -1;
	if(this != NULL && SuperHeroe_isValidId(&id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un ID de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero al que se le pasara el id obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_getId(eSuperHeroe* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Valida que el entero ingresado como id sea numerico
*\param  int id el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int SuperHeroe_isValidId(int* id)
{
     int retorno =-1;
     int i=0;

     if(id != NULL)
     {
        while(id[i] != '\0')
        {
        if(id[i]<'0' || id[i]>'9')
        break;
        i++;
     }
        if(id[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga una descripcion a un elemento de la estructura eComputer
*\param Employee* this puntero a la estructura eComputer
*\param  char* nombre es el string de caracteres que se pasara como nombre
*\return retorna 0 si salio OK -1 si fallo
*/

int SuperHeroe_setNombre(eSuperHeroe* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && SuperHeroe_isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un nombre de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_getNombre(eSuperHeroe* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int SuperHeroe_isValidNombre(char* descripcion)
{
	return 1;
}


/**
*\brief setea las horas trabajadas a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero que se establecera como horas trabajadas para ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_setIdPropietario(eSuperHeroe* this,int idPropietario)
{
	int retorno = -1;
	if(this != NULL && SuperHeroe_isValidIdPropietario(&idPropietario))
	{
		this->idPropietario = idPropietario;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene las horas trabajadas de un elemento de la estructura Employee y se las pasa a una variable
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero al que se le pasaras las horas trabajadas de ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_getIdPropietario(eSuperHeroe* this,int* idPropietario)
{
	int retorno = -1;
	if(this != NULL && idPropietario != NULL)
	{
		*idPropietario = this->idPropietario;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief valida que las horas trabajadas sean numeros validos
*\param  int horasTrabajadas el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int SuperHeroe_isValidIdPropietario(int* idPropietario)
{
	int retorno =-1;
    int i=0;

     if(idPropietario != NULL)
     {
        while(idPropietario[i] != '\0')
        {
        if(idPropietario[i]<'0' || idPropietario[i]>'9')
        break;
        i++;
     }
        if(idPropietario[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief setea un ID a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

int SuperHeroe_setPower(eSuperHeroe* this,int power)
{
	int retorno = -1;
	if(this != NULL && SuperHeroe_isValidPower(&power))
	{
		this->power = power;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un ID de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero al que se le pasara el id obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_getPower(eSuperHeroe* this,int* power)
{
	int retorno = -1;
	if(this != NULL && power != NULL)
	{
		*power = this->power;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Valida que el entero ingresado como id sea numerico
*\param  int id el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int SuperHeroe_isValidPower(int* power)
{
     int retorno =-1;
     int i=0;

     if(power != NULL)
     {
        while(power[i] != '\0')
        {
        if(power[i]<'0' || power[i]>'9')
        break;
        i++;
     }
        if(power[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga una descripcion a un elemento de la estructura eComputer
*\param Employee* this puntero a la estructura eComputer
*\param  char* nombre es el string de caracteres que se pasara como nombre
*\return retorna 0 si salio OK -1 si fallo
*/

int SuperHeroe_setAtaque(eSuperHeroe* this,int ataque)
{
	int retorno = -1;
	if(this != NULL && SuperHeroe_isValidAtaque(&ataque))
	{
		this->ataque = ataque;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un nombre de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int SuperHeroe_getAtaque(eSuperHeroe* this,int* ataque)
{
	int retorno = -1;
	if(this != NULL && ataque != NULL)
	{
		*ataque = this->ataque;
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int SuperHeroe_isValidAtaque(int* ataque)
{

    int retorno =-1;
    int i=0;

    if(ataque != NULL)
    {
       while(ataque[i] != '\0')
       {
       if(ataque[i]<'0' || ataque[i]>'9')
       break;
       i++;
    }
       if(ataque[i] == '\0')
       retorno = 1;
    }

	return retorno;
}




/**
*\brief busca un empleado por ID y devuelve su posicion
*\param void* puntero a la estructura Employee
*\param return la posicion del empleado si salio ok, -1 si fallo
*/
/*int Participante_buscarPorId(LinkedList* pAarrayParticipanteList)
{
    int retorno = -1;
    int id;
    int i;
    eParticipante* auxParticipante;

    Participante_imprimirTodosLosParticipante(pAarrayParticipanteList);
    getInt(&id,"Indique el ID que desea buscar\n","ID INVALIDO",0,ID_MAXIMO,2);

    for(i=0; i<ll_len(pAarrayComputerList); i++)
    {
        auxComputer = ll_get(pAarrayComputerList,i);
        if(auxComputer->id == id)
        {
            retorno = i;
        }
    }

    return retorno;
}*/

/**
*\brief imprime un empleado que se encuentra cargado en la estructura Employee
*\param Employee* this puntero a la estructura Employee
*/
void SuperHeroe_imprimirSuperHeroe(eSuperHeroe* this)
{
    int id;
    char nombre[4096];
    int idPropietario;
    int power;
    int ataque;



    SuperHeroe_getId(this,&id);
    SuperHeroe_getNombre(this,nombre);
    SuperHeroe_getIdPropietario(this,&idPropietario);
    SuperHeroe_getPower(this,&power);
    SuperHeroe_getAtaque(this,&ataque);

    if(idPropietario == 1)
    {
       printf("%d\t %10s\t %15s\t %5d\t %5d\t\n",id,nombre,"DC",power,ataque);
    }
    else
    { if(idPropietario==2) {
    	printf("%d\t %10s\t %15s\t %5d\t %5d\t\n",id,nombre,"MARVEL",power,ataque);
      }

    }


}



/**
*\brief imprime todos los elementos cargados en la lista de la estructura Employee
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
int SuperHeroe_imprimirTodosLosSuperHeroe(LinkedList* pAarraySuperHeroeList)
{
    int retorno = -1;
    int i;
    eSuperHeroe* this;

    if(pAarraySuperHeroeList != NULL)
    {
        printf("%.5s %15s %20s %15s %.15s\n","ID","NOMBRE","PROPIETARIO","POWER","ATAQUE");
        for(i=0 ; i<ll_len(pAarraySuperHeroeList); i++)
        {
            /*if(i%150 == 0 && i != 0)
            {
                system("pause");
            }*/
          this = ll_get(pAarraySuperHeroeList,i);
          SuperHeroe_imprimirSuperHeroe(this);
          retorno = 0;
        }
    }
    return retorno;
}

int SuperHeroe_compareById(void* p1, void* p2)
{
	    eSuperHeroe* superHeroe1;
		eSuperHeroe* superHeroe2;
		int comparacion;
		int id1, id2;
		comparacion = -2;
		superHeroe1 = (eSuperHeroe*) p1;
		superHeroe2 = (eSuperHeroe*) p2;
		if( !(SuperHeroe_getId(superHeroe1, &id1)) &&
			!(SuperHeroe_getId(superHeroe2, &id2)))
		{
			if(id1 > id2)
			{
				comparacion = 1;
			}
			else
			{
				if(id1 < id2)
				{
					comparacion = -1;
				}
				else
				{
					comparacion = 0;
				}
			}
		}
		return comparacion;
}

LinkedList* SuperHeroe_map(LinkedList* listaSuperHeroe)
{
	LinkedList* nuevaLista = NULL;

	if(listaSuperHeroe != NULL)
	{
		nuevaLista = ll_map(listaSuperHeroe,SuperHeroe_mapear);
	}
	return nuevaLista;
}

int SuperHeroe_mapear(void* elemento)
{
	int retorno = -1;
	eSuperHeroe* superHeroe = NULL;
	int power;
	int incrementoPower;
	int ataque;

	if(elemento != NULL)
	{
		superHeroe = (eSuperHeroe*) elemento;
		SuperHeroe_getPower(superHeroe, &power);

		incrementoPower= power*10/100;

		ataque=power+incrementoPower;

		if(!SuperHeroe_setAtaque(superHeroe, ataque))
		{
			retorno = 1;
		}
	}
	return retorno;
}










