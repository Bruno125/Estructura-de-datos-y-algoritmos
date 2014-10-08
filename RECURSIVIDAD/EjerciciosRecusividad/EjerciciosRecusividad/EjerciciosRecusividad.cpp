// EjerciciosRecusividad.cpp : main project file.

#include "stdafx.h"
#include "Lista.h"
#include <math.h>

using namespace System;

void recusividadConLista()
{
	CLista *lista = new CLista();
	lista->Add(50);
	lista->Add(40);
	lista->Add(30);
	lista->Add(20);
	lista->Add(10);
	lista->AddOrdenado(5);

	lista->Imprimir();
	lista->ImprimirAlReves();
	delete lista;
}
int numTriangular(int N){

	if(N<=1)
		return 1;
	return numTriangular(N-1)+N;
}

int fibbonacci(int N){
	if(N<=0)
		return 0;
	if(N==1)
		return 1;
	return fibbonacci(N-1)+fibbonacci(N-2);
}

void trianguloinvertido(int N){
	if(N<=0)	return;
	for(int i=0;i<N;i++)
		printf("*");
	printf("\n");
	trianguloinvertido(N-1);
}

void trianguloNormal(int N){
	if(N<=0)	return;
	trianguloNormal(N-1);
	for(int i=0;i<N;i++)
		printf("*");
	printf("\n");
}

void imprimeAlReves(int N){
	if(N<=0)	return;
	printf("%d",N%10);
	imprimeAlReves(N/10);
}

void imprimecaracteres(int n){
	if(n<=0)	return;
	printf("*");
	imprimecaracteres(n-1);
}


void trianguloSinFor(int i){
	if(i<=0)	return;
	trianguloSinFor(i-1);
	imprimecaracteres(i);
	printf("\n");
}



int main(array<System::String ^> ^args)
{
	/*for(int i=1;i<=10;i++)
		printf("%5d",fibbonacci(i));*/
	//trianguloinvertido(8);
	//trianguloNormal(5);
	//imprimeAlReves(1234578);
	trianguloSinFor(8);
	recusividadConLista();
    getchar();
    return 0;
}
