#include<bits/stdc++.h>
using namespace std;


int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}