#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);


static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList *)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this-> size =0;
    	this->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this != NULL)
    	{
    		returnAux = this->size;
    	}
    }

    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* vRetorno=NULL;

	if(this != NULL && nodeIndex >=0 && nodeIndex< ll_len(this))
	{
		vRetorno = this->pFirstNode;
		for(i=1;i<=nodeIndex;i++)
		{
			vRetorno = vRetorno->pNextNode;
		}
	}
    return vRetorno;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* auxNode;
    int returnAux = -1;
    if(this != NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
    	auxNode = (Node*)malloc(sizeof(Node));

    	if(auxNode!= NULL)
    	{
    		auxNode->pElement = pElement;

    		if(nodeIndex==0)
    		{
    			auxNode->pNextNode = this->pFirstNode;
    			this->pFirstNode = auxNode;
    		}
    		else
    		{
    			auxNode->pNextNode = getNode(this, nodeIndex);
    			(getNode(this,nodeIndex-1))->pNextNode = auxNode;

    		}
    		this->size++;
    		returnAux= 0;

    	}
    }
    return returnAux;
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!= NULL){

    	returnAux = addNode(this,ll_len(this),pElement);
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
    	returnAux = (void*)getNode(this, index)->pElement;
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
		Node* pNode;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNode = getNode(this, index);
		if(pNode !=NULL ){
			pNode->pElement=pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
	Node* auxNode;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
   		auxNode = getNode(this, index);
   		if(auxNode != NULL)
   		{
   			if(index==0)
    		{
    			this->pFirstNode = auxNode->pNextNode;
    		}
    		else
    		{
    			getNode(this,index-1)->pNextNode = auxNode->pNextNode;
    		}
   		}
    	free(auxNode);
    	this->size--;
    	returnAux= 0;
    }

    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	while(ll_len(this))
    	{
    		ll_remove(this,0);
    	}
    	returnAux =0;
    }

    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		if((void*)ll_get(this, i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
    	returnAux = 0;
    	if(!ll_len(this))
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!= NULL )
    {
    	returnAux = (void*)ll_get(this, index);
    	if(returnAux!= NULL)
    	{
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 1;
    	if(ll_indexOf(this, pElement)==-1)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;

	if(this != NULL && this2 != NULL){
		returnAux = 1;
		for(i=0; i < ll_len(this2); i++){

			if(!ll_contains(this, (void*)ll_get(this2, i))){
				returnAux =0;
				break;
			}
		}
	}

	return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL && from>=0 && from<to && to<=ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray!= NULL){
    		for(i=from;i<to;i++)
    		{
    			ll_add(cloneArray, (void*)ll_get(this, i));
    		}
    	}
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray!= NULL){
    		cloneArray = ll_subList(this, 0, ll_len(this));
    	}
    }

    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* pElementAux = NULL;

    if(this!= NULL && pFunc != NULL && (order == 0|| order == 1))
    {
    	for(i=0;i<ll_len(this)-1;i++)
    	{
    		for(j = i+1 ;j<ll_len(this);j++){
    			switch(order)
    			{
    			case 0:
    				if(pFunc((void*)ll_get(this, i),(void*)ll_get(this, j))<0)
    				{
    					pElementAux = (void*)ll_get(this, i);
    					ll_set(this, i, (void*)ll_get(this, j));
    					ll_set(this, j, pElementAux);
    				}
    				break;
    			case 1:
    				if(pFunc((void*)ll_get(this, i),(void*)ll_get(this, j))>0)
    				{
    					pElementAux = (void*)ll_get(this, i);
    					ll_set(this, i, (void*)ll_get(this, j));
    					ll_set(this, j, pElementAux);
    				}
    			break;
    			}
    		}
    	}
		returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_map(LinkedList* this ,void(*fn)(void*))
{
	int i;

	if(this != NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			fn((void*)ll_get(this, i));
		}
	}
	return this;
}
LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{
	LinkedList* thisRetorno = NULL;
	int i;
	void* auxElement;

	if(this!= NULL)
	{
		thisRetorno = ll_newLinkedList();
		if(thisRetorno!= NULL){
			for(i=0;i<ll_len(this);i++)
			{
				auxElement = (void*)ll_get(this, i);
				if(fn(auxElement))
				{
					ll_add(this, auxElement);
				}

			}
		}
	}
	return thisRetorno;
}
int ll_count(LinkedList* this, int(*fn)(void*))
{
	int i;
	int largo;
	int acumulador=0;

	if(this!= NULL && fn != NULL)
	{
		largo = ll_len(this);
		for(i = 0; i< largo;i++)
		{
			acumulador += fn((void*)ll_get(this, i));
		}
	}
	return acumulador;
}
