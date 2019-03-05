#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <string>

#include "KartaWyniki.h"
#include "Kostka.h"



using namespace std;

class Gracz
{
	string nick;
	
	int ilosc_rzutow;
	int const max_rzutow = 3;
	int wynik_po_rzutach=0;
	bool czy_zapisano_wynik=false;
	

public:
	bool sprawdz(int takie_same_liczby, Kostka tab_kostek[]);
	int *sprawdzanie_liczb(Kostka tab_kostek[],  int licznik[]);
	void rzuc_kostkami(int ile_kostek , Kostka tab_kostek[]);
	void zapisz_wynik(Kostka tab_kostek[]);
	void inkrementuj_ilosc_rzutow()
	{
		ilosc_rzutow++;
	}
	KartaWyniki *wsk;

	string GetNick()
	{
		return nick;
	}
	int GetIloscRzutow()
	{
		return ilosc_rzutow;
	}
	int GetMaxRzutow()
	{
		return max_rzutow;
	}
	void SetIloscRzutow(int a=0)
	{
		ilosc_rzutow = a;

	}
	bool GetCzyZapisano()
	{
		return czy_zapisano_wynik;
	}
	void SetCzyZapisano()
	{
		czy_zapisano_wynik = false;
	}
	Gracz();
	~Gracz();
};

#endif GRACZ_H