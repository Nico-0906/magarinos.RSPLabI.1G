/*
 * LinkedList.c
 *
 *  Created on: 30 jul. 2020
 *      Author: nico
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"


static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode = NULL;

	if (this != NULL) {
		if (nodeIndex >= 0 && nodeIndex < ll_len(this)) {
			pNode = this->pFirstNode;
			for (int i = 0; i < nodeIndex; i++) {
				pNode = pNode->pNextNode;
			}
		}
	}
	return pNode;
}

Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *newNode;
	Node *pActualNode;

	if (this != NULL) {

		if (nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
			newNode = (Node*) malloc(sizeof(Node));
			newNode->pElement = pElement;
			newNode->pNextNode = NULL;

			if (nodeIndex == 0) {
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
			} else {
				pActualNode = getNode(this, nodeIndex - 1);
				newNode->pNextNode = pActualNode->pNextNode;
				pActualNode->pNextNode = newNode;
			}
			returnAux = 0;
			this->size++;
		}
	}
	return returnAux;
}

int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList *this, void *pElement) {
	return addNode(this, ll_len(this), pElement);
}

void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *newNode;

	newNode = getNode(this, index);
	if (newNode != NULL) {
		returnAux = newNode->pElement;
	}
	return returnAux;
}

int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *newNode;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		newNode = getNode(this, index);
		if (newNode != NULL) {
			newNode->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *actualNode;
	Node *previousNode;

	if (this != NULL && index < ll_len(this) && index >= 0) {

		actualNode = getNode(this, index);

		if (actualNode != NULL) {
			if (index == 0) {
				this->pFirstNode = actualNode->pNextNode;
				this->size--;
				free(actualNode);
			} else {
				previousNode = getNode(this, index - 1);
				if (previousNode != NULL) {
					previousNode->pNextNode = actualNode->pNextNode;
					this->size--;
					free(actualNode);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int ll_clear(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		while (ll_len(this)) {
			ll_remove(this, 0);
		}
		returnAux = 0;
	}
	return returnAux;
}

int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (!ll_clear(this)) {
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			if (ll_get(this, i) == pElement) {
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = 0;
		if (ll_len(this) == 0) {
			returnAux = 1;
		}
	}
	return returnAux;
}

int ll_push(LinkedList *this, int index, void *pElement) {
	return addNode(this, index, pElement);
}

void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = ll_get(this, index);
		if (ll_remove(this, index)) {
			returnAux = NULL;
		}
	}
	return returnAux;
}

int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = 0;
		if (ll_indexOf(this, pElement) >= 0) {
			returnAux = 1;
		}
	}
	return returnAux;
}

int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	void *pElementAux;
	int tam;

	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		tam = ll_len(this2);

		for (int i = 0; i < tam; i++) {
			pElementAux = ll_get(this2, i);
			if (!ll_contains(this, pElementAux)) {
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	void *pElement;
	if (!(this == NULL || from < 0 || from > ll_len(this) || to <= from || to > ll_len(this))) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (int i = from; i < to; i++) {
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}
	}
	return cloneArray;
}

LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	cloneArray = ll_subList(this, 0, ll_len(this));
	return cloneArray;
}

int ll_sort(LinkedList *this, int (*pFunc)(void* param, void* param2), int order) {
	int returnAux = -1;
	void *element1;
	void *element2;
	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				element1 = ll_get(this, i);
				element2 = ll_get(this, j);
				if ((pFunc(element1, element2) > 0 && order)
				        || (pFunc(element1, element2) < 0 && !order)) {
					ll_set(this, i, element2);
					ll_set(this, j, element1);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void* element)) {

	int tam;
	void *pElement;
	LinkedList *newLinkedList = NULL;

	if (this != NULL && *pFunc != NULL) {

		newLinkedList = ll_newLinkedList();
		if (newLinkedList != NULL) {
			tam = ll_len(this);

			for (int i = 0; i < tam; i++) {
				pElement = ll_get(this, i);
				if (pFunc(pElement)) {
					ll_add(newLinkedList, pElement);
				}
			}
		}
	}
	return newLinkedList;
}

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void* param)){
	int lenght;
	void* pElement;
	LinkedList* mappedList = NULL;
	if(this!=NULL && *pFunc!=NULL){
		mappedList = ll_newLinkedList();
		lenght = ll_len(this);
		for (int i = 0; i < lenght; i++) {
			pElement = ll_get(this, i);
			pElement = pFunc(pElement);
			if(pElement!=NULL){
				ll_add(mappedList, pElement);
			}
		}
	}

return mappedList;
}


