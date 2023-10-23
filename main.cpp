#include <iostream>
using namespace std;

class GradinaPlante {
public:
    string numeGradina;
    int nrPlante;
    float pretIntrare;
    static float TVABilet;
    const int anInfiintareGradina;
    int* durataViata;

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
};

float GradinaPlante::TVABilet = 0.19;

class Flori {
public:
    int nrFlori;
    string denumire;
    string culoare;
    int* codFloare;
    static int pretMinim;
    const string lunaPlantare;

    void afisare() {
        cout << this->nrFlori << " " << this->denumire << " " << this->culoare << " " << this->pretMinim << endl;
    }

    Flori() : lunaPlantare("mai") {
        this->nrFlori = 45;
        this->denumire = "lalea";
        this->culoare = "galben";
        this->codFloare = new int[this->nrFlori]();
    }

    Flori(string denumire, string culoare, const string luna, int nrFlori, int* codFloare) : lunaPlantare(luna) {
        this->denumire = denumire;
        this->culoare = culoare;
        this->nrFlori = nrFlori;
        this->codFloare = new int[this->nrFlori];
        for (int i = 0; i < this->nrFlori; i++)
            this->codFloare[i] = codFloare[i];
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
};

int Flori::pretMinim = 5;

class Arbori {
public:
    string specie;
    float inaltime;
    int* varsta;
    int nrArbori;
    static float inaltimeMinima;
    const string ziPlantare;

    void afisare() {
        cout << this->specie << " " << this->inaltime << " " << this->ziPlantare << endl;
    }

    Arbori() : ziPlantare("luni") {
        this->specie = "stejar";
        this->inaltime = 17.5;
        this->nrArbori = 55;
        this->varsta = new int[this->nrArbori]();
    }

    Arbori(string specie, float inaltime, int nrArbori, int* varsta, const string zi) : ziPlantare(zi) {
        this->specie = specie;
        this->inaltime = inaltime;
        this->nrArbori = nrArbori;
        this->varsta = new int[this->nrArbori];
        for (int i = 0; i < this->nrArbori; i++)
            this->varsta[i] = varsta[i];
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
};

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

    Flori flori;
    flori.afisare();
    int* vectorDeCoduri = new int[2];
    vectorDeCoduri[0] = 111;
    vectorDeCoduri[1] = 112;
    Flori flori2("Trandafir", "rosu", "mai", 2, vectorDeCoduri);
    flori2.afisare();
    Flori flori3 = flori2;
    flori3.afisare();

    Arbori arbori;
    arbori.afisare();
    int* varste = new int[2];
    varste[0] = 1;
    varste[1] = 0;
    Arbori arbori2("brad", 35.5, 67, varste, "0.2");
    arbori2.afisare();
    Arbori arbori3 = arbori2;
    arbori3.afisare();

    delete[] durataviata;
    delete[] vectorDeCoduri;
    delete[] varste;

 
}
