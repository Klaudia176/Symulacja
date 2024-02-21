#include <iostream>
#include "Wedkarz_sredniozaawansowany.h"

using namespace std;

Wedkarz_sredniozaawansowany::Wedkarz_sredniozaawansowany()
{

}
Wedkarz_sredniozaawansowany::Wedkarz_sredniozaawansowany(int x, int y)
{
	this->x = x;
	this->y = y;
	czyZlowionoRybe = 0;
	czyHaczykWWodzie = 1;
}

void Wedkarz_sredniozaawansowany::ZlowRybe(Ryba rybaD)
{
	if (rybaD.CzyJestDrapiezna() == 0) return;
	cout << "sredni" << endl;
	zlowionaRyba = rybaD;
	czyZlowionoRybe = 1;
	czyHaczykWWodzie = 0;
	rybaD.Umieraj();
}