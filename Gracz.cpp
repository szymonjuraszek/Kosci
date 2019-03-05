#include "Gracz.h"
#include "Error.h"




bool Gracz::sprawdz(int takie_same_liczby, Kostka tab_kostek[])
{
	if (!wsk->tab_flag[takie_same_liczby])
	{
		for (int i = 0; i < 5; i++)
		{
			if (tab_kostek[i].wynik == takie_same_liczby)
			{
				wynik_po_rzutach = wynik_po_rzutach + tab_kostek[i].wynik;
			}
		}
		cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
		cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
		string wybor;
		cin >> wybor;
		if ((wybor == "TAK") || (wybor == "tak"))
		{
			wsk->czesc_bonusowa[takie_same_liczby - 1] = wynik_po_rzutach;
			wsk->tab_flag[takie_same_liczby] = true;
			return false;
		}
		else if ((wybor == "NIE") || (wybor == "nie"))
		{
			wynik_po_rzutach = 0;
			return true;
		}
	}
	else
	{
		cout << "Juz jest wpisana wartosc" << endl;
	}
	wynik_po_rzutach = 0;
	return true;
}

int *Gracz::sprawdzanie_liczb(Kostka tab_kostek[],int licznik[])
{
	
	for (int i = 0; i < 6; i++)
	{
		licznik[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		if (tab_kostek[i].wynik == 1)
		{
			licznik[0]++;
		}
		else if (tab_kostek[i].wynik == 2)
		{
			licznik[1]++;
		}
		else if (tab_kostek[i].wynik == 3)
		{
			licznik[2]++;
		}
		else if (tab_kostek[i].wynik == 4)
		{
			licznik[3]++;
		}
		else if (tab_kostek[i].wynik == 5)
		{
			licznik[4]++;
		}
		else
		{
			licznik[5]++;
		}
	}

	int *wsk = NULL;
	wsk = licznik;
	
	return  wsk;
}

void Gracz::rzuc_kostkami(int ile_kostek,Kostka tab_kostek[])
{
	
	if (ile_kostek == 5)
	{
		cout << "rzucam kostkami" << endl;
		for (int i = 0; i < 5; i++)
		{
			tab_kostek[i].wynik = rand() % 6 + 1;
			
		}
		cout << "Wyrzuciles:" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "kostka numer " << j + 1 << " ma ";
			cout << tab_kostek[j].wynik << endl;

		}
		
	}
	else
	{
		cout << "W poprzednim rzucie wyrzuciles:" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "kostka numer " << j + 1<<" ma ";
			cout << tab_kostek[j].wynik << endl;

		}
		int numer;
		
		cout << "Ktorymi dokladnie kostkami chcesz rzucic teraz (podaj numery po kolej)" << endl;
		for (int i = 0; i < ile_kostek; i++)
		{

			numer = Error::ryzykowna_kostki(tab_kostek);
			tab_kostek[numer-1].wynik= rand() % 6 + 1;
			tab_kostek[numer - 1].czy_rzucona = true;
		}
		cout << "Wyrzuciles:" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "kostka numer " << j + 1<<" ma ";
			cout << tab_kostek[j].wynik << endl;
			tab_kostek[j].czy_rzucona = false;

		}

	}

}

