// Ejercicios de recursividad 2.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>


using namespace System;

void ordenar(int v[]){


}

void invertirArreglo(int v[],int izq,int der){
	if(izq>der)	return;
	int aux=v[izq];
	v[izq]=v[der];
	v[der]=aux;
	invertirArreglo(v,izq+1,der-1);
	
	return;
}

int invertirNumero(int n,int acum){
	if(n<=0)	
		return acum;
	acum=acum*10+n%10;
	return invertirNumero(n/10,acum);
}


/*int invertirNumero(int n){
	if(n<=0)	
		return 0;
	int aux=n;
	int acum=1;
	while(aux>9){
		aux/=10;
		acum*=10;
	}
	return 	invertirNumero(n-acum*aux)*10 +aux;
}*/



void imprimeAbecedario(char c){
	if(c<'a')	return;
	imprimeAbecedario(c-1);
	printf("%c",c);


}



int repeticionesCaracter(char c,char s[],int n){
	
	int agrega=0;
	if(s[n]==c)	agrega=1;
	return repeticionesCaracter(c,s,n-1);
}


void colocaComas(int n){
	
	
}

bool primo(int n,int d){
	if(d<=1)	return true;
	if(n%d==0)	return false;
	return primo(n,d-1);
}

bool es_primo(int n){
	return primo(n,n-1);
}


int main(array<System::String ^> ^args)
{
	/*int n=6;
	int v[6]={5,3,8,9,2,1}; 
	invertirArreglo(v,0,n-1);
	for(int i=0;i<n;i++){
		printf("%5d",v[i]);
	}*/
	/*int num=4001;
	printf("Original: %5d \nNuevo: %5d",num,invertirNumero(num,0));*/

	//imprimeAbecedario('g');
	
	/*int num=10;
	printf("%5d es primo?",num);
	if(es_primo(num))	printf(" si");	else printf(" no");*/




	getchar();
    return 0;
}
