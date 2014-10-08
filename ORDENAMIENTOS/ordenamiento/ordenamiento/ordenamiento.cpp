// ordenamiento.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

using namespace System;

void imprimir(int *vec,int n){
	for(int i=0;i<n;i++)
		printf("%5d",vec[i]);

	printf("\n");
}

void ordenamientoIntercambio(int *vec,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(vec[i]> vec[j]){
				int temp=vec[i];
				vec[i]=vec[j];
				vec[j]=temp;
			}
		}
	}

}

void BurbujaModificada(int *vec,int n){
	for(int i=0;i<n-1;i++){
		bool ordenado=true;
		for(int j=0;j<n-i-1;j++){
			if(vec[j]>vec[j+1]){
				int temp=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=temp;
				ordenado=false;
			}

		}
		if(ordenado==true)
			return;
	}
}

void ordenarSeleccion(int *vec,int n){
	int k,menor;
	for(int i=0;i<n;i++){
		k=i;
		menor=vec[i];
		for(int j=i+1;j<n;j++){
			if(vec[j]<menor){
				menor=vec[j];
				k=j;
			}
		}
		vec[k]=vec[i];
		vec[i]=menor;

	}
}

void ordenarInsercion(int *vec,int n){

	/*for(int j=1;j<n;j++){
		int k=j-1;
		do{
			if(vec[k]>vec[k+1]){
				int temp=vec[k];
				vec[k]=vec[k+1];
				vec[k+1]=temp;
				k--;
			}
			else
				break;
		}while(k>=0);

	}*/
		

	int aux, k;
	for (int i=1; i<n; i++)
	{
		aux = vec[i];
		k = i-1;
		while (k >= 0 && aux < vec[k])
		{
			vec[k+1] = vec[k];
			k--;
		}
		vec[k+1] = aux;
	}
}

void dameNumMayor(int *vec,int n,int nmovimientos){
	
}






int main(array<System::String ^> ^args)
{
    int N=6;
	int *vec=new int[N];
	/*vec[0]=9;
	vec[1]=9;
	vec[2]=3;
	vec[3]=9;
	vec[4]=4;
	vec[5]=9;*/
	


	for(int i=0;i<N;i++){
		vec[i]=rand() %10;
	}

	imprimir(vec,N);

	//ordenamientoIntercambio(vec,N);
	//BurbujaModificada(vec,N);
	ordenarSeleccion(vec,N);
	//ordenarInsercion(vec,N);

	//dameNumMayor(vec,N,1);

	imprimir(vec,N);

	

	getchar();



	delete[] vec;
    return 0;
}
