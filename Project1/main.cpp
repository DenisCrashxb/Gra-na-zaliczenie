
#include "Klasa.h"

int main()
{
    Gra gra;
    char cmd;

    while (true)
    {
        gra.wyswietlMape();

        std::cout << "\nRuch: ";
        std::cin >> cmd;

        cmd = tolower(cmd);

      

        gra.ruchGracza(cmd);
    }

    return 0;
}