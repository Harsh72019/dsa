#include<bits/stdc++.h>

using namespace std;


long long solver(long long x, long long nn, long long ans, long long MOD) {
    if (nn <= 0)
        return ans;
    if (nn % 2 == 1) {
        return solver(x, nn - 1, (ans * x) % MOD, MOD); 
    } else {
        return solver((x * x) % MOD, nn / 2, ans, MOD); 
    }
}

int countGoodNumbers(long long n) {
    long long even_positions = (n + 1) / 2;
    long long odd_positions = n / 2;
    long long MOD = 1000000007;
    long long total = (solver(5, even_positions, 1LL, MOD) * solver(4, odd_positions, 1LL, MOD)) % MOD;
    
    return total;
}