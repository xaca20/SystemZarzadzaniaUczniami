#include "klasy.h"
#include <limits>
#include <iostream>
int main()
{
    setlocale(LC_ALL, "Polish");
    char opcja = '0';
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
        cout << "  5. Harmonogram" << endl;
        cout << "  6. Wyjście z programu" << endl;
        opcja = getchar();
        switch (opcja)
        {
        case '1':
        {
            system("cls");
            Uczen u1;
            UstawUczen(u1);
            break;
        }
        case '2':
        {
            system("cls");
            cout<<modyfikujUczen();
            Sleep(5000);
            break;
        }
        case '3':
        {
            system("cls");
            Nauczyciel n1;
            UstawNauczyciel(n1);
            break;
        }
        case '4':
        {
            system("cls");
            cout<<modyfikujNauczyciel();
            Sleep(5000);

            break;
        }
        case '5':
        {
            system("cls");
            Zajecia zajecia;
            Harmonogram harmonogram;
            harmonogram.wczytajZPliku();
            char wybor;
            do {
                harmonogram.wczytajZPliku();
                cout << "\n==== MENU HARMONOGRAMU ====\n";
                cout << "1. Dodaj nowe zajęcia\n";
                cout << "2. Wyświetl harmonogram\n";
                cout << "0. Wyjście\n";
                cout << "Wybierz opcję: ";
                cin.ignore();
				wybor = getchar();

                switch (wybor) {
                case '1':
                {
                    system("cls");
                    harmonogram.dodajZajecia();
                    break;
                }
                case '2':
                {
                    system("cls");
                    harmonogram.wyswietlHarmonogram();
                    break;
                }
                default:
                {
                    cin.ignore();
                    system("cls");
                    cout << "Nieznana opcja! Spróbuj ponownie!" << endl;
                    break;
                }
                }
            } while (wybor != '0');
            system("cls");
            break;
        }

        case '6':
        {
            system("cls");
            cout << "Dziekujemy za skorzystanie z programu!" << endl;
            break;
        }
        default:
        {
            cin.ignore();
            cout << "Nieznana opcja! Spróbuj ponownie!" << endl;
            Sleep(2000);
            break;
        }
        }
    } while (opcja != '6');
    return 0;
}