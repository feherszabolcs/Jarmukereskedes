#include "gtest_lite.h"
#include "adatkezelo.hpp"
#include "jarmu.h"
#include "foldijarmu.hpp"
#include "vizijarmu.hpp"
#include "string5.h"
#include <iostream>
#include <fstream>
#include "memtrace.h"

void test_main()
{
    TEST(Peldanyositas, Jarmupeldany)
    {
        Vizijarmu vj1(3, "Hajocska", 2020, "kek", 9800, 150, "kishajo");
        EXPECT_NO_THROW(FoldiJarmu fj1(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10))
            << "Hibas ctor!";
        EXPECT_THROW(FoldiJarmu fj2(1, "Audi A3", -1930, "piros", 3800, -0.2, "ABC-123", 4, 10), const char *) << "Hibas ctor adatellenőrzés!";
        EXPECT_NO_THROW() << "Hibas ctor!";
        EXPECT_THROW(Vizijarmu vj2(2, "Hajocska", -2020, "kek", 9800, -150, "kishajo"), const char *) << "Hibas ctor adatellenőrzés!";
        EXPECT_NO_THROW(Vizijarmu vj3("5;Hajocska;2010;zold;88200;280;-;kishajo;-;-;"));
        EXPECT_NO_THROW(FoldiJarmu fj3("4;Mercedes;2003;barna;3800;103;LDA-404;-;4;7;"));
        EXPECT_NO_THROW(vj1.print(std::cout, true)) << "Hibas kiiras!";
        EXPECT_NO_THROW(vj1.print(std::cout, false)) << "Hibas kiiras!";
        EXPECT_STREQ("Hajocska", vj1.getMegnevezes().c_str()) << "Hibas megnevezes!";
        EXPECT_EQ(2020, vj1.getEv()) << "Hibas gyartasi ev!";
        EXPECT_STREQ("Vizijarmu", vj1.GetType().c_str()) << "Hibas tipus!";
    }
    END;
    TEST(Alap_Funkciok, Adatkezelo)
    {
        Adatkezelo<10> adatkezelo;
        EXPECT_NO_THROW(adatkezelo.searchJarmu("Audi")) << "Hibas kereses!";
        EXPECT_NO_THROW(adatkezelo.filterJarmuvek("Foldijarmu")) << "Hibas szures!";
        EXPECT_NO_THROW(adatkezelo.addJarmu(new FoldiJarmu(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10))) << "Hibas ctor!";
        EXPECT_EQ(1, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        EXPECT_NO_THROW(adatkezelo.addJarmu(new FoldiJarmu(1, "Audi A4", 2012, "feher", 5300, 230, "DBE-322", 4, 11))) << "Hibas ctor!";
        EXPECT_EQ(2, (int)adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        EXPECT_NO_THROW(adatkezelo.printJarmuvek()) << "Hibas kiiras!" << std::endl;
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