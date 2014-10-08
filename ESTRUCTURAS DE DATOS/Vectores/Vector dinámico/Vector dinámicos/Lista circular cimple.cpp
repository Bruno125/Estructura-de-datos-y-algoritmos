// Lista circular cimple.cpp : main project file.

#include "stdafx.h"
#include "VectorDinamico.h"
#include <stdio.h>

using namespace System;

int main(array<System::String ^> ^args)
{
	CVectorDinamico *vec=new CVectorDinamico();
	for (int i=0;i<100;i++){
		vec->insertar(i);
		printf("Vec[%d]: %d (%d de %d casillas)\n",i,vec->getDatoEnPos(i),vec->getNumElementos(),vec->getNumCasillas());
	}

	getchar();
    return 0;
}
