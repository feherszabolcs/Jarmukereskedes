#ifndef FOLDIJARMU_HPP
#define FOLDIJARMU_HPP
#include "jarmu.h"
#include "string5.h"

class FoldiJarmu : public Jarmu
{
private:
    String rendszam;
    int ajtokSzama;
    int uzemanyagFogyasztas; // liter/100km
public:
    /// Konstruktor mezonkent
    FoldiJarmu(int id, String megnevezes, int gyartasiEv, String szin, int ar, double teljesitmeny, String rendszam, int ajtokSzama, int uzemanyagFogyasztas) : Jarmu(id, megnevezes, gyartasiEv, szin, ar, teljesitmeny), rendszam(rendszam), ajtokSzama(ajtokSzama), uzemanyagFogyasztas(uzemanyagFogyasztas) {}

    /// Masolo konstruktor
    FoldiJarmu(const FoldiJarmu &foldijarmu) : Jarmu(foldijarmu), rendszam(foldijarmu.rendszam), ajtokSzama(foldijarmu.ajtokSzama), uzemanyagFogyasztas(foldijarmu.uzemanyagFogyasztas) {}

    /// Konstruktor a fajl egy sorahoz
    ///@param line: sor ami a fajlbol kerult be
    FoldiJarmu(String line) : Jarmu(line)
    {
        String *temp = line.slice(line, ';');
        this->rendszam = temp[6];
        this->ajtokSzama = atoi(temp[8].c_str());
        this->uzemanyagFogyasztas = atoi(temp[9].c_str());
    }

    /// Rendszam getter
    String getRendszam() const { return rendszam; }

    /// Ajtokszama getter
    int getAjtokSzama() const { return ajtokSzama; }

    /// Uzemanyagfogyasztas getter
    int getUzemanyagFogyasztas() const { return uzemanyagFogyasztas; }

    /// Jarmu kiiratasa
    ///@param os: stream amire kiirjuk
    ///@param formating: true ha formazott kiiras, false ha nem (ez a fajlba irashoz kell)
    std::ostream &print(std::ostream &os, bool formating) const override
    {
        Jarmu::print(os, formating);
        if (formating)
            os << "Rendszam: " << rendszam << "; "
               << "Ajtok szama: " << ajtokSzama << "; "
               << "Uzemanyag fogyasztas: " << uzemanyagFogyasztas << " l/100km;" << std::endl;
        else
            os << rendszam << ";-;" << ajtokSzama << ";" << uzemanyagFogyasztas << ";" << "|";
        return os;
    }

    /// Jarmu tipusa (szureshez)
    String GetType() override
    {
        return "Foldijarmu";
    }
};
#endif