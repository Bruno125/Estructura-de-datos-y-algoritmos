#include "stdafx.h"
#include "ListaPostres.h"


CListaPostres::CListaPostres(void)
{
}
//-------------------------------------------
CListaPostres::~CListaPostres(void)
{
	list<CPostre*>::iterator it = postres.begin();
	while (it != postres.end())
	{
		delete (*it);
		it++;
	}
	postres.clear();
}
//-------------------------------------------
CPostre* CListaPostres::damePostre(int codigo)
{
	list<CPostre*>::iterator it = postres.begin();
	while (it != postres.end())
	{
		if (codigo == (*it)->getCodigo())
			return *it;
		it++;
	}
	return NULL;
}
//-------------------------------------------
bool CListaPostres::agregarPostre(int codigo, char* nombre)
{
	CPostre *postre = damePostre(codigo);
	if (postre != NULL)
		return false;

	postre = new CPostre();
	postre->setCodigo(codigo);
	postre->setNombre(nombre);
	postres.push_back(postre);
	return true;
}
//-------------------------------------------
void CListaPostres::imprimirPostres()
{
	list<CPostre*>::iterator it = postres.begin();
	while (it != postres.end())
	{
		printf("%d - %s\n", (*it)->getCodigo(), (*it)->getNombre());
		(*it)->imprimirIngredientes();
		printf("\n");
		it++;
	}
}
//-------------------------------------------
void CListaPostres::imprimirPostresConIngrediente(char *nombreIngrediente)
{
	list<CPostre*>::iterator it = postres.begin();
	while (it != postres.end())
	{
		if ((*it)->dameIngrediente(nombreIngrediente) != NULL)
		{
			printf("%d - %s\n", (*it)->getCodigo(), (*it)->getNombre());
		}
		it++;
	}
}
//-------------------------------------------

void CListaPostres::imprimirListaCompras(){
	CPostre* mezcla=new CPostre();
	list<CPostre*>::iterator itPostres=postres.begin();
	CIngrediente* ing;
	while(itPostres!=postres.end()){
		int n=(*itPostres)->getNIngredientes();
		int cont=0;
		while(cont<n){
			ing=(*itPostres)->dameIngrediente(cont);
			mezcla->agregarIngrediente(ing->getNombre(),ing->getCantidad());
			cont++;
		}
		itPostres++;
	}
	mezcla->imprimirIngredientes();


}