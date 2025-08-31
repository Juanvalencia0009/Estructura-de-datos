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

// Función para invertir un vector
template <typename T>
Vector<T> Reverse_vector(const Vector<T>& vec) {
    Vector<T> reversed(vec.size()); // Crea un vector con la capacidad adecuada
    // Copia los elementos del vector original en orden inverso
    for (unsigned int i = vec.size(); i > 0; i--) {
        reversed.push_back(vec[i - 1]);
    }
    return reversed;
}

int main() {
    Vector<int> u;
    for (int i = 0; i < 10; i++) {
        u.push_back(i * i);
    }

    // Mostrar el vector original
    cout << "Original vector: ";
    for (unsigned int i = 0; i < u.size(); i++) {
        cout << u[i] << " ";
    }
    cout << endl;

    // Invertir el vector
    Vector<int> reversed = Reverse_vector(u);

    // Mostrar el vector invertido
    cout << "Reversed vector: ";
    for (unsigned int i = 0; i < reversed.size(); i++) {
        cout << reversed[i] << " ";
    }
    cout << endl;

    return 0;
}