#include <iostream>
#include "Symulacja.h"

using namespace std;

int main()
{
    int roslinozerne, drapiezne, czasTrwania;
    cout << "Podaj ilosc ryb roslinozernych: \n";
    cin >> roslinozerne; 
    cout << "Podaj ilosc ryb drapieznych: \n";
    cin >> drapiezne;
    cout << "Podaj czas trwania symulacji w sekundach \n";
    cin >> czasTrwania;

    Symulacja symulacja(drapiezne, roslinozerne,czasTrwania);

    symulacja.TworzMape();

    do
    {
        symulacja.Odswiez();
    } while (symulacja.ZwrocStanSymulacji() == true);

    return 0;
}

