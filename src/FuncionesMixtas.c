/*
 * FuncionesMixtas.c
 *
 *  Created on: 1 ago. 2022
 *      Author: UGIO
 */

#include "funcionesMixtas.h"

void funcionesMixtas_MostrarUnPasajero(int id,char* nombre, char* apellido, float precio,char* codigoDeVuelo, int tipoDeVuelo, int estadoDeVuelo, LinkedList* listaTipo, LinkedList* listaEstado)
{
	char tipoVueloSTR[30];
	char estadoVueloSTR[30];

	tipoVuelo_pasarAString(tipoDeVuelo, tipoVueloSTR, listaTipo);
	estadoVuelo_pasarAString(estadoDeVuelo, estadoVueloSTR, listaEstado);

	printf("| %4d  | %-30s  | %-30s  | %-10.2f  | %-25s| %-30s  | %-30s  |\n",id, nombre, apellido, precio, codigoDeVuelo, tipoVueloSTR,estadoVueloSTR);
}

int funcionesMixtas_MostrarLista(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;
	int tam;

	int id;
	char nombre[25];
	char apellido[30];
	float precio;
	char codigoVuelo[30];
	int tipoDeVuelo;
	int estadoDeVuelo;

	tam = ll_len(listaMain);

	ePasajero* pasajero = NULL;

	printf(" ____________________________________________________________________________________________________________________________________________________________\n");
	printf("| ID    | NOMBRE                                              | APELLIDO                                            | PRECIO      | EDITORIAL                | \n");
	printf("|_______|_____________________________________________________|_____________________________________________________|_____________|__________________________|\n");
	for(int i = 0 ; i < tam ; i++)
	{
		pasajero = ll_get(listaMain, i);

		if(pasajero_GetId(&id, pasajero) == 0
				&& pasajero_GetNombre(nombre, pasajero) == 0
				&& pasajero_GetApellido(apellido, pasajero) == 0
				&& pasajero_GetPrecio(&precio, pasajero) == 0
				&& pasajero_GetCodigoDeVuelo(codigoVuelo, pasajero) == 0
				&& pasajero_GetTipoDeVuelo(&tipoDeVuelo, pasajero) == 0
				&& pasajero_GetEstadoDeVuelo(&estadoDeVuelo, pasajero) == 0)
		{
				funcionesMixtas_MostrarUnPasajero(id, nombre, apellido, precio, codigoVuelo, tipoDeVuelo, estadoDeVuelo,listaTipo, listaEstado);

		}
		retorno = 0;
	}

	return retorno;
}


int funcionesMixtas_modificar(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado, int id)
{
	int retorno = -1;
	int opcion;
	//int validacion = 0;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoDeVuelo[30];

	int auxiliarInt;

	ePasajero* pasajero = NULL;
	ePasajero pasajeroAux;

	 pasajero = ll_get(listaMain, id);

	 pasajeroAux = *pasajero;

	 funcionesMixtas_MostrarUnPasajero(pasajeroAux.id, pasajeroAux.nombre, pasajeroAux.apellido, pasajeroAux.precio, pasajeroAux.codigoVuelo,pasajero->tipoDeVuelo, pasajeroAux.estadoDeVuelo, listaTipo, listaEstado);
	system("pause");
	 do
	{
		printf("\n ingrese la opcion que desea modificar:\n"
				"1-Nombre\n"
				"2-Apellido\n"
				"3-Precio\n"
				"4-Codigo De Vuelo\n"
				"5-Tipo De Vuelo\n"
				"6-Estado De Vuelo\n"
				"7-Salir\n\t->");
		fflush(stdout);
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			printf("ingrese el NUEVO nombre:");
			fflush(stdout);
			scanf("%s",nombre);

			strcpy(pasajeroAux.nombre,nombre);

			break;
		case 2:
			printf("ingrese el NUEVO apellido:");
			fflush(stdout);
			scanf("%s",apellido);

			strcpy(pasajeroAux.apellido,apellido);
			break;
		case 3:
			if(getFloat(&precio, "ingrese el NUEVO precio del vuelo:", "", 0, 100000000) == 0)
			{
				pasajeroAux.precio = precio;
			}
			break;
		case 4:
			printf("ingrese el NUEVO codigo de vuelo:");
			fflush(stdout);
			scanf("%s",codigoDeVuelo);

			strcpy(pasajeroAux.codigoVuelo,codigoDeVuelo);

			break;
		case 5:
			auxiliarInt = getInt("ingrese NUEVO tipo de vuelo:\n"
					"1-FirstClass\n"
					"2-ExecutiveClass\n"
					"3-EconomyClass\n\t->", 0, 5, 5);

			pasajeroAux.tipoDeVuelo = auxiliarInt;
			break;
		case 6:
			auxiliarInt = getInt("ingrese NUEVO estado de vuelo:\n"
					"1-Aterrizado\n"
					"2-En Horario\n"
					"3-En Vuelo\n"
					"4-Demorado\n", 0, 5, 5);

				pasajeroAux.estadoDeVuelo = auxiliarInt;
			break;
		}
	}while(opcion != 7);
	 funcionesMixtas_MostrarUnPasajero(pasajeroAux.id, pasajeroAux.nombre, pasajeroAux.apellido, pasajeroAux.precio, pasajeroAux.codigoVuelo, pasajeroAux.tipoDeVuelo, pasajeroAux.estadoDeVuelo, listaTipo, listaEstado);
	 funcionesMixtas_MostrarUnPasajero(pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoVuelo, pasajero->tipoDeVuelo, pasajero->estadoDeVuelo, listaTipo, listaEstado);

	pasajero = &pasajeroAux;
	ll_set(listaMain, id, pasajero);

	 funcionesMixtas_MostrarUnPasajero(pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoVuelo, pasajero->tipoDeVuelo, pasajero->estadoDeVuelo, listaTipo, listaEstado);
	 system("pause");

	 return retorno;
}


