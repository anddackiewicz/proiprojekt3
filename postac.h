/*
    postac.h
*/
#ifndef postacie
#define postacie

class postac {

public:

virtual void dogory(plansza &) =0;
virtual void wprawo(plansza &) =0;
virtual void dodolu(plansza &) =0;
virtual void wlewo(plansza &) =0;

private:
int pozycja;
};
#endif
