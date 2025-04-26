#include<bits/stdc++.h>
using namespace std;


int findXorToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int findXorFromLToR(int L, int R) {
    return findXorToN(R) ^ findXorToN(L - 1);
}