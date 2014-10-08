#pragma once
class CIngrediente
{
private:
	char nombre[50];
	double cantidad;
public:
	CIngrediente(void);
	~CIngrediente(void);
	void setNombre(char* pNombre);
	char* getNombre();
	void setCantidad(double pCantidad);
	double getCantidad();
};

