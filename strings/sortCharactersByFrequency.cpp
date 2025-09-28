#include<bits/stdc++.h>
using namespace std;


string frequencySort(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    vector<pair<char, int>> vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string result = "";
    for (auto i : vec) {
        result.append(i.second, i.first);
    }

    return result;
}