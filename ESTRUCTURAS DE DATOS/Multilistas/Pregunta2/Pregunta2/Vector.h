#pragma once
#include "Tour.h"
#include <vector>

using namespace std;

class CVector
{
private:
	vector<CTour*> vec;

public:
	CVector(void);
	~CVector(void);
	bool insertar(int codigo, char* nombre, double precio, int cupos);
	void mostrarEnConsola();
	bool venderEntrada(int codigo, int cantEntradas);
	CTour* dameTour(int codigo);
	void guardarEnArchivo();
	void cargarDeArchivo();
};

