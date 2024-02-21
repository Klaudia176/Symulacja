#include <iostream>
#include <cstdlib>
#include "Mapa.h"
#include "Wedkarz_amator.h"
#include "Wedkarz_poczatkujacy.h"
#include "Wedkarz_sredniozaawansowany.h"
#include "Wedkarz_zaawansowany.h"

using namespace std;

Mapa::Mapa()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i > 1) TablicaPol[i][j].CzyJestWoda = true;
		}
	}
	srand(time(NULL));
}

void Mapa::DodajRybyNaMape()
{
	int NoweIleRybR = ileRybR;
	int index = 0;
	int poprzednieX = -1;
	int poprzednieY = -1;
	for (int i = 0; i < NoweIleRybR; i++)
	{
		int y = WylosujIntBezPowtorzen(0, 9, poprzednieX);
		int x = WylosujIntBezPowtorzen(0, 9, poprzednieY);
 
		if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestRybaR)
		{
			NoweIleRybR++;
			poprzednieX = x;
			poprzednieY = y;
			continue;
		}
		WymaganaIloscRybR[index].ZapiszX(x);
		WymaganaIloscRybR[index].ZapiszY(y);;
		TablicaPol[x][y].CzyJestRybaR = 1;
		index++;
	}
	int NoweIleRybD = ileRybD;
	index = 0;
	poprzednieX = -1;
	poprzednieY = -1;
	for (int i = 0; i < NoweIleRybD; i++)
	{
		int y = WylosujIntBezPowtorzen(0, 9, poprzednieX);
		int x = WylosujIntBezPowtorzen(0, 9, poprzednieY);
		if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaR || TablicaPol[x][y].CzyJestRybaD)
		{
			NoweIleRybD++;
			poprzednieX = x;
			poprzednieY = y;
			continue;
		}
		WymaganaIloscRybD[index].ZapiszX(x);
		WymaganaIloscRybD[index].ZapiszY(y);
		TablicaPol[x][y].CzyJestRybaD = 1;
		index++;
	}
}

int Mapa::WylosujIntBezPowtorzen(int start, int koniec, int poprzednioWylosowana)
{
	int los = (rand() % koniec + 1) + start;
	if (los == poprzednioWylosowana) return WylosujIntBezPowtorzen(start, koniec, los);
	return los;
}

void Mapa::PrzypiszTabliceRybR(Ryba ryby[], int ileRybR)
{
	WymaganaIloscRybR = ryby;
	this->ileRybR = ileRybR;
}

void Mapa::OdswiezMape()
{
	cout << "haczyki: " << ileHaczykow << endl;
	cout << "ryby R: " << ileRybR << endl;
	cout << "ryby D: " << ileRybD << endl;
	cout << "rosliny: " << ileRoslin << endl;
}

void Mapa::PrzypiszTabliceRybD(Ryba ryby[], int ileRybD)
{
	WymaganaIloscRybD = ryby;
	this->ileRybD = ileRybD;
}

void Mapa::PrzypiszTabliceRoslin(Roslina rosliny[], int ileRoslin)
{
	WymaganaIloscRoslin = rosliny;
	this->ileRoslin = ileRoslin;
}

void Mapa::DodajRybeD(Ryba ryba)
{
	int y = WylosujIntBezPowtorzen(0, 9, -1);
	int x = WylosujIntBezPowtorzen(0, 9, -1);

	if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestRybaR)
	{
		return DodajRybeD(ryba);
	}
	else
	{
		WymaganaIloscRybD[ileRybD] = ryba;

		WymaganaIloscRybD[ileRybD].ZapiszX(x);
		WymaganaIloscRybD[ileRybD].ZapiszY(y);
		cout << "DODANO RYBE D: " << x << ", " << y << endl;
		TablicaPol[x][y].CzyJestRybaD = 1;
		ileRybD++;
	}

}

void Mapa::DodajRybeR(Ryba ryba)
{
	int y = WylosujIntBezPowtorzen(0, 9, -1);
	int x = WylosujIntBezPowtorzen(0, 9, -1);

	if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestRybaR)
	{
		return DodajRybeR(ryba);
	}
	else
	{
		WymaganaIloscRybR[ileRybR] = ryba;

		WymaganaIloscRybR[ileRybR].ZapiszX(x);
		WymaganaIloscRybR[ileRybR].ZapiszY(y);
		TablicaPol[x][y].CzyJestRybaR = 1;
		ileRybR++;
	}
}

