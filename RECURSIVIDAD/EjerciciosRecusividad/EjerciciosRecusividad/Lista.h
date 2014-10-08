#pragma once
#include <stdio.h>
#include "Nodo.h"

class CLista
{
private:
	CNodo* inicio;
public:
	CLista(void);
	~CLista(void);
	bool Add(int dato);
	bool AddOrdenado(int dato);
	bool agregaordenado(CNodo* nodo,int dato);
	void Imprimir();
	void ImprimirAlReves();
	void imprimeAlReves(CNodo* aux);
};

