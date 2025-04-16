#include<bits/stdc++.h>
using namespace std;

int parseDigits(const string& s, int i, long ans, int sign) {
       
    if (i >= s.size() || !isdigit(s[i])) {
        return (int)(sign * ans);
    }

    ans = ans * 10 + (s[i] - '0');


    if (sign * ans > INT_MAX) return INT_MAX;
    if (sign * ans < INT_MIN) return INT_MIN;

    return parseDigits(s, i + 1, ans, sign); 
}

int myAtoi(string s) {
    int i = 0;
    int n = s.size();

    
    while (i < n && s[i] == ' ') i++;


    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

  
    return parseDigits(s, i, 0, sign);
}