#include <iostream>
#include "Symulacja.h"
#include "Wedkarz_amator.h"
#include "Wedkarz_poczatkujacy.h"
#include "Wedkarz_sredniozaawansowany.h"
#include "Wedkarz_zaawansowany.h"

Symulacja::Symulacja()
{

}

Symulacja::Symulacja(int iloscRybD, int iloscRybR, int czasTrwania)
{
	czasRozpoczecia = GetTickCount64();
	PobierzIloscRybD(iloscRybD);
	PobierzIloscRybR(iloscRybR);
	PobierzCzas(czasTrwania);
	symulacjaTrwa = true;
	srand(time(NULL));
}

void Symulacja::ZapelnijTabliceRyb()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < poczatkowaIloscRybD; i++)
	{
		Ryba_drapiezna drapiezna(x,y);
		DodajRybeDDoTab(drapiezna, i);
		aktualnaLiczbaRybD++;
	}
	for (int i = 0; i < poczatkowaIloscRybR; i++)
	{
		Ryba_roslinozerna roslinozerna(x,y);
		DodajRybeRDoTab(roslinozerna, i);
		aktualnaLiczbaRybR++;
	}
}
void Symulacja::PobierzIloscRybR(int iloscRybR)
{
	poczatkowaIloscRybR = iloscRybR;
}

void Symulacja::PobierzIloscRybD(int iloscRybD)
{
	poczatkowaIloscRybD = iloscRybD;
}

void Symulacja::PobierzCzas(int czas)
{
	this->czasTrwania = czas * 1000;
}

void Symulacja::DodajRybeRDoTab(Ryba ryba, int index)
{
	IlejestRybR[index] = ryba;
}

void Symulacja::DodajRybeDDoTab(Ryba ryba, int index)
{
	IlejestRybD[index] = ryba;
}

void Symulacja::DodajRoslineDoTab(Roslina roslina, int index)
{
	IlejestRoslin[index] = roslina;
}

void Symulacja::Odswiez()
{
	PoruszWszystkieRyby();
	OdliczajCzas(); 
	//ZabijRybyKtoreDawnoNieJad³y();
	ZaktualizujMape();
	std::cout << endl;
	std::cout << "===========================================================================================" << endl<<endl;
}
void Symulacja::ZabijRybyKtoreDawnoNieJad³y()
{
	for (int i = 0; i < aktualnaLiczbaRybD; i++)
	{
		if (IlejestRybD[i].LiczCzasOdOstatniegoJedzenia() > 5)
		{
			UsunRybeZTab(IlejestRybD[i]);
		}
	}
	for (int i = 0; i < aktualnaLiczbaRybR; i++)
	{
		if (IlejestRybR[i].LiczCzasOdOstatniegoJedzenia() > 5)
		{
			UsunRybeZTab(IlejestRybR[i]);
		}
	}
}

