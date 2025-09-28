#include<bits/stdc++.h>

using namespace std;

string largestOddNumber(string num) {
    int index = -1;
    for(int i = num.size() - 1; i >= 0 ; i --)
    {
        if(((int) num[i] )%2 != 0)
        {
            index = i;
            break;
        }
    }
    return num.substr(0 , index + 1);

}