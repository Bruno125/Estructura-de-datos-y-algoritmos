#pragma once
#include <stdlib.h>

class CNodo
{
private:
	int dato;
	CNodo* next;
public:
	CNodo(void);
	~CNodo(void);
	int getDato();
	void setDato(int pDato);
	CNodo* getNext();
	void setNext(CNodo* pNext);
};

