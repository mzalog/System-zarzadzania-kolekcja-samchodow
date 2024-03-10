#include "skrzynia_biegow.h"
#include "Samochod.h"
#include <iostream>
using namespace std;

void car::uruchom() {
	stanSilnika = true;
}
void car::wylacz() {
	stanSilnika = false;
}

void car::nastBieg() {
	aktulanyBieg++;

}

void car::poprzBieg() {
	if (aktulanyBieg > 0) {
		aktulanyBieg--;
	}
	else
		cout << "masz za maly bieg, aby zwiekszyc";

}
void car::przyspiesz() {
	if (stanSilnika == true && aktualnaPredkosc <= 100) {
		aktualnaPredkosc += 10;
		if (aktulanyBieg != (aktualnaPredkosc / 20) + 1) {
			nastBieg(); //dziala tylko dla tych konkretnych predkosci
		}
	}
}


void car::hamuj() {
	if (aktualnaPredkosc >= 0)
		aktualnaPredkosc -= 10;
	if (aktulanyBieg != (aktualnaPredkosc / 20))
		poprzBieg(); //dziala tylko dla tych konkretnych predkosci
}

void car::wyswietl() {
	cout << "aktualna predkosc wynosi: " << aktualnaPredkosc << endl;
	cout << "aktualny bieg wynosi: " << aktulanyBieg;

}

ostream& operator<<(ostream& strm, const car& tesla)
{
	strm << tesla.aktualnaPredkosc << "<-Predkosc" << endl;
	strm << tesla.aktulanyBieg << "<-Bieg" << endl;

	return strm;
}