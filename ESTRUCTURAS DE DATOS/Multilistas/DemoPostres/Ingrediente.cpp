#include "stdafx.h"
#include "Ingrediente.h"
#include <string.h>

CIngrediente::CIngrediente(void)
{
	strcpy(nombre, "");
	cantidad = 0.0;
}
//---------------------------------------------------
CIngrediente::~CIngrediente(void)
{
}
//---------------------------------------------------
void CIngrediente::setNombre(char* pNombre)
{
	strcpy(nombre, pNombre);
}
//---------------------------------------------------
char* CIngrediente::getNombre()
{
	return nombre;
}
//---------------------------------------------------
void CIngrediente::setCantidad(double pCantidad)
{
	if (pCantidad > 0)
		cantidad = pCantidad;
}
//---------------------------------------------------
double CIngrediente::getCantidad()
{
	return cantidad;
}
//---------------------------------------------------
