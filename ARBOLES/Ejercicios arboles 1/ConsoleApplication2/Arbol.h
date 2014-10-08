#pragma once
#include "Nodo.h"
#include <stdio.h>
#include <queue>

using namespace std;

class CArbol
{
private:
	CNodo* raiz;
	void _recorridoPreOrden(void (*imprime)(int),CNodo* nodo);
	void _recorridoInOrden(void (*imprime)(int),CNodo* nodo);
	void _recorridoPostOrden(void (*imprime)(int),CNodo* nodo);
	void _espejo(CNodo* nodo);
	int dameCantidadHijos(CNodo* nodo);


public:
	CArbol(void);
	~CArbol(void);

	bool insertar(int dato);
	void insertarVarios(int arreglo[],int n);

	void recorridoPreOrden(void (*imprime)(int));
	void recorridoInOrden(void (*imprime)(int));
	void recorridoPostOrden(void (*imprime)(int));
	void recorridoPorNivel(void (*imprime)(int));
	void espejo();

	bool equilibrado();


};

