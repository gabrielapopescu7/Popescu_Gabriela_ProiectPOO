#include <iostream>
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
            this->durataViata[i] = i;
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
ostream& operator<<(ostream& out, GradinaPlante gp)
{
    out << "Nume gradina:" << gp.numeGradina;
    out << "Pret Intrare:" << gp.pretIntrare;
    out << "TVA-ul biletului:" << gp.TVABilet;
    out << "An infiintare gradina:" << gp.anInfiintareGradina;
    out << "Numar plante:" << gp.nrPlante;
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
            this->denumire =denumire;
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

        this->codFloare =codFloare;
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
    friend ostream& operator<<(ostream&, Flori);
    friend istream& operator>>(istream&, Flori&);
};

int Flori::pretMinim = 5;
ostream& operator<<(ostream& out, Flori f)
{
    out << "Numar flori:" << f.nrFlori<<endl;
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
istream& operator>>(istream& in, Flori &f)
{
    cout << "Numar flori:"; in >> f.nrFlori;
    cout << "Denumire:"; in>> f.denumire;
    cout << "Culoare:"; in>>f.culoare;
    cout << "Pret minim:"; in>>f.pretMinim;
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

int main() {
    GradinaPlante Gradina;
    Gradina.afisare();
    int* durataviata = new int[2];
    durataviata[0] = 2;
    durataviata[1] = 4;
    GradinaPlante Gradina2("Botanica", 53, 20, 1990, durataviata);
    Gradina2.afisare();
    GradinaPlante Gradina3 = Gradina2;
    Gradina3.afisare();
    GradinaPlante Gradina4("Japoneza", 34, 12);
    Gradina4.afisare();

    Flori flori;
    flori.afisare();
    int* vectorDeCoduri = new int[2];
    vectorDeCoduri[0] = 111;
    vectorDeCoduri[1] = 112;
    Flori flori2("Trandafir", "rosu", "mai", 2, vectorDeCoduri);
    flori2.afisare();
    Flori flori3 = flori2;
    flori3.afisare();
    Flori flori4("Lalea", "alb");
    flori4.afisare();

    Arbori arbori;
    arbori.afisare();
    int* varste = new int[2];
    varste[0] = 10;
    varste[1] = 6;
    Arbori arbori2("brad", 35.5, 67, varste, "joi");
    arbori2.afisare();
    Arbori arbori3 = arbori2;
    arbori3.afisare();
    Arbori arbori4("salcam", 21.7, 20);
    arbori4.afisare();
    cout << arbori.getinaltime();
   
    cout << flori;

  // cin >> arbori;
   
 
    cout << "-------------------------------------";
    cout << endl;
    cout << arbori<<endl;

    cout << "-------------------------------------"<<endl;
    cout << Gradina.getNumeGradina() << endl;
    cout << Gradina.getnrPlante() << endl;
    cout << Gradina.getPretIntrare() << endl;
    cout << Gradina.getTVAbilet() << endl;
    cout << Gradina.getanInfiintareGradina() << endl;
    
    cout << "---------------------------------------" << endl;
    cout << flori.getDenumire() << endl;
    cout << flori.getCuloare() << endl;
    cout << flori.getlunaPlantare() << endl;
    cout << flori.getnrFlori()<<endl;
    cout << flori.getpretMinim()<<endl;

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
  
    delete[] durataviata;
    delete[] vectorDeCoduri;
    delete[] varste;
    
 
}
