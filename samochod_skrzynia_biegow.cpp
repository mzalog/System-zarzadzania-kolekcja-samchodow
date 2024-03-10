#include "samochod_skrzynia_biegow.h"
#include "Samochod.h"
#include <iostream>
using namespace std;


void samochod_skrzynia_biegow::nastBieg() {
    aktulanyBieg++;
}

void samochod_skrzynia_biegow::poprzBieg() {
    if (aktulanyBieg > 0) {
        aktulanyBieg--;
    }
    else {
        std::cout << "masz za maly bieg, aby zwiekszyc";
    }
}

void samochod_skrzynia_biegow::uruchom() {
    stanSilnika = true;
}

void samochod_skrzynia_biegow::wylacz() {
    stanSilnika = false;
}

void samochod_skrzynia_biegow::przyspiesz() {
    if (stanSilnika == true && aktualnaPredkosc <= 100) {
        aktualnaPredkosc += 10;
        if (aktulanyBieg != (aktualnaPredkosc / 20) + 1) {
            nastBieg(); //dziala tylko dla tych konkretnych predkosci
        }
    }
}

void samochod_skrzynia_biegow::hamuj() {
    if (aktualnaPredkosc >= 0) {
        aktualnaPredkosc -= 10;
    }
    if (aktulanyBieg != (aktualnaPredkosc / 20)) {
        poprzBieg(); //dziala tylko dla tych konkretnych predkosci
    }
   
}

void samochod_skrzynia_biegow::wyswietl() {
    std::cout << "aktualna predkosc wynosi: " << aktualnaPredkosc << std::endl;
    std::cout << "aktualny bieg wynosi: " << aktulanyBieg;
}

std::ostream& operator<<(std::ostream& strm, const samochod_skrzynia_biegow& samochod) {
    strm << "stanSilnika: " << samochod.stanSilnika << ", aktulanyBieg: " << samochod.aktulanyBieg << ", aktualnaPredkosc: " << samochod.aktualnaPredkosc;
    return strm;
}