int funcionesMixtas_ordenar(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;
	int (*pfunc)(void*, void*);
	int opcion;

	if(ll_isEmpty(listaMain) == 0 && ll_isEmpty(listaEstado) == 0 && ll_isEmpty(listaTipo) == 0)
	{
		opcion = getInt("ordenar por:\n"
				"1-ID\n"
				"2-Nombre\n"
				"3-Apellido\n"
				"4-Precio\n"
				"5-Codigo\n"
				"6-tipo\n"
				"7-Estado\n"
				"8-Salir\n\t->", 0, 9, 5);
		switch(opcion)
		{
		case 1:
			pfunc = pasajero_ordenarPorId;
			break;
		case 2:
			pfunc = pasajero_ordenarPorNombre;
			break;
		case 3:
			pfunc = pasajero_ordenarPorApellido;
			break;
		case 4:
			pfunc = pasajero_ordenarPorPrecio;
			break;
		case 5:
			pfunc = pasajero_ordenarPorCodigo;
			break;
		case 6:
			pfunc = pasajero_ordenarPorTipo;
			break;
		case 7:
			pfunc = pasajero_ordenarPorEstado;
			break;
		default:
			break;
		}
		if(ll_sort(listaMain, pfunc, 1) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}


int funcionesMixtas_DarDeBaja(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int validacion;
	int idIngresada;
	int remove;

	char nombre[30];
	char apellido[30];
	float precio;
	char codigoDeVuelo[30];
	int tipoDeVuelo;
	int estadoDeVuelo;

	int retorno = -1;
	int bucle = 0;
	int idAux;
	remove = -1;

	ePasajero* pasajero = NULL;

	funcionesMixtas_MostrarLista(listaMain,listaEstado,listaTipo);

	printf("ingrese el ID del pasajero que desea modificar\t");
	scanf("%d",&idIngresada);
	idAux = idIngresada-1;
	pasajero = ll_get(listaMain, idAux);

	do
	{
		printf("\n\tQuiere dar de baja el siguiente pasajero?\n");

		pasajero_GetNombre(nombre, pasajero);
		pasajero_GetApellido(apellido, pasajero);
		pasajero_GetPrecio(&precio, pasajero);
		pasajero_GetCodigoDeVuelo(codigoDeVuelo, pasajero);
		pasajero_GetTipoDeVuelo(&tipoDeVuelo, pasajero);
		pasajero_GetEstadoDeVuelo(&estadoDeVuelo, pasajero);

		funcionesMixtas_MostrarUnPasajero(idIngresada, nombre, apellido, precio, codigoDeVuelo, tipoDeVuelo, estadoDeVuelo, listaTipo, listaEstado);

		printf("1- SI\n"
				"2- NO\n"
				"3- SALIR\n\t->");
		scanf("%d",&validacion);

		switch(validacion)
		{
		case 1:
			remove = ll_remove(listaMain,idAux);

			if(remove != 0)
			{
				printf("ERROR al intentar dar de baja el pasajero\n");
			}
			bucle = 0;
			break;
		case 2:
			printf("Se han descartados los cambios\n");
			bucle = 0;
			break;
		default:
			printf("ERROR,ingrese una opcion correcta:\n");
			bucle = 1;
			break;
		}
		retorno = 0;
	}while(bucle > 0);

	return retorno;
}


int funcionesMixtas_darDeAlta(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado)
{
	int retorno = -1;
	int opcion;
/*
	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoDeVuelo[30];
	int tipoDeVuelo;
	int estadoDeVuelo;

	char tipoDeVueloSTR[30];
	char estadoDeVueloSTR[30];*/

	ePasajero* pasajero = NULL;
	ePasajero pasajeroAux;

	pasajero = pasajero_new();

	printf("ingrese nombre:\n");
	fflush(stdout);
	scanf("%s",pasajeroAux.nombre);

	printf("ingrese apellido:\n");
	fflush(stdout);
	scanf("%s",pasajeroAux.apellido);

	printf("ingrese precio:\n");
	fflush(stdout);
	scanf("%f",&pasajeroAux.precio);

	printf("ingrese codigo de vuelo:\n");
	fflush(stdout);
	scanf("%s",pasajeroAux.codigoVuelo);

	pasajeroAux.tipoDeVuelo = getInt("ingrese NUEVO tipo de vuelo:\n"
			"1-FirstClass\n"
			"2-ExecutiveClass\n"
			"3-EconomyClass\n\t->", 0, 4, 5);

	pasajeroAux.estadoDeVuelo = getInt("ingrese NUEVO estado de vuelo:\n"
			"1-Aterrizado\n"
			"2-En Horario\n"
			"3-En Vuelo\n"
			"4-Demorado\n\t->", 0, 5, 5);

	pasajeroAux.id = pasajero_nuevaId(listaMain)+1;

	funcionesMixtas_MostrarUnPasajero(pasajeroAux.id, pasajeroAux.nombre, pasajeroAux.apellido, pasajeroAux.precio, pasajeroAux.codigoVuelo, pasajeroAux.tipoDeVuelo, pasajeroAux.estadoDeVuelo, listaTipo, listaEstado);

	opcion = validacionS_N("desea dar de alta el siguiente pasajero?");

	if(opcion == 1)
	{
		pasajero = &pasajeroAux;
		if(ll_add(listaMain, pasajero) == 0)
		{
			retorno = 0;
		}

	}else{
		printf("se descartaron los cambios");
	}

	return retorno;
}
