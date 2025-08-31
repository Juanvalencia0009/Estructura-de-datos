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
// Esta función calcula la suma de todos los elementos en un objeto Vector.
template <typename T>
T sum_of_elements(const Vector<T>& vec) {
    T sum = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}

int main() {
    Vector<int> u;
    for (int i = 0; i < 10; i++){
        u.push_back(i * i);
    }
    cout << "Sum of int vector: " << sum_of_elements(u) << endl;
}
