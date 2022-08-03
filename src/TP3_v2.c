/*
 ============================================================================
 Name        : TP3_v2.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "monsalbo.h"
#include "controller.h"

//cosas genericas

int main(void)
{
	int menu;
	int validacion;
	LinkedList* listaMain = ll_newLinkedList();
	LinkedList* listaEstado = ll_newLinkedList();
	LinkedList* listaTipo = ll_newLinkedList();

	do{
		system("cls");
		menu = mostrarMenu();
		switch(menu)
		{
		case 1:
			validacion = controller_CargarDesdeTexto(listaTipo,listaEstado,listaMain, "data.csv");

			mostrarMensaje("se cargo correctamente el archivo", "no se pudo cargar", validacion);
			break;
		case 2:
			validacion = controller_CargarDesdeBin(listaTipo,listaEstado,listaMain, "data.bin");

			mostrarMensaje("se cargo correctamente el archivo", "no se pudo cargar", validacion);//validar guardado de archivo cierre del programa
			break;
		case 3:
			validacion = controller_AltaPasajero(listaMain,listaTipo,listaEstado);//crear archivo respaldo id inicializado en  1001

			mostrarMensaje("se dio de alta correctamente", "error al intentar dar de alta", validacion);
			break;
		case 4:
			validacion = controller_ModificarPasajero(listaMain,listaTipo,listaEstado);

			mostrarMensaje("se modifico correctamente", "error lista inexistente", validacion);
			break;
		case 5:
			validacion = controller_BajaPasajero(listaMain,listaTipo,listaEstado);

			mostrarMensaje("se dio de baja correctamente", "error lista inexistente", validacion);
			break;
		case 6:
			validacion = controller_ListarPasajero(listaMain,listaEstado,listaTipo);

			mostrarMensaje("ok", "error lista inexistente", validacion);
			break;
		case 7:
			validacion = controller_OrdenarPasajero(listaMain,listaEstado,listaTipo);

			mostrarMensaje("", "error lista inexistente", validacion);
			break;
		case 8:
			validacion = controller_GuardarEnTxt(listaMain, "data.csv");

			mostrarMensaje("se guardo correctamente el archivo", "error al intentar guardar el archivo", validacion);
			break;
		case 9:
			validacion = controller_GuardarEnBin(listaMain, "data.bin");

			mostrarMensaje("se guardo correctamente el archivo", "error al intentar guardar el archivo", validacion);
			break;
		}
		system("pause");
	}while(menu != 10);


	return EXIT_SUCCESS;
}



