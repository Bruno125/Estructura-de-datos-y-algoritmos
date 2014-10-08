// ConsoleApplication2.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include "Arbol.h"

void imprime(int dato){
	printf("%4d",dato);
}


using namespace System;

int main(array<System::String ^> ^args)
{
	CArbol* arbol=new CArbol();
	int arreglo[11]={50,40,80,41,30,10,77,46,77,79,50};
	arbol->insertarVarios(arreglo,11);

	arbol->recorridoInOrden(imprime);

	printf("\n\n");
	if(arbol->equilibrado())
		printf("El arbol esta equilibrado");
	else
		printf("El arbol no esta equilibrado");


	getchar();
    return 0;
}
