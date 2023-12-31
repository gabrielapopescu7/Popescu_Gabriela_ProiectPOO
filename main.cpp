#include <iostream>
#include<fstream>
using namespace std;

class GradinaPlante {
private:
    string numeGradina;
    int nrPlante;
    float pretIntrare;
    static float TVABilet;
    const int anInfiintareGradina;
    int* durataViata;
public:
    string getNumeGradina()
    {
        return this->numeGradina;
    }
    void setNumeGradina(string numeGradina)
    {
        if (numeGradina.length() > 4) {
            this->numeGradina = numeGradina;
        }
    }

    int getnrPlante()
    {
        return this->nrPlante;
    }
    void setnrPlante(int nrPlante)
    {
        this->nrPlante = nrPlante;
    }

   float getPretIntrare()
    {
        return this->pretIntrare;
    }
    void setPretIntrare(float pretIntrare)
    {
       
            this->pretIntrare = pretIntrare;
    }

    static float getTVAbilet()

    {
        return TVABilet;
    }
  static void setTVAbilet ( float TVABilet)

    {
            GradinaPlante::TVABilet= TVABilet;
        
    }
  const int getanInfiintareGradina()
  {
      return this->anInfiintareGradina;
  }
  

    int* getdurataViata()
    {
        return this->durataViata;
    }
    int getdurataViata(int i) {
        return this->durataViata[i];
    }
    void setdurataViata(int* durataViata)
    {
        
            this->durataViata = durataViata;
    }


    void afisare() {
        cout << this->numeGradina << " " << this->nrPlante << " " << this->pretIntrare << " " << this->TVABilet << endl;
    }

    GradinaPlante() : anInfiintareGradina(1998) {
        this->numeGradina = "Gradina de Plante";
        this->nrPlante = 100;
        this->pretIntrare = 20;
        this->durataViata = new int[this->nrPlante]();
    }

    GradinaPlante(string numeGradina, int nrPlante, float pretIntrare, const int an, int* durataViata) : anInfiintareGradina(an) {
        this->numeGradina = numeGradina;
        this->nrPlante = nrPlante;
        this->pretIntrare = pretIntrare;
        this->durataViata = new int[this->nrPlante];
        for (int i = 0; i < this->nrPlante; i++)
            this->durataViata[i] = durataViata[i];
    }
    GradinaPlante(string numeGradina, int nrPlante, float pretIntrare):anInfiintareGradina(1998)
    {
        this->nrPlante = nrPlante;
        this->pretIntrare = pretIntrare;
        this->durataViata = new int[this->nrPlante];
         
    }

    GradinaPlante(const GradinaPlante& gp) : anInfiintareGradina(gp.anInfiintareGradina) {
        this->numeGradina = gp.numeGradina;
        this->nrPlante = gp.nrPlante;
        this->pretIntrare = gp.pretIntrare;
        this->durataViata = new int[this->nrPlante];
        for (int i = 0; i < this->nrPlante; i++)
            this->durataViata[i] = gp.durataViata[i];
    }
    int& operator[](int index) {
        if (index > 0 && index < nrPlante)
        {
            return this->durataViata[index];
            throw 404;
        }
    }
    GradinaPlante& operator=(const GradinaPlante& g)
    {
        if (this != &g) {
            this->numeGradina = g.numeGradina;
            this->nrPlante = g.nrPlante;
            this->pretIntrare = g.pretIntrare;
            if (this->durataViata != NULL) {
                delete[]this->durataViata;
            }
            this->durataViata = new int[this->nrPlante];
            for (int i = 0;i < this->nrPlante;i++)
            {
                this->durataViata[i] = g.durataViata[i];
            }
        }
        return *this;
    }
    bool operator<(GradinaPlante g)
    {
        return(this->nrPlante < g.nrPlante);
    }
    GradinaPlante operator++() {
        this->pretIntrare += 10;
        return *this;
    }
    GradinaPlante operator++(int)
    {
        GradinaPlante gp = *this;
        this->pretIntrare += 5;
        return gp;
    }

