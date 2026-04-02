#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    void solve(vector<string>& words, vector<string>& curr, vector<int>& used) {
        if (curr.size() == 4) {
            string top = curr[0];
            string left = curr[1];
            string right = curr[2];
            string bottom = curr[3];

            if (top[0] == left[0] &&
                top[3] == right[0] &&
                bottom[0] == left[3] &&
                bottom[3] == right[3]) {
                ans.push_back(curr);
            }
            return;
        }

        for (int i = 0; i < words.size(); i++) {
            if (used[i]) continue;

            string w = words[i];

            if (curr.size() == 1) {
                if (curr[0][0] != w[0]) continue;
            }

            if (curr.size() == 2) {
                if (curr[0][3] != w[0]) continue;
            }

            if (curr.size() == 3) {
                if (w[0] != curr[1][3]) continue;
                if (w[3] != curr[2][3]) continue;
            }

            used[i] = 1;
            curr.push_back(w);

            solve(words, curr, used);

            curr.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> curr;
        vector<int> used(words.size(), 0);

        sort(words.begin(), words.end()); 

        solve(words, curr, used);

        return ans;
    }
};