#include <iostream>
#include <fstream>

#include "samochod_skrzynia_biegow.h"
#include "Samochod.h"
using namespace std;

void zapiszDoPliku(Samochod* samochody[], int liczbaSamochodow) {
    ofstream plik("samochody.txt");
    if (plik.is_open()) {
        for (int i = 0; i < liczbaSamochodow; ++i) {
            plik << samochody[i]->rodzaj << " ";
            plik << samochody[i]->marka << " ";
            plik << samochody[i]->model << " ";
            plik << samochody[i]->rocznik << " ";
            plik << samochody[i]->moc << " ";
            plik << samochody[i]->przyspieszenie << " ";
            plik << samochody[i]->zasieg << " ";
            // Dodaj zapisywanie dodatkowych pól, jeœli s¹
            plik << endl;
        }
        plik.close();
        cout << "Dane samochodow zostaly zapisane do pliku.\n";
    }
    else {
        cout << "Nie udalo sie otworzyc pliku do zapisu.\n";
    }
}

void wczytajZPliku(Samochod* samochody[], int& liczbaSamochodow) {
    ifstream plik("samochody.txt");
    if (plik.is_open()) {
        while (!plik.eof()) {
            string rodzaj, marka, model;
            int rocznik, moc, zasieg;
            double przyspieszenie;
            plik >> rodzaj >> marka >> model >> rocznik >> moc >> przyspieszenie >> zasieg;
            if (rodzaj.empty()) break; // Sprawdzenie koñca pliku
            samochody[liczbaSamochodow++] = new Samochod(rodzaj, marka, model, rocznik, moc, przyspieszenie, zasieg);
            // Dodaj wczytywanie dodatkowych pól, jeœli s¹
        }
        plik.close();
        cout << "Dane samochodow zostaly wczytane z pliku.\n";
    }
    else {
        cout << "Nie udalo sie otworzyc pliku do wczytania.\n";
    }
}


