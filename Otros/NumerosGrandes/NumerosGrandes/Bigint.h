#pragma once
#include "Nodo.h"
#include <stdio.h>
#include <string.h>

class CBigint
{
private:
	CNodo* inicio;
	CNodo* final;
	bool InsertarAlInicio(int dato);
	bool InsertarAlFinal(int dato);
	bool EliminarAlInicio();
	bool esPositivo;
public:
	CBigint(void);
	CBigint(CBigint *numero);
	CBigint(char* numero);
	CBigint(int numero);
	~CBigint(void);
	void Imprimir();
	void masmas();
	void mas(int numero);
	void mas(char* numero);
	void mas(CBigint* numero);
	void restamas();
	void resta(int numero);
	void resta(char* numero);
	void resta(CBigint* numero);
};

