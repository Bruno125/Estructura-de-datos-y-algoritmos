#pragma once
#include <stdio.h>
#include "Persona.h"
class CPelota
{
private:
	int x,y,dx,dy;

public:
	CPelota(int px,int py);
	~CPelota(void);
	void Dibujar();
	void Mover();
	int getX();
	int getY();
	void guardarEnArchivo(FILE *h);
	void cargarDeArchivo(FILE *h);
	bool choque(CPersona* persona);
};

