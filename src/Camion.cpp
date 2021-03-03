#include "Camion.h"

Camion::Camion()
{
    //ctor
}

Camion::Camion(string i, int h, string a, string b, string c, int d, int e, bool f, int j):Vehicul(i,h,a,b,c,d,e,f){
    this->greutate = j;
}

Camion::~Camion()
{
    //dtor
}

ostream & Camion::afisare(ostream &out){
    Vehicul::afisare(out);
    out<<", Poate duce: "<<greutate<<" kg";

    return out;
}

istream & Camion::citire(istream &in){
    Vehicul::citire(in);
    in>>greutate;
    in.ignore();

    return in;
}
