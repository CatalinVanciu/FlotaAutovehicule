#include <iostream>
#include <fstream>
#include "Vehicul.h"
#include "Autoturism.h"
#include "Camion.h"
#include "Autobuz.h"
#include <list>
#include <ctime>
#include <stdio.h>
#include <sstream>
#include <map>

using namespace std;

void incarcare_date(list<Vehicul*>& l){
    ifstream in;
    in.open("fisier.txt");

    string line;

    while(getline(in, line) && !line.empty()){
        stringstream ss(line);
        int temp;
        string tmp1, tmp2, tmp3;
        int tmp4, tmp5;
        bool tmp6;
        string tmp7;

        ss>>temp; ///id
        ss.ignore();
        getline(ss, tmp1, ','); ///tip
        getline(ss, tmp2, ','); ///numar inamtriculare
        getline(ss, tmp3, ','); ///expirare ITP
        ss>>tmp4; ///capacitate
        ss.ignore();
        ss>>tmp5; ///vechime
        ss.ignore();
        ss>>tmp6; ///folosit sau nu
        ss.ignore();
        getline(ss, tmp7, ','); ///marca

        if(tmp1 == "autoturism"){
            int tmp8;
            ss>>tmp8;
            ss.ignore();
            l.push_back(new Autoturism(tmp7, temp,tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8));
        }
        else if(tmp1 == "camion"){
            int tmp8;
            ss>>tmp8;
            ss.ignore();
            l.push_back(new Camion(tmp7,temp,tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8));
        }
        else if(tmp1 == "autobuz"){
            int tmp8;
            ss>>tmp8;
            ss.ignore();
            l.push_back(new Autobuz(tmp7,temp,tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8));
        }
        else
            cout<<"Vehicul nerecunoscut"<<"\n";
    }
    in.close();
}

void afisare(list<Vehicul*>& l){
    for(Vehicul* e: l)
       cout<<*e<<"\n\n";
}

void adaugare(list<Vehicul*>& l, string tmp1){
    bool ok = false;

    int temp; ///id
    string tmp2, tmp3; ///numar inmatriculare si expirare ITP
    int tmp4, tmp5; ///capacitate si vechime
    bool tmp6; ///folosit sau nu
    string tmp7; ///marca
    cout<<"\n";
    if(tmp1 == "autoturism"){
        cout<<"Introduceti ID-ul vehiculului: ";
        cin>>temp;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti numarul de inmatriculare: ";
        getline(cin, tmp2);
        cout<<"\n";
        cout<<"Introduceti data expirarii ITP-ului: ";
        getline(cin, tmp3);
        cout<<"\n";
        cout<<"Introduceti capacitatea: ";
        cin>>tmp4;
        cin.ignore();
        cout<<"\n";
        cout<<"Cat de vechi este vehiculul: ";
        cin>>tmp5;
        cin.ignore();
        cout<<"\n";
        cout<<"Este folosit sau nu( 0 - NU sau 1 - DA ) :";
        cin>>tmp6;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti marca vehiculului: ";
        getline(cin, tmp7);
        cout<<"\n";
        int tmp8;
        cout<<"Introduceti numarul de usi al vehiculului: ";
        cin>>tmp8;
        cin.ignore();
        cout<<"\n";
        l.push_back(new Autoturism(tmp7, temp, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8));
        ok = true;
    }
    else if(tmp1 == "camion"){
        cout<<"Introduceti ID-ul vehiculului: ";
        cin>>temp;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti numarul de inmatriculare: ";
        getline(cin, tmp2);
        cout<<"\n";
        cout<<"Introduceti data expirarii ITP-ului: ";
        getline(cin, tmp3);
        cout<<"\n";
        cout<<"Introduceti capacitatea: ";
        cin>>tmp4;
        cin.ignore();
        cout<<"\n";
        cout<<"Cat de vechi este vehiculul: ";
        cin>>tmp5;
        cin.ignore();
        cout<<"\n";
        cout<<"Este folosit sau nu( 0 - NU sau 1 - DA ) :";
        cin>>tmp6;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti marca autovehiculului: ";
        getline(cin, tmp7);
        cout<<"\n";
        int tmp8;
        cout<<"Ce greutate poate sa duca camionul: ";
        cin>>tmp8;
        cin.ignore();
        cout<<"\n";
        l.push_back(new Camion(tmp7, temp, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8));
        ok = true;
    }
    else if(tmp1 == "autobuz"){

        int tmp8;

        cout<<"Introduceti ID-ul vehiculului: ";
        cin>>temp;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti numarul de inmatriculare: ";
        getline(cin, tmp2);
        cout<<"\n";
        cout<<"Introduceti data expirarii ITP-ului: ";
        getline(cin, tmp3);
        cout<<"\n";
        cout<<"Introduceti capacitatea: ";
        cin>>tmp4;
        cin.ignore();
        cout<<"\n";
        cout<<"Cat de vechi este vehiculul: ";
        cin>>tmp5;
        cin.ignore();
        cout<<"\n";
        cout<<"Este folosit sau nu( 0 - NU sau 1 - DA ) :";
        cin>>tmp6;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti numarul de locuri: ";
        cin>>tmp8;
        cin.ignore();
        cout<<"\n";
        cout<<"Introduceti marca vehiculului: ";
        getline(cin, tmp7);
        cout<<"\n";
        l.push_back(new Autobuz(tmp7, temp, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6,tmp8));
        ok = true;
    }

    if(ok == false)
        cout<<"\nVehicul nerecunoscut\n";
    else{
        cout<<"\nLista finala a vehiculelor, dupa ce a fost facuta adaugarea este: \n\n";
        afisare(l);
    }
}

