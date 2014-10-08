// Ejercicios de recursividad.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

int multiplicacion(int a,int b){
	if(a<=1)	return b;
	if(b<=1)	return a;
	return multiplicacion(a,b-1) + a;
}

int residuo(int a,int b){
	if(a<=b)	return a;
	return residuo(a-b,b);
}

int cociente(int a,int b){
	if(a<b)	return 0;
	return cociente(a-b,b)+1;
}

int exponencialDe2(int a){
	if(a<=1)	return 2;
	return multiplicacion(exponencialDe2(a-1),2);
}

int xN(int x,int n){
	if(n<=1)	return x;
	return xN(x,n-1)*x;
}

int factorial(int n){
	if(n<=1)	return 1;
	return factorial(n-1)*n;
}


double ecuacion(int x,int n){
	return xN(x,n)*1.0/factorial(n);
}

int mayor(int v[],int ne){
	if(ne<=1)	return v[ne];

	if(v[ne-1]>=mayor(v,ne-1))
		return v[ne-1];
	else
		return mayor(v,ne-1);
}


int suma(int v[],int ne){
	if(ne<=0)	return 0;
	return suma(v,ne-1)+v[ne-1];
}

double promedio(int v[],int ne){
	return suma(v,ne)*1.0/ne;
	
}

void alreves(int n){
	if(n<=0)	return;
	printf("%d",n%10);
	alreves(n/10);
}

int sumadedigitos(int n){
	if(n<=0)	return 0;
	return sumadedigitos(n/10)+n%10;
}

int busquedaBinaria(int v[],int min,int max,int dato){
	int pos_a_comparar=min+(max-min)/2;
	if(v[pos_a_comparar]==dato)
		return pos_a_comparar;
	else{
		if(max-min==1)	max=min;
		if(max==min)	
			return -1;
		if(v[pos_a_comparar]<dato)	min=pos_a_comparar;
		if(v[pos_a_comparar]>dato)	max=pos_a_comparar;

		return busquedaBinaria(v,min,max,dato);
	}

}


int main(array<System::String ^> ^args)
{
	//printf("%5d",multiplicacion(2,5));
	//printf("%5d",residuo(112,10));
	//printf("%5d",cociente(14,3));
	//printf("%5d",exponencialDe2(5));
	//printf("%5llf",ecuacion(2,4));
	/*
	int vec[5]={1,3,4,7,5};
	//printf("%5d",mayor(vec,5));
	//printf("%5d",suma(vec,5));
	printf("%5llf",promedio(vec,5));
	*/

	//alreves(1234);
	//printf("%5d",sumadedigitos(12345));
	int vec[5]={1,3,4,5,7};
	printf("Pos: %5d",busquedaBinaria(vec,0,5,7));


	getchar();
    return 0;
}
