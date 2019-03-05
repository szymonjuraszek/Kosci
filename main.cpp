#include <iostream>
#include <string>
#include <ctime>

#include "Error.h"
#include "Gra.h"
#include "Gracz.h"
#include "KartaWyniki.h"
#include "Kostka.h"

using namespace std;

void kto_wygral(Gracz tab_graczy[],Gra rozgrywka);

int main()
{
	srand(time(NULL));
	cout << "--------------------------------Witam w grze KOSCI--------------------------------" << endl;
	cout << "Podaj ilosc graczy[od 2 do 10]" << endl;
	int ilosc_graczy;
	ilosc_graczy = Error::ryzykowna(2,10);
	
	Gra rozgrywka(ilosc_graczy);
    Kostka tab_kostek[5];
	Gracz *tab_graczy = new Gracz[ilosc_graczy];
	system("cls");
	const int ilosc_tur = 13;

	for (int i = 0; i < ilosc_tur; i++)
	{
		for (int j = 0; j < ilosc_graczy; j++)
		{
			int wybor;
			tab_graczy[j].SetCzyZapisano();
			tab_graczy[j].SetIloscRzutow();
			bool czy_zakonczyc_ture = false;
			

			do
			{
				
				cout << "Co chcesz zrobic " << tab_graczy[j].GetNick() << endl;
				cout << "Rzuc kostkami[1]" << endl;
				cout << "Popatrz na swoja karte z wynikami[2]" << endl;
				cout << "Zapisz wynik[3]" << endl;
				cout << "Zakoncz ture[4]" << endl;
				wybor = Error::ryzykowna_ogolna();
				system("cls");

				switch (wybor)
				{
				case 1:
				{
					if (!tab_graczy[j].GetCzyZapisano())
					{
						if (tab_graczy[j].GetIloscRzutow() < tab_graczy[j].GetMaxRzutow())
						{
							tab_graczy[j].inkrementuj_ilosc_rzutow();
							int ilosc = 5;
							if (tab_graczy[j].GetIloscRzutow() >= 2)
							{
								cout << "Iloma kostkami chcesz rzucic?" << endl;
								ilosc= Error::ryzykowna(1,5);
							}

							tab_graczy[j].rzuc_kostkami(ilosc, tab_kostek);
							
						}
						else
						{
							cout << "Mozna rzucac max 3 razy" << endl;
						}
					}
					else
					{
						cout << "Nie mozna rzucac kostkami bo zapisano juz wynik" << endl;
					}
				
					break;
				}
				case 2:
				{
					tab_graczy[j].wsk->wyswietl();
					break;
				}
				case 3:
				{
					if (!tab_graczy[j].GetCzyZapisano()&& (tab_graczy[j].GetIloscRzutow()>0))
					{
						tab_graczy[j].zapisz_wynik(tab_kostek);
						czy_zakonczyc_ture = true;
					}
					else
					{
						cout << "Juz zapisales wynik albo nie rzuciles jeszcze kostkami" << endl;
					}
					break;
				}
				case 4:
				{
					if (!czy_zakonczyc_ture)
					{
						cout << "Nie rzuciles jeszcze kostkami lub nie zapisales wyniku" << endl;
						wybor = 5;
					}
					else
					{
						cout << "Skonczyles kolejke" << endl;
					}
					break;
				}default:
				{
					cout << "Podales zla liczbe,sproboj jeszcze raz" << endl;
					break;
				}
				}

			} while (wybor !=4 );
		}
		cout << "Minela " << i+1 << " tura" << endl;
		
	}

	kto_wygral(tab_graczy,rozgrywka);
	rozgrywka.wyswietl(tab_graczy);


	delete[]tab_graczy;

	system("pause");
	return 0;
}

void kto_wygral(Gracz tab_graczy[], Gra rozgrywka)
{
	int najlepszy_wynik = 0;
	for (int i = 0; i < rozgrywka.ilosc_graczy; i++)
	{
		if (tab_graczy[i].wsk->GetKoncowyWynik() > najlepszy_wynik)
		{
			najlepszy_wynik = tab_graczy[i].wsk->GetKoncowyWynik();
			rozgrywka.zwyciezca = tab_graczy[i].GetNick();
		}
	}

	
}
