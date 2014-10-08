// DemoPostres.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "ListaPostres.h"
//--------------------------------------
void listado(CListaPostres* postres)
{
	System::Console::Clear();
	printf("LISTADO DE POSTRES\n");
	printf("==================\n");
	postres->imprimirPostres();
	system("PAUSE");
}
//--------------------------------------
void agregarPostre(CListaPostres* postres)
{
	System::Console::Clear();
	printf("AGREGAR POSTRE\n");
	printf("==============\n");
	int codigo;
	char nombre[50];
	printf("Codigo: "); scanf("%d", &codigo); flushall();
	printf("Nombre: "); gets(nombre); flushall();
	if (postres->agregarPostre(codigo, nombre))
		printf("\n\nSE AGREGO CORRECTAMENTE\n\n");
	else
		printf("\n\nERROR!! PROBABLEMENTE EL CODIGO ESTE REPETIDO\n\n");
	system("PAUSE");
}
//--------------------------------------
void agregarIngrediente(CListaPostres* postres)
{
	System::Console::Clear();
	printf("AGREGAR INGREDIENTE\n");
	printf("===================\n");
	int codigo;
	double cantidad;
	char nombre[50];
	printf("Codigo: "); scanf("%d", &codigo); flushall();
	printf("Nombre: "); gets(nombre); flushall();
	printf("Cantidad: "); scanf("%lf", &cantidad); flushall();
	
	CPostre *postre = postres->damePostre(codigo);
	if (postre == NULL)
		printf("\n\nNO ENCONTRAMOS EL POSTRE\n\n");
	else
	{
		if (postre->agregarIngrediente(nombre, cantidad))
			printf("\n\nSE AGREGO EL INGREDIENTE\n\n");
		else
			printf("\n\nUPS!! INGREDIENTE REPETIDO\n\n");
	}

	system("PAUSE");
}
//--------------------------------------
void buscarPostre(CListaPostres* postres)
{
	System::Console::Clear();
	printf("BUSCAR POSTRE\n");
	printf("===================\n");
	int codigo;
	printf("Codigo: "); scanf("%d", &codigo); flushall();
	
	CPostre *postre = postres->damePostre(codigo);
	if (postre == NULL)
		printf("\n\nNO ENCONTRAMOS EL POSTRE\n\n");
	else
		postre->imprimirIngredientes();

	system("PAUSE");
}
//--------------------------------------
void buscarPorIngrediente(CListaPostres* postres)
{
	System::Console::Clear();
	printf("BUSCAR INGREDIENTE\n");
	printf("===================\n");
	char nombre[50];
	printf("Nombre: "); scanf("%d", &nombre); flushall();
	
	postres->imprimirPostresConIngrediente(nombre);

	system("PAUSE");
}
//--------------------------------------
void mostrarListaCompras(CListaPostres* postres)
{
	System::Console::Clear();
	printf("LISTA DE COMPRAS\n");
	printf("===================\n");
	
	postres->imprimirListaCompras();

	system("PAUSE");
}


//--------------------------------------
int main()
{
	CListaPostres* postres = new CListaPostres();
	int op;
	do
	{
		System::Console::Clear();
		printf("MENU\n");
		printf("====\n");
		printf("1. Lista de postres\n");
		printf("2. Agregar postre\n");
		printf("3. Agregar ingrediente\n");
		printf("4. Buscar postre\n");
		printf("5. Buscar por ingrediente\n");
		printf("6. Lista de Compras\n");
		printf("7. Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &op);
		flushall();

		switch (op)
		{
			case 1:
				listado(postres);
				break;
			case 2:
				agregarPostre(postres);
				break;
			case 3:
				agregarIngrediente(postres);
				break;
			case 4:
				buscarPostre(postres);
				break;
			case 5:
				buscarPorIngrediente(postres);
				break;
			case 6:
				mostrarListaCompras(postres);
				break;
		}
	}
	while (op != 7);

	delete postres;
    return 0;
}
