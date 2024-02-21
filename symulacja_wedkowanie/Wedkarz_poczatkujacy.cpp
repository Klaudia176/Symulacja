#include <iostream>
#include "Wedkarz_poczatkujacy.h"

using namespace std;

Wedkarz_poczatkujacy::Wedkarz_poczatkujacy()
{

}

Wedkarz_poczatkujacy::Wedkarz_poczatkujacy(int x, int y)
{
	this->x = x;
	this->y = y;
	czyZlowionoRybe = 0;
	czyHaczykWWodzie = 1;
}
bool Wedkarz_poczatkujacy::CzyHaczykWWodzie()
{
	return czyHaczykWWodzie;
}
bool Wedkarz_poczatkujacy::CzyJestRyba()
{
	return czyZlowionoRybe;
}
void Wedkarz_poczatkujacy::ZlowRybe(Ryba rybaR)
{
	cout << "Siema ryba1" << endl;
	if (rybaR.CzyJestDrapiezna() == 1) return;

	cout << "Siema ryba12" << endl;
	cout << "poczatkujacy" << endl;
	zlowionaRyba = rybaR;
	czyZlowionoRybe = 1;
	czyHaczykWWodzie = 0;
	rybaR.Umieraj();
}