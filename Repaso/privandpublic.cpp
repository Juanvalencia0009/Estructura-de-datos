#include <iostream>
using namespace std;

class Vector {
private:
    //almacena los elementos del vector
    int *storage;
    //alamacena el tamaño del vector
    unsigned int sz;
    //almacena la capacidad del vector
    unsigned int capacity;
    //almacena la politica de crecimiento
    double policy;

public:
    //constructor
    Vector (){
        //inicializa el vector con capacidad 5
        storage = new int [5];
        //inicializa la capacidad del vector
        capacity = 5;
        //inicializa el tamaño del vector
        sz = 0;
        //inicializa la politica de crecimiento
        policy = 1.5;
    }
    Vector (unsigned int c, double p = 1.5){
        //inicializa el vector con capacidad c 
        storage = new int [c];
        //inicializa la capacidad del vector
        capacity = c;
        //inicializa el tamaño del vector
        sz = 0;
        //inicializa la politica de crecimiento
        policy = p;
    }
    void push_back(int elem){
        //verifica si el vector esta lleno
        if (sz == capacity){
            resize ();

        }
        //agrega el nuevo elemento al final del vector
        storage[sz] = elem;
        sz++;
    }
private:
    //redimensiona el vector
    void resize (){
        //duplica la capacidad del vector
        capacity *= policy;
        //crea un nuevo arreglo con la nueva capacidad
        int *newStorage = new int [capacity];
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
        int *newStorage = new int [sz];
        for (unsigned int i = 0; i < sz; i++){
            newStorage[i] = storage[i];
        }
        delete [] storage;
        storage = newStorage;
        capacity = sz;
        }
    }
};
int main()
{
    Vector v(2, 3.0);
    Vector u(16);
    for (int i = 0; i < 20; i++){
        v.push_back(i * i);
        u.push_back(i * i);
    }
    v.push_back(10);
    u.push_back(10);
    return 0;
}

