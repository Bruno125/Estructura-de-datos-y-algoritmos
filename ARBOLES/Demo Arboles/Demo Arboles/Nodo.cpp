#include "stdafx.h"
#include "Nodo.h"


CNodo::CNodo(void)
{
	dato=0;
	izq=der=NULL;
}


CNodo::~CNodo(void)
{
}

void CNodo::setDato(int dato){
	this->dato=dato;
}
//----------------------------------
int CNodo::getDato(){
	return dato;
}
//----------------------------------
void CNodo::setIzq(CNodo* nodo){
	izq=nodo;
}
//----------------------------------
CNodo* CNodo::getIzq(){
	return izq;
}
//----------------------------------
void CNodo::setDer(CNodo* nodo){
	der=nodo;
}
//----------------------------------
CNodo* CNodo::getDer(){
	return der;
}
//----------------------------------