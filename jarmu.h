#ifndef JARMU_H
#define JARMU_H
#include "string5.h"
#include "memtrace.h"

class Jarmu
{
private:
    int id;
    String megnevezes;
    int gyartasiEv; // nem lehet < 0
    String szin;
    int ar;              // nem lehet < 0
    double teljesitmeny; // nem lehet < 0

public:
    /// Alap konstruktor
    Jarmu(int id, String megnevezes, int gyartasiEv, String szin, int ar, double teljesitmeny)
    {
        if (id < 0)
            throw "Hibas ID!";
        if (gyartasiEv < 0)
            throw "Hibas GYARTASIEV!";
        if (ar < 0)
            throw "Hibas AR!";
        if (teljesitmeny < 0)
            throw "Hibas TELJESITMENY!";
        this->id = id;
        this->megnevezes = megnevezes;
        this->gyartasiEv = gyartasiEv;
        this->szin = szin;
        this->ar = ar;
        this->teljesitmeny = teljesitmeny;
    }

    /// Sort feldolgozo konstruktor
    Jarmu(String line)
    {
        String *temp = line.slice(line, ';');
        this->id = atoi(temp[0].c_str());
        this->megnevezes = temp[1];
        this->gyartasiEv = atoi(temp[2].c_str());
        this->szin = temp[3];
        this->ar = atoi(temp[5].c_str());
        this->teljesitmeny = atof(temp[4].c_str());
    };

    /// Id getter
    int getId() const { return id; }

    /// Megnevezes getter
    String getMegnevezes() const { return megnevezes; }

    /// Gyartasi ev getter
    int getEv() const { return gyartasiEv; }

    /// Szin getter
    String getSzin() const { return szin; }

    /// Ar getter
    int getAr() const { return ar; }

    /// Teljesitmeny getter
    int getTeljesitmeny() const { return teljesitmeny; }

    /// Jarmu kiiratasa virtualis fuggveny
    virtual std::ostream &print(std::ostream &os, bool formating) const
    {
        if (formating)
        {
            os << "ID: " << id << "; "
               << "Megnevezes: " << megnevezes << "; "
               << "Gyartasi ev: " << gyartasiEv << "; "
               << "Szin: " << szin << "; "
               << "Ar: " << ar << " ezer Ft; "
               << "Teljesitmeny: " << teljesitmeny << " kW; ";
        }
        else
            os << id << ";" << megnevezes << ";" << gyartasiEv << ";" << szin << ";" << ar << ";" << teljesitmeny << ";";
        return os;
    };

    /// Jarmu tipusa (szureshez)
    virtual String GetType() = 0; // Pure virtual function

    /// Virtualis destruktor
    virtual ~Jarmu() {}
};
#endif