/**
 *
 * \file string5.cpp
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a stringkezelő függvényekre.
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream> // Kiíratáshoz
#include <cstring>  // Stringműveletekhez

#include "memtrace.h" // a standard headerek után kell lennie
#include "string5.h"

using std::cin;
using std::ios_base;

/// Konstruktor: egy char karakterből (createStrFromChar)
String::String(char ch)
{
    // Meghatározzuk a hosszát
    len = 1;
    // Lefoglalunk a helyet a hossznak + a lezaró nullának
    pData = new char[len + 1];
    // Betesszük a karaktert
    pData[0] = ch;
    pData[1] = '\0';
}

// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
String::String(const char *p)
{
    // Meghatározzuk a hosszát
    len = strlen(p);
    // Helyet foglalunk
    pData = new char[len + 1];
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(pData, p);
}

// Másoló konstruktor
String::String(const String &s1)
{
    // Meghatározzuk a hosszát
    len = s1.len;
    // Helyet foglalunk
    pData = new char[len + 1];
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(pData, s1.pData);
}

// operator=
String &String::operator=(const String &rhs_s)
{
    if (this != &rhs_s)
    {
        delete[] pData;
        len = rhs_s.len;
        // Helyet foglalunk
        pData = new char[len + 1];
        // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza.
// indexhiba esetén dobjon egy const char * típusú hibát!
char &String::operator[](unsigned int idx)
{
    if (idx >= len)
        throw "String: indexelesi hiba";
    return pData[idx];
}

const char &String::operator[](unsigned int idx) const
{
    if (idx >= len)
        throw "String: indexelesi hiba";
    return pData[idx];
}

bool String::operator==(const String &rhs_s) const
{
    if (len != rhs_s.len)
        return false;
    return (strcmp(pData, rhs_s.pData) == 0);
}

// + operátor, ami két stringet ad össze (concatString)
String String::operator+(const String &rhs_s) const
{
    String temp; // ide kerül az eredmény
    // Meghatározza az új string hosszát
    temp.len = len + rhs_s.len;
    // Felszabadítja a temp adattaerületét
    delete[] temp.pData;
    // lefoglalja a memóriát az új stringnek.
    temp.pData = new char[temp.len + 1];
    // Az elejére bemásolja az első stringet
    strcpy(temp.pData, pData);
    // Bemásolja a második stringet.
    strcat(temp.pData, rhs_s.pData);

    return temp; // visszatér az eredménnyel
}
// << operator, ami kiír az ostream-re
std::ostream &operator<<(std::ostream &os, const String &s0)
{
    os << s0.c_str();
    return os;
}

String *String::slice(String line, char sep)
{
    static String res[10];
    size_t j = 0;
    String temp = "";
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == sep)
        {
            res[j] = temp;
            j++;
            temp = "";
        }
        else
        {
            temp = temp + line[i];
        }
    }
    return res;
}

String String::toUpper() const
{
    String result = *this;
    for (size_t i = 0; i < len; i++)
    {
        if (islower(result[i]))
        {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

// << operátor, ami beolvas az istreamről egy szót
std::istream &operator>>(std::istream &is, String &s0)
{
    unsigned char ch;
    s0 = String("");                         // üres string, ehhez fűzünk hozzá
    std::ios_base::fmtflags fl = is.flags(); // eltesszük a régi flag-eket
    is.setf(ios_base::skipws);               // az elején eldobjuk a ws-t
    while (is >> ch)
    {
        is.unsetf(ios_base::skipws); // utána pedig már nem
        if (isspace(ch))
        {
            is.putback(ch); // na ezt nem kérjük
            break;
        }
        else
        {
            s0 = s0 + ch; // végére fűzzük a karaktert
        }
    }
    is.setf(fl); // visszaállítjuk a flag-eket
    return is;
}
