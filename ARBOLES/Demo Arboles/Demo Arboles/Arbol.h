#pragma once
#include "Nodo.h"
#include  <queue>

using namespace std;

class CArbol
{
private:
	CNodo* raiz;
	void _recorridoInorden(void (*imprime)(int),CNodo* nodo);
	void _recorridoPreorden(void (*imprime)(int),CNodo* nodo);
	void _recorridoPostorden(void (*imprime)(int),CNodo* nodo);
	void _espejo(CNodo* nodo);

public:
	CArbol(void);
	~CArbol(void);
	
	bool insertar(int dato);
	void recorridoInorden(void (*imprime)(int));
	void recorridoPreorden(void (*imprime)(int));
	void recorridoPostorden(void (*imprime)(int));
	void recorridoPorNivel(void (*imprime)(int));

	void espejo();
	CNodo* encuentraPadre(int dato);


};

