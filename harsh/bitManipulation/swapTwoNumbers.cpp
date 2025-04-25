#include<bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b) {
    a = a ^ b ;
    b = a ^ b;
    a = a ^ b;
    pair<int , int> ans = {a , b};
    return ans;
}