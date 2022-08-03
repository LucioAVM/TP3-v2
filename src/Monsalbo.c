
#include "Monsalbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

											//VALIDACIONES NUMEROS//
//FLOAT//
int getFloat(float* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno;
	float auxiliarFloat;

	retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdout);
			scanf("%f", &auxiliarFloat);
			if(auxiliarFloat > minimo && auxiliarFloat < maximo)
			{
				*resultado = auxiliarFloat ;
				retorno = 0;
				break;
			}else{
				printf("\nEl numero ingresado no esta dentro del limite(%d-%d), intente nuevamente\n",minimo, maximo);
			}
		}while(retorno != 0);
	}
	return retorno;
}

//INT//
int getInt(char* mensaje, int minimo, int maximo, int reintentos)
{
	int retorno;
	int resultado;

	retorno = -1;

	if (mensaje != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdout);
			scanf("%d", &resultado);

			if (resultado > minimo && resultado < maximo)
			{
				retorno = resultado;
				break;
			}else{
				printf("\nEl numero ingresado no esta dentro del limite(%d-%d), intente nuevamente\n",minimo, maximo);
			}
			reintentos--;
		}while(reintentos > 0);
	}
	return retorno;
}

				/* **************************VALIDACION CARACTERES*************************** */
//
int getChar(char resultado[], char *mensaje, char *mensajeError, int reintentos) {
	int retorno;
	char auxiliarChar[100];

	retorno = -1;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		while (reintentos > -1)
		{
			reintentos--;

			printf("%s", mensaje);
			fflush(stdin);

			scanf("%s", auxiliarChar);

			strcpy(auxiliarChar, resultado);
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int getStringLetras(char mensaje[], char input[])
{
	char aux[256];
	int retorno;
	retorno = -1;

	do{
		getString(mensaje, aux);
		if (soloLetras(aux))
		{
			strlwr(aux);
			aux[0] = toupper(aux[0]);

			strcpy(input, aux);
			retorno = 0;
		}else{
			printf("no se ah ingresado unicamente lentras, intente nuevamente:");
		}
	}while(retorno == -1);

	return retorno;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int soloLetras(char str[])
{
	int i = 0;
	int retorno;

	retorno = -1;

	while(str[i] != '\0')
	{
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			retorno = 0;
		i++;
	}
	return retorno;
}

int getNumeros(char mensaje[])
{
	int numeroIngresado;
	int retorno;
	int intentos;

	intentos = 5;

	retorno = -1;

	do {
		numeroIngresado = getDataNum(mensaje);
		if (isdigit(numeroIngresado) != 0)
		{
			retorno = numeroIngresado;
		} else {
			intentos--;
			printf(
					"no se ah ingresado solo numeros intente nuevamente(quedan %d intentos):",
					intentos);
			if (intentos == 0)
			{
				retorno = -2;
				break;
			}
		}
	} while (retorno == -1);
	return retorno;
}

int getDataNum(char mensaje[])
{
	int retorno;

	printf(mensaje);
	scanf("%d", &retorno);

	return retorno;
}

int validacionS_N(char *texto)
{
	int validacionUsuario;
	printf("%s\n"
			"1) SI\n"
			"2) NO\n", texto);
	scanf("%d", &validacionUsuario);
	while (validacionUsuario != 1 && validacionUsuario != 2)
	{
		printf("ERROR, Ingrese una opcion correcta:\n"
				"%s\n"
				"1) SI\n"
				"2) NO\n",texto);
		scanf("%d", &validacionUsuario);
	}
	return validacionUsuario;
}

int validacionS_NParametrizadoInt(char *texto, int parametro)
{
	int validacion;
	printf(" %s\n %d\n"
			"1) SI"
			"2) NO", texto, parametro);
	scanf("%d", &validacion);

	while (validacion < 1 && validacion > 2)
	{
		printf("ERROR, elija una de las opciones:\n"
				" %s\n %d\n"
				"1) SI"
				"2) NO", texto, parametro);
		scanf("%d", &validacion);
	}
	return validacion;
}

void mostrarMensaje(char* mensajeOk, char* mensajeError, int funcion)
{
	if(funcion == 0)
	{
		printf("%s\n",mensajeOk);
	}else{
		printf("%s\n",mensajeError);
	}
}
