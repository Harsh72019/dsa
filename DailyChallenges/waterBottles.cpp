#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int ans = numBottles;
    int emptyBottles = numBottles;
    while (emptyBottles >= 0)
    {
        int newDrinks = emptyBottles / numExchange;
        if (newDrinks <= 0)
            break;
        emptyBottles = emptyBottles % numExchange;
        ans += newDrinks;
        emptyBottles += newDrinks;
    }
    return ans;
}