void Mapa::DodajRosline(Roslina roslina)
{
	int y = WylosujIntBezPowtorzen(0, 9, -1);
	int x = WylosujIntBezPowtorzen(0, 9, -1);

	if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestRybaR)
	{
		return DodajRosline(roslina);
	}
	else
	{
		WymaganaIloscRoslin[ileRoslin] = roslina;

		WymaganaIloscRoslin[ileRoslin].ZapiszX(x);
		WymaganaIloscRoslin[ileRoslin].ZapiszY(y);
		TablicaPol[x][y].CzyJestRoslina = 1;
		ileRoslin++;
	}
}

void Mapa::UsunRosline(int x, int y)
{
	int pozycjaRoslinyWTab = 1000;
	for (int i = 0; i < ileRybR; i++)
	{
		if (WymaganaIloscRoslin[i].ZwrocX() == x && WymaganaIloscRoslin[i].ZwrocY() == y)
		{
			pozycjaRoslinyWTab = i;
		}
		else if (i > pozycjaRoslinyWTab)
		{
			WymaganaIloscRoslin[i - 1] = WymaganaIloscRoslin[i];
		}
	}
	ileRoslin--;
}

void Mapa::DodajRoslinyNaMape()
{
	ileRoslin = 10;
	int NoweIleRoslin = ileRoslin;
	int poprzednieX = -1;
	int poprzednieY = -1;
	for (int i = 0; i < NoweIleRoslin; i++)
	{
		int y = WylosujIntBezPowtorzen(0, 9, poprzednieX);
		int x = WylosujIntBezPowtorzen(0, 9, poprzednieY);

		if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestHaczyk || TablicaPol[x][y].CzyJestRybaR || TablicaPol[x][y].CzyJestRoslina)
		{
			NoweIleRoslin++;
			poprzednieX = x;
			poprzednieY = y;
			continue;
		}

		WymaganaIloscRoslin[i].ZapiszY(y);
		WymaganaIloscRoslin[i].ZapiszX(x);
		TablicaPol[x][y].CzyJestRoslina = 1;
	}
}

void Mapa::DodajHaczykNaMape(Haczyk &haczyk)
{
	int y = (rand() % 10);
	int x = (rand() % 10) ;

	if (!TablicaPol[x][y].CzyJestWoda || TablicaPol[x][y].CzyJestRoslina || TablicaPol[x][y].CzyJestRybaR || TablicaPol[x][y].CzyJestRybaD || TablicaPol[x][y].CzyJestHaczyk)
	{ 
		return DodajHaczykNaMape(haczyk);
	}

	ileHaczykow++;
	haczyk.ZapiszX(x);
	haczyk.ZapiszY(y);
	WymaganaIloscHaczykow[ileHaczykow - 1] = haczyk;
	TablicaPol[x][y].CzyJestHaczyk = 1;
}

void Mapa::AktualizujRybyDlaPola(int x, int y, bool rybaR, bool rybaD)
{
	TablicaPol[x][y].CzyJestRybaD = rybaD;
	TablicaPol[x][y].CzyJestRybaR = rybaR;
}

void Mapa::UsunRybeR(int x,int y)
{
	int pozycjaRybyWTab = 1000;
	for (int i = 0; i < ileRybR; i++)
	{
		if (WymaganaIloscRybR[i].ZwrocPozycjeX() == x && WymaganaIloscRybR[i].ZwrocPozycjeY() == y)
		{
			pozycjaRybyWTab = i;
		}
		else if (i > pozycjaRybyWTab)
		{
			WymaganaIloscRybR[i - 1] = WymaganaIloscRybR[i];
		}
	}
	ileRybR--;
}

void Mapa::UsunRybeD(int x, int y)
{
	int pozycjaRybyWTab = 1000;
	for (int i = 0; i < ileRybD; i++)
	{
		if (WymaganaIloscRybD[i].ZwrocPozycjeX() == x && WymaganaIloscRybD[i].ZwrocPozycjeY() == y)
		{
			pozycjaRybyWTab = i;
		}
		else if (i > pozycjaRybyWTab)
		{
			WymaganaIloscRybD[i - 1] = WymaganaIloscRybD[i];
		}
	}
	ileRybD--;
}

void Mapa::AktualizujIloscHaczykow(int ile)
{
	ileHaczykow = ile;
}

void Mapa::AktualizujIloscRoslin(int ile)
{
	ileRoslin = ile;
}

void Mapa::AktualizujIloscRybR(int ile)
{
	ileRybR = ile;
}

void Mapa::AktualizujIloscRybD(int ile)
{
	ileRybD = ile;
}

void Mapa::AktualizujHaczykDlaPola(int x, int y, bool cond)
{
	TablicaPol[x][y].CzyJestHaczyk = cond;
}

void Mapa::AktualizujRoslineDlaPola(int x, int y, bool cond)
{
	TablicaPol[x][y].CzyJestRoslina = cond;
}

Pole Mapa::PobierzPozycjePola(int x, int y)
{
	return TablicaPol[x][y];
}

