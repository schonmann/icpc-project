#include <iostream> 
#include <stack> 
#include <stdlib.h> 
#include <vector>

#define INF 100000000

using namespace std; 

struct Point { 
	int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {} 
}; 

Point p0;
Point nextToTop(stack<Point> &S) { 
	Point p = S.top(); 
	S.pop(); 
	Point res = S.top(); 
	S.push(p); 
	return res; 
}

int swap(Point &p1, Point &p2) { 
	Point temp = p1; 
	p1 = p2; 
	p2 = temp; 
}

int distSq(Point p1, Point p2) { 
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); 
}
int orientation(Point p, Point q, Point r) 
{ 
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0;
	return (val > 0) ?  1 : 2;
}

int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1; 
    Point *p2 = (Point *)vp2; 

    int o = orientation(p0, *p1, *p2);
    if (o == 0) 
	    return (distSq(
            p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
    return (o == 2)? -1: 1; 
}

vector<Point> cornerCops;

void convexHull(Point points[], int n) {

    int ymin = points[0].y, min = 0; 
    for (int i = 1; i < n; i++) { 
	    int y = points[i].y; 
	    if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) 
		    ymin = points[i].y, min = i; 
    }

    swap(points[0], points[min]); 

    p0 = points[0]; 
    qsort(&points[1], n-1, sizeof(Point), compare); 

    int m = 1;
    for (int i=1; i<n; i++) {
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++; 
        points[m] = points[i]; 
        m++;
    }

    if (m < 3) return;

    stack<Point> S; 
    S.push(points[0]); 
    S.push(points[1]); 
    S.push(points[2]); 

    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop(); 
        S.push(points[i]);
    }

    while (!S.empty()) { 
        Point p = S.top(); S.pop();
        cornerCops.push_back(p);
    }
}

bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false;
}

bool isInside(vector<Point> polygon, Point p) {
    if (polygon.size() < 3)  return false;
    Point extreme = {INF, p.y};
    int count = 0, i = 0; 
    do { 
        int next = (i+1)%polygon.size();
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0) 
               return onSegment(polygon[i], p, polygon[next]); 
            count++; 
        } 
        i = next;
    } while (i != 0);

    return count&1;
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

    Point p1(x1,y1);
    Point p2(x2,y2);
    Point p3(x3,y3);
    Point p4(x4,y4);
    Point runner(xs,ys);

    if(orientation(p1,p2,p3) == 0 && orientation(p2,p3,p4) == 0 && orientation(p1,p3,p4) == 0) {
        printFugiuFugiu(); return 0;
    }

    Point points[] = { p1, p2, p3, p4 };
    
    convexHull(points, sizeof(points)/sizeof(points[0]));

    isInside(cornerCops, runner) ? printPerdeuPerdeu() : printFugiuFugiu();
    
    return 0;
}