    ~GradinaPlante() {
        if (this->durataViata != nullptr) {
            delete[] this->durataViata;
            this->durataViata = nullptr;
        }
    }
    static void setTVABilet(float TVA)
    {
        TVABilet = TVA;
    }
    friend ostream& operator<<(ostream&, GradinaPlante);
    friend istream& operator>>(istream&, GradinaPlante&);
};

float GradinaPlante::TVABilet = 0.19;
class Tara {
private:
    string nume;
    int nrGradini;
    GradinaPlante* gradina;
public:
    string getNumeTara()
{
    return this->nume;
}
void setNumeTara(string nume)
{
        this->nume = nume;
}
int getNrGradini() {
    return this->nrGradini;
}
void stNrGradini(int nrGradini)
{
    this->nrGradini = nrGradini;
}
Tara() {
    this->nume = "Romania";
    this->nrGradini = 3;
    this->gradina = new GradinaPlante[3];
}
GradinaPlante& operator[](int index) {
    if (index >= 0 && index < this->nrGradini) {
        return this->gradina[index];
    }
    
    else {
        throw 404;
    }
    
}
friend bool operator<(Tara t1, Tara t2) {
    return t1.nrGradini < t2.nrGradini;
}

Tara operator++() {
    this->nrGradini += 1;
    return *this;
}
};
ostream& operator<<(ostream& out, GradinaPlante gp)
{
    out << "Nume gradina:" << gp.numeGradina<<endl;
    out << "Pret Intrare:" << gp.pretIntrare<<endl;
    out << "TVA-ul biletului:" << gp.TVABilet<<endl;
    out << "An infiintare gradina:" << gp.anInfiintareGradina<<endl;
    out << "Numar plante:" << gp.nrPlante<<endl;
    out << "Durata viata:";
    for(int i=0;i<gp.nrPlante;i++)
    {
        out << gp.durataViata[i] << " ";
    }
    
    out << endl;
    return out;
}


istream& operator>>(istream& in, GradinaPlante& gp)
{
    cout << "Nume gradina:"; in>> gp.numeGradina;
    cout << "Pret Intrare:"; in>> gp.pretIntrare;
    cout << "TVA-ul biletului:"; in>> gp.TVABilet;
    //cout << "An infiintare gradina:"; in >> gp.anInfiintareGradina;
    cout << "Numar plante";in >> gp.nrPlante;
    if(gp.durataViata!=nullptr)
    {
        delete[] gp.durataViata;
        gp.durataViata = nullptr;
    }
    gp.durataViata = new int[gp.nrPlante];
    cout << "Durata viata";
    for (int i = 0;i < gp.nrPlante;i++)
    {
        in>> gp.durataViata[i];
    }
    return in;

}
class Flori {
private:
    int nrFlori;
    string denumire;
    string culoare;
    int* codFloare;
    static int pretMinim;
    const string lunaPlantare;
public:
    int getnrFlori()
    {
        return this->nrFlori;
    }
    void setnrFlori(int nrFlori)
    {

        this->nrFlori = nrFlori;;

    }

    string getDenumire()
    {
        return this->denumire;
    }
    void setDenumire(string denumire)
    {
        if (denumire.length() > 2) {
            this->denumire = denumire;
        }
    }

    string getCuloare()
    {
        return this->culoare;
    }
    void setCuloare(string culoare)
    {

        this->culoare = culoare;

    }

    int* getcodFloare()
    {
        return this->codFloare;
    }
    int getcodFloare(int i) {
        return this->codFloare[i];
    }
    void setcodFloare(int* codFloare)
    {

        this->codFloare = codFloare;
    }

    static int getpretMinim()

    {
        return pretMinim;
    }
    static void setpretMinim(int pretMinim)

    {
        Flori::pretMinim = pretMinim;

    }
    const string getlunaPlantare()
    {
        return this->lunaPlantare;
    }

    void afisare() {
        cout << this->nrFlori << " " << this->denumire << " " << this->culoare << " " << this->pretMinim << endl;
    }

    Flori() : lunaPlantare("mai") {
        this->nrFlori = 1;
        this->denumire = "lalea";
        this->culoare = "galben";
        this->codFloare = new int[this->nrFlori]();
        this->codFloare[0] = 11;
    }

