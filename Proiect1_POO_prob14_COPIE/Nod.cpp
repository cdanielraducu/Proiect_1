//
// Created by cdani on 10/23/2019.
//

#include "Nod.h"

Nod::Nod(){
    setExponent(0);
    setCoef(0);
}
Nod::Nod(double coef, int exponent){
    this->coef = coef;
    this->exponent = exponent;
}

double Nod::getCoef() const {
    return coef;
}

void Nod::setCoef(double coef) {
    Nod::coef = coef;
}

int Nod::getExponent() const {
    return exponent;
}

void Nod::setExponent(int exponent) {
    Nod::exponent = exponent;
}

Nod *Nod::getNext() const {
    return next;
}

void Nod::setNext(Nod *next) {
    Nod::next = next;
}

