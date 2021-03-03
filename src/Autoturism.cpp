#include "Autoturism.h"

Autoturism::Autoturism(){

}

Autoturism::Autoturism(string i, int h, string a, string b, string c, int d, int e, bool f, int j):Vehicul(i,h,a,b,c,d,e,f){
    this->numarUsi = j;
}

Autoturism::~Autoturism()
{
    //dtor
}

ostream & Autoturism::afisare(ostream &out){
    Vehicul::afisare(out);
    out<<", Numar usi: "<<numarUsi;

    return out;
}

istream & Autoturism::citire(istream &in){
    Vehicul::citire(in);
    in>>numarUsi;
    in.ignore();

    return in;
}
