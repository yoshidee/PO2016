#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Zwierze
{
protected:
    int8_t masa;
public:
    virtual void daj_glos() = 0; //klasa abstrakcyjna, niedostepne do swiata zewnetrznego
    void ustaw_mase (int8_t masa)
    {
        this -> masa = masa; // jezeli Zwierze nie troszczy sie o swoja mase to uzyje tej metody
    }

    Zwierze() //konstruktor
    {
        ustaw_mase(0);
    }
};


class Krowa : public Zwierze
{
public:
    void daj_glos()
    {
        cout << "Muu!";
    }
    void ustaw_mase (int8_t masa)
    {
        if (masa<0 || masa>1000) throw -1;
            Zwierze::ustaw_mase(masa);
        cout << endl << masa << endl;
    }
};

class Koza : public Zwierze
{
public:
    void daj_glos()
    {
        cout << "Beeeeee!";
    }
    void ustaw_mase (int8_t masa)
    {
        if (masa<0 || masa>1000) throw -1;
            Zwierze::ustaw_mase(masa);
        cout << endl << masa << endl;
    }
};


class Zoo
{
protected:
    vector <Zwierze*> v;

public:
    Zoo(){
    v.push_back(new Krowa());
    v.push_back(new Koza());
}
void glosy() {
    for (int i=0; i<v.size(); ++i)
        v.at(i) -> daj_glos();
}
};


int main()
{

    /*Zwierze *z;

    z = new Krowa;
    z->daj_glos();
    z->ustaw_mase(50);
    //cout << z.masa;
    delete z;

    z = new Koza;
    z-> daj_glos();
    delete z;*/

    Zoo zoo;
    zoo.glosy();



    //cout << "\n, Hello World";
    return 0;
}
