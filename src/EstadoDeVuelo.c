/*
 * EstadoDeVuelo.c
 *
 *  Created on: 1 ago. 2022
 *      Author: UGIO
 */

#include "EstadoDeVuelo.h"

eEstadoVuelo* estadoVuelo_new()
{
	eEstadoVuelo* estado = NULL;

	estado = (eEstadoVuelo*)malloc(sizeof(eEstadoVuelo));

	return estado;
}

eEstadoVuelo* estadoVuelo_newParametros(char* id, char* descripcion)
{
	eEstadoVuelo* estadoVuelo = NULL;

	estadoVuelo = estadoVuelo_new();

	if(estadoVuelo != NULL)
	{
		if(!(estadoVuelo_SetId(atoi(id), estadoVuelo) == 0
				&& estadoVuelo_SetDescripcion(descripcion, estadoVuelo) == 0))
		{
			estadoVuelo_delete(estadoVuelo);
		}
	}
	return estadoVuelo;
}


void estadoVuelo_delete(eEstadoVuelo* estado)
{
	if(estado != NULL)
	{
		free(estado);

		estado = NULL;
	}
}

int estadoVuelo_SetId(int id, eEstadoVuelo* estado)
{
	int retorno = -1;

	if(id > 0 && estado != NULL)
	{
		estado->id = id;
		retorno = 0;
	}

	return retorno;
}

int estadoVuelo_GetId(int* id, eEstadoVuelo* estado)
{
	int retorno = -1;

	if(id != NULL && estado != NULL)
	{
		*id = estado->id;
		retorno = 0;
	}

		return retorno;
}

int estadoVuelo_SetDescripcion(char* descripcion, eEstadoVuelo* estado)
{
	int retorno = -1;

	if(descripcion != NULL && estado != NULL)
	{
		strcpy(estado->descripcion, descripcion);
		retorno = 0;
	}

	return retorno;
}

int estadoVuelo_GetDescripcion(char* descripcion, eEstadoVuelo* estado)
{
	int retorno = -1;

	if(descripcion != NULL && estado != NULL)
	{
		strcpy(descripcion, estado->descripcion);
		retorno = 0;
	}

	return retorno;
}


int estadoVuelo_pasarAString(int id, char* Descripcion, LinkedList* lista)
{
	int retorno = -1;
	eEstadoVuelo* estado;
	int tam;
	int idAux;

	tam = ll_len(lista);
	for(int i = 0; i < tam; i++)
	{
		estado = ll_get(lista, i);
		if(estadoVuelo_GetId(&idAux, estado) == 0 && idAux == id)
		{
			retorno = estadoVuelo_GetDescripcion(Descripcion, estado);
			break;
		}
	}

	return retorno;
}
