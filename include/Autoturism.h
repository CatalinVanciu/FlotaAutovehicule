#ifndef AUTOTURISM_H
#define AUTOTURISM_H
#include "Vehicul.h"

class Autoturism:public Vehicul
{
    int numarUsi;

    public:
        Autoturism();
        Autoturism(string, int, string, string, string, int, int, bool, int);
        virtual ~Autoturism();
        ostream & afisare(ostream&);
        istream & citire(istream&);

    protected:

    private:
};

#endif // AUTOTURISM_H
