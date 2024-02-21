#include <iostream>
#include "Ryba.h"

using namespace std;

Ryba::Ryba()
{
	x = 0;
	y = 0;
	srand(time(NULL));
}

void Ryba::Umieraj()
{
//	delete this;
}

int Ryba::LiczCzasOdOstatniegoJedzenia()
{
	int czas = GetTickCount64() - czasOdOstatniegoJedzenia;
	czasOdOstatniegoJedzenia += czas;
	return czasOdOstatniegoJedzenia/1000;
}

void Ryba::ZerujCzasOdOstatniegoJedzenia()
{
	czasOdOstatniegoJedzenia = 0;
}

int Ryba::ZwrocPozycjeX()
{
	return x;
}

int Ryba::ZwrocPozycjeY()
{
	return y;
}

void Ryba::ZapiszX(int x)
{
	this->x = x;
}

bool Ryba::CzyJestDrapiezna()
{
	return czyJestDrapiezna;
}

void Ryba::ZapiszY(int y)
{
	this -> y = y;
}

Ryba::~Ryba()
{

}