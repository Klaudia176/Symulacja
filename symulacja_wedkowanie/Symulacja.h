#pragma once
#include <iostream>
#include "Mapa.h"
#include "windows.h"
#include <fstream>

using namespace std;

class Symulacja
{
private: 
	Mapa mapa;
	Ryba IlejestRybR[100];
	Ryba IlejestRybD[100];

	Roslina IlejestRoslin[20];
	Haczyk IlejestHaczykow[20];

	int aktualnaLiczbaRybR = 0;
	int aktualnaLiczbaRybD = 0;

	int aktualnaLiczbaHaczykow = 0;
	int aktualnaLiczbaRoslin = 0;

	int poczatkowaIloscRybR= 0;
	int poczatkowaIloscRybD= 0;
	int czasTrwania = 0; //sekundy
	int czasRozpoczecia = 0;
	bool symulacjaTrwa = false;
	int ileSieZahaczylo = 0; //test
public:
	Symulacja();
	Symulacja(int iloscRybD,int iloscRybR,int czasTrwania);
	void TworzMape();
	void PobierzIloscRybR(int iloscRybR);
	void PobierzIloscRybD(int iloscRybD);
	void ZapelnijTabliceRyb();
	void ZapelnijTabliceRoslin();
	void PobierzCzas(int czas);
	void OdliczajCzas();
	void Odswiez();
	void PoruszWszystkieRyby();
	Haczyk ZnajdzHaczykWTab(int x, int y);
	void ZaktualizujMape();
	void ZabijRybyKtoreDawnoNieJad³y();
	void UsunRybeZTab(Ryba ryba);
	void UsunRoslineZTab(Roslina roslina);
	void UsunHaczykZTab(Haczyk haczyk);
	void ZarzucWszystkieWedki();
	void ZapiszWynikiSymulacji(int liczbaHaczykow, int liczbaRybR, int liczbaRybD, int liczbaRoslin, int czasTrwania,
		int poczatkowaLiczbaRybR, int poczatkowaLiczbaRybD);
	bool ZwrocStanSymulacji();
	char ZwrocSymbolPola(Pole pole);
	void DodajRybeRDoTab(Ryba ryba, int index);
	void DodajRybeDDoTab(Ryba ryba, int index);
	void DodajRoslineDoTab(Roslina roslina, int index);
	void WyswietlMape();
	void ZarzucWedke();
	~Symulacja();
};

