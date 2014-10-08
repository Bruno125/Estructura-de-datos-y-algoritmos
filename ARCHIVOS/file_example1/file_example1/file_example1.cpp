// file_example1.cpp : main project file.


#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>


using namespace System;

int main(array<System::String ^> ^args)
{
	/*
	FILE *arch=fopen("EJEMPLO.TXT","wt");
	fprintf(arch,"Hola mundo!!!\n");
	fprintf(arch,"La suma de 5+6=%d\n",5+6);
	fclose(arch);
	*/

	//LECTURA DESDE ARCHIVO
	/*
	FILE *arch=fopen("HISTORIA.TXT","rt");
	if(arch==NULL){
		printf("El juego no tiene historia...");
		getchar();
		return 0;
	}*/
	
	/*
	while(!feof(arch)){
		/*
		LEER CARACTER POR CARACTER
		char c=fgetc(arch);
		printf("%c",c);
		Sleep(50);
		*/

		/*
		LEER LINEA POR LINEA
		char cad[1000];
		fgets(cad,1000,arch);
		puts(cad);
		Sleep(200);
		*/
	//}
	/*
	FILE *arch=fopen("DATOS.TXT","rt");
	if(arch!=NULL){
		int nAlumnos;
		double suma=0;
		fscanf(arch,"%d",&nAlumnos);
		for(int i=0;i<nAlumnos;i++){
			double nota;
			char nombre[100];
			fscanf(arch,"%lf\n",&nota);
			fgets(nombre,100,arch);
			printf("%.3lf %s\n",nota,nombre);
			suma+=nota;
		}
		printf("El promedio es %.3lf",suma/nAlumnos);
	}

	system("notepad.exe DATOS.TXT");

	getchar();
	*/


	//CREAR UN ARCHIVO DE ENTEROS SI NO EXISTE
	//FILE *arch=fopen("DATOS.DAT","rb");
	//srand(time(NULL));
	//if(arch==NULL){
	//	arch=fopen("DATOS.DAT","wb");
	//	int c= rand() %20+5;
	//	for(int i=0;i<c;i++){
	//		int a=i+1;
	//		fwrite(&a,sizeof(a),1,arch);
	//	}
	//	fclose(arch);
	//	printf("El archivo se ha creado!!");
	//}
	//else{
	//	fseek(arch,0,SEEK_END);
	//	int nEnteros=ftell(arch)/sizeof(int);
	//	fseek(arch,0,SEEK_SET);
	//	int num;
	//	for(int i=0;i<nEnteros;i++){
	//		fread(&num,sizeof(int),1,arch);
	//		printf("%d\n",num);
	//	}
	//}
	////system("notepad.exe DATOS.DAT");
	//getchar();


	//COPIAR UN ARCHIVO

	FILE *origen=fopen("E:\\demo.pptx","rb");
	FILE *destino = fopen("E:\\demo_copia","wb");

	while(!feof(origen)){
		double c=fgetc(origen);
		fputc(c,destino);
	}
    return 0;
}
