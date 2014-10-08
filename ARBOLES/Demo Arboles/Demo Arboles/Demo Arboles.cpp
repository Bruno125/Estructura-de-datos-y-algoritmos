// Demo Arboles.cpp : main project file.

#include "stdafx.h"
#include "Arbol.h"
#include <stdio.h>

using namespace System;

void imprimeEntero(int dato){
	printf("%4d",dato);
}

int main(array<System::String ^> ^args)
{
	CArbol* arbol=new CArbol();
	arbol->insertar(50);
	arbol->insertar(80);
	arbol->insertar(38);
	arbol->insertar(45);
	arbol->insertar(38);
	arbol->insertar(20);
	arbol->insertar(78);
	arbol->insertar(5);
	arbol->insertar(39);

	arbol->espejo();
	arbol->recorridoInorden(imprimeEntero);

	getchar();
    return 0;
}
