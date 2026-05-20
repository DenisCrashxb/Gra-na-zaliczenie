#include "Postac.h"

Statystyki::Statystyki(int hp, int sila, int obrona)
{
    this->hp = hp;
    this->maxHp = hp;
    this->sila = sila;
    this->obrona = obrona;
}

Postac::Postac(std::string nazwa, char znak, int x, int y, Statystyki staty)
{
    this->nazwa = nazwa;
    this->znak = znak;

    this->x = x;
    this->y = y;

    this->staty = staty;
}

int Postac::getX() { return x; }
int Postac::getY() { return y; }

void Postac::ustawPozycje(int nx, int ny)
{
    x = nx;
    y = ny;
}

char Postac::getZnak() { return znak; }
std::string Postac::getNazwa() { return nazwa; }

void Postac::otrzymajObrazenia(int dmg)
{
    int real = dmg - staty.obrona;
    if (real < 0) real = 0;

    staty.hp -= real;
    if (staty.hp < 0) staty.hp = 0;
}

bool Postac::czyZyje()
{
    return staty.hp > 0;
}