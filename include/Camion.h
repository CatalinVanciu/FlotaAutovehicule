#ifndef CAMION_H
#define CAMION_H
#include "Vehicul.h"

class Camion:public Vehicul
{
    int greutate; ///ce greutate poate sa duca

    public:
        Camion();
        Camion(string, int, string, string, string, int, int, bool, int);
        virtual ~Camion();
        ostream & afisare(ostream&);
        istream & citire(istream&);

    protected:

    private:
};

#endif // CAMION_H