    Flori(string denumire, string culoare, const string luna, int nrFlori, int* codFloare) : lunaPlantare(luna) {
        this->denumire = denumire;
        this->culoare = culoare;
        this->nrFlori = nrFlori;
        this->codFloare = new int[this->nrFlori];
        for (int i = 0; i < this->nrFlori; i++)
            this->codFloare[i] = codFloare[i];
    }
    Flori(string denumire, string culoare) : lunaPlantare("mai") {
        this->denumire = denumire;
        this->culoare = culoare;

    }

    Flori(const Flori& f) : lunaPlantare(f.lunaPlantare) {
        this->nrFlori = f.nrFlori;
        this->denumire = f.denumire;
        this->culoare = f.culoare;
        this->codFloare = new int[this->nrFlori];
        for (int i = 0; i < this->nrFlori; i++)
            this->codFloare[i] = f.codFloare[i];
    }
    int& operator[](int index) {
        if (index > 0 && index < nrFlori)
        {
            return this->codFloare[index];
            throw 404;
        }
    }
    Flori& operator=(const Flori& f)
    {
        if (this != &f)
        {
            this->denumire = f.denumire;
            this->culoare = f.culoare;
            this->nrFlori = f.nrFlori;

            if (this->codFloare != NULL)
            {
                delete[]this->codFloare;
            }
            this->codFloare = new int[this->nrFlori];
            for (int i = 0;i < this->nrFlori;i++)
            {
                this->codFloare[i] = f.codFloare[i];
            }
        }
        return*this;

    }
    int operator()(int x) {
        return nrFlori + x;
    }

    bool operator<(Flori f)
    {
        return (this->nrFlori < f.nrFlori);
    }
    bool operator!()
    {
        return nrFlori == 0;
    }

    ~Flori() {
        if (this->codFloare != nullptr) {
            delete[] this->codFloare;
            this->codFloare = nullptr;
        }
    }
    /*static void setpretMinim(int pretNou )
    {
        pretMinim= pretNou;
    }*/
    friend ostream& operator<<(ostream& out, Flori&f) {
        out << "Numar flori:" << f.nrFlori << endl;
        out << "Denumire:" << f.denumire << endl;
        out << "Culoare:" << f.culoare << endl;
        out << "Pret minim:" << f.pretMinim << endl;
        out << "Cod floare: ";
        for (int i = 0;i < f.nrFlori;i++)
        {
            out << f.codFloare[i] << " ";
        }

        out << endl;
        return out;
    }
    friend ofstream& operator<<(ofstream& out, const Flori& f) {
        out << f.nrFlori << endl;
        out << f.denumire << endl;
        out << f.culoare << endl;
        out << f.pretMinim << endl;
        out << "Cod floare: ";
        for (int i = 0;i < f.nrFlori;i++)
        {
            out<< f.codFloare[i] << " ";
        }

    }

    friend istream& operator>>(istream&in, Flori&f)
        {
            cout << "Numar flori:"; in >> f.nrFlori;
            cout << "Denumire:"; in >> f.denumire;
            cout << "Culoare:"; in >> f.culoare;
            cout << "Pret minim:"; in >> f.pretMinim;
            if (f.codFloare != nullptr)
            {
                delete[] f.codFloare;
                f.codFloare = nullptr;
            }
            f.codFloare = new int[f.nrFlori];
            cout << "COD:";
            for (int i = 0;i < f.nrFlori;i++)
            {
                in >> f.codFloare[i];
            }
            return in;

        }
    friend ifstream& operator>>(ifstream& in, Flori& f)
    {
        in >> f.nrFlori; cout << endl;
        in >> f.denumire;cout << endl;
        in >> f.culoare;cout << endl;
        in >> f.pretMinim; cout << endl;
        if (f.codFloare != nullptr)
        {
            delete[] f.codFloare;
            f.codFloare = nullptr;
        }
        f.codFloare = new int[f.nrFlori];
        cout << endl;
        for (int i = 0;i < f.nrFlori;i++)
        {
            in >> f.codFloare[i];
        }
        return in;

    }
    
};

int Flori::pretMinim = 5;






class Arbori {
private:
    string specie;
    float inaltime;
    int* varsta;
    int nrArbori;
    static float inaltimeMinima;
    const string ziPlantare;
public:
    string getSpecie()
    {
        return this->specie;
    }
    void setSpecie(string specie)
    {
        if (specie.length() > 3) {
            this->specie= specie;
        }
    }
    
