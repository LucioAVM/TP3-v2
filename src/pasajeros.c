#include "pasajeros.h"
#include "string.h"

ePasajero* pasajero_new()
{
	ePasajero* pasajero = NULL;

	pasajero = (ePasajero*)malloc(sizeof(ePasajero));

	return pasajero;
}

ePasajero* pasajero_newParametros(char* id, char* nombre, char* apellido, char* precio, char* codigoDeVuelo, char* tipoDeVuelo, char* estadoDeVuelo)
{
	ePasajero* pasajero = NULL;

	pasajero = pasajero_new();

	if(pasajero != NULL)
	{
		if(!(pasajero_SetId(atoi(id), pasajero) == 0
				&& pasajero_SetNombre(nombre, pasajero) == 0
				&& pasajero_SetApellido(apellido, pasajero) == 0
				&& pasajero_SetPrecio(atof(precio), pasajero) == 0
				&& pasajero_SetCodigoDeVuelo(codigoDeVuelo, pasajero) == 0
				&& pasajero_SetTipoDeVuelo(tipoDeVuelo, pasajero) == 0
				&& pasajero_SetEstadoDeVuelo(estadoDeVuelo, pasajero) == 0))
		{
			pasajero_delete(pasajero);
		}
	}
	return pasajero;
}

void pasajero_delete(ePasajero* pasajero)
{
	if(pasajero != NULL)
	{
		free(pasajero);

		pasajero = NULL;
	}
}

int pasajero_SetId(int id, ePasajero* pasajero)
{
	int retorno = -1;

	if(id > 0 && pasajero != NULL)
	{
		pasajero->id = id;
		retorno = 0;
	}

	return retorno;
}
int pasajero_GetId(int* id, ePasajero* pasajero)
{
	int retorno = -1;

	if(id != NULL && pasajero != NULL)
	{
		*id = pasajero->id;
		retorno = 0;
	}

	return retorno;
}

