
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class NegativnaVrednost
{
public:
    void message()
    {
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
};
class Oglas
{
private:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    double cena;
public:
    Oglas(const char *naslov="",const char *kategorija="",const char *opis="",double cena=0)
    {
        strcpy(this->naslov,naslov);
        strcpy(this->kategorija,kategorija);
        strcpy(this->opis,opis);
        this->cena=cena;
    }
    bool operator >(const Oglas &g)
    {
        return cena > g.cena;
    }
    friend ostream&operator<<(ostream &out,const Oglas &g)
    {
        out<<g.naslov<<endl;
        out<<g.opis<<endl;
        out<<g.cena<<" evra"<<endl;
        return out;
    }
    double getCena()
    {
        return cena;
    }
    char *getKategorija()
    {
        return kategorija;
    }
};
class Oglasnik
{
private:
    char ime[20];
    Oglas *niza;
    int broj;
public:
    Oglasnik(const char *ime="")
    {
        strcpy(this->ime,ime);
        niza=new Oglas[0];
        broj=0;
    }
    Oglasnik&operator+=(Oglas &g)
    {
        if(g.getCena() < 0)
        {
            throw NegativnaVrednost();
        }
        Oglas *temp=new Oglas[broj+1];
        for(int i=0;i<broj;i++)
        {
            temp[i]=niza[i];
        }
        temp[broj++]=g;
        delete[]niza;
        niza=temp;
        return *this;
    }
    friend ostream&operator<<(ostream &out,const Oglasnik &og)
    {
        out<<og.ime<<endl;
        for(int i=0;i<og.broj;i++)
        {
            cout<<og.niza[i]<<endl;
        }
        return out;
    }
    void oglasiOdKategorija(const char *k)
    {
        for(int i=0;i<broj;i++)
        {
            if(strcmp(niza[i].getKategorija(),k) == 0)
            {
                cout<<niza[i]<<endl;
            }
        }
    }
    void najniskaCena()
    {
        Oglas temp = niza[0];
        for(int i=1;i<broj;i++)
        {
            if(niza[i].getCena() < temp.getCena())
            {
                temp=niza[i];
            }
        }
        cout<<temp;
    }
};
int main()
{
  char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
        	try{
			ogl+=o;
        	}
        	catch(NegativnaVrednost &ne)
        	{
        	    ne.message();
        	}
        }
        cout<<ogl;

    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
        	try{
            ogl+=o;
        	}
        	catch(NegativnaVrednost &ne)
        	{
        	    ne.message();
        	}
        }
        cout<<ogl;

        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }
}
