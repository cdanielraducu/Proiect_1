//
// Created by cdani on 10/23/2019.
//
#include <cmath>
#include <iostream>
#include "Polinom.h"
using  namespace std;

int Polinom::nr_polinoame;

Polinom::Polinom(int grad) {
    setHead();
    setFeet();
    this->grad = grad;
    this->setNr_Polinoame(this->getNr_Polinoame()+1);
    cout<<"Trebuie sa construim polinomul... "<<endl;
    int aux = grad;
    while(aux!=-1){
        Nod *a = new Nod();
        int coef;
        cout<<"\rPentru gradul "<<aux<<endl;
        cout<<"\rcoef: "; cin>>coef;
        a->setCoef(coef); a->setExponent(aux);
        a->setNext(nullptr);

        if(head == nullptr){
            head = a;
            feet = a;
            aux--;
            continue;
        }
        feet->setNext(a);
        feet = a;
        aux--;
    }

}
Polinom::Polinom() {
    this->grad = 0;
    setHead();
    setFeet();
}

//un polinom care se initializez peste tot cu 0, face cam acelasi lucru ca setGrad() + pune numele pe ""
Polinom::Polinom(int grad, bool null) {
    int aux = grad;
    this->setNr_Polinoame(this->getNr_Polinoame()+1);
    if(null){
        while(aux!=-1){
            Nod *a = new Nod();
            a->setCoef(0);
            a->setExponent(aux);
            a->setNext(nullptr);
            if(aux==grad){
                head = a;
                feet = a;
                aux--;
                continue;
            }
            feet->setNext(a);
            feet =a;
            aux--;
        }
    }
}

//copy constructor
Polinom::Polinom(const Polinom &polinom) {
    this->setGrad(polinom.getGrad());
    int aux = this->getGrad();
    this->setNr_Polinoame(this->getNr_Polinoame()+1);
    Nod *b = polinom.getHead();
    // copie la polinom
    while(aux!=-1){
        Nod *a = new Nod();
        a->setCoef(b->getCoef());
        a->setExponent(b->getExponent());
        a->setNext(nullptr);
        if(aux == this->getGrad()){
            this->setHead(a);
            this->setFeet(a);
            aux--;
            b=b->getNext();
            continue;
        }
        this->getFeet()->setNext(a);
        this->setFeet(a);
        aux--;
        b = b->getNext();
    }
}
//deconstructor
Polinom::~Polinom() {
    Nod *a = this->getHead();

    while(a!= nullptr){
        Nod *aux = a;
        a= a->getNext();
        delete aux;
    }

    this->setNr_Polinoame(this->getNr_Polinoame()-1);
}


void Polinom::afisareP() {
    Nod *a = head;
    cout<<"P: ";
    int ok = 0;
    //sa fac si pt "-" + sa-i pun un nume polinomului + sa fac cazul si pentru coef 0
    while(a->getNext() != nullptr){
        if(a!=this->getHead() && a!=this->getFeet() && a->getCoef() != 0){
            cout<<"+ ";
        }
        if(a->getCoef() !=0 ) {
            if (a->getCoef() > 0) {
                cout << a->getCoef() << "*x^" << a->getExponent()<<" ";
                ok = 1;
            } else if(a->getCoef() < 0 ){
                cout <<" ("<< a->getCoef() << "*x^" << a->getExponent()<<") ";
                ok =1;
            }
        }

        a = a->getNext();
    }
    if(a!=this->getHead() && a->getCoef() != 0 &&ok==1){
        cout<<"+ ";
    }
    if(a->getCoef() != 0) {
        if (a->getCoef() > 0) {
            cout << a->getCoef() << endl << endl;
            ok = 1;
        } else if(a->getCoef() < 0){
            cout << "(" << a->getCoef() << ")" << endl << endl;
            ok =1;
        }
    }
    a= a->getNext();
    if(ok == 0){
        cout<<"0";
    }
}

int Polinom::getGrad() const {
    return grad;
}
void Polinom::setGrad(int grad) {
    this->grad = grad;
    int aux = grad;
        while(aux!=-1){
            Nod *a = new Nod();
            a->setCoef(0);
            a->setExponent(aux);
            a->setNext(nullptr);
            if(aux==grad){
                this->setHead(a);
                this->setFeet(a);
                aux--;
                continue;
            }
            this->getFeet()->setNext(a);
            this->setFeet(a);
            aux--;
        }
}


void Polinom::setHead(){
    this->head  = nullptr;
}
Nod *Polinom::getHead() const{
    return head;
}
void Polinom::setFeet() {
    this->feet = nullptr;
}
Nod *Polinom::getFeet() const{
    return feet;
}
void Polinom::setHead(Nod *aux) {
    this->head = aux;
}
void Polinom::setFeet(Nod *aux) {
    this->feet = aux;
}
void Polinom::setNr_Polinoame(int nr_polinoame) {
    this->nr_polinoame = nr_polinoame;
}
int Polinom::getNr_Polinoame() const {
    return this->nr_polinoame;
}

