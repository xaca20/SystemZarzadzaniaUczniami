#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
// Definicje klas: Uczen, Nauczyciel, Przedmiot, Platnosc, Harmonogram
class Uczen
{
private:
	string imie; // imiê ucznia
	string nazwisko; // nazwisko ucznia
	string klasa; // klasa: 1A, 2B, 3C itd.
	string poziom; // poziom: podstawowy, rozszerzony
	string tryb; // tryb: stacjonarny, online
public:
	// Konstruktor Uczen
	Uczen() : imie(""), nazwisko(""), klasa(""), poziom(""), tryb("") {}

	// Settery i gettery dla pól klasy Uczen
	void setImie(string imie)
	{
		this->imie = imie;
	}
	void setNazwisko(string nazwisko)
	{
		this->nazwisko = nazwisko;
	}
	void setKlasa(string klasa)
	{
		this->klasa = klasa;
	}
	void setPoziom(string poziom)
	{
		this->poziom = poziom;
	}
	void setTryb(string tryb)
	{
		this->tryb = tryb;
	}
	string getImie() const
	{
		return imie;
	}
	string getNazwisko() const
	{
		return nazwisko;
	}
	string getKlasa() const
	{
		return klasa;
	}
	string getPoziom() const
	{
		return poziom;
	}
	string getTryb() const
	{
		return tryb;
	}
	virtual ~Uczen() {}
};

void UstawUczen(Uczen u1)
{
	string imie, nazwisko, klasa, poziom, tryb;

	cout<<"Podaj imiê ucznia: ";
	cin >> imie;
	u1.setImie(imie);
	cout<<"Podaj nazwisko ucznia: ";
	cin >> nazwisko;
	u1.setNazwisko(nazwisko);
	cout<<"Podaj klasê ucznia: ";
	cin >> klasa;
	u1.setKlasa(klasa);
	cout<<"Podaj poziom ucznia (p - podstawowy, r - rozszerzony): ";
	cin >> poziom;
	u1.setPoziom(poziom);
	cout<<"Podaj tryb ucznia (s - stacjonarny, o - online): ";
	cin >> tryb;
	u1.setTryb(tryb);
	cout << endl;
	cout << "Dane ucznia zosta³y ustawione." << endl;

	//Wczytywanie danych ucznia do pliku
	ofstream plik("dane_uczen.txt", ios::app);
		if(!plik) 
		{
			cout << "Nie mo¿na otworzyæ pliku do zapisu!" << endl;
		}
		else
		{
			plik << u1.getImie() << "|" << u1.getNazwisko() << "|" << u1.getKlasa() << "|" << u1.getPoziom() << "|" << u1.getTryb() << endl;
			plik.close();
			cout << "Dane ucznia zosta³y dodane." << endl;
		}
}

//Funkcja do wyszukiwania ucznia w pliku
string modyfikujUczen()
{
	Uczen u1; // Tworzenie obiektu ucznia do modyfikacji danych
	string imie, nazwisko;
	cout << "Podaj imiê ucznia: ";
	cin >> imie;
	cout<<"Podaj nazwisko ucznia: ";
	cin >> nazwisko;
	cout << endl;

	//Przeszukuje plik dane_uczen.txt w poszukiwaniu ucznia o podanym imieniu i nazwisku
	ifstream szukaj("dane_uczen.txt", ios::app);
	// Plik tymczasowy do zapisu zmodyfikowanych danych
	ofstream zapiszTymczasowo("dane_uczen_tymczasowo.txt", ios::app);
	if (!szukaj || !zapiszTymczasowo) 
	{
		cout << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
		return "";
	}

	string linia;
	while (getline(szukaj, linia))
	{
		if (linia.find(imie) != string::npos && linia.find(nazwisko) != string::npos)
		{
			int wybor=0;
			do
			{
			cout<<"Co chcesz zmieniæ w danych ucznia?"<<endl;
			cout<<"1. Imiê"<<endl;
			cout<<"2. Nazwisko"<<endl;
			cout<<"3. Klasê"<<endl;
			cout<<"4. Poziom"<<endl;
			cout<<"5. Tryb"<<endl;
			cout<<"6. Zakoñcz modyfikacjê"<<endl;
				cin >> wybor;
				switch (wybor)
				{
				case 1:
				{
					string noweImie;
					cout << "Podaj nowe imiê ucznia: ";
					cin >> noweImie;
					u1.setImie(noweImie);
					// Znajduje znak '|' w linii przed wartoœci¹ do zmiany i zastêpuje wartoœæ po nim
					linia.replace((linia.find_last_of("|") + 2), string::npos, u1.getImie());
					zapiszTymczasowo << linia << endl; // Zapisuje zmodyfikowan¹ liniê do pliku tymczasowego
					break;
				}
				case 2:
				{
					string noweNazwisko;
					cout << "Podaj nowe nazwisko ucznia: ";
					cin >> noweNazwisko;
					u1.setNazwisko(noweNazwisko);
					linia.replace((linia.find_last_of("|") + 2), string::npos, u1.getNazwisko());
					zapiszTymczasowo << linia << endl;
					break;
				}
				case 3:
				{
					string nowaKlasa;
					cout << "Podaj now¹ klasê ucznia: ";
					cin >> nowaKlasa;
					u1.setKlasa(nowaKlasa);
					linia.replace((linia.find_last_of("|") + 2), string::npos, u1.getKlasa());
					zapiszTymczasowo << linia << endl;
					break;
				}
				case 4:
				{
					string nowyPoziom;
					cout << "Podaj nowy poziom ucznia (p - podstawowy, r - rozszerzony): ";
					cin >> nowyPoziom;
					u1.setPoziom(nowyPoziom);
					linia.replace((linia.find_last_of("|") + 2), string::npos, u1.getTryb());
					zapiszTymczasowo << linia << endl;
					break;
				}
				case 5:
				{
					string nowyTryb;
					cout << "Podaj nowy tryb ucznia (s - stacjonarny, o - online): ";
					cin >> nowyTryb;
					u1.setTryb(nowyTryb);
					linia.replace(linia.find_last_of("|") + 2, string::npos, u1.getTryb());
					zapiszTymczasowo << linia << endl;
					break;
				}
				default:
				{
					cout << "Nieprawid³owy wybór." << endl;
					break;
				}
				}
			} while (wybor!=6);
			szukaj.close();
			zapiszTymczasowo.close();
			remove("dane_uczen.txt"); // Usuwa oryginalny plik
			rename("dane_uczen_tymczasowo.txt", "dane_uczen.txt"); // Zmienia nazwê pliku tymczasowego na oryginalny
			cout<<"Zmiany zostaly zapisane."<<endl;
			Sleep(5000);
			break;
		}
		else
		{
			szukaj.close();
			zapiszTymczasowo.close();
			cout << "Nie znaleziono ucznia o podanym imieniu i nazwisku." << endl;
			return ""; // Zwraca pusty string, jeœli nie znaleziono ucznia
			break;
		}
	}
	return "";
	
}

