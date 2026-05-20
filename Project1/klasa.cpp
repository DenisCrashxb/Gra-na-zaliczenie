#include "Klasa.h"
#include <iostream>

Gra::Gra()
    : gracz("Gracz", 'O', 1, 1, Statystyki(100, 15, 5))
{
    stworzMape();

    wrogowie.push_back(Postac("Goblin", 'x', 5, 5, Statystyki(40, 8, 2)));
    wrogowie.push_back(Postac("Slime", 'x', 7, 2, Statystyki(30, 5, 1)));

    dodajLog("Gra uruchomiona");
}

void Gra::stworzMape()
{
    mapa.resize(WYSOKOSC, std::vector<char>(SZEROKOSC, '.'));

    for (int y = 0; y < WYSOKOSC; y++)
    {
        for (int x = 0; x < SZEROKOSC; x++)
        {
            if (x == 0 || x == SZEROKOSC - 1 ||
                y == 0 || y == WYSOKOSC - 1)
            {
                mapa[y][x] = '#';
            }
        }
    }

    mapa[3][3] = '#';
    mapa[3][4] = '#';
    mapa[4][4] = '#';
}

void Gra::dodajLog(std::string tekst)
{
    logi.push_back(tekst);

    if (logi.size() > 5)
        logi.erase(logi.begin());
}

void Gra::wyswietlMape()
{
    system("cls");

    std::cout << "===     Mapa    ===\n\n";

    for (int y = 0; y < WYSOKOSC; y++)
    {
        // MAPA (LEWA STRONA)
        for (int x = 0; x < SZEROKOSC; x++)
        {
            bool rys = false;

            if (x == gracz.getX() && y == gracz.getY())
            {
                std::cout << gracz.getZnak() << ' ';
                rys = true;
            }
            else
            {
                for (auto& w : wrogowie)
                {
                    if (w.czyZyje() && x == w.getX() && y == w.getY())
                    {
                        std::cout << w.getZnak() << ' ';
                        rys = true;
                        break;
                    }
                }
            }

            if (!rys)
                std::cout << mapa[y][x] << ' ';
        }

        // PRAWY PANEL (HUD)
        if (y == 0)
            std::cout << "   === POSTAC ===";
        else if (y == 1)
            std::cout << "   HP: "
            << gracz.staty.hp
            << "/"
            << gracz.staty.maxHp;
        else if (y == 3)
            std::cout << "   Sila: " << gracz.staty.sila;
        else if (y == 4)
            std::cout << "   Obrona: " << gracz.staty.obrona;
        else if (y == 6)
            std::cout << "   === EKWIPUNEK ===";
        else if (y == 7)
            std::cout << "   (pusty)";
        else
            std::cout << "";

        std::cout << "\n";
    }

    // LOGI NA DOLE
    std::cout << "\n=== LOGI ===\n";
    for (auto& l : logi)
        std::cout << "- " << l << "\n";

    std::cout << "\nWASD - ruch \n";
}


void Gra::ruchGracza(char kierunek)
{
    int nx = gracz.getX();
    int ny = gracz.getY();

    switch (kierunek)
    {
    case 'w': ny--; break;
    case 's': ny++; break;
    case 'a': nx--; break;
    case 'd': nx++; break;
    default:
        dodajLog("Zla komenda");
        return;
    }

    // ŚCIANY
    if (mapa[ny][nx] == '#')
    {
        dodajLog("Sciana!");
        return;
    }

    // WROGOWIE
    for (auto& w : wrogowie)
    {
        if (w.czyZyje() && w.getX() == nx && w.getY() == ny)
        {
            dodajLog("Spotkano: " + w.getNazwa());
            return;
        }
    }

    // RUCH
    gracz.ustawPozycje(nx, ny);
    dodajLog("Ruch gracza");
}