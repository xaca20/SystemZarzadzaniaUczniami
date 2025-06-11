#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
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




string modyfikujUczen() {
	Uczen u1;
	string imie, nazwisko;
	cout << "Podaj imiê ucznia: ";
	cin >> imie;
	cout << "Podaj nazwisko ucznia: ";
	cin >> nazwisko;
	cout << endl;

	// Otwieranie plików - poprawione flagi
	ifstream szukaj("dane_uczen.txt");
	ofstream zapiszTymczasowo("dane_tymczasowo.txt");

	if (!szukaj.is_open() || !zapiszTymczasowo.is_open()) {
		cout << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
		return "";
	}

	bool znaleziono = false;
	string linia;

	while (getline(szukaj, linia)) {
		// Sprawdzamy czy linia zawiera zarówno imiê jak i nazwisko
		size_t pos_imie = linia.find(imie);
		size_t pos_nazwisko = linia.find(nazwisko);

		if (pos_imie != string::npos && pos_nazwisko != string::npos) {
			znaleziono = true;
			int wybor = 0;

			do {
				cout << "\nCo chcesz zmieniæ w danych ucznia?" << endl;
				cout << "1. Imiê" << endl;
				cout << "2. Nazwisko" << endl;
				cout << "3. Klasê" << endl;
				cout << "4. Poziom" << endl;
				cout << "5. Tryb" << endl;
				cout << "6. Zakoñcz modyfikacjê" << endl;
				cout << "Wybierz opcjê: ";
				cin >> wybor;

				// Parsowanie linii na pola
				size_t start = 0;
				size_t end = linia.find('|');
				vector<string> pola;

				while (end != string::npos) {
					pola.push_back(linia.substr(start, end - start));
					start = end + 1;
					end = linia.find('|', start);
				}
				pola.push_back(linia.substr(start));

				switch (wybor) {
				case 1: {
					string noweImie;
					cout << "Podaj nowe imiê ucznia: ";
					cin >> noweImie;
					u1.setImie(noweImie);
					pola[0] = noweImie;
					break;
				}
				case 2: {
					string noweNazwisko;
					cout << "Podaj nowe nazwisko ucznia: ";
					cin >> noweNazwisko;
					u1.setNazwisko(noweNazwisko);
					pola[1] = noweNazwisko;
					break;
				}
				case 3: {
					string nowaKlasa;
					cout << "Podaj now¹ klasê ucznia: ";
					cin >> nowaKlasa;
					u1.setKlasa(nowaKlasa);
					pola[2] = nowaKlasa;
					break;
				}
				case 4: {
					string nowyPoziom;
					cout << "Podaj nowy poziom ucznia (p - podstawowy, r - rozszerzony): ";
					cin >> nowyPoziom;
					u1.setPoziom(nowyPoziom);
					pola[3] = nowyPoziom;
					break;
				}
				case 5: {
					string nowyTryb;
					cout << "Podaj nowy tryb ucznia (s - stacjonarny, o - online): ";
					cin >> nowyTryb;
					u1.setTryb(nowyTryb);
					pola[4] = nowyTryb;
					break;
				}
				case 6:
					cout << "Zakoñczono modyfikacjê." << endl;
					break;
				default:
					cout << "Nieprawid³owy wybór. Spróbuj ponownie." << endl;
					break;
				}

				// Rekonstrukcja linii z pól
				linia.clear();
				for (size_t i = 0; i < pola.size(); ++i) {
					linia += pola[i];
					if (i != pola.size() - 1) {
						linia += "|";
					}
				}

			} while (wybor != 6);

			// Zapis zmodyfikowanej linii
			zapiszTymczasowo << linia << endl;
		}
		else {
			// Zapis linii bez zmian
			zapiszTymczasowo << linia << endl;
		}
	}

	szukaj.close();
	zapiszTymczasowo.close();

	if (!znaleziono) {
		cout << "Nie znaleziono ucznia o podanym imieniu i nazwisku." << endl;
		remove("dane_tymczasowo.txt"); // Usuwamy niepotrzebny plik tymczasowy
		return "";
	}

	// Zamiana plików
	remove("dane_uczen.txt");
	rename("dane_tymczasowo.txt", "dane_uczen.txt");

	cout << "Zmiany zosta³y zapisane." << endl;
	Sleep(1000);

	return "";
}

