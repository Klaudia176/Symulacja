#pragma once
#include <iostream>

using namespace std;

class Roslina
{
private:
	int x;
	int y;
public:
	Roslina();
	Roslina(int x, int y);
	void ZostanZjedzona();
	void ZapiszX(int x);
	void ZapiszY(int y);
	int ZwrocX();
	int ZwrocY();
	~Roslina();
};