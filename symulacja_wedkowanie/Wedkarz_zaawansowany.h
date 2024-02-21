#pragma once
#include <iostream>
#include "Wedkarz.h"
#include "Ryba.h"

using namespace std;

class Wedkarz_zaawansowany : public Wedkarz
{
public:
	Wedkarz_zaawansowany();
	Wedkarz_zaawansowany(int x, int y);
	void ZlowRybe(Ryba ryba) override;
};