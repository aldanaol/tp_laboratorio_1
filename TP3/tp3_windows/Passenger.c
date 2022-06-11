/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn.h"
#include "LinkedList.h"


static int Passenger_isValidNombre(char* nombre);
static int Passenger_isValidApellido(char* apellido);
static int Passenger_isValidPrecio(float* precio);
static int Passenger_isValidCodigoVuelo(char* codigoVuelo);
static int Passenger_isValidTipoPasajero(int* tipoPasajero);

/**
*\brief Solicita memoria para un bloque de estructura la estructura Passenger
*\return Retorna la posicion de memoria a la estructura
*/

Passenger* Passenger_new()
{
	return malloc(sizeof(Passenger));
}

/**
*\brief Transforma y establece todos los datos de la estructura con los parametros recibidos
*\param char* idStr id del pasajero
*\param char* nombreStr nombre del pasajero
*\param char* apellidoStr apellido del pasajero
*\param float* precioStr precio del vuelo
*\param char* codigoStr codigo del vuelo
*\param int* tipoPasajeroStr tipo de pasajero
* \return Retorna la posicion de memoria a la estructura
*/
Passenger* Passenger_newParametros(int* idStr,char* nombreStr,char* apellidoStr,float* precioStr,char* codigoStr,int* tipoPasajeroStr)
{
	Passenger* retorno = NULL;
	Passenger* this;
	this = Passenger_new();





	if(this != NULL)
	{
		if( Passenger_setId(this,idStr)==0 &&
			Passenger_setNombre(this,nombreStr)==0 &&
			Passenger_setApellido(this,apellidoStr)==0 &&
			Passenger_setPrecio(this,precioStr)==0 &&
			Passenger_setCodigoVuelo(this,codigoStr)==0 &&
			Passenger_setTipoPasajero(this,tipoPasajeroStr)==0 )
		{
			retorno = this;
		}
		else
		{
			Passenger_delete(this);
		}
	}
	return retorno;
}



/**
*\brief libera el espacio de memoria que ocupaba la estructura de Passenger
*\param Passenger* this puntero a la estructura Passenger
*/
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
*\brief setea un ID a un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

