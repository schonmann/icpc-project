#include <set>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

#define Point pair<int, int>

set<Point> hull; 

// Returns the side of point p with respect to line 
// joining points p1 and p2. 
int findSide(Point p1, Point p2, Point p) {
	int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

int lineDist(Point p1, Point p2, Point p) {
	return abs ((p.second - p1.second) * (p2.first - p1.first) - 
			(p2.second - p1.second) * (p.first - p1.first));
} 

void quickHull(vector<Point> points, Point p1, Point p2, int side) {
	int ind = -1;
	int max_dist = 0;

	// pega o ponto com a maior distancia 
	for (int i = 0; i < points.size(); i++) {
		int temp = lineDist(p1, p2, points[i]);
		if (findSide(p1, p2, points[i]) == side && temp > max_dist) {
			ind = i;
			max_dist = temp;
		}
	}
	// If no point is found, add the end points
	// of L to the convex hull.
	if (ind == -1) {
		hull.insert(p1);
		hull.insert(p2);
		return;
	}
	// Recur for the two parts divided by a[ind] 
	quickHull(points, points[ind], p1, -findSide(points[ind], p1, p2));
	quickHull(points, points[ind], p2, -findSide(points[ind], p2, p1));
} 

void printHull(vector<Point> points) {

	if (points.size() < 3) {
		cout << "Convex hull not possible\n"; return;
	}
    //pega o indice dos x maximo e minimo.
	int min_x = 0, max_x = 0;
	for (int i = 1; i < points.size(); i++) {
		if (points[i].first < points[min_x].first) min_x = i;
		if (points[i].first > points[max_x].first) max_x = i;
	}
    //faz um quickhull pra cada lado (1 e -1)
	quickHull(points, points[min_x], points[max_x], 1);
	quickHull(points, points[min_x], points[max_x], -1);

	cout << "The points in Convex Hull are:\n";
	while (!hull.empty()) {
		cout << "(" <<( *hull.begin()).first << ", " << (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
}

int main() {
	vector<Point> points;
    
    points.push_back(pair<int,int>(0, 3));
    points.push_back(pair<int,int>(1, 1));
    points.push_back(pair<int,int>(2, 2));
    points.push_back(pair<int,int>(4, 4));
    points.push_back(pair<int,int>(0, 0));
    points.push_back(pair<int,int>(1, 2));
    points.push_back(pair<int,int>(3, 1));
    points.push_back(pair<int,int>(3, 3));

	printHull(points);

	return 0;
}