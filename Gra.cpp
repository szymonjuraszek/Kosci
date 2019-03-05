#include "Gra.h"

#include <iostream>
#include <string>

using namespace std;



Gra::Gra(int ilosc_graczy)
{
	this->ilosc_graczy = ilosc_graczy;
	
}

void Gra::wyswietl(Gracz tab_graczy[])
{
	system("cls");
	
	cout << "Karty wynikow graczy po calej rozgrywce" << endl;

	for (int i = 0; i < ilosc_graczy; i++)
	{
		cout <<"Gracz "<< tab_graczy[i].GetNick() << endl;
		cout << "Uzyskuje: " << tab_graczy[i].wsk->GetKoncowyWynik() << endl << endl;

	}
	
	cout << "Zwyciezca zostal gracz o nicku:" << zwyciezca <<" Gratulacje!!"<< endl;

}



Gra::~Gra()
{
}
