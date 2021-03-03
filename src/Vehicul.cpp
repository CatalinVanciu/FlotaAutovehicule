#include "Vehicul.h"

Vehicul::Vehicul()
{
    //ctor
}

Vehicul::Vehicul(string h, int g, string a, string b, string c, int d, int e, bool f){
    this->tip = a;
    this->numar = b;
    this->ITP = c;
    this->capacitate = d;
    this->vechime = e;
    this->folosire = f;
    this->id = g;
    this->marca = h;
}

Vehicul::~Vehicul()
{
    //dtor
}

ostream & Vehicul::afisare(ostream &out){
    out<<"ID: "<<id<<", Tip: "<<tip<<", Marca: "<<marca<<", Numar de inmatriculare: "<<numar<<", ITP-ul expira la: "<<ITP<<", Capacitate: "<<capacitate<<" cm^3";
    out<<", Vechime: "<<vechime<<" ani";

    if(folosire)
        out<<", Folosit: DA";
    else
        out<<", Folosit: NU";

    return out;
}

ostream & operator << (ostream &out, Vehicul &v){
    return v.afisare(out);
}

istream & Vehicul::citire(istream &in){
    in>>id;
    in.ignore();
    getline(in, tip);
    getline(in, marca);
    getline(in, numar);
    getline(in, ITP);
    in>>capacitate;
    in.ignore();
    in>>vechime;
    in.ignore();
    in>>folosire;
    in.ignore();

    return in;
}

istream & operator >> (istream &in, Vehicul &v){
    return v.citire(in);
}
