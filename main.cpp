#include <iostream>
#include "string5.h"
#include "adatkezelo.h"
#include "adatkezelo.cpp"
#include "jarmu.h"
#include "vizijarmu.hpp"
#include "foldijarmu.hpp"
#include "limits"
#include <fstream>
#include <string>

using namespace std;

istream &readLine(istream &is, String &result)
{
    char ch;
    result = "";
    while (is.get(ch))
    {
        if (ch == '\n')
            continue;
        if (ch == '|')
            break;
        else
            result = result + ch;
    }
    return is;
}

int mainMenu()
{
    int choice = 0;
    int numOfOptions = 4;
    cout << "1. Jarmu hozzaadasa" << endl;
    cout << "2. Jarmu torlese" << endl;
    cout << "3. Minden jarmu megjelenitese" << endl;
    cout << "4. Kilepes" << endl;

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

Adatkezelo<20> init()
{
    cout << "---JARMUKERESKEDES---" << endl;
    char load;
    int valid = -1;
    Adatkezelo<20> ker;
    do
    {
        cout << "Szeretne betolteni foldi elmentett jarmuveit? [I]-Igen [N]-Nem: ";
        cin >> load;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail() || (toupper(load) != 'I' && toupper(load) != 'N'))
        {
            cin.clear();
            cout << "Hibas valasztas! Probalja ujra!" << endl;
            continue;
        }

        if (cin.good() && (toupper(load) == 'I'))
        {
            String filename;
            cout << "Kerem adja meg a betolteni kivant fajl nevet: ";
            cin >> filename;
            ifstream file(filename.c_str());
            if (file.is_open())
            {
                String line;
                while (readLine(file, line))
                {
                    ker.addJarmu(new FoldiJarmu(line));
                }
                valid = 1;
                std::cout << "Sikeresen betoltve! - " << filename.toUpper() << std::endl;
            }
            else
            {
                cout << "A fajl nem nyithato meg!" << endl;
                valid = -1;
            }
        }
        if (cin.good() && (toupper(load) == 'N')){
            valid = 0;
            cout << "Nem kerult betoltesre fajl!" << endl;
        }
    } while (valid < 0);
    return ker;
}

int main()
{
    // adatkezelo capacity kezdeti meretenek megadasa?
    Adatkezelo<20> kereskedes = init();

    int choice = mainMenu();
    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 3:
        kereskedes.printJarmuvek();
        break;
    case 4:
        cout << "Kilepes!" << endl;

    default:
        break;
    }
}
