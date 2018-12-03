#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

typedef struct point {
    double x, y;
    point(double _x, double _y) : x(_x), y(_y) {}
    double distanceTo(point &p) {
        return hypot(this->x - p.x, this->y - p.y);
    }
}point;

int crossProduct(point a, point b, point p) {
    int dxc = p.x - a.x;
    int dyc = p.y - a.y;
    int dxl = b.x - a.x;
    int dyl = b.y - a.y;
    return dxc*dyl - dyc*dxl;
}

int sameLine(point a, point b, point p) {
    return crossProduct(a,b,p) == 0;
}

set<point> hull;

void quickHull(vector<point> pts, point a, point b, int side) {
    int ind = -1;
    int max_dist = 0;

    for(int i = 0; i < pts.size(); i++) {
        int dist = lineDistance(a, b, pts[i]);
        if(findSide(a, b, pts[i]) == side && dist > max_dist) {
            max_dist = dist;
            ind = i;
        }
    }

    if(ind == -1) {
        hull.put(a);
        hull.put(b);
    }

    quickHull(pts, pts[ind], a, -findSize(pts[ind], a, b));
    quickHull(pts, pts[ind], b, -findSize(pts[ind], b, a));
}

void printPerdeuPerdeu() {
    cout << "\\O/" << endl;
    cout << " | " << endl;
    cout << "/ \\" << endl;
}

void printFugiuFugiu() {
    cout << " O>" << endl;
    cout << "<| " << endl;
    cout << "/ >" << endl;
}

int main(void) {
    long long int x1,y1,x2,y2,x3,y3,x4,y4,xs,ys;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> xs >> ys;

    point p1(x1,y1);
    point p2(x2,y2);
    point p3(x3,y3);
    point p4(x4,y4);

    if(sameLine(p1,p2,p3) && sameLine(p1,p2,p4)) {
        printFugiuFugiu(); return 0;
    }
    
    return 0;
}