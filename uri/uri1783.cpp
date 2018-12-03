#include <iostream>
#include <cmath>

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


double findCircleCenter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    return 30.0;
}

int main(void) {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << "Caso #" << i << ": " << findCircleCenter(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
    }
    return 0;
}