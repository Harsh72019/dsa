#include<bits/stdc++.h>
using namespace std;
// Efficient Logn solution to find the set bit in a number 
int setBit(int n) {
    return n | (n + 1);
}


// My original solution to find the set bit in a number
int setBit(int n) {
    int counter = 0;
    int temp = n;
    while (temp & 1) {
        counter++;
        temp >>= 1; 
    }
    int toAdd = 1 << counter;  
    return n + toAdd;
}
