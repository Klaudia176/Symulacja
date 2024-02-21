#include <iostream>
#include "Haczyk.h"

using namespace std;

Haczyk::Haczyk()
{
}
int Haczyk::ZwrocX()
{
	return x;
}

int Haczyk::ZwrocY()
{
	return y;
}

void Haczyk::ZapiszX(int x)
{
	this->x = x;
}

void Haczyk::ZapiszY(int y)
{
	this->y = y;
}

void Haczyk::ZahaczRybe(Ryba ryba)
{

}

Haczyk::~Haczyk()
{

}