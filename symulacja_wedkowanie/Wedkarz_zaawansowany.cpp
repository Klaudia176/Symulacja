#include <iostream>
#include "Wedkarz_zaawansowany.h"

using namespace std;

Wedkarz_zaawansowany::Wedkarz_zaawansowany()
{

}
Wedkarz_zaawansowany::Wedkarz_zaawansowany(int x, int y)
{
	this->x = x;
	this->y = y;
	czyZlowionoRybe = 0;
	czyHaczykWWodzie = 1;
}

void Wedkarz_zaawansowany::ZlowRybe(Ryba ryba)
{
	cout << "zaawansowany" << endl;
	zlowionaRyba = ryba;
	czyZlowionoRybe = 1;
	czyHaczykWWodzie = 0;
	ryba.Umieraj();
}