void Symulacja::PoruszWszystkieRyby()
{
	for (int i = 0; i < aktualnaLiczbaRybD; i++)
	{
		int nowyX = (rand() % 3) - 1;
		int nowyY = (rand() % 3) - 1;
		int staryX = IlejestRybD[i].ZwrocPozycjeX();
		int staryY = IlejestRybD[i].ZwrocPozycjeY();
		int razemX = nowyX + staryX;
		int razemY = nowyY + staryY;
		Pole nowePole = mapa.PobierzPozycjePola(razemX, razemY);
		if (nowePole.CzyJestWoda && razemX < 10 && razemY < 10 && razemX >= 0 && razemY >= 0 && !nowePole.CzyJestRybaD)
		{
			IlejestRybD[i].ZapiszX(razemX);
			IlejestRybD[i].ZapiszY(razemY);
			mapa.AktualizujRybyDlaPola(staryX, staryY, 0, 0);
			mapa.AktualizujRybyDlaPola(razemX, razemY, 0, 1);

			if (nowePole.CzyJestHaczyk == 1)
			{
				for (int j = 0; j < aktualnaLiczbaHaczykow; j++)
				{
					if (IlejestHaczykow[j].ZwrocX() == razemX && IlejestHaczykow[j].ZwrocY() == razemY)
					{
						IlejestHaczykow[j].ZahaczRybe(IlejestRybD[i]);
						UsunHaczykZTab(IlejestHaczykow[j]);
						UsunRybeZTab(IlejestRybD[i]);
						ZarzucWedke();
					}
				}
				mapa.AktualizujHaczykDlaPola(razemX, razemY, 0);
				mapa.AktualizujRybyDlaPola(razemX, razemY, 0, 0);
				cout << "Trafilo na haczyk " << razemX << ", " << razemY << endl;
				ileSieZahaczylo++;
			}
			else if(nowePole.CzyJestRybaR == 1)
			{
				for (int j = 0; j < aktualnaLiczbaRybR; j++)
				{
					if (IlejestRybR[j].ZwrocPozycjeX() == razemX && IlejestRybR[j].ZwrocPozycjeY() == razemY)
					{
						UsunRybeZTab(IlejestRybR[j]);
						IlejestRybD[i].ZerujCzasOdOstatniegoJedzenia();
						Ryba_drapiezna drapiezna(0, 0);
						DodajRybeDDoTab(drapiezna, aktualnaLiczbaRybD);
						mapa.DodajRybeD(IlejestRybD[aktualnaLiczbaRybD]);
						mapa.AktualizujRybyDlaPola(razemX, razemY, 0, 1);
						aktualnaLiczbaRybD++;
					}
				}
			}
		}
	}
	for (int i = 0; i < aktualnaLiczbaRybR; i++)
	{
		int nowyX = (rand() % 3) - 1;
		int nowyY = (rand() % 3) - 1;
		int staryX = IlejestRybR[i].ZwrocPozycjeX();
		int staryY = IlejestRybR[i].ZwrocPozycjeY();
		int razemX = nowyX + staryX;
		int razemY = nowyY + staryY;
		Pole nowePole = mapa.PobierzPozycjePola(razemX, razemY);
		if (nowePole.CzyJestWoda && razemX < 10 && razemY < 10 && razemX >= 0 && razemY >= 0 && !nowePole.CzyJestRybaR)
		{
			IlejestRybR[i].ZapiszX(razemX);
			IlejestRybR[i].ZapiszY(razemY);
			mapa.AktualizujRybyDlaPola(staryX, staryY, 0, 0);
			mapa.AktualizujRybyDlaPola(razemX, razemY, 1, 0);
			if (nowePole.CzyJestHaczyk == 1)
			{
				for (int j = 0; j < aktualnaLiczbaHaczykow; j++)
				{
					if (IlejestHaczykow[j].ZwrocX() == razemX && IlejestHaczykow[j].ZwrocY() == razemY)
					{
						IlejestHaczykow[j].ZahaczRybe(IlejestRybR[i]);
						UsunHaczykZTab(IlejestHaczykow[j]);
						UsunRybeZTab(IlejestRybR[i]);
						ZarzucWedke();
					}
				}

				mapa.AktualizujHaczykDlaPola(razemX, razemY, 0);
				mapa.AktualizujRybyDlaPola(razemX, razemY, 0, 0);
				cout << "Trafilo na haczyk " << razemX << ", " << razemY << endl;
				ileSieZahaczylo++;
			}
			else if (nowePole.CzyJestRoslina == 1)
			{
				for (int j = 0; j < aktualnaLiczbaRoslin; j++)
				{
					if (IlejestRoslin[j].ZwrocX() == razemX && IlejestRoslin[j].ZwrocY() == razemY)
					{
						UsunRoslineZTab(IlejestRoslin[j]);
						IlejestRybR[i].ZerujCzasOdOstatniegoJedzenia();
						Ryba_roslinozerna roslinozerna(0, 0);
						DodajRybeRDoTab(roslinozerna, aktualnaLiczbaRybR);
						mapa.DodajRybeR(IlejestRybR[aktualnaLiczbaRybR]);
						mapa.AktualizujRoslineDlaPola(razemX, razemY, 0);
						aktualnaLiczbaRybR++;
						Roslina roslina(0, 0);
						aktualnaLiczbaRoslin++;
						DodajRoslineDoTab(roslina, aktualnaLiczbaRoslin);
						mapa.DodajRosline(IlejestRoslin[aktualnaLiczbaRoslin]);
					}
				}
			}
		}
	}
}

