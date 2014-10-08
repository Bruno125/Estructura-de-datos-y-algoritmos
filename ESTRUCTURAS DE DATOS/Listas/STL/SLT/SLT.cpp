// SLT.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

int main(array<System::String ^> ^args)
{
    /*vector<int> vecInt;
	for(int i=0;i<1;i++){
		vecInt.push_back(i);
		//printf("Pos %d = %d (%d / %d)\n",i,vecInt[i],vecInt.size(),vecInt.capacity());
	}

	printf("Imprimiendo\n");
	for(int i=0;i<vecInt.size();i++){
		printf("%4d",vecInt[i]);
	}
	printf("\nTerminado\n");

	printf("Imprimiendo\n");
	vector<int>::iterator it1=vecInt.begin();
	while(it1!=vecInt.end()){
		printf("%4d",*it1);
		it1++;
	};
	printf("\nTerminado\n");*/

	list<int> lista;
	for(int i=0;i<20;i++)
		lista.push_back(i);

	list<int>::iterator it=lista.begin();
	while(it!=lista.end())
	{
		printf("%4d",*it);
		it++;
		if(it!=lista.end())
			it++;
	}
	list<int>::iterator itTemp=lista.begin();
	printf("\nTemporal: %d\n",*itTemp);

	itTemp=lista.end();
	itTemp--;
	printf("\nTemporal: %d\n",*itTemp);

	list<int>::reverse_iterator itRev=lista.rbegin();
	printf("\nTemporal: %d\n",*itRev);
	while(itRev!=lista.rend()){
		printf("%4d",*itRev);
		itRev++;
	}



	getchar();
    return 0;
}
