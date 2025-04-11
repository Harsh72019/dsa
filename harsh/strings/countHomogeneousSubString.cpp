#include<bits/stdc++.h>
using namespace std;
int countHomogenous(string s) {
    long long ans = 0;
    int currentStreak = 1;
    int mod = 1e9 + 7;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            currentStreak++;
        } else {
            ans = (ans + (long long)currentStreak * (currentStreak + 1) / 2) % mod;
            currentStreak = 1;
        }
    }

    ans = (ans + (long long)currentStreak * (currentStreak + 1) / 2) % mod;
    return ans;
}