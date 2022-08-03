#ifndef PASAJEROS_H_
#define PASAJEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funcionesMixtas.h"
#include "monsalbo.h"

typedef struct
{
	int id;
	char nombre[25];
	char apellido[30];
	float precio;
	char codigoVuelo[30];
	int tipoDeVuelo;
	int estadoDeVuelo;
}ePasajero;
//id,name,lastname,price,flycode,typePassenger,statusFlight

ePasajero* pasajero_new();

ePasajero* pasajero_newParametros(char* id, char* nombre, char* apellido, char* precio, char* codigoDeVuelo, char* tipoDeVuelo, char* estadoDeVuelo);

void pasajero_delete(ePasajero* pasajero);

int pasajero_SetId(int id, ePasajero* pasajero);
int pasajero_GetId(int* id, ePasajero* pasajero);

int pasajero_SetNombre(char* nombre, ePasajero* pasajero);
int pasajero_GetNombre(char* nombre, ePasajero* pasajero);

int pasajero_SetApellido(char* apellido, ePasajero* pasajero);
int pasajero_GetApellido(char* apellido, ePasajero* pasajero);

int pasajero_SetPrecio(float precio, ePasajero* pasajero);
int pasajero_GetPrecio(float* precio, ePasajero* pasajero);

int pasajero_SetCodigoDeVuelo(char* codigoDeVuelo, ePasajero* pasajero);
int pasajero_GetCodigoDeVuelo(char* codigoDeVuelo, ePasajero* pasajero);

int pasajero_SetTipoDeVuelo(char* tipoDeVuelo, ePasajero* pasajero);
int pasajero_GetTipoDeVuelo(int* tipoDeVuelo, ePasajero* pasajero);

int pasajero_SetEstadoDeVuelo(char* estadoDeVuelo, ePasajero* pasajero);
int pasajero_GetEstadoDeVuelo(int* estadoDeVuelo, ePasajero* pasajero);

void pasajero_MostrarUnPasajero(int id,char* nombre, char* apellido, float precio,char* codigoDeVuelo, int tipoDeVuelo, int estadoDeVuelo);
int pasajero_MostrarLista(LinkedList* listaMain);

int pasajero_modificar(int id, LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado);

int pasajero_ordenarPorId(void* primero, void* segundo);
int pasajero_ordenarPorNombre(void* primero, void* segundo);
int pasajero_ordenarPorApellido(void* primero, void* segundo);
int pasajero_ordenarPorPrecio(void* primero, void* segundo);
int pasajero_ordenarPorCodigo(void* primero, void* segundo);
int pasajero_ordenarPorTipo(void* primero, void* segundo);
int pasajero_ordenarPorEstado(void* primero, void* segundo);

int pasajero_nuevaId(LinkedList* listaMain);


#endif /* PASAJEROS_H_ */
