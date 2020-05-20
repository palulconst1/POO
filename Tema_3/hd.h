#include <bits/stdc++.h>
#include <typeinfo>
#include<stdarg.h>
using namespace std;

ifstream fin ("citire.txt");
ofstream fout ("afisare.txt");

int nr=0;

class Animal
{
private:
    int nr_membre;
    int nr_ani;
    bool tip;
    char* nume;
public:

    Animal()
    {
        nume = new char[100];
        nr++;
    }

    Animal(char* nm, int c, int a, int b)
    {
        nr_ani=b;
        nr_membre=a;
        tip=c;
        nume = new char[strlen(nm)];
        strcpy(nume,nm);
        nr++;
    }

    void setMem(int x) {
      nr_membre = x;
    }
    int getMem() {
      return nr_membre;
    }
    void setAni(int x) {
      nr_ani = x;
    }
    int getAni() {
      return nr_ani;
    }
     void setTip(bool x) {
      tip = x;
    }
    int getTip() {
      return tip;
    }

    void setNume(char* x) {
      nume = x;
    }
    char* getNume() {
      return nume;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI"<<'\n';}
    friend ostream & operator << (ostream &out, const Animal &c);
    friend istream & operator >> (istream &in,  Animal &c);
    friend istream & operator >> (istream &in,  Animal* &c);
    friend ostream & operator << (ostream &out,  Animal* &c);

    Animal( Animal &p)
    {
    nume=p.nume;
    tip=p.tip;
    nr_ani=p.nr_ani;
    nr_membre=p.nr_membre;
    }

    static void nrAnimale()
    {
        cout<<nr;
    }

    virtual void citeste(Animal* &o)
    {
    fin>>o;
    }
    ~Animal()
    {
        delete nume;
        nr--;
    }
};



ostream & operator << (ostream &out, const Animal &obj)
{
    out <<"NUME: "<<obj.nume<<" SUBREGN: "<<obj.tip<<" NR MEMBRE: "<<obj.nr_membre<<" DURATA DE VIATA: "<<obj.nr_ani<<" ANI"<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Animal* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI"<<'\n';
    return out;
}

istream & operator >> (istream &in, Animal &c)
{
    in >> c.nume;
    in >> c.tip;
    in >> c.nr_membre;
    in >> c.nr_ani;
    return in;
}

istream & operator >> (istream &in, Animal* &c)
{
    in >> c->nume;
    in >> c->tip;
    in >> c->nr_membre;
    in >> c->nr_ani;
    return in;
}

class Vertebrate: public Animal
{
private:
    char* mediu_viata;
public:

    Vertebrate()
    {
        mediu_viata = new char[100];
    }

    Vertebrate(char* mn, int c, int a, int b, char* d):Animal(mn ,c, a, b)
    {
        mediu_viata=d;
    }
    void setMed(char* x) {
      mediu_viata=x;
    }
    char* getMed() {
      return mediu_viata;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI TRAIECTE IN: "<<this->getMed()<<'\n';}
    friend ostream & operator << (ostream &out,  Vertebrate &obj);
    friend istream & operator >> (istream &in,  Vertebrate &c);
    friend ostream & operator << (ostream &out,  Vertebrate* &obj);
    friend istream & operator >> (istream &in,  Vertebrate* &c);
    virtual void citeste(Vertebrate* &o)
    {
    fin>>o;
    }

    Vertebrate( Vertebrate &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    mediu_viata=p.mediu_viata;
    }

    ~Vertebrate()
    {
        delete mediu_viata;
    }
};


istream & operator >> (istream &in, Vertebrate &c)
{
    char* z= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> c.mediu_viata;
    return in;
}

istream & operator >> (istream &in, Vertebrate* &c)
{
    char* z= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> c->mediu_viata;
    return in;
}

ostream & operator << (ostream &out,  Vertebrate &obj)
{
    out <<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIESTE IN: "<<obj.mediu_viata<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Vertebrate* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIESTE IN: "<<obj->mediu_viata<<'\n';
    return out;
}

class Nevertebrate: public Animal
{
    private:
    char* mediu_viata;
public:

     Nevertebrate()
    {
        mediu_viata = new char[100];
    }

