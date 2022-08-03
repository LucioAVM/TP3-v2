/*
 * TipoDeVuelo.c
 *
 *  Created on: 1 ago. 2022
 *      Author: UGIO
 */

#include "TipoDeVuelo.h"

eTipoVuelo* tipoVuelo_new()
{
	eTipoVuelo* tipo = NULL;

	tipo = (eTipoVuelo*)malloc(sizeof(eTipoVuelo));

	return tipo;
}

eTipoVuelo* tipoVuelo_newParametros(char* id, char* descripcion)
{
	eTipoVuelo* tipoVuelo = NULL;

	tipoVuelo = tipoVuelo_new();

	if(tipoVuelo != NULL)
	{
		if(!(tipoVuelo_SetId(atoi(id), tipoVuelo) == 0
				&& tipoVuelo_SetDescripcion(descripcion, tipoVuelo) == 0))
		{
			tipoVuelo_delete(tipoVuelo);
		}
	}
	return tipoVuelo;
}

void tipoVuelo_delete(eTipoVuelo* tipo)
{
	if(tipo != NULL)
	{
		free(tipo);

		tipo = NULL;
	}
}

int tipoVuelo_SetId(int id, eTipoVuelo* tipo)
{
	int retorno = -1;

	if(id > 0 && tipo != NULL)
	{
		tipo->id = id;
		retorno = 0;
	}

		return retorno;
}

int tipoVuelo_GetId(int* id, eTipoVuelo* tipo)
{
	int retorno = -1;

	if(id != NULL && tipo != NULL)
	{
		*id = tipo->id;
		retorno = 0;
	}

	return retorno;
}

int tipoVuelo_SetDescripcion(char* descripcion, eTipoVuelo* tipo)
{
	int retorno = -1;

	if(descripcion != NULL && tipo != NULL)
	{
		strcpy(tipo->descripcion, descripcion);
		retorno = 0;
	}

		return retorno;
}

int tipoVuelo_GetDescripcion(char* descripcion, eTipoVuelo* tipo)
{
	int retorno = -1;

	if(descripcion != NULL && tipo != NULL)
	{
		strcpy(descripcion, tipo->descripcion);
		retorno = 0;
	}

	return retorno;
}


int tipoVuelo_pasarAString(int id, char* Descripcion, LinkedList* lista)
{
	int retorno = -1;
	eTipoVuelo* tipo = NULL;
	int tam;
	int idAux;

	tam = ll_len(lista);
	for(int i = 0; i < tam; i++)
	{
		tipo = ll_get(lista, i);

		if(tipoVuelo_GetId(&idAux, tipo) == 0 && idAux == id)
		{
			retorno = tipoVuelo_GetDescripcion(Descripcion, tipo);
			break;
		}
	}

	return retorno;
}
