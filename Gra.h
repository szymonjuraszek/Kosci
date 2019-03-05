#ifndef GRA_H
#define GRA_H

#include "Gracz.h"

class Gra
{
	int ilosc_graczy;
	string zwyciezca;
	
public:
	friend void kto_wygral(Gracz tab_graczy[], Gra rozgrywka);
	Gra(int ilosc_graczy=2);
	void wyswietl(Gracz tab_graczy[]);

	~Gra();
};

#endif GRA_H