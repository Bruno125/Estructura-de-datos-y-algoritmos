#include "stdafx.h"
#include "Nodo.h"

CNodo::CNodo(void)
{
	dato = 0;
	next = NULL;
	prev = NULL;
}
//-----------------------------------
CNodo::~CNodo(void)
{
}
//-----------------------------------
void CNodo::setDato(int pDato)
{
	dato = pDato;
}
//-----------------------------------
int CNodo::getDato()
{
	return dato;
}
//-----------------------------------
void CNodo::setNext(CNodo* pNext)
{
	next = pNext;
}
//-----------------------------------
CNodo* CNodo::getNext()
{
	return next;
}
//-----------------------------------
void CNodo::setPrev(CNodo* pPrev)
{
	prev = pPrev;
}
//-----------------------------------
CNodo* CNodo::getPrev()
{
	return prev;
}
//-----------------------------------