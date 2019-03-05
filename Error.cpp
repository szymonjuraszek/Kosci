#include "Error.h"

#include <iostream>
#include <string>

using namespace std;

int Error::ryzykowna_ogolna()
{
	int wartosc;
	do
	{
		cin >> wartosc;
		if (cin.fail())
		{
			cout << "Blad,sprobuj jeszcze raz" << endl;
			cin.clear(cin.rdstate()&~ios::failbit);
			string slowo;
			cin >> slowo;

		}
		else
		{

				return wartosc;
			
		}
	} while (cin.good());
}

int Error::ryzykowna(int przedzial_od, int przedzial_do)
{
	int wartosc;
	do
	{
		cin >> wartosc;
		if (cin.fail())
		{
			cout << "Blad,sprobuj jeszcze raz" << endl;
			cin.clear(cin.rdstate()&~ios::failbit);
			string slowo;
			cin >> slowo;

		}
		else
		{
			if ((wartosc < przedzial_od || wartosc>przedzial_do))
			{
				cout << "Blad,sprobuj jeszcze raz" << endl;
			}
			else
			{
				return wartosc;
			}
		}
	} while (cin.good());
}


int Error::ryzykowna_kostki(Kostka tab_kostek[])
{
	int wartosc;
	do
	{
		cin >> wartosc;
		if (cin.fail())
		{
			cout << "Blad,sprobuj jeszcze raz" << endl;
			cin.clear(cin.rdstate()&~ios::failbit);
			string slowo;
			cin >> slowo;

		}
		else
		{
			if ((wartosc < 1 || wartosc>5))
			{
				cout << "Blad,sprobuj jeszcze raz" << endl;
			}
			else
			{
				if (!tab_kostek[wartosc - 1].czy_rzucona)
				{
					return wartosc;
				}
				else
				{
					cout << "Juz wybrales te kostke do rzutu" << endl;
				}
			}
		}
	} while (cin.good());
}


Error::~Error()
{
}
