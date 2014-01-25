/*
    gracz.cpp
*/

#include "gracz.h"



gracz::gracz()                                  /// Konstruktor gracza
{
    pozycja = 0;
    punktacja = 0;
}

gracz::gracz (int poz)                          /// Konstruktor gracza z argumentem pozycji gracza
{
    pozycja = poz;
    punktacja = 0;
}

int gracz::dajpunktacje ()                      /// Podanie punktacji do funkcji wypisujacej
{
    return punktacja;
}

void gracz::zbierz (plansza & level)            /// Zbieranie punktow
{
    punktacja += 10;

    level.plan[pozycja].zawartosc = 0;            /// wymazanie wartosci z pola.

}

void gracz::dogory (plansza & level)
{

    if (pozycja >= 10 && level.plan[pozycja-10].typ == 1)
    {
        pozycja = pozycja - 10;
        level.pozycjagracza = level.pozycjagracza - 10;

        if (level.plan[pozycja].zawartosc == 1)
        {
            zbierz (level);
        }
        /// wykonywanie ruchu do gory !!!
    }
    else
    {
        printw ("\nNie mozesz sie teraz poruszyc do gory !!!\n");
        return;
    }
}

void gracz::wprawo (plansza & level)
{
    if ((pozycja%10) != 9 && level.plan[pozycja+1].typ == 1)
    {
        pozycja = pozycja + 1;
        level.pozycjagracza = level.pozycjagracza + 1;

        if (level.plan[pozycja].zawartosc == 1)
        {
            zbierz (level);
        }
    }
    else
    {
        printw ("\nNie mozesz sie teraz poruszyc w prawo !!!\n");
        return;
    }

}

void gracz::dodolu (plansza & level)
{
    if (pozycja < 90 && level.plan[pozycja+10].typ == 1)
    {
        pozycja = pozycja + 10;
        level.pozycjagracza = level.pozycjagracza + 10;

        if (level.plan[pozycja].zawartosc == 1)
        {
            zbierz (level);
        }
    }
    else
    {
        printw ("\nNie mozesz sie teraz poruszyc do dolu\n");
        return;
    }

}

void gracz::wlewo (plansza & level)
{
    if (pozycja % 10 && level.plan[pozycja-1].typ == 1)
    {
        pozycja = pozycja - 1;
        level.pozycjagracza = level.pozycjagracza - 1;

        if (level.plan[pozycja].zawartosc == 1)
        {
            zbierz (level);
        }
    }
    else
    {
        printw  ("\nNie mozesz sie teraz poruszyc w lewo !!!\n");
        return;
    }

}
