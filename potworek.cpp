/*
    potworek.cpp
*/

#include "potworek.h"

potworek::potworek ()
{
    pozycja = 33;
}

potworek::potworek (int poz)
{
    pozycja = poz;
}


int potworek::czydogory (plansza & level) /// funkcja sprawdza czy potwor moze sie ruszyc do gory
{

        if (pozycja >= 10 && level.plan[pozycja-10].typ == 1)
        {
            /// mozna wykonac ruch do gory !!!
            return 1;

        }

        else
        {
            ///Ai nie moze wykonac ruchu do gory
            return 0;
        }
}

int potworek::czywlewo (plansza & level)
{
    if ((pozycja%10) != 0 && level.plan[pozycja-1].typ == 1)
    {
        /// mozna wykonac ruch w lewo !!!
        return 1;
    }
    else
    {
        ///Ai nie moze wykonac ruchu w lewo
        return 0;
    }

}

int potworek::czydodolu (plansza & level)
{

    if (pozycja < 90 && level.plan[pozycja+10].typ == 1)
    {
        /// mozna wykonac ruch do dolu !!!
        return 1;
    }
    else
    {
        ///Ai nie moze wykonac ruchu do dolu
        return 0;
    }
}

int potworek::czywprawo (plansza & level)
{

    if ((pozycja%10) != 9 && level.plan[pozycja+1].typ == 1)
    {
        /// mozna wykonac ruch w prawo !!!
        return 1;
    }
    else
    {
        ///Ai nie moze wykonac ruchu w prawo
        return 0;
    }
}



void potworek::decyduj (plansza & level)
{

    int roznicapoziom;
    int roznicapion;

    roznicapion = (level.pozycjagracza / 10) - (pozycja / 10);
    roznicapoziom = (level.pozycjagracza % 10) - (pozycja % 10);

    /// Decydowanie co zrobic !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if (roznicapion <= 0 && roznicapoziom <= 0)                        /// Do gory i w lewo
    {
                                                /// co dluzsze ?
                                                /// jak w pionie to do gory a jak nie to w prawo ( chyba ze sie nie da )
        if (-roznicapion >= -roznicapoziom )                            /// uwaga w tym przypadku dluzsze bedzie mniejsze w liczbie !!!
        {
            if (czydogory(level))
            {
                dogory(level);                          /// rusza sie tu do gory
            }
            else if (czywlewo(level))
            {
                wlewo(level);                           /// tutaj w lewo
            }
        }
        else
        {
            if (czywlewo(level))
            {
                wlewo(level);
            }
            else if (czydogory(level))
            {
                dogory(level);
            }
        }
        //cout << "\n1\n";


    }
    else if (roznicapion <= 0 && roznicapoziom >= 0)                                         /// Do gory i w prawo
    {
        if ((-roznicapion >= roznicapoziom))
        {
            if(czydogory(level))
            {
                dogory(level);
            }
            else if (czywprawo(level))
            {
                wprawo(level);
            }
        }
        else
        {
            if (czywprawo(level))
            {
                wprawo(level);
            }
            else if (czydogory(level))
            {
                dogory(level);
            }
        }

        //cout << "\n2\n";
    }
    else if (roznicapion >= 0 && roznicapoziom <= 0)                                         /// Do dolu w lewo
    {
        if (roznicapion >= -roznicapoziom)
        {
            if (czydodolu(level))
            {
                dodolu(level);
            }
            else if (czywlewo(level))
            {
                wlewo(level);
            }
        }
        else
        {
            if (czywlewo(level))
            {
                wlewo(level);
            }
            else if (czydodolu(level))
            {
                dodolu(level);
            }
        }
        //cout << "\n3\n";
    }
    else                                                /// Do dolu w prawo
    {
        if (roznicapion >= roznicapoziom)
        {
            if (czydodolu(level))
            {
                dodolu(level);
            }
            else if (czywprawo(level))
            {
                wprawo(level);
            }
        }
        else
        {
            if (czywprawo(level))
            {
                wprawo(level);
            }
            else if (czydodolu(level))
            {
                dodolu(level);
            }

        }
        //cout << "\n4\n";
    }


    return;
}


void potworek::dogory (plansza & level)
{

    if (pozycja >= 10 && level.plan[pozycja-10].typ == 1)
    {
        pozycja = pozycja - 10;
        level.pozycjapotwora = level.pozycjapotwora - 10;
    }
}

void potworek::wprawo (plansza & level)
{
    if ((pozycja%10) != 9 && level.plan[pozycja+1].typ == 1)
    {
        pozycja = pozycja + 1;
        level.pozycjapotwora = level.pozycjapotwora + 1;

    }
}

void potworek::dodolu (plansza & level)
{
    if (pozycja < 90 && level.plan[pozycja+10].typ == 1)
    {
        pozycja = pozycja + 10;
        level.pozycjapotwora = level.pozycjapotwora + 10;

    }
}

void potworek::wlewo (plansza & level)
{
    if (pozycja % 10 && level.plan[pozycja-1].typ == 1)
    {
        pozycja = pozycja - 1;
        level.pozycjapotwora = level.pozycjapotwora - 1;

    }
}
