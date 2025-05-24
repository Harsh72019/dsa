#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int min_len = INT_MAX, start_index = -1;

        for (int i = 0; i < m; ) {
            // Step 1: Look for a match starting from s1[i]
            if (s1[i] == s2[0]) {
                int j = 0, k = i;

                // Step 2: Move forward to match all of s2
                while (k < m && j < n) {
                    if (s1[k] == s2[j]) j++;
                    k++;
                }

                // If we matched all characters of s2
                if (j == n) {
                    // Step 3: Backtrack to find minimal window
                    int end = k;  // Current position after matching all of s2
                    j = n - 1;
                    k--;  // step back

                    while (j >= 0) {
                        if (s1[k] == s2[j]) j--;
                        k--;
                    }
                    k++; // Now k is at the start of the window

                    // Update minimum window info
                    if (end - k < min_len) {
                        min_len = end - k;
                        start_index = k;
                    }

                    i = k + 1; // Continue from the next character after window start
                } else {
                    break;
                }
            } else {
                i++;
            }
        }

        return (start_index == -1) ? "" : s1.substr(start_index, min_len);
    }
};
