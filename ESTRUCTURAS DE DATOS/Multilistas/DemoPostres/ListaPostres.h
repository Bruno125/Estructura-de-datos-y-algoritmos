#pragma once
#include "Postre.h"

class CListaPostres
{
private:
	list<CPostre*> postres;

public:
	CListaPostres(void);
	~CListaPostres(void);
	CPostre* damePostre(int codigo);
	bool agregarPostre(int codigo, char* nombre);
	void imprimirPostres();
	void imprimirPostresConIngrediente(char *nombreIngrediente);
	void imprimirListaCompras();
};

