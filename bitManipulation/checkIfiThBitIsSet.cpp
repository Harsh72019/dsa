#include<bits/stdc++.h>
using namespace std;


bool isKthBitSet(int n, int k)
{
    return (n >> k -1) & 1;
}
