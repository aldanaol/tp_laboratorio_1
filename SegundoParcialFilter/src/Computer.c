/*
 * Computer.c
 *
 *  Created on: 27 jul. 2022
 *      Author: Admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Computer.h"
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"

static int computer_isValidId(int* id);
static int computer_isValidDescripcion(char* descripcion);
static int computer_isValidPrecio(float* precio);
static int computer_isValidIdTipo(int* idTipo);
static int computer_isValidOferta(char* oferta);



/**
*\brief Solicita memoria para un bloque de estructura la estructura Employee
*\return Retorna la posicion de memoria a la estructura
*/

eComputer* computer_new()
{
	return malloc(sizeof(eComputer));
}

/**
*\brief Transforma y establece todos los datos de la estructura con los parametros recibidos
*\param char* idStr id del empleado
*\param char* nombreStr nombre del empleado
*\param char* horasTrabajadasStr cantidad de horas trabajadas del empleado
*\param char* sueldoStr sueldo del empleado
* \return Retorna la posicion de memoria a la estructura
*/
eComputer* computer_newParametros(
                                    char* idStr,
									char* descripcionStr,
									char* precioStr,
									char* idTipoStr)
{
	eComputer* retorno = NULL;
	eComputer* this;
	this = computer_new();
	int id;
	float precio;
	int idTipo;


	id = atoi(idStr);
	precio = atof(precioStr);
    idTipo = atoi(idTipoStr);

	if(this != NULL)
	{
		if( computer_setId(this,id)==0 &&
			computer_setDescripcion(this,descripcionStr)==0 &&
			computer_setPrecio(this,precio)==0 &&
			computer_setIdTipo(this,idTipo)==0)
		{
			retorno = this;
		}
		else
		{
			computer_delete(this);
		}
	}
	return retorno;
}



/**
*\brief libera el espacio de memoria que ocupaba la estructura de Employee
*\param Employee* this puntero a la estructura Employee
*/
void computer_delete(eComputer* this)
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

int computer_setId(eComputer* this,int id)
{
	int retorno = -1;
	if(this != NULL && computer_isValidId(&id))
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
int computer_getId(eComputer* this,int* id)
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
static int computer_isValidId(int* id)
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

int computer_setDescripcion(eComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && computer_isValidDescripcion(descripcion))
	{
		strcpy(this->descripcion,descripcion);
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
int computer_getDescripcion(eComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int computer_isValidDescripcion(char* descripcion)
{
	return 1;
}


/**
*\brief setea las horas trabajadas a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero que se establecera como horas trabajadas para ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
int computer_setPrecio(eComputer* this,float precio)
{
	int retorno = -1;
	if(this != NULL && computer_isValidPrecio(&precio))
	{
		this->precio = precio;
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
int computer_getPrecio(eComputer* this,float* precio)
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
*\brief valida que las horas trabajadas sean numeros validos
*\param  int horasTrabajadas el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int computer_isValidPrecio(float* precio)
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
*\brief setea un ID a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

int computer_setIdTipo(eComputer* this,int idTipo)
{
	int retorno = -1;
	if(this != NULL && computer_isValidIdTipo(&idTipo))
	{
		this->idTipo = idTipo;
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
int computer_getIdTipo(eComputer* this,int* idTipo)
{
	int retorno = -1;
	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Valida que el entero ingresado como id sea numerico
*\param  int id el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int computer_isValidIdTipo(int* idTipo)
{
     int retorno =-1;
     int i=0;

     if(idTipo != NULL)
     {
        while(idTipo[i] != '\0')
        {
        if(idTipo[i]<'0' || idTipo[i]>'9')
        break;
        i++;
     }
        if(idTipo[i] == '\0')
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

int computer_setOferta(eComputer* this,char* oferta)
{
	int retorno = -1;
	if(this != NULL && computer_isValidOferta(oferta))
	{
		strcpy(this->oferta,oferta);
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
int computer_getOferta(eComputer* this,char* oferta)
{
	int retorno = -1;
	if(this != NULL && oferta != NULL)
	{
		strcpy(oferta,this->oferta);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int computer_isValidOferta(char* oferta)
{
	return 1;
}




/**
*\brief busca un empleado por ID y devuelve su posicion
*\param void* puntero a la estructura Employee
*\param return la posicion del empleado si salio ok, -1 si fallo
*/
int computer_buscarPorId(LinkedList* pAarrayComputerList)
{
    int retorno = -1;
    int id;
    int i;
    eComputer* auxComputer;

    computer_imprimirTodosLosComputers(pAarrayComputerList);
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
}

/**
*\brief imprime un empleado que se encuentra cargado en la estructura Employee
*\param Employee* this puntero a la estructura Employee
*/
void computer_imprimirComputer(eComputer* this)
{
    int id;
    char descripcion[4096];
    float precio;
    int idTipo;
    //char oferta[4096];


    computer_getId(this,&id);
    computer_getDescripcion(this,descripcion);
    computer_getPrecio(this,&precio);
    computer_getIdTipo(this,&idTipo);
    //computer_getOferta(this,oferta);

    if(idTipo == 1)
    {
       printf("%5d %.15s %.2f %.10s\n",id,descripcion,precio,"DESKTOP");
    }
    else
    {
       printf("%5d %.15s %.2f %.10s\n",id,descripcion,precio,"LAPTOP");
    }

}



/**
*\brief imprime todos los elementos cargados en la lista de la estructura Employee
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
int computer_imprimirTodosLosComputers(LinkedList* pAarrayComputerList)
{
    int retorno = -1;
    int i;
    eComputer* this;

    if(pAarrayComputerList != NULL)
    {
        printf("%.5s %15s %10s %10s\n","ID","DESCRIPCION","PRECIO","TIPO");
        for(i=0 ; i<ll_len(pAarrayComputerList); i++)
        {
            /*if(i%150 == 0 && i != 0)
            {
                system("pause");
            }*/
          this = ll_get(pAarrayComputerList,i);
          computer_imprimirComputer(this);
          retorno = 0;
        }
    }
    return retorno;
}