int Passenger_setId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id = *id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un ID de un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  int id el entero al que se le pasara el id obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getId(Passenger* this,int* id)
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
*\brief carga un nombre a un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  char* nombre es el string de caracteres que se pasara como nombre
*\return retorna 0 si salio OK -1 si fallo
*/

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && Passenger_isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un nombre de un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getNombre(Passenger* this,char* nombre)
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
*\brief valida un nombre de un elemento de la estructura Passenger
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int Passenger_isValidNombre(char* nombre)
{
	return 1;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && Passenger_isValidApellido(apellido))
	{
		strcpy(this->apellido,apellido);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un nombre de un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Passenger
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int Passenger_isValidApellido(char* apellido)
{
	return 1;
}


/**
*\brief setea el precio a un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  float* precio el entero que se establecera como precio para ese precio
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_setPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && Passenger_isValidPrecio(precio))
	{
		this->precio = *precio;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene el precio de un elemento de la estructura Passenger y se las pasa a una variable
*\param Passenger* this puntero a la estructura Passenger
*\param  float precio el entero al que se le pasaras el precio
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief valida que el precio sean numeros validos
*\param  int precio el float que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int Passenger_isValidPrecio(float* precio)
{
	int retorno =-1;
    int i=0;

     if(precio != NULL)
     {
        while(precio[i] != '\0')
        {
        if(precio[i]<'0' || precio[i]>'9')
        break;
        i++;
     }
        if(precio[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga un codigo a un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  char codigoVuelo  es el codigo que se cargara al elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
		if(this != NULL && Passenger_isValidCodigoVuelo(codigoVuelo))
		{
			strcpy(this->codigoVuelo,codigoVuelo);
			retorno = 0;
		}
		return retorno;
}

/**
*\brief obtine un codigo de vuelo de un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  char codigoVuelo es el codigo al que se le cargara el codigo del elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief valida que el codigo sea un char valido
*\param  char es el codigo es el elemento que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int Passenger_isValidCodigoVuelo(char* codigoVuelo)
{


	return 1;
}


/**
*\brief setea un tipo de pasajero a un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  int tipoPasajero el entero que se establecera como tipoPasajero
*\return retorna 0 si salio OK -1 si fallo
*/

int Passenger_setTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && Passenger_isValidTipoPasajero(tipoPasajero))
	{
		this->tipoPasajero = *tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un tipoPasajero de un elemento de la estructura Passenger
*\param Passenger* this puntero a la estructura Passenger
*\param  int tipoPasajero el entero al que se le pasara el tipoPasajero obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Valida que el entero ingresado como tipoPasajero sea numerico
*\param  int tipoPasajero el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int Passenger_isValidTipoPasajero(int* tipoPasajero)
{
     int retorno =-1;
     int i=0;

     if(tipoPasajero != NULL)
     {
        while(tipoPasajero[i] != '\0')
        {
        if(tipoPasajero[i]<'0' || tipoPasajero[i]>'9')
        break;
        i++;
     }
        if(tipoPasajero[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

void Passenger_imprimirPassenger(Passenger* this)
{

    int id;
    char nombre[QTY_CARACTERES];
    char apellido[QTY_CARACTERES];
    float precio;
    char codigoVuelo[4];
    int tipoPasajero;

    Passenger_getId(this,&id);
    Passenger_getNombre(this,nombre);
    Passenger_getApellido(this,apellido);
    Passenger_getPrecio(this,&precio);
    Passenger_getCodigoVuelo(this,codigoVuelo);
    Passenger_getTipoPasajero(this,&tipoPasajero);

    printf("%5d %10s %10s %10f %10s %5d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero);

}

/**
*\brief compara los nombres de 2 pasajeros de la estructura Passenger
*\param void* puntero a un pasajero de la estructura Passenger
*\param void* puntero a un segundo pasajero de la estructura Passenger
*\param return retorna 0 si los 2 pasajero tienen el mismo nombre
*\param return retorna <0 si el nombre del primer pasajero esta antes que el del segundo pasajero
*\param return retorna >0 si el nombre del primer pasajero esta despues que el del segundo pasajero
*/

int Passenger_ordenarPorNombre(void* pasajeroUno, void* pasajeroDos)
{
	Passenger* psUno;
	Passenger* psDos;

    psUno = (Passenger*)pasajeroUno;
    psDos = (Passenger*)pasajeroDos;
    return  strcmp(psUno->nombre,psDos->nombre);

}

/**
*\brief compara los nombres de 2 pasajeros de la estructura Passenger
*\param void* puntero a un pasajero de la estructura Passenger
*\param void* puntero a un segundo pasajero de la estructura Passenger
*\param return retorna 0 si los 2 pasajeros tienen el mismo codigo
*\param return retorna 1 si el primer pasajero tiene un codigo menor  que el segundo pasajero
*\param return retorna -1 si el primer pasajero tiene un codigo mayor que el segundo pasajero
*/
int Passenger_ordenarPorCodigo(void* pasajeroUno, void* pasajeroDos)
{
    int retorno = -1;
    Passenger* psUno;
    Passenger* psDos;

    psUno = (Passenger*)pasajeroUno;
    psDos = (Passenger*)pasajeroDos;
    if(psUno->codigoVuelo < psDos->codigoVuelo)
    {
        retorno = 1;
    }
    else if(psUno->codigoVuelo == psDos->codigoVuelo)
    {
        retorno = 0;
    }
    return retorno;
}


int Passanger_ordenarPorTipo(void* pasajeroUno, void* pasajeroDos)
{
    int retorno = -1;
    Passenger* psUno;
    Passenger* psDos;

    psUno = (Passenger*)pasajeroUno;
    psDos = (Passenger*)pasajeroDos;
    if(psUno->tipoPasajero < psDos->tipoPasajero)
    {
        retorno = 1;
    }
    else if(psUno->tipoPasajero == psDos->tipoPasajero)
    {
        retorno = 0;
    }
    return retorno;

}

/**
*\brief menu de modificacion de los parametros cargados de un pasajero
*\param void* puntero a la lista cargada con la estructura Passenger
*\param return void
*/
void passenger_menuModificacion(LinkedList* pArrayListPassenger)
{
    int opcion;
    int index;
    Passenger* auxPassenger;


    if(pArrayListPassenger != NULL)
    {
            printf("--------------INGRESO AL MENU DE MODIFICACION DE DATOS--------------\n\n");
            system("pause");
            index = Passenger_buscarPorId(pArrayListPassenger);
            auxPassenger = ll_get(pArrayListPassenger,index);
            system("pause");
            Passenger_imprimirPassenger(auxPassenger);
            printf(  "1-Modificar el nombre\n"
            		 "2-Modificar el apellido\n"
                     "3-Modificar el precio\n"
                     "4-Modificar el codigo de vuelo\n"
            		 "5-Modificar el tipo de pasajero\n"
                     "6-Salir\n");

            getInt(&opcion,"Ingrese la opcion a modificar:\n","ERROR OPCION INVALIDA\n",1,4,2);
            do
            {
                switch(opcion)
                {
                case 1:
                	Passenger_modificarNombre(auxPassenger);
                    break;
                case 2:
                	Passenger_modificarNombre(auxPassenger);
                    break;
                case 3:
                	Passenger_modificarPrecio(auxPassenger);
                    break;
                case 4:
                	Passenger_modificarCodigo(auxPassenger);
                	break;
                case 5:
                	Passenger_modificarTipo(auxPassenger);
                	break;
                case 6:
                	printf("Volviendo al menu principal");
                	break;
                default:
                	printf("Opcion incorrecta");
                	break;
                }

            }while(opcion != 6);

    }

}

/**
*\brief menu de modificacion del nombre cargado de un pasajero
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_modificarNombre(Passenger* this)
{
	int retorno = -1;
	Passenger auxPassenger;
	char respuesta;

	    getString(auxPassenger.nombre,"Ingrese el nuevo nombre:\n","INGRESO INVALIDO\n",0,QTY_CARACTERES,2);
	    getChar(&respuesta,"Desea modificar el nombre? Ingrese S para modificar\n","NOMBRE INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            strncpy(this->nombre,auxPassenger.nombre,QTY_CARACTERES);
            //Passenger_setNombre(this,auxEmpleado.nombre);
            printf("Se modifico el nombre correctamente\n");
            retorno = 0;
        }
	return retorno;
}

/**
*\brief menu de modificacion del apellido cargado de un pasajero
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_modificarApellido(Passenger* this)
{
	int retorno = -1;
	Passenger auxPassenger;
	char respuesta;

	    getString(auxPassenger.apellido,"Ingrese el nuevo apellido:\n","INGRESO INVALIDO\n",0,QTY_CARACTERES,2);
	    getChar(&respuesta,"Desea modificar el apellido? Ingrese S para modificar\n","NOMBRE INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            strncpy(this->apellido,auxPassenger.apellido,QTY_CARACTERES);
            //Passenger_setApellido(this,auxPassenger.Apellido);
            printf("Se modifico el apellido correctamente\n");
            retorno = 0;
        }
	return retorno;
}

/**
*\brief menu de modificacion del precio cargado
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_modificarPrecio(Passenger* this)
{
	int retorno = -1;
	Passenger auxPassenger;
	char respuesta;
	if(this != NULL)
	{
	    getFloat(&auxPassenger.precio,"Ingrese el nuevo precio:\n","INGRESO INVALIDO\n",0,100000,2);
	    getChar(&respuesta,"Desea modificar el precio? Ingrese S para modificar\n","PRECIO INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            this->precio = auxPassenger.precio;
            printf("Se modifico el precio correctamente\n");
            retorno = 0;
        }

	}

	return retorno;
}
/**
*\brief menu de modificacion de codigo cargado
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_modificarCodigo(Passenger* this)
{
	int retorno = -1;
	Passenger auxPassenger;
	char respuesta;

	    getString(auxPassenger.codigoVuelo,"Ingrese el nuevo codigo:\n","INGRESO INVALIDO\n",0,4,2);
	    getChar(&respuesta,"Desea modificar el codigo? Ingrese S para modificar\n","CODIGO INVALIDO\n",0,4,2);
	    if(respuesta == 's')
        {
            strncpy(this->codigoVuelo,auxPassenger.codigoVuelo,4);

            printf("Se modifico el codigo correctamente\n");
            retorno = 0;
        }
	return retorno;
}


/**
*\brief menu de modificacion del tipo de pasajero
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_modificarTipo(Passenger* this)
{
	int retorno = -1;
	Passenger auxPassenger;
	char respuesta;
	if(this != NULL)
	{
	    getInt(&auxPassenger.tipoPasajero,"Ingrese el tipo de pasajero:\n","INGRESO INVALIDO\n",1,3,2);
	    getChar(&respuesta,"Desea modificar el tipo de pasajero? Ingrese S para modificar\n","INGRESO INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            this->tipoPasajero = auxPassenger.tipoPasajero;
            printf("Se modifico el tipo de pasajero\n");
            retorno = 0;
        }

	}

	return retorno;
}
/**
*\brief imprime todos los elementos cargados en la lista de la estructura Passenger
*\param void* puntero a la estructura Passenger
*\param return 0 si salio ok, -1 si fallo
*/
int Passenger_imprimirTodosLosPasajeros(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int i;
    Passenger* this;

    if(pArrayListPassenger != NULL)
    {
        printf("%5s %10s %10s %10s %10s %5s %5s \n\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO","TIPO PASAJERO","STATUS FLIGHT");
        for(i=0 ; i<ll_len(pArrayListPassenger); i++)
        {
            if(i%150 == 0 && i != 0)
            {
                system("pause");
            }
          this = ll_get(pArrayListPassenger,i);
          Passenger_imprimirPassenger(this);
          retorno = 0;
        }
    }
    return retorno;
}



/**
*\brief busca un pasajero por ID y devuelve su posicion
*\param void* puntero a la estructura Passenger
*\param return la posicion del empleado si salio ok, -1 si fallo
*/
int Passenger_buscarPorId(LinkedList* pAarrayPassengerList)
{
    int retorno = -1;
    int id;
    int i;
    Passenger* auxPassenger;

    Passenger_imprimirTodosLosPasajeros(pAarrayPassengerList);
    getInt(&id,"Indique el ID que desea modificar\n","ID INVALIDO",0,ID_MAXIMO,2);

    for(i=0; i<ll_len(pAarrayPassengerList); i++)
    {
        auxPassenger = ll_get(pAarrayPassengerList,i);
        if(auxPassenger->id == id)
        {
            retorno = i;
        }
    }

    return retorno;
}


