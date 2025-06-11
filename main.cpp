#include "klasy.h"

int main()
{
    setlocale(LC_ALL, "Polish");
    int opcja = 0;
    do
    {
        system("cls");
        cout << "=================================" << endl;
        cout << "  System zarzadzania uczniami" << endl;
        cout << "=================================" << endl;
        cout << "  Wybierz opcje:" << endl;
        cout << "  1. Wprowadz dane ucznia" << endl;
        cout << "  2. Modyfikuj dane ucznia" << endl;
        cout << "  3. Wprowadz dane nauczyciela" << endl;
        cout << "  4. Modyfikuj dane nauczyciela" << endl;
        cout << "  5. Wprowadz dane zajęć" << endl;
        cout << "  6. Wyświetl harmonogram zajęć" << endl;
        cout << "  7. Wyjście z programu" << endl;
        cin >> opcja;
        switch (opcja)
        {
        case 1:
        {
            system("cls");
            Uczen u1;
            UstawUczen(u1);
            break;
        }
        case 2:
        {
            system("cls");
            cout<<modyfikujUczen();
            Sleep(5000);
            break;
        }
        case 3:
        {
            system("cls");
            Nauczyciel n1;
            UstawNauczyciel(n1);
            break;
        }
        case 4:
        {
            system("cls");
            cout<<modyfikujNauczyciel();
            Sleep(5000);
            break;
        }
        case 5:
        {
            system("cls");
            Harmonogram harmonogram;
            harmonogram.wczytajZPliku();
            //Harmonogram h1;
            int wybor;
            do {
                cout << "\n==== MENU HARMONOGRAMU ====\n";
                cout << "1. Dodaj nowe zajęcia\n";
                cout << "2. Wyświetl harmonogram\n";
                cout << "3. Zapisz zmiany\n";
                cout << "0. Wyjście\n";
                cout << "Wybierz opcję: ";
                cin >> wybor;

                switch (wybor) {
                case 1: harmonogram.dodajZajecia(); break;
                case 2: harmonogram.wyswietlHarmonogram(); break;
                case 3: harmonogram.zapiszDoPliku(); break;
                }
            } while (wybor != 0);
           
            break;
        }
        case 6:
        {
            system("cls");
            cout << "Dziekujemy za skorzystanie z programu!" << endl;
            break;
        }
        case 7:
        {
            system("cls");
            cout << "Dziekujemy za skorzystanie z programu!" << endl;
            break;
        }
        default:
        {
            system("cls");
            cout << "Nieznana opcja! Spróbuj ponownie!" << endl;
            break;
        }
        }
    } while (opcja != 7);
    return 0;
}