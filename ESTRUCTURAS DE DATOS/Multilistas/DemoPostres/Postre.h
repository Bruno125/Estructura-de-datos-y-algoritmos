#pragma once
#include "Ingrediente.h"
#include <list>
#include <stdio.h>

using namespace std;

class CPostre
{
private:
	int codigo;
	char nombre[50];
	list<CIngrediente*> ingredientes;

public:
	CPostre(void);
	~CPostre(void);
	void setCodigo(int pCodigo);
	int getCodigo();
	void setNombre(char* pNombre);
	char* getNombre();
	int getNIngredientes();
	CIngrediente* dameIngrediente(char *nombre);
	CIngrediente* dameIngrediente(int index);
	bool agregarIngrediente(char *nombre, double cantidad);
	void imprimirIngredientes();
};

