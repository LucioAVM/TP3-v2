#ifndef TIPODEVUELO_H_
#define TIPODEVUELO_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[30];
}eTipoVuelo;


eTipoVuelo* tipoVuelo_new();
eTipoVuelo* tipoVuelo_newParametros(char* id, char* descripcion);

void tipoVuelo_delete(eTipoVuelo* tipo);

int tipoVuelo_SetId(int id, eTipoVuelo* tipo);
int tipoVuelo_GetId(int* id, eTipoVuelo* tipo);

int tipoVuelo_SetDescripcion(char* descripcion, eTipoVuelo* tipo);
int tipoVuelo_GetDescripcion(char* descripcion, eTipoVuelo* tipo);

int tipoVuelo_pasarAString(int id, char* Descripcion, LinkedList* lista);

#endif /* TIPODEVUELO_H_ */