ostream&operator<<(ostream &out, Polinom &p)  {
    Nod *a = p.getHead();
    out<<"P: ";
    int ok = 0;
    //sa fac si pt "-" + sa-i pun un nume polinomului + sa fac cazul si pentru coef 0
    while(a->getNext() != nullptr){
        if(a!=p.getHead() && a!=p.getFeet() && a->getCoef() != 0 & ok==1){
            cout<<"+ ";
        }
        if(a->getCoef() !=0 ) {
            if (a->getCoef() > 0) {
                out << a->getCoef() << "*x^" << a->getExponent()<<" ";
                ok = 1;
            } else if(a->getCoef() < 0 ){
                out <<" ("<< a->getCoef() << "*x^" << a->getExponent()<<") ";
                ok =1;
            }
        }

        a = a->getNext();
    }
    if(a!=p.getHead() && a->getCoef() != 0 && ok==1){
        cout<<"+ ";
    }
    if(a->getCoef() != 0) {
        if (a->getCoef() > 0) {
            out << a->getCoef() << endl << endl;
            ok = 1;
        } else if(a->getCoef() < 0){
            out << " (" << a->getCoef() << ")" << endl << endl;
            ok =1;
        }
    }
    a=a->getNext();
    if(ok == 0){
        cout<<"0";
    }
    return out;
}

istream&operator>>(istream &in, Polinom &p){
    int grad{0};
    cout<<"Ce grad vrei sa aibe polinomul: "; cin>>grad;
    p.setHead();
    p.setFeet();
    p.grad = grad;
    p.setNr_Polinoame(p.getNr_Polinoame()+1);

    cout<<"Trebuie sa construim polinomul de grad: "<<grad<<endl;
    int aux = grad;
    while(aux!=-1){
        Nod *a = new Nod();
        int coef;
        cout<<"\rPentru gradul "<<aux<<endl;
        cout<<"\rcoef: "; cin>>coef;
        a->setCoef(coef); a->setExponent(aux);
        a->setNext(nullptr);

        if(p.getHead() == nullptr){
            p.setHead(a);
            p.setFeet(a);
            aux--;
            continue;
        }
        p.getFeet()->setNext(a);
        p.setFeet(a);
        aux--;
    }
    return in;
}

Polinom &Polinom::operator=(const Polinom &other) {
    int aux = other.getGrad();
    Nod *b = other.getHead();

    while(aux!= -1){
        Nod *a = new Nod();
        a->setCoef(b->getCoef());
        a->setExponent(b->getExponent());
        a->setNext(nullptr);

        if(aux==other.getGrad()){
            this->setHead(a);
            this->setFeet(a);
            aux--;
            b=b->getNext();
            continue;
        }
        this->getFeet()->setNext(a);
        this->setFeet(a);
        aux--;
        b=b->getNext();
    }
    return *this;
}

Polinom &Polinom::operator+(const Polinom &other) {
    Nod *a = this->getHead();
    Nod *b = other.getHead();
    int max{0};
    if(this->getGrad() > other.getGrad()){
        max = this->getGrad();
    } else {
        max = other.getGrad();
    }
    Polinom *rezultat = new Polinom();
    rezultat->setGrad(max); // ii pun 0 la fiecare grad

    Nod *c = rezultat->getHead(); //un pointer la head-ul de la rezultat

    while(c != nullptr){
        if(a->getExponent() > b->getExponent()){
            c->setCoef(a->getCoef());
            a= a->getNext();
        } else if(a->getExponent() < b->getExponent()){
            c->setCoef(b->getCoef());
            b = b->getNext();
        } else if(a->getExponent() == b->getExponent()){
            c->setCoef(a->getCoef()+b->getCoef());
            a = a->getNext();
            b = b->getNext();
        }
        c = c->getNext();
    }
    return *rezultat;
}

Polinom &Polinom::operator*(const Polinom &other) {
        Nod *a = this->getHead();
        Nod *b = other.getHead();
        int max{0}, m{0},n{0};
        m = this->getGrad();
        n = other.getGrad();
        max = m+n-1;
        Polinom *rezultat;
        rezultat->setGrad(max);
        Nod *c = rezultat->getHead();
        auto *prod =new double[m+n-1];
        for(int i = 0; i<m+n-1; i++){
            prod[i] = 0;
        }
        for(int i = m-1; i>=0; i--){
            for(int j = n-1;j>=0;j--){
                prod[i+j] += a->getCoef()*b->getCoef();
                b = b->getNext();
            }
            b = other.getHead();
            a = a->getNext();
        }
        for(int k = max-1; k>=0; k--){
            c->setCoef(prod[k]);
            c->setExponent(k);
            c = c->getNext();
        }
        return *rezultat;
}

Polinom Polinom::operator-(const Polinom &other) {
    Nod *a = this->getHead();
    Nod *b = other.getHead();
    int max{0};
    if (this->getGrad() > other.getGrad()) {
        max = this->getGrad();
    } else {
        max = other.getGrad();
    }
    Polinom rezultat;
    rezultat.setGrad(max); // ii pun 0 la fiecare grad
    Nod *c = rezultat.getHead(); //un pointer la head-ul de la rezultat
    while (c != nullptr) {
        if (a->getExponent() > b->getExponent()) {
            c->setCoef(a->getCoef());
            a = a->getNext();
        } else if (a->getExponent() < b->getExponent()) {
            c->setCoef(-b->getCoef());
            b = b->getNext();
        } else if (a->getExponent() == b->getExponent()) {
            c->setCoef(a->getCoef() - b->getCoef());
            a = a->getNext();
            b = b->getNext();
        }
        c = c->getNext();
    }
    return rezultat;
}

double Polinom::calcX(double valoare) {
    Nod *a = head;
    double sum = 0;
    while(a != nullptr){
        if((a->getCoef() < 0) && (a->getExponent()%2==0) && (a->getExponent() != 0)){
            sum += abs(a->getExponent()) * valoare;
        } else {
                sum += a->getCoef() * valoare;
        }
        a = a->getNext();
    }
    return sum;
}

