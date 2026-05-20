#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "Postac.h"

class Gra
{
private:
    static const int SZEROKOSC = 10;
    static const int WYSOKOSC = 10;

    std::vector<std::vector<char>> mapa;
    std::vector<std::string> logi;

    Postac gracz;
    std::vector<Postac> wrogowie;

    void stworzMape();

public:
    Gra();

    void wyswietlMape();
    void ruchGracza(char kierunek);

    void dodajLog(std::string tekst);
};

