#include "stdafx.h"
#include "Bigint.h"

CBigint::CBigint(void)
{
	inicio = NULL;
	final = NULL;
	esPositivo=true;

}

CBigint::CBigint(char* numero){
	inicio = NULL;
	final = NULL;
	esPositivo=true;

	int nDigitos=strlen(numero);
	if(nDigitos==0)
		return;
	if(nDigitos==1  && numero[0]=='-')
		return;
	int pos=0;
	if(numero[pos]=='-'){
		esPositivo=false;
		pos++;
	}
	for(int i=0;i<nDigitos;i++){
		char caracter=numero[i];
		if(caracter>='0' && caracter<='9'){
			int digito=caracter-'0';
			InsertarAlFinal(digito);
		}
	}
}


//--------------------------------------------------
CBigint::CBigint(int numero){
	inicio = NULL;
	final = NULL;
	esPositivo=true;

	if(numero==0)
		return;
	if(numero<0){
		esPositivo=false;
		numero*=-1; //Para manejar solo positivos
	}
	while(numero>0){
		InsertarAlInicio(numero%10);
		numero/=10;
	}

}

CBigint::CBigint(CBigint *numero){
	inicio = NULL;
	final = NULL;
	esPositivo=numero->esPositivo;
	CNodo *aux=numero->inicio;
	while(aux!=NULL){
		InsertarAlFinal(aux->getDato());
		aux=aux->getNext();
	}
}


CBigint::~CBigint(void)
{
	while (inicio != NULL)
		EliminarAlInicio();
}
//--------------------------------------------------
bool CBigint::InsertarAlInicio(int dato)
{
	// Crear el nodo nuevo
	CNodo* nuevo = new CNodo();
	if (nuevo == NULL)
		return false;
	nuevo->setDato(dato);
	nuevo->setPrev(NULL);
	nuevo->setNext(inicio);

	if (inicio != NULL)
		inicio->setPrev(nuevo);
	else
		final = nuevo;
	inicio = nuevo;
	return true;
}
//--------------------------------------------------
bool CBigint::InsertarAlFinal(int dato)
{
	if (inicio == NULL)
		 return InsertarAlInicio(dato);
		
	CNodo* nuevo = new CNodo();
	nuevo->setDato(dato);
	nuevo->setNext(NULL);
	nuevo->setPrev(final);
	final->setNext(nuevo);
	final = nuevo;
	return true;
}
//--------------------------------------------------
bool CBigint::EliminarAlInicio()
{
	if (inicio == NULL)
		return false;

	CNodo* aEliminar = inicio;
	inicio = inicio->getNext();
	if (inicio != NULL)
		inicio->setPrev(NULL);
	else
		final = NULL;
	delete aEliminar;
	return true;
}
//--------------------------------------------------

void CBigint::Imprimir(){
	if(!esPositivo)
		printf("-");
	if(inicio==NULL)
		printf("0");
	else{
		CNodo *aux=inicio;
		while(aux!=NULL){
			printf("%d ",aux->getDato());
			aux=aux->getNext();
		}
	}
}

void CBigint::masmas(){
	CBigint* temp=new CBigint(1);
	mas(temp);
	delete temp;
}
void CBigint::mas(int numero){
	CBigint *temp=new CBigint(numero);
	mas(temp);
	delete temp;
}
void CBigint::mas(char* numero){
	CBigint *temp=new CBigint(numero);
	mas(temp);
	delete temp;
}
void CBigint::mas(CBigint* numero){

	CNodo* r1=final;
	CNodo* r2=numero->final;
	CBigint* temp=new CBigint();
	int sumatemp=0;
	int llevar=0;

	while(r1!=NULL && r2!=NULL){
		sumatemp=r1->getDato()+r2->getDato();
		if(llevar!=0){
			sumatemp+=llevar;
			llevar=0;
		}
		if(sumatemp>=10){
			llevar++;
			sumatemp-=10;
		}
		r1->setDato(sumatemp);
		r1=r1->getPrev();
		r2=r2->getPrev();
		sumatemp=0;
	}
	if(llevar!=0){
		sumatemp=llevar;
		if(r1!=NULL){
			sumatemp+=r1->getDato();
			if(sumatemp>=10)	r1->setDato(0);
			else				r1->setDato(sumatemp);
		}
		if(r2!=NULL){
			sumatemp+=r2->getDato();
			if(sumatemp>=10)	r2->setDato(0);
			else				r2->setDato(sumatemp);
		}
		this->InsertarAlInicio(1);
	}
	
}


void CBigint::restamas(){
	CBigint* temp=new CBigint(1);
	resta(temp);
	delete temp;
}
void CBigint::resta(int numero){
	CBigint *temp=new CBigint(numero);
	resta(temp);
	delete temp;
}
void CBigint::resta(char* numero){
	CBigint *temp=new CBigint(numero);
	resta(temp);
	delete temp;
}


void CBigint::resta(CBigint* numero){
	CNodo* r1=final;
	CNodo* r2=numero->final;
	CBigint* temp=new CBigint();
	int restatemp=0;
	int llevar=0;

	while(r1!=NULL && r2!=NULL){
		restatemp=r1->getDato()+llevar-r2->getDato();
		if(restatemp<0)
			llevar=-1;
		else
			llevar=0;
		r1->setDato(restatemp);
		r1=r1->getPrev();
		r2=r2->getPrev();
		restatemp=0;
	}
	if(llevar!=0){
		restatemp=llevar;
		if(r1!=NULL){
			restatemp+=r1->getDato();
			if(restatemp<=0)	this->EliminarAlInicio();
			else				r1->setDato(restatemp);
			return;
		}
		esPositivo=false;
	}
}