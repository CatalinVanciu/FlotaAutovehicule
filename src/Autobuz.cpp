#include "Autobuz.h"

Autobuz::Autobuz()
{
    //ctor
}

Autobuz::Autobuz(string g, int i, string a, string b, string c, int d, int e, bool f, int h):Vehicul(g,i,a,b,c,d,e,f){
    this->numar_locuri = h;
}

Autobuz::~Autobuz()
{
    //dtor
}

ostream & Autobuz::afisare(ostream &out){
    Vehicul::afisare(out);
    out<<", Numar locuri: "<<numar_locuri;

    return out;
}

istream & Autobuz::citire(istream &in){
    Vehicul::citire(in);
    in>>numar_locuri;
    in.ignore();

    return in;
}