class Nauczyciel
{
private:
	string imie; // imiê nauczyciela
	string nazwisko; // nazwisko nauczyciela
	string przedmiot; // przedmiot nauczany przez nauczyciela
public:
	// Konstruktor Nauczyciel
	Nauczyciel() : imie(""), nazwisko(""), przedmiot("") {}

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

	virtual ~Nauczyciel() {};
};

void UstawNauczyciel(Nauczyciel n1)
{
	string imie, nazwisko, przedmiot;

	cout << "Podaj imiê nauczyciela: ";
	cin >> imie;
	n1.setImie(imie);
	cout << "Podaj nazwisko nauczyciela: ";
	cin >> nazwisko;
	n1.setNazwisko(nazwisko);
	cout << "Podaj przedmiot nauczany przez nauczyciela: ";
	cin >> przedmiot;
	n1.setPrzedmiot(przedmiot);
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
		plik << n1.getImie() << "|" << n1.getNazwisko() << "|" << n1.getPrzedmiot()  << endl;
		plik.close();
	}
}
//modyfikacja danych nauczyciela
string modyfikujNauczyciel() {
	Nauczyciel n1;
	string imie, nazwisko;
	cout << "Podaj imiê nauczyciela: ";
	cin >> imie;
	cout << "Podaj nazwisko nauczyciela: ";
	cin >> nazwisko;
	cout << endl;

	// Otwieranie plików - poprawione flagi
	ifstream szukaj("dane_nauczyciel.txt");
	ofstream zapiszTymczasowo("dane_tymczasowo.txt");

	if (!szukaj.is_open() || !zapiszTymczasowo.is_open()) {
		cout << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
		return "";
	}

	bool znaleziono = false;
	string linia;

	while (getline(szukaj, linia)) {
		// Sprawdzamy czy linia zawiera zarówno imiê jak i nazwisko
		size_t pos_imie = linia.find(imie);
		size_t pos_nazwisko = linia.find(nazwisko);

		if (pos_imie != string::npos && pos_nazwisko != string::npos) {
			znaleziono = true;
			int wybor = 0;

			do {
				cout << "\nCo chcesz zmieniæ w danych nauczyciela?" << endl;
				cout << "1. Imiê" << endl;
				cout << "2. Nazwisko" << endl;
				cout << "3. Przedmiot" << endl;
				cout << "4. Zakoñcz modyfikacjê" << endl;
				cout << "Wybierz opcjê: ";
				cin >> wybor;

				// Parsowanie linii na pola
				size_t start = 0;
				size_t end = linia.find('|');
				vector<string> pola;

				while (end != string::npos) {
					pola.push_back(linia.substr(start, end - start));
					start = end + 1;
					end = linia.find('|', start);
				}
				pola.push_back(linia.substr(start));

				switch (wybor) {
				case 1: {
					string noweImie;
					cout << "Podaj nowe imiê nauczyciela: ";
					cin >> noweImie;
					n1.setImie(noweImie);
					pola[0] = noweImie;
					break;
				}
				case 2: {
					string noweNazwisko;
					cout << "Podaj nowe nazwisko nauczyciela: ";
					cin >> noweNazwisko;
					n1.setNazwisko(noweNazwisko);
					pola[1] = noweNazwisko;
					break;
				}
				case 3: {
					string nowyPrzedmiot;
					cout << "Podaj nowy przedmiot nauczyciela: ";
					cin >> nowyPrzedmiot;
					n1.setPrzedmiot(nowyPrzedmiot);
					pola[2] = nowyPrzedmiot;
					break;
				}
				case 4:
					cout << "Zakoñczono modyfikacjê." << endl;
					break;
				default:
					cout << "Nieprawid³owy wybór. Spróbuj ponownie." << endl;
					break;
				}

				// Rekonstrukcja linii z pól
				linia.clear();
				for (size_t i = 0; i < pola.size(); ++i) {
					linia += pola[i];
					if (i != pola.size() - 1) {
						linia += "|";
					}
				}

			} while (wybor != 4);

			// Zapis zmodyfikowanej linii
			zapiszTymczasowo << linia << endl;
		}
		else {
			// Zapis linii bez zmian
			zapiszTymczasowo << linia << endl;
		}
	}

	szukaj.close();
	zapiszTymczasowo.close();

	if (!znaleziono) {
		cout << "Nie znaleziono ucznia o podanym imieniu i nazwisku." << endl;
		remove("dane_tymczasowo.txt"); // Usuwamy niepotrzebny plik tymczasowy
		return "";
	}

	// Zamiana plików
	remove("dane_nauczyciel.txt");
	rename("dane_tymczasowo.txt", "dane_nauczyciel.txt");

	cout << "Zmiany zosta³y zapisane." << endl;
	Sleep(1000);

	return "";
}


