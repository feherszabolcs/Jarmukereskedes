#ifndef ADATKEZELO_H
#define ADATKEZELO_H

#include "jarmu.h"
#include "string5.h"

template <size_t capacity = 20>
class Adatkezelo
{
private:
    Jarmu *jarmuvek[capacity];
    size_t jarmuvekSzama;

public:
    Adatkezelo()
    {
        jarmuvekSzama = 0;
        for (size_t i = 0; i < capacity; ++i)
            jarmuvek[i] = NULL;
    }

    size_t getJarmuvek();
    void printJarmuvek() const;
    void addJarmu(Jarmu *ujJarmu);
    void removeJarmu(int id);
    // szűrő fgv. paramok alapján
    void filterJarmuvek();
    bool toFile(const char *filename) const; // bool return value: sikeres-e a mentés
};
#endif