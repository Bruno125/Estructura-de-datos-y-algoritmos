// Ejercicios Pilas.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void imprimir(stack<int> pila){
	while(!pila.empty()){
		printf("%3d",pila.top());
		pila.pop();
	}

	printf("\n");

}

bool estaEnPila(stack<int> pila,int num){
	while(!pila.empty()){
		if(pila.top()==num)
			return true;
	}
	return false;
}

void eliminarDuplicado(stack<int> &pila){
	stack<int> aux;
	while(!pila.empty()){
		if(!estaEnPila(aux,pila.top()))
			aux.push(pila.top());
		pila.top();
	}
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}

}


void barajar(stack<int> &pila){
	stack<int> canastas[3];
	while(!pila.empty()){
		int r=rand()%3;
		canastas[r].push(pila.top());
		pila.pop();
	}

	for(int i=0;i<3;i++){
		while(!canastas[i].empty()){
			pila.push(canastas[i].top());
			canastas[i].pop();
		}
	}
}

void eliminarNoDuplicado(stack<int> & pila){
	stack<int> aux;
	while(!pila.empty()){
		if(estaEnPila(pila,pila.top()))
			aux.push(pila.top());
		pila.top();
	}
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
}


bool insertarEnPos(stack<int> &pila,int pos,int dato){
	if(pos<0 || pos>pila.size())
		return false;
	stack<int> aux;

	while(pos>0){
		aux.push(pila.top());
		pila.pop();
		pos--;
	}

	pila.push(dato);
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
	return true;

}

bool eliminarEnPos(stack<int> &pila,int pos){
	if(pos<0 || pos>=pila.size())
		return false;
	stack<int> aux;
	while(pos>0){
		aux.push(pila.top());
		pila.pop();
		pos--;
	}
	pila.pop();
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
	return true;

}

int peekEnPos(stack<int> pila,int pos){
	while(pos>0){
		pila.pop();
		pos--;
	}
	return pila.top();
}

bool intercambiarPosiciones(stack<int> &pila, int pos1,int pos2){
	if(pos1<0 || pos2<0 || pos1>=pila.size() || pos2>=pila.size())
		return false;
	
	int dato1,dato2;
	dato1=peekEnPos(pila,pos1);
	dato2=peekEnPos(pila,pos2);
	eliminarEnPos(pila,pos1);
	insertarEnPos(pila,pos1,dato2);
	eliminarEnPos(pila,pos2);
	insertarEnPos(pila,pos2,dato2);

}


void rotar(stack<int> &pila, int n){
	if(n<=0)	return;
	int datoFinal=peekEnPos(pila,pila.size()-1);
	stack<int> aux;
	/*while(pila.size()>1){
		aux.push(pila.top());
		pila.pop();
	}
	datoFinal=pila.top();
	pila.pop();
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
	pila.push(datoFinal);*/
	eliminarEnPos(pila,pila.size()-1);
	pila.push(datoFinal);
	rotar(pila,n-1);
	
}

void rotarInvertido(stack<int> & pila,int n){
	if(n<=0)	return;
	
	int datoArriba=pila.top();
	insertarEnPos(pila,pila.size(),datoArriba);
	eliminarEnPos(pila,0);
	rotarInvertido(pila,n-1);
}

int _dameMayor(stack<int> pila, int mayor){
	if(pila.empty())	return mayor;
	if(pila.top()>mayor)
		mayor=pila.top();
	pila.pop();
	return _dameMayor(pila,mayor);

}

int dameMayor(stack<int> pila){
	return _dameMayor(pila,pila.top());
}

int _dameMenor(stack<int> pila,int menor){
	if(pila.empty())	return menor;
	if(pila.top()<menor)
		menor=pila.top();
	pila.pop();
	return _dameMenor(pila,menor);
}


int dameMenor(stack<int> pila){
	return _dameMenor(pila,pila.top());
}

void invertir(stack<int> &pila){
	stack<int> aux;
	while(!pila.empty()){
		aux.push(pila.top());
		pila.pop();
	}
	stack<int> aux2;
	while(!aux.empty()){
		aux2.push(aux.top());
		aux.pop();
	}

	while(!aux2.empty()){
		pila.push(aux2.top());
		aux2.pop();
	}


}

void invertirMitades(stack<int> &pila){
	int tamaño=pila.size();
	int cont=0;
	stack<int> aux1;
	stack<int> aux2;
	while(cont<tamaño/2){
		aux1.push(pila.top());
		pila.pop();
		cont++;
	}
	while(cont<tamaño){
		aux2.push(pila.top());
		pila.pop();
		cont++;
	}
	invertir(aux1);
	invertir(aux2);

	while(!aux2.empty()){
		pila.push(aux2.top());
		aux2.pop();

	}

	while(!aux1.empty()){
		pila.push(aux1.top());
		aux1.pop();
	}


}

stack<int> intercalar(stack<int> pila1,stack<int>pila2){
	stack<int> aux;
	while(!pila1.empty() || !pila2.empty()){
		if(!pila1.empty()){
			aux.push(pila1.top());
			pila1.pop();
		}
		if(!pila2.empty()){
			aux.push(pila2.top());
			pila2.pop();
		}
	}
	return aux;

}


int _contarPares(stack<int> pila,int n){
	if(pila.empty())	return n;
	if(pila.top()%2==0)
		n++;
	pila.pop();
	return _contarPares(pila,n);
}

int contarPares(stack<int> pila){
	return _contarPares(pila,0);
}


int _contarImpares(stack<int> pila,int n){
	if(pila.empty())	return n;
	if(pila.top()%2!=0)
		n++;
	pila.pop();
	return _contarImpares(pila,n);
}

int contarImpares(stack<int> pila){
	return _contarImpares(pila,0);
}



void ordenarPorLongitud(stack<int> pila){
	
}


int main(array<System::String ^> ^args)
{
	srand(NULL);
	stack<int> pila;
	for(int i=6;i>0;i--)
		pila.push(i);
	stack<int> pila2;
	for(int i=0;i<5;i++)
		pila2.push(rand()%3);


	imprimir(pila);
	//barajar(pila);
	//eliminarDuplicado(pila);
	//insertarEnPos(pila,1,2);
	//eliminarEnPos(pila,0);
	//rotarInvertido(pila,1);
	//printf("Mayor: %5d",dameMayor(pila));
	//printf("Menor: %5d",dameMenor(pila));
	invertirMitades(pila);
	/*imprimir(pila2);
	stack<int> comb=intercalar(pila,pila2);*/

	//imprimir(pila);
	//printf("Impares: %5d", contarImpares(pila));
	imprimir(pila);
	getchar();
    return 0;
}
