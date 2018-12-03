#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef struct Point {
	int x, y;
	Point() {
        this->x = 0;
        this->y = 0;
    }
	Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
	bool operator < (const Point &other) const {
		if (x != other.x) return x < other.x; 
        return y < other.y;
	}
    double distanceTo(Point &b) {
	    return hypot(this->x - b.x, this->y - b.y);
    }
} Point;

typedef struct Vector {
	int x, y; 
	Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }
} Vector;

bool ccw(Point p, Point q, Point r) {
    Vector a = Vector(q.x - p.x, q.y - p.y);
    Vector b = Vector(r.x - p.x, r.y - p.y);
    return a.x * b.y - a.y * b.x > 0; 
}

void convexHull(vector<Point> &pts, vector<Point> &up, vector<Point> &dn) {
    //Aloca structs.
	up.assign(pts.size(),Point());
	dn.assign(pts.size(),Point());
    //Hull
	int i = 0, j = 0;	
	for(vector<Point>::iterator it = pts.begin(); it != pts.end(); ++it){
		while(i > 1 && ccw(up[i-2], up[i-1], *it)) i--;
		while(j > 1 && !ccw(dn[j-2], dn[j-1], *it)) j--;
		up[i++] = *it;
		dn[j++] = *it;
	}
    //Remove excesso.
	up.resize(i);
	dn.resize(j);
}

double sumUpPerimeter(vector<Point> upper, vector<Point> lower) {
    double sum = 0;

    for (int i = 0; i < upper.size() - 1; i++) {
        sum += upper[i].distanceTo(upper[i+1]);
    }

    for(int i = 0; i < lower.size() - 1; i++) {
        sum += lower[i].distanceTo(lower[i+1]);
    }
    
    return sum;
}

int main(void) {
	int n; cout.precision(2);
	while (cin >> n && n) {
        vector<Point> upc, dnc, ptsc;
		for (int i = 0 ; i < n ; ++i) {
	        int x, y; cin >> x >> y;
			ptsc.push_back(Point(x, y));
		}
		sort(ptsc.begin(), ptsc.end());
        
		convexHull(ptsc, upc, dnc);

        double soma = sumUpPerimeter(upc, dnc);

		cout << fixed << "Tera que comprar uma fita de tamanho " << soma << ".\n";
	}
}