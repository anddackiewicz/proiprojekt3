/*
    gracz.h
*/
#include "postac.h"

class gracz : public postac {

public:
friend class plansza;

gracz();
gracz (int poz);
int dajpunktacje ();
void zbierz (plansza & level);
void dogory (plansza & level);
void wprawo (plansza & level);
void dodolu (plansza & level);
void wlewo (plansza & level);

private:
int pozycja;
long long int punktacja;
};
