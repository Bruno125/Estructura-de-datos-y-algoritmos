#include "StdAfx.h"
#include "ListaDoble.h"
#include "stdio.h"

CListaDoble::CListaDoble(int x,int y,int tamaño)
{
	CNodo* primero=new CNodo();
	primero->setPrev(NULL);
	primero->setNext(NULL);
	primero->setPosicion(x,y);
	primero->setTamaño(tamaño);
	cont=1;
	primero->setColor(cont);
	cont=0;
	primero->setVar(0,0);
	inicio=final=primero;
	this->tamaño=tamaño;
}

CListaDoble::~CListaDoble(void)
{
}

bool CListaDoble::AgregarAlFinal(){
	CNodo* nuevo=new CNodo();
	if(nuevo==NULL)
		return false;
	
	nuevo->setPrev(final);
	nuevo->setNext(NULL);
	nuevo->setTamaño(tamaño);
	final->setNext(nuevo);

	if(final->getDx()>0){
		nuevo->setPosicion(final->getX()-tamaño,final->getY());/*Se mueve a la derecha*/
	}
	else{
		if(final->getDx()<0)	nuevo->setPosicion(final->getX()+tamaño,final->getY());/*Se mueve a la izquierda*/
		else{
			if(final->getDy()>0)		nuevo->setPosicion(final->getX(),final->getY()-tamaño);/*Se mueve abajo*/
			else	nuevo->setPosicion(final->getX(),final->getY()+tamaño);/*Se mueve arriba*/
		}
	}
	nuevo->setVar(final->getDx(),final->getDy());
	nuevo->setColor(cont);
	final=nuevo;
	if(cont==1)
		cont=0;
	else
		cont=1;

	return true;
}

void CListaDoble::mostrarTodos(System::Drawing::Graphics ^C){
	CNodo* ref=inicio;
	while(ref!=NULL){
		ref->mostrar(C);
		ref=ref->getNext();
	}
}
void CListaDoble::moverTodos(int gWidth,int gHeight){
	CNodo* ref=inicio;
	while(ref!=NULL){
		ref->mover(gWidth,gHeight);
		ref=ref->getNext();
	}
}

bool CListaDoble::colision(int px,int py,int w,int h){
	int x=inicio->getX();
	int y=inicio->getY();

	int px1,py1,px2,py2,px3,py3,px4,py4;
	px1=px3=px;
	py1=py2=py;
	px2=px4=px+w;
	py3=py4=py+h;

	int pex1,pex2,pex3,pex4,pey1,pey2,pey3,pey4;
	pex1=pex3=x;
	pex2=pex4=x+tamaño;
	pey1=pey2=y;
	pey3=pey4=y+tamaño;

	bool cond1=((px1<pex1 && pex1<px2) && (py1<pey1 && pey1<py3));
	bool cond2=((px1<pex2 && pex2<px2) && (py1<=pey2 && pey2<py3));
	bool cond3=((px1<pex3 && pex3<px2) && (py1<pey3 && pey3<py3));
	bool cond4=((px1<pex4 && pex4<px2) && (py1<pey4 && pey4<py3));

	if(	( cond1 || cond2 || cond3 || cond4 ) )
		return true;
	return false;
	/*if(x>=px && x<=py+w && y>=py&& y<=py+h)
		return true;
	else
		return false;*/
}

bool CListaDoble::colisionPropia(){

	CNodo* ref=inicio->getNext();
	if(ref==NULL)
		return false;
	while(ref!=NULL){
		bool hay_col=colision(ref->getX(),ref->getY(),tamaño,tamaño);
		if(hay_col)
			return true;
		ref=ref->getNext();
	}
	return false;

}


void CListaDoble::cambiaDireccion(Direccion dir){
	int dx=20;
	int dy=20;
	switch(dir){
		case IZQUIERDA:
			inicio->setVar(-dx,0);
			break;
		case DERECHA:
			inicio->setVar(dx,0);
			break;
		case ARRIBA:
			inicio->setVar(0,-dy);
			break;
		case ABAJO:
			inicio->setVar(0,dy);
			break;
	}
}