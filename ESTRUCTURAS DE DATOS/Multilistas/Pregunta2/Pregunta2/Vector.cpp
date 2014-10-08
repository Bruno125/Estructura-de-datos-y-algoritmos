#include "stdafx.h"
#include "Vector.h"


CVector::CVector(void)
{

}
//-----------------------------------
CVector::~CVector(void)
{
	for (int i=0; i<vec.size(); i++)
		delete vec[i];
	//vec.clear();
}
//-----------------------------------
bool CVector::insertar(int codigo, char* nombre, double precio, int cupos)
{
	CTour *tour = dameTour(codigo);
	if (tour != NULL)
		return false;

	tour = new CTour();
	tour->setCodigo(codigo);
	tour->setNombre(nombre);
	tour->setPrecio(precio);
	tour->setCupos(cupos);
	vec.push_back(tour);
	
	return true;
}
//-----------------------------------
void CVector::mostrarEnConsola()
{
	double suma = 0.0;
	for (int i=0; i<vec.size(); i++)
	{
		suma += vec[i]->getVendidas() * vec[i]->getPrecio();
		printf("%10d %-30s %8.2lf %4d/%4d S/.%8.2lf\n",
			vec[i]->getCodigo(),
			vec[i]->getNombre(),
			vec[i]->getPrecio(),
			vec[i]->getVendidas(),
			vec[i]->getCupos(),
			vec[i]->getVendidas() * vec[i]->getPrecio()
		);
	}
	printf("\nTOTAL VENDIDO: S/.%8.2lf\n", suma);
}
//-----------------------------------
bool CVector::venderEntrada(int codigo, int cantEntradas)
{
	CTour *tour = dameTour(codigo);
	if (tour == NULL)
		return false;

	return tour->registrarVenta(cantEntradas);
}
//-----------------------------------
CTour* CVector::dameTour(int codigo)
{
	for (int i=0; i<vec.size(); i++)
	{
		if (vec[i]->getCodigo() == codigo)
			return vec[i];
	}
	return NULL;
}
//-----------------------------------
void CVector::guardarEnArchivo()
{
	FILE *arch = fopen("VENTAS.DAT", "wb");
	if (arch == NULL)
		return;

	int cantTours = vec.size();
	fwrite(&cantTours, sizeof(cantTours), 1, arch);

	for (int i=0; i<vec.size(); i++)
		vec[i]->guardarEnArchivo(arch);

	fclose(arch);
}
//-----------------------------------
void CVector::cargarDeArchivo()
{
	FILE *arch = fopen("VENTAS.DAT", "rb");
	if (arch == NULL)
		return;

	for (int i=0; i<vec.size(); i++)
		delete vec[i];
	vec.clear();

	int cantTours;
	fread(&cantTours, sizeof(cantTours), 1, arch);

	for (int i=0; i<cantTours; i++)
	{
		CTour* aux = new CTour();
		aux->cargarDeArchivo(arch);
		vec.push_back(aux);
	}

	fclose(arch);
}
//-----------------------------------