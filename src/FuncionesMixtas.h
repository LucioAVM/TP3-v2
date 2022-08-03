#ifndef FUNCIONESMIXTAS_H_
#define FUNCIONESMIXTAS_H_

#include <stdio.h>
#include <stdlib.h>
#include "pasajeros.h"
#include "LinkedList.h"
#include "TipoDeVuelo.h"
#include "EstadoDeVuelo.h"
#include "monsalbo.h"

void funcionesMixtas_MostrarUnPasajero(int id,char* nombre, char* apellido, float precio,char* codigoDeVuelo, int tipoDeVuelo, int estadoDeVuelo, LinkedList* listaTipo, LinkedList* listaEstado);

int funcionesMixtas_MostrarLista(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int funcionesMixtas_modificar(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado, int id);

int funcionesMixtas_DarDeBaja(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int funcionesMixtas_ordenar(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int funcionesMixtas_darDeAlta(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado);

#endif /* FUNCIONESMIXTAS_H_ */
