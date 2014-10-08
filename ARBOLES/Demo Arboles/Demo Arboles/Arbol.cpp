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
		CNodo* nuevo = new CNodo();
		nuevo->setDato(dato);
		raiz=nuevo;
		return true;
	}
	CNodo* aux=raiz;
	while(true){
		if(aux->getDato()==dato)
			return false;
		else if(dato < aux->getDato()){
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

//--------------------------------
void CArbol::recorridoInorden(void (*imprime)(int)){
	_recorridoInorden(imprime,raiz);

}
//--------------------------------

void CArbol::_recorridoInorden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	_recorridoInorden(imprime,nodo->getIzq());
	imprime(nodo->getDato());
	_recorridoInorden(imprime,nodo->getDer());

}

void CArbol::recorridoPreorden(void (*imprime)(int)){
	_recorridoPreorden(imprime,raiz);

}
//--------------------------------

void CArbol::_recorridoPreorden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	imprime(nodo->getDato());
	_recorridoInorden(imprime,nodo->getIzq());
	_recorridoInorden(imprime,nodo->getDer());
}

void CArbol::recorridoPostorden(void (*imprime)(int)){
	_recorridoPostorden(imprime,raiz);

}
//--------------------------------

void CArbol::_recorridoPostorden(void (*imprime)(int),CNodo* nodo){
	if(nodo==NULL)	return;
	_recorridoInorden(imprime,nodo->getIzq());
	_recorridoInorden(imprime,nodo->getDer());
	imprime(nodo->getDato());
}

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

void CArbol::espejo(){
	_espejo(raiz);

}

void CArbol::_espejo(CNodo* nodo){
	if(nodo==NULL)	return;

	CNodo* aux=nodo->getIzq();
	nodo->setIzq(nodo->getDer());
	nodo->setDer(aux);
	_espejo(nodo->getIzq());
	_espejo(nodo->getDer());
}

