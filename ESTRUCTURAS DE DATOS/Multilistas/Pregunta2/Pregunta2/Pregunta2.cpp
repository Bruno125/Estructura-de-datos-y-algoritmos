// Pregunta2.cpp : main project file.

#include "stdafx.h"
#include "Vector.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	CVector *vec = new CVector();
	vec->cargarDeArchivo();

	int opcion;
	do
	{
		Console::Clear();
		printf("MENU\n");
		printf("====\n\n");
		printf("1. Insertar\n");
		printf("2. Vender\n");
		printf("3. Listado\n\n");
		printf("4. Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		flushall();

		if (opcion == 1)
		{
			int codigo, cupos;
			double precio;
			char nombre[50];
			printf("Ingrese codigo: ");
			scanf("%d", &codigo);
			printf("Ingrese nombre: ");
			flushall();
			gets(nombre);
			printf("Ingrese cupos: ");
			scanf("%d", &cupos);
			printf("Ingrese precio: ");
			scanf("%lf", &precio);

			if (vec->insertar(codigo, nombre, precio, cupos))
				printf("Gracias!! se inserto el tour\n\n");
			else
				printf("LO SENTIMOS. PUEDE SER QUE EL CODIGO YA EXISTA\n\n");

			flushall();
			getchar();
		}
		if (opcion == 2)
		{
			int codigo, cupos;
			printf("Ingrese codigo: ");
			scanf("%d", &codigo);
			printf("Ingrese cantidad a vender: ");
			scanf("%d", &cupos);

			if (vec->venderEntrada(codigo, cupos))
				printf("SE VENDIERON LAS ENTRADAS\n\n");
			else
				printf("ERROR. NO EXISTE EL TOUR O NO HAY ENTRADAS SUFICIENTES\n\n");

			flushall();
			getchar();
		}
		if (opcion == 3)
		{
			Console::Clear();
			vec->mostrarEnConsola();
			getchar();
		}
	}
	while (opcion != 4);

	vec->guardarEnArchivo();
	delete vec;
    return 0;
}
