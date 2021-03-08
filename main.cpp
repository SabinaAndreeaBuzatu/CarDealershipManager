#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

class masina
{
protected:

    int ani;
    double pret;
    double litraj;
    static int n;
public:

    masina (int ani=0,double pret=0, double litraj=0)
    {
        n++;

        this->litraj=litraj;
        this->ani=ani;
        this->pret=pret;

    }
    masina(masina &m)
    {

        this->litraj=litraj;
        this->ani=m.ani;
        this->pret=m.pret;

    }
    masina &operator =(masina &m)
    {
        this->litraj=litraj;
        this->ani=m.ani;
        this->pret=m.pret;
        return*this;

    }

    ~masina()
    {
        if (litraj!=0&&ani!=0&&pret!=0)
            litraj=0;
        ani=0;
        pret=0;
    }

    virtual void citire(istream& in)
    {

        cout<<"Varsta masinii: ";
        in>>ani;
        cout<<"Litrajul masinii:";
        in>>litraj;
        cout<<" Pretul masinii: ";
        in>>pret;


    }

    virtual void afisare(ostream &out)
    {


        out<<"Varsta masinii: ";
        out<<ani<<endl;
        out<<"Litrajul masinii:";
        out<<litraj<<endl;
        out<<" Pretul masinii: ";
        out<<pret<<endl;
    }

    friend istream &operator>>(istream &in, masina& m);


    friend ostream &operator<<(ostream &out, masina& m);

    static int nrmasini()
    {
        return n;
    }


};
int masina::n;
class MINI:public masina
{
private:

    double lungime;
    const string tiputilizare="Oras";
    const int capacitate=5;
    const bool nou=1;

public:
    MINI( double lungime=0,string tipu="", int ani=0,double pret=0,double litraj=0):masina(ani,pret,litraj)
    {
        try
        {

            if(lungime<0||lungime>4)
                throw lungime;

        }
        catch (double s)
        {
            cout<<"Eroare in constructor. Lungime necorespunzatoare(MINI are lungime de maxim 4 m)\n";
            exit(EXIT_FAILURE);
        }


        this->lungime=lungime;
        //tiputilizare=tipu;

    }
    ~MINI()
    {

    }
    MINI(MINI &m):masina(m)
    {

        lungime=m.lungime;
        //tiputilizare=m.tiputilizare;
    }
    MINI &operator =(MINI &m)
    {
        masina::operator=(m);
        lungime=m.lungime;
        return*this;
    }
    void citire (istream &in)
    {
        masina::citire(in);
        cout<<"Lungime(0-4): ";
        double lung;
        in>>lung;
        try
        {

            if(lung<0||lung>4)
                throw lung;

        }
        catch (double s)
        {
            cout<<"Eroare la citire. Lungime necorespunzatoare(MINI are lungime de maxim 4 m)\n";
            exit(EXIT_FAILURE);
        }

        lungime=lung;
        in.get();

        cout<<endl;
    }
    void afisare(ostream &out)
    {
        out<<"Tipul masinii: MINI"<<endl;
        masina::afisare(out);
        out<<"Litraj: ";
        out<<litraj<<endl;
        out<<"Lungime: ";
        out<<lungime<<endl;
        out <<"Tipul utilizarii: ";
        out<<tiputilizare<<endl;
        out<<"Capacitate:";
        out<<capacitate<<endl;
        out<<"Masina noua sau sh(1/0):";
        out<<nou<<endl;


    }
};
class MICA:public masina
{
private:

    double lungime;
    const string tiputilizare="Oras";
    const int capacitate=5;
    const bool nou=1;

public:
    MICA( double litraj=0,double lungime=0,string tipu="", int ani=0,double pret=0):masina(ani,pret,litraj)
    {
        try
        {

            if(lungime!=0&&(lungime<3.85||lungime>4.1))
                throw lungime;

        }
        catch (double s)
        {
            cout<<"Eroare in constructor. Lungime necorespunzatoare(MICA are lungime cuprinsa intre 3.85 si 4.1 m)\n";
            exit(EXIT_FAILURE);
        }
        this->lungime=lungime;

    }
    ~MICA()
    {

    }
    MICA(MICA &m):masina(m)
    {

        lungime=m.lungime;


    }
    MICA &operator =(MICA &m)
    {
        masina::operator=(m);
        lungime=m.lungime;
        return*this;

    }
    void citire (istream &in)
    {
        masina::citire(in);

        cout<<"Lungime(3,85-4,1): ";
        double lung;
        in>>lung;
        try
        {

            if(lung<3.85||lung>4.1)
                throw lung;

        }
        catch (double s)
        {
            cout<<"Eroare la citire. Lungime necorespunzatoare(MICA are lungime cuprinsa intre 3.85 si 4.1 m)\n";
            exit(EXIT_FAILURE);
        }
        //in.get();
        cout<<endl;
    }
    void afisare(ostream &out)
    {
        cout<<"Tipul masinii : MICA"<<endl;
        masina::afisare(out);
        out<<"Lungime: ";
        out<<lungime<<endl;
        out <<"Tipul utilizarii: ";
        out<<tiputilizare<<endl;
        out<<"Capacitate:";
        out<<capacitate<<endl ;
        out<<"Masina noua sau sh(1/0):";
        out<<nou<<endl;



    }
};
class COMPACTA:public masina
{
private:

