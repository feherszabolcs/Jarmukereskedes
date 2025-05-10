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
    int getId() const { return id; }
    String getMegnevezes() const { return megnevezes; }
    int getEv() const { return gyartasiEv; }
    String getSzin() const { return szin; }
    int getAr() const { return ar; }
    void setAr(int ar) { this->ar = ar; }
    int getTeljesitmeny() const { return teljesitmeny; }
    virtual void print() const
    {
        std::cout << "ID: " << id << "; ";
        std::cout << "Megnevezes: " << megnevezes << "; ";
        std::cout << "Gyartasi ev: " << gyartasiEv << "; ";
        std::cout << "Szin: " << szin << "; ";
        std::cout << "Ar: " << ar << "; ";
        std::cout << "Teljesitmeny: " << teljesitmeny << "; ";
    };
};
#endif