#include <cmath>
#include <iostream>

using namespace std;

typedef struct Point {
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double distanceTo(Point *p) {
        int dx = p->x - this->x;
        int dy = p->y - this->y;

        return sqrt(pow(dx,2) + pow(dy,2));
    }
} Point;

typedef struct Circle {
    Point *center;
    double radius;

    Circle(Point *center, double radius) {
        this->center = center;
        this->radius = radius;
    }

    ~Circle() {
        delete this->center;
    }

    bool includesCircle(Circle *anotherCicle) {
        double centerDistance = this->center->distanceTo(anotherCicle->center);
        return (this->radius - centerDistance) >= (anotherCicle->radius);
    }
} Circle;

int main(void) {

    int r1,x1,y1,r2,x2,y2;

    while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
        Circle hunterCircle = Circle(new Point(x1,y1), r1);
        Circle flowerCircle = Circle(new Point(x2,y2), r2);

        if(hunterCircle.includesCircle(&flowerCircle)) {
            cout << "RICO" << endl;
        } else {
            cout << "MORTO" << endl;
        }
    }


    return 0;
}