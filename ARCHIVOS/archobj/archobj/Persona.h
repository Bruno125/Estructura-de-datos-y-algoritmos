#pragma once
#include <stdio.h>
class CPersona
{
private:
	int x,y;
public:
	CPersona(void);
	~CPersona(void);
	void dibujar();
	void izquierda();
	void derecha();
	void arriba();
	void abajo();
	int getX();
	int getY();
	void guardarEnArchivo(FILE *h);
	void cargarDeArchivo(FILE *h);


};

