#include<bits/stdc++.h>
using namespace std;

// If the string is rotated then it would be a subString of S + S , well right intution but i didn't thought of it

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    string doubled = s + s;
    return doubled.find(goal) != string::npos;
}