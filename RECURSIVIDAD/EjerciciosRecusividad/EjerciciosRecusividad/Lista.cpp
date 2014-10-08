#include "stdafx.h"
#include "Lista.h"

CLista::CLista(void)
{
	inicio = NULL;
}
//---------------------------------
CLista::~CLista(void)
{
	while (inicio != NULL)
	{
		CNodo* aEliminar = inicio;
		inicio = inicio->getNext();
		delete aEliminar;
	}
}
//---------------------------------
bool CLista::Add(int dato)
{
	CNodo *nuevo = new CNodo();
	if (nuevo == NULL)
		return false;
	nuevo->setDato(dato);
	nuevo->setNext(inicio);

	inicio = nuevo;
	return true;
}

bool CLista::AddOrdenado(int dato){
	return agregaordenado(inicio,dato);
}

bool CLista::agregaordenado(CNodo* nodo,int dato){

	if(nodo==inicio && nodo->getDato()>dato){
		CNodo* nuevo=new CNodo();
		nuevo->setDato(dato);
		nuevo->setNext(inicio);
		inicio=nuevo;
		return true;
	}

	if(nodo->getNext()==NULL){
		CNodo* nuevo=new CNodo();
		nuevo->setDato(dato);
		nuevo->setNext(NULL);
		nodo->setNext(nuevo);
		return true;
	}

	if(nodo->getNext()->getDato()>=dato){
		//inserta el dato aqui
		CNodo* nuevo=new CNodo();
		nuevo->setDato(dato);
		nuevo->setNext(nodo->getNext());
		nodo->setNext(nuevo);
		return true;
	}
	else
		return agregaordenado(nodo->getNext(),dato);



}


//---------------------------------
void CLista::Imprimir()
{
	printf("Impresion simple:\n");
	CNodo* aux = inicio;
	while (aux != NULL)
	{
		printf("%5d", aux->getDato());
		aux = aux->getNext();
	}
	printf("\n\n");
}
//---------------------------------
void CLista::ImprimirAlReves()
{
	printf("Impresion al reves:\n");
	imprimeAlReves(inicio);
	printf("\n\n");
}
//---------------------------------

void CLista::imprimeAlReves(CNodo* aux){
	if(aux==NULL)	return;
	imprimeAlReves(aux->getNext());
	printf("%5d",aux->getDato());
}