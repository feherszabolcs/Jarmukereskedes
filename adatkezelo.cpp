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
        jarmuvek[jarmuvekSzama++] = ujJarmu;
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
        }
    }
}