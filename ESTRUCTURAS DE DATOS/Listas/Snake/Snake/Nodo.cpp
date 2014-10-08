#include "StdAfx.h"
#include "Nodo.h"

CNodo::CNodo(void)
{
	next=prev=NULL;
	posCambioX=posCambioY=-100;
}

CNodo::~CNodo(void)
{
}

void CNodo::setColor(int c){
	color=c;
}

void CNodo::mostrar(System::Drawing::Graphics ^C){
	System::Drawing::SolidBrush ^brocha;
	if(color==1)
		brocha=gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(0,255,0));
	else
		brocha=gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(0,56,0));
	C->FillRectangle(brocha,x,y,tamaño,tamaño);
}
void CNodo::mover(int gWidth,int gHeight){
	if(x+dx<0 || x+dx>gWidth || y+dy<0 || y+dy>gHeight){
		//Salir
		return;
	}

	CNodo* anterior=this->getPrev();
	if(anterior==NULL){
		x+=dx;
		y+=dy;
		return;
	}

	if((dx!=anterior->getDx() && (x==anterior->getX()) || y==anterior->getY())){
		dx=anterior->getDx();
		dy=anterior->getDy();
		posCambioX=anterior->getX();
		posCambioY=anterior->getY();
	}
	x+=dx;
	y+=dy;
}

void CNodo::setNext(CNodo* pNext){
	next=pNext;
}
//////////////////////////////
void CNodo::setPrev(CNodo* pPrev){
	prev=pPrev;
}
//////////////////////////////
CNodo* CNodo::getNext(){
	return next;
}
//////////////////////////////
CNodo* CNodo::getPrev(){
	return prev;
}
//////////////////////////////
void CNodo::setPosicion(int x,int y){
	this->x=x;
	this->y=y;
}

void CNodo::setTamaño(int t){
	tamaño=t;
}

int CNodo::getX(){
	return x;
}

int CNodo::getY(){
	return y;
}

void CNodo::setVar(int DX,int DY){
	dx=DX;
	dy=DY;
}

int CNodo::getDx(){
	return dx;
}

int CNodo::getDy(){
	return dy;
}
