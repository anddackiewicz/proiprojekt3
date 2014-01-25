/*
    potworek.h
*/

#include "postac.h"


class potworek : public postac{

public:

friend class plansza;

potworek ();
potworek (int poz);
int czydogory (plansza & level);
int czywlewo (plansza & level);
int czydodolu (plansza & level);
int czywprawo (plansza & level);
void decyduj (plansza & level);
void dogory (plansza & level);
void wprawo (plansza & level);
void dodolu (plansza & level);
void wlewo (plansza & level);

private:
int pozycja;
};
