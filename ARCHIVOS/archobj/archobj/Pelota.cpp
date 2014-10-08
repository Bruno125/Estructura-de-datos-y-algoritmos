#include "stdafx.h"
#include "Pelota.h"

CPelota::CPelota(int px,int py)
{
	x=px;
	y=py;
	dx=dy=1;
}


CPelota::~CPelota(void)
{
}

void CPelota::Dibujar(){
	System::Console::SetCursorPosition(x,y);
	printf("0");
}
void CPelota::Mover(){
	if(x+dx<0 || x+dx>=79)
		dx*=-1;
	if(y+dy<0 || y+dy>=23)
		dy*=-1;
	x+=dx;
	y+=dy;
}

bool CPelota::choque(CPersona* persona){
	if(persona->getX()==x && persona->getY()==y)
		return true;
	else
		return false;
}

int CPelota::getX(){
	return x;
}
int CPelota::getY(){
	return y;
}

void CPelota::guardarEnArchivo(FILE *h){
	fwrite(&x,sizeof(x),1,h);
	fwrite(&y,sizeof(y),1,h);
}
void CPelota::cargarDeArchivo(FILE *h){
	fread(&x,sizeof(y),1,h);
	fread(&y,sizeof(y),1,h);
}