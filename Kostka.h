#ifndef KOSTKA_H
#define KOSTKA_H



class Kostka
{
	friend class Gracz;
	friend class Error;
	int wynik;
	bool czy_rzucona = false;

public:
	
	Kostka();
	~Kostka();
};

#endif KOSTKA_H