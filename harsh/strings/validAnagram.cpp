#include<bits/stdc++.h>

using namespace std;
// This approach can work on any type of input
bool isAnagram(string s, string t) {
    unordered_map<char , int> um;
    for(auto i : s)
        um[i] ++;
    for(auto i : t)
    {
        if(um.find(i) == um.end())
            return false;
        um[i] --;
    }
    for(auto i : um)
    {
        if(i.second != 0)
            return false;
    }
    return true;
}

// There is one more approach in which we can sort both the strings and check for quality