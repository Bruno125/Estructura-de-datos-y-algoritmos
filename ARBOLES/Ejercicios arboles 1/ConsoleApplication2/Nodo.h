#pragma once
class CNodo
{
private:
	int dato;
	CNodo* izq;
	CNodo* der;
public:
	CNodo(void);
	~CNodo(void);

	int getDato();
	void setDato(int pDato);
	CNodo* getIzq();
	void setIzq(CNodo* nodo);
	CNodo* getDer();
	void setDer(CNodo* nodo);

};

