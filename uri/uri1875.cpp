#include <iostream>

using namespace std;

int main(void) {

    int t; cin >> t;
    while(t--) {
        int r, g, b;
        r = 0; g = 0; b = 0;
        int n; cin >> n;

        while(n--) {
            char t1,t2;
            cin >> t1 >> t2;

            if(t1 == 'R') {
                if(t2 == 'G') {
                    r += 2;
                } else if (t2 == 'B') {
                    r += 1;
                }
            } else if (t1 == 'G') {
                if(t2 == 'B') {
                    g += 2;
                } else if (t2 == 'R') {
                    g += 1;
                }
            } else if (t1 == 'B') {
                if(t2 == 'R') {
                    b += 2;
                } else if (t2 == 'G') {
                    b += 1;
                }
            }
        }

        if(r == g && r == b) {
            cout << "trempate" << endl;
        } else if (r > g && r > b){
            cout << "red" << endl;
        } else if (g > r && g > b) {
            cout << "green" << endl;
        } else if (b > r && b > g){
            cout << "blue" << endl;
        } else {
            cout << "empate" << endl;
        }
    }

    return 0;
}


// R = + - -
// G = - - + +
// B = + + -