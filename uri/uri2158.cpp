#include <iostream>

using namespace std;

int main(void) {
    int i = 1;
    long long int fp, fh;
    while(cin >> fp >> fh) {
        long long int ne = (6*fh + 5*fp)/2/*(6*fh+5*fp)/3*/;
        long long int nv = ne + 2 - (fp + fh);
        
        cout << "Molecula #" << i << ".:." << endl << "Possui " << nv << " atomos e " << ne << " ligacoes" << endl << endl;
        i++;
    }
    return 0;
}