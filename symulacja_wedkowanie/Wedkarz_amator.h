#pragma once
#include <iostream>
#include "Wedkarz.h"
#include "Ryba.h"

using namespace std;

class Wedkarz_amator : public Wedkarz
{
public:
	Wedkarz_amator();
	Wedkarz_amator(int x, int y);
	void ZlowRybe(Ryba ryba) override;
};