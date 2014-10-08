// ConsoleApplication1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Pelota.h"
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <conio.h>
using namespace std;

int main(array<System::String ^> ^args)
{
    //CPelota *p=new CPelota();
	vector<CPelota*> vec;

	while(true){
		if(_kbhit()){
			vec.push_back(new CPelota());
		}
		System::Console::Clear();
		vector<CPelota*>::iterator it=vec.begin();
		while(it!=vec.end()){
			(*it)->dibujarMover();
			it++;
		}
		//p->dibujarMover();
		Sleep(100);
	}
    return 0;
}
