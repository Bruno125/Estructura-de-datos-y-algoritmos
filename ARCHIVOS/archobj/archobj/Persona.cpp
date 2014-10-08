#include "stdafx.h"
#include "Persona.h"


CPersona::CPersona(void)
{
	x=y=1;
}


CPersona::~CPersona(void)
{
}

void CPersona::dibujar(){
	System::Console::SetCursorPosition(x,y);
	printf("%c",1);
}

void CPersona::izquierda(){
	x--;
	if(x<0)
		x=1;
}
void CPersona::derecha(){
	x++;
	if(x>=80)
		x=79;
}
void CPersona::arriba(){
	y--;
	if(y<0)
		y=23;
}
void CPersona::abajo(){
	y++;
	if(y>=23)
		y=0;
}
int CPersona::getX(){
	return x;
}
int CPersona::getY(){
	return y;
}

void CPersona::guardarEnArchivo(FILE *h){
	fseek(h,0,SEEK_SET);
	fwrite(&x,sizeof(x),1,h);
	fwrite(&y,sizeof(y),1,h);
}
void CPersona::cargarDeArchivo(FILE *h){
	fseek(h,0,SEEK_SET);
	fread(&x,sizeof(y),1,h);
	fread(&y,sizeof(y),1,h);
}