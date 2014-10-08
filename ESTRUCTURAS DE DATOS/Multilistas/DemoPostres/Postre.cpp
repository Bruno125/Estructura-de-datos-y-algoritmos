#include "stdafx.h"
#include "Postre.h"

CPostre::CPostre(void)
{
	codigo = 0;
	strcpy(nombre, "");
}
//----------------------------------
CPostre::~CPostre(void)
{
	list<CIngrediente*>::iterator it = ingredientes.begin();
	while (it != ingredientes.end())
	{
		delete (*it);
		it++;
	}
	ingredientes.clear();
}
//----------------------------------
void CPostre::setCodigo(int pCodigo)
{
	codigo = pCodigo;
}
//----------------------------------
int CPostre::getCodigo()
{
	return codigo;
}
//----------------------------------
void CPostre::setNombre(char* pNombre)
{
	strcpy(nombre, pNombre);
}
//----------------------------------
char* CPostre::getNombre()
{
	return nombre;
}
//----------------------------------
CIngrediente* CPostre::dameIngrediente(char *nombre)
{
	list<CIngrediente*>::iterator it = ingredientes.begin();
	CIngrediente* ing;
	while (it != ingredientes.end())
	{
		ing= *it;
		if (strcmp(nombre, ing->getNombre()) == 0)
			return ing;
		it++;
	}
	return NULL;
}
//----------------------------------
bool CPostre::agregarIngrediente(char *nombre, double cantidad)
{
	CIngrediente* ing = dameIngrediente(nombre);
	if (ing != NULL){
		//return false;
		ing->setCantidad(ing->getCantidad()+cantidad);
		return true;
	}
	
	ing = new CIngrediente();
	ing->setNombre(nombre);
	ing->setCantidad(cantidad);
	ingredientes.push_back(ing);
	return true;
}
//----------------------------------
void CPostre::imprimirIngredientes()
{
	list<CIngrediente*>::iterator it = ingredientes.begin();
	CIngrediente* ing;
	while (it != ingredientes.end())
	{
		ing=*it;
		printf("    - %5lf %s\n", ing->getCantidad(), ing->getNombre());
		it++;
	}
}
//----------------------------------

int CPostre::getNIngredientes(){
	return ingredientes.size();
}

CIngrediente* CPostre::dameIngrediente(int index){
	list<CIngrediente*>::iterator it = ingredientes.begin();
	int c=0;
	for(int i=0;i<index;i++)
		it++;
	return *it;
	
}