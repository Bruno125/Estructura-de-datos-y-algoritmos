
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Persona.h"
#include "Vector.h"

using namespace System;

int main()
{
	CVector *vec=new CVector();
	CPersona *persona=new CPersona();
	int contador=20;
	bool perdio=false;

	//Vemos si se puede cargar el archivo
	FILE *arch=fopen("JUEGO.DAT","rb");
	if(arch!=NULL){
		fseek(arch,0,SEEK_END);
		persona->cargarDeArchivo(arch);
		vec->cargarDeArchivo(arch);
		fclose(arch);
	}


	while(true){

		if(_kbhit()){
			char c=_getch();
			if(c=='a') persona->izquierda();
			if(c=='d')persona->derecha();
			if(c=='w') persona->arriba();
			if(c=='s') persona->abajo();
			if(c=='b') break;
		}

		if(vec->colision(persona)){
			Console::SetCursorPosition(35,11);
			printf("GAME OVER!!!!");
			perdio=true;
			Sleep(100);
			flushall();
			getch();
			break;
		}


		if(contador>=20)
			vec->agregarP(rand()%80,rand()%24);

		//Movimientos
		Console::Clear();
		vec->dibujarTodas();
		persona->dibujar();

		vec->moverTodas();
		contador++;
		Sleep(100);
		
	}

	//Vemos si se puede cargar el archivo
	arch=fopen("JUEGO.DAT","wb");
	if(arch!=NULL){
		persona->guardarEnArchivo(arch);
		vec->guardarEnArchivo(arch);
		fclose(arch);
	}
	if(perdio)
		remove("JUEGO.DAT");

	delete vec;
	delete persona;
	return 0;
}

