#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x;
    double y;
    double z;

    cout << "introduce el primer cateto para calcular la hipotenusa de un triangulo ";
    cin >> x;
    cout << "introduce el segundo cateto: ";
    cin >> y;
    x = pow(x,2);
    y = pow(y,2);
    z = sqrt (x + y);
    cout << "la hipotenusa del triangulo es: " << z;
    return 0;
}