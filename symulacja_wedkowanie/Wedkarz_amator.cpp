#include <iostream>
#include "Wedkarz_amator.h"

using namespace std;

Wedkarz_amator::Wedkarz_amator()
{

}

Wedkarz_amator::Wedkarz_amator(int x, int y)
{
	this->x = x;
	this->y = y;
	czyZlowionoRybe = 0;
	czyHaczykWWodzie = 1;
}

void Wedkarz_amator::ZlowRybe(Ryba ryba)
{
	//nic nie ³owi
}