    double lungime;
    string tiputilizare;
    string tipspate;
    const int capacitate=5;
    const bool nou=1;

public:
    COMPACTA(double litraj=0,double lungime=0,string tipu="",string tips="", int ani=0,double pret=0):masina(ani,pret,litraj)
    {
        try
        {

            if(lungime!=0&&(lungime<4.2||lungime>4.5))
                throw lungime;

        }
        catch (double s)
        {
            cout<<"Eroare in constructor. Lungime necorespunzatoare(COMPACTA are lungime cuprinsa intre 4.2 si 4.5 m)\n";
            exit(EXIT_FAILURE);
        }


        this->lungime=lungime;
        tiputilizare=tipu;
        tipspate=tips;

    }
    ~COMPACTA() {}
    COMPACTA(COMPACTA &m):masina(m)
    {
        lungime=m.lungime;
        tiputilizare=m.tiputilizare;
        tipspate=m.tipspate;

    }
    COMPACTA &operator =(COMPACTA &m)
    {
        masina::operator=(m);
        lungime=m.lungime;
        tiputilizare=m.tiputilizare;
        tipspate=m.tipspate;
        return*this;
    }
    void citire (istream &in)
    {
        masina::citire(in);

        cout<<"Lungime(4.2-4.5): ";
        double lung;
        in>>lung;
        try
        {

            if(lung<4.2||lung>4.5)
                throw lung;

        }
        catch (double s)
        {
            cout<<"Eroare la citire. Lungime necorespunzatoare(COMPACTA are lungime cuprinsa intre 4.2 si 4.5 m)\n";
            exit(EXIT_FAILURE);
        }
        lungime=lung;
        in.get();
        cout <<"Tipul utilizarii(ORAS/DRUM LUNG): ";
        string x;
        getline(in,x);

        tiputilizare=x;
        cout <<"Tip spate(HATCHBACK/COMBI/SEDAN): ";
        getline(in,x);
        tipspate=x;
        cout<<endl;
    }

    void afisare(ostream &out)
    {
        out<<"Tipul masinii: COMPACTA"<<endl;
        masina::afisare(out);
        out<<"Lungime: ";
        out<<lungime<<endl;
        out <<"Tipul utilizarii: ";
        out<<tiputilizare<<endl;
        out<<"Tip spate: ";
        out<<tipspate<<endl;
        out<<"Capacitate:";
        out<<capacitate<<endl;
        out<<"Masina noua sau sh(1/0):";
        out<<nou<<endl;

    }
};
class MONOVOLUM:public masina
{
private:

    double lungime;
    string tiputilizare;
    int capacitate;
    bool nou;

public:
    MONOVOLUM( double litraj=0,double lungime=0,string tipu="",int capacitate=0, bool nou=0, int ani=0,double pret=0):masina(ani,pret,litraj)
    {

        this->lungime=lungime;

        tiputilizare=tipu;
        try
        {

            if(capacitate!=5&&capacitate!=7&&capacitate!=0)
                throw capacitate;

        }
        catch (int s)
        {
            cout<<"Eroare in constructor. Capacitatea este 5 sau 7)\n";
            exit(EXIT_FAILURE);
        }
        this->capacitate=capacitate;
        this->nou=nou;
    }
    ~MONOVOLUM() {}
    MONOVOLUM(MONOVOLUM &m):masina(m)
    {

        lungime=m.lungime;
        tiputilizare=m.tiputilizare;
        capacitate=m.capacitate;
        nou=m.nou;
    }
    MONOVOLUM &operator =(MONOVOLUM &m)
    {
        masina::operator=(m);
        lungime=m.lungime;
        tiputilizare=m.tiputilizare;
        capacitate=m.capacitate;
        nou=m.nou;
        return *this;

    }