// Klasa reprezentuj¹ca pojedyncze zajêcia
class Zajecia {
private:
	string nauczyciel;
	string przedmiot;
	vector<string> uczniowie;
	string data;
	string godzinaRozpoczecia;
	string godzinaZakonczenia;

public:
	Zajecia(string nauczyciel, string przedmiot, string data, string godzRozp, string godzZak)
		: nauczyciel(nauczyciel), przedmiot(przedmiot), data(data),
		godzinaRozpoczecia(godzRozp), godzinaZakonczenia(godzZak) {}

	// Metoda dodaj¹ca ucznia do zajêæ
	void dodajUcznia(const string& uczen) {
		if (find(uczniowie.begin(), uczniowie.end(), uczen) == uczniowie.end()) {
			uczniowie.push_back(uczen);
		}
	}

	// Metoda usuwaj¹ca ucznia z zajêæ
	void usunUcznia(const string& uczen) {
		auto it = find(uczniowie.begin(), uczniowie.end(), uczen);
		if (it != uczniowie.end()) {
			uczniowie.erase(it);
		}
	}

	// Gettery
	string getNauczyciel() const { return nauczyciel; }
	string getPrzedmiot() const { return przedmiot; }
	vector<string> getUczniowie() const { return uczniowie; }
	string getData() const { return data; }
	string getGodzinaRozpoczecia() const { return godzinaRozpoczecia; }
	string getGodzinaZakonczenia() const { return godzinaZakonczenia; }

	// Metoda do zapisu zajêæ do pliku
	string zapiszDoPliku() const {
		stringstream ss;
		ss << nauczyciel << "|" << przedmiot << "|" << data << "|"
			<< godzinaRozpoczecia << "|" << godzinaZakonczenia << "|";

		for (size_t i = 0; i < uczniowie.size(); ++i) {
			ss << uczniowie[i];
			if (i != uczniowie.size() - 1) {
				ss << ",";
			}
		}

		return ss.str();
	}

	// Metoda do wczytywania zajêæ z pliku
	static Zajecia wczytajZPliku(const string& linia) {
		vector<string> elementy;
		size_t start = 0;
		size_t end = linia.find('|');

		while (end != string::npos) {
			elementy.push_back(linia.substr(start, end - start));
			start = end + 1;
			end = linia.find('|', start);
		}

		// Ostatni element to lista uczniów oddzielona przecinkami
		string uczniowieStr = linia.substr(start);
		vector<string> uczniowie;
		size_t uStart = 0;
		size_t uEnd = uczniowieStr.find(',');

		while (uEnd != string::npos) {
			uczniowie.push_back(uczniowieStr.substr(uStart, uEnd - uStart));
			uStart = uEnd + 1;
			uEnd = uczniowieStr.find(',', uStart);
		}
		if (!uczniowieStr.empty()) {
			uczniowie.push_back(uczniowieStr.substr(uStart));
		}

		return Zajecia(elementy[0], elementy[1], elementy[2], elementy[3], elementy[4]);
	}
};