    Nevertebrate(char* mn, int c, int a, int b, char* d):Animal(mn, c, a, b)
    {
        mediu_viata=d;
    }

    void setMediu(char* x) {
      mediu_viata=x;
    }
    char* getMediu() {
      return mediu_viata;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI TRAIESTE IN: "<<this->getMediu()<<'\n';}
    friend ostream & operator << (ostream &out,  Nevertebrate &c);
    friend istream & operator >> (istream &in,  Nevertebrate &c);
    friend ostream & operator << (ostream &out,  Nevertebrate* &c);
    friend istream & operator >> (istream &in,  Nevertebrate* &c);

    Nevertebrate( Nevertebrate &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    mediu_viata=p.mediu_viata;
    }

    ~Nevertebrate()
    {
        delete mediu_viata;
    }

};

istream & operator >> (istream &in, Nevertebrate &c)
{
    char* z= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> c.mediu_viata;
    return in;
}

istream & operator >> (istream &in, Nevertebrate* &c)
{
    char* z= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> c->mediu_viata;
    return in;
}

ostream & operator << (ostream &out,  Nevertebrate &obj)
{
    out <<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIECTE IN: "<<obj.mediu_viata<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Nevertebrate* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIECTE IN: "<<obj->mediu_viata<<'\n';
    return out;
}

class Pasari: public Vertebrate
{
   private:
    int viteza;
public:

    Pasari(){}

    Pasari(char* mn, int c, int a, int b, char* d, int e):Vertebrate(mn, c, a, b, d)
    {
        viteza = e;
    }
    void setVitPa(int x) {
        viteza=x;
    }
    int getVitPa() {
      return viteza;
    }
    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI TRAIECTE IN: "<<this->getMed()<<" ARE VITEZA DE: "<<this->getVitPa()<<" KM/ORA"<<'\n';}

    friend ostream & operator << (ostream &out,  Pasari &obj);
    friend istream & operator >> (istream &in,  Pasari &c);
     friend ostream & operator << (ostream &out,  Pasari* &obj);
    friend istream & operator >> (istream &in,  Pasari* &c);


    Pasari(Pasari &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    setMed(p.getMed());
    viteza=p.viteza;
    }