    void citire (istream &in)
    {
        masina::citire(in);

        cout<<"Lungime: ";
        in>>lungime;
        in.get();
        cout <<"Tipul utilizarii(ORAS/DRUM LUNG): ";
        string x;
        getline(in,x);
        tiputilizare=x;
        cout<<"Capacitate(5 sau 7):";
        int cap;
        in>>cap;

        try
        {

            if(cap!=5&&cap!=7)
                throw cap;

        }
        catch (int s)
        {
            cout<<"Eroare la citire. Capacitatea este 5 sau 7)\n";
            exit(EXIT_FAILURE);
        }

        capacitate=cap;
        cout<<"Masina noua sau sh(1/0):";
        in>>nou;
        cout<<endl;
    }
    void afisare(ostream &out)
    {
        out<<"Tipul masinii: MONOVOLUM"<<endl;
        masina::afisare(out);
        out<<"Lungime: ";
        out<<lungime<<endl;
        out <<"Tipul utilizarii: ";
        out<<tiputilizare<<endl;
        out<<"Capacitate:";
        out<<capacitate<<endl;
        out<<"Masina noua sau sh(1/0):";
        out<<nou<<endl;
    }

    double get_pret() const
    {
        return pret;
    }
};


template<class v>
class Vanzare
{
private:

    int nrmasinist;
    int nrmasinivd;
    vector<v*> stoc;
    vector<v*> vand;
public:
    Vanzare(int nrmasinist=0,int nrmasinivd=0, v *stoc1=NULL, v *vand1=NULL)
    {
        for(int i=0; i<nrmasinist; i++)
        {
            stoc.push_back(&stoc1[i]);
            vand.push_back(&vand1[i]);
        }
        this->nrmasinist=nrmasinist;
        this->nrmasinivd=nrmasinivd;

    }
    Vanzare<v> (Vanzare &m)
    {
        this->nrmasinist=m.nrmasinist;
        this->nrmasinivd=m.nrmasinivd;
        this-> stoc=  m.stoc;
        this->vand= m.vand;

    }
    Vanzare<v> &operator = (Vanzare &m)
    {
        this->nrmasinist=m.nrmasinist;
        this->nrmasinivd=m.nrmasinivd;
        this-> stoc=  m.stoc;
        this->vand= m.vand;
        return*this;

    }

    ~Vanzare<v>()
    {

    }


    void citire(istream &in)
    {
        cout<<"\nNr masini in stoc:";
        in>>nrmasinist;
        cout<<endl;
        for(int i=0; i<nrmasinist; i++)
        {
            v *a=new v;
            in>>*a;

            stoc.push_back(a);


        }


        cout<<"Nr masini vadute: ";
        in>>nrmasinivd;
        cout<<endl;
        for(int i=0; i<nrmasinivd; i++)
        {
            v *a=new v;
            in>>*a;


            vand.push_back(a);

        }
    }

    Vanzare<v> operator -= ( const int i)
    {

        nrmasinivd++;
        vand.push_back(stoc[i]);
        nrmasinist--;
        stoc.erase(stoc.begin()+i);


        return*this;
    }

    void afisare (ostream &out)
    {



        out<<"\nNr masini in stoc ";
        out<<nrmasinist<<endl<<endl;
        if(nrmasinist>0)
            cout<<"Masini in stoc: "<<endl<<endl;
        for( int i =0; i<nrmasinist; i++)

            out<<*stoc[i]<<endl;
        out<<"\nNr masini vandute ";
        out<<nrmasinivd<<endl<<endl;
        if(nrmasinivd>0)
            cout<<"Masini vandute: "<<endl<<endl;
        for( int i =0; i<nrmasinivd; i++)
            out<<*vand[i]<<endl;



    }
    friend istream &operator>>(istream &in, Vanzare<v>& m)
    {
        m.citire(in);
        return in;
    }

    friend ostream &operator<<(ostream &out, Vanzare<v> &m)
    {
        m.afisare(out);
        return out;
    }

    void cumparare()
    {
        int x;
        for(int i=0; i<nrmasinist; i++)
        {
            cout<<i+1<<"."<<endl;
            cout<<*stoc[i];
        }
        cout<<"Ce masina doriti sa cumparati?(nr de ordine)";
        cin>>x;
        *this-=x-1;




    }

};
istream &operator>>(istream &in, masina& m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, masina& m)
{
    m.afisare(out);
    return out;

}
istream &operator>>(istream &in, MINI& m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, MINI& m)
{
    m.afisare(out);
    return out;
}
istream &operator>>(istream &in, MICA& m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, MICA& m)
{
    m.afisare(out);
    return out;
}

