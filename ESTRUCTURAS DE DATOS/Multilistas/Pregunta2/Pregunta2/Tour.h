#pragma once
#include <string.h>
#include <stdio.h>

class CTour
{
private:
	int codigo;
	char nombre[50];
	double precio;
	int cupos;
	int vendidas;

public:
	CTour(void);
	~CTour(void);
	int getCodigo();
	void setCodigo(int pCodigo);
	char* getNombre();
	void setNombre(char *pNombre);
	double getPrecio();
	void setPrecio(double pPrecio);
	int getCupos();
	void setCupos(int pCupos);
	int getVendidas();

	bool registrarVenta(int cantEntradas);
	void cargarDeArchivo(FILE* arch);
	void guardarEnArchivo(FILE* arch);
};

