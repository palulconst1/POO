#include <iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

int counter=0;

class Biblioteca {
  private:
    char* nume;
    int id;

  public:
      Biblioteca( int id=0, char* nume=NULL):nume(nume), id(id){};
    void setID() {
      id = counter;
      counter+=1;
    }
    int getID() {
      return id;
    }
    void setNume(char* s) {
      nume = s;
    }
    char* getNume() {
      return nume;
    }
    void afiseaza(){cout<<this->getID()<<' '<<this->getNume()<<endl;}
        Biblioteca(const Biblioteca &p) {id= p.id; nume = p.nume;}
        friend ostream & operator << (ostream &out, const Biblioteca &c);
        ~Biblioteca()
{
    delete nume;
}
};
ostream & operator << (ostream &out, const Biblioteca &c)
{
    out << c.id<<" "<< c.nume<< endl;
    return out;
}

class Complex: public Biblioteca
{
private:
    int r, i;
public:
    Complex(int r=0, int i=0, char* nume=NULL, int id=0):r(r), i(i){this->setID();
    this->setNume(nume);};
    void afiseaza(){cout<<this->getID()<<' '<<this->getNume()<<' '<<r<<"+"<<i<<"i "<<'\n';}

    void setR(int x) {
      r = x;
    }
    int getR() {
      return r;
    }

