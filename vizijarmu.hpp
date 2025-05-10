#ifndef VIZIJARMU_HPP
#define VIZIJARMU_HPP
#include "jarmu.h"
#include "string5.h"

class Vizijarmu : public Jarmu
{
private:
    String besorolas; // pl. vitorlás, motorcsónak, kishajó stb.
public:
    Vizijarmu(int id, String megnevezes, int gyartasiEv, String szin, int ar, double teljesitmeny, String besorolas) : Jarmu(id, megnevezes, gyartasiEv, szin, ar, teljesitmeny), besorolas(besorolas) {}
    Vizijarmu(const Vizijarmu &vizijarmu) : Jarmu(vizijarmu), besorolas(vizijarmu.besorolas) {}
    Vizijarmu(String line) : Jarmu(line)
    {
        String *temp = line.slice(line, ';');
        this->besorolas = temp[7];
    }
    String getBesorolas() const { return besorolas; }
    void print() const
    {
        Jarmu::print();
        std::cout << "Besorolas: " << besorolas << "; ";
    }
};
#endif