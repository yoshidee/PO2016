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
    }
};


class Zoo : public Zwierze
{
protected:
    vector <Zwierze*> vz;
};


int main()
{

    Zwierze *z;

    z = new Krowa;
    z->daj_glos();
    delete z;

    z = new Koza;
    z-> daj_glos();
    delete z;


    cout << "\n, Hello World";
    return 0;
}
