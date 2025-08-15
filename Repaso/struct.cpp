typedef struct {
    double x;
    double y;
    double z;
} Point;

#include <iostream>
using namespace std;

int main(){
    Point p;
    Point *q = &p;
    q->x = 1.0;
    q->y = 2.0;
    q->z = 3.0;
    cout << "Point coordinates: (" << q->x << ", " << q->y << ", " << q->z << ")" << endl;
    return 0;
}