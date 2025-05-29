#include "klasy.h"

int main()
{
    cout << "===========================" << endl;
    cout << "System zarzadzania uczniami" << endl;
    cout << "===========================" << endl;
    cout << "Wybierz opcje:" << endl;
    cout << "1. Wprowadz dane ucznia" << endl;
    cout << "2. Wprowadz dane nauczyciela" << endl;
    cout << "3. Wprowadz dane przedmiotu" << endl;
    cout << "4. Wprowadz dane platnosci" << endl;
    cout << "5. Wprowadz dane harmonogramu" << endl;
    char opcja = 0;
    cin >> opcja;
    switch (opcja)
    {
    case '1':
    {
        Uczen u1("Maciek", "Kowalski", "3B", "rozszerzony", "dzienny");
        //u1.podajDane();
        u1.wyswietl();
        break;
    }
    case '2':
    {
        Nauczyciel n1("Miroslaw", "Zelent", "Informatyka", 35);
        //n1.podajDane();
        n1.wyswietl();
        break;
    }
    case '3':
    {
        Przedmiot p1;
        p1.podajDane();
        p1.wyswietl();
        break;
    }
    case '4':
    {
        Platnosc plat1;
        plat1.podajDane();
        plat1.wyswietl();
        break;
    }
    case '5':
    {
        Harmonogram h1;
        h1.podajHarmonogram();
        h1.wyswietl();
        break;
    }
    default:
    {
        cout << "Nieznana opcja!" << endl;
        break;
    }
    }
    return 0;
}