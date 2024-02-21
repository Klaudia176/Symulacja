#pragma once
#include <iostream>
#include "windows.h"

using namespace std;

class Ryba
{
protected:
	int x;
	int y;
	bool czyJestDrapiezna;
	int czasOdOstatniegoJedzenia = 0; //w sekundach
public:
	Ryba();
	void Umieraj();
	int LiczCzasOdOstatniegoJedzenia();
	void ZerujCzasOdOstatniegoJedzenia();
	int ZwrocPozycjeX();
	int ZwrocPozycjeY();
	void ZapiszX(int x);
	void ZapiszY(int y);
	virtual bool CzyJestDrapiezna();
	~Ryba();
};