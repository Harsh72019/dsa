#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int n = word.size();
        int maxLen = n - numFriends + 1;

        string ans = "";

        for (int i = 0; i < n; i++) {
            string curr = word.substr(i, min(maxLen, n - i));
            ans = max(ans, curr);
        }

        return ans;
    }
};