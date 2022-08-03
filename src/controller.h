

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "funcionesMixtas.h"

int mostrarMenu(void);

int controller_CargarDesdeTexto(LinkedList* listaTipo, LinkedList* listaEstado,LinkedList* listaMain, char* path);

int controller_CargarDesdeBin(LinkedList* listaMain, char* path);

int controller_AltaPasajero(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado);

int controller_ModificarPasajero(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado);

int controller_BajaPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int controller_ListarPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int controller_OrdenarPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo);

int controller_GuardarEnTxt(LinkedList* ListaMain, char* path);

int controller_GuardarEnBin(LinkedList* ListaMain,char* path);
#endif /* CONTROLLER_H_ */
