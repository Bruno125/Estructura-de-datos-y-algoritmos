#include "stdafx.h"
#include "Vector.h"

/////////////////////////////////////////////////////////
template <class T>
CVector<T>::CVector(void)
{
	ne=0;
}

/////////////////////////////////////////////////////////
template <class T>
CVector<T>::~CVector(void)
{
}
/////////////////////////////////////////////////////////

template <class T> 
bool CVector<T>::Insertar(T dato){
	if(ne>=MAX)
		return false;
	vec[ne++]=dato;
	return true;
}
/////////////////////////////////////////////////////////
template <class T> 
T CVector<T>::getDatoEnPos(int pos){
	return vec[pos];
}
/////////////////////////////////////////////////////////
template <class T> 
int CVector<T>::getN(){
	return ne;
}

/////////////////////////////////////////////////////////
template <class T> 
bool CVector<T>::InsertarSinDuplicados(T dato){
	for(int i;i<ne;i++){
		if(vec[i]==dato)
			return false;
	}
	vec[ne++]=dato;
	return true;

}
/////////////////////////////////////////////////////////
template <class T> 
int CVector<T>::Eliminar(T dato){
	int c=0;
	for(int i=0;i<ne;i++){
		if(vec[i]==dato)
			c++;
		else
			vec[i-c]=vec[i];
	}
	return c;


}
/////////////////////////////////////////////////////////
template <class T> 
bool CVector<T>::EliminarDuplicados(){
	T aux[ne];
	for(int i=0;i<ne;i++)	aux[i]=0;
	for(int i=0;i<ne-1;i++){
		T dato=vec[i];
		for(int j=i+1;j<ne;j++){
			if(dato==vec[j])
				aux[i]++;
		}
	}
	return true;
}
/////////////////////////////////////////////////////////
template <class T> 
int CVector<T>::buscar(T dato){
	for(int i=0;i<ne;i++)
		if(dato==vec[i])
			return i;
	return -1;
}
/////////////////////////////////////////////////////////
template <class T> 
T CVector<T>::buscaMayor(){
	if(ne==0)
		return 0;
	T mayor=vec[0];
	for(int i=1;i<ne;i++)
		if(vec[i]>mayor)	mayor=vec[i];
	return mayor;
}
/////////////////////////////////////////////////////////
template <class T> 
T CVector<T>::buscaMenor(){
	if(ne==0)
		return 0;
	T menor=vec[0];
	for(int i=1;i<ne;i++)
		if(vec[i]<menor)	menor=vec[i];
	return menor;
}
/////////////////////////////////////////////////////////
template <class T> 
T CVector<T>::hallaPromedio(){
	T suma=0;
	for(int i=0;i<ne;i++){
		suma+=vec[i];
	}
	return suma/ne;
}
/////////////////////////////////////////////////////////
template <class T> 
void CVector<T>::OrdenarAscendente(){
	for(int i=0;i<ne-1;i++){
		T temp=vec[i];
		for(int j=i+1;j<ne;j++){
			if(temp>vec[j]){
				vec[i]=vec[j];
				vec[j]=temp;
				temp=vec[i];
			}
		}
	}

}


/////////////////////////////////////////////////////////
template <class T> 
void CVector<T>::OrdernarDescendiente(){
	for(int i=0;i<ne-1;i++){
		T temp=vec[i];
		for(int j=i+1;j<ne;j++){
			if(temp<vec[j]){
				vec[i]=vec[j];
				vec[j]=temp;
				temp=vec[i];
			}
		}
	}
}
/////////////////////////////////////////////////////////
template <class T> 
T CVector<T>::datoMasRepetido(){
	if(ne==0)
		return;

	T aux[ne];
	int c=0;
	for(int i=0;i<ne;i++){
		bool pasarDato=true;
		T dato=vec[i];
		for(int j=0;j<c;j++)
			if(dato==aux[j])
				pasarDato=false;
		if(pasarDato)
			aux[c++]=dato;
	}
	int mayorRep=0,cont=0;
	T datoMasRepetido=vec[];
	for(int i=0;i<c;i++){
		cont=0;
		for(j=0;j<ne;j++)
			if(vec[j]==aux[i])
				cont++;
		if(cont>mayorRep){
			mayorRep=cont;
			datoMasRepetido=vec[i];
		}

	}

}
/////////////////////////////////////////////////////////
template <class T> 
void CVector<T>::eliminarPares(){
}
/////////////////////////////////////////////////////////
template <class T> 
void CVector<T>::eliminarImpares(){
}
/////////////////////////////////////////////////////////