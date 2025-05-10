#include "string5.h"
#include "iostream"

#include "adatkezelo.h"
#include "jarmu.h"

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
            jarmuvek[i]->print();
        }
    }
}