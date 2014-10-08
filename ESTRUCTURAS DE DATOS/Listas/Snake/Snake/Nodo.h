#pragma once
#include <stdio.h>

enum Direccion {IZQUIERDA=0,DERECHA,ARRIBA,ABAJO};
class CNodo
{
private:
	int x,y,dx,dy,tamaño;
	CNodo* next;
	CNodo* prev;
	int posCambioX,posCambioY;
	int color;

public:
	CNodo(void);
	~CNodo(void);
	void mostrar(System::Drawing::Graphics ^C);
	void mover(int gWidth,int gHeight);
	void setNext(CNodo* pNext);
	void setPrev(CNodo* pPrev);
	CNodo* getNext();
	CNodo* getPrev();
	void setPosicion(int x,int y);
	void setTamaño(int t);
	int getX();
	int getY();
	void setColor(int c);
	void setVar(int DX,int DY);
	int getDx();
	int getDy();
};
