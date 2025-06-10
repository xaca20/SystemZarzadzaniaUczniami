#include "klasy.h"

int main()
{
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
        cout << "  5. Wprowadz dane przedmiotu" << endl;
        cout << "  6. Modyfikuj dane przedmiotu" << endl;
        cout << "  7. Wprowadz dane platnosci" << endl;
        cout << "  8. Wyświetl harmonogram zajęć" << endl;
        cout << "  9. Wyjscie" << endl;
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
            Harmonogram h1;
            h1.podajHarmonogram();
            h1.wyswietl();
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
        case 8:
        {
            system("cls");
            cout << "Dziekujemy za skorzystanie z programu!" << endl;
            break;
        }
        case 9:
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
    } while (opcja != 9);
    return 0;
}