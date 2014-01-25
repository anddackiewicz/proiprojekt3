/*
    plansza.cpp
*/

#include "plansza.h"

plansza::plansza()
{
    printw ("\nkonstrukcja planszy domyslnej !!!\n");
    plan[0].zawartosc = 0;
    plan[0].typ = 1;
    pozycjagracza = 0;
    pozycjapotwora = 33;

    for (int rzad = 0; rzad < 10; rzad++)
    {

        for (int kolumna = 0; kolumna < 10; kolumna++)
        {
            if (rzad == 1||rzad == 2 || rzad == 4 || rzad == 5 || rzad == 7 || rzad == 8)
            {
                if (kolumna == 1||kolumna == 2 || kolumna == 4 || kolumna == 5 || kolumna == 7 || kolumna == 8)
                {
                    plan[rzad * 10 + kolumna].typ = 0;
                    plan[rzad * 10 + kolumna].zawartosc = 0;
                }
                else
                {
                    plan[rzad * 10 + kolumna].typ = 1;
                    plan[rzad * 10 + kolumna].zawartosc = 1;
                }
            }
            else
            {
                plan[rzad * 10 + kolumna].typ = 1;
                plan[rzad * 10 + kolumna].zawartosc = 1;
            }
        }

    }

    plan[99].zawartosc = 2;
}

int plansza::dajpozycjegracza()
{
    return pozycjagracza;
}

int plansza::dajpozycjepotwora()
{
    return pozycjapotwora;
}

int plansza::czytaniezpliku ()
{


    int pomocniczatablica[300];
    FILE *level1;
    if ((level1 = fopen("level1.txt","r")) == 0)  return -1; /// nie udalo sie otworzyc pliku

    int licznik = 0;
    char temp;

    while ((fscanf(level1 , "%c" , &temp)) != EOF)
    {
        pomocniczatablica[licznik] = temp;
        licznik++;
    }

    fclose(level1);

    int aktualnyznak = 0;


    ///______________________________________________
    ///  Analiza tablicyprzeslanej z pliku i zamiana na plansze

    pozycjagracza = 0;
    pozycjapotwora = 0;

    int numerpola = 0;

    int stan = 0;       ///Stan 0 oznacza ze teraz pozycja gracza wczytywana
                        ///Stan 1 oznacza ze teraz

    int stanpola = 0;


    while (pomocniczatablica[aktualnyznak] != 0)
    {

        if ((pomocniczatablica[aktualnyznak] >= '0' && pomocniczatablica[aktualnyznak] <= '9') || pomocniczatablica[aktualnyznak] == '|')
        {

            if (stan == 0 )
            {
                if (pomocniczatablica[aktualnyznak] == '|')
                {
                    stan = 1;
                }
                else
                {
                    pozycjagracza = pozycjagracza * 10 + pomocniczatablica[aktualnyznak] - '0';
                }
            }
            else if (stan == 1)
            {
                if (pomocniczatablica[aktualnyznak] == '|')
                {
                    stan = 2;
                }
                else
                {
                    pozycjapotwora = pozycjapotwora * 10 + pomocniczatablica[aktualnyznak] - '0';
                }
            }
            else if (stan == 2)                             /// USTAWIANIE PLANSZY
            {
                if (pomocniczatablica[aktualnyznak] >= '0' && pomocniczatablica[aktualnyznak] <= '9')
                {

                    if (stanpola == 0)
                    {
                        plan[numerpola].zawartosc = pomocniczatablica[aktualnyznak] - '0';
                        stanpola = 1;
                    }
                    else if (stanpola == 1)
                    {
                        plan[numerpola].typ = pomocniczatablica[aktualnyznak] - '0';
                        stanpola = 0;
                        numerpola++;
                        if (numerpola == 100) return 1;
                    }
                }
                else
                {
                    printw ("\nBlad w ustawianiu pola nr: \n");
                    printw ("%i",numerpola);
                }
            }



        }
        else
        {
            printw ("\nNieprawidlowy znak wczytany !!!\n");
            printw ("%i",numerpola);
            return -1;
        }

        aktualnyznak++;
    }

    getch();

}


int plansza::wypisz (int punktacja)
{


    for (int rzad = 0; rzad < 10; rzad++)
    {
        for (int kolumna = 0; kolumna < 10; kolumna++)
        {
            if (pozycjagracza == rzad*10 + kolumna)
            {
                printw ("G");                                 /// Oznaczenie gracza
            }
            else if (pozycjapotwora == rzad*10 + kolumna)
            {
                printw ("M");
            }
            else if (plan[rzad*10 + kolumna].zawartosc == 2 && plan[rzad*10 + kolumna].typ == 1)
            {
                printw ("E");                                 /// Oznaczenie wyjscia
            }
            else if (plan[rzad*10 + kolumna].typ == 1)
            {
                if (plan[rzad*10 + kolumna].zawartosc == 0)
                {
                    printw ("0");                             /// Czyste przejscie bez punktow
                }
                else printw ("1");                           /// Przejscie z punktami
            }
            else
            {
                printw ("S");
            }
        }
        printw ("\n");
    }

    if (pozycjagracza == pozycjapotwora)
    {

        printw ("\nGracz przegrywa !\n");
        printw  ("\nW trakcie Gry gracz zdobyl: ");
        printw  ("%i", punktacja);
        printw (" punktow.\n");
        return 1;
    }

    else if (plan[pozycjagracza].zawartosc == 2)
    {
        printw ("\nGracz wygrywa !\n");
        printw  ("\nW trakcie Gry gracz zdobyl: ");
        printw  ("%i", punktacja);
        printw (" punktow.\n");
        return 1;
    }
    else
    {
        printw ("Do tej pory gracz zdobyl: ");
        printw ("%i",punktacja);
        printw (" punktow.\n");
    }




    return 0;
}
