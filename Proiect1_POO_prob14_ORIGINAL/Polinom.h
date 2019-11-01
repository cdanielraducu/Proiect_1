//
// Created by cdani on 10/23/2019.
//

#ifndef PROIECT1_POO_PROB14_POLINOM_H
#define PROIECT1_POO_PROB14_POLINOM_H
using namespace std;

#include "Nod.h"

class Polinom {
        int grad; static int nr_polinoame;
        Nod *head = new Nod();
        Nod *feet = new Nod();
public:
        Polinom();
        Polinom(int grad);
        Polinom(int grad, bool fisier);
        Polinom(const Polinom&);

        ~Polinom();
        void afisareP();
private:
    void setGrad(int grad);
    void setHead();
    void setFeet();
    void setHead(Nod * aux);
    void setFeet(Nod * aux);
    void setNr_Polinoame(int nr_polinoame);
public:
    int getGrad() const;
    Nod *getHead() const;
    Nod *getFeet() const;
    int getNr_Polinoame() const;
    Polinom &operator+(const Polinom &other);
    Polinom &operator*(const Polinom &other);
    Polinom &operator=(const Polinom &other);
    Polinom operator-(const Polinom &other);
    Polinom operator--();
    const Polinom operator--(int dummy);
    int operator!=(const Polinom &other);
    //operator float();
    int operator[](int i);
    friend ostream&operator<<(ostream&, Polinom &);
    friend istream&operator>>(istream&, Polinom &);
    double calcX(double valoare);

};


#endif //PROIECT1_POO_PROB14_POLINOM_H
