#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Memorie 

{
private:
    double rezultate[10] = { 0 };
    string operatii[10];
    int index = 0;

public:
    void adaugaInMemorie(double rezultat, const string& operatie) 
    {
        rezultate[index] = rezultat;
        operatii[index] = operatie;
        index = (index + 1) % 10; 
    }

    void afiseazaMemorie() const 
    {
        cout << "Memorie:\n";
        for (int i = 0; i < 10; i++) {
            if (!operatii[i].empty()) {
                cout << i + 1 << ": " << operatii[i] << " = " << rezultate[i] << endl;
            }
        }
    }

    double getRezultat(int pozitie) const 
    {
        return rezultate[pozitie % 10]; 
    }

    void curataMemorie() 
    {
        for (int i = 0; i < 10; i++) {
            rezultate[i] = 0;
            operatii[i].clear();
        }
        index = 0;
    }
};

class Calculator 
{
private:
    double numarCurent;
    Memorie memorie;

public:
    Calculator() : numarCurent(0) {}

    double operator+(double numar) 
    {
        numarCurent += numar;
        memorie.adaugaInMemorie(numarCurent, "Adunare: " + to_string(numar));
        return numarCurent;
    }

    double operator-(double numar) 
    {
        numarCurent -= numar;
        memorie.adaugaInMemorie(numarCurent, "Scadere: " + to_string(numar));
        return numarCurent;
    }

    double operator*(double numar) 
    {
        numarCurent *= numar;
        memorie.adaugaInMemorie(numarCurent, "Inmultire: " + to_string(numar));
        return numarCurent;
    }

    double operator/(double numar) 
    {
        if (numar != 0) {
            numarCurent /= numar;
            memorie.adaugaInMemorie(numarCurent, "Impartire: " + to_string(numar));
        }
        else {
            cout << "Eroare: Impartire la zero!" << endl;
        }
        return numarCurent;
    }

    double ridicareLaPutere(double exponent) 
    {
        numarCurent = pow(numarCurent, exponent);
        memorie.adaugaInMemorie(numarCurent, "Ridicare la putere: " + to_string(exponent));
        return numarCurent;
    }

    double radical() 
    {
        if (numarCurent >= 0) {
            numarCurent = sqrt(numarCurent);
            memorie.adaugaInMemorie(numarCurent, "Radical din: " + to_string(numarCurent));
        }
        else {
            cout << "Eroare: Radical din numar negativ!" << endl;
        }
        return numarCurent;
    }

    double invers() 
    {
        if (numarCurent != 0) {
            numarCurent = 1 / numarCurent;
            memorie.adaugaInMemorie(numarCurent, "Invers: " + to_string(numarCurent));
        }
        else {
            cout << "Eroare: Invers la zero!" << endl;
        }
        return numarCurent;
    }

    double negatie() 
    {
        numarCurent = -numarCurent;
        memorie.adaugaInMemorie(numarCurent, "Negatie: " + to_string(numarCurent));
        return numarCurent;
    }

    void clear() 
    {
        numarCurent = 0;
    }

    void curataMemorie() 
    {
        memorie.curataMemorie();
    }

    void afisareMemorie() const
    {
        memorie.afiseazaMemorie();
    }

    void folosesteMemorie(int pozitie) 
    {
        numarCurent = memorie.getRezultat(pozitie - 1);
    }

    double getNumarCurent() const 
    {
        return numarCurent;
    }
};

void afisareMeniu() 
{
    cout << "Alegeti operatia:\n"
        << "+ : Adunare\n"
        << "- : Scadere\n"
        << "* : Inmultire\n"
        << "/ : Impartire\n"
        << "^ : Ridicare la putere\n"
        << "r : Radical\n"
        << "i : 1/x\n"
        << "n : Negatie\n"
        << "m : Memorie\n"
        << "c : Curatare memorie\n"
        << "q : Iesire\n";
}

int main() 
{
    Calculator calc;
    char continua;
    double numar;

    do 
    {
        cout << "Introduceti un numar: ";
        cin >> numar;
        calc.clear();  
        calc + numar;  

        char operatie;
        do {
            afisareMeniu();
            cin >> operatie;

            if (operatie == '+') {
                cout << "Introduceti un numar pentru adunare: ";
                cin >> numar;
                cout << "Rezultatul: " << calc + numar << endl;
            }
            else if (operatie == '-') {
                cout << "Introduceti un numar pentru scadere: ";
                cin >> numar;
                cout << "Rezultatul: " << calc - numar << endl;
            }
            else if (operatie == '*') {
                cout << "Introduceti un numar pentru inmultire: ";
                cin >> numar;
                cout << "Rezultatul: " << calc * numar << endl;
            }
            else if (operatie == '/') {
                cout << "Introduceti un numar pentru impartire: ";
                cin >> numar;
                cout << "Rezultatul: " << calc / numar << endl;
            }
            else if (operatie == '^') {
                cout << "Introduceti exponentul: ";
                cin >> numar;
                cout << "Rezultatul: " << calc.ridicareLaPutere(numar) << endl;
            }
            else if (operatie == 'r') {
                cout << "Rezultatul radicalului: " << calc.radical() << endl;
            }
            else if (operatie == 'i') {
                cout << "Rezultatul inversului: " << calc.invers() << endl;
            }
            else if (operatie == 'n') {
                cout << "Rezultatul negatiei: " << calc.negatie() << endl;
            }
            else if (operatie == 'm') {
                cout << "Memoria calculatorului:\n";
                calc.afisareMemorie();
            }
            else if (operatie == 'c') {
                calc.curataMemorie();
                cout << "Memoria a fost curatata." << endl;
            }
            else if (operatie == 'q') {
                cout << "Iesire din program." << endl;
            }
            else {
                cout << "Operatie invalida. Va rog sa incercati din nou." << endl;
            }

        } while (operatie != 'q');

        cout << "Doriti sa continuati? (y/n): ";
        cin >> continua;
    } while (continua == 'y' || continua == 'Y');

    return 0;
}