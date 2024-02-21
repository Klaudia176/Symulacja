#pragma once
#include <iostream>
#include "Roslina.h"
#include "Haczyk.h"
#include "Ryba.h"

using namespace std;

struct Pole 
{
public:
	bool CzyJestWoda;
	bool CzyJestRybaR;
	bool CzyJestRybaD;
	bool CzyJestWedkarz;
	bool CzyJestRoslina;
	bool CzyJestHaczyk;
};

class Mapa
{
private:
	Pole TablicaPol[10][10];
	Ryba* WymaganaIloscRybR = new Ryba[100];
	Ryba* WymaganaIloscRybD = new Ryba[100];
	Roslina* WymaganaIloscRoslin = new Roslina[20];
	Haczyk* WymaganaIloscHaczykow = new Haczyk[20];
	int ileRybR;
	int ileRybD;
	int ileRoslin;
	int ileHaczykow;
public:
	Mapa();
	void PrzypiszTabliceRybR(Ryba Ryby[], int ileRybR);
	void PrzypiszTabliceRybD(Ryba Ryby[], int ileRybD);
	void PrzypiszTabliceRoslin(Roslina rosliny[], int ileRoslin);
	void DodajRybeD(Ryba ryba);
	void DodajRybeR(Ryba ryba);
	void DodajRosline(Roslina roslina);
	void UsunRybeD(int x, int y);
	void UsunRybeR(int x, int y);
	void UsunRosline(int x, int y);
	void OdswiezMape();
	int  WylosujIntBezPowtorzen(int start, int koniec, int ostatniaWylosowana);
	Pole PobierzPozycjePola(int x, int y);
	void AktualizujRybyDlaPola(int x, int y, bool rybaR, bool rybaD);
	void DodajRybyNaMape();
	void AktualizujHaczykDlaPola(int x, int y, bool cond);
	void AktualizujIloscHaczykow(int ile);
	void AktualizujIloscRybR(int ile);
	void AktualizujIloscRybD(int ile);
	void AktualizujIloscRoslin(int ile);
	void AktualizujRoslineDlaPola(int x, int y, bool cond);
	void DodajRoslinyNaMape();
	void DodajHaczykNaMape(Haczyk &haczyk);
};