    float getinaltime()
    {
        return this->inaltime;
    }
    void setinaltime(float inaltime)
    {

        this->inaltime = inaltime;
    }
    int* getVarsta()
    {
        return this->varsta;
    }
    int getVarsta(int i) {
        return this->varsta[i];
    }
 
    void setVarsta(int* varsta)
    {

        this->varsta= varsta;
    }
 
    int getnrArbori()
    {
        return this->nrArbori;
    }
    void setnrArbori(int nrArbori)
    {

        this->nrArbori = nrArbori;

    }

    static float getinaltimeMinima()

    {
        return inaltimeMinima;
    }
    static void set(float inaltimeMinima)

    {
        Arbori::inaltimeMinima = inaltimeMinima;

    }
    const string getziPlantare()
    {
        return this->ziPlantare;
    }

    void afisare() {
    
        cout << this->specie << " " << this->inaltime << " " << this->ziPlantare << endl;
    }

    Arbori() : ziPlantare("luni") {
        this->specie = "stejar";
        this->inaltime = 17.5;
        this->nrArbori = 1;
        this->varsta = new int[this->nrArbori]();
        this->varsta[0] = 10;
    }

    Arbori(string specie, float inaltime, int nrArbori, int* varsta, const string zi) : ziPlantare(zi) {
        this->specie = specie;
        this->inaltime = inaltime;
        this->nrArbori = nrArbori;
        this->varsta = new int[this->nrArbori];
        for (int i = 0; i < this->nrArbori; i++)
            this->varsta[i] = varsta[i];
        
    }
    Arbori(string specie, float inaltime, int nrArbori) : ziPlantare("marti") {
        this->specie = specie;
        this->inaltime = inaltime;
        this->nrArbori = nrArbori;
        
    }

    Arbori(const Arbori& a) : ziPlantare(a.ziPlantare) {
        this->specie = a.specie;
        this->inaltime = a.inaltime;
        this->nrArbori = a.nrArbori;
        this->varsta = new int[this->nrArbori];
        for (int i = 0; i < this->nrArbori; i++)
            this->varsta[i] = a.varsta[i];
    }
    int& operator[](int index) {
        if (index > 0 && index < nrArbori)
        {
            return this->varsta[index];
            throw 404;
        }
    }
    Arbori& operator=(const Arbori& a)
    {
        if(this!=&a)
        {
            this->specie = a.specie;
            this->inaltime = a.inaltime;
            this->nrArbori = a.nrArbori;
            if (this->varsta != NULL)
            {
                delete[]this->varsta;
            }
            this->varsta = new int[this->nrArbori];
            for (int i = 0; i < this->nrArbori; i++)
            {
                this->varsta[i] = a.varsta[i];
            }
        }
        return*this;
    }
    bool operator||(const Arbori& in)
    {  
        return(nrArbori > 0) || (in.nrArbori > 0);
    }
    Arbori operator--(int) {
        Arbori rez = *this;  
        nrArbori--;  
        return rez; 
    }
    bool operator&&(const Arbori& h)
    {
        return this->inaltime && h.inaltime;
    }
    ~Arbori() {
        if (this->varsta != nullptr) {
            delete[] this->varsta;
            this->varsta = nullptr;
        }
    }
    static void setinaltimeMinima(float inaltime)
    {
        inaltimeMinima= inaltime;
    }

    friend ostream& operator<<(ostream&, Arbori);
    friend istream& operator>>(istream&, Arbori&);
};

