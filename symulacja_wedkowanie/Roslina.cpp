#include <iostream>
#include "Roslina.h"

using namespace std;

Roslina::Roslina()
{

}

Roslina::Roslina(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Roslina::ZwrocX()
{
	return x;
}

int Roslina::ZwrocY()
{
	return y;
}

void Roslina::ZapiszX(int x)
{
	this->x = x;
}

void Roslina::ZapiszY(int y)
{
	this->y = y;
}

void Roslina::ZostanZjedzona()
{

}

Roslina::~Roslina()
{

}