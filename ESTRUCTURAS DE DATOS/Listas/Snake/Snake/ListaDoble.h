#pragma once
#include "Nodo.h"

class CListaDoble
{
	CNodo* inicio;
	CNodo* final;
	int tamaño;
	int cont;

public:
	CListaDoble(int x,int y,int tamaño);
	~CListaDoble(void);
	bool AgregarAlFinal();
	void mostrarTodos(System::Drawing::Graphics ^C);
	void moverTodos(int gWidth,int gHeight);
	bool colision(int px,int py,int w,int h);
	void cambiaDireccion(Direccion dir);
	bool colisionPropia();

};
