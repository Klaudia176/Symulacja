#pragma once
#include <iostream>
#include "Ryba.h"
#include "Roslina.h"

using namespace std;

class Ryba_roslinozerna : public Ryba
{
public: 
	Ryba_roslinozerna(int x, int y);
	void JedzRosline(Roslina roslina);
};