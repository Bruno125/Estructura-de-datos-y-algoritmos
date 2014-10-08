#pragma once
#include <stdlib.h>

class CNodo
{
private:
	int dato;
	CNodo* next;
	CNodo* prev;
public:
	CNodo(void);
	~CNodo(void);
	void setDato(int pDato);
	int getDato();
	void setNext(CNodo* pNext);
	CNodo* getNext();
	void setPrev(CNodo* pPrev);
	CNodo* getPrev();
};

