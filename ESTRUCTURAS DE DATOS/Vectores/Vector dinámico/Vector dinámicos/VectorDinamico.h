#pragma once
template <Tipo> class CVectorDinamico
{
private:
	Tipo *vec;
	int numElementos,numCasillas;
public:
	CVectorDinamico(void);
	~CVectorDinamico(void);

	bool insertar(Tipo dato);
	Tipo getDatoEnPos(int pos);
	int getNumElementos();
	int getNumCasillas();

	int buscar(Tipo dato);
	int buscar(Tipo dato,int comenzandoEnEstaPos);
	int eliminar(Tipo dato);
	bool eliminarPos(int pos);


};

