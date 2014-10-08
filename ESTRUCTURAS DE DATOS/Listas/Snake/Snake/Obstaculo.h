#pragma once
class CObstaculo
{
private:
	int X,Y;
	int tamaño;
public:
	CObstaculo(int w,int h);
	~CObstaculo(void);
	void mostrar(System::Drawing::Graphics ^C);
	void resetear(int w,int h);
	int getX();
	int getY();
	int getTamaño();
};

