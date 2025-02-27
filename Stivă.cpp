#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

template <typename T>
class Vector 
{
private:
    std::vector<T> elements;

public:
    // Constructorul fara parametri
    Vector() {}

    // Constructorul cu parametri
    Vector(int initialSize) : elements(initialSize) {}

    // Constructorul de copiere
    Vector(const Vector& other) : elements(other.elements) {}

    // Destructorul
    ~Vector() {}

    // Functia de inserare a unui element
    void insert(const T& element)
    {
        elements.push_back(element);
    }

    // Functia de scoatere a unui element (inutila pentru stiva și coada)
    T remove() 
    {
        std::cerr << "Aceasta functie nu ar trebui apelata pentru stiva sau coada." << std::endl;
        return T();
    }

    // Functia de scoatere a unui element de la sfarsitul vectorului (folositoare pentru stiva)
    T pop_back() 
    {
        if (elements.empty()) {
            std::cerr << "Vectorul e gol. Nu se poate scoate niciun element." << std::endl;
            return T();
        }

        T removedElement = elements.back();
        elements.pop_back();
        return removedElement;
    }

    // Functia de scoatere a unui element de la inceputul vectorului (folositoare pentru coada)
    T pop_front() 
    {
        if (elements.empty()) {
            std::cerr << "Vectorul e gol. Nu se poate scoate niciun element." << std::endl;
            return T();
        }

        T removedElement = elements.front();
        elements.erase(elements.begin());
        return removedElement;
    }

    // Funcție de afișare a vectorului
    void display() const 
    {
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

// Clasa Stiva
template <typename T>
class Stiva {
private:
    Vector<T> stack;

public:
    // Constructor fara parametri
    Stiva() {}

    // Constructor cu parametri
    Stiva(int initialSize) : stack(initialSize) {}

    // Constructor de copiere
    Stiva(const Stiva& other) : stack(other.stack) {}

    // Destructor
    ~Stiva() {}

    // Functia de inserare a unui element in stiva
    void push(const T& element) 
    {
        stack.insert(element);
    }

    // Functia de scoatere a unui element din stiva
    T pop() 
    {
        return stack.pop_back();
    }

    // Functia de afisare a stivei
    void display() const 
    {
        std::cout << "Stiva: ";
        stack.display();
    }
};

// Clasa Coada
template <typename T>
class Coada {
private:
    Vector<T> queue;

public:
    // Constructor fara parametri
    Coada() {}

    // Constructor cu parametri
    Coada(int initialSize) : queue(initialSize) {}

    // Constructor de copiere
    Coada(const Coada& other) : queue(other.queue) {}

    // Destructor
    ~Coada() {}

    // Functia de inserare a unui element in coada
    void enqueue(const T& element)
    {
        queue.insert(element);
    }

    // Functia de scoatere a unui element din coada
    T dequeue() 
    {
        return queue.pop_front();
    }

    // Functia de afisare a cozii
    void display() const 
    {
        std::cout << "Coada: ";
        queue.display();
    }
};

int main() 
{
    // Se face testarea stivei cu int
    Stiva<int> stivaInt;
    stivaInt.push(20);
    stivaInt.push(30);
    stivaInt.push(40);

    std::cout << std::endl; 
    stivaInt.display();
    std::cout << "Elementul scos din stiva este: " << stivaInt.pop() << std::endl;
    stivaInt.display();
    std::cout << std::endl;

    // Se face testarea coadei cu float
    Coada<float> coadaFloat;
    coadaFloat.enqueue(1.23f);
    coadaFloat.enqueue(4.56f);
    coadaFloat.enqueue(7.89f);

    std::cout << std::endl; 
    coadaFloat.display();
    std::cout << "Elementul scos din coada este: " << coadaFloat.dequeue() << std::endl;
    coadaFloat.display();
    std::cout << std::endl; 

    return 0;
}