#include <iostream>
#include "string5.h"
#include "adatkezelo.hpp"
#include "jarmu.h"
#include "vizijarmu.hpp"
#include "foldijarmu.hpp"
#include "limits"
#include <fstream>
#include "memtrace.h"
// Customm sleep function for Windows and Linux (source: stackoverflow- cross platform sleep in C, C++)
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000)
#endif

using namespace std;

bool isValidNumber(String &in)
{
    if (atoi(in.c_str()) <= 0)
        return false;
    return true;
}

/// Sor olvasasa a fajlbol
///@param is: bemeneti streame
///@param result: beolvasott String
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

/// Jarmuvek szureset kezelo fgv.
///@param all: jarmuvek adatait tartalmazo adatkezelo objektum
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

/// Fomenut megjelenito fgv.
///@return: a valasztott menupont szama
int mainMenu()
{
    String choice;
    int numOfOptions = 5;
    cout << "---JARMUKERESKEDES MENU---" << endl;
    cout << "1. Jarmu hozzaadasa" << endl;
    cout << "2. Jarmu torlese" << endl;
    cout << "3. Jarmuvek szurese" << endl;
    cout << "4. Minden jarmu megjelenitese" << endl;
    cout << "5. Kereskedesi adatok mentese" << endl;
    cout << "9. Kilepes" << endl;

    bool valid = false;

    do
    {
        cout << "Valasszon egy lehetoseget: ";
        cin >> choice;
        if (isValidNumber(choice) == true && ((atoi(choice.c_str()) >= 1 && atoi(choice.c_str()) <= numOfOptions) || atoi(choice.c_str()) == 9))
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

    return atoi(choice.c_str());
}

/// Az adatkezelo objektumot inicializalo fgv.
/// Szukseg eseten a fajlbol olvas kezdeti allapothoz
///@return: az adatkezelo objektum
Adatkezelo<20> init()
{
    cout << "---JARMUKERESKEDES---" << endl;
    char load;
    int valid = -1;
    Adatkezelo<20> ker;
    do
    {
        cout << "Szeretne betolteni elmentett jarmuveit? [I]-Igen [N]-Nem: ";
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
                while (readLine(file, line))
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
/// Segedfuggveny, sablon a jarmu felvetelehez
void insertHelper(String &id, String &megnev, String &gyartEV, String &szin, String &ar, String &telj)
{
    bool valid_actual = false;
    do
    {
        cout << "[ID] = ";
        cin >> id;
        if ((isValidNumber(id) == false))
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Hibas ID! Probalja ujra!" << endl;
        }
        else
            valid_actual = true;
    } while (!valid_actual);

    cout << "[Megnevezes] = ";
    cin >> megnev;
    valid_actual = false;
    do
    {
        cout << "[Gyartasi ev] = ";
        cin >> gyartEV;
        if (isValidNumber(gyartEV) == false || atoi(gyartEV.c_str()) > 2022)
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Hibas gyartasi ev! Probalja ujra!" << endl;
        }
        else
            valid_actual = true;
    } while (!valid_actual);
    cout << "[Szin] = ";
    cin >> szin;
    valid_actual = false;

    do
    {
        cout << "[Ar] = ";
        cin >> ar;
        if (isValidNumber(ar) == false)
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Hibas ar! Probalja ujra!" << endl;
        }
        else
            valid_actual = true;
    } while (!valid_actual);
    valid_actual = false;

    do
    {
        cout << "[Teljesitmeny] = ";
        cin >> telj;
        if (isValidNumber(telj) == false)
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Hibas teljesitmeny! Probalja ujra!" << endl;
        }
        else
            valid_actual = true;
    } while (!valid_actual);
    valid_actual = false;
}

