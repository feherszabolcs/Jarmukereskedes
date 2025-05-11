#ifndef JARMU_H
#define JARMU_H
#include "string5.h"

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
    int getId() const { return id; }
    String getMegnevezes() const { return megnevezes; }
    int getEv() const { return gyartasiEv; }
    String getSzin() const { return szin; }
    int getAr() const { return ar; }
    void setAr(int ar) { this->ar = ar; }
    int getTeljesitmeny() const { return teljesitmeny; }
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
    virtual String GetType() = 0; // Pure virtual function
    virtual ~Jarmu() {}
};
#endif