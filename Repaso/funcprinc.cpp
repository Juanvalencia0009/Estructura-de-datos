#include <iostream>
#include <cmath>
using namespace	std;

int main()
{
    double x = 9;
    double y = 8;
    double z;
    double w;
    double p;

    z = max (x, y);
    w = min (x, y);
    p = pow (x, y);
    cout << z ;
    cout << '\n';
    cout << w;
    cout << '\n';
    cout << p;

    return 0;
}
