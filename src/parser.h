#ifndef PARSER_H_
#define PARSER_H_


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pasajeros.h"
#include "tipoDeVuelo.h"
#include "estadoDeVuelo.h"

int parser_CargarDesdeTexto(LinkedList* listaMain,FILE* pArchivo);

int parser_CargarDesdeBin(LinkedList* listaMain,FILE* pArchivo);

int parser_CargarArchivosAuxiliares(LinkedList* listaEstado, LinkedList* listaTipo);

int parser_CargarTipos(LinkedList* listaTipo,FILE* pArchivo);

int parser_CargarEstado(LinkedList* listaEstado, FILE* pEstado);
#endif /* PARSER_H_ */
