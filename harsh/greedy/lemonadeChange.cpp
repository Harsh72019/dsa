#include<bits/stdc++.h>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0 , ten = 0;

    for(auto i : bills)
    {
        if(i == 5)  
            five++;
        if(i == 10)
        {
            if(five > 0)
            {
                five--;
                ten++;
            }
            else
                return false;
        }
        else
        {
            if(five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if(five >= 3)
            {
                five -= 3;
            }
            else
                return false;
        }
        return true;
    }
}