#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;




class Floare {
private:
    string tip;
    const int id;
    int nrPlante;
    float* preturi;
    static int nrFlori;

public:
    Floare() : id(++nrFlori) {
        this->tip = "Necunoscuta";
        this->nrPlante = 0;
        this->preturi = nullptr;
    }

    Floare(string tip, int nrPlante, float* preturi) : id(++nrFlori) {
        this->tip = tip;
        this->nrPlante = nrPlante;
        this->preturi = new float[this->nrPlante];
        for (int i = 0; i < this->nrPlante; i++) {
            this->preturi[i] = preturi[i];
        }
 
    }
    Floare operator= (const Floare& f) {
        this->tip = f.tip;
        this->nrPlante = f.nrPlante;
        this->preturi = new float[f.nrPlante];
        for (int i = 0; i < f.nrPlante; i++) {
            this->preturi[i] = f.preturi[i];
        }
        return *this;
    }

    ~Floare() {
       // cout << endl << " S-a apelat destructorul!";
        if (this->preturi != NULL)
        {
            delete[] this->preturi;
        }
        
    }

    void afisareFloare() {
        cout << endl << "Floarea " <<
            this->tip << " , id-ul " << this->id
            << " are " << this->nrPlante << " plante si preturile sunt: ";
        for (int i = 0; i < this->nrPlante; i++) {
            cout << this->preturi[i] << " ";
        }
    }

    static int getNrFlori() {
        return nrFlori;
    }

    int getNrPlante() {
        return this->nrPlante;
    }

    void setNrPlante(int nouaValoare) {
        // Validari
        if (nouaValoare > 0) {
            this->nrPlante = nouaValoare;
        }
        else {
            throw exception();
        }
    }

    void setPreturi(float* preturiNoi) {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
        this->preturi = new float[this->nrPlante];
        for (int i = 0; i < this->nrPlante; i++) {
            this->preturi[i] = preturiNoi[i];
        }
        delete[] preturiNoi;
    }

    float* getPreturi() {
        return this->preturi;
    }
    friend ostream& operator<<(ostream& out, const Floare& floare) {
        out << "\nTip: " << floare.tip;
        out << "\nId: " << floare.id;
        out << "\nNr Plante: " << floare.nrPlante;
        for (int i = 0; i < floare.nrPlante; i++) {
            cout << floare.preturi[i] <<",";
        }
        out << "\nnrFlori: " << floare.nrFlori;
        return out;
    }
};

int Floare::nrFlori = 0;

enum NrPetale
{
    par, impar
};

class FloareDeInterior : public Floare {
private:
    char* nume;
    int nrCuloriPetale;
    int nrInaltimi;
    float* inaltimi;
    string* culoriPetale;
    const int id;
    NrPetale nrPetale;
    bool carinivora;
    float dimensiuneGhiveci;
    string culoareGhivechi;

public:
    float getDimensiuneGhivechi() {
        return dimensiuneGhiveci;
    }
    char* getNume() {
        return this->nume;
    }
    void setNume( const char* nume) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    void setCuloriPetale(string* culoriPetale, int nrCulori) {

        if (this->culoriPetale != NULL)
        {
            delete[] this->culoriPetale;
        }
        this->nrCuloriPetale = nrCulori;
        this->culoriPetale = new string[this->nrCuloriPetale];
        for (int i = 0; i < nrCulori; i++)
        {
            this->culoriPetale[i] = culoriPetale[i];
        }
    }



