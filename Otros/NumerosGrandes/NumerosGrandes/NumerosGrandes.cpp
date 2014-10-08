// NumerosGrandes.cpp : main project file.

#include "stdafx.h"
#include "Bigint.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    CBigint *a=new CBigint("10");
	a->resta(1);
	a->Imprimir();
	getchar();
    return 0;
}
