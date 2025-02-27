#include <iostream>
#include <vector>
#include <string>

class Materie {
private:
    std::string denumire;
    float nota;

public:
    Materie(const std::string& denumire, float nota) : denumire(denumire), nota(nota) {}

    std::string getDenumire() const {
        return denumire;
    }

    float getNota() const {
        return nota;
    }

    bool areRestanta() const {
        return nota < 5.0; // Considerăm că nota sub 5 este restanță
    }
};

class Semestru {
private:
    std::vector<Materie> materii;

public:
    void adaugaMaterie(const Materie& materie) {
        materii.push_back(materie);
    }

    void scoateMaterie(const std::string& denumire) {
        for (size_t i = 0; i < materii.size(); ++i) {
            if (materii[i].getDenumire() == denumire) {
                materii.erase(materii.begin() + i);
                break;
            }
        }
    }

    float notaMaxima() const {
        float maxNota = 0.0;
        for (const auto& materie : materii) {
            if (materie.getNota() > maxNota) {
                maxNota = materie.getNota();
            }
        }
        return maxNota;
    }

    float notaMinima() const {
        if (materii.empty()) return 0.0;
        float minNota = materii[0].getNota();
        for (const auto& materie : materii) {
            if (materie.getNota() < minNota) {
                minNota = materie.getNota();
            }
        }
        return minNota;
    }

    float media() const {
        if (materii.empty()) return 0.0;
        float suma = 0.0;
        for (const auto& materie : materii) {
            suma += materie.getNota();
        }
        return suma / materii.size();
    }

    void afiseazaRestante() const {
        for (const auto& materie : materii) {
            if (materie.areRestanta()) {
                std::cout << materie.getDenumire() << " ";
            }
        }
        std::cout << std::endl;
    }

    const std::vector<Materie>& getMaterii() const {
        return materii;
    }
};

class An {
private:
    std::vector<Semestru> semestre;

public:
    void adaugaSemestru(const Semestru& semestru) {
        semestre.push_back(semestru);
    }

    void scoateSemestru(int index) {
        if (index >= 0 && index < semestre.size()) {
            semestre.erase(semestre.begin() + index);
        }
    }

    float notaMaxima() const {
        float maxNota = 0.0;
        for (const auto& semestru : semestre) {
            float semNotaMax = semestru.notaMaxima();
            if (semNotaMax > maxNota) {
                maxNota = semNotaMax;
            }
        }
        return maxNota;
    }

    float notaMinima() const {
        if (semestre.empty()) return 0.0;
        float minNota = semestre[0].notaMinima();
        for (const auto& semestru : semestre) {
            float semNotaMin = semestru.notaMinima();
            if (semNotaMin < minNota) {
                minNota = semNotaMin;
            }
        }
        return minNota;
    }

    void afiseazaRestante() const {
        for (const auto& semestru : semestre) {
            semestru.afiseazaRestante();
        }
    }

    float media() const {
        float suma = 0.0;
        int numarMaterii = 0;
        for (const auto& semestru : semestre) {
            suma += semestru.media() * semestru.getMaterii().size();
            numarMaterii += semestru.getMaterii().size();
        }
        return numarMaterii > 0 ? suma / numarMaterii : 0.0;
    }

    const std::vector<Semestru>& getSemestre() const {
        return semestre;
    }
};

class GestiuneNote {
private:
    std::vector<An> ani;

public:
    void adaugaAn(const An& an) {
        ani.push_back(an);
    }

    void scoateAn(int index) {
        if (index >= 0 && index < ani.size()) {
            ani.erase(ani.begin() + index);
        }
    }

    float notaMaxima() const {
        float maxNota = 0.0;
        for (const auto& an : ani) {
            float anNotaMax = an.notaMaxima();
            if (anNotaMax > maxNota) {
                maxNota = anNotaMax;
            }
        }
        return maxNota;
    }

    float notaMinima() const {
        if (ani.empty()) return 0.0;
        float minNota = ani[0].notaMinima();
        for (const auto& an : ani) {
            float anNotaMin = an.notaMinima();
            if (anNotaMin < minNota) {
                minNota = anNotaMin;
            }
        }
        return minNota;
    }

    float media() const {
        float suma = 0.0;
        int numarMaterii = 0;
        for (const auto& an : ani) {
            suma += an.media() * an.getSemestre().size();
            numarMaterii += an.getSemestre().size();
        }
        return numarMaterii > 0 ? suma / numarMaterii : 0.0;
    }

    void afiseazaRestante() const {
        for (const auto& an : ani) {
            an.afiseazaRestante();
        }
    }

    // Funcții pentru a obține nota maximă, minimă, media și restanțele pentru un an și un semestru specific
    float notaMaximaAn(int index) const {
        if (index >= 0 && index < ani.size()) {
            return ani[index].notaMaxima();
        }
        return 0.0;
    }

