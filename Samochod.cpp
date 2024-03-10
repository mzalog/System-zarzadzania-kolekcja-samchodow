#include "Samochod.h"
#include <iostream>
#include <fstream>



unsigned int Samochod::ilosc_aut = 0;

Samochod::Samochod(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas)
    : rodzaj(rodz), marka(mar), model(mod), rocznik(rocz), moc(m), przyspieszenie(przysp), zasieg(zas) {}

Samochod::~Samochod() {
    ilosc_aut--;
    std::cout << "Usuneto samochod\n";
    std::cout << "Laczna ilosc aut: " << ilosc_aut << "\n\n";
}

void Samochod::pokaz() {
    std::cout << "rodzaj: " << rodzaj << "\n";
    std::cout << "marka: " << marka << "\n";
    std::cout << "model: " << model << "\n";
    std::cout << "rocznik: " << rocznik << "\n";
    std::cout << "moc: " << moc << " KM\n";
    std::cout << "przyspieszenie: " << przyspieszenie << "s do 100km/h\n";
    std::cout << "zasieg: " << zasieg << " km\n";
    dodajauto();
}

void Samochod::pokazMarkiModelRocznik() {
    std::cout << "marka: " << marka;
    std::cout << ", model: " << model;
    std::cout << ", rocznik: " << rocznik << "\n";
}


void Samochod::wyswietldodane() {
    std::cout << "Dodano samochod\n";
    std::cout << "Laczna ilosc aut: " << ilosc_aut << "\n\n";
}

void Samochod::dodajauto() {
    ilosc_aut++;
}

void Samochod::modyfikuj() {
    cout << "Ktore pole chcesz zmienic?\n";
    cout << "1. Marka\n";
    cout << "2. Model\n";
    cout << "3. Rocznik\n";
    cout << "4. Moc\n";
    cout << "Wybierz opcje: ";

    int opcja;
    cin >> opcja;

    switch (opcja) {
    case 1:
        cout << "Podaj nowa marke: ";
        cin >> marka;
        break;
    case 2:
        cout << "Podaj nowy model: ";
        cin >> model;
        break;
    case 3:
        cout << "Podaj nowy rocznik: ";
        cin >> rocznik;
        break;
    case 4:
        cout << "Podaj nowa moc: ";
        cin >> moc;
        break;
    default:
        cout << "Niepoprawna opcja.\n";
    }
}


Spalinowy::Spalinowy(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string pal)
    : Samochod(rodz, mar, mod, rocz, m, przysp, zas), typ_paliwa(pal) {}

Elektryczny::Elektryczny(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string bat)
    : Samochod(rodz, mar, mod, rocz, m, przysp, zas), poziom_baterii(bat) {}

Hybrydowy::Hybrydowy(std::string rodz, std::string mar, std::string mod, int rocz, int m, double przysp, int zas, std::string pal, std::string bat)
    : Samochod(rodz, mar, mod, rocz, m, przysp, zas), Spalinowy(rodz, mar, mod, rocz, m, przysp, zas, pal), Elektryczny(rodz, mar, mod, rocz, m, przysp, zas, bat) {}
