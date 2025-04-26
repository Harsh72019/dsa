#include<bits/stdc++.h>
using namespace std;


int minBitFlips(int start, int goal) {
    int temp1 = start;
    int temp2 = goal;
    int counter = 0;
    while(temp1 || temp2)
    {
        if((temp1 & 1) != (temp2 & 1) )
            counter++;
        temp1 = temp1 >> 1;
        temp2 = temp2 >> 1;
    }
    return counter;
}