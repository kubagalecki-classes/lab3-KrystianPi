#include <iostream>
#include <math.h>
using namespace std;
class Byt_Geometryczny
{
public:
    virtual void id() = 0;
};
class Figura : public Byt_Geometryczny
{
public:
    Figura() : pole(0){};
    Figura(double liczba) : pole(liczba){};
    void         set_pole(double p) { pole = p; }
    double       get_pole() { return pole; }
    virtual void id()
    {
        cout << "To jest figura geometryczna, jej pole to " << get_pole() << endl;
    };
    virtual ~Figura() { cout << "Figura zniszczona" << endl; }

private:
    double pole;
};
class Kolo : public Figura
{
public:
    Kolo() : Figura() {}
    Kolo(double r) : Figura(r * r * M_PI), promien(r) {}
    double get_promien() { return promien; }
    void   id() override { cout << "To jest kolo, jego pole to " << get_pole() << endl; };
    virtual ~Kolo() { cout << "Kolo zniszczone" << endl; }

private:
    double promien;
};
class Kwadrat : public Figura
{
public:
    Kwadrat() : Figura() {}
    Kwadrat(double a) : Figura(a * a), bok(a) {}
    double get_bok() { return bok; }
    void   id() override { cout << "To jest kwadrat, jego pole to " << get_pole() << endl; };
    virtual ~Kwadrat() { cout << "Kwadrat zniszczony" << endl; }

private:
    double bok;
};
void id(Figura* fig)
{
    if (fig == nullptr) {
        cout << "poza zakresem" << endl;
    }
    else {
        fig->id();
    }
}
class WektorFigur
{
public:
    WektorFigur() : licznik{0} { tab = new Figura[10]; }
    Figura* operator[](int index)
    {
        if (index < licznik) {
            return &tab[index];
        }
        else {
            return nullptr;
        }
    }
    ~WektorFigur() { delete[] tab; }
    void push(const Figura& nowa_figura)
    {

        tab[licznik] = nowa_figura;
        licznik      = licznik + 1;
    }
    void pop()
    {
        delete &tab[licznik];
        licznik = licznik - 1;
    }
    // Figura* operator()(const std::string&, double){}

private:
    int     licznik;
    Figura* tab;
};
class FabrykaFigur
{
public:
    Figura* operator()(const std::string& str, double n)
    {
        if (str == "Kwadrat") {
            Kwadrat{n};
        }
        else {
            if (str == "Kolo") {
                Kolo{n};
            }
            else {
                return nullptr;
            }
        }
    }

private:
};

int main()
{
    Kwadrat      a1(5);
    Kolo         b1(3);
    Kwadrat      c3(7);
    Figura       f1(4);
    FabrykaFigur fab;
    fab(Kolo, 5);
    // Figura  c0 = static_cast< Figura >(a1);
    // c0.id();
    // a1.id();
    // id(a1);
    // id(c0);
    // rzutowanie
    // Figura* f = new Kwadrat{};
    // f         = dynamic_cast< Kwadrat* >(f);
    // f         = dynamic_cast< Kolo* >(f); error
    // id(*f);
    // delete f;
    // wektorfigur testy

    /*WektorFigur w1;
    w1.push(a1);
    w1.push(b1);
    w1.push(c3);
    w1[0]->id();
    id(w1[1]);
    id(w1[2]);
    id(w1[5]);
    id(&a1);*/
}
