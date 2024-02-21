#pragma once
#include <iostream>
#include "Ryba.h"


using namespace std;

class Ryba_drapiezna : public Ryba
{
public:
	Ryba_drapiezna(int x, int y);
	void JedzRybeR(Ryba ryba);
};