istream &operator>>(istream &in, COMPACTA& m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, COMPACTA& m)
{
    m.afisare(out);
    return out;
}

istream &operator>>(istream &in, MONOVOLUM& m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, MONOVOLUM& m)
{
    m.afisare(out);
    return out;
}


void tip(masina *&m, int &i)
{
    string tipm;
    cout<<"\n";
    cout<<"Introduceti tipul masinii:";
    cin>>tipm;
    try
    {
        if(tipm=="MINI")
        {
            m=new MINI;
            cin>>*m;
            i++;
        }
        else if(tipm=="MICA")
        {
            m=new MICA;
            cin>>*m;
            i++;
        }
        else if(tipm=="COMPACTA")
        {
            m=new COMPACTA;
            cin>>*m;
            i++;
        }
        else if(tipm=="MONOVOLUM")
        {
            m=new MONOVOLUM;
            cin>>*m;
            i++;
        }
        else
            throw tipm;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un post valid. ";
    }
}

template <> class Vanzare <MONOVOLUM>
{
private:
    int nrmasinist;
    int nrmasinivd;
    vector<MONOVOLUM*> stoc;
    vector<MONOVOLUM*> vand;
public:
    Vanzare(int nrmasinist=0,int nrmasinivd=0, MONOVOLUM *stoc1=NULL, MONOVOLUM *vand1=NULL)
    {
        for(int i=0; i<nrmasinist; i++)
        {
            stoc.push_back(&stoc1[i]);
            vand.push_back(&vand1[i]);
        }
        this->nrmasinist=nrmasinist;
        this->nrmasinivd=nrmasinivd;

    }
    Vanzare(Vanzare &m)
    {
        this->nrmasinist=m.nrmasinist;
        this->nrmasinivd=m.nrmasinivd;
        this-> stoc=  m.stoc;
        this->vand= m.vand;

    }
    Vanzare &operator = (Vanzare &m)
    {
        this->nrmasinist=m.nrmasinist;
        this->nrmasinivd=m.nrmasinivd;
        this-> stoc=  m.stoc;
        this->vand= m.vand;
        return*this;

    }
    ~Vanzare()
    {

    }

    void citire(istream &in)
    {
        cout<<"\nNr masini in stoc";
        in>>nrmasinist;
        cout<<endl;
        for(int i=0; i<nrmasinist; i++)
        {
            MONOVOLUM *a=new MONOVOLUM;
            in>>*a;

            stoc.push_back(a);


        }


        cout<<"\nNr masini vadute:";
        in>>nrmasinivd;
        cout<<endl;
        for(int i=0; i<nrmasinivd; i++)
        {
            MONOVOLUM *a=new MONOVOLUM;
            in>>*a;


            vand.push_back(a);

        }
    }
    void reducere(const int i)
    {
        time_t now= time(NULL);
        tm* data=localtime(&now);
        char *dataa=ctime(&now);
        cout<<"Data si ora: "<<dataa<<endl;
        if(1+data->tm_mon>=6&&1+data->tm_mon<=8)
        {
            cout<<"Felicitari! Beneficiati de o reducere de 10%"<<endl;
            int x= stoc[i]->get_pret();
            x==x-(10*stoc[i]->get_pret()/100);
        }
        else
        {
            cout<<"Ne pare rau! Nu beneficiati de reducerea de 10%"<<endl;
        }
    }
    Vanzare<MONOVOLUM> operator -= (const  int i)
    {

        nrmasinivd++;
        vand.push_back(stoc[i]);
        nrmasinist--;
        stoc.erase(stoc.begin()+i);


        return*this;
    }
    void cumparare()
    {
        int x;
        for(int i=0; i<nrmasinist; i++)
        {
            cout<<i+1<<"."<<endl;
            cout<<*stoc[i];
        }
        cout<<"Ce masina doriti sa cumparati?(Numarul de ordine)\n";
        cin>>x;
        cout<<endl;
        *this-=x-1;
        Vanzare<MONOVOLUM>::reducere(x);



    }
    void afisare (ostream &out)
    {



        out<<"Nr masini in stoc ";
        out<<nrmasinist<<endl<<endl;
        if(nrmasinist>0)
            cout<<"Masini in stoc: "<<endl<<endl;
        for( int i =0; i<nrmasinist; i++)
            out<<*stoc[i]<<endl;
        out<<"Nr masini vandute ";
        out<<nrmasinivd<<endl<<endl;
        if(nrmasinivd>0)
            cout<<"Masini vandute:"<<endl<<endl;
        for( int i =0; i<nrmasinivd; i++)
            out<<*vand[i]<<endl;



    }
    friend istream &operator>>(istream &in, Vanzare<MONOVOLUM>& m)
    {
        m.citire(in);
        return in;
    }

    friend ostream &operator<<(ostream &out, Vanzare<MONOVOLUM> &m)
    {
        m.afisare(out);
        return out;
    }
};