int main()
{
    Samochod* samochody[100]; // Przyk³adowa kolekcja samochodów, maksymalnie 100 samochodów
    int liczbaSamochodow = 0; // Liczba samochodów w kolekcji

    wczytajZPliku(samochody, liczbaSamochodow);


    char wybor;
    do {
        cout << "\nMENU:\n";
        cout << "1. Dodaj nowy samochod\n";
        cout << "2. Pokaz wszystkie samochody\n";
        cout << "3. Uruchom samochod\n";
        cout << "4. Przyspiesz samochod\n";
        cout << "5. Hamuj samochod\n";
        cout << "6. Wylacz samochod\n";
        cout << "7. Modyfikacja danych samochodu\n";
        cout << "8. Zapisz dane samochodow do pliku\n";
        cout << "9. Wyjdz z programu\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case '1':
            // Dodanie nowego samochodu
            if (liczbaSamochodow < 100) {
                cout << "Wybierz rodzaj samochodu:\n";
                cout << "1. Spalinowy\n";
                cout << "2. Elektryczny\n";
                cout << "3. Hybrydowy\n";
                char wyborRodzaju;
                cin >> wyborRodzaju;
                string rodzaj;
                switch (wyborRodzaju) {
                case '1':
                    rodzaj = "spalinowy";
                    break;
                case '2':
                    rodzaj = "elektryczny";
                    break;
                case '3':
                    rodzaj = "hybrydowy";
                    break;
                default:
                    cout << "Niepoprawna opcja. Samochod nie zostal dodany.\n";
                    return 1; // Zakoñcz program z kodem b³êdu
                }

                if (!rodzaj.empty()) {
                    string mar, mod;
                    int rocz, m, zas;
                    double przysp;
                    cout << "Podaj marke, model, rocznik, moc, przyspieszenie, zasieg:\n";
                    cin >> mar >> mod >> rocz >> m >> przysp >> zas;
                    cin.ignore(); // Ignoruj znak nowej linii
                    if (rodzaj == "spalinowy") {
                        string pal;
                        cout << "Podaj typ paliwa: ";
                        cin >> pal;
                        samochody[liczbaSamochodow++] = new Spalinowy(rodzaj, mar, mod, rocz, m, przysp, zas, pal);
                    }
                    else if (rodzaj == "elektryczny") {
                        string bat;
                        cout << "Podaj poziom baterii (%): ";
                        cin >> bat;
                        samochody[liczbaSamochodow++] = new Elektryczny(rodzaj, mar, mod, rocz, m, przysp, zas, bat);
                    }
                    else if (rodzaj == "hybrydowy") {
                        string pal, bat;
                        cout << "Podaj typ paliwa i poziom baterii (%): ";
                        cin >> pal >> bat;
                        samochody[liczbaSamochodow++] = new Hybrydowy(rodzaj, mar, mod, rocz, m, przysp, zas, pal, bat);
                    }
                }
            }
            else {
                cout << "Nie mozna dodac wiecej samochodow - osiagnieto maksymalna liczbe (100).\n";
            }
            break;

        case '2':
            // Pokazanie wszystkich samochodów
            for (int i = 0; i < liczbaSamochodow; ++i) {
                cout << "Samochod " << i + 1 << ":\n";
                samochody[i]->pokaz();
                cout << endl;
            }
            break;
        case '3':
            // Uruchomienie samochodu
            int nrSamochodu;
            cout << "Podaj numer samochodu do uruchomienia: ";
            cin >> nrSamochodu;
            if (nrSamochodu >= 1 && nrSamochodu <= liczbaSamochodow) {
                samochody[nrSamochodu - 1]->uruchom();
                cout << "Samochod zostal uruchomiony.\n";
                samochody[nrSamochodu - 1]->pokazMarkiModelRocznik();

            }
            else {
                cout << "Niepoprawny numer samochodu.\n";
            }
            break;
        case '4':
            // Przyspieszenie samochodu
            int nrPrzyspieszanego;
            cout << "Podaj numer samochodu do przyspieszenia: ";
            cin >> nrPrzyspieszanego;
            if (nrPrzyspieszanego >= 1 && nrPrzyspieszanego <= liczbaSamochodow) {
                samochody[nrPrzyspieszanego - 1]->przyspiesz();
                cout << "Przyspieszono samochod:\n";
                samochody[nrPrzyspieszanego - 1]->pokazMarkiModelRocznik();
                cout << "\n";
                samochody[nrPrzyspieszanego - 1]->wyswietl();
                cout << "\n";
            }
            else {
                cout << "Niepoprawny numer samochodu.\n";
            }
            break;
        case '5':
            // Hamowanie samochodu
            int nrHamowanego;
            cout << "Podaj numer samochodu do zahamowania: ";
            cin >> nrHamowanego;
            if (nrHamowanego >= 1 && nrHamowanego <= liczbaSamochodow) {
                samochody[nrHamowanego - 1]->hamuj();
                cout << "Zahamowano samochod:\n";
                samochody[nrHamowanego - 1]->pokazMarkiModelRocznik();
                samochody[nrHamowanego - 1]->wyswietl();
                cout << "\n";

            }
            else {
                cout << "Niepoprawny numer samochodu.\n";
            }
            break;
        case '6':
            // Wy³¹czenie samochodu
            int nrWylaczanego;
            cout << "Podaj numer samochodu do wylaczenia: ";
            cin >> nrWylaczanego;
            if (nrWylaczanego >= 1 && nrWylaczanego <= liczbaSamochodow) {
                samochody[nrWylaczanego - 1]->wylacz();
                cout << "Samochod zostal wylaczony.\n";
                samochody[nrWylaczanego - 1]->pokazMarkiModelRocznik();

            }
            else {
                cout << "Niepoprawny numer samochodu.\n";
            }
            break;
        case '7':
            // Modyfikacja danych samochodu
            int nrModyfikowanego;
            cout << "Podaj numer samochodu do modyfikacji: ";
            cin >> nrModyfikowanego;
            if (nrModyfikowanego >= 1 && nrModyfikowanego <= liczbaSamochodow) {
                samochody[nrModyfikowanego - 1]->modyfikuj();
                cout << "Dane samochodu zostaly zmienione.\n";
            }
            else {
                cout << "Niepoprawny numer samochodu.\n";
            }
            break;
        case '8':
            // Zapisanie danych do pliku
            zapiszDoPliku(samochody, liczbaSamochodow);
            break;
        case '9':
            cout << "Zakonczono dzialanie programu.\n";
            break;
        default:
            cout << "Niepoprawna opcja. Sprobuj ponownie.\n";
        }
    } while (wybor != '9');

    // Zwolnienie pamiêci zarezerwowanej dla obiektów samochodów
    for (int i = 0; i < liczbaSamochodow; ++i) {
        delete samochody[i];
    }

    return 0;
}



/* //main do testow

int main()
{

    Samochod bmw_m5("samochod", "bmw", "m5", 2021, 635, 3.0, 602);
    cout << "Obiekt klasy samochod\n";
    bmw_m5.pokaz();

    Spalinowy bmw_5("samochod", "bmw", "m5", 2021, 635, 3.0, 602, "benzyna");
    cout << endl << "Obiekt klasy Spalinowy\n";
    bmw_5.pokaz();

    Elektryczny tesla("samochod", "tesla", "3", 2021, 380, 3.2, 500, "100");
    cout << "Obiekt klasy Elekryczny\n";
    tesla.pokaz();

    Hybrydowy toyota("samochod", "toyota", "corolla", 2021, 184, 9.2, 600, "benzyna", "100");
    cout << "Obiekt klasy Hybrydowy\n";
    toyota.pokaz();

    //car tesla;

    tesla.uruchom();
    tesla.przyspiesz();
    tesla.przyspiesz();
    //cout << tesla;//przeciazenie operatora wyswietlania
    tesla.przyspiesz();
    tesla.przyspiesz();
    tesla.wyswietl();
    tesla.hamuj();
    tesla.hamuj();
    tesla.hamuj();
    tesla.wylacz();

}*/