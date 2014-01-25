/*
    main.cpp
*/


#include <ncurses.h>
#include <iostream>

#include "plansza.h"
#include "gracz.h"
#include "potworek.h"




int main ()
{

    initscr();
    keypad(stdscr, TRUE);

    char decyzja;
    plansza lewel;

    while (1)
    {
        printw ("Czy chcesz czytac plansze z pliku (0) czy chcesz domyslna plansze (1) ?");
        decyzja = getch ();

        if (decyzja == '0')
        {
            lewel.czytaniezpliku();
            break;
        }
        else if (decyzja == '1')
        {
            break;
        }
        else
        {
            clear();
            printw ("Mozna tylko pobrac plansze z pliku albo stworzyc domyslna plansze !!!\n");
        }
    }

    clear();



    gracz a (lewel.dajpozycjegracza());
    int znak;
    potworek monster (lewel.dajpozycjepotwora());
    ///monster.decyduj(lewel);


    timeout(1000);
    bool czykomprusza = 1;

    while (1)
    {
        if (lewel.wypisz(a.dajpunktacje())) break;

        znak = getch();
        clear();
        if ( znak == 260)
        {
            a.wlewo(lewel);
        }
        else if ( znak == 259)
        {
            a.dogory(lewel);
        }
        else if ( znak == 258)
        {
            a.dodolu(lewel);
        }
        else if (znak == 261)
        {
            a.wprawo(lewel);
        }
        else
        {
            printw ("\nNie mozna sie poruszac inaczej niz za pomoca strzalek !!!\n");
        }

        if (lewel.wypisz(a.dajpunktacje()))
        {
            break;
        }
        clear();

        if (czykomprusza == 1)
        {
            monster.decyduj(lewel);
            czykomprusza = 0;
        }

        else if (czykomprusza == 0)
        {
            czykomprusza = 1;
        }
    }


    getch();

    endwin();

}