class Nauczyciel
{
private:
	string imie; // imiê nauczyciela
	string nazwisko; // nazwisko nauczyciela
	string przedmiot; // przedmiot nauczany przez nauczyciela
	int liczbaGodzin; // liczba godzin lekcyjnych w tygodniu
public:
	// Konstruktor Nauczyciel
	Nauczyciel() : imie(""), nazwisko(""), przedmiot(""), liczbaGodzin(0) {}

	// Setter i gettery dla pól klasy Nauczyciel
	void setImie(string imie)
	{
		this->imie = imie;
	}
	void setNazwisko(string nazwisko)
	{
		this->nazwisko = nazwisko;
	}
	void setPrzedmiot(string przedmiot)
	{
		this->przedmiot = przedmiot;
	}
	void setLiczbaGodzin(int liczbaGodzin)
	{
		this->liczbaGodzin = liczbaGodzin;
	}
	string getImie() const
	{
		return imie;
	}
	string getNazwisko() const
	{
		return nazwisko;
	}
	string getPrzedmiot() const
	{
		return przedmiot;
	}
	int getLiczbaGodzin() const
	{
		return liczbaGodzin;
	}
	
	virtual ~Nauczyciel() {};
};

void UstawNauczyciel(Nauczyciel n1)
{
	string imie, nazwisko, przedmiot;
	int liczbaGodzin;

	cout << "Podaj imiê nauczyciela: ";
	cin >> imie;
	n1.setImie(imie);
	cout << "Podaj nazwisko nauczyciela: ";
	cin >> nazwisko;
	n1.setNazwisko(nazwisko);
	cout << "Podaj przedmiot nauczany przez nauczyciela: ";
	cin >> przedmiot;
	n1.setPrzedmiot(przedmiot);
	cout << "Podaj liczbê godzin lekcyjnych w tygodniu: ";
	cin >> liczbaGodzin;
	n1.setLiczbaGodzin(liczbaGodzin);
	cout << endl;
	cout << "Dane nauczyciela zosta³y ustawione." << endl;

	//Wczytywanie danych nauczyciela do pliku
	ofstream plik("dane_nauczyciel.txt", ios::app);
	if (!plik) 
	{
		cout << "Nie mo¿na otworzyæ pliku do zapisu!" << endl;
	}
	else
	{
		plik << n1.getImie() << "|" << n1.getNazwisko() << "|" << n1.getPrzedmiot() << "|" << n1.getLiczbaGodzin() << endl;
		plik.close();
	}
}

string modyfikujNauczyciel()
{
	string imie, nazwisko;
	cout << "Podaj imiê nauczyciela: ";
	cin >> imie;
	cout << "Podaj nazwisko nauczyciela: ";
	cin >> nazwisko;
	cout << endl;

	//Przeszukuje plik dane_nauczyciel.txt w poszukiwaniu nauczyciela o podanym imieniu i nazwisku
	ifstream szukaj("dane_nauczyciel.txt");
	if (!szukaj)
	{
		cout << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
		return "";
	}

	string linia;
	while (getline(szukaj, linia))
	{
		if (linia.find(imie) != string::npos && linia.find(nazwisko) != string::npos)
		{
			szukaj.close();
			return linia; // Zwraca linijkê z danymi nauczyciela
			break;
		}
		else
		{
			szukaj.close();
			cout << "Nie znaleziono nauczyciela o podanym imieniu i nazwisku." << endl;
			return ""; // Zwraca pusty string, jeœli nie znaleziono nauczyciela
			break;
		}
	}
	return "";

}

class Przedmiot
{
private:
	string nazwa; // nazwa przedmiotu
	string poziom; // poziom: podstawowy, rozszerzony
	int liczbaGodzin; // liczba godzin wystepowania przedmiot w tygodniu
public:
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