    FloareDeInterior() : id(0),Floare(){
        this->nume = new char[strlen("muscata")+1];
        strcpy_s(this->nume, strlen("muscata ") + 1, "muscata");
        this->nrCuloriPetale = 0;
        this->nrInaltimi = 0;
        this-> inaltimi = NULL;
        this->culoriPetale = NULL;
        this->nrPetale = par;
        this->carinivora = false;
        this-> dimensiuneGhiveci = 0;
        this->culoareGhivechi = " ";

    }
    FloareDeInterior(int nrCuloriPetale, int nrInaltimi, float* inaltimi, string * culoriPertale) : id(1), Floare() {
        this->nrCuloriPetale = nrCuloriPetale;
        this->nrInaltimi = nrInaltimi;
        this->inaltimi = new float[nrInaltimi];
        for (int i = 0; i < nrInaltimi; i++) {
            this->inaltimi[i] = inaltimi[i];
        }
        this->culoriPetale = new string[nrCuloriPetale];
        for (int i = 0; i < nrCuloriPetale; i++) {
            this->culoriPetale[i] = culoriPertale[i];
        }
        this->nrPetale = impar;
        this->carinivora = true;
        this->dimensiuneGhiveci = 40;
        this->culoareGhivechi = "maro";

    }
    FloareDeInterior(int nrCuloriPetale, int nrInaltimi, float* inaltimi, string* culoriPertale, float dimensiuneGhiveci) : id(1), Floare() {
        this->nrCuloriPetale = nrCuloriPetale;
        this->nrInaltimi = nrInaltimi;
        this->inaltimi = new float[nrInaltimi];
        for (int i = 0; i < nrInaltimi; i++) {
            this->inaltimi[i] = inaltimi[i];
        }
        this->culoriPetale = new string[nrCuloriPetale];
        for (int i = 0; i < nrCuloriPetale; i++) {
            this->culoriPetale[i] = culoriPertale[i];
        }
        this->nrPetale = impar;
        this->carinivora = true;
        this->dimensiuneGhiveci = dimensiuneGhiveci;
        this->culoareGhivechi = "negru";

    }
    FloareDeInterior(const FloareDeInterior& f) :id(f.id), Floare(f) {
        if (this != &f) {

            this->nrCuloriPetale = f.nrCuloriPetale;
            this->nrInaltimi = f.nrInaltimi;
            this->inaltimi = new float[f.nrInaltimi];
            for (int i = 0; i < f.nrInaltimi; i++) {
                this->inaltimi[i] = f.inaltimi[i];
            }
            this->culoriPetale = new string[f.nrCuloriPetale];
            for (int i = 0; i < f.nrCuloriPetale; i++) {
                this->culoriPetale[i] = f.culoriPetale[i];
            }
            this->nrPetale = f.nrPetale;
            this->carinivora = f.carinivora;
            this->dimensiuneGhiveci = f.dimensiuneGhiveci;
            this->culoareGhivechi = f.culoareGhivechi;
        }
    }
    FloareDeInterior operator=(const FloareDeInterior& f) {
        if (this != &f) {
            if (this->inaltimi != NULL)
            {
                delete[] this->inaltimi;
            }
            if (this->culoriPetale != NULL)
            {
                delete[] this->culoriPetale;
            }
            Floare::operator=(f);
            this->nrCuloriPetale = f.nrCuloriPetale;
            this->nrInaltimi = f.nrInaltimi;
            this->inaltimi = new float[f.nrInaltimi];
            for (int i = 0; i < f.nrInaltimi; i++) {
                this->inaltimi[i] = f.inaltimi[i];
                std::copy(f.inaltimi, f.inaltimi + f.nrInaltimi, this->inaltimi);

            }
            this->culoriPetale = new string[f.nrCuloriPetale];
            for (int i = 0; i < f.nrCuloriPetale; i++) {
                this->culoriPetale[i] = f.culoriPetale[i];
                std::copy(f.culoriPetale, f.culoriPetale + f.nrCuloriPetale, this->culoriPetale);
            }
            this->nrPetale = f.nrPetale;
            this->carinivora = f.carinivora;
            this->dimensiuneGhiveci = f.dimensiuneGhiveci;
            this->culoareGhivechi = f.culoareGhivechi;
            return *this;
        }
        
    }
    friend ostream& operator<<(ostream& out, const FloareDeInterior& floareInterior) {
        out << "\nNumar culori petale: " << floareInterior.nrCuloriPetale;
        out << "\nCulorile sunt:";
        for (int i = 0; i < floareInterior.nrCuloriPetale; i++) {
            out << floareInterior.culoriPetale[i] << ",";
        }
        out << "\nInaltimile sunt:";
        out << "\nInaltimi: "<<floareInterior.nrInaltimi;
        for (int i = 0; i < floareInterior.nrInaltimi; i++) {
            out << floareInterior.inaltimi[i] << ",";
        }
        out << "\nnrPetale Par/Impar: " << floareInterior.nrPetale;
        out << "\nCarnivora: " << floareInterior.carinivora;
        out << "\nDimensiune ghivechi: " << floareInterior.dimensiuneGhiveci;
        out << "\nCuloare ghivechi: " << floareInterior.culoareGhivechi;
        out << (Floare)floareInterior;
        return out;
    }
    ~FloareDeInterior() {
        if (this->culoriPetale != NULL) {
            delete[]this->culoriPetale;
        }
        if (this->inaltimi != NULL) {
            delete[]this->inaltimi;
        }
        if (this->nume != NULL) {
            delete[]this->nume;
        }
    }
    void operator++() {
        ++this->dimensiuneGhiveci;
        return;
    }
    void operator+=(float addDimensiuneGhivechi) {
        this->dimensiuneGhiveci += addDimensiuneGhivechi;
        return;
    }
};