    ~Pasari(){}

};

istream & operator >> (istream &in, Pasari &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> y;
    c.setMed(y);
    in >> c.viteza;
    return in;
}

istream & operator >> (istream &in, Pasari* &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> y;
    c->setMed(y);
    in >> c->viteza;
    return in;
}

ostream & operator << (ostream &out,  Pasari &obj)
{
    out<<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIECTE IN: "<<obj.getMed()<<" ARE VITEZA DE: "<<obj.viteza<<" KM/ORA"<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Pasari* &obj)
{
    out<<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIECTE IN: "<<obj->getMed()<<" ARE VITEZA DE: "<<obj->viteza<<" KM/ORA"<<'\n';
    return out;
}

class Pesti: public Vertebrate
{
   private:
    int lg;
    bool rapitor;

public:

    Pesti(){}

    Pesti(char* mn, int c, int a, int b, char* d, int e, bool f):Vertebrate(mn, c, a, b, d)
    {
        lg = e;
        rapitor = f;
    }

    void setLP(int x) {
      lg=x;
    }
    int getLP() {
      return lg;
    }

    void setR(bool x) {
      rapitor=x;
    }
    bool getR() {
      return rapitor;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<"ANI TRAIECTE IN: "<<this->getMed()<<'\n';
    fout<<"ARE LUNGIMEA DE: "<<this->getLP()<<" CM RAPITOR"<<this->getR()<<'/n';}
    friend ostream & operator << (ostream &out,  Pesti &obj);
    friend istream & operator >> (istream &in,  Pesti &c);
    friend ostream & operator << (ostream &out,  Pesti* &obj);
    friend istream & operator >> (istream &in,  Pesti* &c);

    Pesti(Pesti &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    setMed(p.getMed());
    lg=p.lg;
    rapitor=p.rapitor;
    }

    ~Pesti(){}

};

istream & operator >> (istream &in, Pesti &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> y;
    c.setMed(y);
    in >> c.lg;
    in >> c.rapitor;
    return in;
}

istream & operator >> (istream &in, Pesti* &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> y;
    c->setMed(y);
    in >> c->lg;
    in >> c->rapitor;
    return in;
}

ostream & operator << (ostream &out,  Pesti &obj)
{
    out <<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIECTE IN: "<<obj.getMed()<<" ARE LUNGIMEA DE: "<<obj.lg<<" CM RAPITOR "<<obj.rapitor<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Pesti* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIECTE IN: "<<obj->getMed()<<" ARE LUNGIMEA DE: "<<obj->lg<<" CM RAPITOR "<<obj->rapitor<<'\n';
    return out;
}

class Mamifere: public Vertebrate
{
   private:
    bool blana;
    int iq;

public:

    Mamifere(){}

    Mamifere(char* mn, int c, int a, int b, char* d, bool e, int f):Vertebrate(mn, c, a, b, d)
    {
        blana = e;
        iq = f;
    }

    void setBlana(bool x) {
      blana=x;
    }
    bool getBlana() {
      return blana;
    }

    void setIQ(int x) {
      iq=x;
    }
    int getIQ() {
      return iq;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI TRAIECTE IN: "<<this->getMed()<<'\n';
    fout<< this->getBlana()<<" BLANOS"<<" ARE IQ = "<<this->getIQ()<<'\n';}
    friend ostream & operator << (ostream &out,  Mamifere &obj);
    friend istream & operator >> (istream &in,  Mamifere &c);
    friend ostream & operator << (ostream &out,  Mamifere* &obj);
    friend istream & operator >> (istream &in,  Mamifere* &c);

     Mamifere(Mamifere &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    setMed(p.getMed());
    iq=p.iq;
    blana=p.blana;
    }

    ~Mamifere(){}

};

istream & operator >> (istream &in, Mamifere &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> y;
    c.setMed(y);
    in >> c.blana;
    in >> c.iq;
    return in;
}

istream & operator >> (istream &in, Mamifere* &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> y;
    c->setMed(y);
    in >> c->blana;
    in >> c->iq;
    return in;
}

ostream & operator << (ostream &out,  Mamifere &obj)
{
    out <<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIECTE IN: "<<obj.getMed()<<' '<<obj.blana<<" BLANOS ARE IQ = "<<obj.iq<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Mamifere* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIECTE IN: "<<obj->getMed()<<' '<<obj->blana<<" BLANOS ARE IQ = "<<obj->iq<<'\n';
    return out;
}

class Reptile: public Vertebrate
{
   private:
    bool venin;
    int lungime;

public:

    Reptile(){};

    Reptile(char* mn, int c, int a, int b, char* d, bool e, int f):Vertebrate(mn, c, a, b, d)
    {
        venin = e;
        lungime = f;
    }

    void setVenin(bool x) {
      venin=x;
    }
    bool getVenin() {
      return venin;
    }

    void setLG(int x) {
      lungime=x;
    }
    int getLG() {
      return lungime;
    }

    virtual void afis(){fout<<"NUME: "<<this->getNume()<<" SUBREGN: "<<this->getTip()<<" NR MEMBRE: "<<this->getMem()<<" DURATA DE VIATA: "<<this->getAni()<<" ANI TRAIECTE IN: "<<this->getMed()<<'\n';
    fout<<this->getVenin()<<" VENINOS"<<" ARE LUNGIME = "<<this->getLG()<<" CM "<<'\n';}
    friend ostream & operator << (ostream &out,  Reptile &obj);
    friend istream & operator >> (istream &in,  Reptile &c);
    friend ostream & operator << (ostream &out,  Reptile* &obj);
    friend istream & operator >> (istream &in,  Reptile* &c);

    Reptile(Reptile &p)
    {
    setNume(p.getNume());
    setTip(p.getTip());
    setAni(p.getAni());
    setMem(p.getMem());
    setMed(p.getMed());
    lungime=p.lungime;
    venin=p.venin;
    }

    ~Reptile(){};

};

istream & operator >> (istream &in, Reptile &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c.setNume(z);
    in >> d;
    c.setTip(d);
    in >> a;
    c.setMem(a);
    in >> b;
    c.setAni(b);
    in >> y;
    c.setMed(y);
    in >> c.venin;
    in >> c.lungime;
    return in;
}

istream & operator >> (istream &in, Reptile* &c)
{
    char* z= new char[100];
    char* y= new char[100];
    int a, b;
    bool d;
    in >> z;
    c->setNume(z);
    in >> d;
    c->setTip(d);
    in >> a;
    c->setMem(a);
    in >> b;
    c->setAni(b);
    in >> y;
    c->setMed(y);
    in >> c->venin;
    in >> c->lungime;
    return in;
}

ostream & operator << (ostream &out,  Reptile &obj)
{
    out <<"NUME: "<<obj.getNume()<<" SUBREGN: "<<obj.getTip()<<" NR MEMBRE: "<<obj.getMem()<<" DURATA DE VIATA: "<<obj.getAni()<<" ANI TRAIECTE IN: "<<obj.getMed()<<' '<<obj.venin<<" VENINOS ARE LUNGIME = "<<obj.lungime<<" CM "<<'\n';
    return out;
}

ostream & operator << (ostream &out,  Reptile* &obj)
{
    out <<"NUME: "<<obj->getNume()<<" SUBREGN: "<<obj->getTip()<<" NR MEMBRE: "<<obj->getMem()<<" DURATA DE VIATA: "<<obj->getAni()<<" ANI TRAIECTE IN: "<<obj->getMed()<<' '<<obj->venin<<" VENINOS ARE LUNGIME = "<<obj->lungime<<" CM "<<'\n';
    return out;
}

list <Animal*> lista;
list <Animal*>::iterator it;

list <Vertebrate*> lista1;
list <Vertebrate*>::iterator it1;

list <Nevertebrate*> lista2;
list <Nevertebrate*>::iterator it2;

list <Pasari*> lista3;
list <Pasari*>::iterator it3;

list <Pesti*> lista4;
list <Pesti*>::iterator it4;

list <Mamifere*> lista5;
list <Mamifere*>::iterator it5;

list <Reptile*> lista6;
list <Reptile*>::iterator it6;




template<class T1, class T2>
void check(T1 val, T2 ver)
{
    if (typeid(val) != typeid(ver))
        throw std::runtime_error("Tipuri de date diferite !");
}

void citLista()
{
    for(it=lista.begin(); it!=lista.end(); it++)
        fin>>(*it);
}

void citLista1()
{
    for(it1=lista1.begin(); it1!=lista1.end(); it1++)
        fin>>(*it1);
}

void afisLista()
{
    for(it=lista.begin(); it!=lista.end(); it++)
        (*it)->afis();
}

void afisLista1()
{
    for(it1=lista1.begin(); it1!=lista1.end(); it1++)
        (*it1)->afis();
}

void citLista2()
{
    for(it2=lista2.begin(); it2!=lista2.end(); it2++)
        fin>>(*it2);
}

void afisLista2()
{
    for(it2=lista2.begin(); it2!=lista2.end(); it2++)
        (*it2)->afis();
}

void citLista3()
{
    for(it3=lista3.begin(); it3!=lista3.end(); it3++)
        fin>>(*it3);
}

void afisLista3()
{
    for(it3=lista3.begin(); it3!=lista3.end(); it3++)
        (*it3)->afis();
}

void citLista4()
{
    for(it4=lista4.begin(); it4!=lista4.end(); it4++)
        fin>>(*it4);
}

void afisLista4()
{
    for(it4=lista4.begin(); it4!=lista4.end(); it4++)
        (*it4)->afis();
}

void citLista5()
{
    for(it5=lista5.begin(); it5!=lista5.end(); it5++)
        fin>>(*it5);
}

void afisLista5()
{
    for(it5=lista5.begin(); it5!=lista5.end(); it5++)
        (*it5)->afis();
}

void citLista6()
{
    for(it6=lista6.begin(); it6!=lista6.end(); it6++)
        fin>>(*it6);
}

void afisList6()
{
    for(it6=lista6.begin(); it6!=lista6.end(); it6++)
        (*it6)->afis();
}

template <class Z>
class AtlasZoologic {
Z* el;
public:
AtlasZoologic(){el = new Z();}
Z citit(){fin>>el;}
Z afisat(){fout<<el;}
};

class F { virtual void test(){} };
class G: public F{};


