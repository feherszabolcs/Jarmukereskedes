#include "gtest_lite.h"
#include "adatkezelo.hpp"
#include "jarmu.h"
#include "foldijarmu.hpp"
#include "vizijarmu.hpp"
#include "string5.h"
#include <iostream>
#include <fstream>

int test_main()
{
    TEST(Peldanyositas, Jarmupeldany)
    {
        EXPECT_NO_THROW(FoldiJarmu fj1(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10)) << "Hibas ctor!";
        EXPECT_THROW(FoldiJarmu fj2(1, "Audi A3", -1930, "piros", 3800, -0.2, "ABC-123", 4, 10), const char *) << "Hibas ctor adatellenőrzés!";
        EXPECT_NO_THROW(Vizijarmu vj1(3, "Hajocska", 2020, "kek", 9800, 150, "kishajo")) << "Hibas ctor!";
        EXPECT_THROW(Vizijarmu vj2(2, "Hajocska", -2020, "kek", 9800, -150, "kishajo"), const char *) << "Hibas ctor adatellenőrzés!";
    }
    END;
    TEST(Alap_Funkciok, Adatkezelo)
    {
        Adatkezelo<10> adatkezelo;
        EXPECT_NO_THROW(adatkezelo.addJarmu(new FoldiJarmu(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10))) << "Hibas ctor!";
        EXPECT_EQ(1, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        EXPECT_NO_THROW(adatkezelo.addJarmu(new FoldiJarmu(1, "Audi A4", 2012, "feher", 5300, 230, "DBE-322", 4, 11))) << "Hibas ctor!";
        EXPECT_EQ(2, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        EXPECT_NO_THROW(adatkezelo.removeJarmu(1)) << "Hibas torles!";
        EXPECT_EQ(1, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
    }
    END;
    TEST(filehandling, JarmuPeldanyok)
    {

        Adatkezelo<20> adatkezelo;
        EXPECT_EQ(0, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        adatkezelo.addJarmu(new FoldiJarmu(1, "Audi A4", 2012, "feher", 5300, 230, "DBE-322", 4, 11));
        EXPECT_EQ(true, adatkezelo.toFile("test_print.csv"));
        EXPECT_NO_THROW(std::ifstream file("test_print.csv")); // letrejott a fajl
    }
    END;
}