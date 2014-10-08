#pragma once

template <class T>
class CVector
{
private:
	static const int MAX=100;
	T vec[MAX];
	int ne;

public:
	CVector(void);
	~CVector(void);
	bool Insertar(T dato);
	T getDatoEnPos(int pos);
	int getN();
	bool InsertarSinDuplicados(T dato);
	int Eliminar(T dato);
	bool EliminarDuplicados();
	int buscar(T dato);
	T buscaMayor();
	T buscaMenor();
	T hallaPromedio();
	void OrdenarAscendente();
	void OrdernarDescendiente();
	T datoMasRepetido();
	void eliminarPares();
	void eliminarImpares();

	void intercambiar(T a,T b);


};

