#include <ncurses.h>
#include <iostream>

#ifndef pola
#define pola

class pole {

public:

char rodzajpola;                /// W -wall P - player
int zawartosc;                 /// puste/punkty  0 - puste | 1 - punkty | 2 - wyjscie
int typ;                       /// sciana/przejscie 0 - sciana | 1 - przejscie
};
#endif