      void setI(int x) {
      i = x;
    }
    int getI() {
      return i;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
    ~Complex(){}
};

ostream & operator << (ostream &out, const Complex &c)
{
    out <<c.r<<"+"<< c.i<<"i"<< endl;
    return out;
}

class Integer: public Biblioteca
{
private:
    int val;
    public:
        Integer(int val=0, char* nume=NULL, int id=0):val(val){this->setID();
        this->setNume(nume);};
       void afiseaza(){cout<<this->getID()<<' '<<this->getNume()<<' '<<val<<endl;}
    void setVal(int x) {
        val = x;
    }
    int getVal() {
      return val;
    }
friend ostream & operator << (ostream &out, const Integer &c);
~Integer(){}
};

ostream & operator << (ostream &out, const Integer &c)
{
    out <<c.val<< endl;
    return out;
}

class String: public Biblioteca
{
    char* sir;
    public:
        String(char* sir=NULL,char* nume=NULL, int id=0):sir(sir){this->setID();
        this->setNume(nume);};
        void afiseaza()
        {
            cout<<this->getID()<<' '<<this->getNume()<<' ';
            cout<<sir<<endl;
        }
        void setSir(char* x) {
            sir = x;}
    char* getSir() {
      return sir;}
      friend ostream & operator << (ostream &out, const String &c);
      String operator = (String const &obj) {
         char* res;
         strcpy(res, obj.sir) ;
         return res;
      }
      ~String()
{
    delete sir;
}
};

ostream & operator << (ostream &out, const String &c)
{
    out <<c.sir<< endl;
    return out;
}

class Adress: public Biblioteca
{
    char* ad;
    public:
        Adress(char* ad=NULL,char* nume=NULL, int id=0):ad(ad){this->setID();
        this->setNume(nume);};
       void afiseaza()
        {
            cout<<this->getID()<<' '<<this->getNume()<<' ';
            cout<<ad<<endl;
        }
        char* getAdress() {
      return ad;}
      friend ostream & operator << (ostream &out, const Adress &c);
      Adress operator = (Adress const &obj) {
         char* res;
         strcpy(res, obj.ad) ;
         return res;
      }
      ~Adress()
{
    delete ad;
}
};

ostream & operator << (ostream &out, const Adress &c)
{
    out <<c.ad<< endl;
    return out;
}

vector<Complex> C;
vector<Complex>::iterator it1;
vector<Integer> I;
vector<Integer>::iterator it2;
vector<String> S;
vector<String>::iterator it3;
vector<Adress> A;
vector<Adress>::iterator it4;

void verificareComplex(Complex x)
{
    unsigned int i;
    bool ok=true;
    for(i=0; i<C.size(); i++)
    {   char* name1=x.getNume();
        char* name2=C[i].getNume();
        if(strcmp(name1, name2)==0)
        {
            ok=false;
            break;
        }
    }
        if(ok)
            {C.push_back(x);
            return;}
        else
                {
                    x.setR(x.getR()*2);
                    x.setI(x.getI()*2);
                    C[i]=x;
                    return;
                }
}

template <typename V>
void afisare(V v)
{
    for(unsigned int i=0;i<v.size();i++)
        v[i].afiseaza();
    cout<<endl;
}

void verificareInteger(Integer x)
{
    unsigned int i;
    bool ok=true;
    for(i=0; i<I.size(); i++)
    {   char* name1=x.getNume();
        char* name2=I[i].getNume();
        if(strcmp(name1, name2)==0)
        {
            ok=false;
            break;
        }
    }
        if(ok)
            {I.push_back(x);
            return;}
        else
                {
                    x.setVal(x.getVal()*2);
                    I[i]=x;
                    return;
                }
}

void verificareString(String x)
{
    unsigned int i;
    bool ok=true;
    for(i=0; i<S.size(); i++)
    {   char* name1=x.getNume();
        char* name2=S[i].getNume();
        if(strcmp(name1, name2)==0)
        {
            ok=false;
            break;
        }
    }
        if(ok)
            {S.push_back(x);
            return;}
        else
                {
                    char sir2[9999];
                    int k=0;
                    char* sir=(x.getSir());
                    for(unsigned int j=0; j<strlen(sir); j++)
                        {sir2[k]=sir[j];
                        k++;}
                    for(unsigned int j=0; j<strlen(sir); j++)
                        {sir2[k]=sir[j];
                        k++;}
                        sir2[k]=NULL;
                    x.setSir(sir2);
                    S[i]=x;
                    return;
                }
}

void verificareAdresa(Adress x)
{
    unsigned int i;
    bool ok=true;
    for(i=0; i<A.size(); i++)
    {   char* name1=x.getNume();
        char* name2=A[i].getNume();
        if(strcmp(name1, name2)==0)
        {
            ok=false;
            break;
        }
    }
        if(ok)
            {A.push_back(x);
            return;}
        else
                {
                    cout<<"eroare"<<endl;
                    return;
                }
}

void stergeComplex(char* sir)
{
    for(it1=C.begin(); it1!=C.end(); it1++)
        {
        char* name=(*it1).getNume();
        if(strcmp(sir, name)==0)
        {
            C.erase(it1);
            break;
        }
    }
}

void stergeComplex(int id)
{
    for(it1=C.begin(); it1!=C.end(); it1++)
        {
        int idul=(*it1).getID();
        if(id==idul)
        {
            C.erase(it1);
            break;
        }
    }
}

void stergeInteger(char* sir)
{
    for(it2=I.begin(); it2!=I.end(); it2++)
    {
        char* name=(*it2).getNume();
        if(strcmp(sir, name)==0)
        {
            I.erase(it2);
            break;
        }
    }
}

void stergeInteger(int id)
{
    for(it2=I.begin(); it2!=I.end(); it2++)
    {   int idul=(*it2).getID();
        if(id==idul)
        {
            I.erase(it2);
            break;
        }
    }
}

void stergeString(char* sir)
{
    for(it3=S.begin(); it3!=S.end(); it3++)
    {  char* name=(*it3).getNume();
        if(strcmp(sir, name)==0)
        {
            S.erase(it3);
            break;
        }
    }
}

void stergeString(int id)
{
    for(it3=S.begin(); it3!=S.end(); it3++)
    {
        int idul=(*it3).getID();
        if(id==idul)
        {
            S.erase(it3);
            break;
        }
    }
}

void stergeAdress(char* sir)
{
    for(it4=A.begin(); it4!=A.end(); it4++)
    {   char* name=(*it4).getNume();
        if(strcmp(sir, name)==0)
        {
            A.erase(it4);
            break;
        }
    }
}

void stergeAdress(int id)
{
    for(it4=A.begin(); it4!=A.end(); it4++)
    {   int idul=(*it4).getID();
        if(id==idul)
        {
            A.erase(it4);
            break;
        }
    }
}

void stergeNume(char* sirul)
{
    stergeComplex(sirul);
    stergeInteger(sirul);
    stergeString(sirul);
    stergeAdress(sirul);
}

void stergeID(int idul)
{
    stergeComplex(idul);
    stergeInteger(idul);
    stergeString(idul);
    stergeAdress(idul);
}

void cautaComplex(char* sir)
{
    for(it1=C.begin(); it1!=C.end(); it1++)
        {
        char* name=(*it1).getNume();
        if(strcmp(sir, name)==0)
        {
            (*it1).afiseaza();
            break;
        }
    }
}

void cautaComplex(int id)
{
    for(it1=C.begin(); it1!=C.end(); it1++)
        {
        int idul=(*it1).getID();
        if(id==idul)
        {
           (*it1).afiseaza();
            break;
        }
    }
}

void cautaInteger(char* sir)
{
    for(it2=I.begin(); it2!=I.end(); it2++)
    {
        char* name=(*it2).getNume();
        if(strcmp(sir, name)==0)
        {
            (*it2).afiseaza();
            break;
        }
    }
}

void cautaInteger(int id)
{
    for(it2=I.begin(); it2!=I.end(); it2++)
    {   int idul=(*it2).getID();
        if(id==idul)
        {
            (*it2).afiseaza();
            break;
        }
    }
}

void cautaString(char* sir)
{
    for(it3=S.begin(); it3!=S.end(); it3++)
    {  char* name=(*it3).getNume();
        if(strcmp(sir, name)==0)
        {
            (*it3).afiseaza();
            break;
        }
    }
}

void cautaString(int id)
{
    for(it3=S.begin(); it3!=S.end(); it3++)
    {
        int idul=(*it3).getID();
        if(id==idul)
        {
            (*it3).afiseaza();
            break;
        }
    }
}

void cautaAdress(char* sir)
{
    for(it4=A.begin(); it4!=A.end(); it4++)
    {   char* name=(*it4).getNume();
        if(strcmp(sir, name)==0)
        {
            (*it4).afiseaza();
            break;
        }
    }
}

void cautaAdress(int id)
{
    for(it4=A.begin(); it4!=A.end(); it4++)
    {   int idul=(*it4).getID();
        if(id==idul)
        {
            (*it4).afiseaza();
            break;
        }
    }
}

void CautaComplex(int re, int im)
{
    for(it1=C.begin(); it1!=C.end(); it1++)
        {
        if(re==(*it1).getR() && im==(*it1).getI())
        {
            (*it1).afiseaza();
            break;
        }
    }
}

void CautaInteger(int v)
{
    for(it2=I.begin(); it2!=I.end(); it2++)
        {
        if(v==(*it2).getVal())
        {
            (*it2).afiseaza();
            break;
        }
    }
}

void CautaString(char* sir)
{
    for(it3=S.begin(); it3!=S.end(); it3++)
    {   char* cont=(*it3).getSir();
        if(strcmp(sir,cont)==0)
        {
            (*it3).afiseaza();
            break;
        }
    }
}

void CautaAdress(char* sir)
{
    for(it4=A.begin(); it4!=A.end(); it4++)
    {   char* cont=(*it4).getAdress();
        if(strcmp(sir,cont)==0)
        {
            (*it4).afiseaza();
            break;
        }
    }
}

void CautaValNr(int a, int b=99999)
{
     CautaComplex(a, b);
     CautaInteger(a);
}

void CautaValSir(char* c)
{
    CautaString(c);
    CautaAdress(c);
}

void CautaNume(char* sirul)
{
    cautaComplex(sirul);
    cautaInteger(sirul);
    cautaString(sirul);
    cautaAdress(sirul);
}

void CautaID(int idul)
{
    cautaComplex(idul);
    cautaInteger(idul);
    cautaString(idul);
    cautaAdress(idul);
}

int main()
{
    Complex a(5, 6, "mama");
    verificareComplex(a);
    Complex b(3,4, "gigi");
    verificareComplex(b);
    Complex c(5, 6, "mama");
    verificareComplex(c);
    afisare(C);

    Integer d(-3, "piu");
    verificareInteger(d);
    Integer e(4, "pau");
    verificareInteger(e);
    Integer f(-3, "piu");
    verificareInteger(f);
    afisare(I);

    String g("para", "bam");
    verificareString(g);
    String h("mar", "bim");
    verificareString(h);
    String i("para", "bam");
    verificareString(i);
    afisare(S);

    Adress x("copou", "acasa");
    verificareAdresa(x);
    Adress y("pu", "centru");
    verificareAdresa(y);
    Adress z("copou", "acasa");
    verificareAdresa(z);
    afisare(A);

    cout<<a;
    Biblioteca r(10, "carte");
    cout<<r;
    cout<<d;
    cout<<g;
    cout<<x;
    String l=h;
    cout<<l;
    Adress o=x;
    cout<<o;
}
