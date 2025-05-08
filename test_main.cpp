#include "gtest_lite.h"
#include "adatkezelo.h"
#include "jarmu.h"
#include "foldijarmu.hpp"

void test_main()
{
    TEST(Peldanyositas, Jarmupeldany)
    {
        EXPECT_NO_THROW(FoldiJarmu fj1(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10)) << "Hibas ctor!";
        EXPECT_THROW(FoldiJarmu fj2(1, "Audi A3", -1930, "piros", 3800, -0.2, "ABC-123", 4, 10), const char *) << "Hibas ctor adatellenőrzés!";
    }
    END;
    TEST(Peldanyositas, Adatkezelo)
    {
        Adatkezelo<10> adatkezelo;
        // EXPECT_NO_THROW(adatkezelo.addJarmu(new FoldiJarmu(0, "Audi A3", 2010, "piros", 3800, 200, "ABC-123", 4, 10))) << "Hibas ctor!";
        // EXPECT_EQ(1, adatkezelo.getJarmuvek()) << "Hibas jarmu szam!";
        // EXPECT_EQ(0, adatkezelo2.getJarmuvek()) << "Hibas jarmu szam!";
    }
    END;

    // Teszt a hozzáadásra, törlésre, printre
}