#pragma once
#include <iostream>
#include <string>
#include "samochod_skrzynia_biegow.h"



class Samochod : public virtual samochod_skrzynia_biegow {
public:
    static unsigned int ilosc_aut;

    std::string rodzaj;
    std::string marka;
    std::string model;
    int rocznik;
    int moc;
    double przyspieszenie;
    int zasieg;

    Samochod(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas);
    ~Samochod();

    void pokaz();
    void wyswietldodane();
    void pokazMarkiModelRocznik();
    void modyfikuj();

    static void dodajauto();
};

class Spalinowy : public virtual Samochod {
public:
    std::string typ_paliwa;

    Spalinowy(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string pal);
};

class Elektryczny : public virtual Samochod {
public:
    std::string poziom_baterii;


    Elektryczny(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string bat);
};

class Hybrydowy : public Spalinowy, public Elektryczny {
public:
    Hybrydowy(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string pal, std::string bat);
};
