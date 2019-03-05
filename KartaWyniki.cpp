#include "KartaWyniki.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void KartaWyniki::wyswietl()
{

	cout << "|----------------------Karta wynikow gracza ---------------------------" << endl;
	cout << "|Czesc 1:" << endl;
	int suma_pierwsza_czesc=0;
	for (int i = 0; i < 6; i++)
	{
		cout <<"| "<<left<<"Same"<< setw(20) << left << i+1<<"  "<< czesc_bonusowa[i] << endl;
		suma_pierwsza_czesc = suma_pierwsza_czesc + czesc_bonusowa[i];
	}
	cout << "|----------------------------------------------------------------------" << endl;
	cout << setw(28) <<left<< "| Razem(bez bonusu): "<< suma_pierwsza_czesc<< endl;
	cout << setw(28) << left << "| Bonus 35(powyzej 63pkt): ";
	bool czy_bonus = false;
	if (suma_pierwsza_czesc >= 63)
	{
		cout << 35 << endl;
		czy_bonus = true;
	}
	else
	{
		cout <<  "-" << endl;
	}
	cout << setw(28) << left << "| Razem z bonusem: ";
	if (czy_bonus)
	{
		cout <<  suma_pierwsza_czesc + 35 << endl;
		suma_pierwsza_czesc = suma_pierwsza_czesc + 35;
	}
	else
	{
		cout <<  "-" << endl;
	}
	cout << "|----------------------------------------------------------------------" << endl;
	cout << "|Czesc 2:" << endl;
	cout<<setw(28)<< left << "| jednakowe3"<<  jednakowe3<<endl;
	cout << setw(28) << left << "| jednakowe4" <<  jednakowe4 << endl;
	cout << setw(28) << left << "| full" <<  full << endl;
	cout << setw(28) << left << "| maly strit" <<  maly_strit << endl;
	cout << setw(28) << left << "| duzy strit" <<  duzy_strit << endl;
	cout << setw(28) << left << "| general" <<  general << endl;
	cout << setw(28) << left << "| szansa" <<  szansa << endl;
	cout << "|----------------------------------------------------------------------" << endl;
	int suma_czesc_druga = jednakowe3 + jednakowe4 + full + maly_strit + duzy_strit + general + szansa;
	cout << setw(28) << left << "| Razem(czesc 2)" <<  suma_czesc_druga<< endl;
	cout << setw(28) << left << "| Razem(czesc 1)" <<  suma_pierwsza_czesc<< endl;
	cout << setw(28) << left << "| Razem(czesc 1+2)" <<  suma_pierwsza_czesc+suma_czesc_druga<< endl;
    cout << "|----------------------------------------------------------------------" << endl;
	koncowy_wynik = suma_pierwsza_czesc + suma_czesc_druga;

}

void KartaWyniki::spis_wyrazow_pasujacych()
{
	cout << "Jesli chcesz:" << endl << endl;
	cout << "1 to napisz               same1" << endl;
	cout << "2 to napisz               same2" << endl;
	cout << "3 to napisz               same3" << endl;
	cout << "4 to napisz               same4" << endl;
	cout << "5 to napisz               same5" << endl;
	cout << "6 to napisz               same6" << endl;
	cout << "3 te same liczby          jednakowe3" << endl;
	cout << "4 te same liczby          jednakowe4" << endl;
	cout << "full                      full" << endl;
	cout << "general                   general  " << endl;
	cout << "maly strit                malystrit" << endl;
	cout << "duzy strit                duzytrit" << endl;
	cout << "szansa                    szansa" << endl;

}

KartaWyniki::KartaWyniki()
{
	
	for (int i = 0; i < 14; i++)
	{
		tab_flag[i] = false;
	}
}


KartaWyniki::~KartaWyniki()
{
}
