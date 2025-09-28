#include<bits/stdc++.h>
using namespace std;

  string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int required = t.size();
        int left = 0, right = 0;
        int min_len = INT_MAX, min_start = 0;

        while (right < s.size()) {
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;
            right++;

            while (required == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }