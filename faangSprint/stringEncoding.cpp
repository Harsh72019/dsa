#include <bits/stdc++.h>
using namespace std;

string encode(string &message)
{
    string ans =  "";
    char curr = message[0];
    int counter = 1;
    for(int i = 1 ; i < message.size() ; i++)
    {
        if(message[i] == curr)
        {
            counter++;
        }
        else{
            ans += curr;
            ans += to_string(counter);
            curr = message[i];
            counter = 1;
        }
    }
    ans += curr;
    ans += to_string(counter);
    return ans;
}