float Arbori::inaltimeMinima = 0.2;
ostream& operator<<(ostream& out, Arbori a)
{
    out << "Specie:" << a.specie << endl;
    out << "Inaltime:" << a.inaltime<< endl;
    out << "Numr Arbori:" << a.nrArbori << endl;
    
    out << "Varsta: ";
    for (int i = 0;i < a.nrArbori;i++)
    {
        out << a.varsta[i] << " ";
    }

    out << endl;
    out << "Zi de plantare:" << a.ziPlantare<<endl;
    return out;

}
istream& operator>>(istream& in, Arbori& a)
{
    cout << "Specie:"; in>> a.specie ;
    cout << "Inaltime:"; in>>a.inaltime;
    cout << "Numr Arbori:"; in>>a.nrArbori;
    if (a.varsta != nullptr)
    {
        delete[] a.varsta;
        a.varsta = nullptr;
    }
    a.varsta = new int[a.nrArbori];
  
    for (int i = 0;i < a.nrArbori;i++)
    {
        cout << "Varsta:";
        in >> a.varsta[i];
    }
    return in;

}
//
//int main() {
//    GradinaPlante Gradina;
//    Gradina.afisare();
//    int* durataviata = new int[2]{2, 4};;
//    durataviata[0] = 2;
//    durataviata[1] = 4;
//    GradinaPlante Gradina2("Botanica", 2, 20, 1990, durataviata);
//    Gradina2.afisare();
//    GradinaPlante Gradina3 = Gradina2;
//    Gradina3.afisare();
//    GradinaPlante Gradina4("Japoneza", 34, 12);
//    Gradina4.afisare();
//
//    Flori flori;
//    flori.afisare();
//    int* vectorDeCoduri = new int[2] {111, 112};
//    vectorDeCoduri[0] = 111;
//    vectorDeCoduri[1] = 112;
 /*   Flori flori2("Trandafir", "rosu", "mai", 2, vectorDeCoduri);
    flori2.afisare();
    Flori flori3 = flori2;
    flori3.afisare();
    Flori flori4("Lalea", "alb");
    flori4.afisare();

    Arbori arbori;
    arbori.afisare();
    int* varste = new int[2]{10, 6};
    varste[0] = 10;
    varste[1] = 6;
    Arbori arbori2("brad", 35.5, 2, varste, "joi");
    arbori2.afisare();
    Arbori arbori3 = arbori2;
    arbori3.afisare();
    Arbori arbori4("salcam", 21.7, 20);
    arbori4.afisare();
    cout << arbori.getinaltime();

    cout << flori;*/

    // cin >> arbori;


   /* cout << "-------------------------------------";
    cout << endl;
    cout << arbori << endl;

    cout << "-------------------------------------" << endl;
    cout << Gradina.getNumeGradina() << endl;
    cout << Gradina.getnrPlante() << endl;
    cout << Gradina.getPretIntrare() << endl;
    cout << Gradina.getTVAbilet() << endl;
    cout << Gradina.getanInfiintareGradina() << endl;

    cout << "---------------------------------------" << endl;
    cout << flori.getDenumire() << endl;
    cout << flori.getCuloare() << endl;
    cout << flori.getlunaPlantare() << endl;
    cout << flori.getnrFlori() << endl;
    cout << flori.getpretMinim() << endl;

    cout << "-----------------------------------------" << endl;
    cout << arbori.getinaltime() << endl;
    cout << arbori.getnrArbori() << endl;
    cout << arbori.getinaltimeMinima() << endl;
    cout << arbori.getSpecie() << endl;


     cin >> Gradina;
     cout << Gradina << endl;
     cin >> flori;
     cout << flori << endl;
     cin >> arbori;
     cout << endl;
     cout << arbori << endl;


    GradinaPlante Gradina5;
    Gradina5 = Gradina2;
    cout << Gradina5 << endl;

    if (Gradina4 < Gradina2) {
        cout << "Gradina4 are < plante decat Gradina2." << endl;
    }
    else {
        cout << "Gradina4 are >=  de plante decat Gradina2." << endl;
    }
    cout << endl;
    GradinaPlante Gradina6;
    GradinaPlante Gradina7;
    Gradina6 = Gradina5++;
    cout << Gradina6 << endl;
    cout << Gradina5 << endl;
    Gradina7 = ++Gradina5;
    cout << Gradina7 << endl;


    Flori flori5;
    flori5 = flori2;
    cout << flori5;
   
    int x = flori2(2);
    cout << "valoarea lui x este:"<<x<<endl;
    
    
    if (flori4 < flori2)
    {
        cout << "flori4 are mai putine flori";
    }
    else
    {
        cout << "flori2 are mai putine flori";
    }
    cout << endl;
    if (!flori2) {
        cout << "flori2 nu are flori." << endl;
    }
    else {
        cout << "flori2 are flori." << endl;
    }
    cout << endl;
    Arbori arbori5;
    arbori5 = arbori2;
    cout << arbori5 << endl;
    if (arbori4 || arbori2)
    {
        cout << " cel putin unul dintre arbori are un numar mai mare de 0 arbori";
    }
    else
    {
        cout << "Ambele obiecte Arbori au numarul de arbori egal cu 0";
    }
    cout << endl;
    Arbori arbori7;
    arbori7 = arbori5--;
    cout << arbori7 << endl;
    if (arbori7 && arbori2) {
        cout << "Ambii arbori au inaltimi nenule." << endl;
    }
    else {
        cout << "Cel putin unul dintre arbori are inaltimea zero." << endl;
    }*/

    //const int numarGradini = 3;
    //GradinaPlante gradini[numarGradini] = {
    //    GradinaPlante("Gradina1", 10.0, 2000, 5, durataviata ),
    //    GradinaPlante("Gradina2", 15.0, 2010, 3, durataviata),
    //    GradinaPlante("Gradina3", 12.0, 2005, 4, durataviata ) 
    //};
    //GradinaPlante::setTVABilet(0.21);
    //for (int i = 0; i < numarGradini; i++) {
    //    cout << "Gradina " << gradini[i].getanInfiintareGradina() << ": " << gradini[i].getPretIntrare() << " lei cu TVA\n";
    //}

    //const int numarFlori = 2;
    //Flori flori[numarFlori] = {
    //    Flori("Trandafir", "rosu", "mai", 2, vectorDeCoduri),
    //    Flori("Lalele", "Galben","aprilie",3, vectorDeCoduri)
    //  
    //};
    //for (int i = 0; i < numarFlori; i++) {
    //    cout << "Florile " << flori[i] << " au pretul minim de " << Flori::getpretMinim() << " lei\n";
    //}
    //const int numarArbori = 2;
    //Arbori arbori[numarArbori] = {
    //    Arbori("brad", 35.5, 2, varste, "joi"),
    //    Arbori("pin", 22.0,1,varste,"vineri")
    //};
    //Arbori::setinaltimeMinima(1.8);
    //for (int i = 0; i < numarArbori; ++i) {
    //    cout << "Arborii de specia " << arbori[i] << " au inaltimea minima de " << Arbori::getinaltimeMinima() << " metri\n";
    //}
    //const int n = 3;
    //const int m = 2;
    //GradinaPlante gradini[n][m] = {
    //    { GradinaPlante("Gradina1", 20.0, 2000, 3, durataviata),
    //      GradinaPlante("Gradina2", 25.5, 2010, 2, durataviata)},
    //    { GradinaPlante("Gradina3", 18.0, 1998, 4, durataviata),
    //      GradinaPlante("Gradina4", 22.8, 2005, 1, durataviata) },
    //    { GradinaPlante("Gradina5", 30.0, 2015, 5, durataviata),
         // GradinaPlante("Gradina6", 28.3, 2008, 3, durataviata) }
