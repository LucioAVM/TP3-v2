#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"

int mostrarMenu(void)
{
	int menu;

	printf("       Menu Pasajeros\n"
			"       --------------\n\n"
			"1. Cargar datos en texto\n"
			"2. Cargar datos en binario\n"
			"3. Alta\n"
			"4. Modificar\n"
			"5. Baja\n"
			"6. Listar\n"
			"7. Ordenar\n"
			"8. Guardar datos en texto\n"
			"9. Guardar datos en binario\n"
			"10. Salir\n"
		    "\tOpcion: ");
	fflush(stdout);
	scanf("%d",&menu);

	return menu;
}

int controller_CargarDesdeTexto(LinkedList* listaTipo, LinkedList* listaEstado,LinkedList* listaMain, char* path)
{
	int retorno = -1;
	FILE* pArchivo;

	if(ll_isEmpty(listaMain) == 1 && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			if(parser_CargarDesdeTexto(listaMain, pArchivo) == 0
					&& parser_CargarArchivosAuxiliares(listaEstado, listaTipo) == 0)
			{
				retorno = 0;
			}
		}

		fclose(pArchivo);
	}

	return retorno;
}

int controller_CargarDesdeBin(LinkedList* listaTipo, LinkedList* listaEstado,LinkedList* listaMain, char* path)//validar archivo binario
{
	int retorno = -1;
	FILE* pArchivo;

	if(ll_isEmpty(listaMain) == 0 && path != NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL)
		{
			if(parser_CargarDesdeBin(listaMain, pArchivo) == 0
					&& parser_CargarArchivosAuxiliares(listaEstado, listaTipo) == 0)
			{
				retorno = 0;
			}
		}

		fclose(pArchivo);
	}

	return retorno;
}

int controller_AltaPasajero(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) != -1)
	{
		retorno = funcionesMixtas_darDeAlta(listaMain, listaTipo, listaEstado);
	}

	return retorno;
}

int controller_ModificarPasajero(LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado)
{
	int retorno = -1;

	int idIngresado;

	if(ll_isEmpty(listaMain) == 0)
	{//mostrar lista
		funcionesMixtas_MostrarLista(listaMain, listaEstado, listaTipo);

		printf("\ningrese el id del pasajero que desea modificar:");//monsalbo
		fflush(stdout);
		scanf("%d", &idIngresado);

		retorno = pasajero_modificar(idIngresado, listaMain,listaTipo, listaEstado);
	}
	return retorno;
}

int controller_BajaPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0)
	{
		retorno = funcionesMixtas_DarDeBaja(listaMain, listaEstado, listaTipo);
	}

	return retorno;
}

int controller_ListarPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0 && ll_isEmpty(listaEstado) == 0 && ll_isEmpty(listaTipo) == 0)
	{
		retorno = funcionesMixtas_MostrarLista(listaMain,listaEstado,listaTipo);
	}

	return retorno;
}

int controller_OrdenarPasajero(LinkedList* listaMain, LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0 && ll_isEmpty(listaEstado) == 0 && ll_isEmpty(listaTipo) == 0)
	{
			retorno = funcionesMixtas_ordenar(listaMain, listaEstado, listaTipo);
	}
	return retorno;
}

int controller_GuardarEnTxt(LinkedList* ListaMain, char* path)
{
	int retorno = -1;

	FILE* pArchivoTexto;
	ePasajero* pasajero;
	int tam;
	int i;

	retorno = -1;
	tam = ll_len(ListaMain);

	if(path != NULL && ListaMain !=NULL)
	{
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(ListaMain,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
		retorno = 0;
	}
	return retorno;
}

int controller_GuardarEnBin(LinkedList* ListaMain,char* path)
{
	int retorno = -1;

	int tam;
	int i;

	FILE* pArchivoBinario;
	ePasajero* pasajero;

	retorno = -1;
	tam = ll_len(ListaMain);

	if(path != NULL && ListaMain !=NULL)
	{
		pArchivoBinario = fopen(path,"wb");

		if(pArchivoBinario !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(ListaMain,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoBinario);
			}
		}
		fclose(pArchivoBinario);
		retorno = 0;
	}
	return retorno;
}
