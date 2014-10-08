// VectorTemplate.cpp : main project file.

#include "stdafx.h"
#include "Vector.cpp"
#include <stdio.h>

using namespace System;

int main(array<System::String ^> ^args)
{
	CVector<int> *vec=new CVector<int>();
	vec->Insertar(45);
	vec->Insertar(30);
	vec->Insertar(234534);
	vec->Insertar(30);
	vec->Insertar(1232);
	vec->Insertar(164);

	for(int i=0;i<vec->getN();i++){
		printf("%d\n",vec->getDatoEnPos(i));
	}



    getchar();
    return 0;
}
