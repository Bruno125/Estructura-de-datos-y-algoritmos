#include "stdafx.h"
#include "Tour.h"


CTour::CTour(void)
{
	codigo = 0;
	precio = 0.0;
	cupos = 0;
	vendidas = 0;
	nombre[0] = '\0';
}
//---------------------------------
CTour::~CTour(void)
{
}
//---------------------------------
int CTour::getCodigo()
{
	return codigo;
}
//---------------------------------
void CTour::setCodigo(int pCodigo)
{
	codigo = pCodigo;
}
//---------------------------------
char* CTour::getNombre()
{
	return nombre;
}
//---------------------------------
void CTour::setNombre(char *pNombre)
{
	strcpy(nombre, pNombre);
}
//---------------------------------
double CTour::getPrecio()
{
	return precio;
}
//---------------------------------
void CTour::setPrecio(double pPrecio)
{
	if (pPrecio > 0)
		precio = pPrecio;
}
//---------------------------------
int CTour::getCupos()
{
	return cupos;
}
//---------------------------------
void CTour::setCupos(int pCupos)
{
	if (pCupos >= 0)
		cupos = pCupos;
}
//---------------------------------
int CTour::getVendidas()
{
	return vendidas;
}
//---------------------------------
bool CTour::registrarVenta(int cantEntradas)
{
	int quedan = cupos - vendidas;
	if (cantEntradas > 0 && quedan >= cantEntradas)
	{
		vendidas += cantEntradas;
		return true;
	}
	else
		return false;
}
//---------------------------------
void CTour::cargarDeArchivo(FILE* arch)
{
	fread(&codigo, sizeof(codigo), 1, arch);
	fread(&precio, sizeof(precio), 1, arch);
	fread(&cupos, sizeof(cupos), 1, arch);
	fread(&vendidas, sizeof(vendidas), 1, arch);
	int cantLetras;
	fread(&cantLetras, sizeof(cantLetras), 1, arch);
	fread(&nombre, sizeof(char), cantLetras, arch);
}
//---------------------------------
void CTour::guardarEnArchivo(FILE* arch)
{
	fwrite(&codigo, sizeof(codigo), 1, arch);
	fwrite(&precio, sizeof(precio), 1, arch);
	fwrite(&cupos, sizeof(cupos), 1, arch);
	fwrite(&vendidas, sizeof(vendidas), 1, arch);
	int cantLetras = strlen(nombre) + 1;
	fwrite(&cantLetras, sizeof(cantLetras), 1, arch);
	fwrite(&nombre, sizeof(char), cantLetras, arch);
}
//---------------------------------