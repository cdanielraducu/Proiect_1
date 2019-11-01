//
// Created by cdani on 10/30/2019.
//

#ifndef PROIECT1_POO_PROB14_CLASA_H
#define PROIECT1_POO_PROB14_CLASA_H


#include <vector>
#include <iostream>

using namespace std;
#include "Polinom.h"

class Clasa {
    int nr_obiecte;
    Polinom *v;
public:
    Clasa();
    Clasa(int nr_obiecte);
    ~Clasa();
    Polinom *getV() const;

    int getNrObiect() const;
    Polinom operator[](int i);
    friend istream&operator>>(istream&, Clasa &);
    friend ostream&operator<<(ostream&, Clasa &);

};


#endif //PROIECT1_POO_PROB14_CLASA_H