void Symulacja::ZaktualizujMape()
{
	mapa.OdswiezMape();
	WyswietlMape();
}

void Symulacja::OdliczajCzas()
{
	if (GetTickCount64() >= czasTrwania + czasRozpoczecia)
	{
		symulacjaTrwa = false;
		std::cout << "KONIEC SYMULACJI" << endl;
		std::cout << "Zahaczylo sie: " << ileSieZahaczylo << endl;
		ZapiszWynikiSymulacji(aktualnaLiczbaHaczykow, aktualnaLiczbaRybR, aktualnaLiczbaRybD, aktualnaLiczbaRoslin, czasTrwania, poczatkowaIloscRybR, poczatkowaIloscRybD);
	}
}

void Symulacja::ZapiszWynikiSymulacji(int liczbaHaczykow, int liczbaRybR, int liczbaRybD, int liczbaRoslin, int czasTrwania,
	int poczatkowaLiczbaRybR, int poczatkowaLiczbaRybD)
{
	fstream plik("wynik.txt");
	int seed = (rand() % 200000);
	plik << "Symulacja nr: " << seed << endl;
	plik << "Liczba haczyków: " << liczbaHaczykow << endl;
	plik << "Liczba zahaczonych ryb: " << ileSieZahaczylo << endl;
	plik << "liczba ryb roslino¿ernych: " << aktualnaLiczbaRybR << endl;
	plik << "Liczba ryb drapie¿nych: " << aktualnaLiczbaRybD << endl;
	plik << "Liczba roœlin: " << aktualnaLiczbaRoslin << endl;
	plik << "Czas trwania: " << czasTrwania << " milisekund" << endl;
	plik << "Poczatkowa liczba ryb roœlino¿ernych: " << poczatkowaIloscRybR << endl;
	plik << "Poczatkowa liczba ryb drapie¿nych: " << poczatkowaIloscRybD << endl;
	plik << endl;
	plik.close();
}

bool Symulacja::ZwrocStanSymulacji()
{
	return symulacjaTrwa;
}

void Symulacja::ZarzucWszystkieWedki()
{
	for (int i = 0; i < 5; i++)
	{
		ZarzucWedke();
	}
}

void Symulacja::ZarzucWedke()
{		
		Haczyk haczyk;
		IlejestHaczykow[aktualnaLiczbaHaczykow] = haczyk;

		mapa.DodajHaczykNaMape(IlejestHaczykow[aktualnaLiczbaHaczykow]);

		aktualnaLiczbaHaczykow++;
}


void Symulacja::UsunHaczykZTab(Haczyk haczyk)
{
	int pozycjaHaczykaWTab = 1000;
	for (int i = 0; i < aktualnaLiczbaHaczykow; i++)
	{
		if (IlejestHaczykow[i].ZwrocX() == haczyk.ZwrocX() && IlejestHaczykow[i].ZwrocY() == haczyk.ZwrocY())
		{
			pozycjaHaczykaWTab = i;
		}
		else if (i > pozycjaHaczykaWTab)
		{
			IlejestHaczykow[i - 1] = IlejestHaczykow[i];
		}
	}
	aktualnaLiczbaHaczykow--;
	mapa.AktualizujIloscHaczykow(aktualnaLiczbaHaczykow);
}

void Symulacja::ZapelnijTabliceRoslin()
{
	for (int i = 0; i < 10 ; i++)
	{
		Roslina roslina(0,0);
		IlejestRoslin[i] = roslina;
		aktualnaLiczbaRoslin++;
	}
}

