#include <iostream>
#include "string5.h"
#include "adatkezelo.h"
#include "adatkezelo.cpp"
#include "jarmu.h"
#include "vizijarmu.hpp"
#include "foldijarmu.hpp"
#include "limits"
#include <fstream>
// Customm sleep function for Windows and Linux (source: stackoverflow- cross platform sleep in C, C++)
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000)
#endif

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

void filter(Adatkezelo<20> &all)
{
    cout << "---SZURESI LEHETOSEGEK---" << endl;
    int choice = 0;
    int numOfOptions = 4;
    cout << "1. Vizijarmu" << endl;
    cout << "2. Foldijarmu" << endl;
    cout << "3. Megnevezes alapjan" << endl;
    cout << "4. Vissza" << endl;

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
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    } while (!valid);

    // PRINTING
    switch (choice)
    {
    case 1:
        cout << "--Vizijarmuvek:--" << endl;
        all.filterJarmuvek("Vizijarmu");
        break;
    case 2:
        cout << "--Foldijarmuvek:--" << endl;
        all.filterJarmuvek("Foldijarmu");
        break;
    case 4:
        return;
    case 3:
        String filter;
        cout << "Kerem adja meg a jarmu megnevezeset: "; // BOVITES ID alapu kereseshez
        cin >> filter;
        all.searchJarmu(filter);
        break;
    }
}

int mainMenu()
{
    int choice = 0;
    int numOfOptions = 4;
    cout << "---JARMUKERESKEDES MENU---" << endl;
    cout << "1. Jarmu hozzaadasa" << endl;
    cout << "2. Jarmu torlese" << endl;
    cout << "3. Jarmuvek szurese" << endl;
    cout << "4. Minden jarmu megjelenitese" << endl;
    cout << "9. Kilepes" << endl;

    bool valid = false;

    do
    {
        cout << "Valasszon egy lehetoseget: ";
        cin >> choice;
        if (cin.good() && ((choice >= 1 && choice <= numOfOptions) || choice == 9))
        {
            valid = true;
        }
        else
        {
            cout << "Hibas valasztas! Probalja ujra!" << endl;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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

        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
                while (readLine(file, line)) // TODO.
                {
                    if (line.slice(line, ';')[7] == "-")
                        ker.addJarmu(new FoldiJarmu(line));
                    else
                        ker.addJarmu(new Vizijarmu(line));
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
        if (cin.good() && (toupper(load) == 'N'))
        {
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
    while (true)
    {
        int choice = mainMenu();
        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 3:
            filter(kereskedes);
            Sleep(500);
            break;
        case 4:
            kereskedes.printJarmuvek();
            break;
        case 9:
            cout << "Kilepes..." << endl;
            Sleep(500);
            return 0;
            break;
        default:
            cout << "Hibas valasztas! Probalja ujra!" << endl;
            break;
        }
    }
}
