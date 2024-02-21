#pragma once
#include <iostream>
#include "Wedkarz.h"
#include "Ryba_roslinozerna.h"

using namespace std;

class Wedkarz_poczatkujacy : public Wedkarz
{
public:
	Wedkarz_poczatkujacy();
	Wedkarz_poczatkujacy(int x, int y);
	bool CzyHaczykWWodzie() override;
	bool CzyJestRyba() override;
	void ZlowRybe(Ryba rybaR) override;
};
