#include <iomanip>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

typedef struct Point {
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double distanceTo(Point *p) {
        long double dx = p->x - this->x;
        long double dy = p->y - this->y;

        return sqrt(pow(dx,2) + pow(dy,2));
    }
} Point;

bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  long double uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
  long double uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
  return uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1;
}

bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh) {
  bool left =   lineLine(x1,y1,x2,y2, rx,ry,rx, ry+rh);
  bool right =  lineLine(x1,y1,x2,y2, rx+rw,ry, rx+rw,ry+rh);
  bool top =    lineLine(x1,y1,x2,y2, rx,ry, rx+rw,ry);
  bool bottom = lineLine(x1,y1,x2,y2, rx,ry+rh, rx+rw,ry+rh);
  return left || right || top || bottom;
}

long double solve(Point *start, Point *end, Point *rectLowerL, Point *rectUpperR, int v) {
    int tw = rectUpperR->x - rectLowerL->x;
    int th = rectUpperR->y - rectLowerL->y;

    Point *rectLowerR = new Point(rectUpperR->x, rectLowerL->y);
    Point *rectUpperL = new Point(rectLowerL->x, rectUpperR->y);

    long double lowerDistance = start->distanceTo(rectLowerL) + rectLowerL->distanceTo(rectLowerR) + rectLowerR->distanceTo(end);
    long double upperDistance = start->distanceTo(rectUpperL) + rectUpperL->distanceTo(rectUpperR) + rectUpperR->distanceTo(end);

    delete rectLowerR;
    delete rectUpperL;

    return min(lowerDistance, upperDistance)/(double)v;
}

int main(void) {
    int xi,yi,xf,yf,v;
    int xl,yl,xr,yr;
    while(cin >> xi >> yi >> xf >> yf >> v >> xl >> yl >> xr >> yr 
        && (xi+yi+xf+yf+v+xl+yl+xr+yr) > 0) {

        Point *joaozinho = new Point(xi,yi);
        Point *school = new Point(xf,yf);
        Point *rectL = new Point(xl,yl);
        Point *rectR = new Point(xr,yr);

        cout << std::fixed << std::setprecision(1) << solve(joaozinho, school, rectL, rectR, v) << endl;

        delete joaozinho;
        delete school;
        delete rectL;
        delete rectR;
    }
    return 0;
}