// Klasa zarz¹dzaj¹ca harmonogramem
class Harmonogram {
private:
	map<string, vector<Zajecia>> harmonogram; // Klucz: data, wartoœæ: lista zajêæ

	// Metoda wczytuj¹ca dane z pliku
	vector<string> wczytajDane(const string& plik) {
		vector<string> dane;
		ifstream file(plik);
		string linia;

		while (getline(file, linia)) {
			dane.push_back(linia);
		}

		return dane;
	}
	vector<string> rozdzielDane(const string& linia) {
		vector<string> elementy;
		size_t start = 0;
		size_t end = linia.find('|');

		while (end != string::npos) {
			elementy.push_back(linia.substr(start, end - start));
			start = end + 1;
			end = linia.find('|', start);
		}
		elementy.push_back(linia.substr(start));

		return elementy;
	}
public:
	// Metoda dodaj¹ca nowe zajêcia
	void dodajZajecia() {
		cout << "==== DODAWANIE NOWYCH ZAJÊÆ ====\n";

		// Wczytanie dostêpnych nauczycieli
		vector<string> nauczyciele = wczytajDane("dane_nauczyciel.txt");
		cout << "Dostêpni nauczyciele:\n";
		for (size_t i = 0; i < nauczyciele.size(); ++i) {
			vector<string> dane = rozdzielDane(nauczyciele[i]);
			cout << i + 1 << ". " << dane[0] << " " << dane[1] << " (" << dane[2] << ")\n";
		}

		int wyborNauczyciela;
		cout << "Wybierz numer nauczyciela: ";
		cin >> wyborNauczyciela;
		string wybranyNauczyciel = nauczyciele[wyborNauczyciela - 1];

		// Wczytanie danych zajêæ
		string data, godzRozp, godzZak, przedmiot;
		cout << "Podaj datê (DD.MM.RRRR): ";
		cin >> data;
		cout << "Podaj godzinê rozpoczêcia (GG:MM): ";
		cin >> godzRozp;
		cout << "Podaj godzinê zakoñczenia (GG:MM): ";
		cin >> godzZak;
		cout << "Podaj przedmiot: ";
		cin.ignore();
		getline(cin, przedmiot);

		// Sprawdzenie czy termin jest wolny
		if (czyTerminZajety(data, godzRozp, godzZak)) {
			cout << "Termin jest ju¿ zajêty!\n";
			return;
		}

		// Tworzenie nowych zajêæ
		Zajecia noweZajecia(wybranyNauczyciel, przedmiot, data, godzRozp, godzZak);

		// Dodawanie uczniów
		vector<string> uczniowie = wczytajDane("dane_uczen.txt");
		cout << "Dostêpni uczniowie:\n";
		for (size_t i = 0; i < uczniowie.size(); ++i) {
			vector<string> dane = rozdzielDane(uczniowie[i]);
			cout << i + 1 << ". " << dane[0] << " " << dane[1] << " (" << dane[2] << ")\n";
		}

		cout << "Wybierz numery uczniów (0 aby zakoñczyæ):\n";
		int wybor;
		while (cin >> wybor && wybor != 0) {
			noweZajecia.dodajUcznia(uczniowie[wybor - 1]);
		}

		// Dodanie do harmonogramu
		harmonogram[data].push_back(noweZajecia);
		zapiszDoPliku();

		cout << "Zajêcia zosta³y dodane do harmonogramu!\n";
	}

