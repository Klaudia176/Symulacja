#pragma once
#include <iostream>
#include "Wedkarz.h"
#include "Ryba_drapiezna.h"

using namespace std;

class Wedkarz_sredniozaawansowany : public Wedkarz
{
public:
	Wedkarz_sredniozaawansowany();
	Wedkarz_sredniozaawansowany(int x, int y);
	void ZlowRybe(Ryba rybaD) override;
};
