#include <iostream>
#include "string5.h"
#include "adatkezelo.h"
#include "adatkezelo.cpp"
#include "jarmu.h"
#include "vizijarmu.hpp"
#include "foldijarmu.hpp"
#include "limits"

using namespace std;

int mainMenu()
{
    int choice = 0;
    int numOfOptions = 4;
    cout << "1. Jarmu hozzaadasa" << endl;
    cout << "2. Jarmu torlese" << endl;
    cout << "3. Minden jarmu megjelenitese" << endl;
    cout << "4. Kereskedes vege" << endl;

    bool valid = false;

    do
    {
        cout << "Valasszon egy lehetoseget: ";
        cin >> choice;
        if (cin.good() && choice >= 1 && choice <= numOfOptions)
        {
            valid = true;
        }
        else
        {
            cout << "Hibas valasztas! Probalja ujra!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!valid);

    return choice;
}

int main()
{
    int choice = mainMenu();
}