int computer_compareIdComputer(void* argumentoUno, void* argumentoDos)
{
    int retorno = -1;
    eComputer* computerUno;
    eComputer* computerDos;

    computerUno=(eComputer*) argumentoUno;
    computerDos=(eComputer*) argumentoDos;

    if(computerUno->idTipo > computerDos->idTipo)
    {
        retorno = 1;
    }
    else if(computerUno->idTipo == computerDos->idTipo)
    {
        retorno = 0;
    }

    return retorno;

}


int computer_filtrarDesktop(void *pComputer)
{
    int retorno = -1;
    eComputer* auxComputer;

    if(pComputer != NULL)
    {
        retorno = 0;
        auxComputer = (eComputer*) pComputer;

        if(auxComputer->idTipo == 1)
        {
            retorno = 1;
        }
    }

    return retorno;

}



/*int computer_filtrarMenoresDias(void* pElement)
{
	int retorno = -1;
	computer* auxcomputer;
	auxcomputer = (computer*)pElement;
	if(auxcomputer->dias > 45)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
int computer_filtrarMachos(void* pElement)
{
	int retorno = -1;
	computer* auxcomputer;
    char genero;
	if(pElement != NULL)
    {
        auxcomputer = (computer*) pElement;
        computer_getGenero(auxcomputer,&genero);
        if(genero == 'H')
        {
            retorno = 1;
        }
            else
            {
                retorno = 0;
            }
    }
	return retorno;
}
int computer_filtrarCallejeros(void* pElement)
{
	int retorno = -1;
    computer* auxcomputer;
    if(pElement != NULL)
    {
        auxcomputer = (computer*)pElement;
        if(strcmp(auxcomputer->raza,"Callejero")==0)
        {
            retorno = 1;
        }
        else
        {
          retorno = 0;
        }
    }
	return retorno;
}
int cargarListaFiltradaGenero(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaMachos;
    //computer* auxcomputer;
    //int i;
    if(this != NULL)
    {
       listaMachos = ll_filter(this,computer_filtrarMachos);
       if(listaMachos != NULL)
       {
           saveArchivo("Solo machos",listaMachos);
           for(i=0; i<ll_len(listaMachos); i++)
           {
               auxcomputer = ll_get(listaMachos,i);
               computer_imprimircomputer(auxcomputer);
               retorno = 0;
           }
       }
    }
    return retorno;
}
int imprimirListaFiltradaCallejero(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaCallejero;
    computer* auxcomputer;
    int i;
    if(this != NULL)
    {
       listaCallejero = ll_filter(this,computer_filtrarCallejeros);
       if(listaCallejero != NULL)
       {
           printf("%5s %10s %10s %10s %10s %10s\n","ID","NOMBRE","DIAS","RAZA","RESERVADO","GENERO");
           for(i=0; i<ll_len(listaCallejero); i++)
           {
               auxcomputer = ll_get(listaCallejero,i);
               computer_imprimircomputer(auxcomputer);
               retorno = 0;
           }
       }
    }
    return retorno;
}
int cargarListaFiltradaMenoresDias(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaMenoresDias;
    //computer* auxcomputer;
    //int i;
    if(this != NULL)
    {
       listaMenoresDias = ll_filter(this,computer_filtrarMenoresDias);
       if(listaMenoresDias != NULL)
       {
           saveArchivo("Menores dias",listaMenoresDias);
           for(i=0; i<ll_len(listaMenoresDias); i++)
           {
               auxcomputer = ll_get(listaMenoresDias,i);
               computer_imprimircomputer(auxcomputer);
               retorno = 0;
           }
       }
    }
    return retorno;
}*/
