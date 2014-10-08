// PilasColas.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

void imprimePila(stack<int> pila){
	while(!pila.empty()){
		printf("%4d",pila.top());
		pila.pop();
	}
}

int sumaNumeros(stack<int> pila){
	int c=0;
	while(!pila.empty()){
		c+=pila.top();
		pila.pop();
	}
	return c;
}

bool NumeroEstaEnPila(stack<int> pila,int n){
	while(!pila.empty()){
		if(n==pila.top())	return true;
		pila.pop();
	}
	return false;
}

void EliminarDuplicados(stack<int> &pila){
	stack<int> aux;
	while(!pila.empty()){
		if(!NumeroEstaEnPila(aux,pila.top()))
			aux.push(pila.top());
		pila.pop();
	}
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
}

int dameMayor(stack<int> pila){
	if(pila.empty())	return -1;
	int mayor=pila.top();
	while(!pila.empty()){
		if(pila.top()>mayor)	mayor=pila.top();
		pila.pop();
	}
	return mayor;
}

void sacarNumero(stack<int> &pila,int n){
	stack<int> aux;
	while(!pila.empty()){
		if(pila.top()!=n)	aux.push(pila.top());
		pila.pop();
	}
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}

}

void OrdernarPila(stack<int> & pila){
	stack<int> aux;
	while(!pila.empty()){
		int mayor=dameMayor(pila);
		sacarNumero(pila,mayor);
		aux.push(mayor);
	}
	
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}



}




int main(array<System::String ^> ^args)
{
	stack<int> pila;
	for(int i=10;i>0;i--){
		pila.push(i);
	}
	OrdernarPila(pila);

	imprimePila(pila);


	getchar();
    return 0;
}


