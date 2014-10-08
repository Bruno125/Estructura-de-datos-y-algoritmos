#include "stdafx.h"
#include "Obstaculo.h"
#include <stdlib.h>

CObstaculo::CObstaculo(int w,int h)
{
	X=rand() %w;
	Y=rand()%h;
	tama�o=20;
}


CObstaculo::~CObstaculo(void)
{
}

void CObstaculo::mostrar(System::Drawing::Graphics ^C){
	System::Drawing::SolidBrush ^brocha=gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow);
	C->FillEllipse(brocha,X,Y,tama�o,tama�o);
}



void CObstaculo::resetear(int w,int h){
	X=rand() %w-tama�o;
	Y=rand()%h-tama�o;
}

int CObstaculo::getX(){
	return X;
}
int CObstaculo::getY(){
	return Y;
}
int CObstaculo::getTama�o(){
	return tama�o;
}