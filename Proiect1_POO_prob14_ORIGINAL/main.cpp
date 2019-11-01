#include <iostream>
#include "Polinom.h"
#include "Clasa.h"


using namespace std;


int main() {

    //Polinom polinom1(4);
    //polinom1.afisareP(polinom1.getHead());
    //Polinom polinom2(3);
    //cout<<polinom2;
    //cout<<polinom2.getNr_Polinoame()<<endl;
    //{Polinom polinom3(2);
    //cout<<polinom3;
    //cout<<polinom3.getNr_Polinoame()<<endl;
    //}
    //cout<<polinom2.getNr_Polinoame()<<endl;

    //Polinom polinom;
    //cin>>polinom;
    //cout<<polinom;
    //cout<<polinom.getNr_Polinoame();

    //Polinom polinom1(polinom);
    //cout<<polinom1<<endl;
    //cout<<polinom.getNr_Polinoame();

    //Polinom p1(2);
    //cout<<p1;
    //cout<<p1.calcX(1);
    //p1.afisareP();
    //Polinom p2(3);
    //cout<<p2;
    //Polinom r;
    //r = p1 - p2;
    //cout<<r;

    Clasa c(2);
    cin>>c;
    cout<<c;
    cout<<c.getV()[0].calcX(1);
    cout<<endl<<endl;
    cout<<c[0];
    //Polinom p(2,false);
    //p.afisareP_inConsola();
    //cout<<p;
    //cout<<p[1];
    return 0;
}