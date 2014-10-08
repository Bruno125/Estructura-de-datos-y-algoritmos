#include "stdafx.h"
#include "Nodo.h"
#include <stdio.h>

CNodo::CNodo(void)
{
	izq=der=NULL;
}

CNodo::~CNodo(void)
{
}


int CNodo::getDato(){
	return dato;
}
//-----------------------------------------------
void CNodo::setDato(int pDato){
	dato=pDato;
}
//-----------------------------------------------
CNodo* CNodo::getIzq(){
	return izq;
}
//-----------------------------------------------
void CNodo::setIzq(CNodo* nodo){
	izq=nodo;
}
//-----------------------------------------------
CNodo* CNodo::getDer(){
	return der;
}
//-----------------------------------------------
void CNodo::setDer(CNodo* nodo){
	der=nodo;
}
//-----------------------------------------------