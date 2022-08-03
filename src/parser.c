#include "parser.h"

int parser_CargarDesdeTexto(LinkedList* listaMain, FILE* pArchivo)
{
	int retorno = -1;
	char id[5];
	char nombre[30];
	char apellido[30];
	char precio[15];
	char codigoVuelo[30];
	char tipoPasajero[30];
	char estadoVuelo[30];

	int validacion;

	ePasajero* pasajero = NULL;


	do//id,name,lastname,price,flycode,typePassenger,statusFlight
	{
		validacion = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

		if(validacion ==  7 && atoi(id) > 0 && atof(precio) > 0)
		{
			pasajero = pasajero_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			if(ll_add(listaMain, pasajero) != -1)
			{
				retorno = 0;
			}else{
				ll_deleteLinkedList(listaMain);
				retorno = -1;
				break;
			}
		}
	}while(!feof(pArchivo));

	return retorno;
}


int parser_CargarDesdeBin(LinkedList* listaMain,FILE* pArchivo)
{
	int retorno = -1;

	int validacion;

	ePasajero* pasajero = pasajero_new();

	do//id,name,lastname,price,flycode,typePassenger,statusFlight
	{
		validacion = fread(pasajero,sizeof(ePasajero),1,pArchivo);

		if(validacion ==  7 )
		{
			if(ll_add(listaMain, pasajero) == 0)
			{
				printf("adentro");
				retorno = 0;
			}else{
				ll_deleteLinkedList(listaMain);
				retorno = -1;
				break;
			}
		}
	}while(!feof(pArchivo));

	return retorno;
}

int parser_CargarArchivosAuxiliares(LinkedList* listaEstado, LinkedList* listaTipo)
{
	int retorno = -1;
	FILE* pEstado;
	FILE* pTipo;

	if(ll_isEmpty(listaEstado) == 1 && ll_isEmpty(listaTipo) == 1)
	{
		pEstado = fopen("estadoVuelo.csv", "r");
		pTipo = fopen("tipoVuelo.csv", "r");

		if(pEstado != NULL && pTipo != NULL)
		{
			if(parser_CargarTipos(listaTipo, pTipo) == 0
					&& parser_CargarEstado(listaEstado, pEstado) == 0)
			{
				retorno = 0;
			}
		}

		fclose(pEstado);
		fclose(pTipo);
	}
	return retorno;
}

int parser_CargarTipos(LinkedList* listaTipo, FILE* pTipo)
{
	int retorno = -1;

	char id[5];
	char descripcion[30];

	int validacion;
	eTipoVuelo* tipo;

	do
	{
		validacion = fscanf(pTipo,"%[^,],%[^\n]\n", id, descripcion);

		if(validacion == 2 && atoi(id) > 0)
		{
			tipo = tipoVuelo_newParametros(id, descripcion);
			if(ll_add(listaTipo, tipo) == 0)
			{
				retorno = 0;
			}else{
				ll_deleteLinkedList(listaTipo);
				retorno = -1;
				break;
			}
		}
	}while(!feof(pTipo));

	return retorno;
}

int parser_CargarEstado(LinkedList* listaEstado, FILE* pEstado)
{
	int retorno = -1;

	char id[5];
	char descripcion[30];

	int validacion;
	eEstadoVuelo* estado;

	do
	{
		validacion = fscanf(pEstado,"%[^,],%[^\n]\n", id, descripcion);

		if(validacion == 2 && atoi(id) > 0)
		{
			estado = estadoVuelo_newParametros(id, descripcion);
			if(ll_add(listaEstado, estado) == 0)
			{
				retorno = 0;
			}else{
				ll_deleteLinkedList(listaEstado);
				retorno = -1;
				break;
			}
		}
	}while(!feof(pEstado));

	return retorno;
}
