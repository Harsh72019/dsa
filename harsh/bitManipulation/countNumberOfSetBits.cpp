#include<bits/stdc++.h>
using namespace std;


int setBits(int n) {
    int counter = 0;
    while( n != 0 )
    {
        if(n & 1)
         counter++;
         n = n >> 1;
    }
    return counter;
 }