/// Foldijarmu felvetele
///@return: a felvetelt jarmu adatait tartalmazo jarmu objektum
FoldiJarmu insertFDialog()
{
    String id, gyartEV, ar, telj, ajtok, uzema;
    String megnev, szin, rendszam;
    cout << "--- UJ FOLDI JARMU---" << endl;
    insertHelper(id, megnev, gyartEV, szin, ar, telj);
    cout << "[Rendszam] = ";
    cin >> rendszam;
    do
    {
        cout << "[Ajtok szama] = ";
        cin >> ajtok;
    } while (isValidNumber(ajtok) == false);
    do
    {
        cout << "[Uzemanyag fogyasztas] = ";
        cin >> uzema;
    } while (isValidNumber(uzema) == false);
    FoldiJarmu jarmu(atoi(id.c_str()), megnev, atoi(gyartEV.c_str()), szin, atoi(ar.c_str()), atoi(telj.c_str()), rendszam, atoi(ajtok.c_str()), atoi(uzema.c_str()));
    return jarmu;
}

/// Vizijarmu felvetele
///@return: a felvetelt jarmu adatait tartalmazo jarmu objektum
Vizijarmu insertVDialog()
{
    String id, gyartEV, ar, telj;
    String megnev, szin, besorol;
    cout << "--- UJ VIZIJARMU---" << endl;
    insertHelper(id, megnev, gyartEV, szin, ar, telj);
    cout << "[Besorolas] = ";
    cin >> besorol;
    Vizijarmu jarmu(atoi(id.c_str()), megnev, atoi(gyartEV.c_str()), szin, atoi(ar.c_str()), atoi(telj.c_str()), besorol);
    return jarmu;
}

/// Jarmu felvetelet kezelo menu
///@param all: a jarmuvek adatait tarolo objektum
void newJarmuDialog(Adatkezelo<20> &all)
{
    int choice = 0;
    int numOfOptions = 2;
    cout << "---UJ JARMU FELVETELE---" << endl;
    cout << "1. Foldi jarmu" << endl;
    cout << "2. Vizi jarmu" << endl;
    cout << "8. Vissza" << endl;

    bool valid = false;
    do
    {
        cout << "Valasszon egy lehetoseget: ";
        cin >> choice;
        if (cin.good() && ((choice >= 1 && choice <= numOfOptions) || choice == 8))
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

    switch (choice)
    {
    case 1:
        all.addJarmu(new FoldiJarmu(insertFDialog()));
        break;
    case 2:
        all.addJarmu(new Vizijarmu(insertVDialog()));
        break;
    case 8:
        return;
    default:
        break;
    }
}

/// Jarmu torleset kezelo menu
///@param all: a jarmuvek adatait tarolo objektum
void removeDialog(Adatkezelo<20> &all)
{
    int id;
    cout << "Kerem adja meg a torolni kivant jarmu ID-jat: ";
    cin >> id;
    if (all.removeJarmu(id) == true)
    {
        cout << "Sikeresen torolve (ID = " << id << ")!" << endl;
        return;
    }
    cout << "Nem sikerult torolni (ID = " << id << ")!" << endl;
}

/// A program fomenuje, minden felhasznaloi input kezelese
///@return 0, ha a program bezarasara kerult
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
            newJarmuDialog(kereskedes);
            Sleep(500);
            break;
        case 2:
            removeDialog(kereskedes);
            Sleep(500);
            break;
        case 3:
            filter(kereskedes);
            Sleep(500);
            break;
        case 4:
            kereskedes.printJarmuvek();
            Sleep(500);
            break;
        case 9:
            cout << "Kilepes..." << endl;
            Sleep(500);
            return 0;
            break;
        case 5:
        {
            cout << "Kerem adja meg a menteni kivant fajl nevet: ";
            String filename;
            cin >> filename;
            if (kereskedes.toFile(filename.c_str()))
                cout << "Sikeresen elmentve! - " << filename.toUpper() << endl;
            else
                cout << "Nem sikerult elmenteni!" << endl;
            Sleep(500);
            break;
        }
        default:
            cout << "Hibas valasztas! Probalja ujra!" << endl;
            break;
        }
    }
}
