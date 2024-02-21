#include <iostream>
#include "Wedkarz.h"

using namespace std;

Wedkarz::Wedkarz()
{

}

Wedkarz::Wedkarz(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Wedkarz::ZapiszX(int x)
{
	this->x = x;
}

void Wedkarz::ZapiszY(int y)
{
	this->y = y;
}

void Wedkarz::ZlowRybe(Ryba ryba)
{
	cout << "NIEEE" << endl;
}

Ryba Wedkarz::ZwrocZlowionaRybe()
{
	return zlowionaRyba;
}

bool Wedkarz::CzyHaczykWWodzie()
{
	return czyHaczykWWodzie;
}
bool Wedkarz::CzyJestRyba()
{
	return czyZlowionoRybe;
}

void Wedkarz::ZarzucWedke()
{
	czyHaczykWWodzie = 1;
	czyZlowionoRybe = 0;
}

int Wedkarz::ZwrocX()
{
	return x;
}

int Wedkarz::ZwrocY()
{
	return y;
}