//    };
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//    
//            cout << "Afi?are GradinaPlante [" << i << "][" << j << "]\n";
//            //gradini[i][j].afisare();
//        }
//        
//    }
//
//
//
//    delete[] durataviata;
//    delete[] varste;
//}

int main() {
    GradinaPlante Gradina;
    cout << Gradina << endl;

    int* durataviata = new int[2] {2, 4};
    GradinaPlante Gradina2("Botanica", 2, 20, 1990, durataviata);
    cout << Gradina2 << endl;

    GradinaPlante Gradina3 = Gradina2;
    cout << Gradina3 << endl;

    GradinaPlante Gradina4("Japoneza", 34, 12);
    cout << Gradina4 << endl;

    Flori flori;
    cout << flori << endl;

    int* vectorDeCoduri = new int[2] {111, 112};
    Flori flori2("Trandafir", "rosu", "mai", 2, vectorDeCoduri);
    cout << flori2 << endl;

    Flori flori3 = flori2;
    cout << flori3 << endl;

    Flori flori4("Lalea", "alb");
    cout << flori4 << endl;

    Arbori arbori;
    cout << arbori << endl;

    int* varste = new int[2] {10, 6};
    Arbori arbori2("brad", 35.5, 2, varste, "joi");
    cout << arbori2 << endl;

    Arbori arbori3 = arbori2;
    cout << arbori3 << endl;

    Arbori arbori4("salcam", 21.7, 20);
    cout << arbori4 << endl;

    cout << arbori.getinaltime() << endl;

    cout << flori;

    cout << "-------------------------------------" << endl;
    cout << arbori << endl;

    cout << "-------------------------------------" << endl;
    cin >> Gradina;
    cout << Gradina << endl;

    cin >> flori;
    cout << flori << endl;

    cin >> arbori;
    cout << arbori << endl;

    GradinaPlante Gradina5;
    Gradina5 = Gradina2;
    cout << Gradina5 << endl;

    if (Gradina4 < Gradina2) {
        cout << "Gradina4 are < plante decat Gradina2." << endl;
    }
    else {
        cout << "Gradina4 are >= de plante decat Gradina2." << endl;
    }

    cout << endl;

    GradinaPlante Gradina6;
    GradinaPlante Gradina7;
    Gradina6 = Gradina5++;
    cout << Gradina6 << endl;
    cout << Gradina5 << endl;

    Gradina7 = ++Gradina5;
    cout << Gradina7 << endl;

    Flori flori5;
    flori5 = flori2;
    cout << flori5;

    int x = flori2(2);
    cout << "valoarea lui x este: " << x << endl;

    if (flori4 < flori2) {
        cout << "flori4 are mai putine flori" << endl;
    }
    else {
        cout << "flori2 are mai putine flori" << endl;
    }

    cout << endl;

    if (!flori2) {
        cout << "flori2 nu are flori." << endl;
    }
    else {
        cout << "flori2 are flori." << endl;
    }

    cout << endl;

    Arbori arbori5;
    arbori5 = arbori2;
    cout << arbori5 << endl;

    if (arbori4 || arbori2) {
        cout << " cel putin unul dintre arbori are un numar mai mare de 0 arbori" << endl;
    }
    else {
        cout << "Ambele obiecte Arbori au numarul de arbori egal cu 0" << endl;
    }

    cout << endl;

    Arbori arbori7;
    arbori7 = arbori5--;
    cout << arbori7 << endl;

    if (arbori7 && arbori2) {
        cout << "Ambii arbori au inaltimi nenule." << endl;
    }
    else {
        cout << "Cel putin unul dintre arbori are inaltimea zero." << endl;
    }

    const int numarGradini = 3;
    GradinaPlante gradini[numarGradini] = {
        GradinaPlante("Gradina1", 10.0, 2000, 5, durataviata),
        GradinaPlante("Gradina2", 15.0, 2010, 3, durataviata),
        GradinaPlante("Gradina3", 12.0, 2005, 4, durataviata)
    };

    GradinaPlante::setTVABilet(0.21);

    for (int i = 0; i < numarGradini; ++i) {
        cout << gradini[i] << endl;
    }

    Flori f8;
    cin >> f8;
    ofstream file("fisier.txt", ios::out);
   /* file <<f8;*/

    ifstream citire("fisier.txt", ios::in);
    Flori f9;
    citire >> f9;
    cout << f9;

    Flori f10;
    citire >> f10;
    cout <<endl<< f10;

    char* text = new char[5];
    strcpy_s(text, 5, "text:");
    int variabila = 23;
    float valReala =24.5;
    fstream fisierBinar("fisierBinar.g59", ios::binary | ios::out);
    fisierBinar.close();

    Arbori a8;
    cin >> a8;
    ofstream file2("fisier.txt2", ios::out);
    file2 << a8;

    ifstream citire2("fisier.txt2", ios::in);
    Arbori a9;
    citire2 >> a9;
    cout << a9;

    char* text2= new char[4];
    strcpy_s(text, 4, "text:");
    int variabila2 = 22;
    float valReala2 = 23.5;
    fstream fisierBinar2("fisierBinar.gp", ios::binary | ios::out);
    fisierBinar2.close();

    delete[] durataviata;
    delete[] vectorDeCoduri;
    delete[] varste;

    return 0;
}

