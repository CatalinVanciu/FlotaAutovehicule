#ifndef VEHICUL_H
#define VEHICUL_H
#include <iostream>
#include <string>

using namespace std;

class Vehicul
{
    string marca;
    int id;
    string tip;
    string numar;
    string ITP;
    int capacitate;
    int vechime;
    bool folosire;

    public:
        Vehicul();
        Vehicul(string, int, string, string, string, int, int, bool);
        virtual ~Vehicul();
        friend istream & operator >> (istream&, Vehicul&);
        virtual istream & citire(istream&);
        friend ostream & operator << (ostream&, Vehicul&);
        virtual ostream & afisare(ostream&);
        string get_tip(){
            return this->tip;
        }
        string get_numar(){
            return this->numar;
        }
        string get_ITP(){
            return this->ITP;
        }
        int get_capacitate(){
            return this->capacitate;
        }
        int get_vechime(){
            return this->vechime;
        }
        bool get_folosire(){
            return this->folosire;
        }
        int get_ID(){
            return this->id;
        }
        string get_marca(){
            return this->marca;
        }

    protected:

    private:
};

#endif // VEHICUL_H
