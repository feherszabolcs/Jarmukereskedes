#include "string5.h"
#include "iostream"

#include "adatkezelo.h"
#include "jarmu.h"
#include <cstring>
#include <fstream>

template <size_t capacity>
size_t Adatkezelo<capacity>::getJarmuvek()
{
    return this->jarmuvekSzama;
}
template <size_t capacity>
void Adatkezelo<capacity>::addJarmu(Jarmu *ujJarmu)
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
template <size_t capacity>
void Adatkezelo<capacity>::removeJarmu(int id)
{
    for (size_t i = 0; i < jarmuvekSzama; i++)
    {
        if ((jarmuvek[i])->getId() == id)
        {
            jarmuvek[i] = nullptr;
            jarmuvekSzama--;
            break;
        }
    }
}
template <size_t capacity>
void Adatkezelo<capacity>::printJarmuvek() const
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
    for (size_t i = 0; i < jarmuvekSzama; i++)
    {
        if (jarmuvek[i] != nullptr)
        {
            jarmuvek[i]->print(std::cout, true);
        }
    }
}
template <size_t capacity>
void Adatkezelo<capacity>::filterJarmuvek(String filter)
{
    for (size_t i = 0; i < jarmuvekSzama; i++)
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
template <size_t capacity>
void Adatkezelo<capacity>::searchJarmu(String filter)
{
    for (size_t i = 0; i < jarmuvekSzama; i++)
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
template <size_t capacity>
bool Adatkezelo<capacity>::toFile(const char *filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        return false;
    }
    for (size_t i = 0; i < jarmuvekSzama; i++)
    {
        if (jarmuvek[i] != nullptr)
        {
            jarmuvek[i]->print(file, false) << std::endl;
        }
    }
    file.close();
    return true;
}