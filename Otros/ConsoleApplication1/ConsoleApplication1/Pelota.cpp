#include "stdafx.h"
#include "Pelota.h"
#include <stdio.h>
#include <stdlib.h>

CPelota::CPelota(void)
{
	x=rand()%79;
	y=rand()%23;
	dx=rand()%7-3;
	dy=rand()&7-3;
}


CPelota::~CPelota(void)
{
}

void CPelota::dibujarMover(){
	System::Console::SetCursorPosition(x,y);
	printf("0");
	if(x+dx<0 || x+dx>79)
		dx*=-1;
	if(y+dy<0 || y+dy>24)
		dy*=-1;
	x+=dx;
	y+=dy;

}