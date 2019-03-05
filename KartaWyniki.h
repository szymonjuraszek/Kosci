#ifndef KARTA_WYNIKI_H
#define KARTA_WYNIKI_H



class KartaWyniki
{
	friend class Gracz;
	int czesc_bonusowa[6] = { 0,0,0,0,0,0 };
	int jednakowe3=0;
	int jednakowe4=0;
	int full=0;
	int maly_strit=0;
	int duzy_strit=0;
	int general=0;
	int szansa=0;
	bool tab_flag[14];
	int koncowy_wynik;
public:
	void wyswietl();
	void spis_wyrazow_pasujacych();
	KartaWyniki();
	~KartaWyniki();
	int GetKoncowyWynik()
	{
		return koncowy_wynik;
	}
};

#endif KARTA_WYNIKI_H