//plik samochod_skrzynia_biegow.h
#pragma once
#include <iostream>

using namespace std;

class samochod_skrzynia_biegow
{
private:

	bool stanSilnika;
	unsigned int aktulanyBieg;
	unsigned int aktualnaPredkosc;

	void nastBieg();
	void poprzBieg();

public:
	samochod_skrzynia_biegow() : stanSilnika(0), aktulanyBieg(0), aktualnaPredkosc(0) {};

	void uruchom();
	void wylacz();
	void przyspiesz();
	void hamuj();
	void wyswietl();


	friend ostream& operator<<(ostream& strm, const samochod_skrzynia_biegow& samochod);

};