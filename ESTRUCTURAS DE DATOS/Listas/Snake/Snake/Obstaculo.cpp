#include "stdafx.h"
#include "Obstaculo.h"
#include <stdlib.h>

CObstaculo::CObstaculo(int w,int h)
{
	X=rand() %w;
	Y=rand()%h;
	tamaño=20;
}


CObstaculo::~CObstaculo(void)
{
}

void CObstaculo::mostrar(System::Drawing::Graphics ^C){
	System::Drawing::SolidBrush ^brocha=gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow);
	C->FillEllipse(brocha,X,Y,tamaño,tamaño);
}



void CObstaculo::resetear(int w,int h){
	X=rand() %w-tamaño;
	Y=rand()%h-tamaño;
}

int CObstaculo::getX(){
	return X;
}
int CObstaculo::getY(){
	return Y;
}
int CObstaculo::getTamaño(){
	return tamaño;
}