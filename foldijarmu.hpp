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
    FoldiJarmu(int id, String megnevezes, int gyartasiEv, String szin, int ar, double teljesitmeny, String rendszam, int ajtokSzama, int uzemanyagFogyasztas) : Jarmu(id, megnevezes, gyartasiEv, szin, ar, teljesitmeny), rendszam(rendszam), ajtokSzama(ajtokSzama), uzemanyagFogyasztas(uzemanyagFogyasztas) {}
    FoldiJarmu(const FoldiJarmu &foldijarmu) : Jarmu(foldijarmu), rendszam(foldijarmu.rendszam), ajtokSzama(foldijarmu.ajtokSzama), uzemanyagFogyasztas(foldijarmu.uzemanyagFogyasztas) {}
    FoldiJarmu(String line) : Jarmu(line)
    {
        String *temp = line.slice(line, ';');
        this->rendszam = temp[6];
        this->ajtokSzama = atoi(temp[8].c_str());
        this->uzemanyagFogyasztas = atoi(temp[9].c_str());
    }
    String getRendszam() const { return rendszam; }
    int getAjtokSzama() const { return ajtokSzama; }
    int getUzemanyagFogyasztas() const { return uzemanyagFogyasztas; }
    void print() const override
    {
        Jarmu::print();
        std::cout << "Rendszam: " << rendszam << "; ";
        std::cout << "Ajtok szama: " << ajtokSzama << "; ";
        std::cout << "Uzemanyag fogyasztas: " << uzemanyagFogyasztas << " l/100km " << std::endl;
    }
    String GetType() override
    {
        return "Foldijarmu";
    }
};
#endif