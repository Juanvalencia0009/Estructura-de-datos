#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    //almacena los elementos del vector
    T *storage;
    //almacena el tamaño del vector
    unsigned int sz;
    //almacena la capacidad del vector
    unsigned int capacity;
    //almacena la politica de crecimiento
    double policy;

public:
    //constructor
    Vector (){
        //inicializa el vector con capacidad 10
        storage = new T[10];
        //inicializa la capacidad del vector
        capacity = 10;
        //inicializa el tamaño del vector
        sz = 0;
        //inicializa la politica de crecimiento
        policy = 1.5;
    }
    Vector (unsigned int c, double p = 1.5){
        //inicializa el vector con capacidad c 
        storage = new T[c];
        //inicializa la capacidad del vector
        capacity = c;
        //inicializa el tamaño del vector
        sz = 0;
        //inicializa la politica de crecimiento
        policy = p;
    }
    void push_back(T elem){
        //verifica si el vector esta lleno
        if (sz == capacity){
            resize ();
        }
        //agrega el nuevo elemento al final del vector
        storage[sz] = elem;
        sz++;
    }
    unsigned int size() const {
        return sz;
    }
    T& operator[](unsigned int index) {
        return storage[index];
    }
    const T& operator[](unsigned int index) const {
        return storage[index];
    }

private:
    //redimensiona el vector
    void resize (){
        //duplica la capacidad del vector
        capacity *= policy;
        //crea un nuevo arreglo con la nueva capacidad
        T *newStorage = new T[capacity];
        for (unsigned int i = 0; i < sz; i++){
            newStorage[i] = storage[i];
        }
        delete [] storage;
        storage = newStorage;
    }
public:
    //reduce la capacidad del vector
    void shrink_to_fit(){
        if (sz < capacity){
            // Crea un nuevo arreglo con la nueva capacidad
            T *newStorage = new T[sz];
            for (unsigned int i = 0; i < sz; i++){
                newStorage[i] = storage[i];
            }
            delete [] storage;
            storage = newStorage;
            capacity = sz;
        }
    }
};

// Filtra los elementos pares de un vector
template <typename T>
Vector<T> Filter_even(const Vector<T>& vec) {
    Vector<T> filtered;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0) {
            filtered.push_back(vec[i]);
        }
    }
    return filtered;
}

int main() {
    Vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    // Mostrar el vector original
    cout << "Original vector: ";
    for (unsigned int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Filtrar los elementos pares
    Vector<int> even = Filter_even(vec);

    // Mostrar el vector filtrado
    cout << "Even elements: ";
    for (unsigned int i = 0; i < even.size(); i++) {
        cout << even[i] << " ";
    }
    cout << endl;

    return 0;
}