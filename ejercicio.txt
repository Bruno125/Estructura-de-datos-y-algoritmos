// invertir.cpp : main project file.

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <string.h>
#include <iostream>
using namespace System;


void invertir(char *s,int inicio,int fin){
	int i=inicio,j=fin;
	char a,b;
	while(i<j){
		a=s[i];
		b=s[j];
		s[i++]=b;
		s[j--]=a;
	}
}

void invierteFrase(char* s,int n){
	invertir(s,0,n-1);
	int min=0,max;
	for(int i=0;i<n;i++)
		if(s[i]==' ' /*&& s[i+2]!=' '*/){
			max=i-1;
			invertir(s,min,max);
			min=i+1;
		}
	invertir(s,min,n-1);
}


int main(array<System::String ^> ^args)
{
	char *s=new char[100];
	strcpy(s,"YO SOY UPC");
    printf("%s",s);
	invierteFrase(s,strlen(s));
	printf("\n%s",s);
	_getch();
    return 0;
}
