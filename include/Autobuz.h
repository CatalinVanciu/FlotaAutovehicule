#ifndef AUTOBUZ_H
#define AUTOBUZ_H
#include "Vehicul.h"

class Autobuz:public Vehicul
{
    int numar_locuri;

    public:
        Autobuz();
        Autobuz(string, int, string, string, string, int, int, bool, int);
        virtual ~Autobuz();
        ostream & afisare(ostream&);
        istream & citire(istream&);

    protected:

    private:
};

#endif // AUTOBUZ_H
