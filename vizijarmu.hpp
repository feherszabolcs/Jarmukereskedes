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
    String getBesorolas() const { return besorolas; }
};
#endif