void Gracz::zapisz_wynik(Kostka tab_kostek[])
{
	system("cls");
	
	cout << "W poprzednim rzucie wyrzuciles:" << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << "kostka numer " << j + 1 << " ma ";
		cout << tab_kostek[j].wynik << endl;

	}
	wsk->wyswietl();
	bool zakonczenie_petli;
	
	do
	{
		wynik_po_rzutach = 0;
		zakonczenie_petli = false;
		int takie_same_liczby;
		cout << "Gdzie chcesz zapisac swoj wynik?(podaj dokladna nazwe z tabeli)" << endl;
		string nazwa;
		cin >> nazwa;
		if (nazwa == "same1")
		{
			takie_same_liczby = 1;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
			
		}
		else if (nazwa == "same2")
		{
			takie_same_liczby = 2;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
		}
		else if (nazwa == "same3")
		{
			takie_same_liczby = 3;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
		}
		else if (nazwa == "same4")
		{
			takie_same_liczby = 4;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
		}
		else if (nazwa == "same5")
		{
			takie_same_liczby = 5;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
		}
		else if (nazwa == "same6")
		{
			takie_same_liczby = 6;
			zakonczenie_petli=sprawdz(takie_same_liczby, tab_kostek);
		}
		else if (nazwa == "malystrit")
		{
			if (!wsk->tab_flag[10])
			{
				int licznik[6];
				int *wsk_licznikow=sprawdzanie_liczb(tab_kostek,licznik);
				
				int czy_4_wyrazy_po_kolej=0;
				for (int i = 0; i < 6; i++)
				{
					if (wsk_licznikow[i] >= 1)
					{
						czy_4_wyrazy_po_kolej++;
						cout << endl << endl << endl;
						cout << czy_4_wyrazy_po_kolej << endl << endl;
						if (czy_4_wyrazy_po_kolej == 4)
						{
							cout << "Zdobyles malego strita" << endl;
							wynik_po_rzutach = 30;
						}
					}
					else
					{
						czy_4_wyrazy_po_kolej = 0;
					}
				}
				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->maly_strit = wynik_po_rzutach;
					wsk->tab_flag[10] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "duzystrit")
		{
			if (!wsk->tab_flag[11])
			{
				int licznik[6];
				int *wsk_licznikow = sprawdzanie_liczb(tab_kostek,licznik);
				
				int czy_5_wyrazy_po_kolej = 0;
				for (int i = 0; i < 6; i++)
				{
					if (wsk_licznikow[i] == 1)
					{
						czy_5_wyrazy_po_kolej++;
						if (czy_5_wyrazy_po_kolej == 5)
						{
							cout << "Zdobyles malego strita" << endl;
							wynik_po_rzutach = 40;
						}
					}
					else
					{
						czy_5_wyrazy_po_kolej = 0;
					}
				}
				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->duzy_strit = wynik_po_rzutach;
					wsk->tab_flag[11] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "jednakowe3")
		{
			if (!wsk->tab_flag[7])
			{
				int licznik[6];
				int *wsk_licznikow = sprawdzanie_liczb(tab_kostek,licznik);
				
				
				bool sprawdz = false;
				for (int i = 0; i < 6; i++)
				{
					
					if (wsk_licznikow[i] >=3)
					{
						cout << "Zdobyles 3 te same liczby" << endl;
						sprawdz = true;
					}
					
				}
				if (sprawdz)
				{
					for (int i = 0; i < 5; i++)
					{
						wynik_po_rzutach = wynik_po_rzutach + tab_kostek[i].wynik;
					}
				}
				
				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->jednakowe3 = wynik_po_rzutach;
					wsk->tab_flag[7] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "jednakowe4")
		{
			if (!wsk->tab_flag[8])
			{
				int licznik[6];
				int *wsk_licznikow = sprawdzanie_liczb(tab_kostek,licznik);
				
			
				bool sprawdz = false;
				for (int i = 0; i < 6; i++)
				{
					
					if (wsk_licznikow[i] >= 4)
					{
						cout << "Zdobyles 4 te same liczby" << endl;
						sprawdz = true;
					}
					
				}
				if (sprawdz)
				{
					for (int i = 0; i < 5; i++)
					{
						wynik_po_rzutach = wynik_po_rzutach + tab_kostek[i].wynik;
					}
				}

				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->jednakowe4 = wynik_po_rzutach;
					wsk->tab_flag[8] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "general")
		{
			if (!wsk->tab_flag[12])
			{

				int licznik[6];
				int *wsk_licznikow = sprawdzanie_liczb(tab_kostek,licznik);
				
				
				for (int i = 0; i < 6; i++)
				{

					if (wsk_licznikow[i] == 5)
					{
						cout << "Zdobyles Generala" << endl;
						wynik_po_rzutach = 50;
					}
					
				}
				
				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->general = wynik_po_rzutach;
					wsk->tab_flag[12] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "szansa")
		{
			if (!wsk->tab_flag[13])
			{
				for (int i = 0; i < 5; i++)
				{
					wynik_po_rzutach= wynik_po_rzutach+tab_kostek[i].wynik;
				}

				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->szansa = wynik_po_rzutach;
					wsk->tab_flag[13] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else if (nazwa == "full")
		{
			if (!wsk->tab_flag[9])
			{
				int licznik[6];
				int *wsk_licznikow = sprawdzanie_liczb(tab_kostek,licznik);
				

				
				for (int i = 0; i < 6; i++)
				{
					
					if (wsk_licznikow[i] == 3)
					{
						for (int j = 0; j < 6; j++)
						{
							if (wsk_licznikow[j] == 2)
							{
								cout << "Zdobyles Fulla" << endl;
								wynik_po_rzutach = 25;
							}
						}
						
					}

				}

				cout << "Mozesz uzyskac max " << wynik_po_rzutach << " pkt" << endl;
				cout << "czy jestes pewien swojego wyboru?(TAK lub NIE)" << endl;
				string wybor;
				cin >> wybor;
				if ((wybor == "TAK") || (wybor == "tak"))
				{
					wsk->full = wynik_po_rzutach;
					wsk->tab_flag[9] = true;
					zakonczenie_petli = false;
				}
				else if ((wybor == "NIE") || (wybor == "nie"))
				{
					wynik_po_rzutach = 0;
					zakonczenie_petli = true;
				}
			}
			else
			{
				cout << "Juz jest wpisana wartosc" << endl;
				zakonczenie_petli = true;
			}
			
		}
		else
		{
			cout << "------------------------------------------------------------------------------------------ "<< endl;
			cout << "Zaden z podanych wyrazow nie pasuje" << endl;
			cout << "Czy chcesz abym wyswietlil spis wyrazow?[wpisz TAK]" << endl;
			string odp;
			cin >> odp;
			if ((odp == "TAK") || (odp == "tak"))
			{
				wsk->spis_wyrazow_pasujacych();
				system("pause");
				
			}
			zakonczenie_petli = true;
        }

	} while (zakonczenie_petli);
	czy_zapisano_wynik = true;

	
}

Gracz::Gracz()
{
	cout << "Podaj nick:" << endl;
	cin >> nick;
	ilosc_rzutow = 0;
	wsk = new KartaWyniki;
	
}


Gracz::~Gracz()
{
}
