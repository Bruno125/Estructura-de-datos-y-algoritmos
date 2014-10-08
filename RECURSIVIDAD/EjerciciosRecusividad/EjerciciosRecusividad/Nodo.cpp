#include "stdafx.h"
#include "Nodo.h"


CNodo::CNodo(void)
{
	next = NULL;
}
//-------------------------------------
CNodo::~CNodo(void)
{
}
//-------------------------------------
int CNodo::getDato()
{
	return dato;
}
//-------------------------------------
void CNodo::setDato(int pDato)
{
	dato = pDato;
}
//-------------------------------------
CNodo* CNodo::getNext()
{
	return next;
}
//-------------------------------------
void CNodo::setNext(CNodo* pNext)
{
	next = pNext;
}
//-------------------------------------
