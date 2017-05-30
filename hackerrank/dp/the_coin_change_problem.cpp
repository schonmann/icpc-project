/*  
 *  HackerRank
 *  Problem: The Coin Change Problem
 *  Type: Dynamic Programming
 */
 
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

unsigned long long int coinChange( int S[], int m, int n ) {
    unsigned long long int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    return table[n];
}

int main(void) {
    int n,m;
    cin >> n >> m;
    int COINS[m];
    for(int i = 0; i < m; i++) cin >> COINS[i];
    cout << coinChange(COINS, m, n) << endl;
    return 0;
}
