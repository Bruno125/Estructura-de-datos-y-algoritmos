#pragma once
#include "Pelota.h"
#include "Persona.h"

class CVector
{
private:
	static const int MAX=100;
	CPelota* vec[MAX];
	int ne;
public:
	CVector(void);
	~CVector(void);
	bool agregarP(int x,int y);
	bool colision(CPersona *persona);
	void dibujarTodas();
	void moverTodas();
	void guardarEnArchivo(FILE *h);
	void cargarDeArchivo(FILE *h);
};

