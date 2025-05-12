#ifndef ADATKEZELO_H
#define ADATKEZELO_H

#include "jarmu.h"
#include "string5.h"
#include <iostream>
#include <fstream>
#include <cstring>

template <size_t capacity = 20>
class Adatkezelo
{
private:
    Jarmu *jarmuvek[capacity];
    size_t jarmuvekSzama;

public:
    // Alap konstruktor
    Adatkezelo()
    {
        jarmuvekSzama = 0;
        for (size_t i = 0; i < capacity; ++i)
            jarmuvek[i] = NULL;
    }

    /// Jarmuvek szama
    ///@return: jarmuvek szama
    size_t getJarmuvek()
    {
        return this->jarmuvekSzama;
    }

    /// Jarmuvek kiiratasa
    void printJarmuvek() const
    {
        if (jarmuvekSzama == 0)
        {
            std::cout << "Nincs megjelenitheto jarmu!" << std::endl;
            return;
        }
        else
        {
            std::cout << "---Jarmuvek:--- (" << jarmuvekSzama << " db)" << std::endl;
        }
        for (size_t i = 0; i < capacity; i++)
        {
            if (jarmuvek[i] != nullptr)
            {
                jarmuvek[i]->print(std::cout, true);
            }
        }
    }

    /// Jarmu hozzaadasa, ha van meg hely
    ///@param jarmu: uj jarmu pointer
    void addJarmu(Jarmu *ujJarmu)
    {
        if (jarmuvekSzama > capacity)
        {
            throw "Nincs hely a kereskedesben uj jarmunek!";
        }
        if (ujJarmu != nullptr)
        {
            for (size_t i = 0; i < capacity; i++)
            {
                if (jarmuvek[i] == nullptr)
                {
                    jarmuvek[i] = ujJarmu;
                    jarmuvekSzama++;
                    break;
                }
            }
        }

        else
            throw "Hiba tortent!";
    }

    /// Jarmu torlese
    ///@param id: torolni kivant jarmu id-je
    ///@return: sikeres-e a torles
    bool removeJarmu(int id)
    {
        for (size_t i = 0; i < capacity; i++)
        {
            if (jarmuvek[i] != nullptr && (jarmuvek[i])->getId() == id)
            {
                delete jarmuvek[i];
                jarmuvek[i] = nullptr;
                jarmuvekSzama--;
                return true;
            }
        }
        return false;
    }

    /// Jarmuvek szurt kiirasa a cout-ra
    ///@param filter: szurt jarmuvek tipusa
    void filterJarmuvek(String filter)
    {
        for (size_t i = 0; i < capacity; i++)
        {
            if (jarmuvek[i] != nullptr)
            {
                if (jarmuvek[i]->GetType() == filter)
                {
                    jarmuvek[i]->print(std::cout, true) << std::endl;
                }
            }
        }
    }

    /// Jarmu keresese megnevezes mezo alapjan
    ///@param filter: keresett jarmu neve
    void searchJarmu(String filter)
    {
        for (size_t i = 0; i < capacity; i++)
        {
            if (jarmuvek[i] != nullptr)
            {
                if (strstr(jarmuvek[i]->getMegnevezes().c_str(), filter.c_str()) != NULL)
                {
                    jarmuvek[i]->print(std::cout, true);
                    std::cout << std::endl;
                }
            }
        }
    }

    /// Jarmuvek kiirasa egy fajlba (ha nem letezo fajl, letrehozza)
    ///@param filename: fajl neve
    ///@return: sikeres-e a kiiras
    bool toFile(const char *filename) const
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            return false;
        }
        for (size_t i = 0; i < capacity; i++)
        {
            if (jarmuvek[i] != nullptr)
            {
                jarmuvek[i]->print(file, false) << std::endl;
            }
        }
        file.close();
        return true;
    }

    /// Destruktor, ha van jarmu, akkor torli, felszabaditja
    ~Adatkezelo()
    {
        for (size_t i = 0; i < capacity; ++i)
            delete jarmuvek[i];
    }
};
#endif