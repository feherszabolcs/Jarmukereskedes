#include <iostream>
#include "string5.h"
#include "adatkezelo.h"
#include "adatkezelo.cpp"
#include "jarmu.h"
#include "vizijarmu.hpp"
#include "foldijarmu.hpp"

int mainMenu()
{
    int choice = 0;
    int numOfOptions = 4;
    std::cout << "Valasszon egy lehetoseget: ";
    std::cout << "1. Jarmu hozzaadasa" << std::endl;
    std::cout << "2. Jarmu torlese" << std::endl;
    std::cout << "3. Jarmu megjelenitese" << std::endl;
    std::cout << "4. Kereskedes vege" << std::endl;
    while (choice < 1 || choice > numOfOptions)
    {
        std::cin >> choice;
        if (choice < 1 || choice > numOfOptions)
            std::cout << "Nem jo valasztas!" << std::endl;
        else
            break;
    }
    return choice;
}

int main()
{
    int choice = mainMenu();
}
