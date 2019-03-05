#ifndef ERROR_H
#define ERROR_H

#include "Kostka.h"

class Error
{
	
public:
	static int ryzykowna_ogolna();
	static int ryzykowna(int przedzial_od, int przedzial_do);
	static int ryzykowna_kostki(Kostka tab_kostek[]);
	
	~Error();
};

#endif ERROR_H