    float notaMinimaAn(int index) const {
        if (index >= 0 && index < ani.size()) {
            return ani[index].notaMinima();
        }
        return 0.0;
    }

    float mediaAn(int index) const {
        if (index >= 0 && index < ani.size()) {
            return ani[index].media();
        }
        return 0.0;
    }

    void afiseazaRestanteAn(int index) const {
        if (index >= 0 && index < ani.size()) {
            ani[index].afiseazaRestante();
        }
    }

    float notaMaximaSemestru(int anIndex, int semestruIndex) const {
        if (anIndex >= 0 && anIndex < ani.size()) {
            const auto& semestru = ani[anIndex].getSemestre();
            if (semestruIndex >= 0 && semestruIndex < semestru.size()) {
                return semestru[semestruIndex].notaMaxima();
            }
        }
        return 0.0;
    }

    float notaMinimaSemestru(int anIndex, int semestruIndex) const {
        if (anIndex >= 0 && anIndex < ani.size()) {
            const auto& semestru = ani[anIndex].getSemestre();
            if (semestruIndex >= 0 && semestruIndex < semestru.size()) {
                return semestru[semestruIndex].notaMinima();
            }
        }
        return 0.0;
    }

    float mediaSemestru(int anIndex, int semestruIndex) const {
        if (anIndex >= 0 && anIndex < ani.size()) {
            const auto& semestru = ani[anIndex].getSemestre();
            if (semestruIndex >= 0 && semestruIndex < semestru.size()) {
                return semestru[semestruIndex].media();
            }
        }
        return 0.0;
    }
};

int main() {
    // Exemplu de utilizare a claselor
    GestiuneNote gestiune;

    // Crearea anului 1
    An an1;
    Semestru sem1;
    sem1.adaugaMaterie(Materie("Bazele Tehnologiei Informatiei", 8.5));
    sem1.adaugaMaterie(Materie("Bazele programării calculatoarelor", 9.0));
    sem1.adaugaMaterie(Materie("Algebra", 4.5)); // Restanță
    an1.adaugaSemestru(sem1);

    Semestru sem2;
    sem2.adaugaMaterie(Materie("Analiza matematică", 7.0));
    sem2.adaugaMaterie(Materie("Algoritmi și tehnici de programare", 6.0));
    an1.adaugaSemestru(sem2);

    gestiune.adaugaAn(an1);

    // Crearea anului 2
    An an2;
    Semestru sem3; // Semestrul 1 din anul 2
    sem3.adaugaMaterie(Materie("Baze de date", 10.0));
    sem3.adaugaMaterie(Materie("Microeconomie cantitativă", 9.5));
    an2.adaugaSemestru(sem3);

    Semestru sem4; // Semestrul 2 din anul 2
    sem4.adaugaMaterie(Materie("Teoria deciziei", 8.0));
    sem4.adaugaMaterie(Materie("Sisteme de Operare", 5.0)); 
    an2.adaugaSemestru(sem4);

    gestiune.adaugaAn(an2);

    // Afișarea notelor pentru toți anii
    std::cout << "Nota maxima pe toti anii: " << gestiune.notaMaxima() << std::endl;
    std::cout << "Nota minima pe toti anii: " << gestiune.notaMinima() << std::endl;
    std::cout << "Media notelor pe toti anii: " << gestiune.media() << std::endl;

    std::cout << "Materii cu restanta pe toti anii: ";
    gestiune.afiseazaRestante();

    // Afișarea notelor pentru un an specific (anul 1)
    int anIndex = 0; // Anul 1
    std::cout << "\nNota maxima in anul " << (anIndex + 1) << ": " << gestiune.notaMaximaAn(anIndex) << std::endl;
    std::cout << "Nota minima in anul " << (anIndex + 1) << ": " << gestiune.notaMinimaAn(anIndex) << std::endl;
    std::cout << "Media notelor in anul " << (anIndex + 1) << ": " << gestiune.mediaAn(anIndex) << std::endl;

    std::cout << "Materii cu restanta in anul " << (anIndex + 1) << ": ";
    gestiune.afiseazaRestanteAn(anIndex);

    // Afișarea notelor pentru un semestru specific (sem. 1 din anul 2)
    int semestruIndex = 0; // Semestrul 1 din anul 2
    std::cout << "\nNota maxima in anul " << (anIndex + 2) << ", semestrul " << (semestruIndex + 1) << ": "
        << gestiune.notaMaximaSemestru(1, semestruIndex) << std::endl; // Anul 2
    std::cout << "Nota minima in anul " << (anIndex + 2) << ", semestrul " << (semestruIndex + 1) << ": "
        << gestiune.notaMinimaSemestru(1, semestruIndex) << std::endl; // Anul 2
    std::cout << "Media notelor in anul " << (anIndex + 2) << ", semestrul " << (semestruIndex + 1) << ": "
        << gestiune.mediaSemestru(1, semestruIndex) << std::endl; // Anul 2

    return 0;
}