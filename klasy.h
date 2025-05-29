#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <iostream>
using namespace std;
// Definicje klas: Osoba, Uczen, Nauczyciel, Przedmiot, Platnosc, Harmonogram
class Osoba
{
private:
	string imie, nazwisko; // imiê i nazwisko osoby, dziedziczone przez Uczen i Nauczyciel
public:
};
class Uczen : public Osoba
{
private:
	string imie; // imiê ucznia
	string nazwisko; // nazwisko ucznia
	string klasa; // klasa: 1A, 2B, 3C itd.
	string poziom; // poziom: podstawowy, rozszerzony
	string tryb; // tryb: stacjonarny, online
public:
	Uczen(string imie, string nazwisko, string klasa, string poziom, string tryb)
		: imie(imie), nazwisko(nazwisko), klasa(klasa), poziom(poziom), tryb(tryb) {}

	void wyswietl() const
	{
		cout << "Imie ucznia: " << imie << endl;
		cout << "Nazwisko ucznia: " << nazwisko << endl;
		cout << "Klasa: " << klasa << endl;
		cout << "Poziom: " << poziom << endl;
		cout << "Tryb: " << tryb << endl;
	}
};
class Nauczyciel : public Osoba
{
private:
	string imie; // imiê nauczyciela
	string nazwisko; // nazwisko nauczyciela
	string przedmiot; // przedmiot nauczany przez nauczyciela
	int liczbaGodzin; // liczba godzin lekcyjnych w tygodniu
public:
	Nauczyciel(string imie, string nazwisko, string przedmiot, int liczbaGodzin)
		: imie(imie), nazwisko(nazwisko), przedmiot(przedmiot), liczbaGodzin(liczbaGodzin) {}
	void wyswietl() const
	{
		cout << "Imie nauczyciela: " << imie << endl;
		cout << "Nazwisko nauczyciela: " << nazwisko << endl;
		cout << "Przedmiot: " << przedmiot << endl;
		cout << "Liczba godzin w tygodniu: " << liczbaGodzin << endl;
	}
};
class Przedmiot
{
private:
	string nazwa; // nazwa przedmiotu
	string poziom; // poziom: podstawowy, rozszerzony
	int liczbaGodzin; // liczba godzin lekcyjnych w tygodniu
public:
	void podajDane() // Metoda do wprowadzania danych przedmiotu
	{
		cout << "Podaj nazwê przedmiotu: ";
		cin >> nazwa;
		cout << "Podaj poziom (podstawowy, rozszerzony): ";
		cin >> poziom;
		cout << "Podaj liczbê godzin lekcyjnych w tygodniu: ";
		cin >> liczbaGodzin;
	}
	void wyswietl() const
	{
		cout << "Nazwa przedmiotu: " << nazwa << endl;
		cout << "Poziom: " << poziom << endl;
		cout << "Liczba godzin w tygodniu: " << liczbaGodzin << endl;
	}
};
class Platnosc
{
private:
	string typ; // typ p³atnoœci: gotówka, karta, przelew
	double kwota; // kwota p³atnoœci
	string data; // data p³atnoœci
	string opis; // opis p³atnoœci (np. czesne, materia³y)
public:
	void podajDane() // Metoda do wprowadzania danych p³atnoœci
	{
		cout << "Podaj typ p³atnoœci (gotówka, karta, przelew): ";
		cin >> typ;
		cout << "Podaj kwotê: ";
		cin >> kwota;
		cout << "Podaj datê (DD-MM-YYYY): ";
		cin >> data;
		cout << "Podaj opis p³atnoœci: ";
		cin >> opis;
	}
	void wyswietl() const
	{
		cout << "Typ p³atnoœci: " << typ << endl;
		cout << "Kwota: " << kwota << endl;
		cout << "Data: " << data << endl;
		cout << "Opis: " << opis << endl;
	}
};
class Harmonogram
{
private:
	string dzienTygodnia; // dzieñ tygodnia (np. poniedzia³ek, wtorek)
	string godzina; // godzina rozpoczêcia lekcji
	string przedmiot; // przedmiot lekcji
	string nauczyciel; // nauczyciel prowadz¹cy lekcjê
	string tryb; // tryb lekcji: stacjonarny, online
public:
	void podajHarmonogram() const // Metoda do wprowadzania harmonogramu
	{
		/*string dzien, godz, przed, nauczyciel, tryb;
		cout << "Dzien: ";
		cin >> dzien;
		cout << "Godzina: ";
		cin >> godz;
		cout << "Przedmiot: ";
		cin >> przed;
		cout << "Nauczyciel: ";
		cin >> nauczyciel;
		cout << "Tryb: ";
		cin >> tryb;
		cout << endl;
		dzienTygodnia = dzien;
		godzina = godz;
		przedmiot = przed;
		this->nauczyciel = nauczyciel;
		this->tryb = tryb;*/
	}
	// Gettery i settery dla pól klasy Harmonogram
	string getDzienTygodnia() const { return dzienTygodnia; }
	string getGodzina() const { return godzina; }
	string getPrzedmiot() const { return przedmiot; }
	string getNauczyciel() const { return nauczyciel; }
	string getTryb() const { return tryb; }
	void setDzienTygodnia(const string& dzien) { dzienTygodnia = dzien; }
	void setGodzina(const string& godz) { godzina = godz; }
	void setPrzedmiot(const string& przed) { przedmiot = przed; }
	void setNauczyciel(const string& nauczyciel) { this->nauczyciel = nauczyciel; }
	void setTryb(const string& tryb) { this->tryb = tryb; }
	// Metoda do wyœwietlania harmonogramu
	void wyswietl() const
	{
		cout << "Harmonogram lekcji:" << endl;
		cout << "Dzieñ tygodnia: " << dzienTygodnia << endl;
		cout << "Godzina rozpoczêcia: " << godzina << endl;
		cout << "Przedmiot: " << przedmiot << endl;
		cout << "Nauczyciel: " << nauczyciel << endl;
		cout << "Tryb: " << tryb << endl;
	}
};


#endif // KLASY_H
