#ifndef ESTADODEVUELO_H_
#define ESTADODEVUELO_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[30];
}eEstadoVuelo;


eEstadoVuelo* estadoVuelo_new();
eEstadoVuelo* estadoVuelo_newParametros(char* id, char* descripcion);

void estadoVuelo_delete(eEstadoVuelo* estado);

int estadoVuelo_SetId(int id, eEstadoVuelo* estado);
int estadoVuelo_GetId(int* id, eEstadoVuelo* estado);

int estadoVuelo_SetDescripcion(char* descripcion, eEstadoVuelo* estado);
int estadoVuelo_GetDescripcion(char* descripcion, eEstadoVuelo* estado);

int estadoVuelo_pasarAString(int id, char* Descripcion, LinkedList* lista);

#endif /* ESTADODEVUELO_H_ */