int main() {
    float* inaltimi = new float[2];
    inaltimi[0] = 0.25;
    inaltimi[1] = 0.4;

    string* culoriPetale = new string[2];
    culoriPetale[0] = "galben";
    culoriPetale[1] = "rosu";

    string* culoriPetale2 = new string[2];
    culoriPetale2[0] = "verde";
    culoriPetale2[1] = "portocaliu";

    Floare floare;
    floare.afisareFloare();



    Floare floare2("Trandafir", 3, new float[3] { 10.6f, 15.4f, 20.9f });
    floare2.afisareFloare();
    cout << "\n------------------------------------------------------------------------------------" << endl;

    cout << endl << Floare::getNrFlori();

    //delete[] floare2.getPreturi(); 
    FloareDeInterior floareInterior1;
    cout << floareInterior1;
    cout << "\n------------------------------------------------------------------------------------"<<endl;

    FloareDeInterior floareInterior2(2, 2, inaltimi, culoriPetale);
    cout << floareInterior2;
    cout << "\n------------------------------------------------------------------------------------" << endl;

    FloareDeInterior floareInterior3(1, 1, inaltimi, culoriPetale,30.4);
    cout << floareInterior3;
    cout << "\n------------------------------------------------------------------------------------" << endl;

    FloareDeInterior floareInterior4(floareInterior3);
    cout << floareInterior4;
    cout << "\n------------------------------------------------------------------------------------" << endl;

    cout << "\nOperator++\n";
    cout << floareInterior3.getDimensiuneGhivechi();
    ++floareInterior3;
    cout << "\n"<<floareInterior3.getDimensiuneGhivechi();;
    cout << "\n------------------------------------------------------------------------------------" << endl;

    cout << "\nOperator+=\n";
    cout << floareInterior3.getDimensiuneGhivechi();
    floareInterior3+=400;
    cout << "\n" << floareInterior3.getDimensiuneGhivechi();;
    cout << "\n------------------------------------------------------------------------------------" << endl;

    cout << "\nGet Dinamic\n";
    cout << floareInterior1.getNume();
    floareInterior1.setNume("\ntrandafir");
    cout << floareInterior1.getNume();
    cout << "\n------------------------------------------------------------------------------------" << endl;




    /*floareInterior4 = floareInterior1;
    cout << floareInterior4;
    cout << "\n------------------------------------------------------------------------------------" << endl;*/


    return 0;


}