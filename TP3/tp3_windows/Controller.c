
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		retorno = parser_PassengerFromText(pFile,pArrayListPassenger);
	}
	fclose(pFile);
	//pFile = NULL;
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pFile;
	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		retorno = parser_PassengerFromBinary(pFile,pArrayListPassenger);
	}
	fclose(pFile);

    return retorno;
}

/** \brief Alta de pasajeross
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int id)
{
    int retorno = -1;
    Passenger* auxPass;

        int idAux;
    	char nombre[50];
    	char apellido[50];
    	float precio;
    	int tipoPasajero;
    	char codigoVuelo[4];
	//int idAux;
	//int largo;

    if(pArrayListPassenger != NULL)
    {
      getString(nombre,"Ingrese el nombre:\n","Dato ingresado incorrecto\n",0,50,2);
      getString(apellido,"Ingrese el apellido:\n","Dato ingresado incorrecto\n",0,50,2);
      getFloat(&precio,"Ingrese el precio:\n","Dato ingresado incorrecto\n",0,1000,2);
      getInt(&tipoPasajero,"Ingrese el tipo de pasajero:\n","Dato ingresado incorrecto\n",0,4,2);
      getString(codigoVuelo,"Ingrese el codigo de vuelo:\n","Dato ingresado incorrecto\n",0,4,2);
      //largo = ll_len(pArrayListEmployee);
      //idAux = largo+1;
      id++;
      idAux=id;

      auxPass = Passenger_newParametros(&idAux,nombre,apellido,&precio,codigoVuelo,&tipoPasajero);

      if(auxPass != NULL)
       {
          ll_add(pArrayListPassenger,auxPass);
          retorno = 0;
       }
    }

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int opcion;
    int index;

    Passenger* auxPassenger;


    if(pArrayListPassenger != NULL)
    {

            printf("--------------INGRESO AL MENU DE MODIFICACION DE DATOS--------------\n\n");
            system("pause");
            index = Passenger_buscarPorId(pArrayListPassenger);

            auxPassenger = ll_get(pArrayListPassenger,index);
            printf("El pasajero seleccionado es:\n");
            Passenger_imprimirPassenger(auxPassenger);
            system("pause");
            do
            {

            system("cls");
            printf(  "1-Modificar el nombre\n"
            		 "2-Modificar el apellido\n"
                     "3-Modificar el precio\n"
                     "4-Modificar el codigo de vuelo\n"
                     "5-Modificar el tipo de pasajero\n"
                     "6-Salir.");

            getInt(&opcion,"Ingrese la opcion a modificar:\n","ERROR OPCION INVALIDA\n",0,4,2);

                switch(opcion)
                {
                case 1:
                	Passenger_modificarNombre(auxPassenger);
                    system("pause");
                    break;
                case 2:
                	Passenger_modificarApellido(auxPassenger);
                    system("pause");
                    break;
                case 3:
                	Passenger_modificarPrecio(auxPassenger);
                    system("pause");
                    break;
                case 4:
                	Passenger_modificarCodigo(auxPassenger);
                	system("pause");
                	break;
                case 5:
                	Passenger_modificarTipo(auxPassenger);
                	system("pause");
                	break;
                case 6:
                	printf("Volviendo al menu principal");
                	break;

                default:
                	printf("Error.Opcion incorrecta");
                	break;
                }
                retorno = 0;
            }while(opcion != 6);

    }

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* this;
    int index;
    char respuesta;


    if(pArrayListPassenger != NULL)
    {
        index = Passenger_buscarPorId(pArrayListPassenger);
        this = ll_get(pArrayListPassenger,index);
        if(this != NULL)
        {
            printf("Dara de baja al pasajero:\n");
            Passenger_imprimirPassenger(this);

            getChar(&respuesta,"Desea continuar con la baja?Ingrese s para continuar\n","CARACTER INVALIDO\n",'s','z',2);
            if(respuesta == 's')
            {
              ll_remove(pArrayListPassenger,index);
              printf("Se dio de baja al pasajero\n");
              system("pause");
              retorno = 0;
            }

        }

    }

    //this = NULL;
    return retorno;
}

/** \brief Listar pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int i;
    Passenger* this;

    if(pArrayListPassenger != NULL)
    {
        printf("%5s %10s %10s %10s %10s %5s %5s\n\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","TIPO DE PASAJERO","STATUS FLIGTH");
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

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int opcion;
    if(pArrayListPassenger != NULL)
    {
        do
        {
            printf("-------------MENU DE ORDENAMIENTO-------------\n"
                   "1-Ordenar por apellido(ascendente)\n"
                   "2-Ordenar por apellido(descendente)\n\n\n"
                   "3-Salir:\n");

            getInt(&opcion,"Seleccione el criterio de orden\n","Opcion invalida\n",1,3,2);
            switch(opcion)
            {
            case 1:
                printf("Procesando...");
                ll_sort(pArrayListPassenger,Passenger_ordenarPorNombre,1);
                opcion = 7;
                break;
            case 2:
                printf("Procesando...");
                ll_sort(pArrayListPassenger,Passenger_ordenarPorNombre,0);
                break;
            case 3:
                printf("Volviendo al menu principal...");
                break;


            }

        }while(opcion!=3);

       retorno = 0;
    }



    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    pFile = fopen(path,"wb");
    Passenger* this;
    int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];

	if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,apellido,precio,tipoPasajero,codigoVuelo\n");
        for(i=0; i<ll_len(pArrayListPassenger); i++)
        {
            this = ll_get(pArrayListPassenger,i);

            Passenger_getId(this,&id);
            Passenger_getNombre(this,nombre);
            Passenger_getApellido(this,apellido);
            Passenger_getPrecio(this,&precio);
            Passenger_getTipoPasajero(this,&tipoPasajero);
            Passenger_getCodigoVuelo(this,codigoVuelo);
            fprintf(pFile,"%d,%s,%s,%f,%d,%s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int i;
    Passenger* this;
    FILE* pFile;
    pFile = fopen(path,"wb");


	if(pFile != NULL)
    {
        for(i=0; i<ll_len(pArrayListPassenger); i++)
        {
            this = ll_get(pArrayListPassenger,i);
            fwrite(this,sizeof(Passenger),1,pFile);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}

