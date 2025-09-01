/*Write a program that:

Creates an empty Vector<int> u;

Inserts numbers from 1 up to 1000 using push_back.

Every time the capacity changes, print the size and capacity.

Example Output (truncated):

Size: 6, Capacity: 7
Size: 8, Capacity: 10
Size: 11, Capacity: 15
...*/

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
    unsigned int get_capacity() const {
        return capacity;
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

int main() {
    Vector<int> u; // Crea un vector vacío
    unsigned int prev_capacity = u.get_capacity(); // Almacena la capacidad inicial

    for (int i = 1; i <= 1000; i++) {
        u.push_back(i); // Inserta números del 1 al 1000
        if (u.get_capacity() != prev_capacity) { // Verifica si la capacidad cambió
            cout << "Size: " << u.size() << ", Capacity: " << u.get_capacity() << endl;
            prev_capacity = u.get_capacity(); // Actualiza la capacidad previa
        }
    }

    return 0;
}