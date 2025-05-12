#ifndef VIZIJARMU_HPP
#define VIZIJARMU_HPP
#include "jarmu.h"
#include "string5.h"

class Vizijarmu : public Jarmu
{
private:
    String besorolas; // pl. vitorlás, motorcsónak, kishajó stb.
public:
    /// Konstruktor mezonkent
    Vizijarmu(int id, String megnevezes, int gyartasiEv, String szin, int ar, double teljesitmeny, String besorolas) : Jarmu(id, megnevezes, gyartasiEv, szin, ar, teljesitmeny), besorolas(besorolas) {}

    /// Masolo konstruktor
    Vizijarmu(const Vizijarmu &vizijarmu) : Jarmu(vizijarmu), besorolas(vizijarmu.besorolas) {}

    /// Konstruktor a fajl egy sorahoz
    ///@param line: sor ami a fajlbol kerult be
    Vizijarmu(String line) : Jarmu(line)
    {
        String *temp = line.slice(line, ';');
        this->besorolas = temp[7];
    }

    /// Besorolas getter
    String getBesorolas() const { return besorolas; }

    /// Jarmu kiiratasa
    ///@param os: stream amire kiirjuk
    ///@param formating: true ha formazott kiiras, false ha nem (ez a fajlba irashoz kell)
    std::ostream &print(std::ostream &os, bool formating) const
    {
        Jarmu::print(os, formating);
        if (formating)
            os << "Besorolas: " << besorolas << ";" << std::endl;
        else
            os << "-;" << besorolas << ";" << "-;-;" << "|";
        return os;
    }

    /// Jarmu tipusa (szureshez)
    String GetType() override
    {
        return "Vizijarmu";
    }
};
#endif