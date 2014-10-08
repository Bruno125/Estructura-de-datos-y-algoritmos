#include "stdafx.h"
#include "Vector.h"


CVector::CVector(void)
{
	ne=0;
}


CVector::~CVector(void)
{
	for(int i=0;i<ne;i++)
		delete vec[i];
}


bool CVector::agregarP(int x,int y){
	if(ne>=MAX)
		return false;
	vec[ne++]=new CPelota(x,y);
	return true;
}

bool CVector::colision(CPersona *persona){
	for(int i=0;i<ne;i++)
		if(vec[i]->choque(persona))
			return true;
	return false;
}

void CVector::dibujarTodas(){
	for(int i=0;i<ne;i++)
		vec[i]->Dibujar();
}
void CVector::moverTodas(){
	for(int i=0;i<ne;i++)
		vec[i]->Mover();
}

void CVector::guardarEnArchivo(FILE *h){
	fwrite(&ne,sizeof(ne),1,h);
	for(int i=0;i<ne;i++){
		vec[i]->guardarEnArchivo(h);
	}
}
void CVector::cargarDeArchivo(FILE *h){
	fread(&ne,sizeof(ne),1,h);
	int x,y;
	CPelota* p;
	for(int i=0;i<ne;i++){
		p=new CPelota(0,0);
		p->cargarDeArchivo(h);
		vec[i]=p;
		
	}


}