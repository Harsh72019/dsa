#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s){
    int start = 0;
    int ans = 0;
    vector<int> count(3 , 0);

    for(int end = 0 ; end < s.size() ; end++){
        count[s[end] - 'a']++;
        while(count[0] > 0 && count[1] > 0 && count[2] > 0){
            ans += s.size() - end;
            count[s[start] - 'a']--;
            start++;
        }
    }
    return ans;
}