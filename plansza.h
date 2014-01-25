/*
    plansza.h
*/

#include "pole.h"

class plansza {

public:
friend class gracz;
friend class potworek;

plansza ();
int dajpozycjegracza();
int dajpozycjepotwora();
int czytaniezpliku ();
int wypisz (int punktacja);


private:
pole plan[100];
int pozycjagracza;
int pozycjapotwora;
};
