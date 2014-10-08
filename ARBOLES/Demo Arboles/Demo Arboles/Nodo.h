#pragma once
#include <stdlib.h>

class CNodo
{
private:
	int dato;
	CNodo* izq;
	CNodo* der;
public:
	CNodo(void);
	~CNodo(void);
	void setDato(int dato);
	int getDato();
	void setIzq(CNodo* nodo);
	CNodo* getIzq();
	void setDer(CNodo* nodo);
	CNodo* getDer();

};

