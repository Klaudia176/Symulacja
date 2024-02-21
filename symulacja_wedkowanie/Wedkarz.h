#pragma once
#include <iostream>
#include "Ryba.h"

using namespace std;

class Wedkarz
{
protected:
	Ryba zlowionaRyba;
	bool czyZlowionoRybe;
	bool czyHaczykWWodzie;
	int x;
	int y;
public:
	Wedkarz();
	Wedkarz(int x, int y);
	void ZapiszX(int x);
	void ZapiszY(int y);
	virtual void ZlowRybe(Ryba ryba);
	virtual bool CzyJestRyba();
	virtual bool CzyHaczykWWodzie();
	Ryba ZwrocZlowionaRybe();
	void ZarzucWedke();
	int ZwrocX();
	int ZwrocY();
};