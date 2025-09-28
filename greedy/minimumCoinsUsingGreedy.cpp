#include<bits/stdc++.h>

using namespace std;

int minimumCoins(int n)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int count = 0;
    for (int i = 9; i >= 0; i--) {
        while (n >= coins[i]) {
            n -= coins[i];
            count++;
        }
    }
    return count;
}