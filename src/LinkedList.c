

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));

	if(this!=NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int retorno = -1;
	if(this!=NULL)
	{
		retorno = this->size;
	}

	return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) // nodeindex<ll_lend  nodeIndex >=0
{
	Node* pNode = NULL;// hacer con while
	int i;

	if(this!=NULL && nodeIndex < ll_len(this) && nodeIndex > -1)
	{
		pNode = this->pFirstNode;

		if(pNode != NULL)
		{
			for(i = 0; i< nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
			}
		}
	}
	return pNode;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* pNodoAnterior;
	Node* pNuevoNode;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNuevoNode = (Node*) malloc(sizeof(Node));// CREO ESPACIO
		if(pNuevoNode != NULL)
		{
			pNuevoNode->pElement = pElement;
			pNuevoNode->pNextNode = NULL;

			if(nodeIndex == 0)
			{
				pNuevoNode->pNextNode = this->pFirstNode; // PRIMER PUNTERO LL == NULL
				this->pFirstNode = pNuevoNode;// NODO PELEMENT Y APUNTA AL SIGUIENTE
			}else{
				pNodoAnterior = getNode(this,nodeIndex-1); // PINDE EL NODO ANTERIOR PARA LINKEAR
				pNuevoNode->pNextNode = pNodoAnterior->pNextNode;// SACA EL NULL Y APUNTA AL SIGUIENTE
				pNodoAnterior->pNextNode = pNuevoNode;
			}
			this->size = this->size + 1;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int retornoAux;
	int tamNode;

	retornoAux = -1;

	tamNode = ll_len(this);

	if(this!=NULL && addNode(this,tamNode,pElement) == 0)
	{
		retornoAux = 0;
	}
	return retornoAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* retornoAux;
	Node* aux;

	retornoAux = NULL;

	if(this != NULL && index > -1 && index <= ll_len(this))
	{
		aux = getNode(this,index);
		if(aux != NULL)
		{
			retornoAux = aux->pElement;
		}
	}
	return retornoAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int retornoAux = -1;
	Node* pNode = NULL;

	if(this !=NULL && index > -1 && index <= ll_len(this))
	{
		pNode = getNode(this, index);
		if(pNode != NULL)
		{
			pNode->pElement = pElement;
			retornoAux = 0;
		}
	}
	return retornoAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retornoAux = -1;
	Node* removerNodo = NULL;
	Node* nodoPrevio = NULL;

	if(this != NULL && index > -1 && index <= ll_len(this))
	{
		removerNodo = getNode(this, index);

		if(removerNodo != NULL)
		{
			if(index == 0)
			{
				this->pFirstNode = removerNodo->pNextNode;
			}else{
				nodoPrevio = getNode(this,index - 1);
				nodoPrevio->pNextNode = removerNodo->pNextNode;
			}
			free(removerNodo);
			this->size = this->size - 1;
			retornoAux = 0;
		}
	}
	return retornoAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno;
	int tam;

	retorno = -1;

	if(this != NULL)
	{
		tam = ll_len(this);
		if(tam != -1)
		{
			for(int i = tam ; i > 0 ; i--)
			{
				ll_remove(this,i);
			}
			this->pFirstNode = NULL;
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		ll_clear(this);
		free(this->pFirstNode);
		this = NULL;
		retorno = 0;
	}
	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int retorno = -1;
	void* pAuxElement;
	int i;
	int tam;

	if(this != NULL)
	{
		tam = ll_len(this);

		for(i=0; i<tam; i++)
		{
			pAuxElement = ll_get(this, i);

			if(pAuxElement == pElement)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		if(this->size == 0)
		{
			retorno = 1;
		}else{
			if(this->size > 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int retorno;

	retorno = -1;

	if(this != NULL && index >=0 && index <= ll_len(this))//valido para las 2 funciones
	{
		retorno = addNode(this,index, pElement);
	}
	return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* retorno = NULL;
	int tam;

	tam = ll_len(this);

	if(this != NULL && index >= 0 && index <= tam)
	{

		retorno = ll_get(this,index);
		if(retorno != NULL)
		{
			ll_remove(this,index);
		}
	}
	return retorno;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList* this, void* pElement)
{
	int retorno = -1;
	int i;

	if(this != NULL)
	{
		i = ll_indexOf( this, pElement);
		if(i >= 0)
		{
			retorno = 1;
		}else{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int retorno = -1;
	int i;
	void* elemento;
	int resultadoContain;
	int tam;

	if(this != NULL && this2 != NULL)
	{
		tam = ll_len(this);
		retorno = 1;
		for(i = 0; i<tam; i++)
		{
			elemento = ll_get(this2,i);

			if(elemento != NULL)
			{
				resultadoContain = ll_contains(this,elemento);
				if(resultadoContain == 0)
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	int i;
	void* elemento;
	int tam;

	tam = ll_len(this);

	if(tam != -1 && from >= 0 && from < to && to > from && to <= tam && from < tam)
	{
		cloneArray = ll_newLinkedList();

		for(i = from ; i<to ; i++)
		{
			elemento = ll_get(this,i);
			ll_add(cloneArray, elemento);
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;
	int tam;
	void* pElement;

	if(this != NULL)
	{
		tam = ll_len(this);
		cloneArray = ll_subList(this, 0, tam);
		pElement = ll_get(this,tam);
		ll_add(cloneArray, pElement);
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int retorno = -1;

	void* pElement1 = NULL;
	void* pElement2 = NULL;
	void* aux = NULL;

	int i;
	int j;

	int len;

	if(this != NULL && pFunc != NULL && (order == 0 || order == 1))//validacion parametros
	{
		len = ll_len(this);//tam de LL

		for(i = 0; i < len ; i++)//primer for -- buclea la LL hasta tam
		{
			for(j=i+1; j<len; j++)// buclea toda la lista desde el anterior+1 hasta tam
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				aux = pElement1;//guardo el E1 en aux

				if((order == 1 && pFunc(pElement1, pElement2) > 0) || (order == 0 && pFunc(pElement1, pElement2) < 0))
				{
					ll_set(this, i, pElement2);
					ll_set(this, j, aux);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/**
 * @brief calcula el total
 *
 * @param this
 * @param pFuncion
 * @return LL con totales
 *//*
LinkedList* ll_map(LinkedList* this,int (pFuncion)(void*))
{
	LinkedList* pLista = ll_newLinkedList();
	int tam;
	void* pElement = NULL;
	int validacion;

	if(pLista != NULL && ll_isEmpty(this) == 0)
	{
		tam = ll_len(this);
		for(int i = 0 ; i < tam ; i++)
		{
			pElement = ll_get(this, i);

			if(pElement != NULL)
			{
				validacion = pFuncion(pElement);

				ll_add(pLista, pElement);
			}
		}
	}
	return pLista;
}
*/
/**
 * @brief itera todos los elementos del array y los filtra por pFunc
 *
 * @param this
 * @param pFunc
 * @return 1 = Item valido  0 = item invalido
 */
LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* element))
{
	int tam;
	LinkedList* listaFiltrada = ll_newLinkedList();

	void* pElement = NULL;

	if(listaFiltrada != NULL)
	{
		tam = ll_len(this);

		for(int i = 0; i < tam ; i++)
		{
			pElement = ll_get(this, i);

			if(pElement != NULL && pFunc(pElement) == 0)
			{
				ll_add(listaFiltrada, pElement);
			}
		}
	}
	return listaFiltrada;
}

