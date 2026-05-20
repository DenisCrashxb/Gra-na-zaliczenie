#ifndef POSTAC_H
#define POSTAC_H

#include <string>

struct Statystyki
{
    int hp;
    int maxHp;
    int sila;
    int obrona;

    Statystyki(int hp = 100, int sila = 10, int obrona = 5);
};

class Postac
{
private:
    std::string nazwa;
    char znak;

    int x;
    int y;

public:
    Statystyki staty;

    Postac(std::string nazwa, char znak, int x, int y, Statystyki staty);

    int getX();
    int getY();

    void ustawPozycje(int nx, int ny);

    char getZnak();
    std::string getNazwa();

    void otrzymajObrazenia(int dmg);
    bool czyZyje();
};

#endif