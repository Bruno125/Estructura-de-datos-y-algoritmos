#include "stdafx.h"
#include "VectorDinamico.h"
#include <stdio.h>


template <Tipo> CVectorDinamico::CVectorDinamico(void)
{
	numElementos=0;
	numCasillas=5;
	vec=new Tipo[numCasillas];
}


template <Tipo> CVectorDinamico::~CVectorDinamico(void)
{
	delete []vec;
}

template <Tipo> bool CVectorDinamico::insertar(Tipo dato){
	if(numElementos>=numCasillas){
		int *aux=new Tipo[numCasillas*2];
		if(aux==NULL)
			return false;
		for(int i=0;i<numElementos;i++)
			aux[i]=vec[i];
		numCasillas=numCasillas*2;
		delete[] vec;
		vec=aux;
	}
	vec[numElementos++]=dato;
	return true;
}

template <Tipo> Tipo CVectorDinamico::getDatoEnPos(int pos){
	if(pos>=0 && pos<numElementos)
		return vec[pos];
	else
		return 0;
}
template <Tipo> int CVectorDinamico::getNumElementos(){
	return numElementos;
}
template <Tipo> int CVectorDinamico::getNumCasillas(){
	return numCasillas;
}

template <Tipo> int CVectorDinamico::buscar(Tipo dato){
	return 0;
}

template <Tipo>int CVectorDinamico::buscar(Tipo dato,int comenzandoEnEstaPos){
	return 0;
}

template <Tipo>int CVectorDinamico::eliminar(Tipo dato){
	return 0;
}

template <Tipo> bool CVectorDinamico::eliminarPos(int pos){
	return 0;
}