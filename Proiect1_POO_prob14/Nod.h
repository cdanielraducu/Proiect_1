//
// Created by cdani on 10/23/2019.
//

#ifndef PROIECT1_POO_PROB14_NOD_H
#define PROIECT1_POO_PROB14_NOD_H


class Nod {
private:
    double coef;
    int exponent;
    Nod *next;

public:
    Nod();
    Nod(double coef,int exponent);
    double getCoef() const;

    void setCoef(double coef);

    int getExponent() const;

    void setExponent(int exponent);

    Nod *getNext() const;

    void setNext(Nod *next);

};


#endif //PROIECT1_POO_PROB14_NOD_H
