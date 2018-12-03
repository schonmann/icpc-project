#include <iostream> 
#include <stack> 
#include <stdlib.h> 
using namespace std; 

struct Point { 
	int x, y; 
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
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; // colinear 
	return (val > 0)? 1 : 2; // clock or counterclock wise 
}

int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1; 
    Point *p2 = (Point *)vp2; 

    int o = orientation(p0, *p1, *p2);
    if (o == 0) 
	    return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
    return (o == 2)? -1: 1; 
}

void convexHull(Point points[], int n) {

    int ymin = points[0].y, min = 0; 
    for (int i = 1; i < n; i++) { 
	    int y = points[i].y; 
	    if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) 
		    ymin = points[i].y, min = i; 
    } 

    // Place the bottom-most point at first position 
    swap(points[0], points[min]); 

    // Sort n-1 points with respect to the first point. 
    // A point p1 comes before p2 in sorted ouput if p2 
    // has larger polar angle (in counterclockwise 
    // direction) than p1 
    p0 = points[0]; 
    qsort(&points[1], n-1, sizeof(Point), compare); 

    // If two or more points make same angle with p0, 
    // Remove all but the one that is farthest from p0 
    // Remember that, in above sorting, our criteria was 
    // to keep the farthest point at the end when more than 
    // one points have same angle. 
    int m = 1; // Initialize size of modified array 
    for (int i=1; i<n; i++) { 
        // Keep removing i while angle of i and i+1 is same 
        // with respect to p0 
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++; 
        points[m] = points[i]; 
        m++; // Update size of modified array 
    } 

    // If modified array of points has less than 3 points, 
    // convex hull is not possible 
    if (m < 3) return; 

    // Create an empty stack and push first three points 
    // to it. 
    stack<Point> S; 
    S.push(points[0]); 
    S.push(points[1]); 
    S.push(points[2]); 

    // Process remaining n-3 points 
    for (int i = 3; i < m; i++) 
    { 
        // Keep removing top while the angle formed by 
        // points next-to-top, top, and points[i] makes 
        // a non-left turn 
        while (orientation(nextToTop(S), S.top(), points[i]) != 2) 
            S.pop(); 
        S.push(points[i]); 
    } 

    // Now stack has the output points, print contents of stack 
    while (!S.empty()) 
    { 
        Point p = S.top(); 
        cout << "(" << p.x << ", " << p.y <<")" << endl; 
        S.pop(); 
    } 
}

int main() {
	Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
					{0, 0}, {1, 2}, {3, 1}, {3, 3}}; 
	int n = sizeof(points)/sizeof(points[0]); 
	convexHull(points, n); 
	return 0; 
}