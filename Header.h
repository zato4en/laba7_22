# include <iostream>
# include <list>
using namespace std;



///////////////////4.4//////////////////
class Abstr {
public:
    virtual void print() = 0;
    int iPar = 0;
    Abstr() = default;
    Abstr(int p) : iPar(p) {}
    virtual ~Abstr() { cout << "iPar = " << iPar << " virtual Деструктор Abstr " << endl; }
};

class Deriv1 : public Abstr {
public:
    int iDPar;
    Deriv1(int p) : iDPar(p), Abstr(p) {}
    Deriv1() = default;

    virtual void print() {
        cout << "Derv1 = " << iDPar << " Abstr = " << iPar << endl;
    }
    virtual ~Deriv1() { cout << "iDPar = " << iDPar << " virtual Деструктор Deriv1 " << endl; }
};

class Deriv2 : public Deriv1 {
public:
    int iDPar;
    Deriv2(int p) : iDPar(p), Deriv1(p) {}
    Deriv2() = default;
    void print() {
        cout << "Derv2 = " << iDPar << " Abstr = " << iPar << endl;
    }
    virtual ~Deriv2() { cout << "iDPar = " << iDPar << " virtual Деструктор Deriv2 " << endl; }
};

class Deriv3 : public Deriv1 {
public:
    int iDPar;
    Deriv3(int p) : iDPar(p), Deriv1(p) {}
    Deriv3() = default;
    void print() {
        cout << "Derv3 = " << iDPar << " Abstr = " << iPar << endl;
    }
    virtual ~Deriv3() { cout << "iDPar = " << iDPar << " virtual Деструктор Deriv3 " << endl; }
};



void cout_of_list(list<Abstr*>& l)
{
    size_t i = 0;
    typename list<Abstr*>::iterator iterat;
    if (!l.empty())
    {
        for (iterat = l.begin(); iterat != l.end(); ++iterat, ++i)
        {
            cout << "l[" << i << "] = ";
            ((Abstr*)(*iterat))->print();
            cout << endl;
        }
    }
    else
        cout << "Список пуст!" << endl;
}