void stergere(list<Vehicul*>& l, int id){
    bool ok = false;

    for(Vehicul* e : l){
        int temp = e->get_ID();
        if(temp == id){
            l.remove(e);
            ok = true;
            break;
        }
    }

    if(ok == false)
        cout<<"ID-ul autovehiculului nu a fost identificat"<<"\n";
    else{
        cout<<"\nLista de vehicule dupa stergerea vehiculului cu ID-ul "<<id<<" este: \n\n";
        afisare(l);
    }
}

void verificare_ITP(list<Vehicul*>& l){
    int count = 0, luna, an;
    cout<<"Luna curenta: ";
    cin>>luna;
    cout<<"\nAnul: ";
    cin>>an;

    for(Vehicul* e: l){
        string temp = e->get_ITP();

        int t_zi, t_luna, t_an; ///ziua, luna si anul fiecarui obiect din lista
        sscanf(temp.c_str(), "%d/%d/%d", &t_zi, &t_luna, &t_an);

        if((an == t_an) && (luna == t_luna)){
            cout<<"\n"<<*e<<"\n";
            count++;
        }
    }

    if(count == 0)
        cout<<"\nIn luna curenta nu are niciun vehicul ITP-ul expirat\n";
}

void statistica1(list<Vehicul*>& l){///statistica a vechimii vehiculelor, unui tip de vehicul
    string tip_vehicul; ///autoturism, camion, autobuz
    cout<<"Tipul de vehicul, dupa care vrem sa aflam lista vechimii: ";
    cin>>tip_vehicul;
    cout<<"\n";

    if(tip_vehicul != "autoturism" && tip_vehicul != "camion" && tip_vehicul != "autobuz")
        cout<<"Nu exista un asemenea tip de vehicul in flota \n";
    else{
        cout<<"Statistica a vechimii vehiculelor, tipului de vehicul "<<tip_vehicul<<" este:\n";
        for(Vehicul* e: l)
            if(e->get_tip() == tip_vehicul)
                cout<<"\n"<<"ID: "<<e->get_ID()<<", Marca: "<<e->get_marca()<<", Numar de inamtriculare: "<<e->get_numar()<<", Vechime: "<<e->get_vechime()<<" ani\n";
    }
}

void statistica2(list<Vehicul*>& l){///statistica a tipurilor de vehicule (cate vehicule din fiecare tip sunt)
    map<string, int> Mp;
    bool ok = false;

    for(Vehicul* e: l){
        if(Mp.find(e->get_tip()) != Mp.end())
            Mp[e->get_tip()]++;
        else
            Mp[e->get_tip()] = 1;
        ok = true;
    }
    if(ok == false)
        cout<<"Nu exista un asemenea tip de vehicul in flota \n";
    else{
        cout<<"Statistica cu numarul tipurilor de vehicule:\n";
        for(auto e: Mp)
        cout<<"\n"<<e.first<<" - "<<e.second<<"\n";
    }
}

void statistica3(list<Vehicul*>& l){///verificare numar de vehicule care nu sunt folosite
    int count = 0;

    for(Vehicul* e: l)
        if(e->get_folosire() == false){
            cout<<"\nID:"<<e->get_ID()<<", Tip vehicul: "<<e->get_tip()<<", Marca: "<<e->get_marca()<<", Numar de inmatriculare: "<<e->get_numar()<<"\n";
            count++;
        }
    if(count == 1)
        cout<<"\n"<<"In flota nu este folosit "<<count<<" vehicul.\n";
    else
        cout<<"\n"<<"In flota nu sunt folosite "<<count<<" vehicule.\n";
}

int main()
{
    list<Vehicul*> l;
    incarcare_date(l);

    string ok;

    do{
        cout<<"1: AFISARE lista vehicule din flota.\n\n";
        cout<<"2: STERGERE vehicul din flota.\n\n";
        cout<<"3: ADAUGARE vehicul in flota.\n\n";
        cout<<"4: VERIFICARE ITP vehicule.\n\n";
        cout<<"5: prezentare statistica a VECHIMII vehiculelor, unui tip de vehicul.\n\n";
        cout<<"6: LISTA vehiculelor prezente in flota.\n\n";
        cout<<"7: statistica a vehiculelor care NU SUNT FOLOSITE.\n\n";

        int input;
        cout<<"\nIntroduceti un numar: ";
        cin>>input;
        cout<<"\n";


        if(input == 1)
            afisare(l);
        else if(input == 2){
            cout<<"Lista de vehicule disponibile: \n\n";
            afisare(l);
            int id_sters;
            cout<<"\nIntroduceti ID-ul vehiculului care vreti sa-l stergem: ";
            cin>>id_sters;
            cout<<"\n";
            stergere(l,id_sters);
        }
        else if(input == 3){
            cout<<"Ce vehicul dorim sa adaugam: ";
            string tmp1;
            cin>>tmp1;
            adaugare(l, tmp1);
        }
        else if(input == 4){
            verificare_ITP(l);
        }
        else if(input == 5){
            statistica1(l);
        }
        else if(input == 6){
            statistica2(l);
        }
        else if(input == 7){
            cout<<"Statistica cu vehiculele care nu sunt folosite : \n";
            statistica3(l);
        }
        else
            cout<<"Numarul nu corespunde !";

        cout<<"\n\nDaca doresti sa revii la meniul principal, tasteaza DA, altfel tasteaza NU: ";
        cin>>ok;
        cout<<"\n";
    }while(ok == "DA");

    if(ok == "NU")
        cout<<"Procesul s-a incheiat.\n";

    return 0;
}