void Symulacja::UsunRoslineZTab(Roslina roslina)
{
	int pozycjaRoslinyWTab = 1000;
	for (int i = 0; i < aktualnaLiczbaRoslin; i++)
	{
		if (IlejestRoslin[i].ZwrocX() == roslina.ZwrocX() && IlejestRoslin[i].ZwrocY() == roslina.ZwrocY())
		{
			pozycjaRoslinyWTab = i;
		}
		else if (i > pozycjaRoslinyWTab)
		{
			IlejestRoslin[i - 1] = IlejestRoslin[i];
		}
	}
	aktualnaLiczbaRoslin--;
	mapa.UsunRosline(roslina.ZwrocX(), roslina.ZwrocY());
	mapa.AktualizujIloscRoslin(aktualnaLiczbaRoslin);
}

void Symulacja::UsunRybeZTab(Ryba ryba)
{
	int pozycjaRybyWTab = 1000;
	if (ryba.CzyJestDrapiezna() == 1)
	{
		for (int i = 0; i < aktualnaLiczbaRybD; i++)
		{
			if (IlejestRybD[i].ZwrocPozycjeX() == ryba.ZwrocPozycjeX() && IlejestRybD[i].ZwrocPozycjeY() == ryba.ZwrocPozycjeY())
			{
				pozycjaRybyWTab = i;
			}
			else if (i > pozycjaRybyWTab)
			{
				IlejestRybD[i - 1] = IlejestRybD[i];
			}
		}
		aktualnaLiczbaRybD--;
		mapa.UsunRybeD(ryba.ZwrocPozycjeX(), ryba.ZwrocPozycjeY());
		mapa.AktualizujIloscRybD(aktualnaLiczbaRybD);
	}
	else
	{
		for (int i = 0; i < aktualnaLiczbaRybR; i++)
		{
			if (IlejestRybR[i].ZwrocPozycjeX() == ryba.ZwrocPozycjeX() && IlejestRybR[i].ZwrocPozycjeY() == ryba.ZwrocPozycjeY())
			{
				pozycjaRybyWTab = i;
			}
			else if (i > pozycjaRybyWTab)
			{
				IlejestRybR[i - 1] = IlejestRybR[i];
			}
		}
		aktualnaLiczbaRybR--;
		mapa.UsunRybeR(ryba.ZwrocPozycjeX(), ryba.ZwrocPozycjeY());
		mapa.AktualizujIloscRybR(aktualnaLiczbaRybR);
	}
}
void Symulacja::TworzMape()
{
	ZapelnijTabliceRyb();
	ZapelnijTabliceRoslin();
	mapa.PrzypiszTabliceRybR(IlejestRybR, aktualnaLiczbaRybR);
	mapa.PrzypiszTabliceRybD(IlejestRybD, aktualnaLiczbaRybD);
	mapa.PrzypiszTabliceRoslin(IlejestRoslin, aktualnaLiczbaRoslin);
	ZarzucWszystkieWedki();
	mapa.DodajRoslinyNaMape();
	mapa.DodajRybyNaMape();
}

void Symulacja::WyswietlMape()
{
	std::cout << "[x][0][1][2][3][4][5][6][7][8][9]" << endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout <<"["<< i<<"]";
		for (int j = 0; j < 10; j++)
		{
			Pole pole = mapa.PobierzPozycjePola(i, j);
			char symbol = ZwrocSymbolPola(pole);
			std:; cout << "[" << symbol << "]";
		}
	std::cout << endl;
	}
}

char Symulacja::ZwrocSymbolPola(Pole pole)
{
	if (pole.CzyJestRybaD) return 'D';
	else if (pole.CzyJestRybaR) return 'R';
	else if (pole.CzyJestHaczyk) return 'J';
	else if (pole.CzyJestRoslina) return '$';
	else if (pole.CzyJestWoda) return '_';
	else return ' ';
}

Symulacja::~Symulacja()
{

}