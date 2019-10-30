//
// Created by cdani on 10/30/2019.
//

#include "Clasa.h"
using namespace std;


istream &operator>>(istream &in, Clasa &obj) {
    for(int i = 0;i<obj.getNrObiect();i++){
        int grad = 0;
        cout<<"Ce grad pt polinomul "<<i+1<<": "<<endl;
        in>>grad;
        Polinom p(grad);
        obj.getV()[i] = p;
    }
    return in;
}


ostream&operator<<(ostream &out, Clasa &obj){
    for(int i {0};i<obj.getNrObiect();i++){
        out<<obj.getV()[i]<<endl;
    }
    return out;
}

Clasa::Clasa() {
    nr_obiecte = 1;
    cout<<"Puteti pune doar un obiect in aceasta Clasa,";
    cout<<" daca vreti mai multe puneti la parametru nr de obiect"<<endl;
    this->v = new Polinom[nr_obiecte];
}
Clasa::Clasa(int nr_obiecte) {
    this->nr_obiecte=nr_obiecte;
    this->v = new Polinom[nr_obiecte];
}
int Clasa::getNrObiect() const {
    return nr_obiecte;
}

Polinom *Clasa::getV() const {
    return v;
}



