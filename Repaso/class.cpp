#include <iostream>
#include <cmath>

using namespace std;


class Point {
private:
//atributos
    double x;
    double y;
    double z;
public:
//constructores (metodo; cualquier operacion que yo pueda ejecutar sobre un obejto), inicializa todos los atributos del obejeto
    Point (){
        x = 0;
        y = 0;
        z = 0;
    }
    Point (double c){
        x = c;
        y = c;
        z = c;
    }
    double distance (Point* other){
        double dx = x - other->x;
        double dy = y - other->y;
        double dz = z - other->z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
    void print (){
        cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};


int main(){
    Point q (1.9);
    //Construye un obejeto de la clase point el cual nos referimos como p
    Point p;
    //puntero a un obejeto de la clase point
    Point *q = &p;
    //sobre el objeto p, llamo al metodo print
    p.print();
    q.print();
    double d = p.distance(&q);
    cout << "Distance between points: " << d << endl;
    return 0;
}