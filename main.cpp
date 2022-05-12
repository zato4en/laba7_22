#include "Header.h"
//#include "print.cpp"
#include <iterator>

//template<class T>
void Print_list(list<Abstr*>& l)
{
    size_t i = 0;
    typename list<Abstr*>::iterator iter;
    if (!l.empty())
    {
        for (iter = l.begin(); iter != l.end(); ++iter, ++i)
        {
            cout << "l[" << i << "] = ";
            ((Abstr*)(*iter))->print();
            cout << endl;
        }
    }
    else
        cout << "Список пуст!" << endl;
}


//////////////4.3///////////////
class Bas {
public:
    int a;
    int ClassType;
    Bas(int x = 0) : a(x), ClassType(0) {} // Конструктор
};
// Производный класс 1
class Type1 : public Bas {
public:
    int Coord;
    Type1(int x = 0) : Coord(x) { ClassType = 1; }    // Конструктор
    void Move(int Delta) { Coord += Delta; } // Метод для динамического вызовa
};
// Производный класс 2
class Type2 : public Bas {
public:
    int Coord;
    Type2(int x = 0) : Coord(x) { ClassType = 2; }    // Конструктор
    void Move(int Delta) { Coord -= Delta; }   // Метод для динамического вызовa
};

class A {
public:
    int a;
    A(int x = 0) { a = x; }
};
class F : virtual public A {
public:
    int b;
    F(int x = 0, int y = 0) : A(y), b(x) {}
};
class C : virtual public A {
public:
    int c;
    C(int x = 0, int y = 0) : A(y), c(x) {}
};
class D : public F, public C {
public:
    int d;
    D() : d(0) {}
    D(int x, int y, int z, int w) : F::A(w), F(y, w), C(z, w)
    {
        d = x;
    }
};


int main() {
    setlocale(LC_ALL, "Rus");
    // Ручная виртуализация
    Bas* pObj;
    Type1 T1(10);
    Type2 T2(20);
    // Задание значения указателя для Т1
    pObj = &T1;
    cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << endl;
    //При  pObj->Move(); Ошибка, так как указатель па базовый класс, а так Move нет!
    switch (pObj->ClassType)
    {
        case 1:
            ((Type1*)pObj)->Move(5); break; // Типизация указателя для Type1 (Type1 *)pObj
        case 2:
            ((Type2*)pObj)->Move(5); break; // Типизация указателя для Type2(Type2*)pObj
    }
    cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << endl;
    // Задание значения указателя для Т2
    pObj = &T2;
    switch (pObj->ClassType)
    {
        case 1:
            ((Type1*)pObj)->Move(5); break;
        case 2:
            ((Type2*)pObj)->Move(5); break;
    }
    cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << endl;

    //////////////4.5///////////////
    // 	   диаграмма классов
    //////////////4.6///////////////

    // Abstr new_obj;

    //////////////4.7///////////////
    Abstr* pAbs;
    Deriv1 d1(33);
    Deriv2 d2(44);
    Deriv3 d3(66);

    //////////////4.8///////////////
    cout << "\t4.8\n";
    d1.print();
    d2.print();
    d3.print();
    //////////////4.9///////////////
    cout << "\t4.9\n";
    Deriv1* pD2 = &d2;
    pD2->print();
    pD2 = &d1;
    pD2->print();
    pD2 = &d3;
    pD2->print();
    //////////////4.10//////////////
    cout << "\t4.10\n";
    pAbs = &d2;
    pAbs->print();
    //////////////4.11//////////////
    list <Abstr*> ListDer;
    //////////////4.12//////////////
    for (size_t i = 0; i < 3; ++i) {
        Deriv1* tmp1 = new Deriv1(i);
        ListDer.push_back(tmp1);
        //delete tmp1;
    }
    for (size_t i = 3; i < 6; ++i) {
        Deriv2* tmp2 = new Deriv2(i);
        ListDer.push_back(tmp2);
        //delete tmp2;
    }
    for (size_t i = 6; i < 9; ++i) {
        Deriv3* tmp3 = new Deriv3(i);
        ListDer.push_back(tmp3);
        //delete tmp3;
    }
    //////////////4.13///////////////
    cout << "\t4.13\n";
    Print_list(ListDer);
    //////////////4.14///////////////
    auto iter = ListDer.begin();
    for (size_t i = 0; i < 6; ++i) {
        ++iter;
    }
    ListDer.erase(iter);
    cout << "\t4.14\n";
    Print_list(ListDer);
    /////////////4.15///////////////
    cout << "\t4.15\n";
    D d(2, 3, 4, 5);
    cout << " d51.B6::a = " << d.F::a << endl;
    d.C::a = 100;
    cout << " d51.B6::a = " << d.F::a << endl;
    cout << " d51.C6::a = " << d.C::a << endl;
    cout << " d51.A6::a = " << d.A::a << endl;
    cout << " d51.B6::A5::a = " << d.F::A::a << endl;

    return 0;

}