int pasajero_SetNombre(char* nombre, ePasajero* pasajero)
{
	int retorno = -1;

	if(nombre != NULL && pasajero != NULL)
	{
		strcpy(pasajero->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int pasajero_GetNombre(char* nombre, ePasajero* pasajero)
{
	int retorno = -1;

	if(nombre != NULL && pasajero != NULL)
	{
		strcpy(nombre, pasajero->nombre);
		retorno = 0;
	}

	return retorno;
}


int pasajero_SetApellido(char* apellido, ePasajero* pasajero)
{
	int retorno = -1;

	if(apellido != NULL && pasajero != NULL)
	{
		strcpy(pasajero->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int pasajero_GetApellido(char* apellido, ePasajero* pasajero)
{
	int retorno = -1;

	if(apellido != NULL && pasajero != NULL)
	{
		strcpy(apellido, pasajero->apellido);
		retorno = 0;
	}
	return retorno;
}

int pasajero_SetPrecio(float precio, ePasajero* pasajero)
{
	int retorno = 0;

	if(precio > 0 && pasajero != NULL)
	{
		pasajero->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int pasajero_GetPrecio(float* precio, ePasajero* pasajero)
{
	int retorno = -1;

	if(precio != NULL && pasajero != NULL)
	{
		*precio = pasajero->precio;
		retorno = 0;
	}

	return retorno;
}

int pasajero_SetCodigoDeVuelo(char* codigoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;

	if(codigoDeVuelo != NULL && pasajero != NULL)
	{
		strcpy(pasajero->codigoVuelo,codigoDeVuelo);
		retorno = 0;
	}
	return retorno;
}
int pasajero_GetCodigoDeVuelo(char* codigoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;

	if(codigoDeVuelo != NULL && pasajero != NULL)
	{
		strcpy(codigoDeVuelo, pasajero->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int pasajero_SetTipoDeVuelo(char* tipoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;
	int tipoDeVueloInt;

	if(tipoDeVuelo != NULL && pasajero != NULL)
	{
		retorno = 0;
		if(strcmp(tipoDeVuelo, "FirstClass") == 0)
		{
			tipoDeVueloInt = 1;
		}else if(strcmp(tipoDeVuelo, "ExecutiveClass") == 0)
		{
			tipoDeVueloInt = 2;
		}else if(strcmp(tipoDeVuelo, "EconomyClass") == 0)
		{
			tipoDeVueloInt = 3;
		}else{
			retorno = -1;
		}
		pasajero->tipoDeVuelo = tipoDeVueloInt;
	}
	return retorno;
}
int pasajero_GetTipoDeVuelo(int* tipoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;

	if(tipoDeVuelo > 0 && pasajero != NULL)
	{
		*tipoDeVuelo = pasajero->tipoDeVuelo;
		retorno = 0;
	}
	return retorno;
}

int pasajero_SetEstadoDeVuelo(char* estadoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;
	int estadoDeVueloInt;

	if(estadoDeVuelo != NULL && pasajero != NULL)
	{
		retorno = 0;
		if(strcmp(estadoDeVuelo, "Aterrizado") == 0)
		{
			estadoDeVueloInt = 1;
		}else if(strcmp(estadoDeVuelo, "En Horario") == 0)
		{
			estadoDeVueloInt = 2;
		}else if(strcmp(estadoDeVuelo, "En Vuelo") == 0)//Demorado
		{
			estadoDeVueloInt = 3;
		}else if(strcmp(estadoDeVuelo, "Demorado") == 0)
		{
			estadoDeVueloInt = 4;
		}else{
			retorno = -1;
		}
		pasajero->estadoDeVuelo = estadoDeVueloInt;
	}
	return retorno;
}
int pasajero_GetEstadoDeVuelo(int* estadoDeVuelo, ePasajero* pasajero)
{
	int retorno = -1;

	if(estadoDeVuelo > 0 && pasajero != NULL)
	{
		*estadoDeVuelo = pasajero->estadoDeVuelo;
		retorno = 0;
	}
	return retorno;
}

int pasajero_modificar(int id, LinkedList* listaMain, LinkedList* listaTipo, LinkedList* listaEstado)
{
	int retorno = -1;

	char validacion;
	int idAux;

	idAux = id-1;

	ePasajero* pasajero = NULL;

	if(id > 0 && listaMain != NULL)
	{
		pasajero = ll_get(listaMain, idAux);

		funcionesMixtas_MostrarUnPasajero(pasajero->id,pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoVuelo,pasajero->tipoDeVuelo,pasajero->estadoDeVuelo, listaTipo, listaEstado);
		printf("es este el usuario que busca?: S-N");
		fflush(stdout);
		scanf("%s",&validacion);

		if(validacion == 'S')
		{
			retorno = funcionesMixtas_modificar(listaMain, listaTipo, listaEstado,idAux);
		}else{
			retorno = 0;
		}
	}
	return retorno;
}


int pasajero_ordenarPorId(void* primero, void* segundo)
{
	int retorno = -1;
	int primeraId;
	int segundaId;

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetId(&primeraId, primero);
		pasajero_GetId(&segundaId, segundo);

		if(primeraId < segundaId)
		{
			retorno = 1;
		}else if(primeraId < segundaId)
		{
			retorno = -2;
		}else if(primeraId == segundaId)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int pasajero_ordenarPorNombre(void* primero, void* segundo)
{
	int retorno = -1;
	char primerNombre[30];
	char segundoNombre[30];

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetNombre(primerNombre, primero);
		pasajero_GetNombre(segundoNombre, segundo);

		retorno = strcmp(primerNombre, segundoNombre);
	}

	return retorno;
}

int pasajero_ordenarPorApellido(void* primero, void* segundo)
{
	int retorno = -1;
	char primerApellido[30];
	char segundoApellido[30];

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetApellido(primerApellido, primero);
		pasajero_GetApellido(segundoApellido, segundo);

		retorno = strcmp(primerApellido, segundoApellido);
	}

	return retorno;
}

int pasajero_ordenarPorPrecio(void* primero, void* segundo)
{
	int retorno = -1;
	float primerPrecio;
	float segundoPrecio;

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetPrecio(&primerPrecio, primero);
		pasajero_GetPrecio(&segundoPrecio, segundo);

		if(primerPrecio < segundoPrecio)
		{
			retorno = 1;
		}else if(primerPrecio < segundoPrecio)
		{
			retorno = -2;
		}else if(primerPrecio == segundoPrecio)
		{
			retorno = 0;
		}

	}

	return retorno;
}

int pasajero_ordenarPorCodigo(void* primero, void* segundo)
{
	int retorno = -1;
	char primerCodigo[30];
	char segundoCodigo[30];

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetCodigoDeVuelo(primerCodigo, primero);
		pasajero_GetCodigoDeVuelo(segundoCodigo, segundo);

		retorno = strcmp(primerCodigo, segundoCodigo);
	}

	return retorno;
}

int pasajero_ordenarPorTipo(void* primero, void* segundo)
{
	int retorno = -1;
	int primerTipo;
	int segundoTipo;

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetTipoDeVuelo(&primerTipo, primero);
		pasajero_GetTipoDeVuelo(&segundoTipo, segundo);

		if(primerTipo < segundoTipo)
		{
			retorno = 1;
		}else if(primerTipo < segundoTipo)
		{
			retorno = -2;
		}else if(primerTipo == segundoTipo)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int pasajero_ordenarPorEstado(void* primero, void* segundo)
{
	int retorno = -1;
	int primerEstado;
	int segundoEstado;

	if(primero != NULL && segundo != NULL)
	{
		pasajero_GetEstadoDeVuelo(&primerEstado, primero);
		pasajero_GetEstadoDeVuelo(&segundoEstado, segundo);

		if(primerEstado < segundoEstado)
		{
			retorno = 1;
		}else if(primerEstado < segundoEstado)
		{
			retorno = -2;
		}else if(primerEstado == segundoEstado)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int pasajero_nuevaId(LinkedList* listaMain)
{
	int retorno = -1;
	int tam;

	ePasajero* pasajero;

	tam = ll_len(listaMain);

	pasajero = ll_get(listaMain, tam-1);

	pasajero_GetId(&retorno, pasajero);

	return retorno;
}
