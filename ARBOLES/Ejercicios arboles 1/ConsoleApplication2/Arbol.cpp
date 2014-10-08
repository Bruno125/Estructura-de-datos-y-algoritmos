#include "stdafx.h"
#include "Arbol.h"


CArbol::CArbol(void)
{
	raiz=NULL;
}


CArbol::~CArbol(void)
{
}

bool CArbol::insertar(int dato){
	if(raiz==NULL){
		CNodo* nuevo=new CNodo();
		nuevo->setDato(dato);
		raiz=nuevo;
		return true;
	}

	CNodo* aux=raiz;
	while(true){
		if(dato==aux->getDato())
			return false;
		else if(dato<aux->getDato()){
			if(aux->getIzq()==NULL){
				CNodo* nuevo=new CNodo();
				nuevo->setDato(dato);
				aux->setIzq(nuevo);
				return true;
			}
			else
				aux=aux->getIzq();
		}
		else{
			if(aux->getDer()==NULL){
				CNodo* nuevo=new CNodo();
				nuevo->setDato(dato);
				aux->setDer(nuevo);
				return true;
			}
			else
				aux=aux->getDer();
		}
	}
}
//-----------------------------------------------
void CArbol::insertarVarios(int arreglo[],int n){
	for(int i=0;i<n;i++)
		insertar(arreglo[i]);
}
//-----------------------------------------------
void CArbol::recorridoPreOrden(void (*imprime)(int)){
	_recorridoPreOrden(imprime,raiz);
}
//-----------------------------------------------
void CArbol::recorridoInOrden(void (*imprime)(int)){
	_recorridoInOrden(imprime,raiz);
}
//-----------------------------------------------
void CArbol::recorridoPostOrden(void (*imprime)(int)){
	_recorridoPostOrden(imprime,raiz);
}
//-----------------------------------------------
void CArbol::recorridoPorNivel(void (*imprime)(int)){
	if(raiz==NULL)	return;
	queue<CNodo*> cola;
	cola.push(raiz);
	while(!cola.empty()){
		CNodo* aux=cola.front();
		cola.pop();
		imprime(aux->getDato());
		if(aux->getIzq()!=NULL)	cola.push(aux->getIzq());
		if(aux->getDer()!=NULL)	cola.push(aux->getDer());
	}
}



//-----------------------------------------------
void CArbol::_recorridoPreOrden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	imprime(nodo->getDato());
	_recorridoPreOrden(imprime,nodo->getIzq());
	_recorridoPreOrden(imprime,nodo->getDer());

}
//-----------------------------------------------
void CArbol::_recorridoInOrden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	_recorridoInOrden(imprime,nodo->getIzq());
	imprime(nodo->getDato());
	_recorridoInOrden(imprime,nodo->getDer());
}
//-----------------------------------------------
void CArbol::_recorridoPostOrden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	_recorridoPostOrden(imprime,nodo->getIzq());
	_recorridoPostOrden(imprime,nodo->getDer());
	imprime(nodo->getDato());
}

//-----------------------------------------------
void CArbol::espejo(){
	_espejo(raiz);
}
//-----------------------------------------------
void CArbol::_espejo(CNodo* nodo){
	if(nodo==NULL)	return;

	CNodo* aux=nodo->getIzq();
	aux->setIzq(aux->getDer());
	aux->setDer(aux);
	_espejo(aux->getIzq());
	_espejo(aux->getDer());
}
//-----------------------------------------------
int CArbol::dameCantidadHijos(CNodo* nodo){
	if(nodo==NULL)	return 0;
	int c=0;
	if(nodo->getIzq()!=NULL) c++;
	if(nodo->getDer()!=NULL) c++;

	c=c+dameCantidadHijos(nodo->getIzq())+dameCantidadHijos(nodo->getDer());
	return c;
}
//-----------------------------------------------
bool CArbol::equilibrado(){
	if(raiz==NULL)	return true;


	int izq=0,der=0;
	if(raiz->getIzq()==NULL) izq=0;
	else	izq=1+dameCantidadHijos(raiz->getIzq());

	if(raiz->getDer()==NULL) der=0;
	else	der=1+dameCantidadHijos(raiz->getDer());

	return izq==der;

}