	// Metoda sprawdzaj¹ca czy termin jest zajêty
	bool czyTerminZajety(const string& data, const string& godzRozp, const string& godzZak) {
		if (harmonogram.find(data) == harmonogram.end()) {
			return false;
		}

		for (const auto& zajecia : harmonogram[data]) {
			if ((godzRozp >= zajecia.getGodzinaRozpoczecia() && godzRozp < zajecia.getGodzinaZakonczenia()) ||
				(godzZak > zajecia.getGodzinaRozpoczecia() && godzZak <= zajecia.getGodzinaZakonczenia()) ||
				(godzRozp <= zajecia.getGodzinaRozpoczecia() && godzZak >= zajecia.getGodzinaZakonczenia())) {
				return true;
			}
		}

		return false;
	}

	void wyswietlHarmonogram() const {
		cout << "=== HARMONOGRAM ZAJÊÆ ===\n";

		if (harmonogram.empty()) {
			cout << "Harmonogram jest pusty.\n";
			return;
		}

		map<string, vector<Zajecia>>::const_iterator it;
		for (it = harmonogram.begin(); it != harmonogram.end(); ++it) {
			string data = it->first;
			const vector<Zajecia>& listaZajec = it->second;

			cout << "Data: " << data << "\n";

			for (size_t i = 0; i < listaZajec.size(); ++i) {
				const Zajecia& zajecia = listaZajec[i];
				cout << "  " << zajecia.getGodzinaRozpoczecia() << "-" << zajecia.getGodzinaZakonczenia()
					<< ": " << zajecia.getPrzedmiot() << " (" << zajecia.getNauczyciel() << ")\n";
				cout << "  Uczniowie: ";

				const vector<string>& uczniowie = zajecia.getUczniowie();
				for (size_t j = 0; j < uczniowie.size(); ++j) {
					cout << uczniowie[j];
					if (j != uczniowie.size() - 1) {
						cout << ", ";
					}
				}
				cout << "\n\n";
			}
		}
	}

	void zapiszDoPliku() {
		ofstream plik("harmonogram.txt");
		if (!plik.is_open()) {
			cout << "Nie mo¿na otworzyæ pliku do zapisu!\n";
			return;
		}

		map<string, vector<Zajecia>>::const_iterator it;
		for (it = harmonogram.begin(); it != harmonogram.end(); ++it) {
			const vector<Zajecia>& listaZajec = it->second;

			for (size_t i = 0; i < listaZajec.size(); ++i) {
				plik << listaZajec[i].zapiszDoPliku() << "\n";
			}
		}
		plik.close();
	}

	void wczytajZPliku() {
		ifstream plik("harmonogram.txt");
		if (!plik.is_open()) {
			cout << "Nie mo¿na otworzyæ pliku do odczytu!\n";
			return;
		}

		string linia;
		while (getline(plik, linia)) {
			Zajecia zajecia = Zajecia::wczytajZPliku(linia);
			harmonogram[zajecia.getData()].push_back(zajecia);
		}
		plik.close();
	}


	static Zajecia wczytajZPliku(const string& linia) {
		vector<string> elementy;
		size_t start = 0;
		size_t end = linia.find('|');

		while (end != string::npos) {
			elementy.push_back(linia.substr(start, end - start));
			start = end + 1;
			end = linia.find('|', start);
		}

		// Parsowanie uczniów
		string uczniowieStr = linia.substr(start);
		vector<string> uczniowie;
		size_t uStart = 0;
		size_t uEnd = uczniowieStr.find(',');

		while (uEnd != string::npos) {
			uczniowie.push_back(uczniowieStr.substr(uStart, uEnd - uStart));
			uStart = uEnd + 1;
			uEnd = uczniowieStr.find(',', uStart);
		}
		if (!uczniowieStr.empty()) {
			uczniowie.push_back(uczniowieStr.substr(uStart));
		}

		// Tworzenie obiektu zajêæ
		Zajecia zajecie(elementy[0], elementy[1], elementy[2], elementy[3], elementy[4]);

		// Dodawanie uczniów
		for (const auto& uczen : uczniowie) {
			zajecie.dodajUcznia(uczen);
		}

		return zajecie;
	}

	
};

#endif // KLASY_H
