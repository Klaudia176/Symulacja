#pragma once
#include <iostream>
#include "Wedkarz.h"
#include "Wedkarz_amator.h"
#include "Wedkarz_poczatkujacy.h"
#include "Wedkarz_sredniozaawansowany.h"
#include "Wedkarz_zaawansowany.h"
#include "Ryba.h"

using namespace std;

class Haczyk
{
private:
	int x;
	int y;
	int znak = 0;
public:	
	Haczyk();
	void ZahaczRybe(Ryba ryba);
	void ZapiszX(int x);
	void ZapiszY(int y);
	int ZwrocX();
	int ZwrocY();
	~Haczyk();
};