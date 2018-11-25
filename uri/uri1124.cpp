#include <iostream>

using namespace std;

bool solve(int w, int h, int r1, int r2) {
    double dx = w - r1 - r2;
    double dy = h - r1 - r2;
    if (dx < 0 || dy < 0) {
        return false;
    }
    if (dx*dx + dy*dy < (r1 + r2) * (r1 + r2)) {
        return false;
    }
    return min(h, w) >= 2 * max(r1, r2);
}

int main(void) {
    int w,h,r1,r2;
    while(cin >> w >> h >> r1 >> r2 && (w + h + r1 + r2) > 0) {
        cout << (solve(w,h,r1,r2) ? "S" : "N") << endl;
    }
    return 0;
}