void menu_output()
{
    cout<<"\n Buzatu Andreea Sabina Grupa 253 - Proiect 3 - Nr proiect: 4  \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citirea a n masini, afisarea acestora si a numarului de masini citite folosind upcasting, variabile si functii statice";
    cout<<"\n";
    cout<<"2. Cate masini de fiecare fel au fost citite (dynamic cast) si daca este MONOVOLUM afiseaza pretul ( functie const )";
    cout<<"\n";
    cout<<"3. Template MINI";
    cout<<"\n";
    cout<<"4. Template MICA";
    cout<<"\n";
    cout<<"5.Template COMPACTA";
    cout<<"\n";
    cout<<"6. Template MONOVOLUM";
    cout<<"\n";
    cout<<"7. Cumpara o masina din cele citite anterior la punctele 3,4,5 sau 6!";
    cout<<"\n";

    cout<<"0. Iesire.";
    cout<<"\n";
}

void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;



    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        int n;
        masina **m;
        Vanzare <MINI> *a;
        Vanzare <MICA> *b;
        Vanzare <COMPACTA> *c;
        Vanzare <MONOVOLUM> *d;
        if (option==1)
        {

            cout<<"Numarul de masini:";
            cin>>n;


            m=new masina*[n];

            for(int i=0; i<n;)
                tip(m[i],i);
            cout<<"\nAfisam masinile citite anterior:\n";
            for(int i=0; i<n; i++)
            {
                cout<<"\n"<<*m[i];

            }
            cout<<"\nNumarul de masini este :";
            cout<< (*m)->nrmasini();

        }
        if (option==3)
        {
            a=new Vanzare <MINI>;
            cin>>*a;

            cout<<*a;

        }
        if (option==4)
        {
             b=new Vanzare <MICA>;
            cin>>*b;
            cout<<*b;

        }
        if (option==5)
        {
              c=new Vanzare <COMPACTA>;
            cin>>*c;
            cout<<*c;
        }
        if (option==6)
        {
            d= new Vanzare <MONOVOLUM> ;
            cin>>*d;
            cout<<*d;

        }


        if (option==7)
        {
            cout<<" De ce tip de masina sunteti interesat?\n";
            string x;
            cin>>x;
            if(x=="MINI")
            {
                a->cumparare();
                cout<<*a;
            }
            else if(x=="MICA")
               {

                b->cumparare();
                cout<<*b;}
            else if(x=="COMPACTA")
                {c->cumparare();
                cout<<*c;}
            else if(x=="MONOVOLUM")
               {

                d->cumparare();
                cout<<*d;}



        }
          if (option==2)
        {   double *p= new double[n];
            int nrmini=0,nrmica=0,nrcomp=0,nrmonovolum=0,j=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {
             MINI *x=dynamic_cast<MINI*>(m[i]);
             MICA *y=dynamic_cast<MICA*>(m[i]);
             COMPACTA *z=dynamic_cast<COMPACTA*>(m[i]);
              MONOVOLUM*t=dynamic_cast<MONOVOLUM*>(m[i]);
                if (x)
                    {nrmini++;}
                if (y)
                    nrmica++;
                if (z)
                    nrcomp++;
                if (t)
                    {nrmonovolum++;  p[j++]=t->get_pret();
            }}
            cout<<"Numarul de masini de tip MINI: "<<nrmini<<endl;
            cout<<"Numarul de masini de tip MICA: "<<nrmica<<endl;
            cout<<"Numarul de masini de tip COMPACTA: "<<nrcomp<<endl;
            cout<<"Numarul de masini de tip MONOVOLUM: "<<nrmonovolum<<endl;
            cout<<"Pretul monovolumelor:\n ";
            for(int i=0;i<j;i++)
                cout<<p[i]<<" ";
            }
            else{
                cout<<"Reveniti la actiunea 1.\n";
            }


        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>7)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}


int main()
{
    menu();
    return 0;
}
